#include "AssetManager.h"

#include <iostream>
#include <sstream>
#include <fstream>

namespace SDLFramework {

	AssetManager* AssetManager::sInstance = nullptr;
	std::map<std::string, ShaderUtil> AssetManager::mShaders;

	AssetManager* AssetManager::Instance() {
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
		for (auto tex : m_pTextures) {
			if (tex.second != nullptr) {
				SDL_DestroyTexture(tex.second);
			}
		}
		m_pTextures.clear();

		for (auto surf : m_pSurfaceText) {
			if (surf.second != nullptr) {
				SDL_FreeSurface(surf.second);
			}
		}
		m_pSurfaceText.clear();

		for (auto surf : m_pSurfaceTextures) {
			if (surf.second != nullptr) {
				SDL_FreeSurface(surf.second);
			}
		}
		m_pSurfaceTextures.clear();

		for (auto text : m_pText) {
			if (text.second != nullptr) {
				SDL_DestroyTexture(text.second);
			}
		}
		m_pText.clear();

		for (auto font : m_pFonts) {
			if (font.second != nullptr) {
				TTF_CloseFont(font.second);
			}
		}
		m_pFonts.clear();

		for (auto mus : m_pMusic) {
			if (mus.second != nullptr) {
				Mix_FreeMusic(mus.second);
			}
		}
		m_pMusic.clear();

		for (auto sfx : m_pSFX) {
			if (sfx.second != nullptr) {
				Mix_FreeChunk(sfx.second);
			}
		}
		m_pSFX.clear();
	}

	SDL_Texture * AssetManager::GetTexture(std::string filename, bool managed) {
		std::string fullPath = SDL_GetBasePath();
		fullPath.append("Assets/" + filename);

		if (m_pTextures[fullPath] == nullptr) {
			m_pTextures[fullPath] = Graphics::Instance()->LoadTexture(fullPath);
		}

		if (m_pTextures[fullPath] != nullptr && managed) {
			m_pTextureRefCount[m_pTextures[fullPath]] += 1;
		}

		return m_pTextures[fullPath];
	}


	SDL_Surface* AssetManager::GetSurfaceTexture(std::string filename, bool managed /*= false*/)
	{
		std::string fullPath = SDL_GetBasePath();
		fullPath.append("Assets/" + filename);

		if (m_pSurfaceTextures[fullPath] == nullptr) {
			m_pSurfaceTextures[fullPath] = Graphics::Instance()->GetSurfaceTexture(fullPath);
		}

		if (m_pSurfaceTextures[fullPath] != nullptr && managed) {
			m_pSurfaceRefCount[m_pSurfaceTextures[fullPath]] += 1;
		}

		return m_pSurfaceTextures[fullPath];
	}


	SDL_Surface* AssetManager::GetSurfaceText(std::string text, std::string filename, int size, SDL_Color color, bool managed /*= false*/)
	{
		std::stringstream ss;
		ss << size << (int)color.r << (int)color.g << (int)color.b;
		std::string key = text + filename + ss.str();

		if (m_pSurfaceText[key] == nullptr) {
			TTF_Font* font = GetFont(filename, size);
			m_pSurfaceText[key] = Graphics::Instance()->GetSurfaceText(font, text, color);
		}

		if (m_pSurfaceText[key] != nullptr && managed) {
			m_pSurfaceRefCount[m_pSurfaceText[key]] += 1;
		}

		return m_pSurfaceText[key];
	}

	TTF_Font* AssetManager::GetFont(std::string filename, int size) {
		std::string fullPath = SDL_GetBasePath();
		fullPath.append("Assets/" + filename);

		std::stringstream ss;
		ss << size;
		std::string key = fullPath + ss.str();

		if (m_pFonts[key] == nullptr) {
			m_pFonts[key] = TTF_OpenFont(fullPath.c_str(), size);
			if (m_pFonts[key] == nullptr) {
				std::cerr << "Unable to load font " << filename << "! TTF Error: " << TTF_GetError() << std::endl;
			}
		}

		return m_pFonts[key];
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

		if (m_pText[key] == nullptr) {
			TTF_Font * font = GetFont(filename, size);
			m_pText[key] = Graphics::Instance()->CreateTextTexture(font, text, color);
		}

		if (m_pText[key] != nullptr && managed) {
			m_pTextureRefCount[m_pText[key]] += 1;
		}

		return m_pText[key];
	}

