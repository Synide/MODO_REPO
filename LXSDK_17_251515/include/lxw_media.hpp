//
// C++ wrapper for lxsdk/lxmedia.h.
//
//	Copyright 2024.
//
//
#pragma once

#include <lxmedia.h>
#include <lx_wrap.hpp>
#include <string>

namespace lx
{
    static LXtGUID const guid_AudioLoaderTarget = {0xEDD92652, {0x76A0, 0x471B}, {0xB0, 0x2C, 0xF4, 0x7C, 0xCC, 0x16, 0xA8, 0x60}};
    static LXtGUID const guid_Audio = {0xABADACB8, {0xA93D, 0x45B1}, {0xB7, 0x76, 0x34, 0x7C, 0xBE, 0x76, 0x1B, 0x13}};
    static LXtGUID const guid_AudioWrite = {0xB1C160A8, {0x6FF3, 0x4C54}, {0xB8, 0x17, 0x8C, 0x17, 0xA4, 0x9A, 0xB1, 0xD6}};
    static LXtGUID const guid_AudioDevice = {0x5CBC3BC8, {0x95BB, 0x4F24}, {0xB1, 0xA4, 0x84, 0x74, 0x70, 0x8E, 0xDE, 0x3A}};
    static LXtGUID const guid_AudioHandle = {0x6A7F9318, {0xA9CF, 0x44CA}, {0x9F, 0x71, 0x32, 0x00, 0x61, 0x02, 0xFF, 0x24}};
} // namespace lx

class CLxLoc_AudioLoaderTarget : public CLxLocalize<ILxAudioLoaderTargetID>
{
public:
    CLxLoc_AudioLoaderTarget()
    {
        _init();
    }

