#pragma once

#include <sfmlutils\abstractradiobutton.hpp>

namespace sfmlutils
{
	bool AbstractRadioButton::onMouseRelease(const sf::Vector2f & pos)
	{
		if (state_ == STATE::CLICKED)
		{
			if (isInsideButton(pos))
			{
				notifyObservers();
				return true;
			}
		}
		return false;
	}

	void AbstractRadioButton::forceState(STATE s)
	{
		switchState(s);
	}
}