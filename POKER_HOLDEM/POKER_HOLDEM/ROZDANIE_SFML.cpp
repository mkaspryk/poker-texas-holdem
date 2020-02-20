#include "ROZDANIE_SFML.h"

ROZDANIE_SFML::ROZDANIE_SFML()
{
	SKarta1.setScale(0.15f, 0.15f);
	SKarta1.setPosition(850, 750);
	SKarta2.setScale(0.15f, 0.15f);
	SKarta2.setPosition(1000, 750);
	SKarta3.setScale(0.16f, 0.16f);
	SKarta3.setPosition(850, 100);
	SKarta4.setScale(0.16f, 0.16f);
	SKarta4.setPosition(1000, 100);
	SKarta5.setScale(0.15f, 0.15f);
	SKarta5.setPosition(650, 400);
	SKarta6.setScale(0.15f, 0.15f);
	SKarta6.setPosition(800, 400);
	SKarta7.setScale(0.15f, 0.15f);
	SKarta7.setPosition(950, 400);
	SKarta8.setScale(0.15f, 0.15f);
	SKarta8.setPosition(1100, 400);
	SKarta9.setScale(0.15f, 0.15f);
	SKarta9.setPosition(1250, 400);
}	

void ROZDANIE_SFML::nowe_rozdanie()
{
	KARTA NOWA;
	for (int i = 0; i < 9; i++)
	{
		ROZDANIE.push_back(NOWA);
		if (i < 7)
		{
			KARTY_GRACZ.push_back(NOWA);
			KARTY_AI.push_back(NOWA);
		}
	}
	TALIA_KART STlo;
	STlo.tasowanie();
	std::vector<KARTA> K;
	K = STlo.rozdaj_9();
	int x = 0;
	for (std::vector<KARTA>::iterator it = K.begin(); it != K.end(); ++it)
	{
		ROZDANIE[x] = *it;
		x++;
	}
	KARTY_GRACZ[0] = ROZDANIE[0];
	KARTY_GRACZ[1] = ROZDANIE[1];
	for (int i = 2; (i + 2) < 9; i++)
		KARTY_GRACZ[i] = ROZDANIE[i + 2];
	for (int i = 2; i < 9; i++)
		KARTY_AI[i - 2] = ROZDANIE[i];
}

std::vector<KARTA> ROZDANIE_SFML::a_gracz_karty()
{
	return KARTY_GRACZ;
}

std::vector<KARTA> ROZDANIE_SFML::a_ai_karty()
{
	return KARTY_AI;
}

