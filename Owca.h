#pragma once
#pragma once
#include "Zwierze.h"
class Owca : public Zwierze {
	bool czy_ten_gatunek(Organizm* other);
	void rozmnoz(Organizm* other) override;

public:
	Owca(Polozenie punkt,Swiat* swiat);
	char znak_Ascii()override;
	void napisz1() override;
	void napisz2() override;
};
