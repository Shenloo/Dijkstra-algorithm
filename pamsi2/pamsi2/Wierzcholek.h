#pragma once
#include<iostream>
#include"Wezel.h"
#include"Lista.h"


using namespace std;

/* Klasa wierzcholek
 * zawiera referencjê do pozycji w liscie oraz pole z wartoscia
 *
 */
template<typename E>
class Wierzcholek
{
	Lista<E>* incydencje;	   													     	  // wskaŸnik do listy referencji do krawedzi incydentnych
	Wezel<Wierzcholek>* pozycja;                                                          // referencja do pozycji w liscie wierzcholkow
	int pole_wierzcholka;
	int klucz;
public:
	Wierzcholek() { pole_wierzcholka = 0; klucz = 0; pozycja = nullptr; incydencje = nullptr; } //konstruktor
	~Wierzcholek() 
	{ 
		if(incydencje!= nullptr)
			while (!incydencje->Pusta()) 
				incydencje->UsunWezel(); 
	};
	void UstawPozycje(Wezel<Wierzcholek>* w) { pozycja = w; }
	void UstawPole(int p) { pole_wierzcholka = p; }                                             // "nazwa" wierzcholka
	void UstawKlucz(int k) { klucz = k; }                                                       // przechowuje odleglosc 
	void UstawListeIncydencji(Lista<E>* L) { incydencje = L; }                                  // przypisuje listê incydencji danemu wierzcholkowi
	void DodajIncydencje(E* krawedz) { incydencje->DodajKoniec(krawedz); }                      // dodaje krawedz incydentna do listy
	Wezel<E>* IncydencjeKoniec() { return incydencje->Koniec(); }                               // zwraca referencje do obiektu z listy incydencji
	Wezel<E>* IncydencjePoczatek() { return incydencje->Poczatek(); }
	int IleIncydencji() { return incydencje->Rozmiar(); }
	int PoleWierzcholka() { return pole_wierzcholka; }
	Wezel<Wierzcholek>* ZwrocPozycje() { return pozycja; }
	int WezKlucz() { return klucz; }
};