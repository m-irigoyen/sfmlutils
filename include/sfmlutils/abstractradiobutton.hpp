#pragma once

#include <sfmlutils\abstractbutton.hpp>

namespace sfmlutils
{
	class AbstractRadioButton : public AbstractButton
	{
	public:
		AbstractRadioButton();

		enum STATE
		{
			REST,
			HOVER,
			CLICKED,
			SELECTED,

			COUNT
		};

		virtual void onMouseMove(const sf::Vector2f& pos) override;
		virtual bool onMousePress(const sf::Vector2f& pos) override;
		virtual bool onMouseRelease(const sf::Vector2f& pos) override;

		//! Forces state without notifying observers
		virtual void setState(STATE s) = 0;

		STATE getState() const;

	protected:
		STATE state_;
	};
}