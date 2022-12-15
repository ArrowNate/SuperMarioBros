#include "AssetManager.h"

#include <iostream>
#include <sstream>
#include <fstream>

namespace SDLFramework {

	AssetManager * AssetManager::sInstance = nullptr;
	std::map<std::string, ShaderUtil> AssetManager::Shaders;

	AssetManager * AssetManager::Instance() {
		if (sInstance == nullptr) {
			sInstance = new AssetManager();
		}

		return sInstance;
	}

	void AssetManager::Release() {
		delete sInstance;
		sInstance = nullptr;
	}

	AssetManager::AssetManager() {
	}

	AssetManager::~AssetManager() {
		for (auto tex : mTextures) {
			if (tex.second != nullptr) {
				SDL_DestroyTexture(tex.second);
			}
		}
		mTextures.clear();

		for (auto surf : mSurfaceText) {
			if (surf.second != nullptr) {
				SDL_FreeSurface(surf.second);
			}
		}
		mSurfaceText.clear();

		for (auto surf : mSurfaceTextures) {
			if (surf.second != nullptr) {
				SDL_FreeSurface(surf.second);
			}
		}
		mSurfaceTextures.clear();

		for (auto text : mText) {
			if (text.second != nullptr) {
				SDL_DestroyTexture(text.second);
			}
		}
		mText.clear();

		for (auto font : mFonts) {
			if (font.second != nullptr) {
				TTF_CloseFont(font.second);
			}
		}
		mFonts.clear();
	}

	SDL_Texture * AssetManager::GetTexture(std::string filename, bool managed) {
		std::string fullPath = SDL_GetBasePath();
		fullPath.append("Assets/" + filename);

		if (mTextures[fullPath] == nullptr) {
			mTextures[fullPath] = Graphics::Instance()->LoadTexture(fullPath);
		}

		if (mTextures[fullPath] != nullptr && managed) {
			mTextureRefCount[mTextures[fullPath]] += 1;
		}

		return mTextures[fullPath];
	}


	SDL_Surface* AssetManager::GetSurfaceTexture(std::string filename, bool managed /*= false*/)
	{
		std::string fullPath = SDL_GetBasePath();
		fullPath.append("Assets/" + filename);

		if (mSurfaceTextures[fullPath] == nullptr) {
			mSurfaceTextures[fullPath] = Graphics::Instance()->GetSurfaceTexture(fullPath);
		}

		if (mSurfaceTextures[fullPath] != nullptr && managed) {
			mSurfaceRefCount[mSurfaceTextures[fullPath]] += 1;
		}

		return mSurfaceTextures[fullPath];
	}


	SDL_Surface* AssetManager::GetSurfaceText(std::string text, std::string filename, int size, SDL_Color color, bool managed /*= false*/)
	{
		std::stringstream ss;
		ss << size << (int)color.r << (int)color.g << (int)color.b;
		std::string key = text + filename + ss.str();

		if (mSurfaceText[key] == nullptr) {
			TTF_Font* font = GetFont(filename, size);
			mSurfaceText[key] = Graphics::Instance()->GetSurfaceText(font, text, color);
		}

		if (mSurfaceText[key] != nullptr && managed) {
			mSurfaceRefCount[mSurfaceText[key]] += 1;
		}

		return mSurfaceText[key];
	}

	TTF_Font* AssetManager::GetFont(std::string filename, int size) {
		std::string fullPath = SDL_GetBasePath();
		fullPath.append("Assets/" + filename);

		std::stringstream ss;
		ss << size;
		std::string key = fullPath + ss.str();

		if (mFonts[key] == nullptr) {
			mFonts[key] = TTF_OpenFont(fullPath.c_str(), size);
			if (mFonts[key] == nullptr) {
				std::cerr << "Unable to load font " << filename << "! TTF Error: " << TTF_GetError() << std::endl;
			}
		}

		return mFonts[key];
	}


