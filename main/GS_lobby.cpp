//klasa GS_LOBBY
#include "Game_states.hpp"

GS_lobby::GS_lobby()
{
	fontsize = 23;
	
	buttons.push_back(Button("Buttons/Cross.png", "Buttons/Cross_hover.png", "Buttons/Cross_clicked.png", "", NOWHERE, sf::Vector2f(944, 10)));
	buttons.back().Init();
	buttons.back().onclick = std::bind(&GS_lobby::Exit, this);

	buttons.push_back(Button("Buttons/Button.png", "Buttons/Button_hover.png", "/Buttons/Button_clicked.png", "Host", Aligment::NOWHERE, sf::Vector2f(150, 500)));
	buttons.back().Init();
	buttons.back().onclick = std::bind(&GS_lobby::Host, this);

	buttons.push_back(Button("Buttons/Button.png", "Buttons/Button_hover.png", "/Buttons/Button_clicked.png", "Join", Aligment::NOWHERE, sf::Vector2f(550, 500)));
	buttons.back().Init();
	buttons.back().onclick = std::bind(&GS_lobby::Join, this);
}

GS_lobby::~GS_lobby()
{

}

//CallBacks
void GS_lobby::Exit()
{
	action = POP;
	state = GS_NONE;
}

void GS_lobby::Join()
{

}

void GS_lobby::Host()
{

}

void GS_lobby::Update(const sf::RenderWindow &window)
{
	GameState::Update(window);

}

void GS_lobby::Render(sf::RenderWindow *window)
{
	window->clear(sf::Color(0, 155, 255)); //Background: 009bff 
	GameState::Render(window);

}
