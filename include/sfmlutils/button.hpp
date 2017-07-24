#pragma once

namespace sfmlutils
{
	class Button
	{
	public :
		// TODO this
		Button(sf::String text);

		void setTextShader(sf::Shader* textShader);
		void setRectShader(sf::Shader* rectShader);

		void setRotation(float angle);
		void setPosition(const sf::Vector2f& pos);
		void setScale(const sf::Vector2f& scale);

		void draw(sf::RenderWindow* window);

		sf::Text text;
		sf::RectangleShape rect;
		sf::Text textHover;
		sf::RectangleShape rectHover;
		sf::Text textClicked;
		sf::RectangleShape rectCicked;

		sf::Shader* textShader_;
		sf::Shader* rectShader_;
		sf::Shader* textShaderHover_;
		sf::Shader* rectShaderHover_;
		sf::Shader* textShaderClicked_;
		sf::Shader* rectShaderClicked_;
	};
}