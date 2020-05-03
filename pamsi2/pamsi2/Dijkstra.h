#pragma once
#include<iostream>
#include"GrafLista.h"
#include"GrafMacierz.h"
#include"Lista.h"
#include"Kolejka.h"

#define INF 1000000

using namespace std;

int * DijkstraLista(GrafLista* G, Wierzcholek<Krawedz>* w,int poprzednik[])
{
	Kolejka<Wierzcholek<Krawedz>>* Q = new Kolejka<Wierzcholek<Krawedz>>;
	Wezel<Wierzcholek<Krawedz>>* x = G->Wierzcholki()->Poczatek();
	Wezel<Krawedz>* k = nullptr;
	Wierzcholek<Krawedz>* z = nullptr;
	Wierzcholek<Krawedz>* u = nullptr;
	int r;
	for(int i =0;i<G->Wierzcholki()->Rozmiar();++i)
	{
		if (x->WezElement() == w)
		{
			x->UstawKlucz(0);
			x->WezElement()->UstawKlucz(0);
			poprzednik[x->WezElement()->PoleWierzcholka()] = x->WezElement()->PoleWierzcholka();
		}
		else
		{
			x->UstawKlucz(INF);
			x->WezElement()->UstawKlucz(INF);
		}	
		Q->Dodaj(x->WezElement(), x->WezElement()->WezKlucz());
		x = x->WezNastepny();
	}
	x = nullptr;
	for (int j = 0; j < Q->Rozmiar(); ++j)
	{
		u = Q->UsunMin()->WezElement();
		k = u->IncydencjePoczatek();
		for (int i = 0; i < u->IleIncydencji(); ++i)
		{
			z = G->Przeciwlegly(u, k->WezElement());
			x = z->ZwrocPozycje();
			r = u->WezKlucz() + k->WezElement()->PoleKrawedzi();
			if (r < z->WezKlucz())
			{
				z->UstawKlucz(r);
				if (z->ZwrocPozycje() != nullptr)
				{
					Q->Dodaj(z,r);
					poprzednik[z->PoleWierzcholka()] = u->PoleWierzcholka();
				}	
			}
			k = k->WezNastepny();
		} 

	}
	delete Q;
	return poprzednik;
}

void DijkstraMacierz(GrafMacierz* G, Wierzcholek<Krawedz>* w,int poprzednik[])
{
	Kolejka<Wierzcholek<Krawedz>>* Q = new Kolejka<Wierzcholek<Krawedz>>;
	Wezel<Wierzcholek<Krawedz>>* x = G->Wierzcholki()->Poczatek();
	Wezel<Krawedz>* k = nullptr;
	Lista<Krawedz>* o = nullptr;
	Wierzcholek<Krawedz>* z = nullptr;
	Wierzcholek<Krawedz>* u = nullptr;
	int r;
	for (int i = 0; i < G->Wierzcholki()->Rozmiar(); ++i)
	{
		if (x->WezElement() == w)
		{
			x->UstawKlucz(0);
			x->WezElement()->UstawKlucz(0);
			poprzednik[x->WezElement()->PoleWierzcholka()] = x->WezElement()->PoleWierzcholka();
		}
		else
		{
			x->UstawKlucz(INF);
			x->WezElement()->UstawKlucz(INF);
		}
		Q->Dodaj(x->WezElement(), x->WezElement()->WezKlucz());
		x = x->WezNastepny();
	}
	x = nullptr;
	for (int j = 0; j < Q->Rozmiar(); ++j)
	{
		u = Q->UsunMin()->WezElement();
		o = G->Incydentne(u);
		k = o->Poczatek();
		for (int i = 0; i < o->Rozmiar(); ++i)
		{
			z = G->Przeciwlegly(u, k->WezElement());
			x = z->ZwrocPozycje();
			r = u->WezKlucz() + k->WezElement()->PoleKrawedzi();
			if (r < z->WezKlucz())
			{
				z->UstawKlucz(r);
				if (z->ZwrocPozycje() != nullptr)
				{
					Q->Dodaj(z, r);
					poprzednik[z->PoleWierzcholka()] = u->PoleWierzcholka();
				}
			}
			k = k->WezNastepny();
		}
		while (o->Pusta())
			o->UsunWezel();
	}
	delete Q;
}