    CLxLoc_AudioLoaderTarget(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_AudioLoaderTarget(CLxLoc_AudioLoaderTarget const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_AudioLoaderTarget;
    }

    auto SetChannels(unsigned channels) -> LxResult
    {
        return m_loc[0]->SetChannels(m_loc, channels);
    }

    auto SetType(unsigned type) -> LxResult
    {
        return m_loc[0]->SetType(m_loc, type);
    }

    auto SetFrequency(unsigned frequency) -> LxResult
    {
        return m_loc[0]->SetFrequency(m_loc, frequency);
    }

    auto SetSamples(unsigned samples) -> LxResult
    {
        return m_loc[0]->SetSamples(m_loc, samples);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_Audio
{
public:
    virtual ~CLxImpl_Audio() = default;

    virtual unsigned int audio_Channels(void) = 0;

    virtual unsigned int audio_Type(void) = 0;

    virtual unsigned int audio_Frequency(void) = 0;

    virtual double audio_TrimStart(void) = 0;

    virtual double audio_Duration(void) = 0;

    virtual const char * audio_Filename(void) = 0;

    virtual unsigned int audio_Size(void) = 0;

    virtual const void * audio_Data(void) = 0;

    virtual auto audio_Sample([[maybe_unused]] double time, [[maybe_unused]] unsigned int type, [[maybe_unused]] void *value) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual void audio_Seek([[maybe_unused]] unsigned int frame)
    {
    }

    virtual unsigned int audio_Tell(void) = 0;

    virtual auto audio_Read([[maybe_unused]] unsigned int *frames, [[maybe_unused]] void *buff, [[maybe_unused]] int *eof) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual void audio_Metrics([[maybe_unused]] LXtAudioMetrics *metrics)
    {
    }
};

#define LXxD_Audio_Channels unsigned int audio_Channels() override
#define LXxO_Audio_Channels LXxD_Audio_Channels
#define LXxC_Audio_Channels(c) unsigned int c::audio_Channels()
#define LXxD_Audio_Type unsigned int audio_Type() override
#define LXxO_Audio_Type LXxD_Audio_Type
#define LXxC_Audio_Type(c) unsigned int c::audio_Type()
#define LXxD_Audio_Frequency unsigned int audio_Frequency() override
#define LXxO_Audio_Frequency LXxD_Audio_Frequency
#define LXxC_Audio_Frequency(c) unsigned int c::audio_Frequency()
#define LXxD_Audio_TrimStart double audio_TrimStart() override
#define LXxO_Audio_TrimStart LXxD_Audio_TrimStart
#define LXxC_Audio_TrimStart(c) double c::audio_TrimStart()
#define LXxD_Audio_Duration double audio_Duration() override
#define LXxO_Audio_Duration LXxD_Audio_Duration
#define LXxC_Audio_Duration(c) double c::audio_Duration()
#define LXxD_Audio_Filename const char * audio_Filename() override
#define LXxO_Audio_Filename LXxD_Audio_Filename
#define LXxC_Audio_Filename(c) const char * c::audio_Filename()
#define LXxD_Audio_Size unsigned int audio_Size() override
#define LXxO_Audio_Size LXxD_Audio_Size
#define LXxC_Audio_Size(c) unsigned int c::audio_Size()
#define LXxD_Audio_Data const void * audio_Data() override
#define LXxO_Audio_Data LXxD_Audio_Data
#define LXxC_Audio_Data(c) const void * c::audio_Data()
#define LXxD_Audio_Sample LxResult audio_Sample([[maybe_unused]] double time, [[maybe_unused]] unsigned int type, [[maybe_unused]] void *value) override
#define LXxO_Audio_Sample LXxD_Audio_Sample
#define LXxC_Audio_Sample(c) LxResult c::audio_Sample([[maybe_unused]] double time, [[maybe_unused]] unsigned int type, [[maybe_unused]] void *value)
#define LXxD_Audio_Seek void audio_Seek([[maybe_unused]] unsigned int frame) override
#define LXxO_Audio_Seek LXxD_Audio_Seek
#define LXxC_Audio_Seek(c) void c::audio_Seek([[maybe_unused]] unsigned int frame)
#define LXxD_Audio_Tell unsigned int audio_Tell() override
#define LXxO_Audio_Tell LXxD_Audio_Tell
#define LXxC_Audio_Tell(c) unsigned int c::audio_Tell()
#define LXxD_Audio_Read LxResult audio_Read([[maybe_unused]] unsigned int *frames, [[maybe_unused]] void *buff, [[maybe_unused]] int *eof) override
#define LXxO_Audio_Read LXxD_Audio_Read
#define LXxC_Audio_Read(c) LxResult c::audio_Read([[maybe_unused]] unsigned int *frames, [[maybe_unused]] void *buff, [[maybe_unused]] int *eof)
#define LXxD_Audio_Metrics void audio_Metrics([[maybe_unused]] LXtAudioMetrics *metrics) override
#define LXxO_Audio_Metrics LXxD_Audio_Metrics
#define LXxC_Audio_Metrics(c) void c::audio_Metrics([[maybe_unused]] LXtAudioMetrics *metrics)

template <class T>
class CLxIfc_Audio: public CLxInterface
{
public:
    CLxIfc_Audio()
    {
        vt.Channels = Channels;
        vt.Type = Type;
        vt.Frequency = Frequency;
        vt.TrimStart = TrimStart;
        vt.Duration = Duration;
        vt.Filename = Filename;
        vt.Size = Size;
        vt.Data = Data;
        vt.Sample = Sample;
        vt.Seek = Seek;
        vt.Tell = Tell;
        vt.Read = Read;
        vt.Metrics = Metrics;
        vTable = &vt.iunk;
        iid = &lx::guid_Audio;
    }

    static auto Channels(LXtObjectID wcom) -> unsigned int
    {
        LXCWxINST (CLxImpl_Audio, loc);
        return loc->audio_Channels();
    }

    static auto Type(LXtObjectID wcom) -> unsigned int
    {
        LXCWxINST (CLxImpl_Audio, loc);
        return loc->audio_Type();
    }

    static auto Frequency(LXtObjectID wcom) -> unsigned int
    {
        LXCWxINST (CLxImpl_Audio, loc);
        return loc->audio_Frequency();
    }

    static auto TrimStart(LXtObjectID wcom) -> double
    {
        LXCWxINST (CLxImpl_Audio, loc);
        return loc->audio_TrimStart();
    }

    static auto Duration(LXtObjectID wcom) -> double
    {
        LXCWxINST (CLxImpl_Audio, loc);
        return loc->audio_Duration();
    }

    static auto Filename(LXtObjectID wcom) -> const char *
    {
        LXCWxINST (CLxImpl_Audio, loc);
        return loc->audio_Filename();
    }

    static auto Size(LXtObjectID wcom) -> unsigned int
    {
        LXCWxINST (CLxImpl_Audio, loc);
        return loc->audio_Size();
    }

    static auto Data(LXtObjectID wcom) -> const void *
    {
        LXCWxINST (CLxImpl_Audio, loc);
        return loc->audio_Data();
    }

    static auto Sample(LXtObjectID wcom,double time,unsigned int type,void *value) -> LxResult
    {
        LXCWxINST (CLxImpl_Audio, loc);
        try
        {
           return loc->audio_Sample( time, type, value);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Seek(LXtObjectID wcom,unsigned int frame) -> void
    {
        LXCWxINST (CLxImpl_Audio, loc);
        loc->audio_Seek( frame);
    }

    static auto Tell(LXtObjectID wcom) -> unsigned int
    {
        LXCWxINST (CLxImpl_Audio, loc);
        return loc->audio_Tell();
    }

    static auto Read(LXtObjectID wcom,unsigned int *frames,void *buff,int *eof) -> LxResult
    {
        LXCWxINST (CLxImpl_Audio, loc);
        try
        {
           return loc->audio_Read( frames, buff, eof);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Metrics(LXtObjectID wcom,LXtAudioMetrics *metrics) -> void
    {
        LXCWxINST (CLxImpl_Audio, loc);
        loc->audio_Metrics( metrics);
    }

private:
    ILxAudio vt;
};

class CLxLoc_Audio : public CLxLocalize<ILxAudioID>
{
public:
    CLxLoc_Audio()
    {
        _init();
    }

    CLxLoc_Audio(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_Audio(CLxLoc_Audio const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_Audio;
    }

    auto Channels(void) -> unsigned int
    {
        return m_loc[0]->Channels(m_loc);
    }

    auto Type(void) -> unsigned int
    {
        return m_loc[0]->Type(m_loc);
    }

    auto Frequency(void) -> unsigned int
    {
        return m_loc[0]->Frequency(m_loc);
    }

    auto TrimStart(void) -> double
    {
        return m_loc[0]->TrimStart(m_loc);
    }

    auto Duration(void) -> double
    {
        return m_loc[0]->Duration(m_loc);
    }

    auto Filename(void) -> const char *
    {
        return m_loc[0]->Filename(m_loc);
    }

    auto Size(void) -> unsigned int
    {
        return m_loc[0]->Size(m_loc);
    }

    auto Data(void) -> const void *
    {
        return m_loc[0]->Data(m_loc);
    }

    auto Sample(double time, unsigned int type, void *value) -> LxResult
    {
        return m_loc[0]->Sample(m_loc, time, type, value);
    }

    auto Seek(unsigned int frame) -> void
    {
        m_loc[0]->Seek(m_loc, frame);
    }

    auto Tell(void) -> unsigned int
    {
        return m_loc[0]->Tell(m_loc);
    }

    auto Read(unsigned int *frames, void *buff, int *eof) -> LxResult
    {
        return m_loc[0]->Read(m_loc, frames, buff, eof);
    }

    auto Metrics(LXtAudioMetrics *metrics) -> void
    {
        m_loc[0]->Metrics(m_loc, metrics);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxImpl_AudioWrite
{
public:
    virtual ~CLxImpl_AudioWrite() = default;

    virtual auto audiow_WriteBegin([[maybe_unused]] LXtAudioMetrics *metrics, [[maybe_unused]] unsigned int *frameRange) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto audiow_Write([[maybe_unused]] unsigned int *frames, [[maybe_unused]] const void *data) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto audiow_WriteEnd([[maybe_unused]] void) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto audiow_SetSample([[maybe_unused]] double time, [[maybe_unused]] unsigned int type, [[maybe_unused]] const void *value) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto audiow_SetStart([[maybe_unused]] double start) -> LxResult
    {
        return LXe_NOTIMPL;
    }

    virtual auto audiow_SetDuration([[maybe_unused]] double duration) -> LxResult
    {
        return LXe_NOTIMPL;
    }
};

#define LXxD_AudioWrite_WriteBegin LxResult audiow_WriteBegin([[maybe_unused]] LXtAudioMetrics *metrics, [[maybe_unused]] unsigned int *frameRange) override
#define LXxO_AudioWrite_WriteBegin LXxD_AudioWrite_WriteBegin
#define LXxC_AudioWrite_WriteBegin(c) LxResult c::audiow_WriteBegin([[maybe_unused]] LXtAudioMetrics *metrics, [[maybe_unused]] unsigned int *frameRange)
#define LXxD_AudioWrite_Write LxResult audiow_Write([[maybe_unused]] unsigned int *frames, [[maybe_unused]] const void *data) override
#define LXxO_AudioWrite_Write LXxD_AudioWrite_Write
#define LXxC_AudioWrite_Write(c) LxResult c::audiow_Write([[maybe_unused]] unsigned int *frames, [[maybe_unused]] const void *data)
#define LXxD_AudioWrite_WriteEnd LxResult audiow_WriteEnd() override
#define LXxO_AudioWrite_WriteEnd LXxD_AudioWrite_WriteEnd
#define LXxC_AudioWrite_WriteEnd(c) LxResult c::audiow_WriteEnd()
#define LXxD_AudioWrite_SetSample LxResult audiow_SetSample([[maybe_unused]] double time, [[maybe_unused]] unsigned int type, [[maybe_unused]] const void *value) override
#define LXxO_AudioWrite_SetSample LXxD_AudioWrite_SetSample
#define LXxC_AudioWrite_SetSample(c) LxResult c::audiow_SetSample([[maybe_unused]] double time, [[maybe_unused]] unsigned int type, [[maybe_unused]] const void *value)
#define LXxD_AudioWrite_SetStart LxResult audiow_SetStart([[maybe_unused]] double start) override
#define LXxO_AudioWrite_SetStart LXxD_AudioWrite_SetStart
#define LXxC_AudioWrite_SetStart(c) LxResult c::audiow_SetStart([[maybe_unused]] double start)
#define LXxD_AudioWrite_SetDuration LxResult audiow_SetDuration([[maybe_unused]] double duration) override
#define LXxO_AudioWrite_SetDuration LXxD_AudioWrite_SetDuration
#define LXxC_AudioWrite_SetDuration(c) LxResult c::audiow_SetDuration([[maybe_unused]] double duration)

template <class T>
class CLxIfc_AudioWrite: public CLxInterface
{
public:
    CLxIfc_AudioWrite()
    {
        vt.WriteBegin = WriteBegin;
        vt.Write = Write;
        vt.WriteEnd = WriteEnd;
        vt.SetSample = SetSample;
        vt.SetStart = SetStart;
        vt.SetDuration = SetDuration;
        vTable = &vt.iunk;
        iid = &lx::guid_AudioWrite;
    }

    static auto WriteBegin(LXtObjectID wcom,LXtAudioMetrics *metrics,unsigned int *frameRange) -> LxResult
    {
        LXCWxINST (CLxImpl_AudioWrite, loc);
        try
        {
           return loc->audiow_WriteBegin( metrics, frameRange);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto Write(LXtObjectID wcom,unsigned int *frames,const void *data) -> LxResult
    {
        LXCWxINST (CLxImpl_AudioWrite, loc);
        try
        {
           return loc->audiow_Write( frames, data);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto WriteEnd(LXtObjectID wcom) -> LxResult
    {
        LXCWxINST (CLxImpl_AudioWrite, loc);
        try
        {
           return loc->audiow_WriteEnd();
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SetSample(LXtObjectID wcom,double time,unsigned int type,const void *value) -> LxResult
    {
        LXCWxINST (CLxImpl_AudioWrite, loc);
        try
        {
           return loc->audiow_SetSample( time, type, value);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SetStart(LXtObjectID wcom,double start) -> LxResult
    {
        LXCWxINST (CLxImpl_AudioWrite, loc);
        try
        {
           return loc->audiow_SetStart( start);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

    static auto SetDuration(LXtObjectID wcom,double duration) -> LxResult
    {
        LXCWxINST (CLxImpl_AudioWrite, loc);
        try
        {
           return loc->audiow_SetDuration( duration);
        }
        catch (LxResult rc)
        {
            return rc;
        }
    }

private:
    ILxAudioWrite vt;
};

class CLxLoc_AudioWrite : public CLxLocalize<ILxAudioWriteID>
{
public:
    CLxLoc_AudioWrite()
    {
        _init();
    }

    CLxLoc_AudioWrite(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_AudioWrite(CLxLoc_AudioWrite const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_AudioWrite;
    }

    auto WriteBegin(LXtAudioMetrics *metrics, unsigned int *frameRange) -> LxResult
    {
        return m_loc[0]->WriteBegin(m_loc, metrics, frameRange);
    }

    auto Write(unsigned int *frames, const void *data) -> LxResult
    {
        return m_loc[0]->Write(m_loc, frames, data);
    }

    auto WriteEnd(void) -> LxResult
    {
        return m_loc[0]->WriteEnd(m_loc);
    }

    auto SetSample(double time, unsigned int type, const void *value) -> LxResult
    {
        return m_loc[0]->SetSample(m_loc, time, type, value);
    }

    auto SetStart(double start) -> LxResult
    {
        return m_loc[0]->SetStart(m_loc, start);
    }

    auto SetDuration(double duration) -> LxResult
    {
        return m_loc[0]->SetDuration(m_loc, duration);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_AudioDevice : public CLxLocalize<ILxAudioDeviceID>
{
public:
    CLxLoc_AudioDevice()
    {
        _init();
    }

    CLxLoc_AudioDevice(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_AudioDevice(CLxLoc_AudioDevice const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_AudioDevice;
    }

    auto Handle(ILxUnknownID audio, void **ppvObj) -> LxResult
    {
        return m_loc[0]->Handle(m_loc,(ILxUnknownID) audio, ppvObj);
    }

    auto Handle(ILxUnknownID audio, CLxLocalizedObject &o_dest) -> CLxResult
    {
        LXtObjectID o_obj;
        LxResult r_c = m_loc[0]->Handle(m_loc,(ILxUnknownID) audio, &o_obj);
        return lx::TakeResult(o_dest, r_c, o_obj);
    }

    auto StopAll(void) -> LxResult
    {
        return m_loc[0]->StopAll(m_loc);
    }

    auto PlayFile(const char *filePath) -> LxResult
    {
        return m_loc[0]->PlayFile(m_loc, filePath);
    }

    auto Playing(void) -> int
    {
        return m_loc[0]->Playing(m_loc);
    }

    auto PlayRange(ILxUnknownID audio, double start, double end, double volume, double pitch) -> LxResult
    {
        return m_loc[0]->PlayRange(m_loc,(ILxUnknownID) audio, start, end, volume, pitch);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
class CLxLoc_AudioHandle : public CLxLocalize<ILxAudioHandleID>
{
public:
    CLxLoc_AudioHandle()
    {
        _init();
    }

    CLxLoc_AudioHandle(ILxUnknownID obj)
    {
        _init();
        set(obj);
    }

    CLxLoc_AudioHandle(CLxLoc_AudioHandle const& other)
    {
        _init();
        set(other.m_loc);
    }

    auto guid() const -> LXtGUID const* override
    {
        return &lx::guid_AudioHandle;
    }

    auto Audio(void) -> ILxUnknownID
    {
        return (ILxUnknownID)m_loc[0]->Audio(m_loc);
    }

    auto Offset(void) -> double
    {
        return m_loc[0]->Offset(m_loc);
    }

    auto SetOffset(double offset) -> LxResult
    {
        return m_loc[0]->SetOffset(m_loc, offset);
    }

    auto Pitch(void) -> double
    {
        return m_loc[0]->Pitch(m_loc);
    }

    auto SetPitch(double pitch) -> LxResult
    {
        return m_loc[0]->SetPitch(m_loc, pitch);
    }

    auto Volume(void) -> double
    {
        return m_loc[0]->Volume(m_loc);
    }

    auto SetVolume(double volume) -> LxResult
    {
        return m_loc[0]->SetVolume(m_loc, volume);
    }

    auto Loop(void) -> LxResult
    {
        return m_loc[0]->Loop(m_loc);
    }

    auto SetLoop(unsigned int loop) -> LxResult
    {
        return m_loc[0]->SetLoop(m_loc, loop);
    }

    auto Play(int forward) -> LxResult
    {
        return m_loc[0]->Play(m_loc, forward);
    }

    auto Stop(void) -> LxResult
    {
        return m_loc[0]->Stop(m_loc);
    }

    auto Pause(void) -> LxResult
    {
        return m_loc[0]->Pause(m_loc);
    }

    auto Resume(void) -> LxResult
    {
        return m_loc[0]->Resume(m_loc);
    }

    auto State(LXtAudioState *state) -> LxResult
    {
        return m_loc[0]->State(m_loc, state);
    }

protected:
    void _init()
    {
        m_loc = nullptr;
    }
};
