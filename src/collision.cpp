#include <sfmlutils\collision.hpp>

bool sfmlutils::isInAABB(Vec2 p, Vec2 aabbTopLeft, Vec2 aabbBottomRight)
{
	// Changing coordinates so that aabtopleft is 0,0
	aabbBottomRight -= aabbTopLeft;
	p -= aabbTopLeft;
	return (p.x >= 0) && (p.y >= 0) && (p.x <= aabbBottomRight.x) && (p.y <= aabbBottomRight.y);
}

bool sfmlutils::isInCircle(Vec2 p, Vec2 center, float radius)
{
	// TODO : assert radius >= 0
	return (center-p).length() <= radius;
}
