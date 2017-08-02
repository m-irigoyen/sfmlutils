#include <sfmlutils/abstractbutton.hpp>

#include <sfmlutils/shapeutils.hpp>

namespace sfmlutils
{
	AbstractButton::AbstractButton()
		: text_(new sf::Text())
		, rectShape_(new sf::RectangleShape())
		, textShader_(nullptr)
		, rectShader_(nullptr)
	{

	}

	void AbstractButton::setString(std::string text)
	{
		text_->setString(text);
		sfmlutils::setTextOriginToCenter(text_);
		computeRect();
	}

	void AbstractButton::setMargin(const sf::Vector2f & margin)
	{
		margin_ = margin;
		computeRect();
	}

	sf::Text * sfmlutils::AbstractButton::getText() const
	{
		return text_;
	}

	sf::RectangleShape * AbstractButton::getRectShape() const
	{
		return rectShape_;
	}

	sf::Shader * AbstractButton::getTextShader() const
	{
		return textShader_;
	}

	sf::Shader * AbstractButton::getRectShader() const
	{
		return rectShader_;
	}

	sf::Vector2f AbstractButton::getMargin() const
	{
		return margin_;
	}

	sf::Vector2f AbstractButton::getSize() const
	{
		return rectShape_->getSize() + margin_;
	}

	void AbstractButton::draw(sf::RenderWindow * window) const
	{
		rectShape_->setPosition(position);
		if (rectShader_)
		{
			window->draw(*rectShape_, rectShader_);
		}
		else
		{
			window->draw(*rectShape_);
		}

		text_->setPosition(position);
		if (textShader_)
		{
			window->draw(*text_, textShader_);
		}
		else
		{
			window->draw(*text_);
		}
	}

	bool AbstractButton::isInsideButton(const sf::Vector2f & pos) const
	{
		return false;
	}

	void AbstractButton::computeRect()
	{
		sf::FloatRect textBounds = text_->getGlobalBounds();
		rectShape_->setSize(sf::Vector2f(textBounds.width + margin_.x * 2
			, textBounds.height + margin_.y * 2));
		sfmlutils::setShapeOriginToCenter(rectShape_);
	}
}

