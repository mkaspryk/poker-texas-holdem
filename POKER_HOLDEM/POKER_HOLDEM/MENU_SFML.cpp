#include "MENU_SFML.h"

MENU_SFML::MENU_SFML()
{
	this->panel_trudnosci = false;
	this->panel_wyboru_opcji = false;
	this->panel_statystyk = false;
	try
	{
		if (!TTlo.loadFromFile("images/MAINMENU.png"))
			exit(EXIT_FAILURE);
	}
	catch (std::exception&e)
	{
		std::cout << "Blad wczytania MAINMENU.png" << e.what() << "\n";
	}
	catch (...)
	{
		std::cout << "Nieznany blad\n";
	}
	STlo.setTexture(TTlo);
	try
	{
		if (!TContinue.loadFromFile("images/CONTINUE.png"))
			exit(EXIT_FAILURE);
	}
	catch (std::exception&e)
	{
		std::cout << "Blad wczytania CONTINUE.png" << e.what() << "\n";
	}
	catch (...)
	{
		std::cout << "Nieznany blad\n";
	}
	SContinue.setTexture(TContinue);
	SContinue.setPosition(200, 100);
	SContinue.setScale(0.4f, 0.3f);
	try
	{
		if (!TNewGame.loadFromFile("images/NEWGAME.png"))
			exit(EXIT_FAILURE);
	}
	catch (std::exception&e)
	{
		std::cout << "Blad wczytania NEWGAME.png" << e.what() << "\n";
	}
	catch (...)
	{
		std::cout << "Nieznany blad\n";
	}
	SNewGame.setTexture(TNewGame);
	SNewGame.setPosition(200, 350);
	SNewGame.setScale(0.4f, 0.3f);
	try
	{
		if (!TOptions.loadFromFile("images/OPTIONS.png"))
			exit(EXIT_FAILURE);
	}
	catch (std::exception&e)
	{
		std::cout << "Blad wczytania OPTIONS.png" << e.what() << "\n";
	}
	catch (...)
	{
		std::cout << "Nieznany blad\n";
	}
	SOptions.setTexture(TOptions);
	SOptions.setPosition(200, 600);
	SOptions.setScale(0.4f, 0.3f);
	try
	{
		if (!TExit.loadFromFile("images/EXIT.png"))
			exit(EXIT_FAILURE);
	}
	catch (std::exception&e)
	{
		std::cout << "Blad wczytania EXIT.png" << e.what() << "\n";
	}
	catch (...)
	{
		std::cout << "Nieznany blad\n";
	}
	SExit.setTexture(TExit);
	SExit.setPosition(200, 850);
	SExit.setScale(0.4f, 0.3f);
	try
	{
		if (!TDIFFICULTYLEVEL.loadFromFile("images/DIFFICULTYLEVEL.png"))
			exit(EXIT_FAILURE);
	}
	catch (std::exception&e)
	{
		std::cout << "Blad wczytania DIFFICULTYLEVEL.png" << e.what() << "\n";
	}
	catch (...)
	{
		std::cout << "Nieznany blad\n";
	}
	SDIFFICULTYLEVEL.setTexture(TDIFFICULTYLEVEL);
	SDIFFICULTYLEVEL.setPosition(700, 200);
	SDIFFICULTYLEVEL.setScale(0.4f, 0.3f);
	try
	{
		if (!TSTATISTICS.loadFromFile("images/STATISTICS.png"))
			exit(EXIT_FAILURE);
	}
	catch (std::exception&e)
	{
		std::cout << "Blad wczytania STATISTICS.png" << e.what() << "\n";
	}
	catch (...)
	{
		std::cout << "Nieznany blad\n";
	}
	SSTATISTICS.setTexture(TSTATISTICS);
	SSTATISTICS.setPosition(700, 700);
	SSTATISTICS.setScale(0.4f, 0.3f);
	try
	{
		if (!TEasy.loadFromFile("images/EASY.png"))
			exit(EXIT_FAILURE);
	}
	catch (std::exception&e)
	{
		std::cout << "Blad wczytania EASY.png" << e.what() << "\n";
	}
	catch (...)
	{
		std::cout << "Nieznany blad\n";
	}
	SEasy.setTexture(TEasy);
	SEasy.setPosition(1250, 200);
	SEasy.setScale(0.4f, 0.3f);
	try
	{
		if (!TMedium.loadFromFile("images/MEDIUM.png"))
			exit(EXIT_FAILURE);
	}
	catch (std::exception&e)
	{
		std::cout << "Blad wczytania MEDIUM.png" << e.what() << "\n";
	}
	catch (...)
	{
		std::cout << "Nieznany blad\n";
	}
	SMedium.setTexture(TMedium);
	SMedium.setPosition(1250, 450);
	SMedium.setScale(0.4f, 0.3f);
	try
	{
		if (!THard.loadFromFile("images/HARD.png"))
			exit(EXIT_FAILURE);
	}
	catch (std::exception&e)
	{
		std::cout << "Blad wczytania HARD.png" << e.what() << "\n";
	}
	catch (...)
	{
		std::cout << "Nieznany blad\n";
	}
	SHard.setTexture(THard);
	SHard.setPosition(1250, 700);
	SHard.setScale(0.4f, 0.3f);
	try
	{
		if (!Ffont1.loadFromFile("images/czcionki/Gimme_Danger.ttf"))
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
	TDifficultyLevel.setFont(Ffont1);
	TDifficultyLevel.setString("DIFFICULTY LEVEL");
	TDifficultyLevel.setCharacterSize(50);
	TDifficultyLevel.setFillColor(sf::Color::Red);
	TDifficultyLevel.setPosition(1100, 100);
	TStatistics.setFont(Ffont1);
	TStatistics.setString("STATISTICS");
	TStatistics.setCharacterSize(50);
	TStatistics.setFillColor(sf::Color::Red);
	TStatistics.setPosition(1200, 100);
	TKwota.setFont(Ffont1);
	TKwota.setCharacterSize(40);
	TKwota.setFillColor(sf::Color::Green);
	TKwota.setPosition(1500, 300);
	TYouWon.setFont(Ffont1);
	TYouWon.setString("YOU WON IN THE ROUND");
	TYouWon.setCharacterSize(40);
	TYouWon.setFillColor(sf::Color::Blue);
	TYouWon.setPosition(1090, 200);
}

void MENU_SFML::wypisz_menu(sf::RenderWindow &app)
{
	app.draw(STlo);
	app.draw(SNewGame);
	app.draw(SOptions);
	app.draw(SExit);
	app.draw(SContinue);
}

void MENU_SFML::rysowanie_wyboru(sf::RenderWindow &app)
{
	app.draw(SDIFFICULTYLEVEL);
	app.draw(SSTATISTICS);
}

void MENU_SFML::rysowanie_poziomu_trudnosci(sf::RenderWindow &app)
{
	app.draw(TDifficultyLevel);
	app.draw(SHard);
	app.draw(SMedium);
	app.draw(SEasy);
}

void MENU_SFML::rysowanie_statystyk(sf::RenderWindow &app,STATYSTYKA &STA,RUNDA &R)
{
	std::stringstream ss;
	int wartosc = STA.zwroc();
	ss << wartosc;
	std::string str = ss.str();
	TKwota.setString(str);
	app.draw(TStatistics);
	app.draw(TKwota);
	app.draw(TYouWon);
}

void MENU_SFML::wybor()
{
	if (this->panel_wyboru_opcji == false)
		this->panel_wyboru_opcji = true;
	else
		this->panel_wyboru_opcji = false;
}

void MENU_SFML::switch_poziom()
{
	if (this->panel_trudnosci == false)
		this->panel_trudnosci = true;
	else
		this->panel_trudnosci = false;
}

void MENU_SFML::switch_statystyka()
{
	if (this->panel_statystyk == false)
		this->panel_statystyk = true;
	else
		this->panel_statystyk = false;
}

bool MENU_SFML::a_panel_wyboru_opcji()
{
	return panel_wyboru_opcji;
}

bool MENU_SFML::a_panel_trudnosci()
{
	return panel_trudnosci;
}

bool MENU_SFML::a_panel_statystyk()
{
	return panel_statystyk;
}

MENU_SFML::~MENU_SFML()
{
}
