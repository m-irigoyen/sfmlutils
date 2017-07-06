#include <SFML\Graphics\Shape.hpp>
#include <SFML\Graphics\Text.hpp>

namespace sfmlutils
{
	void setShapeOriginToCenter(sf::Shape* shape);
	void setTextOriginToCenter(sf::Text* shape);
	float length(const sf::Vector2f& v);
	sf::Vector2f normalized(const sf::Vector2f& v);
}