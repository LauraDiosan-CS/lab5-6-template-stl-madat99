
#include "stdafx.h"
#include"stdafx.h"
#include<iostream>
#include <fstream>
using namespace std;

#ifndef DULCIURI_H
#define DULCIURI_H

class Dulciuri {
private:
	char* nume;
	int cod;
	int pret;
public:
	Dulciuri();
	Dulciuri(char* n, int c, int p);
	Dulciuri(const Dulciuri &c);
	~Dulciuri();
	Dulciuri&operator=(const Dulciuri&c);

	char* getNume();
	int getPret();
	int getCod();

	void setNume(char* t);
	void setPret(int p);
	void setCod(int);

	char* toString();

	friend ostream& operator<<(ostream &, const Dulciuri &);
};


#endif

