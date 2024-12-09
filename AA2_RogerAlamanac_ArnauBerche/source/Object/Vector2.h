#pragma once
#include <cmath>
class Vector2
{
public:
	float x;
	float y;
	Vector2() : x(0.0f), y(0.0f) {}
	Vector2(float _x, float _y) : x(_x), y(_y) {}
	void Normalize() {
		float length = sqrtf(x * x + y * y);
		x /= length;
		y /= length;
	}
	inline Vector2 const operator+(const Vector2& other) const { return Vector2(x + other.x, y + other.y); }
	inline Vector2 const operator-(const Vector2& other) const { return Vector2(x - other.x, y - other.y); }
	inline Vector2 const operator*(const Vector2& other) const { return Vector2(x * other.x, y * other.y); }
	inline Vector2 const operator*(const float& value) const { return Vector2(x * value, y * value); }
	inline Vector2 const operator/(const float& value) const { return Vector2(x / value, y / value); }
};

