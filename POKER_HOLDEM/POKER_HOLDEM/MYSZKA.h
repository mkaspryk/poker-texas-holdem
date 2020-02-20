//____________________________________________________________________________________________________
//****************************************************************************************************
//****************************                                   *************************************
//**************************** KLASA WYKONUJ¥CA ZDARZENIA MYSZKI *************************************
//****************************                                   *************************************
//****************************************************************************************************
//____________________________________________________________________________________________________


#ifndef H_MYSZKA
#define H_MYSZKA
#include <SFML/Graphics.hpp>
#include <sstream>
#include <iostream>

/*!
Klasa reprezentuje strefy myszki ktore powoduja odpowiednia zdarzenia w grze
*/
class MYSZKA
{
	//_______________________________________ POLA _______________________________________________

	struct strefa_myszki
	{
		int x0, x1, y0, y1;
		int ktora;
		bool aktywna;
	}strefa[20];

	//_______________________________________ SFML _________________________________________________

	sf::Text napis1, napis2;
	sf::Font czcionka;

	//______________________________________________________________________________________________
public:

	/*!
	Konstruktor bezargumentowy klasy MYSZKA
	*/
	MYSZKA();

	/*!
	Metoda rysujaca pozycje myszki
	*/
	void rysuj(sf::RenderWindow &app, sf::Vector2f pozycja_myszki);
	
	/*!
	Metoda ustawiajaca nowa strefe klikniecia myszki
    */
	void ustaw_strefe(int ktoraStrefa, int _x0, int _x1, int _y0, int _y1);

	/*!
	Metoda sprawdzajaca strefe klikniecia myszki 
    */
	int sprawdz_strefe(sf::RenderWindow &app);

	/*!
	Destruktor klasy MYSZKA
	*/
	~MYSZKA();
};

#endif
