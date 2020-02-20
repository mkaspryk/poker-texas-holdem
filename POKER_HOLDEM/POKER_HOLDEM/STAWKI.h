//____________________________________________________________________________________________________
//****************************************************************************************************
//******************************                                 *************************************
//****************************** WYZNACZA STAWKI DLA DANEJ RUNDY *************************************
//******************************                                 *************************************
//****************************************************************************************************
//____________________________________________________________________________________________________


#ifndef H_STAWKI
#define H_STAWKI

/*!
Klasa dostarczajaca do gry stawki i zwieksza je co 4 rundy
*/
class STAWKI
{
	//______________________________________ POLA ____________________________________________________

	int small_blind; // mala ciemna
	int big_blind;   // duza ciemna

	//________________________________________________________________________________________________
public:

	/*!
	Konstruktor bezargumentowy klasy STAWKI
	*/
	STAWKI();

	/*!
	Akcesor do wartosci small blind
	*/
	int a_small_blind();

	/*!
	Akcesor do wartosci big blind
	*/
	int a_big_blind();

	/*!
	Metoda inicjalizujaca stawki
	*/
	void ustaw_stawki();

	/*!
	Metoda zwiekszajaca wartosc stawek
	*/
	void zwiekszanie();

	/*!
	Destruktor klasy STAWKI
	*/
	~STAWKI();
};
#endif 

