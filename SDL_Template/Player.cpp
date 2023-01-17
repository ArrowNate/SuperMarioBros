#include "Player.h"

Player::Player()
{
	m_pTimer = Timer::Instance();
	m_pInput = InputManager::Instance();
	m_pAudio = AudioManager::Instance();

	mVisible = false;
	misNotMoving = false;
	mIdleRight = true;
	mIdleLeft = false;
	mAnimatingRight = false;
	mAnimatingLeft = false;
	misMovingRight = false;
	misMovingLeft = false;
	mWasHit = false;
	//mDeathAnimation = false;

	mScore = 0;
	mLives = 3;

	m_pMarioRight = new TextureGL("MarioIdleRight.png", 0, 0, 33, 41);
	m_pMarioRight->Parent(this);
	m_pMarioRight->Position(-169.0f, 181.0f);
	
	m_pMarioMovingRight = new AnimatedTexture("MarioRunningRight.png", 0.0f, 0.0f, 40.0f, 41.0f, 3, 0.6f, AnimatedTexture::Horizontal);
	m_pMarioMovingRight->Parent(m_pMarioRight);
	m_pMarioMovingRight->Position(Vec2_Zero);

	m_pMarioLeft = new TextureGL("MarioIdleLeft.png", 0, 0, 33, 41);
	m_pMarioLeft->Parent(this);
	Vector2 pos = m_pMarioRight->Position();
	m_pMarioLeft->Position(pos);

	m_pMarioMovingLeft = new AnimatedTexture("MarioRunningLeft.png", 0.0f, 0.0f, 41.0f, 40.0f, 3, 0.6f, AnimatedTexture::Horizontal);
	m_pMarioMovingLeft->Parent(m_pMarioLeft);
	m_pMarioMovingLeft->Position(Vec2_Zero);

	m_pDeathAnimation = new TextureGL("MarioDeath.png", 0, 0, 30, 28);
	m_pDeathAnimation->Parent(this);
	m_pDeathAnimation->Position(pos);

	//m_pMarioMoving = new TextureGL("MarioRunning.png", 0.0f, 0.0f, 41.0f, 41.0f);
	//m_pMarioMoving->Parent(m_pMario);
	//m_pMarioMoving->Position(Vec2_Zero);

	mCurrentSpeed = 0.0f;
	mCurrentSpeedLeft = 0.0f;
	mMoveSpeed = 0.0f;
	mMoveSpeedLeft = 0.0f;
	mMaxSpeed = 400.0f;
	mMaxSpeedLeft = -400.0f;

	mDeathAnimationUp = 0.0f;
	mDeathAnimationUpMax = 60.0f;
	mDeathAnimationDown = 0.0f;
	mDeathAnimationDownMax = -1000.0f;
	mDeathAnimation = false;

	mDeathAnimationDone = true;

	mMoveBounds = Vector2(172.2f, 550.0f);
	//mMoveBoundsLeft = Vector2(0.0f, 550.0f);
}

