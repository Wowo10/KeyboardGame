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

	static sf::Font menufont;

	static void Refresh();
	static void Init();

	static sf::Texture LoadTexture(std::string path);
	
};

#endif //EVENTS_HPP_INCLUDED