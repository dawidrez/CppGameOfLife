#pragma once
#include "Roslina.h"
class Trawa : public Roslina {
	void zasiej( Polozenie* punkt) override;
	int szansa();
    Trawa(Polozenie punkt,Swiat* swiat);
	~Trawa();
	void napisz1() override;
	void napisz2() override;
	char znak_Ascii()override;
};

