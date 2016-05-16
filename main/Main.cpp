#include "Includes.hpp"
#include "Game_states.hpp"
#include "Game_state_manager.hpp"

int main()
{
	Events::Init();

	sf::RenderWindow window(sf::VideoMode(Events::screenwidth, Events::screenheight), "GameTryout");
	
	GameStateManager StateManager;
	StateManager.Init();

	while (window.isOpen() && !Events::exit)
	{
		if (StateManager.dq_states.back()->action == CHANGE)
		{
			StateManager.ChangeState(StateManager.dq_states.back()->state);
		}
		else if (StateManager.dq_states.back()->action == POP)
		{
			StateManager.PopState();
		}
		else if (StateManager.dq_states.back()->action == PUSH)
		{
			StateManager.PushState(StateManager.dq_states.back()->state);
		}

		StateManager.dq_states.back()->Update(window);

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				Events::exit = true;
				window.close();
			}
		}

		StateManager.dq_states.back()->Render(&window);

		Events::Refresh();

		window.display();
	} 

	return 0;
};