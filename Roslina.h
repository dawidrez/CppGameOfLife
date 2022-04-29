
#pragma once
#include <iostream>
#include "Swiat.h"
#include "Organizm.h"
class Roslina : public Organizm {
protected:
	
	bool czy_rozsiewa();
	void rozsiej();
	int virtual szansa()=0;
	void virtual zasiej(Polozenie* punkt)=0;
	int virtual ileProb();
public:
	void akcja() override;
	Roslina(int sila, int inicjatywa, Swiat* swiat, Polozenie punkt);
	~Roslina();
};