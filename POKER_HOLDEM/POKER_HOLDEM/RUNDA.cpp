#include "RUNDA.h"

RUNDA::RUNDA()
{
	ktoraRunda = 1;
	try
	{
		if (!Ffont1.loadFromFile("images/czcionki/poker_font.otf"))
			exit(EXIT_FAILURE);
	}
	catch (std::exception&e)
	{
		std::cout << "Blad wczytania poker_font.otf" << e.what() << "\n";
	}
	catch (...)
	{
		std::cout << "Nieznany blad\n";
	}
	TRoundName.setFont(Ffont1);
	TRoundName.setString("ROUND");
	TRoundName.setCharacterSize(50);
	TRoundName.setFillColor(sf::Color::Black);
	TRoundName.setPosition(1360, 20);
	TNumberOfRound.setFont(Ffont1);
	TNumberOfRound.setCharacterSize(50);
	TNumberOfRound.setFillColor(sf::Color::White);
	TNumberOfRound.setPosition(1590, 20);
}

void RUNDA::zwieksz_runde()
{
	this->ktoraRunda++;
}

int RUNDA::a_ktoraRunda()
{
	return ktoraRunda;
}

void RUNDA::zeruj_runde()
{
	this->ktoraRunda = 1;
}

void RUNDA::rysuj_runde(sf::RenderWindow &app)
{
	std::stringstream ss;
	ss << this->ktoraRunda;
	std::string str = ss.str();
	TNumberOfRound.setString(str);
	app.draw(TRoundName);
	app.draw(TNumberOfRound);
}

RUNDA::~RUNDA()
{
}
