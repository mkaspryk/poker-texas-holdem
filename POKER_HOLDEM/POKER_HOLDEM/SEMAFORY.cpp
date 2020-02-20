#include "SEMAFORY.h"

SEMAFORY::SEMAFORY()
{
	this->semafor_ai = 0;
	this->x = 0;
}

int SEMAFORY::a_semafor_ai()
{
	return semafor_ai;
}

void SEMAFORY::zwieksz_x()
{
	this->x++;
}

void SEMAFORY::zeruj_x()
{
	this->x = 0;
}

int SEMAFORY::a_x()
{
	return x;
}

SEMAFORY &SEMAFORY::operator++()
{
	this->semafor_ai++;
	return *this;
}

SEMAFORY &SEMAFORY::operator--()
{
	this->semafor_ai--;
	return *this;
}

SEMAFORY &SEMAFORY::operator= (int i)
{
	this->semafor_ai = i;
	return *this;
}

SEMAFORY::~SEMAFORY()
{
}