	ShaderUtil AssetManager::loadShaderFromFile(const GLchar* vShaderFile, const GLchar* fShaderFile, const GLchar* gShaderFile /*= nullptr*/)
	{
		// 1. Retrieve the vertex/fragment source code from filePath
		std::string vertexCode;
		std::string fragmentCode;
		std::string geometryCode;
		try
		{
			// Open files
			std::ifstream vertexShaderFile(vShaderFile);
			std::ifstream fragmentShaderFile(fShaderFile);
			std::stringstream vShaderStream, fShaderStream;
			// Read file's buffer contents into streams
			vShaderStream << vertexShaderFile.rdbuf();
			fShaderStream << fragmentShaderFile.rdbuf();
			// close file handlers
			vertexShaderFile.close();
			fragmentShaderFile.close();
			// Convert stream into string
			vertexCode = vShaderStream.str();
			fragmentCode = fShaderStream.str();
			// If geometry shader path is present, also load a geometry shader
			if (gShaderFile != nullptr)
			{
				std::ifstream geometryShaderFile(gShaderFile);
				std::stringstream gShaderStream;
				gShaderStream << geometryShaderFile.rdbuf();
				geometryShaderFile.close();
				geometryCode = gShaderStream.str();
			}
		}
		catch (std::exception e)
		{
			std::cout << "ERROR::SHADER: Failed to read shader files" << std::endl;
		}
		const GLchar* vShaderCode = vertexCode.c_str();
		const GLchar* fShaderCode = fragmentCode.c_str();
		const GLchar* gShaderCode = geometryCode.c_str();
		// 2. Now create shader object from source code
		ShaderUtil shader;
		shader.Compile(vShaderCode, fShaderCode, gShaderFile != nullptr ? gShaderCode : nullptr);
		return shader;
	}

	SDL_Texture* AssetManager::GetText(std::string text, std::string filename, int size, SDL_Color color, bool managed) {
		std::stringstream ss;
		ss << size << (int)color.r << (int)color.g << (int)color.b;
		std::string key = text + filename + ss.str();

		if (mText[key] == nullptr) {
			TTF_Font * font = GetFont(filename, size);
			mText[key] = Graphics::Instance()->CreateTextTexture(font, text, color);
		}

		if (mText[key] != nullptr && managed) {
			mTextureRefCount[mText[key]] += 1;
		}

		return mText[key];
	}

	ShaderUtil AssetManager::GetShader(std::string name)
	{
		return Shaders[name];

	}


	ShaderUtil AssetManager::LoadShader(const GLchar* vShaderFile, const GLchar* fShaderFile, const GLchar* gShaderFile, std::string name)
	{
		Shaders[name] = loadShaderFromFile(vShaderFile, fShaderFile, gShaderFile);
		return Shaders[name];
	}

	void AssetManager::DestroyTexture(SDL_Texture* texture) {

		if (mTextureRefCount.find(texture) != mTextureRefCount.end())
		{
			mTextureRefCount[texture] -= 1;
			if (mTextureRefCount[texture] == 0) {
				for (auto elem : mTextures) {
					if (elem.second == texture) {
						SDL_DestroyTexture(elem.second);
						mTextures.erase(elem.first);
						return; // work finished, leave function
					}
				}

				for (auto elem : mText) {
					if (elem.second == texture) {
						SDL_DestroyTexture(elem.second);
						mText.erase(elem.first);
						return; // work finished, leave function
					}
				}
			}
		}
	}


	void AssetManager::DestroySurface(SDL_Surface* surface)
	{
		if (mSurfaceRefCount.find(surface) != mSurfaceRefCount.end())
		{
			mSurfaceRefCount[surface] -= 1;
			if (mSurfaceRefCount[surface] == 0) {
				for (auto elem : mSurfaceTextures) {
					if (elem.second == surface) {
						SDL_FreeSurface(elem.second);
						mSurfaceTextures.erase(elem.first);
						return; // work finished, leave function
					}
				}
				for (auto elem : mSurfaceText) {
					if (elem.second == surface) {
						SDL_FreeSurface(elem.second);
						mSurfaceText.erase(elem.first);
						return; // work finished, leave function
					}
				}
			}

		}
	}
}