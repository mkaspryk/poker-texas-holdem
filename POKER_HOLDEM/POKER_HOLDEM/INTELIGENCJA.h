//____________________________________________________________________________________________________
//****************************************************************************************************
//****************************                          **********************************************
//**************************** SZTUCZNA INTELIGENCJA AI **********************************************
//****************************                          **********************************************
//****************************************************************************************************
//____________________________________________________________________________________________________


#ifndef H_INTELIGENCJA
#define H_INTELIGENCJA
#include "KARTA.h"
#include "GRACZ.h"
#include "GRA_SFML.h"
#include "STAWKI.h"
#include "TURA.h"
#include "RUNDA.h"
#include "SEMAFORY.h"
#include "STAWKI.h"
#include "STATYSTYKA.h"
#include <iostream>
#include <algorithm> 
#include <utility>
#include <vector>
#include <random>
#include <chrono>

/*!
Klasa reprezentujaca inteligencje AI 
*/
class INTELIGENCJA 
{
	//___________________________________ POLA __________________________________________

	int agresywnosc;
	bool pas;

	//___________________________________ SFML __________________________________________

	sf::Text TFold;
	sf::Font Ffont1;

	//___________________________________________________________________________________
public:
	/*!
	Konstruktor bezargumentowy klasy INTELIGENCJA
	*/
	INTELIGENCJA();

	/*!
	Meotda zamieniajaca wartosc pas(pasowanie AI) na false
	*/
	void koniec_pas();

	/*!
	Akcesor do wartosci pas
	*/
	bool a_pas();

	/*!
	Metoda rysujaca FOLD oznacza to ze AI spasowal
	*/
	void rysuj_pas(sf::RenderWindow &app);

	/*!
	Metoda zmieniajaca poziom trudnosci
	*/
	void change_difficulty(int level);

	/*!
	Metoda losujaca liczbe z przedzialu od 0 do 1000
	*/
	int losowanie();

	/*!
	Metoda raise podbicie przez AI kwoty w puli
	*/
	void raise(GRACZ &PLAYER, GRACZ &AI, GRA_SFML &GRA,STAWKI &S,int roznica);

	/*!
	Metoda call wyrownanie przez AI kwoty w puli
	*/
	void call(GRACZ &PLAYER, GRACZ &AI, GRA_SFML &GRA, int roznica);

	/*!
	Metoda check czekanie w przypadku rownej kwoty 
	*/
	void check();

	/*!
	Metoda fold spasowanie rundy
	*/
	void fold(GRACZ &PLAYER, GRACZ &AI, GRA_SFML &GRA, TURA &T, RUNDA &R, SEMAFORY &SEM, STAWKI &S, STATYSTYKA &STA);

	/*!
	Metoda w ktorej zostaje okreslone jaki ruch wykonana AI
	*/
	void decyzja(GRACZ &PLAYER, GRACZ &AI, GRA_SFML &GRA, STAWKI &S,TURA &T, RUNDA &R, SEMAFORY &SEM,ZEGAR &Z,sf::RenderWindow &app,STATYSTYKA &STA);

	/*!
	Destruktor klasy INTELIGENCJA
	*/
	~INTELIGENCJA();
};

#endif