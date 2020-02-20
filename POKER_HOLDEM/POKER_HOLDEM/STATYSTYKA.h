//____________________________________________________________________________________________________
//****************************************************************************************************
//**************************************            **************************************************
//************************************** STATYSTYKA **************************************************
//**************************************            **************************************************
//****************************************************************************************************
//____________________________________________________________________________________________________


#ifndef H_STATYSTYKA
#define H_STATYSTYKA
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <string>
#include <sstream>

/*!
Lista dwukierunkowa zawierajaca pole z kwota wygrana przez PLAYER
*/
struct lista
{
	int kwota_wygrana;
	std::shared_ptr<lista> next;
	std::shared_ptr<lista> prev;
	lista(int kwota_wygrana1, std::shared_ptr<lista> next1, std::shared_ptr<lista> prev1)
		:kwota_wygrana(kwota_wygrana1), next(next1), prev(prev1) {};
};

/*!
Klasa dostarczajaca informacje o kwocie wygranej w biezacej rundzie
*/
class STATYSTYKA
{
	//_____________________________________________ POLA ___________________________________________

	std::shared_ptr<lista> head;

public:

	/*!
	Konstruktor bezargumentowy klasy STATYSTYKA
	*/
	STATYSTYKA();

	/*!
	Konstruktor argumentowy klasy STATYSTYKA
	*/
	STATYSTYKA(std::shared_ptr<lista> head1);

	/*!
	Metoda inicjalizujaca statystyke dla nowej rundy 
	*/
	void ustaw(std::shared_ptr<lista> head1);

	/*!
	Metoda dodajaca nowa wartosc kwoty wygranej przez PLAYER na koniec listy
	*/
	void push_back(int kwota_wygrana);

	/*!
	Metoda zwracjaca kwote dla biezacej rundy
	*/
	int zwroc();

	/*!
	Destruktor klasy STATYSTYKA
	*/
	~STATYSTYKA();
};

#endif