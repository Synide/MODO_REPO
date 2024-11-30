//
// C++ wrapper for lxsdk/lximage.h.
//
//	Copyright 2024.
//
//
#pragma once

#include <lximage.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_Image = {0x469AFBB8, {0xE6A2, 0x4d88}, {0x9C, 0x39, 0x54, 0x30, 0xCA, 0x72, 0xE4, 0x04}};
    static LXtGUID const guid_ImageSegment = {0x370ABB2F, {0x119E, 0x4EEC}, {0x98, 0xF8, 0x03, 0x38, 0x8A, 0xBE, 0x7D, 0x2C}};
    static LXtGUID const guid_ImageWrite = {0x8F9CF293, {0xB6F9, 0x498e}, {0xA1, 0x24, 0x67, 0x04, 0xE2, 0xC2, 0x46, 0x62}};
    static LXtGUID const guid_IndexImage = {0x08CAE3BC, {0xED69, 0x4EC4}, {0x9D, 0x7D, 0xBB, 0xDB, 0xE4, 0xE3, 0x53, 0x43}};
    static LXtGUID const guid_IndexImageWrite = {0xD59C5E09, {0x779E, 0x445b}, {0xB3, 0x17, 0x28, 0x26, 0x30, 0xCB, 0x6B, 0xD5}};
    static LXtGUID const guid_LayeredImage = {0x8523ECC4, {0xB8B3, 0x4C6E}, {0x8F, 0x14, 0xA1, 0xD2, 0xD0, 0x1E, 0x80, 0x38}};
    static LXtGUID const guid_LayeredImageWrite = {0x79D28886, {0x9652, 0x4A76}, {0x9A, 0xA7, 0x1B, 0x1E, 0x4D, 0x55, 0x3D, 0xCD}};
    static LXtGUID const guid_TileImage = {0xBD12D6C3, {0xC08F, 0x4AD1}, {0xA0, 0x80, 0x39, 0x9F, 0x95, 0x8D, 0x28, 0xC0}};
    static LXtGUID const guid_ImageLoaderTarget1 = {0x9F124A7B, {0xDFC7, 0x42E6}, {0x97, 0x7B, 0x71, 0xAE, 0x2E, 0x33, 0xB0, 0x17}};
    static LXtGUID const guid_ImageLoaderTarget = {0x1034861C, {0x78C4, 0x4BEC}, {0x95, 0x88, 0xF1, 0xD3, 0xC0, 0xB0, 0x40, 0x1A}};
    static LXtGUID const guid_ImageLevelSample = {0x79A6EA0E, {0x9589, 0x4D03}, {0x88, 0x0C, 0xC0, 0x6A, 0x6E, 0xC6, 0xCF, 0x7D}};
    static LXtGUID const guid_ImageService = {0x03A7D258, {0x397C, 0x4D92}, {0xB3, 0xAF, 0x69, 0x5A, 0xD6, 0x76, 0xFC, 0xF9}};
    static LXtGUID const guid_ImageBlockCodec = {0x7960B5BA, {0x70D3, 0x4FAD}, {0x8C, 0xA1, 0xBD, 0x30, 0xA7, 0x93, 0x85, 0x54}};
    static LXtGUID const guid_ImageFilter = {0xFB00C87C, {0x5A34, 0x4B45}, {0xB0, 0xE8, 0x99, 0x89, 0x26, 0xC7, 0x9D, 0xC4}};
    static LXtGUID const guid_ImageFilterSample = {0x9EC74AED, {0xF86F, 0x4105}, {0xAC, 0xE9, 0x7B, 0xDA, 0xA6, 0x29, 0x87, 0x36}};
    static LXtGUID const guid_ImageFilterMetrics = {0x8F7A47EB, {0x5812, 0x47F4}, {0x91, 0xF5, 0x21, 0x95, 0xB0, 0x53, 0xF9, 0x7D}};
    static LXtGUID const guid_ImageFilterMetrics1 = {0x0D2CA8D8, {0x66A9, 0x45A0}, {0xAA, 0xE6, 0x83, 0x64, 0xD9, 0x03, 0xAF, 0xDA}};
    static LXtGUID const guid_Movie = {0xB7BD9F49, {0x9400, 0x45F1}, {0xAD, 0xEE, 0xBF, 0xE8, 0x2A, 0x1C, 0x4A, 0x65}};
} // namespace lx

class CLxImpl_Image
{
public:
    virtual ~CLxImpl_Image() = default;

    virtual void img_Size([[maybe_unused]] unsigned int *w, [[maybe_unused]] unsigned int *h)
    {
    }

    virtual LXtPixelFormat img_Format(void) = 0;

    virtual auto img_GetPixel([[maybe_unused]] unsigned int x, [[maybe_unused]] unsigned int y, [[maybe_unused]] LXtPixelFormat type, [[maybe_unused]] void *pixel) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual const void * img_GetLine(unsigned int y, LXtPixelFormat type, void *buf) = 0;
};

#define LXxD_Image_Size void img_Size([[maybe_unused]] unsigned int *w, [[maybe_unused]] unsigned int *h) override
#define LXxO_Image_Size LXxD_Image_Size
#define LXxC_Image_Size(c) void c::img_Size([[maybe_unused]] unsigned int *w, [[maybe_unused]] unsigned int *h)
#define LXxD_Image_Format LXtPixelFormat img_Format() override
#define LXxO_Image_Format LXxD_Image_Format
#define LXxC_Image_Format(c) LXtPixelFormat c::img_Format()
#define LXxD_Image_GetPixel LxResult img_GetPixel([[maybe_unused]] unsigned int x, [[maybe_unused]] unsigned int y, [[maybe_unused]] LXtPixelFormat type, [[maybe_unused]] void *pixel) override
#define LXxO_Image_GetPixel LXxD_Image_GetPixel
#define LXxC_Image_GetPixel(c) LxResult c::img_GetPixel([[maybe_unused]] unsigned int x, [[maybe_unused]] unsigned int y, [[maybe_unused]] LXtPixelFormat type, [[maybe_unused]] void *pixel)
#define LXxD_Image_GetLine const void * img_GetLine([[maybe_unused]] unsigned int y, [[maybe_unused]] LXtPixelFormat type, [[maybe_unused]] void *buf) override
#define LXxO_Image_GetLine LXxD_Image_GetLine
#define LXxC_Image_GetLine(c) const void * c::img_GetLine([[maybe_unused]] unsigned int y, [[maybe_unused]] LXtPixelFormat type, [[maybe_unused]] void *buf)

template <class T>
class CLxIfc_Image: public CLxInterface
{
public:
    CLxIfc_Image()
    {
        vt.Size = Size;
        vt.Format = Format;
        vt.GetPixel = GetPixel;
        vt.GetLine = GetLine;
        vTable = &vt.iunk;
        iid = &lx::guid_Image;
    }

    static auto Size(LXtObjectID wcom,unsigned int *w,unsigned int *h) -> void
    {
        LXCWxINST (CLxImpl_Image, loc);
        loc->img_Size( w, h);
    }

    static auto Format(LXtObjectID wcom) -> LXtPixelFormat
    {
        LXCWxINST (CLxImpl_Image, loc);
        return loc->img_Format();
    }

