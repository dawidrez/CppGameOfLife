#include <iostream>
#include "Swiat.h"
class Zwierze;
#include <Windows.h>
using namespace std;

void Swiat::narysujPlansze() {
	for (int i = 0;i <= Y + 1;i++)
	{
		for (int j = 0;j <= X + 1;j++) {
			cout << znaki[i][j];
		}
		cout << endl;
	}
}

void Swiat::zabij(Polozenie punkt) {
	Organizm* tmp=this->Organizm_punkt(punkt);
	tmp->setZycie(false);
	this->do_usuniecia1.push_back(tmp);
}


void Swiat::uaktualnij_znaki() {
	for (int i = 1;i <= Y;i++)
	{
		for (int j = X;j <= X;j++)
			znaki[i][j] = ' ';
	}
	int x;
	int y;
	char znak;
	int rozmiar = organizmy.size();
	for (int i = 0;i <rozmiar;i++)
	{
		x = organizmy[i]->getX();
		y =organizmy[i]->getY();
		znak = organizmy[i]->znak_Ascii();
		znaki[y][x] = znak;
	}
}

Swiat::Swiat(int x, int y,int tura ) {
	this->wysokosc_pisania = 0;
	this->tura = tura;
	this->X = x;
	this->Y = y;
    znaki = new char*[y+1];
	char* linijki = new char[(x+1)*(y+1)];
	for (int i = 0;i < y + 1;i++)
	{
		znaki[i] = linijki+(i * (x + 1));
	}
	for (int i = 0;i <= y + 1;i++)
	{
		for (int j = 0;j <= x + 1;j++)
			if (i == 0 || i == y + 1)
				znaki[i][j] = '-';
			else if(j==0||j==x+1)
				znaki[i][j] = ' ';
	}
} 

int Swiat::GetX() {
	return this->X;
}
int Swiat::GetY(){
	return this->Y;
}
Organizm* Swiat::Organizm_punkt(Polozenie punkt) {
	int liczba_organizmow = this->organizmy.size();
	for (int i = 0;i < liczba_organizmow;i++)
		if (this->organizmy[i]->getX() == punkt.getX())
			if (this->organizmy[i]->getY() == punkt.getY())
				return this->organizmy[i];
	return nullptr;
}

void Swiat::dodaj_organizm(Organizm* nowy) {
	this->organizmy.push_back(nowy);
}
vector<Organizm*> Swiat::getOrganizmy() {
	return this->organizmy;
}
int Swiat::getTura() {
	return this->tura;
}

void Swiat::wykonajTure() {
	int rozmiar = this->organizmy.size();
	for (int i = 0;i < rozmiar;i++)
		this->organizmy[i]->akcja();
}

int Swiat:: Max (int i) {
	int max_inicjatywa = this->organizmy[i]->getInicjatywa();
	int max_wiek = this->organizmy[i]->getWiek();
	int max_index = i;
	int inicjatywa;
	int wiek;
	int rozmiar = this->organizmy.size();
	for (int j = i + 1;j < rozmiar;j++)
	{
		inicjatywa = this->organizmy[j]->getInicjatywa();
		wiek = this->organizmy[i]->getWiek();
		if (inicjatywa > max_inicjatywa || inicjatywa == max_inicjatywa &&wiek>max_wiek)
		{
			max_inicjatywa = inicjatywa;
			max_wiek = wiek;
			max_index = j;
		}		
	}
	return max_index;
}


void Swiat::kolejnosc() {
	int index_max;
	int rozmiar = this->organizmy.size() - 1;
	for (int i = 0;i < rozmiar;i++)
	{
		index_max = Max(i);
		if (index_max != i)
		{
			Organizm* tmp = this->organizmy[i];
			this->organizmy[i] = this->organizmy[index_max];
			this->organizmy[index_max] = tmp;
		}
	}
}










