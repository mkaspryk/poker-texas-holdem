//____________________________________________________________________________________________________
//****************************************************************************************************
//******************                                                        **************************
//****************** INTERFEJS GRAFICZNY POKERA INFORMACJE O KWOTACH W PULI **************************
//******************                                                        **************************
//****************************************************************************************************
//____________________________________________________________________________________________________


#ifndef H_GRA_SFML
#define H_GRA_SFML
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <stdlib.h>
#include <exception>
#include "GRACZ.h"
#include "MYSZKA.h"

/*!
Klasa dostarczajaca tekstury glownej planszy i zawierajaca informacje o kwotach w puli
jest to klasa pochodna po klasie GRACZ
*/
class GRA_SFML:public GRACZ
{
	//_______________________________ POLA ________________________________________________

	int ile_w_puli;
	int ile_dodane_player;
	int ile_dodane_ai;

	//_______________________________ SFML ________________________________________________

	sf::Texture TStol, THide, TFold, TRaise, TCall, TCheck, TMenu,TOk,TGameOver,TWinner;
	sf::Sprite SStol, SHide1, SHide2, SFold, SCheck, SCall, SRaise, SMenu,SOk,SGameOver,SWinner;
	sf::Text  TPlayerName, TAiName,TPot,TPotName,TPokerName,TPlayerAdd,TAiAdd;
	sf::Font Ffont1, Ffont2;
	
	//_____________________________________________________________________________________
public:
	/*!
	Konstruktor bezargumentowy klasy GRA_SFML
	*/
	GRA_SFML();

	/*!
	Metoda dodaj¹ca do puli kwote
	*/
	void dodaj_do_puli(int ile);

	/*!
	Metoda dodajaca kwote dodana przez PLAYER
	*/
	void dodaj_player(int ile);

	/*!
	Metoda dodajaca kwote dodana przez AI
	*/
	void dodaj_ai(int ile);

	/*!
	Akcesor do kwoty dodanej do puli
	*/
	int a_ile_w_puli();

	/*!
	Akcesor do kwoty dodanej do puli przez PLAYER
	*/
	int a_ile_dodane_player();

	/*!
	Akcesor do kwoty dodanej do puli przez AI
	*/
	int a_ile_dodane_ai();

	/*!
	Metoda zerujaca pule glowna oraz pule PLAYER i AI
    */
	void zeruj_pule();

	/*!
	Metoda SFML rysujaca 2 karty ukryte AI
	*/
	void rysuj_karty_ukryte(sf::RenderWindow &app);

	/*!
	Metoda SFML rysujaca plansze GRY
	*/
	void rysuj_plansze(sf::RenderWindow &app, int i);

	/*!
	Metoda SFML rysuje ok, ktore zatrzymuje gre, aby mozna bylo sprawdzic wynik rundy
	*/
	void rysuj_ok(sf::RenderWindow &app);

	/*!
	Metoda SFML rysuje koniec gry (wygrana lub przegrana)
	*/
	void rysuj_koniec(sf::RenderWindow &app, MYSZKA &myszka, bool koniec, int &kliknieta_strefa);

	/*!
	Destruktor klasy GRA_SFML
	*/
	~GRA_SFML();
};

#endif