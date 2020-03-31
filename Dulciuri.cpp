
#include"stdafx.h"
#include<string>
#include"Dulciuri.h"
#include <iostream>
using namespace std;


//Descr: crearea unui dulce
//In: -
//Out: o instanta a unui dulce
Dulciuri::Dulciuri() {
	//cout << "default constructor" << endl;
	this->nume = NULL;
	this->cod = 0;
	this->pret = 0;
}

//Descr: creeaza un dulce
//In: nume cod si pret
//Out: 
Dulciuri::Dulciuri(char* n, int c, int p) {
	//cout << "constructor with param" << endl;
	this->nume = new char[strlen(n) + 1];
	strcpy_s(this->nume, strlen(n) + 1, n);
	this->pret = p;
	this->cod = c;
}

//Descr: crearea unui dulce folosind info din alt dulce
//In: un dulce c
//Out: o instanta a dulcelui cu info de la c
Dulciuri::Dulciuri(const Dulciuri&c) {
	//cout << "copy constructor" << endl;
	this->nume = new char[strlen(c.nume) + 1];
	strcpy_s(this->nume, strlen(c.nume) + 1, c.nume);
	this->pret = c.pret;
	this->cod = c.cod;
}

//Descr: distrugerea unui dulce
//In: un dulce 
//Out: - (destructor)
Dulciuri::~Dulciuri() {
	if (this->nume != NULL) {
		//cout << "destructor of expense " << this->nume << endl;
		delete[]this->nume;
		this->nume = NULL;
	}
	//delete[]this->tip;
}

Dulciuri&Dulciuri::operator=(const Dulciuri&c) {
	if (this != &c) {
		setNume(c.nume);
		pret = c.pret;
		cod = c.cod;
	}
	return *this;
}

//Descr: access pretul unui dulce
//In:un dulce 
//Out: pret
int Dulciuri::getPret() {
	//returns price;
	return this->pret;
}
//Descr: access numele unui dulce
//In: un dulce 
//Out: nume
char* Dulciuri::getNume() {
	return this->nume;
}
//Descr: access codul unui dulce 
//In: un dulce  
//Out: cod
int Dulciuri::getCod() {
	return this->cod;
}

//Descr: change the price of an expense 
//In: an expense and a price
//Out: the expense with changed price
void Dulciuri::setPret(int p) {
	this->pret = p;
}
//Descr: schimba codul unui dulce
//In: un dulce si codul
//Out: dulce cu cod schimbat
void Dulciuri::setCod(int z) {
	this->cod = z;
}

//Descr: schimba numele unui dulce 
//In: un dulce si nume
//Out: dulce cu nume schimbat

void Dulciuri::setNume(char* t) {
	delete[]this->nume;
	this->nume = new char[strlen(t) + 1];
	strcpy_s(this->nume, strlen(t) + 1, t);
}

//Descr: conversie dulciuri la string
//In: un dulce
//Out: un string cu info despre un dulce
char* Dulciuri::toString() {
	if (this->nume != NULL) {
		int noChars = strlen(this->nume) + 1 + 5 + 1 + 5 + 2;
		char* aux = new char[5];
		char* aux1 = new char[5];
		char* s = new char[noChars];
		strcpy_s(s, noChars, this->nume);
		strcat_s(s, noChars, ";");
		_itoa_s(this->pret, aux, 5, 10);
		_itoa_s(this->cod, aux1, 5, 10);
		strcat_s(s, noChars, aux);
		strcat_s(s, noChars, ";");
		strcat_s(s, noChars, aux1);
		strcat_s(s, noChars, ";");


		if (aux) {
			delete[] aux;
			aux = NULL;
		}

		strcat_s(s, noChars, ";");
		return s;
		cout << "cout tostring dulciuri..." << endl;
	}
	else
	{
		char* v = new char[1];
		strcpy_s(v, 1, "");
		return v;
	}
}

ostream& operator<<(ostream &os, const Dulciuri &f) {
	os << f.nume << " " << f.cod << " " << f.pret << endl;
	return os;
}