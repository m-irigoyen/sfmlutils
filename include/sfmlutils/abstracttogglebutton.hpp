#pragma once

#include <sfmlutils\abstractbutton.hpp>

namespace sfmlutils
{
	class AbstractToggleButton : public AbstractButton
	{
	public:
		enum STATE
		{
			OFF,
			ON,

			COUNT
		};

		AbstractToggleButton();

		virtual void onMouseMove(const sf::Vector2f& pos) override;
		virtual bool onMousePress(const sf::Vector2f& pos) override;
		virtual bool onMouseRelease(const sf::Vector2f& pos) override;
		virtual bool isInsideButton(const sf::Vector2f & pos) const override;

		//! Forces state without notifying observers
		virtual void setState(STATE s) = 0;

		STATE getState() const;

		virtual void setHoverIndication() = 0;

		virtual bool isOn() const;

	protected:
		bool hover_;
		STATE state_;
	};
}