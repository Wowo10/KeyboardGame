#include "Events.hpp"

sf::Clock Events::clock;

ConnectionType Events::connection;

bool Events::exit;

int Events::screenheight;
int Events::screenwidth;

sf::Font Events::font;

sf::IpAddress Events::ip;
sf::TcpSocket Events::socket;

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

	connection = NOCONNECTION;

	screenheight = 780;
	screenwidth = 1024;

	if (!font.loadFromFile("Fonts/Font.otf"))
	{
		std::cout << "No Such Font!\n";
	}

	//Network
	ip = sf::IpAddress::getLocalAddress();
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

std::string Events::TimeText(int miliseconds)
{
	std::string temp = std::to_string(miliseconds / 1000);
	temp += ':';
	temp += std::to_string((miliseconds % 1000) / 100);
	return temp;
}

int Events::CenterText(const sf::Text* text)
{
	return (Events::screenwidth - text->getLocalBounds().width) / 2;
}

char Events::GetKeyPressed()
{
	for (int i = 0; i < 25; i++ )
	{
		sf::Keyboard::Key key = static_cast<sf::Keyboard::Key>(i);
		if (sf::Keyboard::isKeyPressed(key))
		{
			std::cout << (char)65 + i<< "\n";
			return 65 + i;
		}
	}
	return 0;
}