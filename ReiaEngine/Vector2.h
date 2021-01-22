#pragma once

class Vector2
{
public:
	double X;
	double Y;

	Vector2(double x, double y) : X(x), Y(y) {}

	double Distance(Vector2 a, Vector2 b) {
		Vector2 result = a - b;

		return result.X + result.Y;
	}

	Vector2& operator+=(const Vector2& a)
	{
		this->X += a.X;
		this->Y += a.Y;

		return *this;
	}

	Vector2& operator-=(const Vector2& a)
	{
		this->X -= a.X;
		this->Y -= a.Y;

		return *this;
	}

	friend Vector2 operator-(Vector2 a, const Vector2& b)
	{
		a -= b;
		return a;
	}

	friend Vector2 operator+(Vector2 a, const Vector2& b)
	{
		a += b;
		return a;
	}
};

