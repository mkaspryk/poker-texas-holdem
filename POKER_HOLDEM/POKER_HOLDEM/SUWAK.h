//____________________________________________________________________________________________________
//****************************************************************************************************
//****************************                                               *************************
//**************************** INTERFEJS GRAFICZNY DLA SUWAKA DODAJ¥CY KWOTE *************************
//****************************                                               *************************
//****************************************************************************************************
//____________________________________________________________________________________________________


#ifndef H_SUWAK
#define H_SUWAK
#include <SFML\Graphics.hpp>
#include <iostream>
#include <sstream>
#include <string>

/*!
Klasa reprezentuje suwak uzyty do wprowdzania kwot przez PLAYER w przypadku raise (podbicia)
*/
class SUWAK
{
	//__________________________________________ POLA ________________________________________________
	
	int minValue;
	int maxValue;
	int xCord;
	int yCord;
	int axisWidth;
	int axisHeight;
	int sliderWidth;
	int sliderHeight;
	int sliderValue;
	int oldSliderValue;

	//__________________________________________ SFML ________________________________________________

	sf::RectangleShape slider;
	sf::RectangleShape axis;
	sf::Font Ffont1;
	sf::Text text, value;

public:

	/*!
	Konstruktor argumentowy klasy SUWAK
	*/
	SUWAK(int x,int y);

	/*!
	Metoda zwracajaca text z wartosciami suwaka
	*/
	sf::Text returnText(int x, int y, std::string z, int fontSize);

	/*!
	Metoda tworzaca suwak
	*/
	void create(int min, int max);

	/*!
	Metoda zapewniajca logike dla suwaka
	*/
	void logic(sf::RenderWindow &app);

	/*!
	Akcesor do wczesniejszej wartosci suwaka
	*/
	int getOldSliderValue();

	/*!
	Metoda resetujaca wartosc suwaka
	*/
	void resetOldSliderValue();

	/*!
	Metoda rysujaca biezaca wartosc suwaka
	*/
	void myDraw(sf::RenderWindow &app);

	/*!
	Akcesor do wartosci suwaka
	*/
	int getSliderValue();

	/*!
	Metoda ustawiajca wartosc suwaka
	*/
	void setSliderValue(int newValue);

	/*!
	Metoda logiczna ustwiajca zakres suwaka 
	*/
	void setSliderPercentValue(float newPercentValue);

	/*!
	Metoda rysujaca suwak
	*/
	void draw(sf::RenderWindow & app);

	/*!
	Destruktor klasy SUWAK
	*/
	~SUWAK();
};

#endif // !H_SUWAK