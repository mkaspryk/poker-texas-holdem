//____________________________________________________________________________________________________
//****************************************************************************************************
//******************                                                           ***********************
//****************** INTERFEJS GRAFICZNY DLA GRACZA(AI i PLAYER) + POLA GRACZA ***********************
//******************                                                           ***********************
//****************************************************************************************************
//____________________________________________________________________________________________________


#ifndef H_GRACZ
#define H_GRACZ
#include <SFML\Graphics.hpp>
#include <iostream>
#include <string.h>
#include <sstream>
#include "KARTA.h"

/*!
Klasa reprezentujca danego gracza dostarcza informacje o kwotach i o tym kto jest dealer
*/
class GRACZ 
{
	//___________________________________________ POLA _______________________________________________

	int numer;                // numer gracza (numerem jeden jest u¿ytkownik)
	int kwota;                // suma nale¿¹ca do gracza
	bool gra;                 // jeœli jest w grze to true innaczej false
	bool dealer;              // czy jest dealerem

	// __________________________________________ SFML _______________________________________________

	sf::Texture TDealer;                                               // zmienna do wczytania tekstury
	sf::Sprite SDealer1,SDealer2;                                      // zmienne wypisujace tekstury
	sf::Text TCashName,TWinName,TLossName,TDrawName;                   // zmienna do wyswietlania kwoty
	sf::Font Ffont1,Ffont2;                                            // czcionki

	//________________________________________________________________________________________________
public:

	/*!
	Konstruktor bezargumentowy klasy GRACZ
	*/
	GRACZ();

	/*!
	Metoda inicjalizujaca nowa gre
	*/
	void poczatek(int numer1,int kwota1,bool dealer1);

	/*!
	Metoda zmieniajaca stan gracza, ktory byl w grze na false (poza gra)
	*/
	inline void koniec_gry() { gra = false; }

	/*!
	Metoda rysujaca zeton dealer ze wzgledu na runde
	*/
	void rysuj_dealer(sf::RenderWindow &app, int i);

	/*! 
	Metoda zmieniajaca dealera po kazdej rundzie
	*/
	void zmien_dealera();

	/*!
	Metoda pobierajaca od gracza kwote
	*/
	void pobierz(int ile);

	/*! 
	Metoda rysujaca kwote dla danego gracza
	*/
	void rysuj_kwote(sf::RenderWindow &app);

	/*!
	Metoda uaktualniajaca kwote dla danego gracza
	*/
	void uaktualnij_kwote();

	/*!
	Akcesor do numeru gracza
	*/
	int a_numer() { return numer; }
	
	/*!
	Akcesor do kwoty gracza
	*/
	int a_kwota() { return kwota; }
	
	/*
	Akcesor do wartosci gra okreslajacej czy dany gracz jest w grze
	*/
	bool a_gra() { return gra; }
	
	/*!
	Akcesor do wartosci dealer okreslajacej kto jest dealerem 
	*/
	bool a_dealer() { return dealer; }
	
	/*!
	Metoda zamieniajca wartosc pola gra na false z true
	*/
	void podanie();
	
	/*!
	Metoda rysujaca wygrana
	*/
	void rysuj_wygrana(sf::RenderWindow &app);

	/*!
	Metoda rysujaca przegrana
	*/
	void rysuj_przegrana(sf::RenderWindow &app);

	/*!
	Metoda rysujaca remis 
	*/
	void rysuj_remis(sf::RenderWindow &app);

	/*!
	Metoda dodajaca kwote dla danego gracza
	*/
	void dodaj_kwote(int ile);

	~GRACZ();
};

#endif