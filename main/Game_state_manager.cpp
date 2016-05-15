// Game State Manager CPP

#include "Game_state_manager.hpp"
#include "Game_states.hpp"

GameStateManager::GameStateManager()
{

}

void GameStateManager::Clear()
{
	dq_states.clear();
}

void GameStateManager::ChangeState(GS_states state)
{
	GameState* HelpState;

	if (!dq_states.empty())
		dq_states.pop_back();

	switch (state)
	{
	case GS_MENU:
		HelpState = new GS_menu;
		break;

	case GS_MULTI:
		HelpState = new GS_multi;
		break;

	case GS_SINGLE:
		HelpState = new GS_single;
		break;

	case GS_PAUSE:
		HelpState = new GS_pause;
		break;

	default: HelpState = new GS_menu;
	}

	dq_states.push_back(HelpState);
}


void GameStateManager::PushState(GS_states state)
{
	GameState* HelpState;

	switch (state)
	{
	case GS_MENU:
		HelpState = new GS_menu;
		break;

	case GS_MULTI:
		HelpState = new GS_multi;
		break;

	case GS_SINGLE:
		HelpState = new GS_single;
		break;

	case GS_PAUSE:
		HelpState = new GS_pause;
		break;

	default: HelpState = new GS_menu;
	}

	dq_states.push_back(HelpState);
}

void GameStateManager::PopState()
{
	if (!dq_states.empty())
		dq_states.pop_back();

	dq_states.back()->action = NONE;
	dq_states.back()->state = GS_NONE;
}

void GameStateManager::Init()
{
	PushState(GS_MENU);
}