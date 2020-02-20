#include "GRA_SFML.h"

GRA_SFML::GRA_SFML()
{
	// ile w puli
	ile_w_puli = 0;
	ile_dodane_player = 0;
	ile_dodane_ai = 0;
	try
	{
		if (!TStol.loadFromFile("images/POKER_TABLE.png"))
			exit(EXIT_FAILURE);
	}
	catch (std::exception&e)
	{
		std::cout << "Blad wczytania POKER_TABLE.png" << e.what() << "\n";
	}
	catch (...)
	{
		std::cout << "Nieznany blad\n";
	}
	SStol.setTexture(TStol);
	// karty przeciwnika
	try
	{
		if (!THide.loadFromFile("images/karty/hide.png"))
			exit(EXIT_FAILURE);
	}
	catch (std::exception&e)
	{
		std::cout << "Blad wczytania hide.png" << e.what() << "\n";
	}
	catch (...)
	{
		std::cout << "Nieznany blad\n";
	}
	SHide1.setTexture(THide);
	SHide1.setPosition(850, 100);
	SHide1.setScale(0.16f, 0.16f);
	SHide2.setTexture(THide);
	SHide2.setPosition(1000, 100);
	SHide2.setScale(0.16f, 0.16f);
	// RUCH
	try
	{
		if (!TFold.loadFromFile("images/FOLD.png"))
			exit(EXIT_FAILURE);
	}
	catch (std::exception&e)
	{
		std::cout << "Blad wczytania FOLD.png" << e.what() << "\n";
	}
	catch (...)
	{
		std::cout << "Nieznany blad\n";
	}
	SFold.setTexture(TFold);
	SFold.setPosition(1600, 450);
	SFold.setScale(0.2f, 0.2f);
	try
	{
		if (!TCheck.loadFromFile("images/CHECK.png"))
			exit(EXIT_FAILURE);
	}
	catch (std::exception&e)
	{
		std::cout << "Blad wczytania CHECK.png" << e.what() << "\n";
	}
	catch (...)
	{
		std::cout << "Nieznany blad\n";
	}
	SCheck.setTexture(TCheck);
	SCheck.setPosition(1600, 900);
	SCheck.setScale(0.2f, 0.2f);
	try
	{
		if (!TCall.loadFromFile("images/CALL.png"))
			exit(EXIT_FAILURE);
	}
	catch (std::exception&e)
	{
		std::cout << "Blad wczytania CALL.png" << e.what() << "\n";
	}
	catch (...)
	{
		std::cout << "Nieznany blad\n";
	}
	SCall.setTexture(TCall);
	SCall.setPosition(1600, 750);
	SCall.setScale(0.2f, 0.2f);
	try
	{
		if (!TRaise.loadFromFile("images/RAISE.png"))
			exit(EXIT_FAILURE);
	}
	catch (std::exception&e)
	{
		std::cout << "Blad wczytania RAISE.pn" << e.what() << "\n";
	}
	catch (...)
	{
		std::cout << "Nieznany blad\n";
	}
	SRaise.setTexture(TRaise);
	SRaise.setPosition(1600, 600);
	SRaise.setScale(0.2f, 0.2f);
	// menu
	try
	{
		if (!TMenu.loadFromFile("images/MENU.png"))
			exit(EXIT_FAILURE);
	}
	catch (std::exception&e)
	{
		std::cout << "Blad wczytania RAISE.pn" << e.what() << "\n";
	}
	catch (...)
	{
		std::cout << "Nieznany blad\n";
	}
	SMenu.setTexture(TMenu);
	SMenu.setPosition(1700, 0);
	SMenu.setScale(0.2f, 0.2f);
	// PLAYER wypisanie nazwy gracza
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
	TPlayerName.setFont(Ffont1);
	TPlayerName.setString("PLAYER");
	TPlayerName.setCharacterSize(50);
	TPlayerName.setFillColor(sf::Color::Black);
	TPlayerName.setPosition(30, 900);
	// COMPUTER wypisanie nazwy AI
	TAiName.setFont(Ffont1);
	TAiName.setString("AI");
	TAiName.setCharacterSize(50);
	TAiName.setFillColor(sf::Color::Black);
	TAiName.setPosition(110, 20);
	// pula
	std::stringstream ss;
	ss << ile_w_puli;
	std::string str = ss.str();
	// ustawianie puli
	TPot.setFont(Ffont1);
	TPot.setString(str);
	TPot.setCharacterSize(70);
	TPot.setFillColor(sf::Color::Blue);
	TPot.setPosition(330, 650);
	// wypisanie puli 'nazwa'
	TPotName.setFont(Ffont1);
	TPotName.setString("POT");
	TPotName.setCharacterSize(70);
	TPotName.setFillColor(sf::Color::Black);
	TPotName.setPosition(330, 570);
	try
	{
		if (!Ffont2.loadFromFile("images/czcionki/Championship.ttf"))
			exit(EXIT_FAILURE);
	}
	catch (std::exception&e)
	{
		std::cout << "Blad wczytania Championship.ttf" << e.what() << "\n";
	}
	catch (...)
	{
		std::cout << "Nieznany blad\n";
	}
	TPokerName.setFont(Ffont2);
	TPokerName.setString("MK POKER TEXAS HOLDEM");
	TPokerName.setCharacterSize(100);
	TPokerName.setFillColor(sf::Color::Red);
	TPokerName.setPosition(430, 320);
	try
	{
		if (!TOk.loadFromFile("images/OK.png"))
			exit(EXIT_FAILURE);
	}
	catch (std::exception&e)
	{
		std::cout << "Blad wczytania OK.png" << e.what() << "\n";
	}
	catch (...)
	{
		std::cout << "Nieznany blad\n";
	}
	SOk.setTexture(TOk);
	SOk.setPosition(1200, 620);
	SOk.setScale(0.2f, 0.2f);
	try
	{
		if (!TWinner.loadFromFile("images/WINNER.png"))
			exit(EXIT_FAILURE);
	}
	catch (std::exception&e)
	{
		std::cout << "Blad wczytania WINNER.png" << e.what() << "\n";
	}
	catch (...)
	{
		std::cout << "Nieznany blad\n";
	}
	SWinner.setTexture(TWinner);
	SWinner.setPosition(440, 220);
	SWinner.setScale(1, 1);
	try
	{
		if (!TGameOver.loadFromFile("images/GAMEOVER.png"))
			exit(EXIT_FAILURE);
	}
	catch (std::exception&e)
	{
		std::cout << "Blad wczytania GAMEOVER.png" << e.what() << "\n";
	}
	catch (...)
	{
		std::cout << "Nieznany blad\n";
	}
	SGameOver.setTexture(TGameOver);
	SGameOver.setPosition(440, 220);
	SGameOver.setScale(1, 1);
}

