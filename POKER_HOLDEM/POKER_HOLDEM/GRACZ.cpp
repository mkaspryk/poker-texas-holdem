#include "GRACZ.h"

GRACZ::GRACZ()
{
	this->gra = false;
	try
	{
		if (!TDealer.loadFromFile("images/DEALER.png"))
			exit(EXIT_FAILURE);
	}
	catch (std::exception&e)
	{
		std::cout << "Blad wczytania DEALER.png" << e.what() << "\n";
	}
	catch (...)
	{
		std::cout << "Nieznany blad\n";
	}
	// ustawianie dealera dla gracza PLAYER
	SDealer1.setTexture(TDealer);
	SDealer1.setPosition(850, 600);
	SDealer1.setScale(0.04f, 0.04f);
	// ustawianie dealera dla gracza COMPUTER
	SDealer2.setTexture(TDealer);
	SDealer2.setPosition(850, 270);
	SDealer2.setScale(0.04f, 0.04f);
	// kwota dla danego gracza
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
	TCashName.setFont(Ffont1);
	TCashName.setCharacterSize(50);
	TCashName.setFillColor(sf::Color::White);
	try
	{
		if (!Ffont2.loadFromFile("images/czcionki/Gimme_Danger.ttf"))
			exit(EXIT_FAILURE);
	}
	catch (std::exception&e)
	{
		std::cout << "Blad wczytania Gimme_Danger.ttf" << e.what() << "\n";
	}
	catch (...)
	{
		std::cout << "Nieznany blad\n";
	}
	TWinName.setFont(Ffont2);
	TWinName.setString("WIN");
	TWinName.setCharacterSize(50);
	TWinName.setFillColor(sf::Color::Green);
	TWinName.setPosition(1180, 200);
	TLossName.setFont(Ffont2);
	TLossName.setString("LOSS");
	TLossName.setCharacterSize(50);
	TLossName.setFillColor(sf::Color::Red);
	TLossName.setPosition(1180, 200);
	TDrawName.setFont(Ffont2);
	TDrawName.setString("DRAW");
	TDrawName.setCharacterSize(50);
	TDrawName.setFillColor(sf::Color::Yellow);
	TDrawName.setPosition(1180, 200);
}

void GRACZ::dodaj_kwote(int ile)
{
	this->kwota += ile;
}

void GRACZ::poczatek(int numer1, int kwota1, bool dealer1)
{
	this->gra = true;
	this->numer = numer1;
	this->kwota = kwota1;
	this->dealer = dealer1;
}

void GRACZ::podanie()
{
	this->gra = false;
}

void GRACZ::rysuj_dealer(sf::RenderWindow &app, int i)
{
	if (i == 1)
		app.draw(SDealer1);
	else
		app.draw(SDealer2);
}

void GRACZ::zmien_dealera()
{
	if (this->dealer)
		this->dealer = false;
	else
		this->dealer = true;
}

void GRACZ::rysuj_kwote(sf::RenderWindow &app)
{
	app.draw(TCashName);
}

void GRACZ::rysuj_wygrana(sf::RenderWindow &app)
{
	app.draw(TWinName);
}

void GRACZ::rysuj_przegrana(sf::RenderWindow &app)
{
	app.draw(TLossName);
}

void GRACZ::rysuj_remis(sf::RenderWindow &app)
{
	app.draw(TDrawName);
}

void GRACZ::pobierz(int ILE)
{
	this->kwota = this->kwota - ILE;
}

void GRACZ::uaktualnij_kwote()
{
	std::stringstream ss;
	ss << this->kwota;
	std::string str = ss.str();
	TCashName.setString(str);
	if (this->numer == 2)
		TCashName.setPosition(75, 90);
	else
		TCashName.setPosition(75, 970);
}

GRACZ::~GRACZ()
{
}
