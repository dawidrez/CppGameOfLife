#pragma once
#include "Roslina.h"
class Mlecz : public Roslina {
	void zasiej(Polozenie* punkt) override;
	int szansa();
	Mlecz(Polozenie punkt, Swiat* swiat);
	~Mlecz();
	void napisz1() override;
	void napisz2() override;
	char znak_Ascii()override;
	int ileProb() override;
};
