#pragma once
#include<iostream>
#include"Lista.h"
#include"Wierzcholek.h"
#include"Krawedz.h"
#define MAX 1000

using namespace std;

class GrafMacierz
{
	Lista<Krawedz> krawedzie;
	Lista<Wierzcholek<Krawedz>> wierzcholki;
	Krawedz*** macierz;
public:
	GrafMacierz() 
	{ 
		macierz = new Krawedz ** [MAX];
		for (int i = 0; i < MAX; ++i)
			macierz[i] = new Krawedz * [MAX];
		for (int i = 0; i < MAX; ++i)
			for (int j = 0; j < MAX; ++j)
				macierz[i][j] = nullptr;
	}
	~GrafMacierz() 
	{
		for (int i = 0; i < MAX; ++i)
		{
			delete[] macierz[i];
		}
		delete [] macierz;
		krawedzie.~Lista();
		wierzcholki.~Lista();
	}
	Lista<Wierzcholek<Krawedz>>* Wierzcholki() { Lista<Wierzcholek<Krawedz>>* w = &wierzcholki; return w; }
	Lista<Krawedz>* Krawedzie() { Lista<Krawedz>* w = &krawedzie; return w; }
	void DodajWierzcholek(Wierzcholek<Krawedz>* w,int pole)
	{
		wierzcholki.DodajKoniec(w);
		w->UstawPole(pole);
		w->UstawKlucz(wierzcholki.Rozmiar());
		w->UstawPozycje(wierzcholki.Koniec());
	}
	void DodajKrawedz(Wierzcholek<Krawedz>* poprzedni, Wierzcholek<Krawedz>* nastepny, int pole)
	{
		Krawedz* k = new Krawedz;
		krawedzie.DodajKoniec(k);
		k->UstawPole(pole);
		k->UstawPozycje(krawedzie.Koniec());
		k->UstawWierzcholki(poprzedni, nastepny);
		macierz[poprzedni->PoleWierzcholka()][nastepny->PoleWierzcholka()] = k;
		macierz[nastepny->PoleWierzcholka()][poprzedni->PoleWierzcholka()] = k;
	}
	Wierzcholek<Krawedz>* Przeciwlegly(Wierzcholek<Krawedz>* w, Krawedz* k)
	{
		Wierzcholek<Krawedz>* pom;
		if (w == k->Nastepny())
		{
			pom = k->Poprzedni();
			return pom;
		}
		else if (w == k->Poprzedni())
		{
			pom = k->Nastepny();
			return pom;
		}
		else
			return nullptr;
	}
	Lista<Krawedz>* Incydentne(Wierzcholek<Krawedz>* w)
	{
		Lista<Krawedz>* l = new Lista<Krawedz>;
		for (int i = 0; i < MAX; ++i)
			if (macierz[w->PoleWierzcholka()][i] != nullptr)
				l->DodajKoniec(macierz[w->PoleWierzcholka()][i]);
		return l;
	}
};