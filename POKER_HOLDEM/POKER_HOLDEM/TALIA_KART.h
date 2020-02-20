//____________________________________________________________________________________________________
//****************************************************************************************************
//*************************************                ***********************************************
//************************************* TALIA KART(52) ***********************************************
//*************************************                ***********************************************
//****************************************************************************************************
//____________________________________________________________________________________________________



#ifndef H_TALIA_KART
#define H_TALIA_KART
#include <cstdlib>
#include <ctime>
#include <vector>
#include <iomanip>
#include <chrono>
#include <random>
#include "KARTA.h"

const int LICZBA_KART = 52;

/*!
Klasa reprezentuje talie 52 kart jest to klasa pochodna po klasie KARTA
*/
class TALIA_KART :public KARTA
{

	//______________________________________ POLA _____________________________________________

	KARTA *TALIA;
	int ktoraKARTA;

	//_________________________________________________________________________________________

public:

	/*!
	Konstrukor bezargumentowy klasy TALIA_KART
	*/
	TALIA_KART();

	/*!
	Metoda tasujaca karty w tali
	*/
	void tasowanie();

	/*!
	Metoda rozdajaca karte z tali
	*/
	KARTA rozdaj_karte();

	/*!
	Metoda rozdajca karty na dana runde
	*/
	std::vector<KARTA> rozdaj_9();

	/*!
	Destruktor klasy TALIA_KART
	*/
	~TALIA_KART();
};


#endif