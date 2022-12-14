#include "GameManager.h"

namespace SDLFramework {

	GameManager* GameManager::sInstance = nullptr;

	GameManager* GameManager::Instance()
	{
		if (sInstance == nullptr) {
			sInstance = new GameManager();
		}
		return sInstance;
	}

	void GameManager::Release() {
		delete sInstance;
		sInstance = nullptr;
	}

	void GameManager::Run() {
		while (!mQuit) {
			m_pTimer->Update();

			while (SDL_PollEvent(&mEvent)) {
				switch (mEvent.type) {
				case SDL_QUIT:
					mQuit = true;
					break;
				}
			}

			if (m_pTimer->DeltaTime() >= 1.0f / FRAME_RATE) {
				Update();
				LateUpdate();
				Render();
				m_pTimer->Reset();
			}
		}
	}

	void GameManager::Update() {
		m_pInputManager->Update();
		m_pScreenManager->Update();
	}

	void GameManager::LateUpdate() {
		m_pInputManager->UpdatePrevInput();
		m_pPhysicsManager->Update();
	}

	void GameManager::Render() {
		m_pGraphics->ClearBackBuffer();
		m_pScreenManager->Render();
		m_pGraphics->Render();
	}

	GameManager::GameManager() : mQuit(false) {
		m_pGraphics = Graphics::Instance();

		if (!Graphics::Initialized()) {
			mQuit = true;
		}

		m_pAssetManager = AssetManager::Instance();
		m_pInputManager = InputManager::Instance();
		m_pAudioManager = AudioManager::Instance();

		m_pPhysicsManager = PhysicsManager::Instance();
		m_pPhysicsManager->SetLayerCollisionMask(PhysicsManager::CollisionLayers::Friendly, PhysicsManager::CollisionFlags::Hostile | PhysicsManager::CollisionFlags::HostileProjectiles);
		m_pPhysicsManager->SetLayerCollisionMask(PhysicsManager::CollisionLayers::FriendlyProjectiles, PhysicsManager::CollisionFlags::Hostile);
		m_pPhysicsManager->SetLayerCollisionMask(PhysicsManager::CollisionLayers::Hostile, PhysicsManager::CollisionFlags::Friendly | PhysicsManager::CollisionFlags::FriendlyProjectiles);
		m_pPhysicsManager->SetLayerCollisionMask(PhysicsManager::CollisionLayers::HostileProjectiles, PhysicsManager::CollisionFlags::Friendly);

		m_pTimer = Timer::Instance();

		m_pScreenManager = ScreenManager::Instance();
	}

	GameManager::~GameManager() {
		ScreenManager::Release();
		m_pScreenManager = nullptr;

		Timer::Release();
		m_pTimer = nullptr;

		AudioManager::Release();
		m_pAudioManager = nullptr;

		InputManager::Release();
		m_pInputManager = nullptr;

		AssetManager::Release();
		m_pAssetManager = nullptr;

		PhysicsManager::Release();
		m_pPhysicsManager = nullptr;

		Graphics::Release();
		m_pGraphics = nullptr;

		// Quit SDL subsystems
		SDL_Quit();
	}
}