void GRA_SFML::rysuj_karty_ukryte(sf::RenderWindow &app)
{
	app.draw(SHide1);
	app.draw(SHide2);
}

void GRA_SFML::dodaj_do_puli(int ile)
{
	this->ile_w_puli += ile;
}

void GRA_SFML::dodaj_player(int ile)
{
	this->ile_dodane_player += ile;
}

void GRA_SFML::dodaj_ai(int ile)
{
	this->ile_dodane_ai += ile;
}

int GRA_SFML::a_ile_w_puli()
{
	return this->ile_w_puli;
}

int GRA_SFML::a_ile_dodane_player()
{
	return ile_dodane_player;
}

int GRA_SFML::a_ile_dodane_ai()
{
	return ile_dodane_ai;
}

void GRA_SFML::zeruj_pule()
{
	this->ile_w_puli = 0;
	ile_dodane_player = 0;
	ile_dodane_ai = 0;
}

void GRA_SFML::rysuj_plansze(sf::RenderWindow &app, int i)
{
	std::stringstream ss, ss1, ss2;
	std::string str, str1, str2;
	if (i >= 0)
	{
		ss << ile_w_puli;
		str = ss.str();
		TPot.setFont(Ffont1);
		TPot.setString(str);
		TPot.setCharacterSize(70);
		TPot.setFillColor(sf::Color::Blue);
		TPot.setPosition(330, 650);
	}
	ss1 << ile_dodane_player;
	str1 = ss1.str();
	TPlayerAdd.setFont(Ffont1);
	TPlayerAdd.setString(str1);
	TPlayerAdd.setCharacterSize(60);
	TPlayerAdd.setFillColor(sf::Color::Yellow);
	TPlayerAdd.setPosition(100, 800);
	ss2 << ile_dodane_ai;
	str2 = ss2.str();
	TAiAdd.setFont(Ffont1);
	TAiAdd.setString(str2);
	TAiAdd.setCharacterSize(60);
	TAiAdd.setFillColor(sf::Color::Yellow);
	TAiAdd.setPosition(100, 180);
	app.draw(SStol);
	app.draw(TPokerName);
	app.draw(SMenu);
	app.draw(SCheck);
	app.draw(SFold);
	app.draw(SCall);
	app.draw(SRaise);
	app.draw(TPlayerName);
	app.draw(TAiName);
	app.draw(TPot);
	app.draw(TPotName);
	app.draw(TPlayerAdd);
	app.draw(TAiAdd);
}

void GRA_SFML::rysuj_ok(sf::RenderWindow &app)
{
	app.draw(SOk);
}

void GRA_SFML::rysuj_koniec(sf::RenderWindow &app, MYSZKA &myszka, bool koniec, int &kliknieta_strefa)
{
	while (true)
	{
		app.clear();
		kliknieta_strefa = myszka.sprawdz_strefe(app);
		if (koniec == true)
			app.draw(SWinner);
		else
			app.draw(SGameOver);
		if (kliknieta_strefa == 15)
		{
			kliknieta_strefa = 4;
			break;
		}
		app.display();
	}
}

GRA_SFML::~GRA_SFML()
{
}
