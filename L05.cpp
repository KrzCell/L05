#include <iostream>

#define ZadanieA 

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
			int zm = tab[i][y];
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
	
}
#endif

#ifdef ZadanieC

#endif

