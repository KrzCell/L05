#include <iostream>
using namespace std;
#define ZadanieC 

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
	char tekst[] = "}(){";
	int liczniki[3] = {0,0,0};
	//Wyszukiwanie nawiasów:
	int dlugosc=sizeof(tekst)-1;
	int zamkniety[3] = {1,1,1};
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
		if (liczniki[0] < 0)
			zamkniety[0] = 0;
		if (liczniki[1] < 0)
			zamkniety[1] = 0;
		if (liczniki[2] < 0)
			zamkniety[2] = 0;
		
    }

	if (liczniki[0] == 0 || zamkniety[0] == 1)
		cout << "OK ()\n";
	else
		cout << "BLAD ()\n";

	if (liczniki[1] == 0 || zamkniety[1] == 1)
		cout << "OK []\n";
	else
		cout << "BLAD []\n";

	if (liczniki[2] == 0 || zamkniety[2] == 1)
		cout << "OK {}\n";
	else
		cout << "BLAD {}\n";
	


}
	

#endif

#ifdef ZadanieC
int main()
{
	constexpr int ROZMIAR_DANYCH = 100, ROZMIAR_KLUCZA = 4;
	constexpr int NAJWYZSZY_KOD_ZNAKU = 127;
	char tekstWe[ROZMIAR_DANYCH];
	char klucz[ROZMIAR_KLUCZA];
	char szyfr[ROZMIAR_DANYCH];
	char tekstWy[ROZMIAR_DANYCH];

	//Pobranie danych:
	cout << "Wiadomosc: ";
	fgets(tekstWe, ROZMIAR_DANYCH, stdin);
	cout << "Klucz szyfrujacy: ";
	fgets(klucz, ROZMIAR_KLUCZA, stdin);
	int i = 0, j = 0;

	//Szyfrowanie:
	while(tekstWe[i]!='\0')
	{
		if (j == 4)
		{
			szyfr[i] = (char)(((int)tekstWe[i] + (int)klucz[j]) % NAJWYZSZY_KOD_ZNAKU);
			j = 0;
		}
		else
			szyfr[i] = (char)(((int)tekstWe[i] + (int)klucz[j]) % NAJWYZSZY_KOD_ZNAKU);
		i++;
		j++;
 	}
	cout << "Szyfrogram: " << szyfr << endl;

	// Odszyfrowanie:
	while (tekstWe[i] != '\0')
	{
		if (j == 4)
		{
			tekstWy[i] = (char)(((int)szyfr[i] - (int)klucz[j]) % NAJWYZSZY_KOD_ZNAKU);
			j = 0;
		}
		else
			tekstWy[i] = (char)(((int)szyfr[i] - klucz[j]) % NAJWYZSZY_KOD_ZNAKU);
		i++;
		j++;
	}
	cout << "Wiadomosc: " << tekstWy << endl;
}
#endif

