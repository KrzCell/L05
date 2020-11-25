#include <iostream>

#define ZadanieA 

#ifdef ZadanieA

using namespace std;

int main(void)
{
	constexpr int SIZE = 5;
	int tab[SIZE][SIZE] = {};
	int i;

	// Element początkowy:
	int w = 0, k = SIZE/2;
	tab[w][k] = 1;

	//Następne elementy:
	for (i = 0; i < SIZE * SIZE; i++)
	{
		//Przesuń współrzędne
		w ++, k --;
		//Sprawdź i skoryguj naruszenie granic tablicy:
		if (w < 0)
			w += SIZE;
		if (k >= SIZE)
			k -= SIZE;
		//Sprawdź, czy element tablicy był już zapisany:
		if (tab[w][k] != 0)
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

}
#endif

#ifdef ZadanieB
int main()
{
	// TU ROZWIĄZUJ ZADANIE B:
}
#endif

#ifdef ZadanieC

#endif

