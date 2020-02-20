#include "ZEGAR.h"

ZEGAR::ZEGAR()
{
}

void ZEGAR::czekaj(int ile_czasu)  // ilosc czasu w milisekundach
{
	sf::Clock tmp;
	tmp.restart();
	do
	{
	} while (tmp.getElapsedTime().asMicroseconds() < ile_czasu);
}

ZEGAR::~ZEGAR()
{
}
