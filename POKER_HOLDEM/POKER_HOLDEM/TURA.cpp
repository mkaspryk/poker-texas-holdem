#include "TURA.h"

TURA::TURA()
{
	ktoraTura = 1;
}

void TURA::tury_gry(GRACZ &PLAYER, GRACZ &AI, GRA_SFML &GRA, ROZDANIE_SFML &KARTY, SEMAFORY &SEM, RUNDA &R, STAWKI &S, UKLAD_KART &UKLAD, MYSZKA &myszka, SUWAK &slider1, ZEGAR &Z, sf::RenderWindow &app, int &kliknieta_strefa,STATYSTYKA &STA)
{
	if (ktoraTura == 1)
	{
		KARTY.rysuj_karty_gracz(app);
		GRA.rysuj_karty_ukryte(app);
	}
	else if (ktoraTura == 2)
	{
		KARTY.rysuj_karty_gracz(app);
		GRA.rysuj_karty_ukryte(app);
		KARTY.rysuj_flop(app);
	}
	else if (ktoraTura == 3)
	{
		KARTY.rysuj_karty_gracz(app);
		GRA.rysuj_karty_ukryte(app);
		KARTY.rysuj_flop(app);
		KARTY.rysuj_turn(app);
	}
	else if (ktoraTura == 4)
	{
		KARTY.rysuj_karty_gracz(app);
		GRA.rysuj_karty_ukryte(app);
		KARTY.rysuj_flop(app);
		KARTY.rysuj_turn(app);
		KARTY.rysuj_river(app);
	}
	else if (ktoraTura == 5 )
	{
		KARTY.rysuj_karty_gracz(app);
		KARTY.rysuj_karty_przeciwnik(app);
		KARTY.rysuj_flop(app);
		KARTY.rysuj_turn(app);
		KARTY.rysuj_river(app);
		if (SEM.a_x() == 3)
		{
			KARTY.a_gracz_karty();
			KARTY.a_ai_karty();
			w = UKLAD.sprawdzenie(KARTY.a_gracz_karty(), KARTY.a_ai_karty());
			while (true)
			{
				app.clear();
				GRA.rysuj_plansze(app, 1);
				R.rysuj_runde(app);
				if (PLAYER.a_dealer())
					PLAYER.rysuj_dealer(app, 1);
				else
					AI.rysuj_dealer(app, 2);
				slider1.draw(app);
				PLAYER.rysuj_kwote(app);
				AI.rysuj_kwote(app);
				GRA.rysuj_ok(app);
				kliknieta_strefa = myszka.sprawdz_strefe(app);
				if (kliknieta_strefa == 9)
				{
					Z.czekaj(100000);
					if (w == 0)                   // podzial po rowno
					{
						PLAYER.dodaj_kwote(GRA.a_ile_dodane_player());
						STA.push_back(GRA.a_ile_dodane_player());
						AI.dodaj_kwote(GRA.a_ile_dodane_ai());
						GRA.zeruj_pule();
					}
					else if (w == 1)              // gracz bierze pule
					{
						if (GRA.a_ile_dodane_player() > GRA.a_ile_dodane_ai())
						{
							PLAYER.dodaj_kwote(GRA.a_ile_w_puli());
							STA.push_back(GRA.a_ile_w_puli());
						}
						else
						{
							PLAYER.dodaj_kwote(2 * GRA.a_ile_dodane_player());
							STA.push_back(2 * GRA.a_ile_dodane_player());
							AI.dodaj_kwote(GRA.a_ile_dodane_ai() - GRA.a_ile_dodane_player());
						}
						GRA.zeruj_pule();
					}
					else if (w == 2)              // ai bierze pule
					{
						if (GRA.a_ile_dodane_ai() > GRA.a_ile_dodane_player())
						{
							AI.dodaj_kwote(GRA.a_ile_w_puli());
							STA.push_back(0);
						}
						else
						{
							AI.dodaj_kwote(2 * GRA.a_ile_dodane_ai());
							PLAYER.dodaj_kwote(GRA.a_ile_dodane_player()-GRA.a_ile_dodane_ai());
							STA.push_back(GRA.a_ile_dodane_player() - GRA.a_ile_dodane_ai());
						}
						GRA.zeruj_pule();
					}
					PLAYER.zmien_dealera();
					SEM = 0;
					AI.zmien_dealera();
					R.zwieksz_runde();
					if (R.a_ktoraRunda() % 4 == 0)
						S.zwiekszanie();
					break;
				}
				if (w == 0)
				{
					PLAYER.rysuj_remis(app);
				}
				else if (w == 1)
				{
					PLAYER.rysuj_wygrana(app);
				}
				else if (w == 2)
				{
					PLAYER.rysuj_przegrana(app);
				}
				KARTY.rysuj_karty_gracz(app);
				KARTY.rysuj_karty_przeciwnik(app);
				KARTY.rysuj_flop(app);
				KARTY.rysuj_turn(app);
				KARTY.rysuj_river(app);
				app.display();
			}
			ktoraTura = 1;
			SEM.zeruj_x();
		}
	}
}

void TURA::kolejna_tura()
{
	ktoraTura++;
}

void TURA::resetuj_ture()
{
	ktoraTura = 1;
}

int TURA::a_tura()
{
	return ktoraTura;
}

TURA::~TURA()
{
}