void ROZDANIE_SFML::wczytanie_kart()
{
	for (int i = 0; i < 9; i++)
	{
		int k = ROZDANIE[i].a_kol();
		int w = ROZDANIE[i].a_war();
		if (k == 0)
		{
			if (w == 0)
			{
				try
				{
					if (!TKarty[i].loadFromFile("images/karty/2Karo.png"))
						exit(EXIT_FAILURE);
				}
				catch (std::exception&e)
				{
					std::cout << "Blad wczytania karty 2Karo.png" << e.what() << "\n";
				}
				catch (...)
				{
					std::cout << "Nieznany blad\n";
				}
			}
			else if (w == 1)
			{
				try
				{
					if (!TKarty[i].loadFromFile("images/karty/3Karo.png"))
						exit(EXIT_FAILURE);
				}
				catch (std::exception&e)
				{
					std::cout << "Blad wczytania karty 3Karo.png" << e.what() << "\n";
				}
				catch (...)
				{
					std::cout << "Nieznany blad\n";
				}

			}
			else if (w == 2)
			{
				try
				{
					if (!TKarty[i].loadFromFile("images/karty/4Karo.png"))
						exit(EXIT_FAILURE);
				}
				catch (std::exception&e)
				{
					std::cout << "Blad wczytania karty 4Karo.png" << e.what() << "\n";
				}
				catch (...)
				{
					std::cout << "Nieznany blad\n";
				}
			}
			else if (w == 3)
			{
				try
				{
					if (!TKarty[i].loadFromFile("images/karty/5Karo.png"))
						exit(EXIT_FAILURE);
				}
				catch (std::exception&e)
				{
					std::cout << "Blad wczytania karty 5Karo.png" << e.what() << "\n";
				}
				catch (...)
				{
					std::cout << "Nieznany blad\n";
				}
			}
			else if (w == 4)
			{
				try
				{
					if (!TKarty[i].loadFromFile("images/karty/6Karo.png"))
						exit(EXIT_FAILURE);
				}
				catch (std::exception&e)
				{
					std::cout << "Blad wczytania karty 6Karo.png" << e.what() << "\n";
				}
				catch (...)
				{
					std::cout << "Nieznany blad\n";
				}
			}
			else if (w == 5)
			{
				try
				{
					if (!TKarty[i].loadFromFile("images/karty/7Karo.png"))
						exit(EXIT_FAILURE);
				}
				catch (std::exception&e)
				{
					std::cout << "Blad wczytania karty 7Karo.png" << e.what() << "\n";
				}
				catch (...)
				{
					std::cout << "Nieznany blad\n";
				}
			}
			else if (w == 6)
			{
				try
				{
					if (!TKarty[i].loadFromFile("images/karty/8Karo.png"))
						exit(EXIT_FAILURE);
				}
				catch (std::exception&e)
				{
					std::cout << "Blad wczytania karty 8Karo.png" << e.what() << "\n";
				}
				catch (...)
				{
					std::cout << "Nieznany blad\n";
				}
			}
			else if (w == 7)
			{
				try
				{
					if (!TKarty[i].loadFromFile("images/karty/9Karo.png"))
						exit(EXIT_FAILURE);
				}
				catch (std::exception&e)
				{
					std::cout << "Blad wczytania karty 9Karo.png" << e.what() << "\n";
				}
				catch (...)
				{
					std::cout << "Nieznany blad\n";
				}
			}
			else if (w == 8)
			{
				try
				{
					if (!TKarty[i].loadFromFile("images/karty/10Karo.png"))
						exit(EXIT_FAILURE);
				}
				catch (std::exception&e)
				{
					std::cout << "Blad wczytania karty 10Karo.png" << e.what() << "\n";
				}
				catch (...)
				{
					std::cout << "Nieznany blad\n";
				}
			}
			else if (w == 9)
			{
				try
				{
					if (!TKarty[i].loadFromFile("images/karty/WaletKaro.png"))
						exit(EXIT_FAILURE);
				}
				catch (std::exception&e)
				{
					std::cout << "Blad wczytania karty WaletKaro.png" << e.what() << "\n";
				}
				catch (...)
				{
					std::cout << "Nieznany blad\n";
				}
			}
			else if (w == 10)
			{
				try
				{
					if (!TKarty[i].loadFromFile("images/karty/DamaKaro.png"))
						exit(EXIT_FAILURE);
				}
				catch (std::exception&e)
				{
					std::cout << "Blad wczytania karty DamaKaro.png" << e.what() << "\n";
				}
				catch (...)
				{
					std::cout << "Nieznany blad\n";
				}
			}
			else if (w == 11)
			{
				try
				{
					if (!TKarty[i].loadFromFile("images/karty/KrolKaro.png"))
						exit(EXIT_FAILURE);
				}
				catch (std::exception&e)
				{
					std::cout << "Blad wczytania karty KrolKaro.png" << e.what() << "\n";
				}
				catch (...)
				{
					std::cout << "Nieznany blad\n";
				}
			}
			else if (w == 12)
			{
				try
				{
					if (!TKarty[i].loadFromFile("images/karty/AsKaro.png"))
						exit(EXIT_FAILURE);
				}
				catch (std::exception&e)
				{
					std::cout << "Blad wczytania karty AsKaro.png" << e.what() << "\n";
				}
				catch (...)
				{
					std::cout << "Nieznany blad\n";
				}
			}
		}
		else if (k == 1)
		{
			if (w == 0)
			{
				try
				{
					if (!TKarty[i].loadFromFile("images/karty/2Trefl.png"))
						exit(EXIT_FAILURE);
				}
				catch (std::exception&e)
				{
					std::cout << "Blad wczytania karty 2Trefl.png" << e.what() << "\n";
				}
				catch (...)
				{
					std::cout << "Nieznany blad\n";
				}
			}
			else if (w == 1)
			{
				try
				{
					if (!TKarty[i].loadFromFile("images/karty/3Trefl.png"))
						exit(EXIT_FAILURE);
				}
				catch (std::exception&e)
				{
					std::cout << "Blad wczytania karty 3Trefl.png" << e.what() << "\n";
				}
				catch (...)
				{
					std::cout << "Nieznany blad\n";
				}
			}
			else if (w == 2)
			{
				try
				{
					if (!TKarty[i].loadFromFile("images/karty/4Trefl.png"))
						exit(EXIT_FAILURE);
				}
				catch (std::exception&e)
				{
					std::cout << "Blad wczytania karty 4Trefl.png" << e.what() << "\n";
				}
				catch (...)
				{
					std::cout << "Nieznany blad\n";
				}
			}
			else if (w == 3)
			{
				try
				{
					if (!TKarty[i].loadFromFile("images/karty/5Trefl.png"))
						exit(EXIT_FAILURE);
				}
				catch (std::exception&e)
				{
					std::cout << "Blad wczytania karty 5Trefl.png" << e.what() << "\n";
				}
				catch (...)
				{
					std::cout << "Nieznany blad\n";
				}
			}
			else if (w == 4)
			{
				try
				{
					if (!TKarty[i].loadFromFile("images/karty/6Trefl.png"))
						exit(EXIT_FAILURE);
				}
				catch (std::exception&e)
				{
					std::cout << "Blad wczytania karty 6Trefl.png" << e.what() << "\n";
				}
				catch (...)
				{
					std::cout << "Nieznany blad\n";
				}
			}
			else if (w == 5)
			{
				try
				{
					if (!TKarty[i].loadFromFile("images/karty/7Trefl.png"))
						exit(EXIT_FAILURE);
				}
				catch (std::exception&e)
				{
					std::cout << "Blad wczytania karty 7Trefl.png" << e.what() << "\n";
				}
				catch (...)
				{
					std::cout << "Nieznany blad\n";
				}
			}
			else if (w == 6)
			{
				try
				{
					if (!TKarty[i].loadFromFile("images/karty/8Trefl.png"))
						exit(EXIT_FAILURE);
				}
				catch (std::exception&e)
				{
					std::cout << "Blad wczytania karty 8Trefl.png" << e.what() << "\n";
				}
				catch (...)
				{
					std::cout << "Nieznany blad\n";
				}
			}
			else if (w == 7)
			{
				try
				{
					if (!TKarty[i].loadFromFile("images/karty/9Trefl.png"))
						exit(EXIT_FAILURE);
				}
				catch (std::exception&e)
				{
					std::cout << "Blad wczytania karty 9Trefl.png" << e.what() << "\n";
				}
				catch (...)
				{
					std::cout << "Nieznany blad\n";
				}
			}
			else if (w == 8)
			{
				try
				{
					if (!TKarty[i].loadFromFile("images/karty/10Trefl.png"))
						exit(EXIT_FAILURE);
				}
				catch (std::exception&e)
				{
					std::cout << "Blad wczytania karty 10Trefl.png" << e.what() << "\n";
				}
				catch (...)
				{
					std::cout << "Nieznany blad\n";
				}
			}
			else if (w == 9)
			{
				try
				{
					if (!TKarty[i].loadFromFile("images/karty/WaletTrefl.png"))
						exit(EXIT_FAILURE);
				}
				catch (std::exception&e)
				{
					std::cout << "Blad wczytania karty WaletTrefl.png" << e.what() << "\n";
				}
				catch (...)
				{
					std::cout << "Nieznany blad\n";
				}
			}
			else if (w == 10)
			{
				try
				{
					if (!TKarty[i].loadFromFile("images/karty/DamaTrefl.png"))
						exit(EXIT_FAILURE);
				}
				catch (std::exception&e)
				{
					std::cout << "Blad wczytania karty DamaTrefl.png" << e.what() << "\n";
				}
				catch (...)
				{
					std::cout << "Nieznany blad\n";
				}
			}
			else if (w == 11)
			{
				try
				{
					if (!TKarty[i].loadFromFile("images/karty/KrolTrefl.png"))
						exit(EXIT_FAILURE);
				}
				catch (std::exception&e)
				{
					std::cout << "Blad wczytania karty KrolTrefl.png" << e.what() << "\n";
				}
				catch (...)
				{
					std::cout << "Nieznany blad\n";
				}
			}
			else if (w == 12)
			{
				try
				{
					if (!TKarty[i].loadFromFile("images/karty/AsTrefl.png"))
						exit(EXIT_FAILURE);
				}
				catch (std::exception&e)
				{
					std::cout << "Blad wczytania karty AsTrefl.png" << e.what() << "\n";
				}
				catch (...)
				{
					std::cout << "Nieznany blad\n";
				}
			}
		}
		else if (k == 2)
		{
			if (w == 0)
			{
				try
				{
					if (!TKarty[i].loadFromFile("images/karty/2Kier.png"))
						exit(EXIT_FAILURE);
				}
				catch (std::exception&e)
				{
					std::cout << "Blad wczytania karty 2Kier.png" << e.what() << "\n";
				}
				catch (...)
				{
					std::cout << "Nieznany blad\n";
				}
			}
			else if (w == 1)
			{
				try
				{
					if (!TKarty[i].loadFromFile("images/karty/3Kier.png"))
						exit(EXIT_FAILURE);
				}
				catch (std::exception&e)
				{
					std::cout << "Blad wczytania karty 3Kier.png" << e.what() << "\n";
				}
				catch (...)
				{
					std::cout << "Nieznany blad\n";
				}
			}
			else if (w == 2)
			{
				try
				{
					if (!TKarty[i].loadFromFile("images/karty/4Kier.png"))
						exit(EXIT_FAILURE);
				}
				catch (std::exception&e)
				{
					std::cout << "Blad wczytania karty 4Kier.png" << e.what() << "\n";
				}
				catch (...)
				{
					std::cout << "Nieznany blad\n";
				}	
			}
			else if (w == 3)
			{
				try
				{
					if (!TKarty[i].loadFromFile("images/karty/5Kier.png"))
						exit(EXIT_FAILURE);
				}
				catch (std::exception&e)
				{
					std::cout << "Blad wczytania karty 5Kier.png" << e.what() << "\n";
				}
				catch (...)
				{
					std::cout << "Nieznany blad\n";
				}
			}
			else if (w == 4)
			{
				try
				{
					if (!TKarty[i].loadFromFile("images/karty/6Kier.png"))
						exit(EXIT_FAILURE);
				}
				catch (std::exception&e)
				{
					std::cout << "Blad wczytania karty 6Kier.png" << e.what() << "\n";
				}
				catch (...)
				{
					std::cout << "Nieznany blad\n";
				}
			}
			else if (w == 5)
			{
				try
				{
					if (!TKarty[i].loadFromFile("images/karty/7Kier.png"))
						exit(EXIT_FAILURE);
				}
				catch (std::exception&e)
				{
					std::cout << "Blad wczytania karty 7Kier.png" << e.what() << "\n";
				}
				catch (...)
				{
					std::cout << "Nieznany blad\n";
				}
			}
			else if (w == 6)
			{
				try
				{
					if (!TKarty[i].loadFromFile("images/karty/8Kier.png"))
						exit(EXIT_FAILURE);
				}
				catch (std::exception&e)
				{
					std::cout << "Blad wczytania karty 8Kier.png" << e.what() << "\n";
				}
				catch (...)
				{
					std::cout << "Nieznany blad\n";
				}
			}
			else if (w == 7)
			{
				try
				{
					if (!TKarty[i].loadFromFile("images/karty/9Kier.png"))
						exit(EXIT_FAILURE);
				}
				catch (std::exception&e)
				{
					std::cout << "Blad wczytania karty 9Kier.png" << e.what() << "\n";
				}
				catch (...)
				{
					std::cout << "Nieznany blad\n";
				}
			}
			else if (w == 8)
			{
				try
				{
					if (!TKarty[i].loadFromFile("images/karty/10Kier.png"))
						exit(EXIT_FAILURE);
				}
				catch (std::exception&e)
				{
					std::cout << "Blad wczytania karty 10Kier.png" << e.what() << "\n";
				}
				catch (...)
				{
					std::cout << "Nieznany blad\n";
				}
			}
			else if (w == 9)
			{
				try
				{
					if (!TKarty[i].loadFromFile("images/karty/WaletKier.png"))
						exit(EXIT_FAILURE);
				}
				catch (std::exception&e)
				{
					std::cout << "Blad wczytania karty WaletKier.png" << e.what() << "\n";
				}
				catch (...)
				{
					std::cout << "Nieznany blad\n";
				}
			}
			else if (w == 10)
			{
				try
				{
					if (!TKarty[i].loadFromFile("images/karty/DamaKier.png"))
						exit(EXIT_FAILURE);
				}
				catch (std::exception&e)
				{
					std::cout << "Blad wczytania karty DamaKier.png" << e.what() << "\n";
				}
				catch (...)
				{
					std::cout << "Nieznany blad\n";
				}
			}
			else if (w == 11)
			{
				try
				{
					if (!TKarty[i].loadFromFile("images/karty/KrolKier.png"))
						exit(EXIT_FAILURE);
				}
				catch (std::exception&e)
				{
					std::cout << "Blad wczytania karty KrolKier.png" << e.what() << "\n";
				}
				catch (...)
				{
					std::cout << "Nieznany blad\n";
				}
			}
			else if (w == 12)
			{
				try
				{
					if (!TKarty[i].loadFromFile("images/karty/AsKier.png"))
						exit(EXIT_FAILURE);
				}
				catch (std::exception&e)
				{
					std::cout << "Blad wczytania karty AsKier.png" << e.what() << "\n";
				}
				catch (...)
				{
					std::cout << "Nieznany blad\n";
				}
			}
		}
		else if (k == 3)
		{
			if (w == 0)
			{
				try
				{
					if (!TKarty[i].loadFromFile("images/karty/2Pik.png"))
						exit(EXIT_FAILURE);
				}
				catch (std::exception&e)
				{
					std::cout << "Blad wczytania karty 2Pik.png" << e.what() << "\n";
				}
				catch (...)
				{
					std::cout << "Nieznany blad\n";
				}
			}
			else if (w == 1)
			{
				try
				{
					if (!TKarty[i].loadFromFile("images/karty/3Pik.png"))
						exit(EXIT_FAILURE);
				}
				catch (std::exception&e)
				{
					std::cout << "Blad wczytania karty 3Pik.png" << e.what() << "\n";
				}
				catch (...)
				{
					std::cout << "Nieznany blad\n";
				}
			}
			else if (w == 2)
			{
				try
				{
					if (!TKarty[i].loadFromFile("images/karty/4Pik.png"))
						exit(EXIT_FAILURE);
				}
				catch (std::exception&e)
				{
					std::cout << "Blad wczytania karty 4Pik.png" << e.what() << "\n";
				}
				catch (...)
				{
					std::cout << "Nieznany blad\n";
				}	
			}
			else if (w == 3)
			{
				try
				{
					if (!TKarty[i].loadFromFile("images/karty/5Pik.png"))
						exit(EXIT_FAILURE);
				}
				catch (std::exception&e)
				{
					std::cout << "Blad wczytania karty 5Pik.png" << e.what() << "\n";
				}
				catch (...)
				{
					std::cout << "Nieznany blad\n";
				}
			}
			else if (w == 4)
			{
				try
				{
					if (!TKarty[i].loadFromFile("images/karty/6Pik.png"))
						exit(EXIT_FAILURE);
				}
				catch (std::exception&e)
				{
					std::cout << "Blad wczytania karty 6Pik.png" << e.what() << "\n";
				}
				catch (...)
				{
					std::cout << "Nieznany blad\n";
				}
			}
			else if (w == 5)
			{
				try
				{
					if (!TKarty[i].loadFromFile("images/karty/7Pik.png"))
						exit(EXIT_FAILURE);
				}
				catch (std::exception&e)
				{
					std::cout << "Blad wczytania karty 7Pik.png" << e.what() << "\n";
				}
				catch (...)
				{
					std::cout << "Nieznany blad\n";
				}	
			}
			else if (w == 6)
			{
				try
				{
					if (!TKarty[i].loadFromFile("images/karty/8Pik.png"))
						exit(EXIT_FAILURE);
				}
				catch (std::exception&e)
				{
					std::cout << "Blad wczytania karty 8Pik.png" << e.what() << "\n";
				}
				catch (...)
				{
					std::cout << "Nieznany blad\n";
				}
			}
			else if (w == 7)
			{
				try
				{
					if (!TKarty[i].loadFromFile("images/karty/9Pik.png"))
						exit(EXIT_FAILURE);
				}
				catch (std::exception&e)
				{
					std::cout << "Blad wczytania karty 9Pik.png" << e.what() << "\n";
				}
				catch (...)
				{
					std::cout << "Nieznany blad\n";
				}
			}
			else if (w == 8)
			{
				try
				{
					if (!TKarty[i].loadFromFile("images/karty/10Pik.png"))
						exit(EXIT_FAILURE);
				}
				catch (std::exception&e)
				{
					std::cout << "Blad wczytania karty 10Pik.png" << e.what() << "\n";
				}
				catch (...)
				{
					std::cout << "Nieznany blad\n";
				}
			}
			else if (w == 9)
			{
				try
				{
					if (!TKarty[i].loadFromFile("images/karty/WaletPik.png"))
						exit(EXIT_FAILURE);
				}
				catch (std::exception&e)
				{
					std::cout << "Blad wczytania karty WaletPik.png" << e.what() << "\n";
				}
				catch (...)
				{
					std::cout << "Nieznany blad\n";
				}
			}
			else if (w == 10)
			{
				try
				{
					if (!TKarty[i].loadFromFile("images/karty/DamaPik.png"))
						exit(EXIT_FAILURE);
				}
				catch (std::exception&e)
				{
					std::cout << "Blad wczytania karty DamaPik.png" << e.what() << "\n";
				}
				catch (...)
				{
					std::cout << "Nieznany blad\n";
				}
			}
			else if (w == 11)
			{
				try
				{
					if (!TKarty[i].loadFromFile("images/karty/KrolPik.png"))
						exit(EXIT_FAILURE);
				}
				catch (std::exception&e)
				{
					std::cout << "Blad wczytania karty KrolPik.png" << e.what() << "\n";
				}
				catch (...)
				{
					std::cout << "Nieznany blad\n";
				}
			}
			else if (w == 12)
			{
				try
				{
					if (!TKarty[i].loadFromFile("images/karty/AsPik.png"))
						exit(EXIT_FAILURE);
				}
				catch (std::exception&e)
				{
					std::cout << "Blad wczytania karty AsPik.png" << e.what() << "\n";
				}
				catch (...)
				{
					std::cout << "Nieznany blad\n";
				}
			}
		}
		switch (i)
		{
		case 0:
			SKarta1.setTexture(this->TKarty[i]);
			break;
		case 1:
			SKarta2.setTexture(this->TKarty[i]);
			break;
		case 2:
			SKarta3.setTexture(this->TKarty[i]);
			break;
		case 3:
			SKarta4.setTexture(this->TKarty[i]);
			break;
		case 4:
			SKarta5.setTexture(this->TKarty[i]);
			break;
		case 5:
			SKarta6.setTexture(this->TKarty[i]);
			break;
		case 6:
			SKarta7.setTexture(this->TKarty[i]);
			break;
		case 7:
			SKarta8.setTexture(this->TKarty[i]);
			break;
		case 8:
			SKarta9.setTexture(this->TKarty[i]);
			break;
		default:
			break;
		}
	}
}

void ROZDANIE_SFML::rysuj_karty_gracz(sf::RenderWindow &app)
{
	app.draw(SKarta1);
	app.draw(SKarta2);
}

void ROZDANIE_SFML::rysuj_karty_przeciwnik(sf::RenderWindow &app)
{
	app.draw(SKarta3);
	app.draw(SKarta4);
}

void ROZDANIE_SFML::rysuj_flop(sf::RenderWindow &app)
{
	app.draw(SKarta5);
	app.draw(SKarta6);
	app.draw(SKarta7);
}

void ROZDANIE_SFML::rysuj_turn(sf::RenderWindow &app)
{
	app.draw(SKarta8);
}

void ROZDANIE_SFML::rysuj_river(sf::RenderWindow &app)
{
	app.draw(SKarta9);
}

ROZDANIE_SFML::~ROZDANIE_SFML()
{
}
