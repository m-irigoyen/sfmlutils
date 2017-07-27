#include <sfmlutils\abstracttogglebutton.hpp>

#include <mutils/collision.hpp>

namespace sfmlutils
{
	AbstractToggleButton::AbstractToggleButton()
		: hover_(false),
		state_(OFF)
	{
	}

	void AbstractToggleButton::onMouseMove(const sf::Vector2f & pos)
	{
		if ((isInsideButton(pos) && !hover_)
			|| ((!isInsideButton(pos) && (hover_))))
		{
			hover_ = !hover_;
		}
		setHoverIndication();
	}

	bool AbstractToggleButton::onMousePress(const sf::Vector2f & pos)
	{
		if (isInsideButton(pos))
		{
			return true;
		}
		return false;
	}

	bool AbstractToggleButton::onMouseRelease(const sf::Vector2f & pos)
	{
		if (isInsideButton(pos))
		{
			setState(state_ == ON ? OFF : ON);
			notifyObservers();
			return true;
		}
		return false;
	}

	bool AbstractToggleButton::isInsideButton(const sf::Vector2f & pos) const
	{
		return mutils::isInAABB(pos, getRectShape()->getGlobalBounds());
	}

	AbstractToggleButton::STATE AbstractToggleButton::getState() const
	{
		return state_;
	}
	bool AbstractToggleButton::isOn() const
	{
		return state_ == ON;
	}
}
