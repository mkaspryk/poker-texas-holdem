#include "STAWKI.h"

STAWKI::STAWKI()
{
	small_blind = 10;
	big_blind = 20;
}

int STAWKI::a_small_blind()
{
	return small_blind;
}

int STAWKI::a_big_blind()
{
	return big_blind;
}

void STAWKI::ustaw_stawki()
{
	small_blind = 10;
	big_blind = 20;
}

void STAWKI::zwiekszanie()
{
	small_blind = 2 * small_blind;
	big_blind = 2 * big_blind;
}

STAWKI::~STAWKI()
{
}
