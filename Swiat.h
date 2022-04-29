#pragma once
#include <iostream>
#include "Organizm.h"
#include "Polozenie.h"
class Komentator;
class Zwierze;
class Organizm;
#include <vector>
class Swiat{
	std::vector<Organizm*> organizmy;
	std::vector<Organizm*> do_usuniecia1;
	std::vector<Zwierze*> do_usuniecia2;
	int X,Y;
	int tura;
	int Max(int i);
	int wysokosc_pisania;
	char** znaki;

public:
	void uaktualnij_znaki();
	Organizm* Organizm_punkt(Polozenie punkt);
	Swiat(int x,int y,int tura);
	int getTura();
	void zabij(Polozenie punkt);
	void wykonajTure();
	void kolejnosc();
	void narysujPlansze();
	int GetX();
	int GetY();
	void dodaj_organizm(Organizm* nowy);
	std::vector<Organizm*> getOrganizmy();
};