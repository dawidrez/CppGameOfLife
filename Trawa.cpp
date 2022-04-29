#pragma once
#include "Trawa.h"
#define SILA_TRAWY 0
#define INICJATYWA_TRAWY 0
using namespace std;
Trawa::Trawa(Polozenie punkt,Swiat* swiat):
	Roslina(SILA_TRAWY, INICJATYWA_TRAWY, swiat, punkt) {
}

void Trawa::napisz1() {
	cout << "trawa";
}

void Trawa::napisz2() {
	cout << "trawe";
}
char Trawa::znak_Ascii() {
	return 'T';
}

int Trawa::szansa() {
	return 3;
}

void Trawa::zasiej(Polozenie* punkt) {
	Trawa* trawka = new Trawa ( *punkt,this->swiat);
	this->swiat->dodaj_organizm(trawka);
}

Trawa::~Trawa() {

}