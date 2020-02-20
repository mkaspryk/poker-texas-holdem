#include "UKLAD_KART.h"

UKLAD_KART::UKLAD_KART() {};

template <typename T>
UKLAD_KART::UKLAD_KART(T w1, T rank1, T rank2, std::vector<KARTA> TALIA1) :w(w1), rank(rank1), rank2(rank2), TALIA(TALIA1)
{
}

KARTA UKLAD_KART::akcesor_talia(int i)
{
	return this->TALIA[i];
}

void UKLAD_KART::sortuj()
{
	for (int i = 0; i < 7; i++)
		for (int j = 1; j < 7 - i; j++)
			if (this->TALIA[j - 1].a_war() > this->TALIA[j].a_war())
				std::swap(TALIA[j - 1], TALIA[j]);
}

int UKLAD_KART::wygrana(UKLAD_KART G1, UKLAD_KART G2)
{
	if (G1.rank > G2.rank)
		return 1;
	else if (G1.rank < G2.rank)
		return 2;
	else
		return 0;
}

int UKLAD_KART::wygrana2(UKLAD_KART G1, UKLAD_KART G2)
{
	if (G1.rank2 > G2.rank2)
		return 1;
	else if (G1.rank2 < G2.rank2)
		return 2;
	else
		return 0;
}

void UKLAD_KART::odfiltrowanie()
{
	int x = 0;
	for (int i = 0; i < 6; i++)
	{
		if (this->TALIA[i].a_war() == rank || this->TALIA[i].a_war() == rank2)
		{
			std::swap(this->TALIA[i], this->TALIA[x]);
			x++;
		}
	}
}

int UKLAD_KART::sprawdzenie(std::vector<KARTA> T1, std::vector<KARTA> T2)
{
	UKLAD_KART G1(0, -1, -1, T1);
	UKLAD_KART G2(0, -1, -1, T2);
	G1.sortuj();
	G2.sortuj();
	// poker
	G1.poker();
	G2.poker();
	if (G1.rank != -1 || G2.rank != -1)
		return this->w = wygrana(G1, G2);
	// kareta
	int k;
	G1.kareta();
	G2.kareta();
	if (G1.rank != -1 || G2.rank != -1)
	{
		this->w = wygrana(G1, G2);
		if (w == 0)
		{
			G1.odfiltrowanie();
			G2.odfiltrowanie();
			k = 6;
			while (G1.najwyzsza(k) == G2.najwyzsza(k))
			{
				k--;
				if (k == 5)
					break;
			}
			this->w = wygrana(G1, G2);
		}
		return this->w;
	}
	// full
	std::pair<int, int> p1 = G1.full();
	std::pair<int, int> p2 = G2.full();
	if (p1.first != -1 && p1.second != -1 || p2.first != -1 && p2.second != -1)
	{
		this->w = wygrana(G1, G2);
		if (this->w == 0)
			return this->w = wygrana2(G1, G2);
		return this->w;
	}
	// kolor
	G1.kolor();
	G2.kolor();
	if (G1.rank != -1 || G2.rank != -1)
		return this->w = wygrana(G1, G2);
	//strit
	G1.strit();
	G2.strit();
	if (G1.rank != -1 || G2.rank != -1)
		return this->w = wygrana(G1, G2);
	// trojka
	G1.trojka();
	G2.trojka();
	if (G1.rank != -1 || G2.rank != -1)
	{
		this->w = wygrana(G1, G2);
		if (this->w == 0)
		{
			G1.odfiltrowanie();
			G2.odfiltrowanie();
			k = 6;
			while (G1.najwyzsza(k) == G2.najwyzsza(k))
			{
				k--;
				if (k == 4)
					break;
			}
			this->w = wygrana(G1, G2);
		}
		return this->w;
	}
	// dwie pary
	std::pair<int, int> p3 = G1.dwie_pary();
	std::pair<int, int> p4 = G2.dwie_pary();
	if (p3.first != -1 && p3.second != -1 || p4.first != -1 && p4.second != -1)
	{
		this->w = wygrana(G1, G2);
		if (this->w == 0)
		{
			this->w = wygrana2(G1, G2);
			if (this->w == 0)
			{
				G1.odfiltrowanie();
				G2.odfiltrowanie();
				G1.najwyzsza(6);
				G2.najwyzsza(6);
				this->w = wygrana(G1, G2);
			}
		}
		return this->w;
	}
	// jedna para
	G1.jedna_para();
	G2.jedna_para();
	if (G1.rank != G2.rank)
	{
		this->w = wygrana(G1, G2);
		if (G1.rank == G2.rank)
		{
			G1.odfiltrowanie();
			G2.odfiltrowanie();
			k = 6;
			while (G1.najwyzsza(k) == G2.najwyzsza(k))
			{
				k--;
				if (k == 3)
					break;
			}
			this->w = wygrana(G1, G2);
		}
		return this->w;
	}
	// najwy¿sza karta
	k = 6;
	while (G1.najwyzsza(k) == G2.najwyzsza(k))
	{
		k--;
		if (k == 1)
			break;
	}
	if (G1.rank != G2.rank)
		return this->w = wygrana(G1, G2);
	return 0;
}

