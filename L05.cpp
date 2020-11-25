#include <iostream>
using namespace std;
#define ZadanieB 

#ifdef ZadanieA

using namespace std;

int main(void)
{
	constexpr int SIZE = 5;
	int tab[SIZE][SIZE] = {};
	int i;
	bool tab2[SIZE * SIZE + 1] = {};
	bool rozne = true;

	// Element początkowy:
	int w = 0, k = SIZE/2;
	tab[w][k] = 1;

	//Następne elementy:
	for (i = 2; i <= SIZE * SIZE; i++)
	{
		//Przesuń współrzędne
		w --, k ++;
		//Sprawdź i skoryguj naruszenie granic tablicy:
		if (w < 0)
			w += SIZE;
		if (k >= SIZE)
			k -= SIZE;
		//Sprawdź, czy element tablicy był już zapisany:
		if (tab[w][k])
		{
			//Przesuń współrzędne i sprawdź granice:
			w += 2;
			k--;
			if (k < 0)
				k += SIZE;
			if (w >= SIZE)
				w -= SIZE;
		}
		//Zapisz element:
		tab[w][k] = i;
	}

	//Wyświetl tablicę:
	for (i = 0; i < SIZE; i += 1)
	{
		for (int y = 0; y < SIZE; y += 1)
		{
			cout << tab[i][y] << "\t";
		}
		cout << endl;
	}

	for (i = 0; i < SIZE; i += 1)
	{
		for (int y = 0; y < SIZE; y += 1)
		{
			int zm = tab[i][y]; //sprawdzanie czy sa 2 takie same wartosci
			if (tab2[zm])
				rozne = false;
			else
				tab2[zm] = true;

		}
		
	}
	if (rozne)
		cout << "Liczby nie powtarzaja sie" << endl;
	else
		cout << "Liczby powtarzaja sie" << endl;

}
#endif

#ifdef ZadanieB
int main()
{
	//Tekst do przeszukania:
	char tekst[] = "}()";
	int liczniki[3] = {0,0,0};
	//Wyszukiwanie nawiasów:
	int dlugosc=sizeof(tekst)-1;
	bool zamkniety = true;
	for (int j = 0; j < dlugosc; j++)
	{
		switch (tekst[j])
		{
		case '(':
			liczniki[0] ++;
			break;
		case ')':
			liczniki[0] --;
			break;
		case '[':
			liczniki[1] ++;
			break;
		case ']':
			liczniki[1] --;
			break;
		case '{':
			liczniki[2] ++;
			break;
		case '}':
			liczniki[2] --;
			break;
		default:
			break;
		}
		if (liczniki[0] < 0 || liczniki[1] < 0 || liczniki[2] < 0)
			zamkniety = false;
		else
			zamkniety = true;
		
    }

	if (liczniki[0] == 0)
		cout << "OK ()\n";
	else
		cout << "BLAD ()\n";

	if (liczniki[1] == 0)
		cout << "OK []\n";
	else
		cout << "BLAD []\n";

	if (liczniki[2] == 0)
		cout << "OK {}\n";
	else
		cout << "BLAD {}\n";
}
	

#endif

#ifdef ZadanieC

#endif

