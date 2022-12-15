#include "Graphics.h"
#include "GraphicsSDL.h"
#include "GraphicsGL.h"


namespace SDLFramework {

	Graphics * Graphics::sInstance = nullptr;
	bool Graphics::sInitialized = false;

	// static member functions
	Graphics * Graphics::Instance() {
		if (sInstance == nullptr) {
			sInstance =  new GraphicsGL(); 
		}
		

		return sInstance;
	}

	void Graphics::Release() {
		delete sInstance;
		sInstance = nullptr;
		sInitialized = false;
	}

	bool Graphics::Initialized() {
		return sInitialized;
	}


	SDL_Texture* Graphics::LoadTexture(std::string path)
	{
		SDL_Texture* tex = nullptr;
		SDL_Surface* surface = GetSurfaceTexture(path);
		if (surface == nullptr) {
			return nullptr;
		}

		tex = SDL_CreateTextureFromSurface(mRenderer, surface);
		if (tex == nullptr) {
			std::cerr << "Unable to create texture from surface! IMG Error: " << IMG_GetError() << std::endl;
			return nullptr;
		}

		SDL_FreeSurface(surface);
		return tex;
	}


	SDL_Texture* Graphics::CreateTextTexture(TTF_Font* font, std::string text, SDL_Color color)
	{
		SDL_Surface* surface = GetSurfaceText(font, text, color);
		if (surface == nullptr) {
			return nullptr;
		}

		SDL_Texture* tex = SDL_CreateTextureFromSurface(mRenderer, surface);
		if (tex == nullptr) {
			std::cerr << "CreateTextTexture:: SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
			return nullptr;
		}

		SDL_FreeSurface(surface);
		return tex;
	}

	SDL_Surface* Graphics::GetSurfaceTexture(std::string path)
	{
		SDL_Surface* surface = IMG_Load(path.c_str());

		if (surface == nullptr) {
			std::cerr << "Unable to load " << path << ". Surface Error: " << IMG_GetError() << std::endl;
			return nullptr;
		}

		return surface;
	}

	SDL_Surface* Graphics::GetSurfaceText(TTF_Font* font, std::string text, SDL_Color color)
	{
		SDL_Surface* surface = TTF_RenderText_Blended(font, text.c_str(), color);
		if (surface == nullptr) {
			std::cerr << "CreateTextTexture:: TTF_RenderText_Solid Error: " << TTF_GetError() << std::endl;
			return nullptr;
		}
		return surface;
	}

	//private member functions
	Graphics::Graphics() : mRenderer(nullptr) {
		
	}

	Graphics::~Graphics() {
		SDL_DestroyWindow(mWindow);

		
		mWindow = nullptr;

		TTF_Quit();
		IMG_Quit();
	}

	bool Graphics::Init() {
		if (SDL_InitSubSystem(SDL_INIT_VIDEO) < 0) {
			std::cerr << "Unable to initialize SDL video! SDL Error: " << SDL_GetError() << std::endl;
			return false;
		}
		
		mWindow = SDL_CreateWindow(
			WINDOW_TITLE,				// window title
			SDL_WINDOWPOS_UNDEFINED,	// window xpos
			SDL_WINDOWPOS_UNDEFINED,	// window ypos
			SCREEN_WIDTH,				// window width
			SCREEN_HEIGHT,				// window height
			SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);			// window flags
		if (mWindow == nullptr) {
			std::cerr << "Unable to create Window! SDL Error: " << SDL_GetError() << std::endl;
			return false;
		}

		mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);
		if (mRenderer == nullptr) {
			std::cerr << "Unable to create renderer! SDL Error: " << SDL_GetError() << std::endl;
			return false;
		}

		int flags = IMG_INIT_PNG;
		if (!(IMG_Init(flags) & flags)) {
			std::cerr << "Unable to initialize SDL_image! IMG Error: " << IMG_GetError() << std::endl;
			return false;
		}

		if (TTF_Init() == -1) {
			std::cerr << "Unable to initialized SDL_ttf! TTF Error: " << TTF_GetError() << std::endl;
			return false;
		}
	
		return true;
	}
}