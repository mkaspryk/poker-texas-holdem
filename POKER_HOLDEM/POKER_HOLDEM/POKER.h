//____________________________________________________________________________________________________
//****************************************************************************************************
//****************************************       *****************************************************
//**************************************** POKER *****************************************************
//****************************************       *****************************************************
//****************************************************************************************************
//____________________________________________________________________________________________________


#ifndef  H_POKER
#define  H_POKER

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <memory>
#include "KARTA.h"
#include "TALIA_KART.h"
#include "GRA_SFML.h"
#include "GRACZ.h"
#include "UKLAD_KART.h"
#include "ROZDANIE_SFML.h"
#include "TURA.h"
#include "RUNDA.h"
#include "STAWKI.h"
#include "INTELIGENCJA.h"
#include "MENU_SFML.h"
#include "MYSZKA.h"
#include "ZEGAR.h"
#include "SUWAK.h"
#include "SEMAFORY.h"
#include "RUCH.h"
#include "STATYSTYKA.h"

/*!
Glowna klasa gry wywolywana z poziomu main 
*/
class POKER
{
public:

	/*!
	Konstruktor bezargumentowy klasy POKER
	*/
	POKER();

	/*!
	Glowna metoda gry Poker Texas Holdem
	*/
	void POKER_TEXAS_HOLDEM();

	/*!
	Destruktor klasy POKER
	*/
	~POKER();
};

#endif // ! H_POKER