//____________________________________________________________________________________________________
//****************************************************************************************************
//*********************************                         ******************************************
//********************************* SPRAWDZAJ¥CA UK£AD KART ******************************************
//*********************************                         ******************************************
//****************************************************************************************************
//____________________________________________________________________________________________________


#ifndef H_UKLAD_KART
#define H_UKLAD_KART
#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include "KARTA.h"


/*!
Klasa sprawdzajaca uklad kart uzyskany przez danego gracza jest to klasa pochodna po klasie KARTA
*/
class UKLAD_KART :public KARTA
{
	//_________________________________________ POLA _________________________________________________


	int w;                           // wartosc dodatkowa sprawdza czy wygral gracz czy komputer
	int rank;                        // sprawdza czy dany uk³ad jest wiêkszy od innego 
	int rank2;                       // dodatkowe sprawdzenie w przypadku dwóch par (druga para), full (para kart)
	std::vector<KARTA> TALIA;        // 7 kart dostepnych dla danego gracza 5 wspolnych 2 osobiste 

	//________________________________________________________________________________________________
public:

	/*!
	Konstruktor bezargumentowy klasy UKLAD_KART
	*/
	UKLAD_KART();

	/*!
	Konstruktor argumentowy klasy UKLAD_KART
	*/
	template <typename T>
	UKLAD_KART(T w1, T rank1, T rank2, std::vector<KARTA> TALIA);

	/*!
	Akcesor do wygranej
	*/
	int a_w() { return w; }

	/*!
	Metoda sprawdzajca kto wygral
	*/
	int wygrana(UKLAD_KART G1, UKLAD_KART G2);

	/*!
	Metoda sprawdzajca kto wygral
	*/
	int wygrana2(UKLAD_KART G1, UKLAD_KART G2);

	/*!
	Metoda sprawdzajca uklad kart
	*/
	int sprawdzenie(std::vector<KARTA> T1, std::vector<KARTA> T2);

	/*!
	Akcesor do tali (7 kart)
	*/
	KARTA akcesor_talia(int i);

	/*!
	Metoda sortujaca karty dla danego gracza
	*/
	void sortuj();

	/*!
	Metoda odfiltrujaca karty dla danego gracza
	*/
	void odfiltrowanie();

	/*!
	Metoda znajdujca najwyzsza karte
	*/
	int najwyzsza(int k); // dziala 

	/*!
	Metoda znajdujca pare
	*/
	int jedna_para(); // dziala 

	/*!
	Metoda znajdujca dwie pary
	*/
	std::pair<int, int> dwie_pary(); // dziala 

	/*!
	Metoda znajdujca trojke
	*/
	int trojka(); // dziala 

	/*!
	Metoda znajdujca strit
	*/
	int strit(); // dziala

	/*!
	Metoda znajdujca kolor
	*/
	int kolor(); // dziala

	/*!
	Metoda znajdujca full
	*/
	std::pair<int, int> full(); //dziala

	/*!
	Metoda znajdujca karete
	*/
	int kareta(); // dziala 

	/*!
	Metoda znajdujca poker
	*/
	int poker(); // dziala 

	/*!
	Destruktor klasy UKLAD_KART
	*/
	~UKLAD_KART();
};


#endif