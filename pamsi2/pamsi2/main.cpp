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

double DijkstraTestMacierz(ifstream& strumien, ofstream& zapis, string wejsciowy);
double DijkstraTest(ifstream& strumien, ofstream& zapis,string wejsciowy);                // funkcja testujaca dzialanie algorytmu Dijkstry
																						  // wczytuje graf z pliku, stosuje algorytm i zapisuje wynik
																						  // zwraca czas dzialania samego algorytmu Dijkstry
void Generate_Input(string Inputname, int nbofvertices, int nbofedges);

int main()
{
	ifstream strumien;
	ofstream zapis;
	double czas = 0;
	/* Grafy 10 wierzcholkow */
	/*
	for (int i = 0; i < 100; ++i)
	{
		Generate_Input("graf10_25.txt", 10, 11);
		czas += DijkstraTest(strumien, zapis, "graf10_25.txt");
	}
	cout << "Czas Dijkstra 10_25 = " << czas << endl;
	czas=0;
	for (int i = 0; i < 100; ++i)
	{
		Generate_Input("graf10_50.txt", 10, 23);
		czas += DijkstraTest(strumien, zapis,"graf10_50.txt");
	}
	cout << "Czas Dijkstra 10_50 = " << czas << endl;
	czas=0;
	for (int i = 0; i < 100; ++i)
	{
		Generate_Input("graf10_75.txt", 10, 34);
		czas += DijkstraTest(strumien, zapis, "graf10_75.txt");
	}
	cout << "Czas Dijkstra 10_75 = " << czas << endl;
	czas=0;
	for (int i = 0; i < 100; ++i)
	{
		Generate_Input("graf10_100.txt", 10, 45);
		czas += DijkstraTest(strumien, zapis, "graf10_100.txt");
	}
	cout << "Czas Dijkstra 10_100 = " << czas << endl;
	*/

	/*Grafy 50 wierzcholkow */
	/*
	czas=0;
	for (int i = 0; i < 100; ++i)
	{
		Generate_Input("graf50_25.txt", 50, 281);
		czas += DijkstraTest(strumien, zapis, "graf50_25.txt");
	}
	cout << "Czas Dijkstra 50_25 = " << czas << endl;
	czas=0;
	for (int i = 0; i < 100; ++i)
	{
		Generate_Input("graf50_50.txt", 50, 563);
		czas += DijkstraTest(strumien, zapis, "graf50_50.txt");
	}
	cout << "Czas Dijkstra 50_50 = " << czas << endl;
	czas=0;
	for (int i = 0; i < 100; ++i)
	{
		Generate_Input("graf50_75.txt", 50, 844);
		czas += DijkstraTest(strumien, zapis, "graf50_75.txt");
	}
	cout << "Czas Dijkstra 50_75 = " << czas << endl;
	czas=0;
	for (int i = 0; i < 100; ++i)
	{
		Generate_Input("graf50_100.txt", 50, 1125);
		czas += DijkstraTest(strumien, zapis, "graf50_100.txt");
	}
	cout << "Czas Dijkstra 50_100 = " << czas << endl;
	*/

	/*Grafy 100 */
	/*
	czas=0;
	for (int i = 0; i < 100; ++i)
	{
		Generate_Input("graf100_25.txt", 100, 1238);
		czas += DijkstraTest(strumien, zapis, "graf100_25.txt");
	}
	cout << "Czas Dijkstra 100_25 = " << czas << endl;
	czas=0;
	for (int i = 0; i < 100; ++i)
	{
		Generate_Input("graf100_50.txt", 100, 2475);
		czas += DijkstraTest(strumien, zapis, "graf100_50.txt");
	}
	cout << "Czas Dijkstra 100_50 = " << czas << endl;
	czas=0;
	for (int i = 0; i < 100; ++i)
	{
		Generate_Input("graf100_75.txt", 100, 3713);
		czas += DijkstraTest(strumien, zapis, "graf100_75.txt");
	}
	cout << "Czas Dijkstra 100_75 = " << czas << endl;
	czas=0;
	for (int i = 0; i < 100; ++i)
	{
		Generate_Input("graf100_100.txt", 100, 4950);
		czas += DijkstraTest(strumien, zapis, "graf100_100.txt");
	}
	cout << "Czas Dijkstra 100_100 = " << czas << endl;
	*/

	/*grafy 250 */
	/*
	czas=0;
	for (int i = 0; i < 100; ++i)
	{
		Generate_Input("graf250_25.txt", 250, 7781);
		czas += DijkstraTest(strumien, zapis, "graf250_25.txt");
	}
	cout << "Czas Dijkstra 250_25 = " << czas << endl;
	czas=0;
	for (int i = 0; i < 100; ++i)
	{
		Generate_Input("graf250_50.txt", 250, 15563);
		czas += DijkstraTest(strumien, zapis, "graf250_50.txt");
	}
	cout << "Czas Dijkstra 250_50 = " << czas << endl;
	czas=0;
	for (int i = 0; i < 100; ++i)
	{
		Generate_Input("graf250_75.txt", 250, 23344);
		czas += DijkstraTest(strumien, zapis, "graf250_75.txt");
	}
	cout << "Czas Dijkstra 250_75 = " << czas << endl;
	czas=0;
	for (int i = 0; i < 100; ++i)
	{
		Generate_Input("graf250_100.txt", 250, 31125);
		czas += DijkstraTest(strumien, zapis, "graf250_100.txt");
	}
	cout << "Czas Dijkstra 250_100 = " << czas << endl;
	*/

	/*Grafy 500*/
	/*
	czas=0;
	for (int i = 0; i < 100; ++i)
	{
		Generate_Input("graf500_25.txt", 500, 31188);
		czas += DijkstraTest(strumien, zapis, "graf500_25.txt");
	}
	cout << "Czas Dijkstra 500_25 = " << czas << endl;
	czas=0;
	for (int i = 0; i < 100; ++i)
	{
		Generate_Input("graf500_50.txt", 500, 62375);
		czas += DijkstraTest(strumien, zapis, "graf500_50.txt");
	}
	cout << "Czas Dijkstra 500_50 = " << czas << endl;
	czas=0;
	for (int i = 0; i < 100; ++i)
	{
		Generate_Input("graf500_75.txt", 500, 96563);
		czas += DijkstraTest(strumien, zapis, "graf500_75.txt");
	}
	cout << "Czas Dijkstra 500_75 = " << czas << endl;
	czas=0;
	for (int i = 0; i < 100; ++i)
	{
		Generate_Input("graf500_100.txt", 500, 124750);
		czas += DijkstraTest(strumien, zapis, "graf500_100.txt");
	}
	cout << "Czas Dijkstra 500_100 = " << czas << endl;  */

	/////////////////////////////////////////////////////////////////////////////
	/////////// Macierz sasiedztwa //////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////

	/* Grafy 10 wierzcholkow */
	/*
	for (int i = 0; i < 100; ++i)
	{
		Generate_Input("graf10_25.txt", 10, 11);
		czas += DijkstraTestMacierz(strumien, zapis, "graf10_25.txt");
	}
	cout << "Czas Dijkstra 10_25 = " << czas << endl;
	czas =0;
	for (int i = 0; i < 100; ++i)
	{
		Generate_Input("graf10_50.txt", 10, 23);
		czas += DijkstraTestMacierz(strumien, zapis,"graf10_50.txt");
	}
	cout << "Czas Dijkstra 10_50 = " << czas << endl;
	czas=0;
	for (int i = 0; i < 100; ++i)
	{
		Generate_Input("graf10_75.txt", 10, 34);
		czas += DijkstraTestMacierz(strumien, zapis, "graf10_75.txt");
	}
	cout << "Czas Dijkstra 10_75 = " << czas << endl;
	czas=0;
	for (int i = 0; i < 100; ++i)
	{
		Generate_Input("graf10_100.txt", 10, 45);
		czas += DijkstraTestMacierz(strumien, zapis, "graf10_100.txt");
	}
	cout << "Czas Dijkstra 10_100 = " << czas << endl;
	*/

	/*Grafy 50 wierzcholkow */
	/*
	czas=0;
	for (int i = 0; i < 100; ++i)
	{
		Generate_Input("graf50_25.txt", 50, 281);
		czas += DijkstraTestMacierz(strumien, zapis, "graf50_25.txt");
	}
	cout << "Czas Dijkstra 50_25 = " << czas << endl;
	czas=0;
	for (int i = 0; i < 100; ++i)
	{
		Generate_Input("graf50_50.txt", 50, 563);
		czas += DijkstraTestMacierz(strumien, zapis, "graf50_50.txt");
	}
	cout << "Czas Dijkstra 50_50 = " << czas << endl;
	czas=0;
	for (int i = 0; i < 100; ++i)
	{
		Generate_Input("graf50_75.txt", 50, 844);
		czas += DijkstraTestMacierz(strumien, zapis, "graf50_75.txt");
	}
	cout << "Czas Dijkstra 50_75 = " << czas << endl;
	czas=0;
	for (int i = 0; i < 100; ++i)
	{
		Generate_Input("graf50_100.txt", 50, 1125);
		czas += DijkstraTestMacierz(strumien, zapis, "graf50_100.txt");
	}
	cout << "Czas Dijkstra 50_100 = " << czas << endl;
	*/

	/*Grafy 100 */
	/*
	czas=0;
	for (int i = 0; i < 100; ++i)
	{
		Generate_Input("graf100_25.txt", 100, 1238);
		czas += DijkstraTestMacierz(strumien, zapis, "graf100_25.txt");
	}
	cout << "Czas Dijkstra 100_25 = " << czas << endl;
	czas=0;
	for (int i = 0; i < 100; ++i)
	{
		Generate_Input("graf100_50.txt", 100, 2475);
		czas += DijkstraTestMacierz(strumien, zapis, "graf100_50.txt");
	}
	cout << "Czas Dijkstra 100_50 = " << czas << endl;
	czas=0;
	for (int i = 0; i < 100; ++i)
	{
		Generate_Input("graf100_75.txt", 100, 3713);
		czas += DijkstraTestMacierz(strumien, zapis, "graf100_75.txt");
	}
	cout << "Czas Dijkstra 100_75 = " << czas << endl;
	czas=0;
	for (int i = 0; i < 100; ++i)
	{
		Generate_Input("graf100_100.txt", 100, 4950);
		czas += DijkstraTestMacierz(strumien, zapis, "graf100_100.txt");
	}
	cout << "Czas Dijkstra 100_100 = " << czas << endl;
	*/

	/*grafy 250 */
	/*
	czas=0;
	for (int i = 0; i < 100; ++i)
	{
		Generate_Input("graf250_25.txt", 250, 7781);
		czas += DijkstraTestMacierz(strumien, zapis, "graf250_25.txt");
	}
	cout << "Czas Dijkstra 250_25 = " << czas << endl;
	czas=0;
	for (int i = 0; i < 100; ++i)
	{
		Generate_Input("graf250_50.txt", 250, 15563);
		czas += DijkstraTestMacierz(strumien, zapis, "graf250_50.txt");
	}
	cout << "Czas Dijkstra 250_50 = " << czas << endl;
	czas=0;
	for (int i = 0; i < 100; ++i)
	{
		Generate_Input("graf250_75.txt", 250, 23344);
		czas += DijkstraTestMacierz(strumien, zapis, "graf250_75.txt");
	}
	cout << "Czas Dijkstra 250_75 = " << czas << endl;
	czas=0;
	for (int i = 0; i < 100; ++i)
	{
		Generate_Input("graf250_100.txt", 250, 31125);
		czas += DijkstraTestMacierz(strumien, zapis, "graf250_100.txt");
	}
	cout << "Czas Dijkstra 250_100 = " << czas << endl;
	*/

	/*Grafy 500*/
	/*
	czas=0;
	for (int i = 0; i < 100; ++i)
	{
		Generate_Input("graf500_25.txt", 500, 31188);
		czas += DijkstraTestMacierz(strumien, zapis, "graf500_25.txt");
	}
	cout << "Czas Dijkstra 500_25 = " << czas << endl;
	czas=0;
	for (int i = 0; i < 100; ++i)
	{
		Generate_Input("graf500_50.txt", 500, 62375);
		czas += DijkstraTestMacierz(strumien, zapis, "graf500_50.txt");
	}
	cout << "Czas Dijkstra 500_50 = " << czas << endl;
	czas=0;
	for (int i = 0; i < 100; ++i)
	{
		Generate_Input("graf500_75.txt", 500, 96563);
		czas += DijkstraTestMacierz(strumien, zapis, "graf500_75.txt");
	}
	cout << "Czas Dijkstra 500_75 = " << czas << endl;
	czas=0;
	for (int i = 0; i < 100; ++i)
	{
		Generate_Input("graf500_100.txt", 500, 124750);
		czas += DijkstraTestMacierz(strumien, zapis, "graf500_100.txt");
	}
	cout << "Czas Dijkstra 500_100 = " << czas << endl; */;


	int poprzedni, nastepny, waga;
	int liczba_wierzcholkow, liczba_krawedzi, wierzcholek_startowy;
	GrafLista* GL = new GrafLista;

	Generate_Input("graftest.txt", 8, 15);

	strumien.open("graftest.txt");

	if (strumien.good() == false)
	{
		cout << "Nie wczytano pliku" << endl;
		return 0;
	}

	strumien >> liczba_wierzcholkow >> liczba_krawedzi >> wierzcholek_startowy;

	Wierzcholek<Krawedz>** w1 = new Wierzcholek<Krawedz> * [liczba_wierzcholkow];

	for (int i = 0; i < liczba_wierzcholkow; ++i)
	{
		w1[i] = new Wierzcholek<Krawedz>;
	}


	for (int i = 0; i < liczba_wierzcholkow; ++i)
	{
		GL->DodajWierzcholek(w1[i], i);
	}

	while (!strumien.eof())
	{
		while (strumien >> poprzedni >> nastepny >> waga)
		{
			GL->DodajKrawedz(w1[poprzedni], w1[nastepny], waga);
		}
	}

	Wezel<Krawedz>* a = GL->Krawedzie()->Poczatek();
	for (int i = 0; i < GL->Krawedzie()->Rozmiar();++i)
	{
		cout << "konce krawedzi " << a->WezElement()->Poprzedni()->PoleWierzcholka() << " ";
		cout << a->WezElement()->Nastepny()->PoleWierzcholka() << " ";
		cout << " waga krawedzi " << a->WezElement()->PoleKrawedzi() << endl;
		a = a->WezNastepny();
	}

	strumien.close();
	int pop;
	double przed, po;
	int poprzednik[1000] = { 0 };
	int pom[1000] = { 0 };

	DijkstraLista(GL, w1[wierzcholek_startowy], poprzednik);

	Wezel<Wierzcholek<Krawedz>>* f = GL->Wierzcholki()->Poczatek();

	for (int i = 0; i < GL->Wierzcholki()->Rozmiar(); ++i)
	{
		cout << f->WezElement()->PoleWierzcholka() << " {";
		pop = f->WezElement()->PoleWierzcholka();
		int j = 0;
		do
		{
			pom[j] = pop;
			pop = poprzednik[pop];
			++j;
			if (pop == wierzcholek_startowy)
			{
				pom[j] = pop;
			}
		} while (pop != wierzcholek_startowy);
		while (j >= 0)
		{
			if (j != 0)
				cout << pom[j] << "->";
			else
				cout << pom[j];
			--j;
		}
		cout << "} " << f->WezElement()->WezKlucz() << endl;
		f = f->WezNastepny();
	}
	delete GL;
	
}

