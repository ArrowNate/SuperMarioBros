#include "Player.h"

Player::Player()
{
	m_pTimer = Timer::Instance();
	m_pInput = InputManager::Instance();
	m_pAudio = AudioManager::Instance();

	mVisible = false;
	misNotMoving = false;
	mAnimatingRight = false;
	misMovingRight = false;
	misMovingLeft = false;
	mWasHit = false;

	mScore = 0;
	mLives = 3;

	m_pMario = new TextureGL("MarioIdle_01.png", 0, 0, 33, 41);
	m_pMario->Parent(this);
	m_pMario->Position(-169.0f, 181.0f);

	//m_pMarioMoving = new AnimatedTexture("MarioRunning.png", 0.0f, 0.0f, 41.0f, 41.0f, 3, 1.0f, AnimatedTexture::Horizontal);
	//m_pMarioMoving->Parent(m_pMario);
	//m_pMarioMoving->Position(Vec2_Zero);

	m_pMarioMoving = new TextureGL("MarioRunning.png", 0.0f, 0.0f, 41.0f, 41.0f);
	m_pMarioMoving->Parent(m_pMario);
	m_pMarioMoving->Position(Vec2_Zero);

	mCurrentSpeed = 0.0f;
	mCurrentSpeedLeft = 0.0f;
	mMoveSpeed = 0.0f;
	mMoveSpeedLeft = 0.0f;
	mMaxSpeed = 100.0f;
	mMaxSpeedLeft = -100.0f;
}

Player::~Player()
{
	m_pTimer = nullptr;
	m_pInput = nullptr;
	m_pAudio = nullptr;

	delete m_pMario;
	m_pMario = nullptr;

	delete m_pMarioMoving;
	m_pMarioMoving = nullptr;
}

//bool Player::IsMovingRight()
//{
//	return misMovingRight;
//}
//
//bool Player::IsMovingLeft()
//{
//	return misMovingLeft;
//}

void Player::Visible(bool visible)
{
	mVisible = visible;
}

bool Player::IsNotRunning()
{
	return misNotMoving;
}

bool Player::IsAnimating()
{
	return mAnimatingRight;
}

void Player::Running()
{
	mAnimatingRight = true;
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
	//m_pMario->Update();
	//m_pMarioMoving->Update();
	//IsAnimating();
	Running();
	HandleMovementRight();
	HandleMovementLeft();
	HandleFire();
	MarioPhysicsRight();
	MarioPhysicsLeft();
	//IsMovingRight();
	//IsMovingLeft();
	if (mAnimatingRight) {
		m_pMarioMoving->Update();
		mAnimatingRight = false;
	}
	else {
		m_pMario->Update();
	}
}

void Player::Render()
{
	//m_pMario->Render();
	//IsAnimating();
	if (!mVisible) {
		if (mAnimatingRight) {
			m_pMarioMoving->Render();
		}
		else {
			m_pMario->Render();
		}
	}
}

void Player::HandleMovementRight()
{
	if (m_pInput->KeyDown(SDL_SCANCODE_D) && !misNotMoving) {
		Running();
		misMovingRight = true;
		misMovingLeft = false;
	}
	if (m_pInput->KeyReleased(SDL_SCANCODE_D) && misNotMoving) {
		mAnimatingRight = false;
		misMovingRight = false;
		misMovingLeft = false;
	}
}

void Player::HandleMovementLeft()
{
	if (m_pInput->KeyDown(SDL_SCANCODE_A)) {
		misMovingLeft = true;
		misMovingRight = false;
		mAnimatingRight = false;
	}
	if (m_pInput->KeyReleased(SDL_SCANCODE_A)) {
		misMovingLeft = false;
		misMovingRight = false;
		mAnimatingRight = false;
	}
}

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
//
//	//Translate(-Vec2_Right * (mCurrentSpeed + mMoveSpeed) * m_pTimer->DeltaTime() * (std::cos(Rotation()), std::sin(Rotation()), World));
//	//if (misMovingLeft == true) {
//	//	mCurrentSpeed += 100.0f * m_pTimer->DeltaTime();
//	//	if (mCurrentSpeed > mMaxSpeed) {
//	//		mCurrentSpeed = mMaxSpeed;
//	//	}
//	//}
//
//	//if (misMovingLeft == false) {
//	//	mCurrentSpeed -= 100.0f * m_pTimer->DeltaTime();
//	//	if (mCurrentSpeed < 0.0f) {
//	//		mCurrentSpeed = 0.0f;
//	//		mMoveSpeed = 0.0f;
//	//	}
//	//}
}

void Player::MarioPhysicsLeft()
{
	Translate(Vec2_Right * (mCurrentSpeedLeft - mMoveSpeedLeft) * m_pTimer->DeltaTime() * (std::cos(Rotation()), std::sin(Rotation()), World));
	if (misMovingLeft == true) {
		mCurrentSpeedLeft -= 50.0f * m_pTimer->DeltaTime();
		if (mCurrentSpeedLeft < mMaxSpeedLeft) {
			mCurrentSpeedLeft = mMaxSpeedLeft;
		}
	}

	if (misMovingLeft == false) {
		mCurrentSpeedLeft += 80.0f * m_pTimer->DeltaTime();
		if (mCurrentSpeedLeft > 0.0f) {
			mCurrentSpeedLeft = 0.0f;
			mMoveSpeedLeft = 0.0f;
		}
	}
}
