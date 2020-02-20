#include "POKER.h"

POKER::POKER()
{
}

void POKER::POKER_TEXAS_HOLDEM()
{
	//_______________________________________ SUWAK _________________________________________________

	SUWAK slider1(320, 1000);
	slider1.setSliderValue(2000);

	//_______________________________________ ZEGAR _________________________________________________

	ZEGAR Z;

	//________________________________ STREFY RUCH GRACZA ___________________________________________

	MYSZKA myszka;
	myszka.ustaw_strefe(0, 1600, 1810, 450, 570);    // FOLD 
	myszka.ustaw_strefe(1, 1600, 1810, 600, 720);    // RAISE
	myszka.ustaw_strefe(2, 1600, 1810, 750, 870);    // CALL
	myszka.ustaw_strefe(3, 1600, 1810, 900, 1020);   // CHECK
	myszka.ustaw_strefe(4, 1600, 1910, 0, 120);      // MENU

	//_____________________________________ STREFY MENU _____________________________________________

	myszka.ustaw_strefe(5, 200, 620, 100, 280);      // CONTINUE
	myszka.ustaw_strefe(6, 200, 620, 350, 530);      // NEW GAME
	myszka.ustaw_strefe(7, 200, 620, 600, 780);      // OPTIONS
	myszka.ustaw_strefe(8, 200, 620, 850, 1030);     // EXIT
	myszka.ustaw_strefe(10, 1250, 1670, 200, 380);   // EASY
	myszka.ustaw_strefe(11, 1250, 1670, 450, 630);   // MEDIUM
	myszka.ustaw_strefe(12, 1250, 1670, 700, 880);   // HARD
	myszka.ustaw_strefe(13, 700, 1120, 200, 380);   // DIFICULTY LEVEL
	myszka.ustaw_strefe(14, 700, 1120, 700, 880);   // STATISTICS
	//_____________________________________ KONIEC RUNDY _____________________________________________

	myszka.ustaw_strefe(9, 1200, 1410, 620, 740);

	//_______________________________________ KONIEC GRY _____________________________________________

	myszka.ustaw_strefe(15, 0, 1920, 0, 1080);

	//________________________________________  STREFA  ______________________________________________

	int kliknieta_strefa = 4;   // wartosc poczatkowa klikniecia chcemy by sie otworzylo najpierw menu

	//________________________________________ SFML OKNO _____________________________________________

	sf::RenderWindow app{ sf::VideoMode{1920,1080},"POKER TEXAS HOLDEM",sf::Style::Fullscreen }; // tworzenie okienka 
	app.setFramerateLimit(60);                                                                   // ustawianie framerate

	//___________________________________________ MENU _______________________________________________

	MENU_SFML M;

	//____________________________________________ GRA _______________________________________________

	GRA_SFML GRA;

	//________________________________________ UKLAD KART ____________________________________________

	UKLAD_KART UKLAD;

	//__________________________________________ GRACZE ______________________________________________

	GRACZ PLAYER;
	GRACZ AI;

	//________________________________________ INTELIGENCJA __________________________________________

	INTELIGENCJA I;

	//__________________________________________ SEMAFORY ____________________________________________

	SEMAFORY SEM;

	//____________________________________________ RUCH ______________________________________________

	RUCH RU;

	//____________________________________________ RUNDA _____________________________________________

	RUNDA R;

	//____________________________________________ TURA _____________________________________________

	TURA T;                        // okresla nam rozdanie

	//___________________________________________ STAWKI ____________________________________________

	STAWKI S;                      // okresla nam wysokosc stawek small_blind and big_blind

	//________________________________________ ROZDANIE KART ________________________________________

	ROZDANIE_SFML KARTY;           // znajduja sie tu wszystkie karty (9 kart)

	//________________________________________ STATYSTYKA ___________________________________________

	STATYSTYKA STA(std::shared_ptr<lista>(new lista(0, nullptr, nullptr)));

	//_______________________________________________________________________________________________
	while (app.isOpen())
	{
		sf::Event zdarzenie;
		//_________________________________________ menu ____________________________________________

		app.pollEvent(zdarzenie);
		if (kliknieta_strefa == 4 || zdarzenie.type == sf::Event::KeyPressed&&zdarzenie.key.code == sf::Keyboard::M)
		{
			while (true)
			{
				app.clear();
				M.wypisz_menu(app);
				kliknieta_strefa = myszka.sprawdz_strefe(app);
				if (kliknieta_strefa == 5)                                   // kontynowanie
				{
					Z.czekaj(100000);
					if (PLAYER.a_gra() == true)
						break;
				}
				else if (kliknieta_strefa == 6)                              // nowa gra
				{
					Z.czekaj(100000);
					PLAYER.poczatek(1, 2000, true);
					AI.poczatek(2, 2000, false);
					SEM.zeruj_x();
					GRA.zeruj_pule();
					SEM = 0;
					R.zeruj_runde();
					S.ustaw_stawki();
					STA.ustaw(std::shared_ptr<lista>(new lista(0, nullptr, nullptr)));
					break;
				}
				else if (kliknieta_strefa == 7)                              // opcje
				{
					Z.czekaj(100000);
					M.wybor();
				}
				if (kliknieta_strefa == 8)                                   // wyjscie z aplikacji
				{
					Z.czekaj(100000);
					app.close();
					break;
				}
				if (M.a_panel_wyboru_opcji())
				{
					M.rysowanie_wyboru(app);
					if (kliknieta_strefa == 13)
					{
						Z.czekaj(100000);
						M.switch_poziom();
						M.wybor();
					}
					else if (kliknieta_strefa == 14)
					{
						Z.czekaj(100000);
						M.switch_statystyka();
						M.wybor();
					}
				}
				if (M.a_panel_trudnosci())
				{
					M.rysowanie_poziomu_trudnosci(app);
					if (kliknieta_strefa == 10)      // EASY
					{
						Z.czekaj(100000);
						I.change_difficulty(-100);
						M.switch_poziom();
					}
					if (kliknieta_strefa == 11)      // MEDIUM
					{
						Z.czekaj(100000);
						I.change_difficulty(0);
						M.switch_poziom();
					}
					if (kliknieta_strefa == 12)      // HARD
					{
						Z.czekaj(100000);
						I.change_difficulty(100);
						M.switch_poziom();
					}
				}
				if (M.a_panel_statystyk() == true)
				{
					M.rysowanie_statystyk(app,STA,R);
				}
				app.pollEvent(zdarzenie);
				if (zdarzenie.type == sf::Event::KeyPressed&&zdarzenie.key.code == sf::Keyboard::Escape)
				{
					app.close();
					break;
				}
				if (zdarzenie.type == sf::Event::KeyPressed&&zdarzenie.key.code == sf::Keyboard::Q)
					break;
				app.display();
			}
		}
		//______________________________________ rozdanie kart _______________________________________

		if (SEM.a_x() == 0)
		{
			KARTY.nowe_rozdanie();
			KARTY.wczytanie_kart();
			SEM.zwieksz_x();
		}

		//____________________________________  aktualizacja kwot ____________________________________

		AI.uaktualnij_kwote();
		PLAYER.uaktualnij_kwote();

		//_____________________________________ rysowanie planszy ____________________________________

		app.clear();
		GRA.rysuj_plansze(app, 1);
		R.rysuj_runde(app);

		//_____________________________________ tworzenie suwaka _____________________________________

		slider1.create(0, PLAYER.a_kwota());
		slider1.draw(app);

		//___________________________________ poczatek rozdania ______________________________________

		while (SEM.a_x() == 1)
		{
			app.clear();
			GRA.rysuj_plansze(app, 1);
			R.rysuj_runde(app);
			slider1.draw(app);
			PLAYER.rysuj_kwote(app);
			AI.rysuj_kwote(app);
			GRA.rysuj_ok(app);
			if (I.a_pas() == true)
				I.rysuj_pas(app);
			kliknieta_strefa = myszka.sprawdz_strefe(app);
			if (kliknieta_strefa == 9)
			{
				I.koniec_pas();
				break;
			}
			app.display();
		}

		//_____________________________ rysowanie aktualnych kwot ____________________________________

		PLAYER.rysuj_kwote(app);
		AI.rysuj_kwote(app);

		//_________________________________ ustawianie dealera _______________________________________

		RU.ustawianie_dealer(AI, PLAYER, GRA, T, S, SEM, app);

		//____________________________ inteligencja (ruch komputera) _________________________________

		if (SEM.a_semafor_ai() == 1)
		{
			I.decyzja(PLAYER, AI, GRA, S, T, R, SEM, Z, app,STA);
		}

		//___________________________________ ruch playera ___________________________________________

		kliknieta_strefa = myszka.sprawdz_strefe(app);
		if (SEM.a_semafor_ai() == 2)
			RU.wybor(AI, PLAYER, GRA, T, R, S, SEM, Z, slider1, kliknieta_strefa,STA);

		//________________________________________ tury ______________________________________________

		T.tury_gry(PLAYER, AI, GRA, KARTY, SEM, R, S, UKLAD, myszka, slider1, Z, app, kliknieta_strefa,STA);

		//______________________________________ koniec gry __________________________________________

		if (PLAYER.a_kwota() == 0 && SEM.a_x() == 0)                       // koniec gry dla PLAYER
			PLAYER.koniec_gry();
		else if (AI.a_kwota() == 0 && SEM.a_x() == 0)                      // koniec gry dla AI
			AI.koniec_gry();

		if (PLAYER.a_gra() == false || AI.a_gra() == false)
		{
			if (PLAYER.a_gra() == false)                                   // koniec gry player wygrywa
				GRA.rysuj_koniec(app, myszka, false, kliknieta_strefa);
			else
				GRA.rysuj_koniec(app, myszka, true, kliknieta_strefa);
			kliknieta_strefa = 4;
		}

		//_______________________________ zdarzenia do zamkniecia okna gry ___________________________

		if (zdarzenie.type == sf::Event::Closed)
		{
			app.close();
			break;
		}
		if (zdarzenie.type == sf::Event::KeyPressed&&zdarzenie.key.code == sf::Keyboard::Escape)
		{
			app.close();
			break;
		}
		app.display();
	}
}

POKER::~POKER()
{
}
