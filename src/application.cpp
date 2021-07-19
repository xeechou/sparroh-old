#include <SDL2/SDL.h>
#include <SDL2/SDL_video.h>
#include <memory>
#include <stdexcept>
#include "macros.h"
#include "application.h"

static int GetWindowFlags()
{
    int flags = SDL_WINDOW_SHOWN | SDL_WINDOW_ALLOW_HIGHDPI;
#if VULKAN_SUPPORTED
    flags |= SDL_WINDOW_VULKAN;
#elif D3D12_SUPPORTED
    type = RENDER_DEVICE_TYPE_D3D12;
#elif D3D11_SUPPORTED
    type = RENDER_DEVICE_TYPE_D3D11;
#elif GL_SUPPORTED
    flags |= SDL_WINDOW_OPENGL;
#endif
    return flags;
}

namespace sparroh
{

bool Application::Initialize()
{
    if (!CreateWindow("Application", 1280, 720))
        return false;
    if (!InitEngine())
        return false;
    return true;
}

Application::Application() :
    m_pDevice(nullptr),
    m_pImmediateContext(nullptr),
    m_pSwapChain(nullptr),
    m_pWindow(nullptr)
{}

Application::~Application()
{
    if (m_pImmediateContext)
        m_pImmediateContext->Flush();

    m_pSwapChain        = nullptr;
    m_pImmediateContext = nullptr;
    m_pDevice           = nullptr;

    if (m_pWindow)
    {
        SDL_DestroyWindow(m_pWindow);
        SDL_Quit();
    }
    //hey, we do not have cursors
    m_pWindow = nullptr;
}

bool Application::CreateWindow(const char *title, int w, int h)
{
    auto flags = ::GetWindowFlags();
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
        return false;
    m_pWindow = SDL_CreateWindow(title,
                                 SDL_WINDOWPOS_CENTERED,
                                 SDL_WINDOWPOS_CENTERED,
                                 w, h, flags);
    if (!m_pWindow)
        return false;
    //for metal, d3d and vulkan, there is no specific
    if (flags & SDL_WINDOW_OPENGL) {
        SDL_GLContext ctx = SDL_GL_CreateContext(m_pWindow);
        SDL_GL_SetSwapInterval(1); //enable vsync
        SDL_GL_MakeCurrent(m_pWindow, ctx);
        //after this we can call SDL_GL_GetCurrentContext
    }
    return true;
}

bool Application::InitEngine()
{
    //This is an ugly part of this API, we
    dg::SwapChainDesc SCDesc;

    if (m_pDevice == nullptr ||
        m_pImmediateContext == nullptr ||
        m_pSwapChain == nullptr)
        return false;
    return true;
}

}
