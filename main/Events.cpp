#include "Events.hpp"

sf::Clock Events::clock;

bool Events::exit;

int Events::screenheight;
int Events::screenwidth;

sf::Font Events::font;

//metody klasy statycznej
Events::Events(void)
{

}


Events::~Events(void)
{

}

void Events::Refresh()
{
	clock.restart();
}

void Events::Init()
{
	exit = false;

	srand(time(NULL));

	screenheight = 780;
	screenwidth = 1024;

	if (!font.loadFromFile("Fonts/Font.otf"))
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

int Events::CenterText(const sf::Text* text)
{
	return (Events::screenwidth - text->getLocalBounds().width) / 2;
}
