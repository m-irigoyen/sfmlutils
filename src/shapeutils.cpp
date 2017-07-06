#include <sfmlutils/shapeutils.hpp>
#include <math.h>

namespace sfmlutils
{
	void setShapeOriginToCenter(sf::Shape* shape)
	{
		if (shape)
		{
			sf::FloatRect bounds = shape->getLocalBounds();
			shape->setOrigin(bounds.left + bounds.width / 2
				, bounds.top + bounds.height / 2);
		}
	}

	void setTextOriginToCenter(sf::Text* shape)
	{
		if (shape)
		{
			sf::FloatRect bounds = shape->getLocalBounds();
			shape->setOrigin(bounds.left + (bounds.width / 2.0f)
				, bounds.top + (bounds.height /2.0f));
		}
	}

	float length(const sf::Vector2f& v)
	{
		return sqrt(v.x*v.x + v.y*v.y);
	}

	sf::Vector2f normalized(const sf::Vector2f& v)
	{
		float l = length(v);
		return sf::Vector2f(v.x / l, v.y / l);
	}
}