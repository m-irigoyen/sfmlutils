#pragma once

#include <sfmlutils\abstractpushbutton.hpp>

namespace sfmlutils
{
	class AbstractRadioButton : public AbstractPushButton
	{
	public:
		virtual bool onMouseRelease(const sf::Vector2f& pos) override;

		//! Forces state without notifying observers
		virtual void forceState(STATE s);
	};
}