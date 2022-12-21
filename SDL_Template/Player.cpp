#include "Player.h"

Player::Player()
{
	m_pTimer = Timer::Instance();
	m_pInput = InputManager::Instance();
	m_pAudio = AudioManager::Instance();

	mVisible = false;
	mAnimating = false;
	misMovingRight = false;
	//misMovingLeft = false;
	mWasHit = false;

	mScore = 0;
	mLives = 3;

	m_pMario = new TextureGL("MarioIdle_01.png", 0, 0, 33, 41);
	m_pMario->Parent(this);
	m_pMario->Position(-169.0f, 181.0f);

	mCurrentSpeed = 0.0f;
	mMoveSpeed = 0.0f;
	mMaxSpeed = 100.0f;
}

Player::~Player()
{
	m_pTimer = nullptr;
	m_pInput = nullptr;
	m_pAudio = nullptr;

	delete m_pMario;
	m_pMario = nullptr;
}

void Player::Visible(bool visible)
{
	mVisible = visible;
}

bool Player::IsAnimating()
{
	return mAnimating;
}

int Player::Score()
{
	return mScore;
}

int Player::Lives()
{
	return mLives;
}

void Player::AddScore(int change)
{
	mScore += change;
}

bool Player::WasHit()
{
	return mWasHit;
}

void Player::WasHit(bool hit)
{
	mWasHit = hit;
}

void Player::Update()
{
	m_pMario->Update();
	HandleMovementRight();
	//HandleMovementLeft();
	HandleFire();
	MarioPhysicsRight();
	//MarioPhysicsLeft();
}

void Player::Render()
{
	m_pMario->Render();
}

void Player::HandleMovementRight()
{
	if (m_pInput->KeyDown(SDL_SCANCODE_D)) {
		misMovingRight = true;
	}
	if (m_pInput->KeyReleased(SDL_SCANCODE_D)) {
		misMovingRight = false;
	}
}

//void Player::HandleMovementLeft()
//{
//	if (m_pInput->KeyDown(SDL_SCANCODE_A)) {
//		misMovingLeft = true;
//	}
//	if (m_pInput->KeyReleased(SDL_SCANCODE_A)) {
//		misMovingLeft = false;
//	}
//}

void Player::HandleFire()
{
}

void Player::MarioPhysicsRight()
{
	Translate(Vec2_Right * (mCurrentSpeed + mMoveSpeed) * m_pTimer->DeltaTime() * (std::cos(Rotation()), std::sin(Rotation()), World));
	if (misMovingRight == true) {
		mCurrentSpeed += 50.0f * m_pTimer->DeltaTime();
		if (mCurrentSpeed > mMaxSpeed) {
			mCurrentSpeed = mMaxSpeed;
		}
	}

	if (misMovingRight == false) {
		mCurrentSpeed -= 80.0f * m_pTimer->DeltaTime();
		if (mCurrentSpeed < 0.0f) {
			mCurrentSpeed = 0.0f;
			mMoveSpeed = 0.0f;
		}
	}

	//Translate(-Vec2_Right * (mCurrentSpeed + mMoveSpeed) * m_pTimer->DeltaTime() * (std::cos(Rotation()), std::sin(Rotation()), World));
	//if (misMovingLeft == true) {
	//	mCurrentSpeed += 100.0f * m_pTimer->DeltaTime();
	//	if (mCurrentSpeed > mMaxSpeed) {
	//		mCurrentSpeed = mMaxSpeed;
	//	}
	//}

	//if (misMovingLeft == false) {
	//	mCurrentSpeed -= 100.0f * m_pTimer->DeltaTime();
	//	if (mCurrentSpeed < 0.0f) {
	//		mCurrentSpeed = 0.0f;
	//		mMoveSpeed = 0.0f;
	//	}
	//}
}

//void Player::MarioPhysicsLeft()
//{
//	Translate(-Vec2_Right * (mCurrentSpeed + mMoveSpeed) * m_pTimer->DeltaTime() * (std::cos(Rotation()), std::sin(Rotation()), World));
//	if (misMovingLeft == true) {
//		mCurrentSpeed += 50.0f * m_pTimer->DeltaTime();
//		if (mCurrentSpeed > mMaxSpeed) {
//			mCurrentSpeed = mMaxSpeed;
//		}
//	}
//
//	if (misMovingLeft == false) {
//		mCurrentSpeed -= 80.0f * m_pTimer->DeltaTime();
//		if (mCurrentSpeed < 0.0f) {
//			mCurrentSpeed = 0.0f;
//			mMoveSpeed = 0.0f;
//		}
//	}
//}
