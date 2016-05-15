// klasa GS_MENU
#include "Game_states.hpp"

GS_menu::GS_menu()
{
	fontsize = 23;

	buttons.push_back(Button("Buttons/Button.png", "Buttons/Button_hover.png", "/Buttons/Button_clicked.png", "Single Player", Aligment::CENTER, sf::Vector2f(0, 300)));
	buttons.back().Init();
	//buttons.back().onclick = std::bind(&GS_menu::GoSinglePlayer, this);

	buttons.push_back(Button("Buttons/Button.png", "Buttons/Button_hover.png", "/Buttons/Button_clicked.png", "Multi Player", Aligment::CENTER, sf::Vector2f(0, 450)));
	buttons.back().Init();

	buttons.push_back(Button("Buttons/Button.png", "Buttons/Button_hover.png", "/Buttons/Button_clicked.png", "Exit", Aligment::CENTER, sf::Vector2f(0, 600)));
	buttons.back().Init();
	buttons.back().onclick = std::bind(&GS_menu::Exit, this);
}

GS_menu::~GS_menu()
{

}

void GS_menu::Exit()
{
	Events::exit = true;
}

void GS_menu::Update(sf::RenderWindow &window)
{
	GameState::Update(window);

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		action = PUSH;
		state = GS_SINGLE;
	}
}

void GS_menu::Render(sf::RenderWindow *window)
{
	window->clear(sf::Color(0,155,255)); //Background: 009bff 
	GameState::Render(window);

	sf::Text title("Keyboard Game", Events::menufont, 60);

	title.setPosition((Events::screenwidth - title.getLocalBounds().width) / 2, 100);
	window->draw(title);
}
