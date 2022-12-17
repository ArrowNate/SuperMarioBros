#include "GameEntity.h"

namespace SDLFramework {

	GameEntity::GameEntity(float x, float y)
		: mPosition(x, y), mRotation(0.0f), mScale(Vec2_One), mActive(true), m_pParent(nullptr) {
	}

	SDLFramework::GameEntity::GameEntity(const Vector2 & position)
		: mPosition(position), mRotation(0.0f), mScale(Vec2_One), mActive(true), m_pParent(nullptr) {
	}


	GameEntity::~GameEntity() {
		m_pParent = nullptr;
	}

	void GameEntity::Position(float x, float y) {
		mPosition = Vector2(x, y);
	}

	void GameEntity::Position(const Vector2 & pos) {
		mPosition = pos;
	}

	Vector2 GameEntity::Position(Space space) {
		if (space == Local || m_pParent == nullptr) {
			return mPosition;
		}
		Vector2 parentScale = m_pParent->Scale(World);
		Vector2 rotPosition = RotateVector(mPosition, m_pParent->Rotation(Local));

		return m_pParent->Position(World) + Vector2(rotPosition.x * parentScale.x, rotPosition.y * parentScale.y);
	}

	void GameEntity::Rotation(float rot) {
		mRotation = rot;

		while (mRotation > 360.0f) {
			mRotation -= 360.0f;
		}

		while (mRotation < 0.0f) {
			mRotation += 360.0f;
		}
	}

	float GameEntity::Rotation(Space space) {
		if (space == Local || m_pParent == nullptr) {
			return mRotation;
		}

		return m_pParent->Rotation(World) + mRotation;
	}

	void GameEntity::Scale(Vector2 scale) {
		mScale = scale;
	}

	Vector2 GameEntity::Scale(Space space) {
		if (space == Local || m_pParent == nullptr) {
			return mScale;
		}

		Vector2 scale = m_pParent->Scale(World);
		scale.x *= mScale.x;
		scale.y *= mScale.y;

		return scale;
	}

	void GameEntity::Active(bool active) {
		mActive = active;
	}

	bool GameEntity::Active() const {
		return mActive;
	}

	void GameEntity::Parent(GameEntity * parent) {
		if (parent == nullptr) {
			mPosition = Position(World);
			mRotation = Rotation(World);
			mScale = Scale(World);
		}
		else {
			if (m_pParent != nullptr) {
				Parent(nullptr);
			}
			Vector2 parentScale = parent->Scale(World);

			mPosition = RotateVector(Position(World) - parent->Position(World), -parent->Rotation(World));
			mPosition.x /= parentScale.x;
			mPosition.y /= parentScale.y;

			mRotation -= parent->Rotation(World);
			mScale = Vector2(mScale.x / parentScale.x, mScale.y / parentScale.y);
		}

		m_pParent = parent;
	}

	GameEntity * GameEntity::Parent() const
	{
		return m_pParent;
	}

	void GameEntity::Translate(Vector2 vec, Space space) {
		if (space == World) {
			mPosition += vec;
		}
		else {
			mPosition += RotateVector(vec, Rotation());
		}
	}

	void GameEntity::Rotate(float amount) {
		Rotation(mRotation + amount);
	}
}