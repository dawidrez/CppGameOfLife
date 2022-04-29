#pragma once
#include "Polozenie.h"
using namespace std;
void Polozenie::setX(int x) {
	this->X = x;
}
Polozenie::Polozenie() {
	X = 0;
	Y = 0;
}
int Polozenie::getX() {
	return X;
}
void Polozenie::setY(int y) {
	this->Y = y;
}
int Polozenie::getY() {
	return Y;
}
bool Polozenie::operator==(Polozenie right) {
	if (this->X == right.getX())
		if (this->Y == right.getY())
			return true;
	return false;
}
void Polozenie::operator*(int x) {
	setX(this->getX() * x);
	setY(this->getY() * x);
}

vector <Polozenie*>  Polozenie::przesuniecie(int x,int y) {
	vector<Polozenie*>pola;
	if (this->getX() - 1 >= 0)
		pola.push_back(new Polozenie(this->getX() - 1, this->getY()));
	if (this->getY() - 1 >= 0)
		pola.push_back(new Polozenie(this->getX(), this->getY()-1));
	if (this->getX() + 1 >=x)
		pola.push_back(new Polozenie(this->getX() + 1, this->getY()));
	if (this->getY() + 1 >= y)
		pola.push_back(new Polozenie(this->getX(), this->getY() + 1));	
		return pola;
}



Polozenie::Polozenie(int x, int y)
{
	X = x;
	Y = y;
}
Polozenie::~Polozenie()
{
}




vector <Polozenie*> Polozenie::GetPolaDlaDzieci(int x,int y) {
	vector<Polozenie*> pola;
	int x1 = this->getX();
	int y1 = this->getY();
	if (x1 > 0)
		{
			pola.push_back(new Polozenie(x1 - 1, y1));
		}
		if (x1 < x)
		{
			pola.push_back(new Polozenie(x1 + 1, y1));
		}
		if (y1 > 0)
		{		
				pola.push_back(new Polozenie(x1, y1 - 1));
		}
		if (y1 < y)
		{
			
				pola.push_back(new Polozenie(x1, y1 + 1));
		}
	return pola;
}
vector<Polozenie*> Polozenie::GetPolaDlaDzieci(Polozenie partner,int x,int y) {
	vector<Polozenie*> pola;
	int x1 = this->getX();
	int x2 = partner.getX();
	int y1 = this->getY();
	int y2 = partner.getY();
	if (x1 == x2)
	{
		if (x1 > 0)
		{
			pola.push_back(new Polozenie(x1 - 1, y1));
			pola.push_back(new Polozenie(x1 - 1, y2));
		}
		if (x1 <x)
		{
			pola.push_back(new Polozenie(x1 + 1, y1));
			pola.push_back(new Polozenie(x1 + 1, y2));
		}
		if (y1 > 0 && y2 > 0)
		{
			if (y1 > y2)
				pola.push_back(new Polozenie(x1, y2 - 1));
			else
				pola.push_back(new Polozenie(x1, y1 - 1));
		}
		if (y1 <y && y2 < y)
		{
			if (y1 > y2)
				pola.push_back(new Polozenie(x1, y1 + 1));
			else
				pola.push_back(new Polozenie(x1, y2 + 1));
		}

	}
	else
	{
		if (y1 > 0)
		{
			pola.push_back(new Polozenie(x1, y1 - 1));
			pola.push_back(new Polozenie(x2, y2 - 1));
		}
		if (y1 < y)
		{
			pola.push_back(new Polozenie(x1, y1 + 1));
			pola.push_back(new Polozenie(x1, y2 + 1));
		}
		if (x1 > 0 && x2 > 0)
		{
			if (x1 > x2)
				pola.push_back(new Polozenie(x2 - 1, y2));
			else
				pola.push_back(new Polozenie(x1 - 1, y1));
		}
		if (y1 <y && y2 < y)
		{
			if (y1 > y2)
				pola.push_back(new Polozenie(x1 + 1, y1));
			else
				pola.push_back(new Polozenie(x1 + 1, y2));
		}

	}
	return pola;
}