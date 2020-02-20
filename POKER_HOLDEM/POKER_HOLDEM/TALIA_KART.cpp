#include "TALIA_KART.h"

TALIA_KART::TALIA_KART()
{
	int wartosc[] = { 12,11,10,9,8,7,6,5,4,3,2,1,0 };
	int kolor[] = { 3,2,1,0 };
	TALIA = new KARTA[LICZBA_KART];
	ktoraKARTA = 0;
	for (int i = 0; i < LICZBA_KART; i++)
	{
		TALIA[i] = KARTA(wartosc[i % 13], kolor[i / 13]);
	}
}

void TALIA_KART::tasowanie()
{
	ktoraKARTA = 0;
	for (int pierwsza = 0; pierwsza < LICZBA_KART; pierwsza++)
	{
		int druga = (rand() + time(NULL)) % LICZBA_KART;
		KARTA pom = TALIA[pierwsza];
		TALIA[pierwsza] = TALIA[druga];
		TALIA[druga] = pom;
	}
}

std::vector<KARTA> TALIA_KART::rozdaj_9()
{
	std::vector<KARTA> K;
	for (int i = 0; i < 9; i++)
	{
		K.push_back(this->rozdaj_karte());
	}
	return K;
}

KARTA TALIA_KART::rozdaj_karte()
{
	if (ktoraKARTA > LICZBA_KART)
		tasowanie();
	if (ktoraKARTA < LICZBA_KART)
		return TALIA[ktoraKARTA++];
	return TALIA[0];
}

TALIA_KART::~TALIA_KART()
{
	delete[]TALIA;
}
