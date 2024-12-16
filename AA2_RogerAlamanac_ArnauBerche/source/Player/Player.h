#pragma once
#include "../Object/Object.h"
#include "Attacker.h"
#include "Damager.h"
enum class PlayerDirections
{
	NONE = 0,
	RIGHT = 1,
	UPERRIGHT = 2,
	UP = 3,
	UPERLEFT = 4,
	LEFT = 5,
	DOWNLEFT = 6,
	DOWN = 7,
	DOWNRIGHT = 8
};

class Player : public IAttacker, public IDamager {
public:
	Player() = default;
	Vector2 DirectionToVector(PlayerDirections direction) {
		switch (direction) {
		case PlayerDirections::RIGHT: return { 1.f, 0.f };
		case PlayerDirections::UPERRIGHT: return { std::sqrt(0.5f), -std::sqrt(0.5f) };
		case PlayerDirections::UP: return { 0.f, -1.f };
		case PlayerDirections::UPERLEFT: return { -std::sqrt(0.5f), -std::sqrt(0.5f) };
		case PlayerDirections::LEFT: return { -1.f, 0.f };
		case PlayerDirections::DOWNLEFT: return { -std::sqrt(0.5f), std::sqrt(0.5f) };
		case PlayerDirections::DOWN: return { 0.f, 1.f };
		case PlayerDirections::DOWNRIGHT: return { std::sqrt(0.5f), std::sqrt(0.5f) };
		case PlayerDirections::NONE: return { 0.f, 0.f };
		}
	}
	virtual void Movement() = 0;
	virtual void Attack() = 0;
	virtual void ReceiveDamage() = 0;
};