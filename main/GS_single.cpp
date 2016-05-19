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

void GS_single::LoadRandomWord()
{
	word.clear();
	
	std::fstream file;
	file.open("Fonts/Words.txt", std::ios::in);

	if (!file.is_open())
	{
		std::cout << "no Words file!\n";
	}

	std::string text;
	for (int i = 0; i < rand()%4+1; i++)
	{
		std::getline(file,text);
	}

	for (int i = 0; i < text.length(); i++)
	{
		word.push_back(text[i]);
	}
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
		char key = Events::GetKeyPressed();
		if (!press)
		{
			if (word[index].sign == key)
			{
				word[index++].type = GOOD;
				press = true;
			}
			else if (key != 0)
			{
				press = true;
				word[index++].type = BAD;
			}
		}
		else if(key == 0)
		{
			press = false;
		}

		if (index == word.size())
		{
			stage = WAIT;
			index = 0;
		}		
	}
	else //for both Ready and Wait
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
		{
			stage = WRITE;
			LoadRandomWord();

			Events::clock.restart();
			timer = Events::clock.getElapsedTime();
		}
	}
};

void GS_single::Render(sf::RenderWindow *window)
{
	window->clear(sf::Color(0, 155, 255)); //Background: 009bff 
	GameState::Render(window);

	sf::Text elapsed(Events::TimeText(timer.asMilliseconds()), Events::font, 30);
	elapsed.setPosition(700, 200);

	window->draw(elapsed);

	if (stage == READY)
	{
		sf::Text instruction("Press Enter when ready", Events::font, 30);
		instruction.setPosition(Events::CenterText(&instruction), 100);

		window->draw(instruction);
	}
	else if (stage == WRITE)
	{
		sf::Text instruction("Write ASAP!", Events::font, 30);
		instruction.setPosition(Events::CenterText(&instruction), 100);

		window->draw(instruction);

		timer += Events::clock.getElapsedTime();

		int amount = (Events::screenwidth - word.size() * 24) / 2; //24 - hardcoded width of letter

		for (int i = 0; i < word.size(); i++)
		{
			sf::Text temp(word[i].sign, Events::font, 26);
			temp.setColor(word[i].GetColor());
			temp.setPosition(amount, 400);
			amount += temp.getLocalBounds().width + 5;
			window->draw(temp);
		}
	}
	else
	{
		sf::Text instruction("Press Enter for next challenge", Events::font, 30);
		instruction.setPosition(Events::CenterText(&instruction), 100);

		window->draw(instruction);
	}
};