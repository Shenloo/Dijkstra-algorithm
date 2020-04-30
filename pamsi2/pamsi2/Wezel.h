#pragma once
#include<iostream>

using namespace std;

template <typename E>
class Wezel
{
	int klucz;
	E* element;                                                                    // wskaznik do przechowywanego elementu
	Wezel* nastepny;                                                               // wskaznik na nastepny wezel (prawy syn w kolejce)
	Wezel* poprzedni;                                                              // wskaznik na poprzedni wezel (lewy syn w kolejce)
	Wezel* ojciec;                                                                 // wskaznik na ojca w kolejce

public:
	Wezel() { klucz = 0; element = nullptr; nastepny = nullptr; poprzedni = nullptr; ojciec = nullptr; } // konstruktor
	~Wezel() { }						                          			       // destruktor
	void UstawKlucz(int k) { klucz = k; }                                          // ustawia klucz wezla
	int WezKlucz() { return klucz; }                                               // zwraca klucz danego wezla
	E* WezElement() { return element; }                                            // zwraca wskaznik do elementu na liscie
	Wezel* WezNastepny() { return nastepny; }                                      // zwraca wskaznik do nastepnego wezla
	Wezel* WezPoprzedni() { return poprzedni; }                                    // zwraca wskaznik do poprzedniego wezla
	Wezel* WezOjca() { return ojciec; }                                            // zwraca wskaznik do ojca w kolejce
	void UstawElement(E* nowy) { element = nowy; }                                 // przypisuje element do wezla
	void UstawNastepny(Wezel* nowy) { nastepny = nowy; }                           // przypisuje do wezla kolejny wezel
	void UstawPoprzedni(Wezel* nowy) { poprzedni = nowy; }                         // przypisuje do wezla poprzedni wezel
	void UstawOjca(Wezel* nowy) { ojciec = nowy; }                                 // przypisuje do wezla jego ojca
};