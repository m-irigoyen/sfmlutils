#pragma once

#include <sfmlutils\abstractradiobutton.hpp>

#include <mutils/collision.hpp>

namespace sfmlutils
{
	AbstractRadioButton::AbstractRadioButton()
		: AbstractButton()
		, state_(REST)
	{
	}

	void AbstractRadioButton::onMouseMove(const sf::Vector2f & pos)
	{
		if (isInsideButton(pos) && (state_ == REST))
		{
			setState(HOVER);
		}
		else if (!isInsideButton(pos) && (state_ == HOVER))
		{
			setState(REST);
		}
	}

	bool AbstractRadioButton::onMousePress(const sf::Vector2f & pos)
	{
		if (isInsideButton(pos) && (state_ == HOVER))
		{
			setState(CLICKED);
			return true;
		}
		return false;
	}

	bool AbstractRadioButton::onMouseRelease(const sf::Vector2f & pos)
	{
		if (state_ == STATE::CLICKED)
		{
			if (isInsideButton(pos))
			{
				setState(SELECTED);
				notifyObservers();
				return true;
			}
		}
		return false;
	}

	AbstractRadioButton::STATE AbstractRadioButton::getState() const
	{
		return state_;
	}
	bool AbstractRadioButton::isInsideButton(const sf::Vector2f & pos) const
	{
		return mutils::isInAABB(pos, getRectShape()->getGlobalBounds());
	}
}