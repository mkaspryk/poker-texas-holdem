#include "RUCH.h"

RUCH::RUCH()
{
}

void RUCH::wybor(GRACZ &AI, GRACZ &PLAYER, GRA_SFML &GRA, TURA &T, RUNDA &R, STAWKI &S, SEMAFORY &SEM, ZEGAR &Z, SUWAK &slider1, int kliknieta_strefa,STATYSTYKA &STA)
{
	if (kliknieta_strefa == 0)                                                                                                  // FOLD
	{
		Z.czekaj(100000);
		AI.dodaj_kwote(GRA.a_ile_w_puli());
		STA.push_back(0);
		GRA.zeruj_pule();
		PLAYER.zmien_dealera();
		AI.zmien_dealera();
		if (R.a_ktoraRunda() % 4 == 0)
			S.zwiekszanie();
		R.zwieksz_runde();
		SEM.zeruj_x();
		T.resetuj_ture();
		SEM = 0;
	}
	else if (kliknieta_strefa == 1 && slider1.getOldSliderValue() >= (GRA.a_ile_dodane_ai() - GRA.a_ile_dodane_player()) || kliknieta_strefa == 1 && PLAYER.a_kwota() <= (GRA.a_ile_dodane_ai() - GRA.a_ile_dodane_player()))        // RAISE
	{
		Z.czekaj(100000);
		GRA.dodaj_do_puli(slider1.getOldSliderValue());
		GRA.dodaj_player(slider1.getOldSliderValue());
		PLAYER.pobierz(slider1.getOldSliderValue());
		slider1.resetOldSliderValue();
		T.kolejna_tura();
		--SEM;
	}
	else if (kliknieta_strefa == 2 && GRA.a_ile_dodane_ai() > GRA.a_ile_dodane_player() && PLAYER.a_kwota() >= (GRA.a_ile_dodane_ai() - GRA.a_ile_dodane_player()))  // CALL
	{
		Z.czekaj(100000);
		int ile = GRA.a_ile_dodane_ai() - GRA.a_ile_dodane_player();
		if (ile > PLAYER.a_kwota())
		{
			PLAYER.pobierz(PLAYER.a_kwota());
			GRA.dodaj_player(PLAYER.a_kwota());
			GRA.dodaj_do_puli(ile);
		}
		else
		{
			PLAYER.pobierz(ile);
			GRA.dodaj_player(ile);
			GRA.dodaj_do_puli(ile);
			T.kolejna_tura();
			--SEM;
		}
	}
	else if ((kliknieta_strefa == 3 && GRA.a_ile_dodane_player() == GRA.a_ile_dodane_ai()) || (kliknieta_strefa == 3 && AI.a_kwota() == 0) || (kliknieta_strefa == 3 && PLAYER.a_kwota() == 0)) // CHECK
	{
		Z.czekaj(200000);
		T.kolejna_tura();
		--SEM;
	}
}

void RUCH::ustawianie_dealer(GRACZ &AI, GRACZ &PLAYER, GRA_SFML &GRA, TURA &T, STAWKI &S, SEMAFORY &SEM, sf::RenderWindow &app)
{
	if (PLAYER.a_dealer())    // player jest dealer wiec rozdaje karty, pobierana jest mala ciemna
	{
		PLAYER.rysuj_dealer(app, 1);
		if (T.a_tura() == 1 && SEM.a_x() == 1)
		{
			++SEM;
			++SEM;
			if (PLAYER.a_kwota() < S.a_small_blind())
			{
				GRA.dodaj_player(PLAYER.a_kwota());
				PLAYER.pobierz(PLAYER.a_kwota());
				GRA.dodaj_do_puli(PLAYER.a_kwota());
			}
			else
			{
				GRA.dodaj_player(S.a_small_blind());
				PLAYER.pobierz(S.a_small_blind());
				GRA.dodaj_do_puli(S.a_small_blind());
			}
			if (AI.a_kwota() < S.a_big_blind())
			{
				GRA.dodaj_ai(AI.a_kwota());
				AI.pobierz(AI.a_kwota());
				GRA.dodaj_do_puli(AI.a_kwota());
			}
			else
			{
				GRA.dodaj_ai(S.a_big_blind());
				AI.pobierz(S.a_big_blind());
				GRA.dodaj_do_puli(S.a_big_blind());
			}
			// ------------------------------
			SEM.zwieksz_x();
		}
	}
	else
	{
		AI.rysuj_dealer(app, 2);
		if (T.a_tura() == 1 && SEM.a_x() == 1)
		{
			++SEM;
			if (PLAYER.a_kwota() < S.a_big_blind())
			{
				GRA.dodaj_player(PLAYER.a_kwota());
				PLAYER.pobierz(PLAYER.a_kwota());
				GRA.dodaj_do_puli(PLAYER.a_kwota());
			}
			else
			{
				GRA.dodaj_player(S.a_big_blind());
				PLAYER.pobierz(S.a_big_blind());
				GRA.dodaj_do_puli(S.a_big_blind());
			}
			if (AI.a_kwota() < S.a_small_blind())
			{
				GRA.dodaj_ai(AI.a_kwota());
				AI.pobierz(AI.a_kwota());
				GRA.dodaj_do_puli(AI.a_kwota());
			}
			else
			{
				GRA.dodaj_ai(S.a_small_blind());
				AI.pobierz(S.a_small_blind());
				GRA.dodaj_do_puli(S.a_small_blind());
			}
			// ------------------------------
			SEM.zwieksz_x();
		}
	}
	if (T.a_tura() == 1 && SEM.a_x() == 2)
	{
		// wpisanie pobranych kwot od player i ai
		// --------------------------------------
		SEM.zwieksz_x();
	}
}

RUCH::~RUCH()
{
}
