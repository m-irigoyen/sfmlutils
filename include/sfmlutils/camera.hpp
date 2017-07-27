#pragma once

#include <mutils\vec2.hpp>
#include <SFML\Graphics\RenderWindow.hpp>

namespace sfmlutils
{
	class Camera
	{
	public:
		Camera(const sf::RenderWindow& window);
		Camera(const sf::RenderWindow& window, const mutils::Vec2& size);
		Camera(const sf::RenderWindow& window, const sf::FloatRect& rect);

		//! Returns a view corresponding to the camera values
		sf::View toView() const;
		sf::FloatRect toViewRect() const;
		mutils::Vec2 getWorldSize() const;
		sf::FloatRect getWorldRect() const;

		//! Moves camera by given vector
		void move(const mutils::Vec2& movement);

		//! Rotates the came by given amount
		void rotate(const float& rotation);

		void reset(const mutils::Vec2& pos = mutils::Vec2(0.f, 0.f)
			, const mutils::Vec2& size = mutils::Vec2(1000.f, 1000.f)
			, const sf::FloatRect& vp = sf::FloatRect(0, 0, 1, 1)
			, const float& rotation = 0.f
			, const float& scale = 1.f);

		mutils::Vec2 size;
		mutils::Vec2 position;
		float rotation;
		float scale;
		sf::FloatRect viewport;
		const sf::RenderWindow& window;
	};
}