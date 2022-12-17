#include "GraphicsSDL.h"

namespace SDLFramework {

	GraphicsSDL* GraphicsSDL::Instance()
	{
		if (sInstance == nullptr) {
			Graphics::Instance();
		}

		return (GraphicsSDL*)sInstance;
	}

	GraphicsSDL::GraphicsSDL() : Graphics()
	{
		sInitialized = Init();
	}

	GraphicsSDL::~GraphicsSDL()
	{
		SDL_DestroyRenderer(m_pRenderer);

		m_pRenderer = nullptr;
	}

	void GraphicsSDL::DrawTexture(SDL_Texture* tex, SDL_Rect* srcRect /*= nullptr*/, SDL_Rect* dstRect /*= nullptr*/, float angle /*= 0.0f*/, SDL_RendererFlip flip /*= SDL_FLIP_NONE*/)
	{
		SDL_RenderCopyEx(m_pRenderer, tex, srcRect, dstRect, angle, nullptr, flip);
	}

	void GraphicsSDL::Render()
	{
		SDL_RenderPresent(m_pRenderer);
	}

	void GraphicsSDL::ClearBackBuffer()
	{
		SDL_RenderClear(m_pRenderer);
	}

	bool GraphicsSDL::Init()
	{
		if (!Graphics::Init())
			return false;



		return true;
	}
}