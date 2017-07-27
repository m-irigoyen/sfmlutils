#include <sfmlutils/abstractpushbutton.hpp>

#include <mutils/assert.hpp>
#include <mutils/collision.hpp>

#include <sfmlutils/shapeutils.hpp>

namespace sfmlutils
{
	AbstractPushButton::AbstractPushButton()
		: state_(STATE::REST)
		, text_(nullptr)
		, rectShape_(nullptr)
		, textShader_(nullptr)
		, rectShader_(nullptr)
	{
		text_ = new sf::Text();
		rectShape_ = new sf::RectangleShape();
	}

	AbstractPushButton::~AbstractPushButton()
	{
		if (text_) { delete (text_); }
		if (rectShape_) { delete (rectShape_); }
		// Shaders are not owned by graphics objects
	}

	void AbstractPushButton::setString(std::string text)
	{
		text_->setString(text);
		sfmlutils::setTextOriginToCenter(text_);
		computeRect();
	}

	void AbstractPushButton::setMargin(const sf::Vector2f & margin)
	{
		margin_ = margin;
		computeRect();
	}

	sf::Text * sfmlutils::AbstractPushButton::getText() const
	{
		return text_;
	}

	sf::RectangleShape * AbstractPushButton::getRectShape() const
	{
		return rectShape_;
	}

	sf::Shader * AbstractPushButton::getTextShader() const
	{
		return textShader_;
	}

	sf::Shader * AbstractPushButton::getRectShader() const
	{
		return rectShader_;
	}

	AbstractPushButton::STATE AbstractPushButton::getState() const
	{
		return state_;
	}

	sf::Vector2f AbstractPushButton::getMargin() const
	{
		return margin_;
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

	sf::Vector2f AbstractPushButton::getSize() const
	{
		return rectShape_->getSize() + margin_;
	}

	bool AbstractPushButton::isInsideButton(const sf::Vector2f & pos) const
	{
		sf::FloatRect r = getRectShape()->getGlobalBounds();

		return (mutils::isInAABB(
			pos
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

	void AbstractPushButton::computeRect()
	{
		sf::FloatRect textBounds = text_->getGlobalBounds();
		rectShape_->setSize(sf::Vector2f(textBounds.width + margin_.x*2
			, textBounds.height + margin_.y*2));
		sfmlutils::setShapeOriginToCenter(rectShape_);
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