    static auto GetPixel(LXtObjectID wcom,unsigned int x,unsigned int y,LXtPixelFormat type,void *pixel) -> LxResult
    {
        LXCWxINST (CLxImpl_Image, loc);
        try
        {
           return loc->img_GetPixel( x, y, type, pixel);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GetLine(LXtObjectID wcom,unsigned int y,LXtPixelFormat type,void *buf) -> const void *
    {
        LXCWxINST (CLxImpl_Image, loc);
        return loc->img_GetLine( y, type, buf);
    }

private:
    ILxImage vt;
};

class CLxLoc_Image : public CLxLocalize<ILxImageID>
{
public:
    CLxLoc_Image()
    {
        _init();
    }

    CLxLoc_Image(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_Image(CLxLoc_Image const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_Image;
    }

    auto Size(unsigned int *w, unsigned int *h) const -> void
    {
        m_loc[0]->Size(m_loc, w, h);
    }

    auto Format(void) const -> LXtPixelFormat
    {
        return m_loc[0]->Format(m_loc);
    }

    auto GetPixel(unsigned int x, unsigned int y, LXtPixelFormat type, void *pixel) const -> LxResult
    {
        return m_loc[0]->GetPixel(m_loc, x, y, type, pixel);
    }

    auto GetLine(unsigned int y, LXtPixelFormat type, void *buf) const -> const void *
    {
        return m_loc[0]->GetLine(m_loc, y, type, buf);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_ImageSegment
{
public:
    virtual ~CLxImpl_ImageSegment() = default;

    virtual auto imgs_GetSegment([[maybe_unused]] unsigned int y, [[maybe_unused]] unsigned int left, [[maybe_unused]] unsigned int right, [[maybe_unused]] LXtImageFloat *rgba) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto imgs_SetSegment([[maybe_unused]] unsigned int y, [[maybe_unused]] unsigned int left, [[maybe_unused]] unsigned int right, [[maybe_unused]] LXtPixelFormat type, [[maybe_unused]] const void *line) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_ImageSegment_GetSegment LxResult imgs_GetSegment([[maybe_unused]] unsigned int y, [[maybe_unused]] unsigned int left, [[maybe_unused]] unsigned int right, [[maybe_unused]] LXtImageFloat *rgba) override
#define LXxO_ImageSegment_GetSegment LXxD_ImageSegment_GetSegment
#define LXxC_ImageSegment_GetSegment(c) LxResult c::imgs_GetSegment([[maybe_unused]] unsigned int y, [[maybe_unused]] unsigned int left, [[maybe_unused]] unsigned int right, [[maybe_unused]] LXtImageFloat *rgba)
#define LXxD_ImageSegment_SetSegment LxResult imgs_SetSegment([[maybe_unused]] unsigned int y, [[maybe_unused]] unsigned int left, [[maybe_unused]] unsigned int right, [[maybe_unused]] LXtPixelFormat type, [[maybe_unused]] const void *line) override
#define LXxO_ImageSegment_SetSegment LXxD_ImageSegment_SetSegment
#define LXxC_ImageSegment_SetSegment(c) LxResult c::imgs_SetSegment([[maybe_unused]] unsigned int y, [[maybe_unused]] unsigned int left, [[maybe_unused]] unsigned int right, [[maybe_unused]] LXtPixelFormat type, [[maybe_unused]] const void *line)

template <class T>
class CLxIfc_ImageSegment: public CLxInterface
{
public:
    CLxIfc_ImageSegment()
    {
        vt.GetSegment = GetSegment;
        vt.SetSegment = SetSegment;
        vTable = &vt.iunk;
        iid = &lx::guid_ImageSegment;
    }

    static auto GetSegment(LXtObjectID wcom,unsigned int y,unsigned int left,unsigned int right,LXtImageFloat *rgba) -> LxResult
    {
        LXCWxINST (CLxImpl_ImageSegment, loc);
        try
        {
           return loc->imgs_GetSegment( y, left, right, rgba);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SetSegment(LXtObjectID wcom,unsigned int y,unsigned int left,unsigned int right,LXtPixelFormat type,const void *line) -> LxResult
    {
        LXCWxINST (CLxImpl_ImageSegment, loc);
        try
        {
           return loc->imgs_SetSegment( y, left, right, type, line);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxImageSegment vt;
};

class CLxLoc_ImageSegment : public CLxLocalize<ILxImageSegmentID>
{
public:
    CLxLoc_ImageSegment()
    {
        _init();
    }

    CLxLoc_ImageSegment(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_ImageSegment(CLxLoc_ImageSegment const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_ImageSegment;
    }

    auto GetSegment(unsigned int y, unsigned int left, unsigned int right, LXtImageFloat *rgba) const -> LxResult
    {
        return m_loc[0]->GetSegment(m_loc, y, left, right, rgba);
    }

    auto SetSegment(unsigned int y, unsigned int left, unsigned int right, LXtPixelFormat type, const void *line) -> LxResult
    {
        return m_loc[0]->SetSegment(m_loc, y, left, right, type, line);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_ImageWrite
{
public:
    virtual ~CLxImpl_ImageWrite() = default;

    virtual void imgw_Size([[maybe_unused]] unsigned int *w, [[maybe_unused]] unsigned int *h)
    {
    }

    virtual LXtPixelFormat imgw_Format(void) = 0;

    virtual auto imgw_AddAttribute([[maybe_unused]] const char *name, [[maybe_unused]] const char *type, [[maybe_unused]] unsigned *index) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto imgw_SetPixel([[maybe_unused]] unsigned int x, [[maybe_unused]] unsigned int y, [[maybe_unused]] LXtPixelFormat type, [[maybe_unused]] const void *pixel) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto imgw_SetLine([[maybe_unused]] unsigned int y, [[maybe_unused]] LXtPixelFormat type, [[maybe_unused]] const void *line) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_ImageWrite_Size void imgw_Size([[maybe_unused]] unsigned int *w, [[maybe_unused]] unsigned int *h) override
#define LXxO_ImageWrite_Size LXxD_ImageWrite_Size
#define LXxC_ImageWrite_Size(c) void c::imgw_Size([[maybe_unused]] unsigned int *w, [[maybe_unused]] unsigned int *h)
#define LXxD_ImageWrite_Format LXtPixelFormat imgw_Format() override
#define LXxO_ImageWrite_Format LXxD_ImageWrite_Format
#define LXxC_ImageWrite_Format(c) LXtPixelFormat c::imgw_Format()
#define LXxD_ImageWrite_AddAttribute LxResult imgw_AddAttribute([[maybe_unused]] const char *name, [[maybe_unused]] const char *type, [[maybe_unused]] unsigned *index) override
#define LXxO_ImageWrite_AddAttribute LXxD_ImageWrite_AddAttribute
#define LXxC_ImageWrite_AddAttribute(c) LxResult c::imgw_AddAttribute([[maybe_unused]] const char *name, [[maybe_unused]] const char *type, [[maybe_unused]] unsigned *index)
#define LXxD_ImageWrite_SetPixel LxResult imgw_SetPixel([[maybe_unused]] unsigned int x, [[maybe_unused]] unsigned int y, [[maybe_unused]] LXtPixelFormat type, [[maybe_unused]] const void *pixel) override
#define LXxO_ImageWrite_SetPixel LXxD_ImageWrite_SetPixel
#define LXxC_ImageWrite_SetPixel(c) LxResult c::imgw_SetPixel([[maybe_unused]] unsigned int x, [[maybe_unused]] unsigned int y, [[maybe_unused]] LXtPixelFormat type, [[maybe_unused]] const void *pixel)
#define LXxD_ImageWrite_SetLine LxResult imgw_SetLine([[maybe_unused]] unsigned int y, [[maybe_unused]] LXtPixelFormat type, [[maybe_unused]] const void *line) override
#define LXxO_ImageWrite_SetLine LXxD_ImageWrite_SetLine
#define LXxC_ImageWrite_SetLine(c) LxResult c::imgw_SetLine([[maybe_unused]] unsigned int y, [[maybe_unused]] LXtPixelFormat type, [[maybe_unused]] const void *line)

template <class T>
class CLxIfc_ImageWrite: public CLxInterface
{
public:
    CLxIfc_ImageWrite()
    {
        vt.Size = Size;
        vt.Format = Format;
        vt.AddAttribute = AddAttribute;
        vt.SetPixel = SetPixel;
        vt.SetLine = SetLine;
        vTable = &vt.iunk;
        iid = &lx::guid_ImageWrite;
    }

    static auto Size(LXtObjectID wcom,unsigned int *w,unsigned int *h) -> void
    {
        LXCWxINST (CLxImpl_ImageWrite, loc);
        loc->imgw_Size( w, h);
    }

    static auto Format(LXtObjectID wcom) -> LXtPixelFormat
    {
        LXCWxINST (CLxImpl_ImageWrite, loc);
        return loc->imgw_Format();
    }

    static auto AddAttribute(LXtObjectID wcom,const char *name,const char *type,unsigned *index) -> LxResult
    {
        LXCWxINST (CLxImpl_ImageWrite, loc);
        try
        {
           return loc->imgw_AddAttribute( name, type, index);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SetPixel(LXtObjectID wcom,unsigned int x,unsigned int y,LXtPixelFormat type,const void *pixel) -> LxResult
    {
        LXCWxINST (CLxImpl_ImageWrite, loc);
        try
        {
           return loc->imgw_SetPixel( x, y, type, pixel);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SetLine(LXtObjectID wcom,unsigned int y,LXtPixelFormat type,const void *line) -> LxResult
    {
        LXCWxINST (CLxImpl_ImageWrite, loc);
        try
        {
           return loc->imgw_SetLine( y, type, line);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxImageWrite vt;
};

class CLxLoc_ImageWrite : public CLxLocalize<ILxImageWriteID>
{
public:
    CLxLoc_ImageWrite()
    {
        _init();
    }

    CLxLoc_ImageWrite(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_ImageWrite(CLxLoc_ImageWrite const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_ImageWrite;
    }

    auto Size(unsigned int *w, unsigned int *h) const -> void
    {
        m_loc[0]->Size(m_loc, w, h);
    }

    auto Format(void) const -> LXtPixelFormat
    {
        return m_loc[0]->Format(m_loc);
    }

    auto AddAttribute(const char *name, const char *type, unsigned *index) -> LxResult
    {
        return m_loc[0]->AddAttribute(m_loc, name, type, index);
    }

    auto SetPixel(unsigned int x, unsigned int y, LXtPixelFormat type, const void *pixel) -> LxResult
    {
        return m_loc[0]->SetPixel(m_loc, x, y, type, pixel);
    }

    auto SetLine(unsigned int y, LXtPixelFormat type, const void *line) -> LxResult
    {
        return m_loc[0]->SetLine(m_loc, y, type, line);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_IndexImage : public CLxLocalize<ILxIndexImageID>
{
public:
    CLxLoc_IndexImage()
    {
        _init();
    }

    CLxLoc_IndexImage(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_IndexImage(CLxLoc_IndexImage const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_IndexImage;
    }

    auto Size(unsigned int *w, unsigned int *h) const -> void
    {
        m_loc[0]->Size(m_loc, w, h);
    }

    auto Format(void) const -> LXtPixelFormat
    {
        return m_loc[0]->Format(m_loc);
    }

    auto MapSize(unsigned *numColors) const -> LxResult
    {
        return m_loc[0]->MapSize(m_loc, numColors);
    }

    auto GetIndex(unsigned int x, unsigned int y, LXtImageIndex *index) const -> LxResult
    {
        return m_loc[0]->GetIndex(m_loc, x, y, index);
    }

    auto GetMap(LXtImageIndex index, LXtPixelFormat type, void *pixel) const -> LxResult
    {
        return m_loc[0]->GetMap(m_loc, index, type, pixel);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_IndexImageWrite : public CLxLocalize<ILxIndexImageWriteID>
{
public:
    CLxLoc_IndexImageWrite()
    {
        _init();
    }

    CLxLoc_IndexImageWrite(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_IndexImageWrite(CLxLoc_IndexImageWrite const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_IndexImageWrite;
    }

    auto Size(unsigned int *w, unsigned int *h) const -> void
    {
        m_loc[0]->Size(m_loc, w, h);
    }

    auto Format(void) const -> LXtPixelFormat
    {
        return m_loc[0]->Format(m_loc);
    }

    auto AddAttribute(const char *name, const char *type, unsigned *index) -> LxResult
    {
        return m_loc[0]->AddAttribute(m_loc, name, type, index);
    }

    auto SetIndex(unsigned int x, unsigned int y, LXtImageIndex index) -> LxResult
    {
        return m_loc[0]->SetIndex(m_loc, x, y, index);
    }

    auto SetMap(LXtImageIndex index, LXtPixelFormat type, const void *pixel) -> LxResult
    {
        return m_loc[0]->SetMap(m_loc, index, type, pixel);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_LayeredImage
{
public:
    virtual ~CLxImpl_LayeredImage() = default;

    virtual auto limg_Size([[maybe_unused]] unsigned int *w, [[maybe_unused]] unsigned int *h) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual unsigned int limg_Count(void) = 0;

    virtual auto limg_Image([[maybe_unused]] unsigned int index, [[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto limg_Name([[maybe_unused]] unsigned int index, [[maybe_unused]] const char **name) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto limg_Type([[maybe_unused]] unsigned int index, [[maybe_unused]] unsigned int *flags, [[maybe_unused]] const char **type) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto limg_Offset([[maybe_unused]] unsigned int index, [[maybe_unused]] int *x, [[maybe_unused]] int *y) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto limg_Blend([[maybe_unused]] unsigned int index, [[maybe_unused]] float *opacity, [[maybe_unused]] unsigned int *mode) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto limg_ChannelName([[maybe_unused]] unsigned layerIndex, [[maybe_unused]] unsigned channelIndex, [[maybe_unused]] const char **name) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto limg_Parent([[maybe_unused]] unsigned layerIndex, [[maybe_unused]] int *parentIndex) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto limg_IsGroup([[maybe_unused]] unsigned layerIndex, [[maybe_unused]] unsigned int *isGroup) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_LayeredImage_Size LxResult limg_Size([[maybe_unused]] unsigned int *w, [[maybe_unused]] unsigned int *h) override
#define LXxO_LayeredImage_Size LXxD_LayeredImage_Size
#define LXxC_LayeredImage_Size(c) LxResult c::limg_Size([[maybe_unused]] unsigned int *w, [[maybe_unused]] unsigned int *h)
#define LXxD_LayeredImage_Count unsigned int limg_Count() override
#define LXxO_LayeredImage_Count LXxD_LayeredImage_Count
#define LXxC_LayeredImage_Count(c) unsigned int c::limg_Count()
#define LXxD_LayeredImage_Image LxResult limg_Image([[maybe_unused]] unsigned int index, [[maybe_unused]] void **ppvObj) override
#define LXxO_LayeredImage_Image LXxD_LayeredImage_Image
#define LXxC_LayeredImage_Image(c) LxResult c::limg_Image([[maybe_unused]] unsigned int index, [[maybe_unused]] void **ppvObj)
#define LXxD_LayeredImage_Name LxResult limg_Name([[maybe_unused]] unsigned int index, [[maybe_unused]] const char **name) override
#define LXxO_LayeredImage_Name LXxD_LayeredImage_Name
#define LXxC_LayeredImage_Name(c) LxResult c::limg_Name([[maybe_unused]] unsigned int index, [[maybe_unused]] const char **name)
#define LXxD_LayeredImage_Type LxResult limg_Type([[maybe_unused]] unsigned int index, [[maybe_unused]] unsigned int *flags, [[maybe_unused]] const char **type) override
#define LXxO_LayeredImage_Type LXxD_LayeredImage_Type
#define LXxC_LayeredImage_Type(c) LxResult c::limg_Type([[maybe_unused]] unsigned int index, [[maybe_unused]] unsigned int *flags, [[maybe_unused]] const char **type)
#define LXxD_LayeredImage_Offset LxResult limg_Offset([[maybe_unused]] unsigned int index, [[maybe_unused]] int *x, [[maybe_unused]] int *y) override
#define LXxO_LayeredImage_Offset LXxD_LayeredImage_Offset
#define LXxC_LayeredImage_Offset(c) LxResult c::limg_Offset([[maybe_unused]] unsigned int index, [[maybe_unused]] int *x, [[maybe_unused]] int *y)
#define LXxD_LayeredImage_Blend LxResult limg_Blend([[maybe_unused]] unsigned int index, [[maybe_unused]] float *opacity, [[maybe_unused]] unsigned int *mode) override
#define LXxO_LayeredImage_Blend LXxD_LayeredImage_Blend
#define LXxC_LayeredImage_Blend(c) LxResult c::limg_Blend([[maybe_unused]] unsigned int index, [[maybe_unused]] float *opacity, [[maybe_unused]] unsigned int *mode)
#define LXxD_LayeredImage_ChannelName LxResult limg_ChannelName([[maybe_unused]] unsigned layerIndex, [[maybe_unused]] unsigned channelIndex, [[maybe_unused]] const char **name) override
#define LXxO_LayeredImage_ChannelName LXxD_LayeredImage_ChannelName
#define LXxC_LayeredImage_ChannelName(c) LxResult c::limg_ChannelName([[maybe_unused]] unsigned layerIndex, [[maybe_unused]] unsigned channelIndex, [[maybe_unused]] const char **name)
#define LXxD_LayeredImage_Parent LxResult limg_Parent([[maybe_unused]] unsigned layerIndex, [[maybe_unused]] int *parentIndex) override
#define LXxO_LayeredImage_Parent LXxD_LayeredImage_Parent
#define LXxC_LayeredImage_Parent(c) LxResult c::limg_Parent([[maybe_unused]] unsigned layerIndex, [[maybe_unused]] int *parentIndex)
#define LXxD_LayeredImage_IsGroup LxResult limg_IsGroup([[maybe_unused]] unsigned layerIndex, [[maybe_unused]] unsigned int *isGroup) override
#define LXxO_LayeredImage_IsGroup LXxD_LayeredImage_IsGroup
#define LXxC_LayeredImage_IsGroup(c) LxResult c::limg_IsGroup([[maybe_unused]] unsigned layerIndex, [[maybe_unused]] unsigned int *isGroup)

template <class T>
class CLxIfc_LayeredImage: public CLxInterface
{
public:
    CLxIfc_LayeredImage()
    {
        vt.Size = Size;
        vt.Count = Count;
        vt.Image = Image;
        vt.Name = Name;
        vt.Type = Type;
        vt.Offset = Offset;
        vt.Blend = Blend;
        vt.ChannelName = ChannelName;
        vt.Parent = Parent;
        vt.IsGroup = IsGroup;
        vTable = &vt.iunk;
        iid = &lx::guid_LayeredImage;
    }

    static auto Size(LXtObjectID wcom,unsigned int *w,unsigned int *h) -> LxResult
    {
        LXCWxINST (CLxImpl_LayeredImage, loc);
        try
        {
           return loc->limg_Size( w, h);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Count(LXtObjectID wcom) -> unsigned int
    {
        LXCWxINST (CLxImpl_LayeredImage, loc);
        return loc->limg_Count();
    }

    static auto Image(LXtObjectID wcom,unsigned int index,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_LayeredImage, loc);
        try
        {
           return loc->limg_Image( index, ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Name(LXtObjectID wcom,unsigned int index,const char **name) -> LxResult
    {
        LXCWxINST (CLxImpl_LayeredImage, loc);
        try
        {
           return loc->limg_Name( index, name);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Type(LXtObjectID wcom,unsigned int index,unsigned int *flags,const char **type) -> LxResult
    {
        LXCWxINST (CLxImpl_LayeredImage, loc);
        try
        {
           return loc->limg_Type( index, flags, type);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Offset(LXtObjectID wcom,unsigned int index,int *x,int *y) -> LxResult
    {
        LXCWxINST (CLxImpl_LayeredImage, loc);
        try
        {
           return loc->limg_Offset( index, x, y);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Blend(LXtObjectID wcom,unsigned int index,float *opacity,unsigned int *mode) -> LxResult
    {
        LXCWxINST (CLxImpl_LayeredImage, loc);
        try
        {
           return loc->limg_Blend( index, opacity, mode);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto ChannelName(LXtObjectID wcom,unsigned layerIndex,unsigned channelIndex,const char **name) -> LxResult
    {
        LXCWxINST (CLxImpl_LayeredImage, loc);
        try
        {
           return loc->limg_ChannelName( layerIndex, channelIndex, name);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Parent(LXtObjectID wcom,unsigned layerIndex,int *parentIndex) -> LxResult
    {
        LXCWxINST (CLxImpl_LayeredImage, loc);
        try
        {
           return loc->limg_Parent( layerIndex, parentIndex);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto IsGroup(LXtObjectID wcom,unsigned layerIndex,unsigned int *isGroup) -> LxResult
    {
        LXCWxINST (CLxImpl_LayeredImage, loc);
        try
        {
           return loc->limg_IsGroup( layerIndex, isGroup);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxLayeredImage vt;
};

class CLxLoc_LayeredImage : public CLxLocalize<ILxLayeredImageID>
{
public:
    CLxLoc_LayeredImage()
    {
        _init();
    }

    CLxLoc_LayeredImage(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_LayeredImage(CLxLoc_LayeredImage const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_LayeredImage;
    }

    auto Size(unsigned int *w, unsigned int *h) const -> LxResult
    {
        return m_loc[0]->Size(m_loc, w, h);
    }

    auto Count(void) const -> unsigned int
    {
        return m_loc[0]->Count(m_loc);
    }

    auto Image(unsigned int index, void **ppvObj) -> LxResult
    {
        return m_loc[0]->Image(m_loc, index, ppvObj);
    }

    auto Image(unsigned int index, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Image(m_loc, index, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Name(unsigned int index, const char **name) const -> LxResult
    {
        return m_loc[0]->Name(m_loc, index, name);
    }

    auto Type(unsigned int index, unsigned int *flags, const char **type) const -> LxResult
    {
        return m_loc[0]->Type(m_loc, index, flags, type);
    }

    auto Offset(unsigned int index, int *x, int *y) const -> LxResult
    {
        return m_loc[0]->Offset(m_loc, index, x, y);
    }

    auto Blend(unsigned int index, float *opacity, unsigned int *mode) const -> LxResult
    {
        return m_loc[0]->Blend(m_loc, index, opacity, mode);
    }

    auto ChannelName(unsigned layerIndex, unsigned channelIndex, const char **name) const -> LxResult
    {
        return m_loc[0]->ChannelName(m_loc, layerIndex, channelIndex, name);
    }

    auto Parent(unsigned layerIndex, int *parentIndex) const -> LxResult
    {
        return m_loc[0]->Parent(m_loc, layerIndex, parentIndex);
    }

    auto IsGroup(unsigned layerIndex, unsigned int *isGroup) const -> LxResult
    {
        return m_loc[0]->IsGroup(m_loc, layerIndex, isGroup);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_LayeredImageWrite
{
public:
    virtual ~CLxImpl_LayeredImageWrite() = default;

    virtual auto limgw_AddLayer([[maybe_unused]] ILxUnknownID image, [[maybe_unused]] const char *name, [[maybe_unused]] const char **channelNames) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto limgw_SetType([[maybe_unused]] unsigned int index, [[maybe_unused]] int flags, [[maybe_unused]] const char *type) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto limgw_SetOffset([[maybe_unused]] unsigned int index, [[maybe_unused]] int x, [[maybe_unused]] int y) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto limgw_SetBlending([[maybe_unused]] unsigned int index, [[maybe_unused]] float blend, [[maybe_unused]] const char *mode) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto limgw_AddAttribute([[maybe_unused]] const char *name, [[maybe_unused]] const char *type, [[maybe_unused]] int *index) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_LayeredImageWrite_AddLayer LxResult limgw_AddLayer([[maybe_unused]] ILxUnknownID image, [[maybe_unused]] const char *name, [[maybe_unused]] const char **channelNames) override
#define LXxO_LayeredImageWrite_AddLayer LXxD_LayeredImageWrite_AddLayer
#define LXxC_LayeredImageWrite_AddLayer(c) LxResult c::limgw_AddLayer([[maybe_unused]] ILxUnknownID image, [[maybe_unused]] const char *name, [[maybe_unused]] const char **channelNames)
#define LXxD_LayeredImageWrite_SetType LxResult limgw_SetType([[maybe_unused]] unsigned int index, [[maybe_unused]] int flags, [[maybe_unused]] const char *type) override
#define LXxO_LayeredImageWrite_SetType LXxD_LayeredImageWrite_SetType
#define LXxC_LayeredImageWrite_SetType(c) LxResult c::limgw_SetType([[maybe_unused]] unsigned int index, [[maybe_unused]] int flags, [[maybe_unused]] const char *type)
#define LXxD_LayeredImageWrite_SetOffset LxResult limgw_SetOffset([[maybe_unused]] unsigned int index, [[maybe_unused]] int x, [[maybe_unused]] int y) override
#define LXxO_LayeredImageWrite_SetOffset LXxD_LayeredImageWrite_SetOffset
#define LXxC_LayeredImageWrite_SetOffset(c) LxResult c::limgw_SetOffset([[maybe_unused]] unsigned int index, [[maybe_unused]] int x, [[maybe_unused]] int y)
#define LXxD_LayeredImageWrite_SetBlending LxResult limgw_SetBlending([[maybe_unused]] unsigned int index, [[maybe_unused]] float blend, [[maybe_unused]] const char *mode) override
#define LXxO_LayeredImageWrite_SetBlending LXxD_LayeredImageWrite_SetBlending
#define LXxC_LayeredImageWrite_SetBlending(c) LxResult c::limgw_SetBlending([[maybe_unused]] unsigned int index, [[maybe_unused]] float blend, [[maybe_unused]] const char *mode)
#define LXxD_LayeredImageWrite_AddAttribute LxResult limgw_AddAttribute([[maybe_unused]] const char *name, [[maybe_unused]] const char *type, [[maybe_unused]] int *index) override
#define LXxO_LayeredImageWrite_AddAttribute LXxD_LayeredImageWrite_AddAttribute
#define LXxC_LayeredImageWrite_AddAttribute(c) LxResult c::limgw_AddAttribute([[maybe_unused]] const char *name, [[maybe_unused]] const char *type, [[maybe_unused]] int *index)

template <class T>
class CLxIfc_LayeredImageWrite: public CLxInterface
{
public:
    CLxIfc_LayeredImageWrite()
    {
        vt.AddLayer = AddLayer;
        vt.SetType = SetType;
        vt.SetOffset = SetOffset;
        vt.SetBlending = SetBlending;
        vt.AddAttribute = AddAttribute;
        vTable = &vt.iunk;
        iid = &lx::guid_LayeredImageWrite;
    }

    static auto AddLayer(LXtObjectID wcom,LXtObjectID image,const char *name,const char **channelNames) -> LxResult
    {
        LXCWxINST (CLxImpl_LayeredImageWrite, loc);
        try
        {
           return loc->limgw_AddLayer((ILxUnknownID) image, name, channelNames);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SetType(LXtObjectID wcom,unsigned int index,int flags,const char *type) -> LxResult
    {
        LXCWxINST (CLxImpl_LayeredImageWrite, loc);
        try
        {
           return loc->limgw_SetType( index, flags, type);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SetOffset(LXtObjectID wcom,unsigned int index,int x,int y) -> LxResult
    {
        LXCWxINST (CLxImpl_LayeredImageWrite, loc);
        try
        {
           return loc->limgw_SetOffset( index, x, y);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SetBlending(LXtObjectID wcom,unsigned int index,float blend,const char *mode) -> LxResult
    {
        LXCWxINST (CLxImpl_LayeredImageWrite, loc);
        try
        {
           return loc->limgw_SetBlending( index, blend, mode);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto AddAttribute(LXtObjectID wcom,const char *name,const char *type,int *index) -> LxResult
    {
        LXCWxINST (CLxImpl_LayeredImageWrite, loc);
        try
        {
           return loc->limgw_AddAttribute( name, type, index);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxLayeredImageWrite vt;
};

class CLxLoc_LayeredImageWrite : public CLxLocalize<ILxLayeredImageWriteID>
{
public:
    CLxLoc_LayeredImageWrite()
    {
        _init();
    }

    CLxLoc_LayeredImageWrite(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_LayeredImageWrite(CLxLoc_LayeredImageWrite const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_LayeredImageWrite;
    }

    auto AddLayer(ILxUnknownID image, const char *name, const char **channelNames) -> LxResult
    {
        return m_loc[0]->AddLayer(m_loc,(ILxUnknownID) image, name, channelNames);
    }

    auto SetType(unsigned int index, int flags, const char *type) -> LxResult
    {
        return m_loc[0]->SetType(m_loc, index, flags, type);
    }

    auto SetOffset(unsigned int index, int x, int y) -> LxResult
    {
        return m_loc[0]->SetOffset(m_loc, index, x, y);
    }

    auto SetBlending(unsigned int index, float blend, const char *mode) -> LxResult
    {
        return m_loc[0]->SetBlending(m_loc, index, blend, mode);
    }

    auto AddAttribute(const char *name, const char *type, int *index) -> LxResult
    {
        return m_loc[0]->AddAttribute(m_loc, name, type, index);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_TileImage
{
public:
    virtual ~CLxImpl_TileImage() = default;

    virtual unsigned tileimg_LevelCount(void) = 0;

    virtual auto tileimg_GetTile([[maybe_unused]] unsigned int level, [[maybe_unused]] unsigned int tileX, [[maybe_unused]] unsigned int tileY, [[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto tileimg_GetTileSize([[maybe_unused]] unsigned int level, [[maybe_unused]] unsigned int tileX, [[maybe_unused]] unsigned int tileY, [[maybe_unused]] unsigned int *width, [[maybe_unused]] unsigned int *height) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto tileimg_GetLevelSize([[maybe_unused]] unsigned int level, [[maybe_unused]] unsigned int *width, [[maybe_unused]] unsigned int *height, [[maybe_unused]] unsigned int *tilesWidth, [[maybe_unused]] unsigned int *tilesHeight) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto tileimg_DetermineTile([[maybe_unused]] unsigned int level, [[maybe_unused]] unsigned int x, [[maybe_unused]] unsigned int y, [[maybe_unused]] unsigned int *tileX, [[maybe_unused]] unsigned int *tileY) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto tileimg_DeterminePixel([[maybe_unused]] unsigned int level, [[maybe_unused]] unsigned int x, [[maybe_unused]] unsigned int y, [[maybe_unused]] unsigned int *adjX, [[maybe_unused]] unsigned int *adjY) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_TileImage_LevelCount unsigned tileimg_LevelCount() override
#define LXxO_TileImage_LevelCount LXxD_TileImage_LevelCount
#define LXxC_TileImage_LevelCount(c) unsigned c::tileimg_LevelCount()
#define LXxD_TileImage_GetTile LxResult tileimg_GetTile([[maybe_unused]] unsigned int level, [[maybe_unused]] unsigned int tileX, [[maybe_unused]] unsigned int tileY, [[maybe_unused]] void **ppvObj) override
#define LXxO_TileImage_GetTile LXxD_TileImage_GetTile
#define LXxC_TileImage_GetTile(c) LxResult c::tileimg_GetTile([[maybe_unused]] unsigned int level, [[maybe_unused]] unsigned int tileX, [[maybe_unused]] unsigned int tileY, [[maybe_unused]] void **ppvObj)
#define LXxD_TileImage_GetTileSize LxResult tileimg_GetTileSize([[maybe_unused]] unsigned int level, [[maybe_unused]] unsigned int tileX, [[maybe_unused]] unsigned int tileY, [[maybe_unused]] unsigned int *width, [[maybe_unused]] unsigned int *height) override
#define LXxO_TileImage_GetTileSize LXxD_TileImage_GetTileSize
#define LXxC_TileImage_GetTileSize(c) LxResult c::tileimg_GetTileSize([[maybe_unused]] unsigned int level, [[maybe_unused]] unsigned int tileX, [[maybe_unused]] unsigned int tileY, [[maybe_unused]] unsigned int *width, [[maybe_unused]] unsigned int *height)
#define LXxD_TileImage_GetLevelSize LxResult tileimg_GetLevelSize([[maybe_unused]] unsigned int level, [[maybe_unused]] unsigned int *width, [[maybe_unused]] unsigned int *height, [[maybe_unused]] unsigned int *tilesWidth, [[maybe_unused]] unsigned int *tilesHeight) override
#define LXxO_TileImage_GetLevelSize LXxD_TileImage_GetLevelSize
#define LXxC_TileImage_GetLevelSize(c) LxResult c::tileimg_GetLevelSize([[maybe_unused]] unsigned int level, [[maybe_unused]] unsigned int *width, [[maybe_unused]] unsigned int *height, [[maybe_unused]] unsigned int *tilesWidth, [[maybe_unused]] unsigned int *tilesHeight)
#define LXxD_TileImage_DetermineTile LxResult tileimg_DetermineTile([[maybe_unused]] unsigned int level, [[maybe_unused]] unsigned int x, [[maybe_unused]] unsigned int y, [[maybe_unused]] unsigned int *tileX, [[maybe_unused]] unsigned int *tileY) override
#define LXxO_TileImage_DetermineTile LXxD_TileImage_DetermineTile
#define LXxC_TileImage_DetermineTile(c) LxResult c::tileimg_DetermineTile([[maybe_unused]] unsigned int level, [[maybe_unused]] unsigned int x, [[maybe_unused]] unsigned int y, [[maybe_unused]] unsigned int *tileX, [[maybe_unused]] unsigned int *tileY)
#define LXxD_TileImage_DeterminePixel LxResult tileimg_DeterminePixel([[maybe_unused]] unsigned int level, [[maybe_unused]] unsigned int x, [[maybe_unused]] unsigned int y, [[maybe_unused]] unsigned int *adjX, [[maybe_unused]] unsigned int *adjY) override
#define LXxO_TileImage_DeterminePixel LXxD_TileImage_DeterminePixel
#define LXxC_TileImage_DeterminePixel(c) LxResult c::tileimg_DeterminePixel([[maybe_unused]] unsigned int level, [[maybe_unused]] unsigned int x, [[maybe_unused]] unsigned int y, [[maybe_unused]] unsigned int *adjX, [[maybe_unused]] unsigned int *adjY)

template <class T>
class CLxIfc_TileImage: public CLxInterface
{
public:
    CLxIfc_TileImage()
    {
        vt.LevelCount = LevelCount;
        vt.GetTile = GetTile;
        vt.GetTileSize = GetTileSize;
        vt.GetLevelSize = GetLevelSize;
        vt.DetermineTile = DetermineTile;
        vt.DeterminePixel = DeterminePixel;
        vTable = &vt.iunk;
        iid = &lx::guid_TileImage;
    }

    static auto LevelCount(LXtObjectID wcom) -> unsigned
    {
        LXCWxINST (CLxImpl_TileImage, loc);
        return loc->tileimg_LevelCount();
    }

    static auto GetTile(LXtObjectID wcom,unsigned int level,unsigned int tileX,unsigned int tileY,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_TileImage, loc);
        try
        {
           return loc->tileimg_GetTile( level, tileX, tileY, ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GetTileSize(LXtObjectID wcom,unsigned int level,unsigned int tileX,unsigned int tileY,unsigned int *width,unsigned int *height) -> LxResult
    {
        LXCWxINST (CLxImpl_TileImage, loc);
        try
        {
           return loc->tileimg_GetTileSize( level, tileX, tileY, width, height);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GetLevelSize(LXtObjectID wcom,unsigned int level,unsigned int *width,unsigned int *height,unsigned int *tilesWidth,unsigned int *tilesHeight) -> LxResult
    {
        LXCWxINST (CLxImpl_TileImage, loc);
        try
        {
           return loc->tileimg_GetLevelSize( level, width, height, tilesWidth, tilesHeight);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto DetermineTile(LXtObjectID wcom,unsigned int level,unsigned int x,unsigned int y,unsigned int *tileX,unsigned int *tileY) -> LxResult
    {
        LXCWxINST (CLxImpl_TileImage, loc);
        try
        {
           return loc->tileimg_DetermineTile( level, x, y, tileX, tileY);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto DeterminePixel(LXtObjectID wcom,unsigned int level,unsigned int x,unsigned int y,unsigned int *adjX,unsigned int *adjY) -> LxResult
    {
        LXCWxINST (CLxImpl_TileImage, loc);
        try
        {
           return loc->tileimg_DeterminePixel( level, x, y, adjX, adjY);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxTileImage vt;
};

class CLxLoc_TileImage : public CLxLocalize<ILxTileImageID>
{
public:
    CLxLoc_TileImage()
    {
        _init();
    }

    CLxLoc_TileImage(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_TileImage(CLxLoc_TileImage const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_TileImage;
    }

    auto LevelCount(void) const -> unsigned
    {
        return m_loc[0]->LevelCount(m_loc);
    }

    auto GetTile(unsigned int level, unsigned int tileX, unsigned int tileY, void **ppvObj) const -> LxResult
    {
        return m_loc[0]->GetTile(m_loc, level, tileX, tileY, ppvObj);
    }

    auto GetTile(unsigned int level, unsigned int tileX, unsigned int tileY, CLxLocalizedObject &o_dest) const -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->GetTile(m_loc, level, tileX, tileY, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto GetTileSize(unsigned int level, unsigned int tileX, unsigned int tileY, unsigned int *width, unsigned int *height) const -> LxResult
    {
        return m_loc[0]->GetTileSize(m_loc, level, tileX, tileY, width, height);
    }

    auto GetLevelSize(unsigned int level, unsigned int *width, unsigned int *height, unsigned int *tilesWidth, unsigned int *tilesHeight) const -> LxResult
    {
        return m_loc[0]->GetLevelSize(m_loc, level, width, height, tilesWidth, tilesHeight);
    }

    auto DetermineTile(unsigned int level, unsigned int x, unsigned int y, unsigned int *tileX, unsigned int *tileY) const -> LxResult
    {
        return m_loc[0]->DetermineTile(m_loc, level, x, y, tileX, tileY);
    }

    auto DeterminePixel(unsigned int level, unsigned int x, unsigned int y, unsigned int *adjX, unsigned int *adjY) const -> LxResult
    {
        return m_loc[0]->DeterminePixel(m_loc, level, x, y, adjX, adjY);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_ImageLoaderTarget1 : public CLxLocalize<ILxImageLoaderTarget1ID>
{
public:
    CLxLoc_ImageLoaderTarget1()
    {
        _init();
    }

    CLxLoc_ImageLoaderTarget1(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_ImageLoaderTarget1(CLxLoc_ImageLoaderTarget1 const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_ImageLoaderTarget1;
    }

    auto SetSize(LXtPixelFormat type, unsigned width, unsigned height) -> LxResult
    {
        return m_loc[0]->SetSize(m_loc, type, width, height);
    }

    auto SetMap(unsigned ncolor) -> LxResult
    {
        return m_loc[0]->SetMap(m_loc, ncolor);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_ImageLoaderTarget : public CLxLocalize<ILxImageLoaderTargetID>
{
public:
    CLxLoc_ImageLoaderTarget()
    {
        _init();
    }

    CLxLoc_ImageLoaderTarget(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_ImageLoaderTarget(CLxLoc_ImageLoaderTarget const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_ImageLoaderTarget;
    }

    auto SetSize(LXtPixelFormat type, unsigned width, unsigned height) -> LxResult
    {
        return m_loc[0]->SetSize(m_loc, type, width, height);
    }

    auto SetMap(unsigned ncolor) -> LxResult
    {
        return m_loc[0]->SetMap(m_loc, ncolor);
    }

    auto SetColorspaceDepth(unsigned depth) -> LxResult
    {
        return m_loc[0]->SetColorspaceDepth(m_loc, depth);
    }

    auto SetColorspace(const char *colorspace) -> LxResult
    {
        return m_loc[0]->SetColorspace(m_loc, colorspace);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_ImageLevelSample
{
public:
    virtual ~CLxImpl_ImageLevelSample() = default;

    virtual unsigned level_Count(void) = 0;

    virtual auto level_GetLevelSize([[maybe_unused]] unsigned level, [[maybe_unused]] unsigned *width, [[maybe_unused]] unsigned *height) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto level_SampleLevel([[maybe_unused]] unsigned level, [[maybe_unused]] LXtImageSample *pixel, [[maybe_unused]] unsigned num) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto level_GetPixel([[maybe_unused]] unsigned level, [[maybe_unused]] unsigned int x, [[maybe_unused]] unsigned int y, [[maybe_unused]] LXtPixelFormat type, [[maybe_unused]] void *pixel) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual const LXtImageFloat * level_GetLine(unsigned level, unsigned y, LXtImageFloat *buf) = 0;
};

#define LXxD_ImageLevelSample_Count unsigned level_Count() override
#define LXxO_ImageLevelSample_Count LXxD_ImageLevelSample_Count
#define LXxC_ImageLevelSample_Count(c) unsigned c::level_Count()
#define LXxD_ImageLevelSample_GetLevelSize LxResult level_GetLevelSize([[maybe_unused]] unsigned level, [[maybe_unused]] unsigned *width, [[maybe_unused]] unsigned *height) override
#define LXxO_ImageLevelSample_GetLevelSize LXxD_ImageLevelSample_GetLevelSize
#define LXxC_ImageLevelSample_GetLevelSize(c) LxResult c::level_GetLevelSize([[maybe_unused]] unsigned level, [[maybe_unused]] unsigned *width, [[maybe_unused]] unsigned *height)
#define LXxD_ImageLevelSample_SampleLevel LxResult level_SampleLevel([[maybe_unused]] unsigned level, [[maybe_unused]] LXtImageSample *pixel, [[maybe_unused]] unsigned num) override
#define LXxO_ImageLevelSample_SampleLevel LXxD_ImageLevelSample_SampleLevel
#define LXxC_ImageLevelSample_SampleLevel(c) LxResult c::level_SampleLevel([[maybe_unused]] unsigned level, [[maybe_unused]] LXtImageSample *pixel, [[maybe_unused]] unsigned num)
#define LXxD_ImageLevelSample_GetPixel LxResult level_GetPixel([[maybe_unused]] unsigned level, [[maybe_unused]] unsigned int x, [[maybe_unused]] unsigned int y, [[maybe_unused]] LXtPixelFormat type, [[maybe_unused]] void *pixel) override
#define LXxO_ImageLevelSample_GetPixel LXxD_ImageLevelSample_GetPixel
#define LXxC_ImageLevelSample_GetPixel(c) LxResult c::level_GetPixel([[maybe_unused]] unsigned level, [[maybe_unused]] unsigned int x, [[maybe_unused]] unsigned int y, [[maybe_unused]] LXtPixelFormat type, [[maybe_unused]] void *pixel)
#define LXxD_ImageLevelSample_GetLine const LXtImageFloat * level_GetLine([[maybe_unused]] unsigned level, [[maybe_unused]] unsigned y, [[maybe_unused]] LXtImageFloat *buf) override
#define LXxO_ImageLevelSample_GetLine LXxD_ImageLevelSample_GetLine
#define LXxC_ImageLevelSample_GetLine(c) const LXtImageFloat * c::level_GetLine([[maybe_unused]] unsigned level, [[maybe_unused]] unsigned y, [[maybe_unused]] LXtImageFloat *buf)

template <class T>
class CLxIfc_ImageLevelSample: public CLxInterface
{
public:
    CLxIfc_ImageLevelSample()
    {
        vt.Count = Count;
        vt.GetLevelSize = GetLevelSize;
        vt.SampleLevel = SampleLevel;
        vt.GetPixel = GetPixel;
        vt.GetLine = GetLine;
        vTable = &vt.iunk;
        iid = &lx::guid_ImageLevelSample;
    }

    static auto Count(LXtObjectID wcom) -> unsigned
    {
        LXCWxINST (CLxImpl_ImageLevelSample, loc);
        return loc->level_Count();
    }

    static auto GetLevelSize(LXtObjectID wcom,unsigned level,unsigned *width,unsigned *height) -> LxResult
    {
        LXCWxINST (CLxImpl_ImageLevelSample, loc);
        try
        {
           return loc->level_GetLevelSize( level, width, height);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SampleLevel(LXtObjectID wcom,unsigned level,LXtImageSample *pixel,unsigned num) -> LxResult
    {
        LXCWxINST (CLxImpl_ImageLevelSample, loc);
        try
        {
           return loc->level_SampleLevel( level, pixel, num);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GetPixel(LXtObjectID wcom,unsigned level,unsigned int x,unsigned int y,LXtPixelFormat type,void *pixel) -> LxResult
    {
        LXCWxINST (CLxImpl_ImageLevelSample, loc);
        try
        {
           return loc->level_GetPixel( level, x, y, type, pixel);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto GetLine(LXtObjectID wcom,unsigned level,unsigned y,LXtImageFloat *buf) -> const LXtImageFloat *
    {
        LXCWxINST (CLxImpl_ImageLevelSample, loc);
        return loc->level_GetLine( level, y, buf);
    }

private:
    ILxImageLevelSample vt;
};

class CLxLoc_ImageLevelSample : public CLxLocalize<ILxImageLevelSampleID>
{
public:
    CLxLoc_ImageLevelSample()
    {
        _init();
    }

    CLxLoc_ImageLevelSample(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_ImageLevelSample(CLxLoc_ImageLevelSample const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_ImageLevelSample;
    }

    auto Count(void) const -> unsigned
    {
        return m_loc[0]->Count(m_loc);
    }

    auto GetLevelSize(unsigned level, unsigned *width, unsigned *height) const -> LxResult
    {
        return m_loc[0]->GetLevelSize(m_loc, level, width, height);
    }

    auto SampleLevel(unsigned level, LXtImageSample *pixel, unsigned num) const -> LxResult
    {
        return m_loc[0]->SampleLevel(m_loc, level, pixel, num);
    }

    auto GetPixel(unsigned level, unsigned int x, unsigned int y, LXtPixelFormat type, void *pixel) const -> LxResult
    {
        return m_loc[0]->GetPixel(m_loc, level, x, y, type, pixel);
    }

    auto GetLine(unsigned level, unsigned y, LXtImageFloat *buf) const -> const LXtImageFloat *
    {
        return m_loc[0]->GetLine(m_loc, level, y, buf);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_ImageService : public CLxLocalizedService
{
public:
    ILxImageServiceID m_loc{ nullptr };

public:
    CLxLoc_ImageService()
    {
        _init();
        set();
    }

    ~CLxLoc_ImageService() = default;

    void set()
    {
        if (!m_loc)
        {
            m_loc = reinterpret_cast<ILxImageServiceID>(lx::GetGlobal(&lx::guid_ImageService));
        }
    }

    auto ScriptQuery(void **ppvObj) -> LxResult
    {
        return m_loc[0]->ScriptQuery(m_loc, ppvObj);
    }

    auto ScriptQuery(CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->ScriptQuery(m_loc, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Create(unsigned int width, unsigned int height, LXtPixelFormat type, unsigned int maxIndex, void **ppvObj) -> LxResult
    {
        return m_loc[0]->Create(m_loc, width, height, type, maxIndex, ppvObj);
    }

    auto Create(unsigned int width, unsigned int height, LXtPixelFormat type, unsigned int maxIndex, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Create(m_loc, width, height, type, maxIndex, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Duplicate(ILxUnknownID source, LXtPixelFormat type, void **ppvObj) -> LxResult
    {
        return m_loc[0]->Duplicate(m_loc,(ILxUnknownID) source, type, ppvObj);
    }

    auto Duplicate(ILxUnknownID source, LXtPixelFormat type, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Duplicate(m_loc,(ILxUnknownID) source, type, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Load(const char *filePath, void **ppvObj) -> LxResult
    {
        return m_loc[0]->Load(m_loc, filePath, ppvObj);
    }

    auto Load(const char *filePath, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Load(m_loc, filePath, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto Save(ILxUnknownID image, const char *filePath, const char *format, ILxUnknownID monitor) -> LxResult
    {
        return m_loc[0]->Save(m_loc,(ILxUnknownID) image, filePath, format,(ILxUnknownID) monitor);
    }

    auto Resample(ILxUnknownID dest, ILxUnknownID source, LXtProcessHint hint) -> LxResult
    {
        return m_loc[0]->Resample(m_loc,(ILxUnknownID) dest,(ILxUnknownID) source, hint);
    }

    auto Composite(ILxUnknownID dest, ILxUnknownID source, const LXtFVector2 pos) -> LxResult
    {
        return m_loc[0]->Composite(m_loc,(ILxUnknownID) dest,(ILxUnknownID) source, pos);
    }

    auto DrawLine(ILxUnknownID image, const LXtFVector2 p0, const LXtFVector2 p1, const LXtFVector color) -> LxResult
    {
        return m_loc[0]->DrawLine(m_loc,(ILxUnknownID) image, p0, p1, color);
    }

    auto Kelvin2RGB(float kelvin, LXtFVector rgbColor) -> LxResult
    {
        return m_loc[0]->Kelvin2RGB(m_loc, kelvin, rgbColor);
    }

    auto RGB2Kelvin(const LXtFVector rgbColor, float *kelvin) -> LxResult
    {
        return m_loc[0]->RGB2Kelvin(m_loc, rgbColor, kelvin);
    }

    auto CreateCrop(ILxUnknownID sourceImage, double x, double y, double w, double h, void **ppvObj) -> LxResult
    {
        return m_loc[0]->CreateCrop(m_loc,(ILxUnknownID) sourceImage, x, y, w, h, ppvObj);
    }

    auto CreateCrop(ILxUnknownID sourceImage, double x, double y, double w, double h, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->CreateCrop(m_loc,(ILxUnknownID) sourceImage, x, y, w, h, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto ImageGetBuffer(ILxUnknownID sourceImage, LXtPixelFormat type, void *buf) -> LxResult
    {
        return m_loc[0]->ImageGetBuffer(m_loc,(ILxUnknownID) sourceImage, type, buf);
    }

    auto LoadNoCache(const char *filePath, void **ppvObj) -> LxResult
    {
        return m_loc[0]->LoadNoCache(m_loc, filePath, ppvObj);
    }

    auto LoadNoCache(const char *filePath, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->LoadNoCache(m_loc, filePath, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto CreateLayered(unsigned int width, unsigned int height, unsigned int layerNum, void **ppvObj) -> LxResult
    {
        return m_loc[0]->CreateLayered(m_loc, width, height, layerNum, ppvObj);
    }

    auto CreateLayered(unsigned int width, unsigned int height, unsigned int layerNum, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->CreateLayered(m_loc, width, height, layerNum, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto SaveLayered(ILxUnknownID layeredImage, const char *filePath, const char *format, ILxUnknownID monitor) -> LxResult
    {
        return m_loc[0]->SaveLayered(m_loc,(ILxUnknownID) layeredImage, filePath, format,(ILxUnknownID) monitor);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_ImageBlockCodec
{
public:
    virtual ~CLxImpl_ImageBlockCodec() = default;

    virtual auto ibc_Compress([[maybe_unused]] ILxUnknownID image, [[maybe_unused]] unsigned char **buf, [[maybe_unused]] int *size) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual void ibc_Free([[maybe_unused]] unsigned char *buf, [[maybe_unused]] int size)
    {
    }

    virtual auto ibc_Decompress([[maybe_unused]] unsigned char *buf, [[maybe_unused]] int size, [[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_ImageBlockCodec_Compress LxResult ibc_Compress([[maybe_unused]] ILxUnknownID image, [[maybe_unused]] unsigned char **buf, [[maybe_unused]] int *size) override
#define LXxO_ImageBlockCodec_Compress LXxD_ImageBlockCodec_Compress
#define LXxC_ImageBlockCodec_Compress(c) LxResult c::ibc_Compress([[maybe_unused]] ILxUnknownID image, [[maybe_unused]] unsigned char **buf, [[maybe_unused]] int *size)
#define LXxD_ImageBlockCodec_Free void ibc_Free([[maybe_unused]] unsigned char *buf, [[maybe_unused]] int size) override
#define LXxO_ImageBlockCodec_Free LXxD_ImageBlockCodec_Free
#define LXxC_ImageBlockCodec_Free(c) void c::ibc_Free([[maybe_unused]] unsigned char *buf, [[maybe_unused]] int size)
#define LXxD_ImageBlockCodec_Decompress LxResult ibc_Decompress([[maybe_unused]] unsigned char *buf, [[maybe_unused]] int size, [[maybe_unused]] void **ppvObj) override
#define LXxO_ImageBlockCodec_Decompress LXxD_ImageBlockCodec_Decompress
#define LXxC_ImageBlockCodec_Decompress(c) LxResult c::ibc_Decompress([[maybe_unused]] unsigned char *buf, [[maybe_unused]] int size, [[maybe_unused]] void **ppvObj)

template <class T>
class CLxIfc_ImageBlockCodec: public CLxInterface
{
public:
    CLxIfc_ImageBlockCodec()
    {
        vt.Compress = Compress;
        vt.Free = Free;
        vt.Decompress = Decompress;
        vTable = &vt.iunk;
        iid = &lx::guid_ImageBlockCodec;
    }

    static auto Compress(LXtObjectID wcom,LXtObjectID image,unsigned char **buf,int *size) -> LxResult
    {
        LXCWxINST (CLxImpl_ImageBlockCodec, loc);
        try
        {
           return loc->ibc_Compress((ILxUnknownID) image, buf, size);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Free(LXtObjectID wcom,unsigned char *buf,int size) -> void
    {
        LXCWxINST (CLxImpl_ImageBlockCodec, loc);
        loc->ibc_Free( buf, size);
    }

    static auto Decompress(LXtObjectID wcom,unsigned char *buf,int size,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_ImageBlockCodec, loc);
        try
        {
           return loc->ibc_Decompress( buf, size, ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxImageBlockCodec vt;
};


class CLxImpl_ImageFilter
{
public:
    virtual ~CLxImpl_ImageFilter() = default;

    virtual unsigned int imf_Type(void) = 0;

    virtual auto imf_Generate([[maybe_unused]] int width, [[maybe_unused]] int height, [[maybe_unused]] ILxUnknownID monitor, [[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto imf_MultiSample([[maybe_unused]] ILxUnknownID monitor, [[maybe_unused]] ILxUnknownID image, [[maybe_unused]] void **ppvObj) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto imf_SingleSample([[maybe_unused]] const LXtColorRGBA src, [[maybe_unused]] LXtColorRGBA dest) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto imf_SingleSampleN([[maybe_unused]] const LXtImageFloat *src, [[maybe_unused]] LXtImageFloat *dest, [[maybe_unused]] unsigned num) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_ImageFilter_Type unsigned int imf_Type() override
#define LXxO_ImageFilter_Type LXxD_ImageFilter_Type
#define LXxC_ImageFilter_Type(c) unsigned int c::imf_Type()
#define LXxD_ImageFilter_Generate LxResult imf_Generate([[maybe_unused]] int width, [[maybe_unused]] int height, [[maybe_unused]] ILxUnknownID monitor, [[maybe_unused]] void **ppvObj) override
#define LXxO_ImageFilter_Generate LXxD_ImageFilter_Generate
#define LXxC_ImageFilter_Generate(c) LxResult c::imf_Generate([[maybe_unused]] int width, [[maybe_unused]] int height, [[maybe_unused]] ILxUnknownID monitor, [[maybe_unused]] void **ppvObj)
#define LXxD_ImageFilter_MultiSample LxResult imf_MultiSample([[maybe_unused]] ILxUnknownID monitor, [[maybe_unused]] ILxUnknownID image, [[maybe_unused]] void **ppvObj) override
#define LXxO_ImageFilter_MultiSample LXxD_ImageFilter_MultiSample
#define LXxC_ImageFilter_MultiSample(c) LxResult c::imf_MultiSample([[maybe_unused]] ILxUnknownID monitor, [[maybe_unused]] ILxUnknownID image, [[maybe_unused]] void **ppvObj)
#define LXxD_ImageFilter_SingleSample LxResult imf_SingleSample([[maybe_unused]] const LXtColorRGBA src, [[maybe_unused]] LXtColorRGBA dest) override
#define LXxO_ImageFilter_SingleSample LXxD_ImageFilter_SingleSample
#define LXxC_ImageFilter_SingleSample(c) LxResult c::imf_SingleSample([[maybe_unused]] const LXtColorRGBA src, [[maybe_unused]] LXtColorRGBA dest)
#define LXxD_ImageFilter_SingleSampleN LxResult imf_SingleSampleN([[maybe_unused]] const LXtImageFloat *src, [[maybe_unused]] LXtImageFloat *dest, [[maybe_unused]] unsigned num) override
#define LXxO_ImageFilter_SingleSampleN LXxD_ImageFilter_SingleSampleN
#define LXxC_ImageFilter_SingleSampleN(c) LxResult c::imf_SingleSampleN([[maybe_unused]] const LXtImageFloat *src, [[maybe_unused]] LXtImageFloat *dest, [[maybe_unused]] unsigned num)

template <class T>
class CLxIfc_ImageFilter: public CLxInterface
{
public:
    CLxIfc_ImageFilter()
    {
        vt.Type = Type;
        vt.Generate = Generate;
        vt.MultiSample = MultiSample;
        vt.SingleSample = SingleSample;
        vt.SingleSampleN = SingleSampleN;
        vTable = &vt.iunk;
        iid = &lx::guid_ImageFilter;
    }

    static auto Type(LXtObjectID wcom) -> unsigned int
    {
        LXCWxINST (CLxImpl_ImageFilter, loc);
        return loc->imf_Type();
    }

    static auto Generate(LXtObjectID wcom,int width,int height,LXtObjectID monitor,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_ImageFilter, loc);
        try
        {
           return loc->imf_Generate( width, height,(ILxUnknownID) monitor, ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto MultiSample(LXtObjectID wcom,LXtObjectID monitor,LXtObjectID image,void **ppvObj) -> LxResult
    {
        LXCWxINST (CLxImpl_ImageFilter, loc);
        try
        {
           return loc->imf_MultiSample((ILxUnknownID) monitor,(ILxUnknownID) image, ppvObj);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SingleSample(LXtObjectID wcom,const LXtColorRGBA src,LXtColorRGBA dest) -> LxResult
    {
        LXCWxINST (CLxImpl_ImageFilter, loc);
        try
        {
           return loc->imf_SingleSample( src, dest);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SingleSampleN(LXtObjectID wcom,const LXtImageFloat *src,LXtImageFloat *dest,unsigned num) -> LxResult
    {
        LXCWxINST (CLxImpl_ImageFilter, loc);
        try
        {
           return loc->imf_SingleSampleN( src, dest, num);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxImageFilter vt;
};

class CLxLoc_ImageFilter : public CLxLocalize<ILxImageFilterID>
{
public:
    CLxLoc_ImageFilter()
    {
        _init();
    }

    CLxLoc_ImageFilter(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_ImageFilter(CLxLoc_ImageFilter const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_ImageFilter;
    }

    auto Type(void) -> unsigned int
    {
        return m_loc[0]->Type(m_loc);
    }

    auto Generate(int width, int height, ILxUnknownID monitor, void **ppvObj) -> LxResult
    {
        return m_loc[0]->Generate(m_loc, width, height,(ILxUnknownID) monitor, ppvObj);
    }

    auto Generate(int width, int height, ILxUnknownID monitor, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Generate(m_loc, width, height,(ILxUnknownID) monitor, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto MultiSample(ILxUnknownID monitor, ILxUnknownID image, void **ppvObj) -> LxResult
    {
        return m_loc[0]->MultiSample(m_loc,(ILxUnknownID) monitor,(ILxUnknownID) image, ppvObj);
    }

    auto MultiSample(ILxUnknownID monitor, ILxUnknownID image, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->MultiSample(m_loc,(ILxUnknownID) monitor,(ILxUnknownID) image, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto SingleSample(const LXtColorRGBA src, LXtColorRGBA dest) -> LxResult
    {
        return m_loc[0]->SingleSample(m_loc, src, dest);
    }

    auto SingleSampleN(const LXtImageFloat *src, LXtImageFloat *dest, unsigned num) -> LxResult
    {
        return m_loc[0]->SingleSampleN(m_loc, src, dest, num);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};

class CLxImpl_ImageFilterMetrics
{
public:
    virtual ~CLxImpl_ImageFilterMetrics() = default;

    virtual auto imfmet_Generate([[maybe_unused]] LXtImageMetrics *metrics) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto imfmet_Evaluate([[maybe_unused]] LXtImageMetrics *metrics) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_ImageFilterMetrics_Generate LxResult imfmet_Generate([[maybe_unused]] LXtImageMetrics *metrics) override
#define LXxO_ImageFilterMetrics_Generate LXxD_ImageFilterMetrics_Generate
#define LXxC_ImageFilterMetrics_Generate(c) LxResult c::imfmet_Generate([[maybe_unused]] LXtImageMetrics *metrics)
#define LXxD_ImageFilterMetrics_Evaluate LxResult imfmet_Evaluate([[maybe_unused]] LXtImageMetrics *metrics) override
#define LXxO_ImageFilterMetrics_Evaluate LXxD_ImageFilterMetrics_Evaluate
#define LXxC_ImageFilterMetrics_Evaluate(c) LxResult c::imfmet_Evaluate([[maybe_unused]] LXtImageMetrics *metrics)

template <class T>
class CLxIfc_ImageFilterMetrics: public CLxInterface
{
public:
    CLxIfc_ImageFilterMetrics()
    {
        vt.Generate = Generate;
        vt.Evaluate = Evaluate;
        vTable = &vt.iunk;
        iid = &lx::guid_ImageFilterMetrics;
    }

    static auto Generate(LXtObjectID wcom,LXtImageMetrics *metrics) -> LxResult
    {
        LXCWxINST (CLxImpl_ImageFilterMetrics, loc);
        try
        {
           return loc->imfmet_Generate( metrics);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Evaluate(LXtObjectID wcom,LXtImageMetrics *metrics) -> LxResult
    {
        LXCWxINST (CLxImpl_ImageFilterMetrics, loc);
        try
        {
           return loc->imfmet_Evaluate( metrics);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxImageFilterMetrics vt;
};

class CLxLoc_ImageFilterMetrics : public CLxLocalize<ILxImageFilterMetricsID>
{
public:
    CLxLoc_ImageFilterMetrics()
    {
        _init();
    }

    CLxLoc_ImageFilterMetrics(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_ImageFilterMetrics(CLxLoc_ImageFilterMetrics const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_ImageFilterMetrics;
    }

    auto Generate(LXtImageMetrics *metrics) -> LxResult
    {
        return m_loc[0]->Generate(m_loc, metrics);
    }

    auto Evaluate(LXtImageMetrics *metrics) -> LxResult
    {
        return m_loc[0]->Evaluate(m_loc, metrics);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};

class CLxImpl_Movie
{
public:
    virtual ~CLxImpl_Movie() = default;

    virtual auto mov_BeginMovie([[maybe_unused]] const char *fname, [[maybe_unused]] int w, [[maybe_unused]] int h, [[maybe_unused]] int flags) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto mov_SetFramerate([[maybe_unused]] int frate) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto mov_AddImage([[maybe_unused]] ILxUnknownID image) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto mov_EndMovie([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto mov_AddAudio([[maybe_unused]] ILxUnknownID audio) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_Movie_BeginMovie LxResult mov_BeginMovie([[maybe_unused]] const char *fname, [[maybe_unused]] int w, [[maybe_unused]] int h, [[maybe_unused]] int flags) override
#define LXxO_Movie_BeginMovie LXxD_Movie_BeginMovie
#define LXxC_Movie_BeginMovie(c) LxResult c::mov_BeginMovie([[maybe_unused]] const char *fname, [[maybe_unused]] int w, [[maybe_unused]] int h, [[maybe_unused]] int flags)
#define LXxD_Movie_SetFramerate LxResult mov_SetFramerate([[maybe_unused]] int frate) override
#define LXxO_Movie_SetFramerate LXxD_Movie_SetFramerate
#define LXxC_Movie_SetFramerate(c) LxResult c::mov_SetFramerate([[maybe_unused]] int frate)
#define LXxD_Movie_AddImage LxResult mov_AddImage([[maybe_unused]] ILxUnknownID image) override
#define LXxO_Movie_AddImage LXxD_Movie_AddImage
#define LXxC_Movie_AddImage(c) LxResult c::mov_AddImage([[maybe_unused]] ILxUnknownID image)
#define LXxD_Movie_EndMovie LxResult mov_EndMovie() override
#define LXxO_Movie_EndMovie LXxD_Movie_EndMovie
#define LXxC_Movie_EndMovie(c) LxResult c::mov_EndMovie()
#define LXxD_Movie_AddAudio LxResult mov_AddAudio([[maybe_unused]] ILxUnknownID audio) override
#define LXxO_Movie_AddAudio LXxD_Movie_AddAudio
#define LXxC_Movie_AddAudio(c) LxResult c::mov_AddAudio([[maybe_unused]] ILxUnknownID audio)

template <class T>
class CLxIfc_Movie: public CLxInterface
{
public:
    CLxIfc_Movie()
    {
        vt.BeginMovie = BeginMovie;
        vt.SetFramerate = SetFramerate;
        vt.AddImage = AddImage;
        vt.EndMovie = EndMovie;
        vt.AddAudio = AddAudio;
        vTable = &vt.iunk;
        iid = &lx::guid_Movie;
    }

    static auto BeginMovie(LXtObjectID wcom,const char *fname,int w,int h,int flags) -> LxResult
    {
        LXCWxINST (CLxImpl_Movie, loc);
        try
        {
           return loc->mov_BeginMovie( fname, w, h, flags);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SetFramerate(LXtObjectID wcom,int frate) -> LxResult
    {
        LXCWxINST (CLxImpl_Movie, loc);
        try
        {
           return loc->mov_SetFramerate( frate);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto AddImage(LXtObjectID wcom,LXtObjectID image) -> LxResult
    {
        LXCWxINST (CLxImpl_Movie, loc);
        try
        {
           return loc->mov_AddImage((ILxUnknownID) image);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto EndMovie(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_Movie, loc);
        try
        {
           return loc->mov_EndMovie();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto AddAudio(LXtObjectID wcom,LXtObjectID audio) -> LxResult
    {
        LXCWxINST (CLxImpl_Movie, loc);
        try
        {
           return loc->mov_AddAudio((ILxUnknownID) audio);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxMovie vt;
};


