#ifndef _PLAYER_H
#define _PLAYER_H
#include "AnimatedTexture.h"
#include "InputManager.h"
#include "AudioManager.h"
//#include "Fire.h"
#include "Timer.h"

using namespace SDLFramework;

class Player : public GameEntity
{
private:
	Timer* m_pTimer;
	InputManager* m_pInput;
	AudioManager* m_pAudio;

	bool mVisible;
	bool misNotMoving;
	bool mIdleRight;
	bool mIdleLeft;
	bool mAnimatingRight;
	bool mAnimatingLeft;
	bool misMovingRight;
	bool misMovingLeft;
	bool mWasHit;

	int mScore;
	int mLives;

	TextureGL* m_pMarioRight;
	TextureGL* m_pMarioLeft;
	//TextureGL* m_pMarioMoving;
	AnimatedTexture* m_pMarioMovingRight;
	AnimatedTexture* m_pMarioMovingLeft;
	AnimatedTexture* m_pDeathAnimation;

	float mCurrentSpeed;
	float mCurrentSpeedLeft;
	float mMoveSpeed;
	float mMoveSpeedLeft;
	float mMaxSpeed;
	float mMaxSpeedLeft;

public:
	Player();
	~Player();

	//bool IsMovingRight();
	//bool IsMovingLeft();

	void Visible(bool visible);
	bool IsNotRunning();
	bool IsIdleRight();
	bool IsIdleLeft();
	bool IsAnimatingRight();
	bool IsAnimatingLeft();
	void IdleRight();
	void IdleLeft();
	void RunningRight();
	void RunningLeft();

	int Score();
	int Lives();

	void AddScore(int change);

	bool WasHit();
	void WasHit(bool hit);

	void Update() override;
	void Render() override;

private:
	void HandleMovementRight();
	void HandleMovementLeft();
	void HandleFire();
	void MarioPhysicsRight();
	void MarioPhysicsLeft();
};

#endif // !_PLAYER_H