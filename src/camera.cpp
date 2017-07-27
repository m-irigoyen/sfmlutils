#include <sfmlutils\camera.hpp>

namespace sfmlutils
{
	using Vec2 = mutils::Vec2;

	Camera::Camera(const sf::RenderWindow& w)
		: window(w)
	{
		reset(Vec2(0, 0), Vec2(1000, 1000));
	}

	Camera::Camera(const sf::RenderWindow& w, const mutils::Vec2 & s)
		: window(w)
	{
		reset(Vec2(0, 0), s);
	}

	Camera::Camera(const sf::RenderWindow& w, const sf::FloatRect & rect)
		: window(w)
	{
		reset(
			Vec2(rect.left + rect.width / 2.f, rect.top + rect.height / 2.f)
			, Vec2(rect.width, rect.height));
	}

	sf::View Camera::toView() const
	{
		sf::View v(getWorldRect());
		v.rotate(rotation);
		v.setViewport(viewport);
		return v;
	}

	mutils::Vec2 Camera::getWorldSize() const
	{
		// TODO : make sure scale doesn't mess computation up
		Vec2 s = size;
		float ratio = (viewport.width * window.getSize().x)
			/ (viewport.height * window.getSize().y);
		if (ratio > 1.f)
		{
			s.x *= ratio;
		}
		else if (ratio < 1.f)
		{
			s.y *= 1.f / ratio;
		}
		return s * scale;
	}

	sf::FloatRect Camera::getWorldRect() const
	{
		Vec2 s = getWorldSize();
		return sf::FloatRect(position.x - s.x / 2.f
			, position.y - s.y / 2.f
			, s.x
			, s.y);
	}

	void Camera::move(const mutils::Vec2 & movement)
	{
		position += movement;
	}
	void Camera::rotate(const float & rot)
	{
		rotation += rot;
	}

	void Camera::reset(const mutils::Vec2 & pos
		, const mutils::Vec2 & s
		, const sf::FloatRect& vp
		, const float & rot
		, const float & sca)
	{
		position = pos;
		size = s;
		viewport = vp;
		rotation = rot;
		scale = sca;
	}
}


