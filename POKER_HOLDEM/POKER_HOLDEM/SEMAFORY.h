//____________________________________________________________________________________________________
//****************************************************************************************************
//***************************************            *************************************************
//***************************************  SEMAFORY  *************************************************
//***************************************            *************************************************
//****************************************************************************************************
//____________________________________________________________________________________________________

#ifndef H_SEMAFORY
#define H_SEMAFORY

/*!
Klasa reprezentujaca semafory typowe dla gry turowej
*/
class SEMAFORY
{
	//______________________________________ POLA ____________________________________________________
	
	int semafor_ai;
	int x;

	//________________________________________________________________________________________________
public:

	/*!
	Konstruktor bezargumentowy klasy SEMAFOR
	*/
	SEMAFORY();

	/*!
	Akcesor do semaforu AI
	*/
	int a_semafor_ai();

	/*!
	Akcesor do semaforu x
	*/
	int a_x();

	/*!
	Metoda zwiekszajaca x
	*/
	void zwieksz_x();

	/*!
	Metoda zerujaca x
	*/
	void zeruj_x();

	/*!
	Operator inkrementujacy wartosc semafor_ai
	*/
	SEMAFORY &operator++();

	/*!
	Operator dekrementujacy wartosc semafor_ai
	*/
	SEMAFORY &operator--();

	/*!
	Operator przypisujacy wartosc semafor_ai
	*/
	SEMAFORY &operator=(int i);

	/*!
	Destruktor klasy SEMAFORY
	*/
	~SEMAFORY();
};

#endif