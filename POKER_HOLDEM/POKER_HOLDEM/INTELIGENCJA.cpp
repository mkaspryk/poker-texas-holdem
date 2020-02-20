#include "INTELIGENCJA.h"

INTELIGENCJA::INTELIGENCJA()
{
	try
	{
		if(!Ffont1.loadFromFile("images/czcionki/poker_font.otf"))
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
	TFold.setFont(Ffont1);
	TFold.setString("FOLD");
	TFold.setCharacterSize(70);
	TFold.setFillColor(sf::Color::Red);
	TFold.setPosition(360, 60);
	this->agresywnosc = 0;
	this->pas = false;
}

void INTELIGENCJA::koniec_pas()
{
	this->pas = false;
}

bool INTELIGENCJA::a_pas()
{
	return pas;
}

void INTELIGENCJA::rysuj_pas(sf::RenderWindow &app)
{
	app.draw(TFold);
}

void INTELIGENCJA::change_difficulty(int level)
{
	agresywnosc = level;
}

int INTELIGENCJA::losowanie()
{
	srand(time(NULL));
	return rand() % 1000;
}

void INTELIGENCJA::raise(GRACZ &PLAYER, GRACZ &AI, GRA_SFML &GRA, STAWKI &S, int roznica)
{
	int podbicie = 2 * S.a_big_blind();
	if (podbicie > roznica&&podbicie < AI.a_kwota())
	{
		AI.pobierz(podbicie);
		GRA.dodaj_ai(podbicie);
		GRA.dodaj_do_puli(podbicie);
	}
	else
	{
		AI.pobierz(roznica);
		GRA.dodaj_ai(roznica);
		GRA.dodaj_do_puli(roznica);
	}
}

void INTELIGENCJA::call(GRACZ &PLAYER, GRACZ &AI, GRA_SFML &GRA, int roznica)
{
	GRA.dodaj_ai(roznica);
	GRA.dodaj_do_puli(roznica);
	AI.pobierz(roznica);
}

void INTELIGENCJA::check()
{
}

void INTELIGENCJA::fold(GRACZ &PLAYER, GRACZ &AI, GRA_SFML &GRA, TURA &T,RUNDA &R,SEMAFORY &SEM,STAWKI &S,STATYSTYKA &STA)
{
	PLAYER.dodaj_kwote(GRA.a_ile_w_puli());
	STA.push_back(GRA.a_ile_w_puli());
	GRA.zeruj_pule();
	PLAYER.zmien_dealera();
	AI.zmien_dealera();
	if (R.a_ktoraRunda() % 4 == 0)
		S.zwiekszanie();
	R.zwieksz_runde();
	SEM.zeruj_x();
	T.resetuj_ture();
	this->pas = true;
}

void INTELIGENCJA::decyzja(GRACZ &PLAYER, GRACZ &AI, GRA_SFML &GRA, STAWKI &S, TURA &T, RUNDA &R, SEMAFORY &SEM,ZEGAR &Z,sf::RenderWindow &app,STATYSTYKA &STA)
{
	int wylosowana = losowanie();
	int kwota_ai = GRA.a_ile_dodane_ai();
	int kwota_pl = GRA.a_ile_dodane_player();
	int roznica = kwota_pl - kwota_ai;
	if (roznica > AI.a_kwota())                                                                        // all in return 1
	{
		GRA.dodaj_ai(AI.a_kwota());
		GRA.dodaj_do_puli(AI.a_kwota());
		AI.pobierz(AI.a_kwota());
		++SEM;
	}
	else if (wylosowana >= 700 - agresywnosc && kwota_ai < kwota_pl&&AI.a_kwota()>kwota_pl-kwota_ai)   // raise  return 1
	{
		raise(PLAYER, AI, GRA, S, roznica);
		++SEM;
	}
	else if (wylosowana >= 400 && kwota_ai < kwota_pl)                                                 // call   return 2
	{
		call(PLAYER, AI, GRA, roznica);
		++SEM;
	}
	else if (kwota_ai == kwota_pl)                                                                     // check  return 3
	{
		check();
		++SEM;
	}
	else                                                                                               // fold   return 4
	{
		fold(PLAYER, AI, GRA, T, R, SEM, S,STA);
		SEM = 0;
	}
}

INTELIGENCJA::~INTELIGENCJA()
{
}
