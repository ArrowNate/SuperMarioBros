#ifndef _PLAYER_H
#define _PLAYER_H
#include "AnimatedTexture.h"
#include "InputManager.h"
#include "AudioManager.h"
//#include "Bullet.h"
#include "Timer.h"

using namespace SDLFramework;

class Player : public GameEntity
{
private:
	Timer* m_pTimer;
	InputManager* m_pInput;
	AudioManager* m_pAudio;

	bool mVisible;
	bool mAnimating;
	bool misMovingRight;
	//bool misMovingLeft;
	bool mWasHit;

	int mScore;
	int mLives;

	TextureGL* m_pMario;
	AnimatedTexture* m_pMarioMoving;
	AnimatedTexture* m_pDeathAnimation;

	float mCurrentSpeed;
	float mMoveSpeed;
	float mMaxSpeed;

public:
	Player();
	~Player();

	void Visible(bool visible);
	bool IsAnimating();

	int Score();
	int Lives();

	void AddScore(int change);

	bool WasHit();
	void WasHit(bool hit);

	void Update() override;
	void Render() override;

private:
	void HandleMovementRight();
	//void HandleMovementLeft();
	void HandleFire();
	void MarioPhysicsRight();
	//void MarioPhysicsLeft();
};

#endif // !_PLAYER_H