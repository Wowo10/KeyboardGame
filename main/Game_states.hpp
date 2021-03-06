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
	GS_LOBBY,
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

			std::cout << buttons[i].getText() << " ";

			temp.setPosition((buttons[i].getSprite().getTextureRect().width - temp.getLocalBounds().width) / 2
				+ buttons[i].getSprite().getPosition().x, (buttons[i].getSprite().getTextureRect().height - temp.getLocalBounds().height)
				/ 2 + buttons[i].getSprite().getPosition().y); //Spaghetti!

			std::cout << temp.getLocalBounds().width << " " << temp.getLocalBounds().height << " ";

			window->draw(temp);
		}
		std::cout << "\n";
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

	enum Typed
	{
		NOT = 0,
		GOOD,
		BAD
	};

	struct Letter
	{
		char sign;
		Typed type;

		sf::Color GetColor()
		{
			if (type == NOT)
			{
				return sf::Color::White;
			}
			else if (type == GOOD)
			{
				return sf::Color::Green;
			}
			else
			{
				return sf::Color::Red;
			}
		}

		Letter(char sign)
		{
			this->sign = sign;
			type = NOT;
		}

	};

	Stage stage = READY;

	void LoadRandomWord();

	std::vector<Letter> word;
	int index = 0;

	bool press = false;

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

class GS_lobby : public GameState
{
public:
	void Update(const sf::RenderWindow &window);
	void Render(sf::RenderWindow *window);

	void Exit();
	void Join();
	void Host();

	GS_lobby();
	~GS_lobby();
};

#endif //GAME_STATE_HPP_INCLUDED