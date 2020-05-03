#pragma once
#include"Lista.h"
#include"Wierzcholek.h"
#include"Krawedz.h"

using namespace std;

class GrafLista                               // graf zaimplementowany przez listê s¹siedztwa
{
	Lista<Krawedz> krawedzie;                              // lista krawedzi
	Lista<Wierzcholek<Krawedz>> wierzcholki;               // lista wierzcholkow
public:
	GrafLista() { }
	~GrafLista() { krawedzie.~Lista(); wierzcholki.~Lista(); }
	Lista<Wierzcholek<Krawedz>>* Wierzcholki() { Lista<Wierzcholek<Krawedz>>* w = &wierzcholki; return w; }
	Lista<Krawedz>* Krawedzie() { Lista<Krawedz>* w = &krawedzie; return w; }
	void DodajWierzcholek(Wierzcholek<Krawedz>* w, int klucz)
	{
		wierzcholki.DodajKoniec(w);                                 // dodanie do listy wierzcholkow
		w->UstawPole(klucz);                                        // ustawianie parametrow wierzcholka
		w->UstawPozycje(wierzcholki.Koniec());
		Lista<Krawedz>* l = new Lista<Krawedz>;
		w->UstawListeIncydencji(l);
	}
	void DodajKrawedz(Wierzcholek<Krawedz>* poprzedni, Wierzcholek<Krawedz>* nastepny, int klucz)
	{
		Krawedz* k = new Krawedz;
		krawedzie.DodajKoniec(k);
		k->UstawPole(klucz);
		k->UstawPozycje(krawedzie.Koniec());
		k->UstawWierzcholki(poprzedni, nastepny);
		poprzedni->DodajIncydencje(k);
		nastepny->DodajIncydencje(k);
		k->UstawIncydencje(poprzedni->IncydencjeKoniec(), nastepny->IncydencjeKoniec());
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

	bool CzySasiednie(Wierzcholek<Krawedz>* w1, Wierzcholek<Krawedz>* w2)
	{
		Wezel<Krawedz>* pom = nullptr;                                           // wskaznik pomocniczy do przeszukiwania listy 
		if (w1->IleIncydencji() < w2->IleIncydencji())
		{
			pom = w1->IncydencjePoczatek();
			while (pom != nullptr)
			{
				if (w2 == Przeciwlegly(w1, pom->WezElement()))
					return true;
				pom = pom->WezNastepny();
			}
			return false;
		}
		else
		{
			pom = w2->IncydencjePoczatek();
			while (pom != nullptr)
			{
				if (w1 == Przeciwlegly(w2, pom->WezElement()))
					return true;
				pom = pom->WezNastepny();
			}
			return false;
		}
	}
	void UsunWierzcholek(Wierzcholek<Krawedz>* w)                // usuwa powiazania wierzcholka z grafu i zwraca do niego wskaznik,
	{                                                                             // ale nie usuwa samego obiektu
		wierzcholki.UsunWezel(w->ZwrocPozycje());
	}
};
