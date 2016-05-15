#include "Button.hpp"

Button::Button(std::string normal, std::string hover, std::string clicked, sf::String text, Aligment aligment, sf::Vector2f position)
{
	this->normal = Events::LoadTexture("Images/" + normal);
	this->hover = Events::LoadTexture("Images/" + hover);
	this->clicked = Events::LoadTexture("Images/" + clicked);
	this->text = text;

	current = false;

	switch (aligment)
	{
	case Aligment::NOWHERE:
		currentSpr.setPosition(position); break;
	case Aligment::LEFT:
		currentSpr.setPosition(sf::Vector2f(10, position.y)); break;
	case Aligment::RIGHT:
		currentSpr.setPosition(sf::Vector2f(Events::screenwidth - this->normal.getSize().x - 10, position.y)); break;
	case Aligment::CENTER:
		currentSpr.setPosition(sf::Vector2f((Events::screenwidth - this->normal.getSize().x) / 2, position.y)); break;
	default:
		std::cout << "Unknown Aligment!\n"; break;
	}
}

void Button::Init() // MAKE IT IN A CONSTRUCTOR! No idea why not working
{
	currentSpr.setTexture(normal);
}

void Button::checkState(const sf::RenderWindow &window)
{
	std::cout << sf::Mouse::getPosition(window).x << " " << sf::Mouse::getPosition(window).y <<"\n";
	if (sf::Mouse::getPosition(window).x > currentSpr.getPosition().x &&
		sf::Mouse::getPosition(window).x < (currentSpr.getPosition().x + currentSpr.getTextureRect().width))
	{
		if (sf::Mouse::getPosition(window).y > currentSpr.getPosition().y &&
			sf::Mouse::getPosition(window).y < (currentSpr.getPosition().y + currentSpr.getTextureRect().height))
		{
			currentSpr.setTexture(hover);
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				setState(true);
			}
		/*	else if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				setState(false);					
			}*/
			else
			{
				if (current)
				{
					setState(false);
					if (onclick)
					{
						onclick();
					}
				}
			}
		}
		else
			currentSpr.setTexture(normal);
	}
	else
		currentSpr.setTexture(normal);
}
void Button::setState(bool state) {
	current = state;
	if (current) {
		currentSpr.setTexture(clicked);
		return;
	}
	currentSpr.setTexture(normal);
}

void Button::setText(std::string words) {
	text = words;
}

bool Button::getVar() {
	return current;
}

sf::Sprite Button::getSprite() {
	return currentSpr;
}

std::string Button::getText() {
	return text;
}