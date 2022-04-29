#pragma once
#include <iostream>
#include "Roslina.h"
#define PRAWDOPODOBIENSTWO 5
using namespace std;

bool Roslina::czy_rozsiewa() {
	int random = rand() % PRAWDOPODOBIENSTWO;
	if (this->szansa() > random)
		return true;
	return false;

}
void Roslina::rozsiej() {
	if (this->czy_rozsiewa())
	{
		vector<Polozenie*> pola=this->GetPolaDlaDzieci(this->swiat->GetX(),this->swiat->GetY());
		int rozmiar = pola.size();
		int i=0;
		while ( rozmiar>0)
		{
			Organizm* tmp=this->swiat->Organizm_punkt(*pola[i]);
			if (tmp != nullptr)
			{
				pola.erase(pola.begin() + i);
			}
			else
				i++;
			rozmiar--;
		}
		 rozmiar = pola.size();
		 if (rozmiar > 0)
		 {
			 int random = rand() % rozmiar;
			 this->zasiej(pola[random]);

		}
		
	}
}




Roslina::Roslina(int sila, int inicjatywa, Swiat* swiat, Polozenie punkt):
Organizm(sila,inicjatywa,swiat,punkt){

}

Roslina::~Roslina() {

}

int Roslina::ileProb() {
	return 1;
}


void Roslina::akcja() {
	if (this->czy_rozsiewa())
		this->rozsiej();

}
