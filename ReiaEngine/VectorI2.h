#pragma once

class VectorI2
{
public:
	int X;
	int Y;

	VectorI2(int x, int y) : X(x), Y(y) {}

	int Distance(VectorI2 a, VectorI2 b) {
		VectorI2 result = a - b;

		return result.X + result.Y;
	}

	VectorI2& operator+=(const VectorI2& a)
	{
		this->X += a.X;
		this->Y += a.Y;

		return *this;
	}

	VectorI2& operator-=(const VectorI2& a)
	{
		this->X -= a.X;
		this->Y -= a.Y;

		return *this;
	}

	friend VectorI2 operator-(VectorI2 a, const VectorI2& b)
	{
		a -= b;
		return a;
	}

	friend VectorI2 operator+(VectorI2 a, const VectorI2& b)
	{
		a += b;
		return a;
	}
};

