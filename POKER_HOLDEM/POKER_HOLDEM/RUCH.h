//____________________________________________________________________________________________________
//****************************************************************************************************
//****************************************************************************************************
//***************************************** RUCH *****************************************************
//****************************************************************************************************
//****************************************************************************************************
//____________________________________________________________________________________________________


#ifndef H_RUCH
#define H_RUCH
#include "GRACZ.h"
#include "GRA_SFML.h"
#include "ZEGAR.h"
#include "TURA.h"
#include "RUNDA.h"
#include "STAWKI.h"
#include "SEMAFORY.h"
#include "SUWAK.h"
#include "STATYSTYKA.h"

/*!
Klasa reprezentuje ruch decyzje wykonana przez PLAYER
*/
class RUCH
{
public:

	/*!
	Konstruktor bezargumentowy klasy RUCH
	*/
	RUCH();

	/*!
	Metoda wybor jest to metoda w ktorej PLAYER wybiera sposrod check, call, raise i fold
	*/
	void wybor(GRACZ &AI,GRACZ &PLAYER,GRA_SFML &GRA,TURA &T,RUNDA &R,STAWKI &S,SEMAFORY &SEM, ZEGAR &Z,SUWAK &slider1, int kliknieta_strefa, STATYSTYKA &STA);

	/*!
	Metoda ustawiajaca dealera ze wzgledu na dana runde
	*/
	void ustawianie_dealer(GRACZ &AI, GRACZ &PLAYER, GRA_SFML &GRA, TURA &T, STAWKI &S, SEMAFORY &SEM, sf::RenderWindow &app);	

	/*!
	Destruktor klasy RUCH
	*/
	~RUCH();
};

#endif 