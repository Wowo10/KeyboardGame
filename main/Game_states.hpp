// Klasy GameStates
#ifndef GAME_STATE_HPP_INCLUDED
#define GAME_STATE_HPP_INCLUDED

#include "includes.hpp"

enum GS_states
{
	GS_NONE = 0,
	GS_MENU,
	GS_SINGLE,
	GS_MULTI,
	GS_PAUSE
};

enum Change_states
{
	NONE = 0,
	CHANGE,
	PUSH,
	POP,
};

class GameState
{
protected:
	std::vector<Button> buttons;
	int fontsize;
public:
	GS_states state;
	Change_states action;

	virtual void Exit() = 0;

	virtual void Update(const sf::RenderWindow &window)
	{
		for (int i = 0; i < buttons.size(); i++)
		{
			buttons[i].checkState(window);
		}
	}
	virtual void Render(sf::RenderWindow *window)
	{
		for (int i = 0; i < buttons.size(); i++)
		{
			window->draw(buttons[i].getSprite());
			sf::Text temp(buttons[i].getText(), Events::font, fontsize);

			temp.setPosition((buttons[i].getSprite().getTextureRect().width - temp.getLocalBounds().width) / 2
				+ buttons[i].getSprite().getPosition().x, (buttons[i].getSprite().getTextureRect().height - temp.getLocalBounds().height)
				/ 2 + buttons[i].getSprite().getPosition().y); //Spaghetti!

			window->draw(temp);
		}
	}
};

class GS_menu :public GameState
{
	sf::Texture keyboardtexture;
	sf::Sprite rightsprite;
	sf::Sprite leftsprite;
public:
	void Update(const sf::RenderWindow &window);
	void Render(sf::RenderWindow *window);

	sf::Time timer;

	void Exit();
	void GoSingle();
	void GoMulti();

	GS_menu();
	~GS_menu();
};

class GS_multi :public GameState
{
public:
	void Update(const sf::RenderWindow &window);
	void Render(sf::RenderWindow *window);

	sf::Time timer;

	void Exit();

	GS_multi();
	~GS_multi();
};

class GS_single :public GameState
{
private:
	enum Stage
	{
		READY = 0,
		WRITE,
		WAIT
	};

	Stage stage = READY;

	void LoadRandomWord();

	std::string active;
	std::string byuser = "";
public:
	void Update(const sf::RenderWindow &window);
	void Render(sf::RenderWindow *window);

	sf::Time timer;

	void Exit();

	GS_single();
	~GS_single();
};

class GS_pause :public GameState
{
public:
	void Update(const sf::RenderWindow &window);
	void Render(sf::RenderWindow *window);

	void Exit();

	GS_pause();
	~GS_pause();
};

#endif //GAME_STATE_HPP_INCLUDED