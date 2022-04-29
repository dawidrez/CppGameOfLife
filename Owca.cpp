#pragma once
#include "Owca.h"
#define SILA_OWCY 4
#define INICJATYWA_OWCY 4 
using namespace std;
Owca::Owca(Polozenie punkt,Swiat* swiat):
	Zwierze(SILA_OWCY, INICJATYWA_OWCY,swiat, punkt) {
}

bool Owca::czy_ten_gatunek(Organizm* other) {
	Owca* temp_a = dynamic_cast<Owca*>(other);
	return temp_a != nullptr;
}
void Owca::rozmnoz(Organizm* other) {
	vector<Polozenie*> pola = this->GetPolaDlaDzieci(other->getPolozenie(), this->swiat->GetX(), this->swiat->GetY());
	int ilosc_miejsc = pola.size();
	int index = rand() % ilosc_miejsc;
	Owca* owieczka = new Owca(*pola[index],this->swiat);
	swiat->dodaj_organizm(owieczka);
}
void Owca::napisz1() {
	cout << "owca";
}
void Owca::napisz2() {
	cout << "owce";
}
char Owca::znak_Ascii() {
	return 'O';
}