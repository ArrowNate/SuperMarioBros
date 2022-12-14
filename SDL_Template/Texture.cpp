#include "Texture.h"
#include "GraphicsGL.h"
namespace SDLFramework {

	Texture::Texture(std::string filename, bool managed) {
		m_pGraphics = Graphics::Instance();
		m_pTex = AssetManager::Instance()->GetTexture(filename, managed);
		//mSurf = AssetManager::Instance()->GetSurfaceTexture(filename, managed);

		SDL_QueryTexture(m_pTex, nullptr, nullptr, &mWidth, &mHeight);

		mClipped = false;
		mDestinationRect.w = mWidth;
		mDestinationRect.h = mHeight;
	}

	Texture::Texture(std::string filename, int x, int y, int w, int h, bool managed) {
		m_pGraphics = Graphics::Instance();
		m_pTex = AssetManager::Instance()->GetTexture(filename, managed);
		//mSurf = AssetManager::Instance()->GetSurfaceTexture(filename, managed);

		mWidth = w;
		mHeight = h;

		mClipped = true;
		mDestinationRect.w = mWidth;
		mDestinationRect.h = mHeight;

		mSourceRect.x = x;
		mSourceRect.y = y;
		mSourceRect.w = mWidth;
		mSourceRect.h = mHeight;
	}

	Texture::Texture(std::string text, std::string fontPath, int size, SDL_Color color, bool managed) {
		m_pGraphics = Graphics::Instance();
		m_pTex = AssetManager::Instance()->GetText(text, fontPath, size, color, managed);
		//mSurf = AssetManager::Instance()->GetSurfaceText(text, fontPath, size, color, managed);


		mClipped = false;

		SDL_QueryTexture(m_pTex, nullptr, nullptr, &mWidth, &mHeight);

		mDestinationRect.w = mWidth;
		mDestinationRect.h = mHeight;
	}
	Texture::~Texture() {
		AssetManager::Instance()->DestroyTexture(m_pTex);
		m_pTex = nullptr;
		m_pGraphics = nullptr;
	}

	Vector2 Texture::ScaledDimensions() {
		Vector2 scaledDimensions = Scale();
		scaledDimensions.x *= mWidth;
		scaledDimensions.y *= mHeight;

		return scaledDimensions;
	}

	int Texture::GetWidth()
	{
		return mWidth;
	}

	int Texture::GetHeight()
	{
		return mHeight;
	}

	void Texture::SetSourceRect(SDL_Rect * sourceRect) {
		mSourceRect = *sourceRect;
	}

	void Texture::Render() {
		Vector2 pos = Position(World);
		Vector2 scale = Scale(World);
		mDestinationRect.x = (int)(pos.x - mWidth * scale.x * 0.5f);
		mDestinationRect.y = (int)(pos.y - mHeight * scale.y * 0.5f);
		mDestinationRect.w = (int)(mWidth * scale.x);
		mDestinationRect.h = (int)(mHeight * scale.y);

		if (GraphicsGL::Instance() == nullptr)
		{
			m_pGraphics->DrawTexture(m_pTex, mClipped ? &mSourceRect : nullptr, &mDestinationRect, Rotation(World));
		}
	}
}