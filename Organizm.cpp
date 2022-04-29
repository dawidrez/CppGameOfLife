#pragma once
#include "Organizm.h"
using namespace std;
int Organizm::getSila() const {
	return this->sila;
}
int Organizm::getInicjatywa() const {
	return this->inicjatywa;
}
bool Organizm::czy_odpiera(Organizm* atakujacy) {
	return false;
}
bool Organizm::czy_ucieczka() {
	return false;
}

void Organizm::setPolozenie(Polozenie punkt) {
	this->punkt = punkt;
}

Polozenie Organizm::getPolozenie()  const {
return	this->punkt ;
}


bool Organizm::czy_efekt_zjedzenie() {
	return false;
}

void  Organizm::efekt_zjedzenie(Polozenie punkt) {
}

bool Organizm::getMozliwoscRuchu() {
	return this->mozliwoscRuchu;
}

void Organizm::setMozliwoscRuchu(bool moznosc) {
 this->mozliwoscRuchu=moznosc;
}



int Organizm::getWiek() {
	return this->wiek;
}

bool Organizm::czy_zywy() const {
	return zywy;
}

Organizm::Organizm() {

}
void Organizm::setZycie(bool zycie) {
	zywy = zycie;	
}


vector<Polozenie*> Organizm::przesuniecie_wolne(Swiat* swiat) {
	vector<Polozenie*>pola;
	if (this->getX() - 1 >= 0)
		pola.push_back(new Polozenie(this->getX() - 1, this->getY()));
	if (this->getY() - 1 >= 0)
		pola.push_back(new Polozenie(this->getX(), this->getY() - 1));
	if (this->getX() + 1 >= swiat->GetX())
		pola.push_back(new Polozenie(this->getX() + 1, this->getY()));
	if (this->getY() + 1 >= swiat->GetY())
		pola.push_back(new Polozenie(this->getX(), this->getY() + 1));
	int rozmiar = pola.size();
	for (int i = 0;i < rozmiar;i++)
	{
		Organizm* tmp = swiat->Organizm_punkt(*pola[i]);
		if (tmp != nullptr)
		{
			if (tmp->getSila() < 3)
				continue;
		}
		pola.erase(pola.begin() + i);
	}
	return pola;
}

vector <Polozenie*> Organizm::ucieknij() {
	vector<Polozenie*>pola= this->przesuniecie_wolne(this->swiat);
		return pola;
}
Organizm::Organizm(int sila, int inicjatywa,  Swiat* swiat, Polozenie punkt):
sila(sila),inicjatywa(inicjatywa),wiek(0),swiat(swiat),punkt(punkt),mozliwoscRuchu(false),zywy(true)
{

}