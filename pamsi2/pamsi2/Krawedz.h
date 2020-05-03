#pragma once
#include"Wierzcholek.h"
#include"Wezel.h"

using namespace std;

/* Klasa Krawedz
 * Zawiera referencje do pozycji w liscie, wskazniki do wierzcholka poczatkowego i koncowego oraz pole z wartoscia
 *
 */
class Krawedz
{
	Wezel<Krawedz>* pozycja;                                              // referencja do pozycji w liscie krawedzi
	Wezel<Krawedz>* pierwszy;                                             // referencja do pozycji w liscie krawedzi incydentnych
	Wezel<Krawedz>* drugi;         
	Wierzcholek<Krawedz>* poprzedni;                                      // wskazniki na wierzcholki na koncach krawedzi
	Wierzcholek<Krawedz>* nastepny;
	int pole_krawedzi;
public:
	Krawedz() 
	{
		pole_krawedzi = 0; pozycja = nullptr; 
		poprzedni = nullptr; nastepny = nullptr;
		pierwszy = nullptr; drugi = nullptr;
	}
	~Krawedz() { }
	void UstawPozycje(Wezel<Krawedz>* w) { pozycja = w; }                    // ustawia referencje do pozycji w liscie krawedzi
	void UstawPole(int k) { pole_krawedzi = k; }                             // ustawia pole krawedzi
	void UstawIncydencje(Wezel<Krawedz>* w1, Wezel<Krawedz>* w2)             // ustawia referencje do pozycji w liscie krawedzi incydentnych
	{
		pierwszy = w1;
		drugi = w2;
	}            
	void UstawWierzcholki(Wierzcholek<Krawedz>* w1, Wierzcholek<Krawedz>* w2 )  // ustawia wierzcholki koncowe krawedzi
	{
		poprzedni = w1;
		nastepny = w2;
	}
	Wierzcholek<Krawedz>* Poprzedni() { return poprzedni; }
	Wierzcholek<Krawedz>* Nastepny() { return nastepny; }
	int PoleKrawedzi() { return pole_krawedzi; }
};