#pragma once
#include<iostream>
#include"Wezel.h"
#include"Wierzcholek.h"
#include"Krawedz.h"

using namespace std;

template<typename E>
class Kolejka
{
	int rozmiar;
	Wezel<E>* korzen;
	Wezel<E>* ostatni;
public:
	Kolejka() { rozmiar = 0; korzen = nullptr; ostatni = nullptr; }
	~Kolejka() { while (!Pusta()) delete UsunMin(); }
	Wezel<E>* Korzen() { return korzen; }
	int Rozmiar() { return rozmiar; }
	bool Pusta() { if (rozmiar == 0) return true; else return false; }
	void ZmienKlucz(Wezel<E>* w, int k)
	{ 
		if (w != nullptr)
		{
			w->UstawKlucz(k);
				wGore(w);
		}
	}
	void wGore(Wezel<E>* w)                                                                // przesuwa elementy z mniejszym kluczem w gore
	{
		if (w->WezKlucz() < w->WezOjca()->WezKlucz() && w == ostatni)
		{
			ostatni = w->WezOjca();
		}
			
		while (w->WezOjca() != korzen && w->WezKlucz() < w->WezOjca()->WezKlucz())
		{
			if (w->WezOjca()->WezNastepny() == w)                                          // jesli wezel jest prawym synem 
			{
				Wezel<E>* pom = nullptr;
				pom = w->WezNastepny();
				w->UstawNastepny(w->WezOjca());
				w->WezOjca()->UstawNastepny(pom);
				if (pom != nullptr)
					pom->UstawOjca(w->WezOjca());
				pom = w->WezPoprzedni();
				w->UstawPoprzedni(w->WezOjca()->WezPoprzedni());
				w->WezOjca()->UstawPoprzedni(pom);
				if (pom != nullptr)
					pom->UstawOjca(w->WezOjca());
				w->WezPoprzedni()->UstawOjca(w);
				pom = w->WezOjca();
				if (pom == pom->WezOjca()->WezNastepny())
					pom->WezOjca()->UstawNastepny(w);
				else if (pom == pom->WezOjca()->WezPoprzedni())
					pom->WezOjca()->UstawPoprzedni(w);
				w->UstawOjca(pom->WezOjca());
				pom->UstawOjca(w);
				if (w->WezPoprzedni() != nullptr)
					w->WezPoprzedni()->UstawOjca(w);
			}
			else if (w->WezOjca()->WezPoprzedni() == w)                            // jesli wezel jest lewym synem 
			{
				Wezel<E>* pom;
				pom = w->WezPoprzedni();
				w->UstawPoprzedni(w->WezOjca());
				w->WezOjca()->UstawPoprzedni(pom);
				if (pom != nullptr)
					pom->UstawOjca(w->WezOjca());
				pom = w->WezNastepny();
				w->UstawNastepny(w->WezOjca()->WezNastepny());
				w->WezOjca()->UstawNastepny(pom);
				if (pom != nullptr)
					pom->UstawOjca(w->WezOjca());
				pom = w->WezOjca();
				if (pom == pom->WezOjca()->WezNastepny())
					pom->WezOjca()->UstawNastepny(w);
				else if (pom == pom->WezOjca()->WezPoprzedni())
					pom->WezOjca()->UstawPoprzedni(w);
				w->UstawOjca(pom->WezOjca());
				pom->UstawOjca(w);
				if(w->WezNastepny() != nullptr)
					w->WezNastepny()->UstawOjca(w);
			}
		}
		if (w->WezOjca() == korzen && w->WezKlucz() < w->WezOjca()->WezKlucz())
		{
			if (w->WezOjca()->WezNastepny() == w)                                          // jesli wezel jest prawym synem 
			{
				Wezel<E>* pom = nullptr;
				pom = w->WezNastepny();
				w->UstawNastepny(w->WezOjca());
				w->WezOjca()->UstawNastepny(pom);
				if (pom != nullptr)
					pom->UstawOjca(w->WezOjca());
				pom = w->WezPoprzedni();
				w->UstawPoprzedni(w->WezOjca()->WezPoprzedni());
				w->WezOjca()->UstawPoprzedni(pom);
				if (pom != nullptr)
					pom->UstawOjca(w->WezOjca());
				w->WezPoprzedni()->UstawOjca(w);
				pom = w->WezOjca();
				if (pom == pom->WezOjca()->WezNastepny())
					pom->WezOjca()->UstawNastepny(w);
				else if (pom == pom->WezOjca()->WezPoprzedni())
					pom->WezOjca()->UstawPoprzedni(w);
				w->UstawOjca(korzen);
				korzen = w;
				pom->UstawOjca(w);
				if (w->WezPoprzedni() != nullptr)
					w->WezPoprzedni()->UstawOjca(w);
				
			}
			else if (w->WezOjca()->WezPoprzedni() == w)                            // jesli wezel jest lewym synem 
			{
				Wezel<E>* pom;
				pom = w->WezPoprzedni();
				w->UstawPoprzedni(w->WezOjca());
				w->WezOjca()->UstawPoprzedni(pom);
				if (pom != nullptr)
					pom->UstawOjca(w->WezOjca());
				pom = w->WezNastepny();
				w->UstawNastepny(w->WezOjca()->WezNastepny());
				w->WezOjca()->UstawNastepny(pom);
				if (pom != nullptr)
					pom->UstawOjca(w->WezOjca());
				pom = w->WezOjca();
				if (pom == pom->WezOjca()->WezNastepny())
					pom->WezOjca()->UstawNastepny(w);
				else if (pom == pom->WezOjca()->WezPoprzedni())
					pom->WezOjca()->UstawPoprzedni(w);
				w->UstawOjca(korzen);
				korzen = w;
				pom->UstawOjca(w);
				if (w->WezNastepny() != nullptr)
					w->WezNastepny()->UstawOjca(w);

				
			}
		}
	}
	void wDol(Wezel<E>* w)                                                                 // przesuwa elementy z wiekszym kluczem w dol
	{
		Wezel<E>* najmniejszy = nullptr;                                                   // wskaznik do syna z mniejszym kluczem, pomoc przy sprawdzaniu
																						   // czy wezel nalezy przesunac, i w ktora strone
		if (w->WezPoprzedni() != nullptr && w->WezNastepny() != nullptr)                   // sprzawdzenie czy wezel ma obu synow
		{
			if (w->WezPoprzedni()->WezKlucz() < w->WezNastepny()->WezKlucz())
				najmniejszy = w->WezPoprzedni();
			else
				najmniejszy = w->WezNastepny();
		}
		else if (w->WezPoprzedni() != nullptr && w->WezNastepny() == nullptr)              // jesli wezel ma tylko lewego syna
			najmniejszy = w->WezPoprzedni();

		if (najmniejszy != nullptr)                                                        // jesli wezel ma co najmniej jednego syna
		{
			if (w->WezKlucz() > najmniejszy->WezKlucz())                                   // jesli wezel ma klucz wiekszy niz ktorys z synow
			{
				if (rozmiar <= 3)
				{
					if (najmniejszy == w->WezPoprzedni())
					{
						if (najmniejszy == ostatni)
							ostatni = w;
						najmniejszy->UstawPoprzedni(w);
						najmniejszy->UstawNastepny(w->WezNastepny());
						najmniejszy->UstawOjca(korzen);
						w->UstawNastepny(nullptr);
						w->UstawPoprzedni(nullptr);
						w->UstawOjca(najmniejszy);
						korzen = najmniejszy;
					}
					if (najmniejszy == w->WezNastepny())
					{
						if (najmniejszy == ostatni)
							ostatni = w;
						w->UstawNastepny(nullptr);
						najmniejszy->UstawNastepny(w);
						najmniejszy->UstawOjca(korzen);
						najmniejszy->UstawPoprzedni(w->WezPoprzedni());
						w->UstawPoprzedni(nullptr);
						w->UstawNastepny(nullptr);
						w->UstawOjca(najmniejszy);
						korzen = najmniejszy;
					}
				}
				else if (najmniejszy == w->WezPoprzedni())                                      // jesli wezel jest lewym synem
				{
					Wezel<E>* pom;
					pom = najmniejszy->WezPoprzedni();
					najmniejszy->UstawPoprzedni(w);
					w->UstawPoprzedni(pom);
					if (pom != nullptr)
						pom->UstawOjca(w);
					pom = najmniejszy->WezNastepny();
					najmniejszy->UstawNastepny(w->WezNastepny());
					w->UstawNastepny(pom);
					if (pom != nullptr)
						pom->UstawOjca(w);
					if (w != korzen)
					{
						if (w == w->WezOjca()->WezNastepny())
							w->WezOjca()->UstawNastepny(najmniejszy);
						else if (w == w->WezOjca()->WezPoprzedni())
							w->WezOjca()->UstawPoprzedni(najmniejszy);
						najmniejszy->UstawOjca(w->WezOjca());
					}
					w->UstawOjca(najmniejszy);
					if (najmniejszy->WezNastepny() != nullptr)
						najmniejszy->WezNastepny()->UstawOjca(najmniejszy);
					if (w == korzen)
						korzen = najmniejszy;
					if (najmniejszy == ostatni)
						ostatni = w;
					wDol(w);
				}
				else if (najmniejszy == w->WezNastepny())                                  // jesli wezel jest prawym synem
				{
					Wezel<E>* pom;
					pom = najmniejszy->WezNastepny();
					najmniejszy->UstawNastepny(w);
					w->UstawNastepny(pom);
					if (pom != nullptr)
						pom->UstawOjca(w);
					pom = najmniejszy->WezPoprzedni();
					najmniejszy->UstawPoprzedni(w->WezPoprzedni());
					w->UstawPoprzedni(pom);
					if (pom != nullptr)
						pom->UstawOjca(w);
					najmniejszy->WezPoprzedni()->UstawOjca(najmniejszy);
					if (w != korzen)
					{
						if (w == w->WezOjca()->WezNastepny())
							w->WezOjca()->UstawNastepny(najmniejszy);
						else if (w == w->WezOjca()->WezPoprzedni())
							w->WezOjca()->UstawPoprzedni(najmniejszy);
						najmniejszy->UstawOjca(w->WezOjca());
					}
					w->UstawOjca(najmniejszy);
					if (w == korzen)
						korzen = najmniejszy;
					if (najmniejszy == ostatni)
						ostatni = w;
					wDol(w);
				}
			}
		}
	}
	void Dodaj(Wierzcholek<Krawedz>* nowy,int droga)                                      // dodaje wierzcholek do kolejki
	{
		if (rozmiar < 3)
		{
			if (ostatni == nullptr)
			{
				Wezel<E>* w = new Wezel<E>;
				korzen = w;
				w->UstawKlucz(droga);
				w->UstawElement(nowy);
				w->UstawOjca(korzen);
				nowy->UstawPozycje(w);
				ostatni = w;
				++rozmiar;
			}
			else if (ostatni == korzen)                                                   // jesli ostatni wezel jest korzeniem
			{
				Wezel<E>* w = new Wezel<E>;
				korzen->UstawPoprzedni(w);
				w->UstawKlucz(droga);
				w->UstawOjca(korzen);
				w->UstawElement(nowy);
				nowy->UstawPozycje(w);
				ostatni = w;
				wGore(w);
				++rozmiar;
			}
			else if (ostatni == korzen->WezPoprzedni())
			{
				Wezel<E>* w = new Wezel<E>;
				korzen->UstawNastepny(w);
				w->UstawKlucz(droga);
				w->UstawOjca(ostatni->WezOjca());
				w->UstawElement(nowy);
				nowy->UstawPozycje(w);
				ostatni = w;
				wGore(w);
				++rozmiar;
			}
		}
		else if (ostatni == ostatni->WezOjca()->WezPoprzedni())                                    // jesli ostatni wezel jest lewym synem 
		{
			Wezel<E>* w = new Wezel<E>;
			ostatni->WezOjca()->UstawNastepny(w);
			w->UstawKlucz(droga);
			w->UstawOjca(ostatni->WezOjca());
			w->UstawElement(nowy);
			nowy->UstawPozycje(w);
			ostatni = w;
			wGore(w);
			++rozmiar;
		}
		else
		{
			while (ostatni == ostatni->WezOjca()->WezNastepny())                                   // dopoki wezel jest prawym synem idz do ojca
			{
				ostatni = ostatni->WezOjca();
				if (ostatni == korzen)
					break;
			}
			
			if (ostatni != korzen)                                                                 // jesli ojciec nie jest korzeniem
				if (ostatni == ostatni->WezOjca()->WezPoprzedni())                                 // a wezel jest lewym synem idz do prawego syna
				{
					ostatni = ostatni->WezOjca()->WezNastepny();
				}
			
			while (ostatni->WezPoprzedni() != nullptr)                                             // dopoki wezel jest wewnetrzny idz do lewego syna
			{
				ostatni = ostatni->WezPoprzedni();
			}

			Wezel<E>* w = new Wezel<E>;
			ostatni->UstawPoprzedni(w);
			w->UstawKlucz(droga);
			w->UstawElement(nowy);
			w->UstawOjca(ostatni);
			nowy->UstawPozycje(w);
			ostatni = w;
			wGore(w);
			++rozmiar;
		}
	}
	Wezel<E>* UsunMin()                       // zwraca wskaznik do najmniejszego elementu kolejki i usuwa go z niej
	{
		Wezel<E>* w;
		w = korzen;
		korzen = ostatni;
		if (rozmiar == 0)                                                         // jesli zostanie wywolane usuniecie elementu dla pustej kolejki
		{
			w = new Wezel<E>;
			w->UstawKlucz(-1);
			cout << "kolejka pusta, zwrocono element o kluczu -1" << endl;
			return w;
		}
		while (ostatni == ostatni->WezOjca()->WezPoprzedni() && rozmiar > 2)      // dopoki wezel jest lewym synem idz do ojca
			ostatni = ostatni->WezOjca();
		
		if (ostatni != w && ostatni == ostatni->WezOjca()->WezNastepny())         // jesli wezel nie jest korzeniem i jest prawym synem idz do lewego syna
		{
			ostatni = ostatni->WezOjca()->WezPoprzedni();
			while (ostatni->WezNastepny() != nullptr)
				ostatni = ostatni->WezNastepny();			
		}		
		
		if (ostatni == w )                                                        // jesli wezel jest korzeniem, dopoki jest wewnetrzny idz do prawego syna
			while(ostatni->WezNastepny()!=nullptr)
				ostatni = ostatni->WezNastepny();

		if (korzen->WezOjca()->WezNastepny() == korzen)                           // przeniesienie ostatniego wezla w miejsce korzenia
			korzen->WezOjca()->UstawNastepny(nullptr);
		else if (korzen->WezOjca()->WezPoprzedni())
			korzen->WezOjca()->UstawPoprzedni(nullptr);
		korzen->UstawNastepny(w->WezNastepny());
		korzen->UstawPoprzedni(w->WezPoprzedni());
		korzen->UstawOjca(korzen);
		if (w->WezNastepny() != nullptr)
			w->WezNastepny()->UstawOjca(korzen);
		if (w->WezPoprzedni() != nullptr)
			w->WezPoprzedni()->UstawOjca(korzen);
		if(w!=ostatni)
			w->UstawOjca(nullptr);
		w->UstawNastepny(nullptr);
		w->UstawPoprzedni(nullptr);
		wDol(korzen);                                                             // przeniesienie wezla w dol jesli klucz jest wiekszy niz ktoregos z synow
		--rozmiar;
		if (rozmiar == 1)                                                         // kiedy zostal jedynie korzen
		{
			korzen->UstawNastepny(nullptr);
			korzen->UstawPoprzedni(nullptr);
			ostatni = korzen;
		}
		if (rozmiar == 0)                                                         // kiedy kolejka jest pusta
		{ 
			korzen = nullptr;
			ostatni = nullptr;
		}
		return w;
	}
};