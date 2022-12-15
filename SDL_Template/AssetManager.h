#ifndef __ASSETMANAGER_H
#define __ASSETMANAGER_H
#include "Graphics.h"

#include <map>
#include <sstream>
#include "ShaderUtil.h"

namespace SDLFramework {

	class AssetManager
	{
	private:
		static AssetManager * sInstance;

		std::map<std::string, SDL_Texture*> mTextures;
		std::map<std::string, TTF_Font*> mFonts;
		std::map<std::string, SDL_Texture*> mText;
		std::map<std::string, SDL_Surface*> mSurfaceTextures;
		std::map<std::string, SDL_Surface*> mSurfaceText;
		static std::map<std::string, ShaderUtil> Shaders;


		std::map<SDL_Surface*, unsigned> mSurfaceRefCount;
		std::map<SDL_Texture*, unsigned> mTextureRefCount;

		TTF_Font * GetFont(std::string filename, int size);

		static ShaderUtil loadShaderFromFile(const GLchar* vShaderFile, const GLchar* fShaderFile, const GLchar* gShaderFile = nullptr);

		AssetManager();
		~AssetManager();

	public:
		static AssetManager * Instance();
		static void Release();

		SDL_Texture * GetTexture(std::string filename, bool managed = false);
		SDL_Surface* GetSurfaceTexture(std::string filename, bool managed = false);
		SDL_Surface* GetSurfaceText(std::string text, std::string filename, int size, SDL_Color color, bool managed = false);
		SDL_Texture * GetText(std::string text, std::string filename, int size, SDL_Color color, bool managed = false);

		static ShaderUtil GetShader(std::string name);

		static ShaderUtil LoadShader(const GLchar* vShaderFile, const GLchar* fShaderFile, const GLchar* gShaderFile, std::string name);

		void DestroyTexture(SDL_Texture* texture);
		void DestroySurface(SDL_Surface* surface);
	};
}
#endif