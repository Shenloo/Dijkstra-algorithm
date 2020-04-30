#include <iostream>
#include<fstream>
#include<string>
#include<ctime>
#include<cstdlib>
#include"Krawedz.h"
#include"Wierzcholek.h"
#include"Lista.h"
#include"Kolejka.h"
#include"GrafLista.h"
#include"GrafMacierz.h"
#include"Dijkstra.h"

using namespace std;

int main()
{
	int poprzedni, nastepny, waga;
	int liczba_wierzcholkow, liczba_krawedzi, wierzcholek_startowy;
	GrafLista* GL = new GrafLista;
	GrafMacierz* GM = new GrafMacierz;
	
	ifstream strumien;
	strumien.open("graf10_25.txt");

	if (strumien.good() == false)
	{
		cout << "Nie wczytano pliku" << endl;
		return 0;
	}

	strumien >> liczba_wierzcholkow >> liczba_krawedzi >> wierzcholek_startowy;

	Wierzcholek<Krawedz>** w1 = new Wierzcholek<Krawedz>  *[liczba_wierzcholkow];
	Wierzcholek<Krawedz>** w2 = new Wierzcholek<Krawedz> * [liczba_wierzcholkow];

	for (int i = 0; i < liczba_wierzcholkow; ++i)
	{
		w2[i] = new Wierzcholek<Krawedz>;
		w1[i] = new Wierzcholek<Krawedz>;
	}
		

	for (int i = 0; i < liczba_wierzcholkow; ++i)
	{
		GL->DodajWierzcholek(w1[i], i);
		GM->DodajWierzcholek(w2[i], i);
	}

	while (!strumien.eof())
	{
		while (strumien >> poprzedni >> nastepny >> waga)
		{
			GL->DodajKrawedz(w1[poprzedni], w1[nastepny], waga);
			GM->DodajKrawedz(w2[poprzedni], w2[nastepny], waga);
		}
	}

	strumien.close();

	Wezel<Krawedz>* x;
	x = GL->Krawedzie()->Poczatek();
	for (int i = 0; i < liczba_wierzcholkow; ++i)                                 // wyswietl krawedzie w grafie lista sasiedztwa
	{
		cout << x->WezElement()->PoleKrawedzi()<<" ";
		x = x->WezNastepny();
	}
	cout << endl;

	delete GL;
	delete GM;


}