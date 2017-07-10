#include <sfmlutils\vec2.hpp>

/* Includes - STL */
#include <iostream>
#include <cmath>

namespace sfmlutils
{
	Vec2::Vec2(void) : x(0), y(0)
	{
	}

	Vec2::Vec2(const Vec2 & v)
		: x(v.x), y(v.y)
	{
	}

	Vec2::Vec2(float x, float y) : x(x), y(y)
	{
	}

	Vec2::Vec2(const sf::Vector2f &v)
		: x(v.x), y(v.y)
	{
	}

	Vec2::Vec2(const sf::Vector2i & v)
		: x(v.x), y(v.y)
	{
	}

	Vec2::~Vec2(void)
	{
	}

	void Vec2::reassign(float x, float y)
	{
		this->x = x;
		this->y = y;
	}

	void Vec2::reassign(Vec2 otr)
	{
		reassign(otr.x, otr.y);
	}

	void Vec2::clamp(float min, float max)
	{
		if (x < min)
			x = min;
		else if (x > max)
			x = max;

		if (y < min)
			y = min;
		else if (y > max)
			y = max;
	}

	void Vec2::clamp(float minX, float maxX, float minY, float maxY)
	{
		if (x < minX)
			x = minX;
		else if (x > maxX)
			x = maxX;

		if (x < minY)
			x = minY;
		else if (x > maxY)
			x = maxY;
	}

	const sf::Vector2f Vec2::toSFMLVector() const
	{
		return sf::Vector2f(this->x, this->y);
	}

	Vec2& Vec2::operator+=(const Vec2 otr)
	{
		this->x += otr.x;
		this->y += otr.y;
		return *this;
	}

	Vec2& Vec2::operator-=(const Vec2 otr)
	{
		this->x -= otr.x;
		this->y -= otr.y;
		return *this;
	}

	Vec2& Vec2::operator*=(float scl)
	{
		this->x *= scl;
		this->y *= scl;
		return *this;
	}

	Vec2& Vec2::operator/=(float scl)
	{
		this->x /= scl;
		this->y /= scl;
		return *this;
	}

	Vec2& Vec2::operator%=(float theta)
	{
		float cs = std::cos(theta);
		float sn = std::sin(theta);

		float px = x * cs - y * sn;
		float py = x * sn + y * cs;

		this->x = px;
		this->y = py;
		return *this;
	}

	Vec2 Vec2::operator+(const Vec2 otr) const
	{
		return Vec2(this->x + otr.x, this->y + otr.y);
	}

	Vec2 Vec2::operator-(const Vec2 otr) const
	{
		return Vec2(this->x - otr.x, this->y - otr.y);
	}

	Vec2 Vec2::operator*(float scl) const
	{
		return Vec2(this->x * scl, this->y * scl);
	}

	Vec2 Vec2::operator/(float scl) const
	{
		return Vec2(this->x / scl, this->y / scl);
	}

	Vec2 Vec2::operator%(float theta) const
	{
		float cs = std::cos(theta);
		float sn = std::sin(theta);

		float px = x * cs - y * sn;
		float py = x * sn + y * cs;

		return Vec2(px, py);
	}

	void Vec2::rotateDeg(float f)
	{
		rotateRad(degToRad(f));
	}

	void Vec2::rotateRad(float f)
	{
		*this %= f;
	}

	Vec2 Vec2::rotatedDeg(float f) const
	{
		return rotatedRad(degToRad(f));
	}

	Vec2 Vec2::rotatedRad(float f) const
	{
		return operator%(f);
	}

	bool Vec2::operator==(const Vec2 otr)
	{
		return this->x == otr.x && this->y == otr.y;
	}

	bool Vec2::operator!=(const Vec2 otr)
	{
		return !(*this == otr);
	}

	float Vec2::dot(const Vec2 otr)
	{
		return this->x * otr.x + this->y * otr.y;
	}

	Vec2 Vec2::normalize()
	{
		*this = *this / this->length();
		return *this;
	}

	Vec2 Vec2::normalized() const
	{
		return *this / this->length();
	}

	Vec2& Vec2::trunc(float max)
	{
		if (this->length() > max)
			this->reassign(this->normalized() * max);
		return *this;
	}

	float Vec2::angle() const
	{
		return std::atan2(this->x, this->y);
	}

	float Vec2::length() const
	{
		return std::sqrt(std::pow(this->x, 2) + std::pow(this->y, 2));
	}

	const std::string Vec2::toString() const
	{
		return std::string("[" + std::to_string(x) + ", " + std::to_string(y) + "]");
	}
	float Vec2::degToRad(float angleInDegree)
	{
		return angleInDegree * PI / 180;
	}
	float Vec2::radToDeg(float angleInRadian)
	{
		return angleInRadian * 180 / PI;
	}
}