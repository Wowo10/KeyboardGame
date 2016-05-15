// Game State Manager HPP
#include <deque>
#include "Game_states.hpp"

class GameStateManager
{
public:
	GameStateManager();
	void ChangeState(GS_states state);
	void PushState(GS_states state);
	void PopState();
	void Clear();
	void Init();
	std::deque <GameState*> dq_states;
};