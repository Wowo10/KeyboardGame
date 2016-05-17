#ifndef EVENTS_HPP_INCLUDED
#define EVENTS_HPP_INCLUDED
#include "includes.hpp"

class Events
{
public:
	Events();
	~Events();

	static sf::Clock clock;

	static bool exit;

	static int screenheight;
	static int screenwidth;

	static sf::Font font;

	static void Refresh();
	static void Init();

	static sf::Texture LoadTexture(std::string path);

	static std::string TimeText(int miliseconds);

	static char GetKeyPressed();
	
	static int CenterText(const sf::Text* text);
};

#endif //EVENTS_HPP_INCLUDED