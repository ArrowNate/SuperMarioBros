#ifndef __GAMEMANAGER_H
#define __GAMEMANAGER_H
#include <SDL.h>
#include "Timer.h"
#include "AudioManager.h"
#include "ScreenManager.h"
#include "PhysicsManager.h"

namespace SDLFramework {

	class GameManager
	{
	private:
		static GameManager * sInstance;
		const int FRAME_RATE = 60;

		bool mQuit;
		Graphics* m_pGraphics;
		AssetManager* m_pAssetManager;
		InputManager* m_pInputManager;
		AudioManager* m_pAudioManager;
		PhysicsManager* m_pPhysicsManager;

		Timer* m_pTimer;

		SDL_Event mEvent;

		ScreenManager* m_pScreenManager;

	public:
		static GameManager* Instance();
		static void Release();

		void Run();

		void Update();
		void LateUpdate();

		void Render();

		GameManager();
		~GameManager();
	};
}
#endif