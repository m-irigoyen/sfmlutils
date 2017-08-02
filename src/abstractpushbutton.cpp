#include <sfmlutils/abstractpushbutton.hpp>

#include <sfmlutils/vectorutils.hpp>

#include <mutils/assert.hpp>
#include <mutils/collision.hpp>

#include <sfmlutils/shapeutils.hpp>

namespace sfmlutils
{
	AbstractPushButton::AbstractPushButton()
		: AbstractButton()
		, state_(STATE::REST)
	{
	}

	AbstractPushButton::~AbstractPushButton()
	{
		if (text_) { delete (text_); }
		if (rectShape_) { delete (rectShape_); }
		// Shaders are not owned by graphics objects
	}

	AbstractPushButton::STATE AbstractPushButton::getState() const
	{
		return state_;
	}

	void AbstractPushButton::onMouseMove(const sf::Vector2f & pos)
	{
		if (isInsideButton(pos))
		{
			if (state_ == STATE::REST)
			{
				switchState(STATE::HOVER);
			}
		}
		else
		{
			if (state_ == STATE::HOVER)
			{
				switchState(STATE::REST);
			}
		}
	}

	bool AbstractPushButton::onMousePress(const sf::Vector2f & pos)
	{
		if (isInsideButton(pos))
		{
			switchState(STATE::CLICKED);
			return true;
		}
		return false;
	}

	bool AbstractPushButton::onMouseRelease(const sf::Vector2f& pos)
	{
		if (state_ == STATE::CLICKED)
		{
			if (isInsideButton(pos))
			{
				notifyObservers();
				switchState(STATE::REST);
				return true;
			}
			else
			{
				switchState(STATE::REST);
			}
		}
		return false;
	}

	bool AbstractPushButton::isInsideButton(const sf::Vector2f & pos) const
	{
		sf::FloatRect r = getRectShape()->getGlobalBounds();

		return (mutils::isInAABB(
			sfToVec2(pos)
			, mutils::Vec2(r.left, r.top)
			, mutils::Vec2(r.left + r.width, r.top + r.height)));
	}

	void AbstractPushButton::switchState(STATE state)
	{
		if (state_ == state)
		{
			return;
		}
		else if (state != STATE::COUNT)
		{
			setState(state);
		}
		else
		{
			MUTILS_ASSERT(false);
		}
	}

	void AbstractPushButton::draw(sf::RenderWindow * window) const
	{
		rectShape_->setPosition(position);
		//rectShape_->setScale(scale);
		if (rectShader_)
		{
			window->draw(*rectShape_, rectShader_);
		}
		else
		{
			window->draw(*rectShape_);
		}

		text_->setPosition(position);
		//text_->setScale(scale);
		if (textShader_)
		{
			window->draw(*text_, textShader_);
		}
		else
		{
			window->draw(*text_);
		}
	}

	void AbstractPushButton::onObserverRegistered(mutils::Observer * obs)
	{
	}
	void AbstractPushButton::onObserverNotified(mutils::Observer * obs)
	{
	}
}


