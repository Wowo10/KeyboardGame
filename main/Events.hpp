#ifndef EVENTS_HPP_INCLUDED
#define EVENTS_HPP_INCLUDED
#include "includes.hpp"

enum ConnectionType
{
	NOCONNECTION = 0,
	CLIENT,
	SERVER
};

class Events
{
public:
	Events();
	~Events();

	static sf::Clock clock;

	static ConnectionType connection;

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

	//Network part
	static sf::IpAddress ip;
	static sf::TcpSocket socket;
};

#endif //EVENTS_HPP_INCLUDED