#pragma once
#include<iostream>
#include"GrafLista.h"
#include"GrafMacierz.h"
#include"Lista.h"
#include"Kolejka.h"

#define INF 1000000

using namespace std;

void DijkstraLista(GrafLista* G, Wierzcholek<Krawedz>* w)
{
	Kolejka<Wierzcholek<Krawedz>>* Q = new Kolejka<Wierzcholek<Krawedz>>;
	Wezel<Wierzcholek<Krawedz>>* x = G->Wierzcholki()->Poczatek();
	Wezel<Krawedz>* k = nullptr;
	Wierzcholek<Krawedz>* c = nullptr;
	Wierzcholek<Krawedz>* u = nullptr;
	int r;
	while (x != G->Wierzcholki()->Koniec())
	{
		if (x->WezElement() == w)
			x->UstawKlucz(0);
		else
			x->UstawKlucz(INF);
		Q->Dodaj(x->WezElement(), x->WezKlucz());
		x = x->WezNastepny();
		if (x == G->Wierzcholki()->Koniec())
		{
			if (x->WezElement() == w)
				x->UstawKlucz(0);
			else
				x->UstawKlucz(INF);
			Q->Dodaj(x->WezElement(), x->WezKlucz());
		}
	}
	x = nullptr;
	while (!Q->Pusta())
	{
		u = Q->UsunMin()->WezElement();
		k = u->IncydencjePoczatek();
		while (k != x->WezElement()->IncydencjeKoniec())
		{
			c = G->Przeciwlegly(u, k->WezElement());
			r = u->WezKlucz() + k->WezKlucz();
			if (r < c->WezKlucz())
			{
				c->UstawKlucz(r);

			}
		}
	}
}

void DijkstraMacierz(GrafMacierz* G, Wierzcholek<Krawedz>* w)
{

}