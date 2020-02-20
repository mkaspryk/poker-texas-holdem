//____________________________________________________________________________________________________
//****************************************************************************************************
//*********************************                    ***********************************************
//********************************* LICZ¥CA TURE (1-5) ***********************************************
//*********************************                    ***********************************************
//****************************************************************************************************
//____________________________________________________________________________________________________


#ifndef H_TURA
#define H_TURA
#include "GRACZ.h"
#include "GRA_SFML.h"
#include "ROZDANIE_SFML.h"
#include "SEMAFORY.h"
#include "STAWKI.h"
#include "UKLAD_KART.h"
#include "MYSZKA.h"
#include "SUWAK.h"
#include "ZEGAR.h"
#include "RUNDA.h"
#include "STATYSTYKA.h"

/*!
Klasa reprezentuje piec tur, w ktorych wypisuje odpowiednia ilosc kart
*/
class TURA:public GRA_SFML
{
	//__________________________________________ POLA ________________________________________________

	int ktoraTura;
	int w;

	//________________________________________________________________________________________________
public:

	/*!
	Konstruktor klasy TURA
	*/
	TURA();

	/*!
	Metoda ktora przeprowadza rysowanie poszczegolnych tur gry i wykonuje dzielenie kwoty puli
	*/
	void tury_gry(GRACZ &PLAYER, GRACZ &AI, GRA_SFML &GRA, ROZDANIE_SFML &KARTY, SEMAFORY &SEM, RUNDA &R, STAWKI &S, UKLAD_KART &UKLAD, MYSZKA &myszka, SUWAK &slider1, ZEGAR &Z, sf::RenderWindow &app, int &kliknieta_strefa, STATYSTYKA &STA);

	/*!
	Metoda inkrementujaca ture 
	*/
	void kolejna_tura();

	/*!
	Metoda resetujaca ture (ktoraTura = 1)
	*/
	void resetuj_ture();

	/*!
	Akcesor do wartosci ktoraTura
	*/
	int a_tura();

	/*!
	Destruktor klasy TURA
	*/
	~TURA();
};

#endif 