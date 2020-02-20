#include "KARTA.h"

KARTA::KARTA()
{
}

KARTA::KARTA(int wartosc1, int kolor1) :wartosc(wartosc1), kolor(kolor1)
{
}

int KARTA::a_war() { return wartosc; }

int KARTA::a_kol() { return kolor; }

KARTA::~KARTA()
{
}
