#pragma once
#include<string>
#include <vector>
using namespace std;
class eksponatmuzealny
{
public:
	string nazwa;
	int rocznik;
	virtual void wypisz() =0;
	virtual void wypiszk() {};
	virtual void dostrumienia(ostream& strumien) {};
	virtual void wyppis() {};
	virtual void wypnie() {};
};

class pisane : public eksponatmuzealny
{
public:
	int czypisane;
};

class starodruk : public pisane
{
	string stan;
public:
	starodruk(string nazwa, int rocznik, int czypisane, string stan);
	void wypisz();
	void wypiszk();
	void dostrumienia(ostream& strumien);
	void wyppis();
	void wypnie();
};

class rekopis : public pisane
{
	string stan;
public:
	rekopis(string nazwa, int rocznik, int czypisane, string stan);
	void wypisz();
	void wypiszk();
	void dostrumienia(ostream& strumien);
	void wyppis();
	void wypnie();
};

class niepisane : public eksponatmuzealny
{
public:
	int czypisane;
};

class obraz :public niepisane
{
	string autor;
public:
	obraz(string nazwa, int rocznik, int czypisane, string autor);
	void wypisz();
	void wypiszk();
	void dostrumienia(ostream& strumien);
	void wyppis();
	void wypnie();
};

class rzezba :public niepisane
{
	string autor;
public:
	rzezba(string nazwa, int rocznik, int czypisane, string autor);
	void wypisz();
	void wypiszk();
	void dostrumienia(ostream& strumien);
	void wyppis();
	void wypnie();
};

class mebel :public niepisane
{
	double waga;
public:
	mebel(string nazwa, int rocznik, int czypisane, double waga);
	void wypisz();
	void wypiszk();
	void dostrumienia(ostream& strumien);
	void wyppis();
	void wypnie();
};

class przedmiotuzytkowy :public niepisane
{
	double waga;
public:
	przedmiotuzytkowy(string nazwa, int rocznik, int czypisane, double waga);
	void wypisz();
	void wypiszk();
	void dostrumienia(ostream& strumien);
	void wyppis();
	void wypnie();
};

class database
{
	vector<eksponatmuzealny*> items;
public:
	void dodaj();
	void usun();
	void wczytaj();
	void zapisz();
	void usunbaze();
	void wypisz();
	void edytujelement();
	void menu();
	void usunbaze2();
};