double DijkstraTestMacierz(ifstream& strumien, ofstream& zapis, string wejsciowy)
{
	int poprzedni, nastepny, waga;
	int liczba_wierzcholkow, liczba_krawedzi, wierzcholek_startowy;
	GrafMacierz* GM = new GrafMacierz;

	strumien.open(wejsciowy);

	if (strumien.good() == false)
	{
		cout << "Nie wczytano pliku" << endl;
		return 0;
	}

	strumien >> liczba_wierzcholkow >> liczba_krawedzi >> wierzcholek_startowy;

	Wierzcholek<Krawedz>** w1 = new Wierzcholek<Krawedz> * [liczba_wierzcholkow];

	for (int i = 0; i < liczba_wierzcholkow; ++i)
	{
		w1[i] = new Wierzcholek<Krawedz>;
	}


	for (int i = 0; i < liczba_wierzcholkow; ++i)
	{
		GM->DodajWierzcholek(w1[i], i);
	}

	while (!strumien.eof())
	{
		while (strumien >> poprzedni >> nastepny >> waga)
		{
			GM->DodajKrawedz(w1[poprzedni], w1[nastepny], waga);
		}
	}

	strumien.close();

	int pop;
	double przed, po, czas = 0;
	int poprzednik[1000] = { 0 };
	int pom[1000] = { 0 };

	przed = (double)clock();
	DijkstraMacierz(GM, w1[wierzcholek_startowy], poprzednik);
	po = (double)clock();
	czas = (double)(po - przed) / CLOCKS_PER_SEC;

	Wezel<Wierzcholek<Krawedz>>* f = GM->Wierzcholki()->Poczatek();

	zapis.open("wynik.txt");

	for (int i = 0; i < GM->Wierzcholki()->Rozmiar(); ++i)
	{
		zapis << f->WezElement()->PoleWierzcholka() << " {";
		pop = f->WezElement()->PoleWierzcholka();
		int j = 0;
		do
		{
			pom[j] = pop;
			pop = poprzednik[pop];
			++j;
			if (pop == wierzcholek_startowy)
			{
				pom[j] = pop;
			}
		} while (pop != wierzcholek_startowy);
		while (j >= 0)
		{
			if (j != 0)
				zapis << pom[j] << "->";
			else
				zapis << pom[j];
			--j;
		}
		zapis << "} " << f->WezElement()->WezKlucz() << endl;
		f = f->WezNastepny();
	}
	zapis.close();

	delete GM;
	return czas;
}

