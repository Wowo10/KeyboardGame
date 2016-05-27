// klasa GS_MENU
#include "Game_states.hpp"

GS_menu::GS_menu()
{
	fontsize = 23;

	buttons.push_back(Button("Buttons/Button.png", "Buttons/Button_hover.png", "/Buttons/Button_clicked.png", "Single Player", Aligment::CENTER, sf::Vector2f(0, 300)));
	buttons.back().Init();
	buttons.back().onclick = std::bind(&GS_menu::GoSingle, this);

	buttons.push_back(Button("Buttons/Button.png", "Buttons/Button_hover.png", "/Buttons/Button_clicked.png", "Multi Player", Aligment::CENTER, sf::Vector2f(0, 450)));
	buttons.back().Init();
	buttons.back().onclick = std::bind(&GS_menu::GoMulti, this);

	buttons.push_back(Button("Buttons/Button.png", "Buttons/Button_hover.png", "/Buttons/Button_clicked.png", "Exit", Aligment::CENTER, sf::Vector2f(0, 600)));
	buttons.back().Init();
	buttons.back().onclick = std::bind(&GS_menu::Exit, this);

	keyboardtexture = Events::LoadTexture("Images/keyboard.png");
	rightsprite.setTexture(keyboardtexture);
	leftsprite.setTexture(keyboardtexture);
	leftsprite.setScale(0.8, 0.8);

	leftsprite.setColor(sf::Color(255, 255, 255, 120));
	rightsprite.setColor(sf::Color(255, 255, 255, 180));

	rightsprite.setPosition(800, 300 + rand() % 300);
	leftsprite.setPosition(-300, -50 + rand() % 300);

	timer = Events::clock.getElapsedTime();
}

GS_menu::~GS_menu()
{

}

//Button Callbacks
void GS_menu::Exit()
{
	Events::exit = true;
}

void GS_menu::GoSingle()
{
	action = PUSH;
	state = GS_SINGLE;
}

void GS_menu::GoMulti()
{
	action = PUSH;
	state = GS_LOBBY;
}

//Functions
void GS_menu::Update(const sf::RenderWindow &window)
{
	GameState::Update(window);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		Exit();
	}

}

void GS_menu::Render(sf::RenderWindow *window)
{
	window->clear(sf::Color(0, 155, 255)); //Background: 009bff 
	GameState::Render(window);

	sf::Text title("Keyboard Game", Events::font, 60);

	timer = Events::clock.getElapsedTime();
	rightsprite.setPosition(rightsprite.getPosition() - sf::Vector2f(0, timer.asSeconds() * 14));
	window->draw(rightsprite);

	leftsprite.setPosition(leftsprite.getPosition() + sf::Vector2f(0, timer.asSeconds() * 10));
	window->draw(leftsprite);

	title.setPosition(Events::CenterText(&title), 100);
	window->draw(title);
}
