// GS_single
#include "Game_states.hpp"
#include "Game_state_manager.hpp"


GS_single::GS_single()
{

};

GS_single::~GS_single()
{

};

void GS_single::Update(sf::RenderWindow &window)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
	{
		action = POP;
		state = GS_states::GS_NONE;
	}
};

void GS_single::Render(sf::RenderWindow *window)
{
	window->clear(sf::Color::Magenta);
};
/*
void GS_single::Draw(int przesuniecie,int pozycja)
{

};
*/