#include "MYSZKA.h"

MYSZKA::MYSZKA()
{
}

void MYSZKA::ustaw_strefe(int ktora_strefa, int _x0, int _x1, int _y0, int _y1)
{
	strefa[ktora_strefa].x0 = _x0;
	strefa[ktora_strefa].x1 = _x1;
	strefa[ktora_strefa].y0 = _y0;
	strefa[ktora_strefa].y1 = _y1;
	strefa[ktora_strefa].aktywna = true;
}

void MYSZKA::rysuj(sf::RenderWindow &app, sf::Vector2f pozycja_myszki)
{
	try
	{
		if (!czcionka.loadFromFile("images/czcionki/poker_font.otf"))
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
	std::stringstream ss;
	ss << pozycja_myszki.x;
	std::string str = ss.str();
	napis1.setFont(czcionka);
	napis1.setString(str);
	napis1.setCharacterSize(70);
	napis1.setFillColor(sf::Color::Blue);
	napis1.setPosition(500, 450);
	app.draw(napis1);
	std::stringstream ss2;
	ss2 << pozycja_myszki.y;
	std::string str2 = ss2.str();
	napis2.setFont(czcionka);
	napis2.setString(str2);
	napis2.setCharacterSize(70);
	napis2.setFillColor(sf::Color::Blue);
	napis2.setPosition(700, 450);
	app.draw(napis2);
}

int MYSZKA::sprawdz_strefe(sf::RenderWindow &app)
{
	sf::Vector2f pozycja_myszki;
	pozycja_myszki = sf::Vector2f(sf::Mouse::getPosition(app).x, sf::Mouse::getPosition(app).y);
	//rysuj(app,pozycja_myszki);
	for (int i = 0; i < 20; i++)
	{
		if (pozycja_myszki.x > strefa[i].x0&&pozycja_myszki.x<strefa[i].x1 && pozycja_myszki.y > strefa[i].y0 && pozycja_myszki.y < strefa[i].y1&&sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			return i;
		}
	}
	return -1;
}

MYSZKA::~MYSZKA()
{
}