	Mix_Music * AssetManager::GetMusic(std::string filename, bool managed) {
		std::string fullPath = SDL_GetBasePath();
		fullPath.append("Assets/" + filename);

		if (m_pMusic[fullPath] == nullptr) {
			m_pMusic[fullPath] = Mix_LoadMUS(fullPath.c_str());
		}

		if (m_pMusic[fullPath] == nullptr) {
			std::cerr << "Unable to load music " << filename << "! Mix error: " << Mix_GetError() << std::endl;
		}
		else if (managed) {
			m_pMusicRefCount[m_pMusic[fullPath]] += 1;
		}

		return m_pMusic[fullPath];
	}

	Mix_Chunk * AssetManager::GetSFX(std::string filename, bool managed) {
		std::string fullPath = SDL_GetBasePath();
		fullPath.append("Assets/" + filename);

		/*if (mSFX[fullPath] == nullptr) {
			mSFX[fullPath] = Mix_LoadWAV(fullPath.c_str());
		}

		if (mSFX[fullPath] == nullptr) {
			std::cerr << "Unable to load SFX " << filename << "! Mix error: " << Mix_GetError() << std::endl;
		}
		else if (managed) {
			mSFXRefCount[mSFX[fullPath]] += 1;
		}*/

		return m_pSFX[fullPath];
	}


	ShaderUtil AssetManager::GetShader(std::string name)
	{
		return mShaders[name];

	}


	ShaderUtil AssetManager::LoadShader(const GLchar* vShaderFile, const GLchar* fShaderFile, const GLchar* gShaderFile, std::string name)
	{
		mShaders[name] = loadShaderFromFile(vShaderFile, fShaderFile, gShaderFile);
		return mShaders[name];
	}

	void AssetManager::DestroyTexture(SDL_Texture* texture) {

		if (m_pTextureRefCount.find(texture) != m_pTextureRefCount.end())
		{
			m_pTextureRefCount[texture] -= 1;
			if (m_pTextureRefCount[texture] == 0) {
				for (auto elem : m_pTextures) {
					if (elem.second == texture) {
						SDL_DestroyTexture(elem.second);
						m_pTextures.erase(elem.first);
						return; // work finished, leave function
					}
				}

				for (auto elem : m_pText) {
					if (elem.second == texture) {
						SDL_DestroyTexture(elem.second);
						m_pText.erase(elem.first);
						return; // work finished, leave function
					}
				}
			}
		}
	}


	void AssetManager::DestroySurface(SDL_Surface* surface)
	{
		if (m_pSurfaceRefCount.find(surface) != m_pSurfaceRefCount.end())
		{
			m_pSurfaceRefCount[surface] -= 1;
			if (m_pSurfaceRefCount[surface] == 0) {
				for (auto elem : m_pSurfaceTextures) {
					if (elem.second == surface) {
						SDL_FreeSurface(elem.second);
						m_pSurfaceTextures.erase(elem.first);
						return; // work finished, leave function
					}
				}
				for (auto elem : m_pSurfaceText) {
					if (elem.second == surface) {
						SDL_FreeSurface(elem.second);
						m_pSurfaceText.erase(elem.first);
						return; // work finished, leave function
					}
				}
			}

		}
	}

	void AssetManager::DestroyMusic(Mix_Music* music) {
		for (auto elem : m_pMusic) {
			if (elem.second == music) {
				m_pMusicRefCount[elem.second] -= 1;

				if (m_pMusicRefCount[elem.second] == 0) {
					Mix_FreeMusic(elem.second);
					m_pMusic.erase(elem.first);
				}
				return; // work finished, leave function
			}
		}
	}

	void AssetManager::DestroySFX(Mix_Chunk * sfx) {
		for (auto elem : m_pSFX) {
			if (elem.second == sfx) {
				m_pSFXRefCount[elem.second] -= 1;

				if (m_pSFXRefCount[elem.second] == 0) {
					Mix_FreeChunk(elem.second);
					m_pSFX.erase(elem.first);
				}
				return; // work finished, leave function
			}
		}
	}
}