int UKLAD_KART::najwyzsza(int k)
{
	return this->rank = this->TALIA[k].a_war();
}

int UKLAD_KART::jedna_para()
{
	this->rank = -1;
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
			if (i != j)
			{
				if (TALIA[i].a_war() == TALIA[j].a_war())
					if (TALIA[i].a_war() > this->rank)
						this->rank = TALIA[i].a_war();
			}
	}
	return this->rank;
}

std::pair<int, int> UKLAD_KART::dwie_pary()
{
	std::pair<int, int> STlo;
	this->rank = jedna_para();
	this->rank2 = -1;
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
			if (i != j)
			{
				if (this->TALIA[i].a_war() != this->rank && this->TALIA[j].a_war() != this->rank)
					if (this->TALIA[i].a_war() == this->TALIA[j].a_war())
						this->rank2 = this->TALIA[i].a_war();
			}
	}
	STlo = std::make_pair(this->rank, this->rank2);
	return STlo;
}

int UKLAD_KART::trojka()
{
	this->rank = -1;
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
			for (int k = 0; k < 7; k++)
				if (i != j && i != k && j != k)
				{
					if (this->TALIA[i].a_war() == this->TALIA[j].a_war() && this->TALIA[i].a_war() == this->TALIA[k].a_war())
						this->rank = this->TALIA[i].a_war();
				}
	}
	return this->rank;
}

int UKLAD_KART::strit()
{
	this->rank = -1;
	int ile = 0;
	for (int i = 0; i < 6; i++)
		if (this->TALIA[i].a_war() == this->TALIA[i + 1].a_war() - 1)
		{
			if (ile == 0)
				ile += 2;
			else
				ile++;
			if (ile >= 5)
				this->rank = this->TALIA[i + 1].a_war();
		}
		else if (this->TALIA[i].a_war() == this->TALIA[i + 1].a_war())
			std::swap(this->TALIA[i], this->TALIA[i + 1]);
		else
			ile = 0;
	return this->rank;
}

int UKLAD_KART::kolor()
{
	this->rank = -1;
	int ile = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (i == this->TALIA[j].a_kol())
			{
				ile++;
				if (ile >= 5)
				{
					this->rank = this->TALIA[j].a_war();
					this->rank2 = i;
				}
			}
		}
		ile = 0;
	}
	return this->rank;
}

std::pair<int, int> UKLAD_KART::full()
{
	this->rank = trojka();
	this->rank2 = -1;
	std::pair<int, int> STlo;
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
			if (i != j)
			{
				if (this->TALIA[i].a_war() != this->rank && this->TALIA[j].a_war() != this->rank)
					if (this->TALIA[i].a_war() == this->TALIA[j].a_war())
						this->rank2 = this->TALIA[i].a_war();
			}
	}
	STlo = std::make_pair(this->rank, this->rank2);
	if (this->rank != -1 && this->rank2 != -1)
		return STlo;
	else
	{
		STlo = std::make_pair(-1, -1);
		return STlo;
	}
}

int UKLAD_KART::kareta()
{
	this->rank = -1;
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			for (int k = 0; k < 7; k++)
			{
				for (int m = 0; m < 7; m++)
				{
					if (i != j && i != k && i != m && j != k && j != m && k != m)
					{
						if (this->TALIA[i].a_war() == this->TALIA[j].a_war() && this->TALIA[i].a_war() == this->TALIA[k].a_war() && this->TALIA[i].a_war() == this->TALIA[m].a_war())
						{
							this->rank = this->TALIA[i].a_war();
						}
					}
				}
			}
		}
	}
	return this->rank;
}

int UKLAD_KART::poker()
{
	this->rank = -1;
	int ile = 0;
	kolor();
	for (int i = 0; i < 6; i++)
	{
		if (this->TALIA[i].a_kol() == this->rank2)
		{
			if (this->TALIA[i].a_war() == this->TALIA[i + 1].a_war() - 1)
			{
				if (ile == 0)
					ile += 2;
				else
					ile++;
				if (ile >= 5)
					this->rank = this->TALIA[i + 1].a_war();
			}
			else if (this->TALIA[i].a_war() == this->TALIA[i + 1].a_war())
				std::swap(this->TALIA[i], this->TALIA[i + 1]);
			else
				ile = 0;
		}
	}
	return this->rank;
}

UKLAD_KART::~UKLAD_KART()
{
}
