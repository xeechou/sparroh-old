#pragma once

// diligient application, the samples is built upon the SampleBase, on the
// other hand, we are building an engine using SDL for handling WSI, we can
// extend this for sparroh

#include <SDL2/SDL_video.h>

#include "Common/interface/RefCntAutoPtr.hpp"
#include "Graphics/GraphicsEngine/interface/DeviceContext.h"
#include "Graphics/GraphicsEngine/interface/RenderDevice.h"
#include "Graphics/GraphicsEngine/interface/SwapChain.h"

#include <SDL2/SDL.h>

namespace dg = Diligent;

namespace sparroh
{

class Application
{
    //extend this into engine?


public:
    Application();
    virtual ~Application();

    virtual bool Initialize();
	//public APIS
    // IEngineFactory* GetEngineFactory() { return m_pDevice->GetEngineFactory(); }
    // IRenderDevice*  GetDevice() { return m_pDevice; }
    // IDeviceContext* GetContext() { return m_pImmediateContext; }
    // ISwapChain*     GetSwapChain() { return m_pSwapChain; }

protected:

    // diligent structure, for render structure
    dg::RefCntAutoPtr<dg::IRenderDevice> m_pDevice;
    dg::RefCntAutoPtr<dg::IDeviceContext> m_pImmediateContext;
    dg::RefCntAutoPtr<dg::ISwapChain> m_pSwapChain;
    SDL_Window *m_pWindow = nullptr;

    //used in initialize
    bool CreateWindow(const char *title, int w, int h);
    bool InitEngine();
};

}
