#pragma once
#include <iostream>
#include <vector>
class Polozenie;
class Swiat;
#include "Swiat.h"
#include "Polozenie.h"
class Organizm:public Polozenie {
	protected:
	int sila, inicjatywa, wiek;
	Swiat* swiat;
	Polozenie punkt;
	bool mozliwoscRuchu;
	bool zywy;
public:
	std::vector <Polozenie*> przesuniecie_wolne(Swiat* swiat);
	virtual void akcja() = 0;
	virtual bool czy_efekt_zjedzenie();
	virtual void efekt_zjedzenie(Polozenie pumkt);
	char virtual znak_Ascii() = 0;
	int getWiek();
	Organizm();
	    void setPolozenie(Polozenie punkt);
		Polozenie getPolozenie() const;
		void setMozliwoscRuchu(bool moznosc);
		bool getMozliwoscRuchu();
		void virtual napisz1() = 0;
		void virtual napisz2() = 0;
		int getSila()  const;
		int getInicjatywa()  const;
		bool virtual czy_odpiera(Organizm* atakujacy);
		bool virtual  czy_ucieczka();
		bool czy_zywy()  const;
		void setZycie(bool zycie);
		std::vector <Polozenie*> ucieknij();
		Organizm(int sila,int inicjatywa,Swiat* swiat,Polozenie punkt);
};

