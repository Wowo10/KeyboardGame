#include "Events.hpp"

sf::Clock Events::clock;

bool Events::exit;

int Events::screenheight;
int Events::screenwidth;

sf::Font Events::menufont;

//metody klasy statycznej
Events::Events(void)
{

}


Events::~Events(void)
{

}

void Events::Refresh()
{

}

void Events::Init()
{
	exit = false;

	screenheight = 780;
	screenwidth = 1024;

	if (!menufont.loadFromFile("Fonts/Font.otf"))
	{
		std::cout << "No Such Font!\n";
	}
}

sf::Texture Events::LoadTexture(std::string path)
{
	sf::Texture temp;
	if (!temp.loadFromFile(path))
	{
		std::cout << "Texture Path error!\n" + path + "\n";
	}

	return temp;
}

