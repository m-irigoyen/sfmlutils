#pragma once

#include <mutils/observed.hpp>
#include <SFML\Graphics\RenderWindow.hpp>

namespace sfmlutils
{
	class AbstractButton : public mutils::Observed
	{
	public:

		virtual void draw(sf::RenderWindow* window) const = 0;

		virtual void onMouseMove(const sf::Vector2f& pos) = 0;
		virtual bool onMousePress(const sf::Vector2f& pos) = 0;
		virtual bool onMouseRelease(const sf::Vector2f& pos) = 0;
		virtual bool isInsideButton(const sf::Vector2f& pos) const = 0;

		sf::Vector2f position;
	protected:
		// Inherited via Observed
		virtual void onObserverRegistered(mutils::Observer * obs = 0) = 0;
		virtual void onObserverNotified(mutils::Observer * obs = 0) = 0;
	};
}