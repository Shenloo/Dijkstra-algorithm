#pragma once
#include<iostream>
#include"Wezel.h"

using namespace std;

template<typename E>
class Kolejka
{
	int rozmiar;
	Wezel<E>* korzen;
	Wezel<E>* ostatni;
public:
	Kolejka() { rozmiar = 0; korzen = nullptr; ostatni = nullptr; }
	~Kolejka() { }
	Wezel<E>* Korzen() { return korzen; }
	bool Pusta() { if (korzen == nullptr) return true; else return false; }
	void ZmienKlucz(Wezel<E>* w, int k) { w->UstawKlucz(k); }
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

				if (w->WezNastepny() != nullptr) cout << w->WezNastepny()->WezKlucz() << endl;
				else cout << "-" << endl;
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

				if (w->WezNastepny() != nullptr) cout << w->WezNastepny()->WezKlucz() << endl;
				else cout << "-" << endl;
			}
			cout << "f" << endl;
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

				if (w->WezNastepny() != nullptr) cout << w->WezNastepny()->WezKlucz() << endl;
				else cout << "-" << endl;
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

				if (w->WezNastepny() != nullptr) cout << w->WezNastepny()->WezKlucz() << endl;
				else cout << "-" << endl;
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
						w->UstawNastepny(nullptr);
						najmniejszy->UstawPoprzedni(w);
						najmniejszy->UstawOjca(korzen);
						w->UstawPoprzedni(nullptr);
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
					wDol(w);
				}
			}
		}
	}
	void Dodaj(E* nowy,int droga)                                                          // dodaje wezel do kolejki
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
				ostatni = w;
				++rozmiar;
			}
			else if (ostatni == korzen )                                                   // jesli ostatni wezel jest korzeniem
			{
				Wezel<E>* w = new Wezel<E>;
				korzen->UstawPoprzedni(w);
				w->UstawKlucz(droga);
				w->UstawOjca(korzen);
				w->UstawElement(nowy);
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
			ostatni = w;
			wGore(w);
			++rozmiar;
		}
		cout << ostatni->WezKlucz() << " " << ostatni->WezOjca()->WezKlucz() << endl;
	}
	Wezel<E>* UsunMin()                       // zwraca wskaznik do najmniejszego elementu kolejki i usuwa go zniej
	{
		Wezel<E>* w;
		w = korzen;
		korzen = ostatni;
		while (ostatni == ostatni->WezOjca()->WezPoprzedni())                                   // dopoki wezel jest lewym synem idz do ojca
		{
			ostatni = ostatni->WezOjca();
			if (ostatni == w)
				break;
		}
		if (ostatni != w)                                                                      // jesli ojciec nie jest korzeniem
			if (ostatni == ostatni->WezOjca()->WezNastepny())                                 // a wezel jest prawym synem idz do lewego syna
			{
				ostatni = ostatni->WezOjca()->WezPoprzedni();
			}
		while (ostatni->WezNastepny() != nullptr)                                             // dopoki wezel jest wewnetrzny idz do prawego syna
		{
			ostatni = ostatni->WezNastepny();
		}
		if (rozmiar == 3)
			ostatni = w->WezNastepny();
		if (rozmiar == 2)
			ostatni = w->WezPoprzedni();
		if (rozmiar == 1)
			ostatni = w;
		if (korzen == korzen->WezOjca()->WezNastepny())                                           // jesli ostatni wezel byl prawym synem
			korzen->WezOjca()->UstawNastepny(nullptr);
		else if (ostatni == korzen->WezOjca()->WezPoprzedni())
			korzen->WezOjca()->UstawPoprzedni(nullptr);

		korzen->UstawPoprzedni(w->WezPoprzedni());                                           // wstawienie ostatniego wezla w miejsce korzenia
		korzen->UstawNastepny(w->WezNastepny());
		if(w->WezPoprzedni()!=nullptr)
			korzen->WezPoprzedni()->UstawOjca(korzen);
		if(w->WezNastepny()!=nullptr)
			korzen->WezNastepny()->UstawOjca(korzen);
		wDol(korzen);
		--rozmiar;
		if (rozmiar == 0)
		{
			korzen = nullptr;
			ostatni = nullptr;
		}
		return w;
	}
};