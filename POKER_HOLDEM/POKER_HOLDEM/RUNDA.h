//____________________________________________________________________________________________________
//****************************************************************************************************
//**************************                                      ************************************
//************************** KLASA LICZ¥CA RUNDY I RYSUJ¥CA RUNDÊ ************************************
//**************************                                      ************************************
//****************************************************************************************************
//____________________________________________________________________________________________________


#ifndef H_RUNDA
#define H_RUNDA
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string.h>
#include <sstream>

/*!
Klasa reprezentujaca runde i wyswietlajaca tekst informujacy ktora runda jest obecnie
*/
class RUNDA
{
	//____________________________________ POLA __________________________________________

	int ktoraRunda;
	
	//____________________________________ SFML __________________________________________

	sf::Text TRoundName, TNumberOfRound;
	sf::Font Ffont1;

	//_____________________________________________________________________________________
	
public:

	/*!
	Konstruktor bezargumentowy klasy RUNDA
	*/
	RUNDA();

	/*!
	Metoda inkrementujaca runde
	*/
	void zwieksz_runde();

	/*!
	Akcesor do wartosci ktora runda
	*/
	int a_ktoraRunda();

	/*!
	Metoda ustawiajacy runde na wartosc 1
	*/
	void zeruj_runde();

	/*!
	Metoda rysujaca wartosc biezacej rundy
	*/
	void rysuj_runde(sf::RenderWindow &app);

	/*!
	Destruktor klasy RUNDA
	*/
	~RUNDA();
};
#endif // !H_RUNDA