double DijkstraTest(ifstream& strumien, ofstream& zapis,string wejsciowy)
{
	int poprzedni, nastepny, waga;
	int liczba_wierzcholkow, liczba_krawedzi, wierzcholek_startowy;
	GrafLista* GL = new GrafLista;

	strumien.open(wejsciowy);

	if (strumien.good() == false)
	{
		cout << "Nie wczytano pliku" << endl;
		return 0;
	}

	strumien >> liczba_wierzcholkow >> liczba_krawedzi >> wierzcholek_startowy;

	Wierzcholek<Krawedz>** w1 = new Wierzcholek<Krawedz> * [liczba_wierzcholkow];

	for (int i = 0; i < liczba_wierzcholkow; ++i)
	{
		w1[i] = new Wierzcholek<Krawedz>;
	}


	for (int i = 0; i < liczba_wierzcholkow; ++i)
	{
		GL->DodajWierzcholek(w1[i], i);
	}

	while (!strumien.eof())
	{
		while (strumien >> poprzedni >> nastepny >> waga)
		{
			GL->DodajKrawedz(w1[poprzedni], w1[nastepny], waga);
		}
	}

	strumien.close();
	int pop;
	double przed, po, czas = 0;
	int poprzednik[1000] = { 0 };
	int pom[1000] = { 0 };

	przed = (double)clock();
	DijkstraLista(GL, w1[wierzcholek_startowy], poprzednik);
	po = (double)clock();
	czas = (double)(po - przed) / CLOCKS_PER_SEC;

	Wezel<Wierzcholek<Krawedz>>* f = GL->Wierzcholki()->Poczatek();

	zapis.open("wynik.txt");

	for (int i = 0; i < GL->Wierzcholki()->Rozmiar(); ++i)
	{
		zapis << f->WezElement()->PoleWierzcholka() << " {";
		pop = f->WezElement()->PoleWierzcholka();
		int j = 0;
		do
		{
			pom[j] = pop;
			pop = poprzednik[pop];
			++j;
			if (pop == wierzcholek_startowy)
			{
				pom[j] = pop;
			}
		} while (pop != wierzcholek_startowy);
		while (j >= 0)
		{
			if (j != 0)
				zapis << pom[j] << "->";
			else
				zapis << pom[j];
			--j;
		}
		zapis << "} " << f->WezElement()->WezKlucz() << endl;
		f = f->WezNastepny();
	}
	zapis.close();
	delete GL;

	return czas;
}

