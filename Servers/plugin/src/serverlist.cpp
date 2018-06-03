#include "serverlist.hpp"

namespace sy_serverlist
{
	void initialize()
	{
		CLxGenericPolymorph *srv = new CLxPolymorph<CSyServerList>;
		srv->AddInterface(new CLxIfc_Command    <CSyServerList>);
		srv->AddInterface(new CLxIfc_TagDescription<CSyServerList>);
		lx::AddServer(SERVER_NAME, srv);
	}

	void cleanup()
	{
		//do nothing
	}

	CSyServerList::CSyServerList()
	{
		Log.setByName(LOG_NAME);
	}

	unsigned int CSyServerList::tag_Count()
	{
		return 2;
	}

	LxResult CSyServerList::tag_Describe(unsigned index, LXtTagInfoDesc *desc)
	{
		LxResult result(LXe_OK);
		switch (index)
		{
		case 0:
			desc->type = LXsSRV_LOGSUBSYSTEM;
			desc->info = LOG_NAME;
			break;
		case 1:
			desc->type = LXsSRV_USERNAME;
			desc->info = SERVER_USERNAME;
			break;
		default:
			result = LXe_OUTOFBOUNDS;
			break;
		}
		return result;
	}

	//void CSyServerList::basic_Notifiers()
	//{
	//	basic_AddNotify(LXsNOTIFIER_SELECT, "item +dv"); /* Will be notified when Item selection changes */
	//}

	bool CSyServerList::basic_Enable(CLxUser_Message &msg)
	{
		return true;
	}

	int CSyServerList::basic_CmdFlags()
	{
		return LXfCMD_UNDO;
	}

	void CSyServerList::setup_args(CLxAttributeDesc	&desc)
	{
		desc.add("PreviousSDKBuildVersion", LXsTYPE_INTEGER);
	}

	void CSyServerList::cmd_Execute(unsigned int flags)
	{

		CLxUser_PlatformService PlatformService;
		int pathCount(-1);
		PlatformService.PathCount(&pathCount);
		const char* path(NULL);
		const char* name(NULL);
		map<string, string> paths;
		//string licensedto = PlatformService.LicensedTo();
		for (int i = 0; i < pathCount; i++)
		{
			PlatformService.PathNameByIndex(i, &name);
			PlatformService.PathByIndex(i, &path);
			if (strcmp(name, "user") == 0 && path)
			{
				string appUsername = PlatformService.AppUsername();
				int appVersion(-1);
				int appBuild(-1);
				PlatformService.AppVersion(&appVersion);
				PlatformService.AppBuild(&appBuild);
				string filename(path);
				filename += "\\modo_servers_" + syI2S(appVersion) + "_" + syI2S(appBuild) + ".xml";
				tinyxml2::XMLDeclaration *element_declaration = OutputXMLDoc.NewDeclaration();
				OutputXMLDoc.InsertFirstChild(element_declaration);
				CLxUser_HostService HostService;
				unsigned int TotalNoOfServers(0);
				string ClassesInputXMLFile(path);
				ClassesInputXMLFile += "\\Kits\\cmds\\modo_server_classes.xml";
				if (ClassesInputXMLDoc.LoadFile(ClassesInputXMLFile.c_str()) != tinyxml2::XMLError::XML_SUCCESS)
					return;
				if ((xmlelement_root = ClassesInputXMLDoc.FirstChildElement("classes")) == NULL)
					return;
				const char *value = NULL;
				unsigned int uValue = xmlelement_root->UnsignedAttribute("count");
				tinyxml2::XMLElement* xmlelement_class = xmlelement_root->FirstChildElement("class");
				do 
				{
					if ((value = xmlelement_class->GetText()) != NULL)
						vClasses.push_back(string(value));
					xmlelement_class = xmlelement_class->NextSiblingElement();
				} while (xmlelement_class);
				//if (value = xmlelement_root->Attribute("count"))
				//	xmlelement_InputLayouts = root_children;

				//tinyxml2::XMLElement* root_children = xmlelement_root->FirstChildElement("class");
				//do
				//{
				//	if (value = root_children->Attribute("Name", "ParameterGroups"))
				//		xmlelement_ParameterGroups = root_children;
				//	if (value = root_children->Attribute("Name", "MaterialDefinitions"))
				//		xmlelement_MaterialDefinitions = root_children;
				//	root_children = root_children->NextSiblingElement("Array");
				//} while (root_children);









				for each (string cls in vClasses)
				{
					unsigned int NoOfServers = HostService.NumServers(cls.c_str());
					TotalNoOfServers += NoOfServers;
				}
				tinyxml2::XMLElement *element_servers = OutputXMLDoc.NewElement("servers");
				element_servers->SetAttribute("count", TotalNoOfServers);
				OutputXMLDoc.InsertEndChild(element_servers); //Root element of the xml file
				for each (string cls in vClasses)
				{
					CLxUser_Factory factory;
					unsigned int NoOfServers = HostService.NumServers(cls.c_str());
					tinyxml2::XMLElement *element_class = OutputXMLDoc.NewElement("class");
					element_class->SetAttribute("name", cls.c_str());
					element_class->SetAttribute("count", NoOfServers);
					element_servers->InsertEndChild(element_class);
					for (unsigned int i = 0; i < NoOfServers; i++)
					{
						const char* servername(NULL);
						HostService.ServerByIndex(cls.c_str(), i, factory);
						factory.Name(&servername);
						tinyxml2::XMLElement *element_server = OutputXMLDoc.NewElement("server");
						element_server->SetAttribute("class", cls.c_str());
						element_server->SetAttribute("name", servername);
						element_class->InsertEndChild(element_server);
						
						unsigned int tagCount;
						factory.TagCount(&tagCount);
						if (tagCount > 0)
						{
							tinyxml2::XMLElement *element_tags = OutputXMLDoc.NewElement("tags");
							element_tags->SetAttribute("count", tagCount);
							element_server->InsertEndChild(element_tags);
							for (unsigned int j = 0; j < tagCount; j++)
							{
								const char* tagName(NULL);
								const char* tagValue(NULL);
								if (LXx_OK(factory.TagByIndex(j, &tagName, &tagValue)))
								{
									tinyxml2::XMLElement *element_tag = OutputXMLDoc.NewElement("tag");
									element_tag->SetAttribute("name", tagName);

									#pragma region Workaround
									//5-Sep-2016
									//Synide
									//Hack around 'invalid' tag value data for package2>servers with a 'tool.order' tag
									if (strcmp(tagName, "tool.order") == 0)
									{
										int tv = syS2I(tagValue);
										element_tag->SetText(syI2S(tv).c_str());
										Log.Message(LXe_INFO, "'%s' - 'tool.order' tag value invalid. '%s'", servername, element_tag->Value());
									}
									else
										element_tag->SetText(tagValue);
									#pragma endregion

									element_tags->InsertEndChild(element_tag);
								}
							}
						}
						factory.clear();
					}
					Log.Message(LXe_INFO, "'%u' servers written for class '%s'", NoOfServers, cls.c_str());
				}
				OutputXMLDoc.SaveFile(filename.c_str());
				Log.Message(LXe_INFO, "Total of '%u' servers written to xml file '%s' from '%u' types of server classes found in '%s' classes file.", TotalNoOfServers, filename.c_str(), vClasses.size(), ClassesInputXMLFile.c_str());
				break;
			}
		}
		int a(1);


	}

}//namespace sy_serverlist