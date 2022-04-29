#pragma once

#include <vector>

class Polozenie {
	int X, Y;
protected:
	std::vector <Polozenie*> GetPolaDlaDzieci(Polozenie partner, int X, int Y);
	std::vector <Polozenie*> GetPolaDlaDzieci(int X, int Y);
	bool operator ==(Polozenie other);
	void operator *( int x);
	virtual std::vector <Polozenie*>  przesuniecie(int X, int Y);
public:
	Polozenie(int x,int y);
	Polozenie();
	void setX(int x);
	void setY(int y);
	int getX();
	int getY();
	~Polozenie();
};