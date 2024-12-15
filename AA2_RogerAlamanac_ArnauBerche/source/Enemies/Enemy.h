#pragma once
#include <queue>
#include "../Object/Vector2.h"
enum class Directions 
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

class Enemy {
private:
	int health;
	int damage;
	bool loops;


public:
	Enemy(int _health, int _damage, bool _loops) : health(_health), damage(_damage), loops(_loops) {};
	virtual void BaseMovement() = 0;

protected:
	std::queue<Directions> pathPattern;
	float movementTimeRemaining;
	Directions currentDirection;
	float movementSpeed;

	Vector2 DirectionToVector(Directions direction) {
		switch (direction) {
		case Directions::RIGHT: return { 1.f, 0.f };
		case Directions::UPERRIGHT: return { std::sqrt(0.5f), -std::sqrt(0.5f) };
		case Directions::UP: return { 0.f, -1.f };
		case Directions::UPERLEFT: return { -std::sqrt(0.5f), -std::sqrt(0.5f) };
		case Directions::LEFT: return { -1.f, 0.f };
		case Directions::DOWNLEFT: return { -std::sqrt(0.5f), std::sqrt(0.5f) };
		case Directions::DOWN: return { 0.f, 1.f };
		case Directions::DOWNRIGHT: return { std::sqrt(0.5f), std::sqrt(0.5f) };
		case Directions::NONE: return { 0.f, 0.f };
		}
	}

	bool Loops() 
	{
		return loops;
	}

};