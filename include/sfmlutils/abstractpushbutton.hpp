#pragma once

#include <sfmlutils\abstractbutton.hpp>

namespace sfmlutils
{
	class AbstractPushButton : public AbstractButton
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

		virtual void draw(sf::RenderWindow* window) const override;

		STATE getState() const;

		virtual void onMouseMove(const sf::Vector2f& pos) override;
		virtual bool onMousePress(const sf::Vector2f& pos) override;
		virtual bool onMouseRelease(const sf::Vector2f& pos) override;

		//! WARNING : This does NOT consider rotation
		virtual bool isInsideButton(const sf::Vector2f& pos) const;

	protected:
		// Functions
		virtual void setState(STATE state) = 0;
		void switchState(STATE state);

		// Attributes
		STATE state_;

		// Inherited via Observed
		virtual void onObserverRegistered(mutils::Observer * obs) override;
		virtual void onObserverNotified(mutils::Observer * obs) override;
	};
}