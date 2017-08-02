#pragma once

#include <mutils/observed.hpp>

#include <SFML\Graphics\Text.hpp>
#include <SFML\Graphics\RectangleShape.hpp>
#include <SFML\Graphics\RenderWindow.hpp>

namespace sfmlutils
{
	class AbstractButton : public mutils::Observed
	{
	public:
		AbstractButton();

		sf::Text* getText() const;
		sf::RectangleShape* getRectShape() const;
		sf::Shader* getTextShader() const;
		sf::Shader* getRectShader() const;
		sf::Vector2f getMargin() const;
		void setString(std::string text);
		void setMargin(const sf::Vector2f& margin);
		sf::Vector2f getSize() const;

		virtual void draw(sf::RenderWindow* window) const;

		virtual void onMouseMove(const sf::Vector2f& pos) = 0;
		virtual bool onMousePress(const sf::Vector2f& pos) = 0;
		virtual bool onMouseRelease(const sf::Vector2f& pos) = 0;
		virtual bool isInsideButton(const sf::Vector2f& pos) const;

		sf::Vector2f position;

	protected:
		void computeRect();

		// Inherited via Observed
		virtual void onObserverRegistered(mutils::Observer * obs = 0) = 0;
		virtual void onObserverNotified(mutils::Observer * obs = 0) = 0;


		sf::Vector2f margin_;
		sf::Text* text_;
		sf::RectangleShape* rectShape_;
		sf::Shader* textShader_;
		sf::Shader* rectShader_;
	};
}