#include <iostream>

#define ZadanieA 

#ifdef ZadanieA

using namespace std;

int main(void)
{
	constexpr int SIZE = 5;
	int tab[SIZE][SIZE] = {};

	// Element początkowy:
	int w = 0, k = SIZE / 2;
	tab[w][k] = 1;

	//Następne elementy:
	for (int n = 2; n < SIZE * SIZE; n += 1)
	{
		//Przesuń współrzędne
		w -= 1; k += 1;
		//Sprawdź i skoryguj naruszenie granic tablicy:
		if (w <= 0)
			w += SIZE;
		if (k >= SIZE)
			k -= SIZE;
		//Sprawdź, czy element tablicy był już zapisany:
		if (tab[w][k] != 0)
		{
			//Przesuń współrzędne i sprawdź granice:
			w += 1;
			if (w >= SIZE)
				w -= SIZE;
		}
		//Zapisz element:
		tab[w][k] = n;
	}

	//Wyświetl tablicę:
	for (int x = 0; x < SIZE; x += 1)
	{
		for (int y = 0; y < SIZE; y += 1)
		{
			cout << y << "\t";
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

