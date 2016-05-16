// GS_single
#include "Game_states.hpp"
#include "Game_state_manager.hpp"


GS_single::GS_single()
{
	timer = sf::Time::Zero;

	buttons.push_back(Button("Buttons/Cross.png", "Buttons/Cross_hover.png", "Buttons/Cross_clicked.png", "", NOWHERE, sf::Vector2f(944, 10)));
	buttons.back().Init();
	buttons.back().onclick = std::bind(&GS_single::Exit, this);
};

GS_single::~GS_single()
{

};

//Button Callbacks
void GS_single::Exit()
{
	action = POP;
	state = GS_NONE;
}

void GS_single::Update(const sf::RenderWindow &window)
{
	GameState::Update(window);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	{
		Exit();
	}
	
	if (stage == WRITE)
	{
		//Get Pressed Keys

		//Check end then push WAIT
	}
	else //for both Ready and Wait
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
		{
			stage = WRITE;
		}
	}
};

void GS_single::Render(sf::RenderWindow *window)
{
	window->clear(sf::Color(0, 155, 255)); //Background: 009bff 
	GameState::Render(window);

	if (stage == READY)
	{
		sf::Text instruction("Press Enter when ready",Events::font,30);
		instruction.setPosition(Events::CenterText(&instruction),100);

		window->draw(instruction);
	}
};