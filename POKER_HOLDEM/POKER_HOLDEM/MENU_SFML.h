//____________________________________________________________________________________________________
//****************************************************************************************************
//****************************                          **********************************************
//**************************** INTERFEJS GRAFICZNY MENU **********************************************
//****************************                          **********************************************
//****************************************************************************************************
//____________________________________________________________________________________________________


#ifndef H_MENU_SFML
#define H_MENU_SFML
#include <SFML/Graphics.hpp>
#include <iostream>
#include "STATYSTYKA.h"
#include "RUNDA.h"

/*!
Klasa reprezentuje menu gry
*/
class MENU_SFML
{
	//______________________________ POLA ___________________________________________
	
	bool panel_trudnosci;
	bool panel_wyboru_opcji;
	bool panel_statystyk;

	//______________________________ SFML ___________________________________________

	sf::Texture TTlo, TNewGame, TOptions, TExit,TContinue, THard,TMedium,TEasy,TDIFFICULTYLEVEL,TSTATISTICS;
	sf::Sprite STlo, SNewGame, SOptions, SExit,SContinue,SHard,SMedium,SEasy,SDIFFICULTYLEVEL,SSTATISTICS;
	sf::Text TDifficultyLevel,TStatistics,TKwota,TYouWon;
	sf::Font Ffont1;

	//_______________________________________________________________________________
public:
	/*!
	Konstruktor bezargumentowy klasy MENU_SFML
	*/
	MENU_SFML();

	/*!
	Metoda wypisujaca MENU GRY
	*/
	void wypisz_menu(sf::RenderWindow &app);

	/*!
	Metoda rysujaca bloki z DIFFICULT LEVEL i STATISTICS
	*/
	void rysowanie_wyboru(sf::RenderWindow &app);

	/*!
	Metoda rysujaca bloki z EASY, MEDIUM i HARD
	*/
	void rysowanie_poziomu_trudnosci(sf::RenderWindow &app);

	/*!
	Metoda rysujaca wartosc wygranej kwoty dla PLAYER w biezacej rundzie
	*/
	void rysowanie_statystyk(sf::RenderWindow &app, STATYSTYKA &STA, RUNDA &R);

	/*!
	Akcesor do wartosci panel trudnosci
	*/
	bool a_panel_trudnosci();

	/*!
	Akcesor do wartosci panel wyboru opcji
	*/
	bool a_panel_wyboru_opcji();

	/*!
	Akcesor do wartosci panel statystyk
	*/
	bool a_panel_statystyk();

	/*!
	Metoda zmieniajaca wartosc panel wyboru opcji true na false i false na true
	*/
	void wybor();

	/*!
	Metoda zmieniajaca wartosc panel trudnosci true na false i false na true
	*/
	void switch_poziom();

	/*!
	Metoda zmieniajaca wartosc panel statystyk true na false i false na true
	*/
	void switch_statystyka();

	/*!
	Destruktor klasy MENU_SFML
	*/
	~MENU_SFML();
};

#endif H_MENU_SFML