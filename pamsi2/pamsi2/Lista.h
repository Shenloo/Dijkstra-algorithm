#pragma once
#include<iostream>
#include"Wezel.h"

using namespace std;

template<typename E>
class Lista
{
	int rozmiar;                                                              // rozmiar listy
	Wezel<E>* poczatek;                                                       // wskaznik na pierwszy element
	Wezel<E>* koniec;                                                        // wskaznik na ostatni element
public:
	Lista() { rozmiar = 0; poczatek = nullptr; koniec = nullptr; }            // konstruktor
	~Lista() { while (!Pusta()) UsunPoczatek(); }                             // destruktor
	bool Pusta() { if (rozmiar == 0) return true; else return false; }        // sprawdza, czy lista jest pusta
	int Rozmiar() { return rozmiar; }                                         // zwraca rozmiar listy
	Wezel<E>* Koniec() { if (!Pusta()) return koniec; else return nullptr; }    // zwraca wskaünik na ostatni element listy
	Wezel<E>* Poczatek() { if (!Pusta()) return poczatek; else return nullptr; }// zwraca wskaünik na pierwszy element listy
	void DodajKoniec(E* nowy)                                                 // dodaje nowy element na koniec listy i zwieksza jej rozmiar
	{
 		if (rozmiar == 0)                                                     // ustawia wskazniki na poczatek i koniec w przypadku pustej listy
		{                                                                     // dodaje pierwszy element i zwieksza rozmiar listy
			Wezel<E>* v = new Wezel<E>;
			v->UstawElement(nowy);
			v->UstawKlucz(rozmiar);
			poczatek = v;
			koniec = v;
			v->UstawPoprzedni(poczatek);
			v->UstawNastepny(koniec);
			++rozmiar;
		}
		else
		{
			Wezel<E>* v = new Wezel<E>;                                       // dodaje wezel na koniec listy, aktualizuje wskaznik koniec
			v->UstawElement(nowy);                                            // i zwieksza rozmiar listy
			v->UstawKlucz(rozmiar);
			v->UstawPoprzedni(koniec);
			koniec = v;
			v->WezPoprzedni()->UstawNastepny(v);
			v->UstawNastepny(koniec);

			++rozmiar;
		}
	}
	void UsunPoczatek()                                                      // usuwa wezel z poczatku listy
	{
		if (rozmiar > 0)                                                     // sprawdzenie czy na poczatku jest jakis element
		{
			Wezel<E>* stary = poczatek;
			E* x = stary->WezElement();                                       // sprawdzenie, czy element nie zostal wczesniej usuniety
			delete x;
			poczatek = poczatek->WezNastepny();
			poczatek->UstawPoprzedni(poczatek);
			delete stary;
			--rozmiar;
			if (rozmiar == 0)
			{
				poczatek = nullptr;
				koniec = nullptr;
			}
		}
		else if (rozmiar == 0)                                              // jesli lista jest pusta wyswietla komunikat
		{
			cout << "Nie mozna usunac, lista jest pusta" << endl;
		}
	}
	void UsunWezel(Wezel<E>* w)                                              // usuwa wybrany wezel
	{
		if (rozmiar > 0)                                                     // sprawdzenie czy na poczatku jest jakis element
		{
			w->WezPoprzedni()->UstawNastepny(w->WezNastepny());
			w->WezNastepny()->UstawPoprzedni(w->WezPoprzedni());
			--rozmiar;
			if (rozmiar == 0)
			{
				poczatek = nullptr;
				koniec = nullptr;
			}
		}
		else if (rozmiar == 0)                                              // jesli lista jest pusta wyswietla komunikat
		{
			cout << "Nie mozna usunac, lista jest pusta" << endl;
		}
	}
	void UsunWezel()                                                         // usuwa po kolei wszystkie wezly
	{
		if (rozmiar > 0)                                                     // sprawdzenie czy na poczatku jest jakis element
		{
			Wezel<E>* stary = poczatek;
			poczatek = poczatek->WezNastepny();
			delete stary;
			--rozmiar;
			if (rozmiar == 0)
			{
				poczatek = nullptr;
				koniec = nullptr;
			}
		}
		else if (rozmiar == 0)                                              // jesli lista jest pusta wyswietla komunikat
		{
			cout << "Nie mozna usunac, lista jest pusta" << endl;
		}
	}
};