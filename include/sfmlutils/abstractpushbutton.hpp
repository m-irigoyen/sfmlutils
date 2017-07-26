#pragma once

#include <SFML\Graphics\Text.hpp>
#include <SFML\Graphics\RectangleShape.hpp>
#include <SFML\Graphics\RenderWindow.hpp>

#include <mutils/observed.hpp>

#include <string>

namespace sfmlutils
{
	class AbstractPushButton : public mutils::Observed
	{
	public :
		enum STATE
		{
			REST,
			HOVER,
			CLICKED,

			COUNT
		};

		AbstractPushButton();
		~AbstractPushButton();

		virtual void draw(sf::RenderWindow* window) const;

		sf::Text* getText() const;
		sf::RectangleShape* getRectShape() const;
		sf::Shader* getTextShader() const;
		sf::Shader* getRectShader() const;
		STATE getState() const;
		sf::Vector2f getMargin() const;

		void setString(std::string text);
		void setMargin(const sf::Vector2f& margin);

		virtual void inputPosition(const sf::Vector2f& pos);
		virtual bool onMousePress(const sf::Vector2f& pos);
		virtual bool onMouseRelease(const sf::Vector2f& pos);

		sf::Vector2f getSize() const;

		//! WARNING : This does NOT consider rotation
		virtual bool isInsideButton(const sf::Vector2f& pos);

		sf::Vector2f position;
		//float rotation;
		//sf::Vector2f scale;

	protected:
		// Functions
		virtual void setState(STATE state) = 0;
		void switchState(STATE state);

		void computeRect();

		// Attributes
		STATE state_;
		sf::Vector2f margin_;

		sf::Text* text_;
		sf::RectangleShape* rectShape_;
		sf::Shader* textShader_;
		sf::Shader* rectShader_;

		// Inherited via Observed
		virtual void onObserverRegistered(mutils::Observer * obs) override;
		virtual void onObserverNotified(mutils::Observer * obs) override;
	};
}