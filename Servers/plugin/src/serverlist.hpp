#pragma once
#ifndef SY_SERVERLIST_HPP
#define SY_SERVERLIST_HPP

#include <lxidef.h>
#include <lx_plugin.hpp>
#include <lx_layer.hpp>
#include <lx_mesh.hpp>
#include <lx_log.hpp>
#include <lx_trisurf.hpp>
#include <lx_server.hpp>
#include <lx_scripts.hpp>
#include <lxu_command.hpp>
#include "tinyxml2.h"

#include "general.hpp"


using namespace std;
using namespace sy;
using namespace lx;

namespace sy_serverlist
{

	void initialize();
	void cleanup();

	#pragma region Defines & Statics
	#define SERVER_NAME							"sy.serverlist"
	#define SERVER_USERNAME						"Sy Server List"
	#define LOG_NAME							"sy/cmds"
	#define MSG_TABLE							"sy.msgs"

	#pragma endregion

	class CSyServerList : public CLxBasicCommand, public CLxImpl_TagDescription
	{
	private:
		vector<string>						vClasses;
		set<string>							sPreviousServers;
		tinyxml2::XMLDocument				ClassesInputXMLDoc;
		tinyxml2::XMLElement*				xmlelement_root; //root element of the classes xml input document eg. '<classes>'

		tinyxml2::XMLDocument				OutputXMLDoc;
	public:
		CLxUser_Log							Log;

		CSyServerList();
		unsigned int						tag_Count();
		LxResult							tag_Describe(unsigned index, LXtTagInfoDesc *desc);
		//void								basic_Notifiers();
		bool								basic_Enable(CLxUser_Message &msg);
		int									basic_CmdFlags();
		void								cmd_Execute(unsigned int flags);
		void								setup_args(CLxAttributeDesc	&desc);
	};

}//namespace sy_serverlist









#endif  SY_SERVERLIST_HPP