void Generate_Input(string Inputname, int nbofvertices, int nbofedges)
{

	int** array = new int* [nbofvertices];			//taka trochê macierz s¹siedztwa
	for (int i = 0; i < nbofvertices; i++)
	{
		array[i] = new int[nbofvertices];
	}

	for (int i = 0; i < nbofvertices; i++)
	{
		for (int j = 0; j < nbofvertices; j++)		//inicjujê 0, tam siê znajduj¹ wagi krawêdzi
		{
			array[i][j] = 0;
		}
	}

	ofstream Input;				//trochê mieszanka nazw, ale chodzi o to, ¿e generuje siê Input, czyli wejœciowy opis krawêdzi grafu
	Input.open(Inputname);
	Input.close();					//to robiê po to, ¿eby mieæ pewnoœæ, ¿e plik z którego potem korzystam jest pusty
	Input.open(Inputname);


	Input << nbofvertices << "\t" << nbofedges << "\t" << 0 << "\n"; // zapis liczby wierzcholkow, liczby krawedzi i wierzcholek poczatkowy jako 0 

	for (int i = 0; i < nbofvertices - 1; i++)
	{
		int source = i; //losuje pierwszy wierzcholek - Ÿród³o
		int target = i + 1; //losuje drugi wierzcholek - cel
		int weight = rand() % 1000;  // losuje wage krawedzi

		array[source][target] = weight;			//zapisujê wagê krawêdzi w macierzy

	}
	for (int j = 0; j < nbofedges - nbofvertices + 1; j++)
	{
		int source = rand() % nbofvertices; //losuje pierwsz wierzcholek - Ÿród³o
		int target = rand() % nbofvertices; //losuje drugi wierzcholek - cel
		int weight = rand() % 1000;           // losuje wage krawedzi

		if (source == target) {
			j--;							//nie uda³o siê wykonanie
		}
		else if (target - source == 1) {	//œcie¿ka ju¿ zrobiona
			j--;
		}
		else if (source != target && target - source != 1)
		{			//ten drugi warunek siê bierze z tego, ¿e œcie¿kê, ju¿ robi³em


			if (array[source][target] == 0 && array[target][source] == 0) {

				array[source][target] = weight;			//zapisz wartoœæ nowej krawêdzi

			}
			else
				j--;
		}

	}
	for (int i = 0; i < nbofvertices; i++)
	{
		for (int j = 0; j < nbofvertices; j++)
		{
			if (array[i][j] != 0) {
				Input << i << "\t" << j << "\t" << array[i][j] << endl;
			}
		}
	}


	Input.close();

	for (int i = 0; i < nbofvertices; i++)
	{
		delete array[i];
	}
	delete[] array;
}