Player::~Player()
{
	m_pTimer = nullptr;
	m_pInput = nullptr;
	m_pAudio = nullptr;

	delete m_pMarioRight;
	m_pMarioRight = nullptr;

	delete m_pMarioMovingRight;
	m_pMarioMovingRight = nullptr;

	delete m_pMarioLeft;
	m_pMarioLeft = nullptr;

	delete m_pMarioMovingLeft;
	m_pMarioMovingLeft = nullptr;
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

bool Player::IsIdleRight()
{
	return mIdleRight;
}

bool Player::IsIdleLeft()
{
	return mIdleLeft;
}

bool Player::IsAnimatingRight()
{
	return mAnimatingRight;
}

bool Player::IsAnimatingLeft()
{
	return mAnimatingLeft;
}

void Player::IdleRight()
{
	mIdleRight = true;
}

void Player::IdleLeft()
{
	mIdleLeft = true;
}

void Player::RunningRight()
{
	mAnimatingRight = true;
}

void Player::RunningLeft()
{
	mAnimatingLeft = true;
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
	//Running();
	HandleMovementRight();
	HandleMovementLeft();
	HandleFire();
	MarioPhysicsRight();
	MarioPhysicsLeft();
	MarioDeath();
	MarioDeathAnimation();

	//IsMovingRight();
	//IsMovingLeft();

	if (mAnimatingRight == true && mIdleRight == false) {

		m_pMarioMovingRight->Update();
	}
	if (mAnimatingRight == false && mIdleRight == true) {

		m_pMarioRight->Update();
	}
	if (mAnimatingLeft == true && mIdleLeft == false) {
		m_pMarioMovingLeft->Update();
	}
	if (mAnimatingLeft == false && mIdleLeft == true) {
		m_pMarioLeft->Update();
	}
}

void Player::Render()
{
	//m_pMarioRight->Render();
	//IsAnimating();
	if (!mVisible) {
		if (mAnimatingRight == false && mIdleRight == true && mIdleLeft == false && mAnimatingLeft == false && mDeathAnimation == false) {
			m_pMarioRight->Render();
		}
		if (mAnimatingRight == true && mIdleRight == false && mIdleLeft == false && mAnimatingLeft == false && mDeathAnimation == false) {
			m_pMarioMovingRight->Render();
		}
		if (mAnimatingLeft == true && mIdleRight == false && mIdleLeft == false && mAnimatingRight == false && mDeathAnimation == false) {
			m_pMarioMovingLeft->Render();
		}
		if (mAnimatingLeft == false && mIdleRight == false && mIdleLeft == true && mAnimatingRight == false && mDeathAnimation == false) {
			m_pMarioLeft->Render();
		}
		if (mDeathAnimation == true && mAnimatingRight == false && mAnimatingLeft == false && mIdleRight == false && mIdleLeft == false) {
			m_pDeathAnimation->Render(); {
				mIdleRight = true;
			}
		}
	}
}

void Player::HandleMovementRight()
{
	if (m_pInput->KeyDown(SDL_SCANCODE_D)) {
		mIdleRight = false;
		mAnimatingRight = true;
		misMovingRight = true;
		misMovingLeft = false;
		mAnimatingLeft = false;
		mIdleLeft = false;
		
	}
	if (m_pInput->KeyReleased(SDL_SCANCODE_D)) {
		mIdleRight = true;
		mAnimatingRight = false;
		misMovingRight = false;
		misMovingLeft = false;
		mAnimatingLeft = false;
		mIdleLeft = false;
	}

	Vector2 pos = Position(Local);
	if (pos.x > mMoveBounds.y - m_pMarioMovingRight->ScaledDimensions().x * 0.5f) {
		pos.x = mMoveBounds.y - m_pMarioMovingRight->ScaledDimensions().x * 0.5f;
	}

	Position(pos);
}

void Player::HandleMovementLeft()
{
	if (m_pInput->KeyDown(SDL_SCANCODE_A)) {
		mIdleLeft = false;
		mAnimatingLeft = true;
		misMovingLeft = true;
		misMovingRight = false;
		mAnimatingRight = false;
		mIdleRight = false;
	}
	if (m_pInput->KeyReleased(SDL_SCANCODE_A)) {
		mIdleLeft = true;
		mAnimatingLeft = false;
		misMovingLeft = false;
		misMovingRight = false;
		mAnimatingRight = false;
		mIdleRight = false;
	}

	Vector2 pos = Position(Local);
	std::cout << pos.x << std::endl;
	if (pos.x < mMoveBounds.x + m_pMarioMovingLeft->ScaledDimensions().x * 0.5f) {
		pos.x = mMoveBounds.x + m_pMarioMovingLeft->ScaledDimensions().x * 0.5f;
	}

	Position(pos);
}

void Player::HandleFire()
{
}

void Player::MarioPhysicsRight()
{
	Translate(Vec2_Right * (mCurrentSpeed + mMoveSpeed) * m_pTimer->DeltaTime() * (std::cos(Rotation()), std::sin(Rotation()), World));
	if (misMovingRight == true) {
		mCurrentSpeed += 200.0f * m_pTimer->DeltaTime();
		if (mCurrentSpeed > mMaxSpeed) {
			mCurrentSpeed = mMaxSpeed;
		}
	}

	if (misMovingRight == false) {
		mCurrentSpeed -= 350.0f * m_pTimer->DeltaTime();
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
		mCurrentSpeedLeft -= 200.0f * m_pTimer->DeltaTime();
		if (mCurrentSpeedLeft < mMaxSpeedLeft) {
			mCurrentSpeedLeft = mMaxSpeedLeft;
		}
	}

	if (misMovingLeft == false) {
		mCurrentSpeedLeft += 350.0f * m_pTimer->DeltaTime();
		if (mCurrentSpeedLeft > 0.0f) {
			mCurrentSpeedLeft = 0.0f;
			mMoveSpeedLeft = 0.0f;
		}
	}
}

void Player::MarioDeath()
{
	if (m_pInput->KeyPressed(SDL_SCANCODE_X)) {
		mDeathAnimation = true;
		mIdleRight = false;
		mAnimatingRight = false;
		misMovingRight = false;
		misMovingLeft = false;
		mAnimatingLeft = false;
		mIdleLeft = false;

		std::cout << "Death" << std::endl;

		mDeathAnimationStart = Position();
	}
}

void Player::MarioDeathAnimation()
{
	if (mDeathAnimation == true) {

	}

	//if (mDeathAnimation == true) {
	//	Translate(Vec2_Up * m_pTimer->DeltaTime() * mDeathAnimationUp, World);
	//}

	//Lerp(mDeathAnimationStart, Vector2(Position().x, )

}