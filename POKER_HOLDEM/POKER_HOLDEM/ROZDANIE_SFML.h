//____________________________________________________________________________________________________
//****************************************************************************************************
//****************************                                       *********************************
//**************************** ROZDANIE KART (9) ORAZ RYSOWANIE SFML *********************************
//****************************                                       *********************************
//****************************************************************************************************
//____________________________________________________________________________________________________


#ifndef H_ROZDANIE_SFML
#define H_ROZDANIE_SFML
#include <SFML/Graphics.hpp>
#include <vector>
#include <exception>
#include <stdlib.h>
#include <iostream>
#include "KARTA.h"
#include "TALIA_KART.h"

/*!
Klasa w ktorej zostaje przeprowadzone wczytanie kart jest to klasa pochodna po klasie KARTA
*/
class ROZDANIE_SFML:public KARTA
{
	//_____________________________________ POLA ________________________________________________

	std::vector<KARTA> ROZDANIE;               // wczytanie wszystkich kart w jednej turze 9 kart
	std::vector<KARTA> KARTY_GRACZ;            // 7 kart
	std::vector<KARTA> KARTY_AI;               // 7 kart
	std::vector<KARTA> h_2;                    // 2 karty

	//_____________________________________ SFML ________________________________________________

	sf::Texture TKarty[9];
	sf::Sprite SKarta1, SKarta2, SKarta3, SKarta4, SKarta5, SKarta6, SKarta7, SKarta8, SKarta9;

	//___________________________________________________________________________________________

public:
	
	/*!
	Konstruktor bezargumentowy klasy ROZDANIE_SFML
	*/
	ROZDANIE_SFML();

	/*!
	Akcesor do kart PLAYER
	*/
	std::vector<KARTA> a_gracz_karty();

	/*!
	Akcesor do kart AI
	*/
	std::vector<KARTA> a_ai_karty();

	/*!
	Metoda wszytujaca karty z pliku
	*/
	void wczytanie_kart();

	/*!
	Metoda inicjalizujaca nowe rozdanie
	*/
	void nowe_rozdanie();

	/*!
	Metoda rysujaca karty PLAYER
	*/
	void rysuj_karty_gracz(sf::RenderWindow &app);

	/*!
	Metoda rysujaca karty AI
	*/
	void rysuj_karty_przeciwnik(sf::RenderWindow &app);

	/*!
	Metoda rysujaca karty flop (3 pierwsze karty)
	*/
	void rysuj_flop(sf::RenderWindow &app);

	/*!
	Metoda rysujaca karty turn (czwarta karte)
	*/
	void rysuj_turn(sf::RenderWindow &app);

	/*!
	Metoda rysujaca (piata karte)
	*/
	void rysuj_river(sf::RenderWindow &app);

	/*!
	Destruktor klasy ROZDANIE_SFML
	*/
	~ROZDANIE_SFML();
};

#endif