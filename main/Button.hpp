#ifndef BUTTON_HPP_INCLUDED
#define BUTTON_HPP_INCLUDED
#include "includes.hpp"

enum Aligment
{
	NOWHERE = 0,
	CENTER,
	LEFT,
	RIGHT
};

class Button {
public:
	Button(std::string normal, std::string hover, std::string clicked, sf::String text, Aligment aligment, sf::Vector2f position = sf::Vector2f(0, 0));
	void checkState(const sf::RenderWindow &window);
	void setState(bool);
	void setText(std::string words);
	bool getVar();
	sf::Sprite getSprite();
	std::string getText();
	std::function<void()> onclick;

	void Init(); //Crap
private:
	sf::Texture normal;
	sf::Texture clicked;
	sf::Texture hover;
	sf::Sprite currentSpr;
	sf::String text;
	bool current;
};

#endif //BUTTON_HPP_INCLUDED