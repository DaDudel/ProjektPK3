#include "classes.h"
#include<string>
#include<iostream>
#include<fstream>
using namespace std;
void database::dodaj()
{
	char wybor = 0;
	int con=1;
	string nazwa;
	string stan;
	string autor;
	int rocznik;
	double waga;
	while (con)
	{
		cout << "Jaki eksponat chcesz dodac? Wybierz liczbe." << endl;
		cout << "1 - starodruk" << endl;
		cout << "2 - rekopis" << endl;
		cout << "3 - obraz" << endl;
		cout << "4 - rzezba" << endl;
		cout << "5 - mebel" << endl;
		cout << "6 - przedmiot uzytkowy" << endl;
		cin >> wybor;
		switch (wybor)
		{
		case '1':
		{
			//dodaj starodruk
			cout << "Podaj rocznik" << endl;
			cin >> rocznik;
			cout << "Podaj nazwe" << endl;
			getchar();
			getline(cin, nazwa);
			cout << "Podaj stan" << endl;
			getline(cin, stan);
			items.push_back(new starodruk(nazwa, rocznik, 1, stan));
			con = 0;
			break;
		}
		case '2':
		{
			//dodaj rekopis
			cout << "Podaj rocznik" << endl;
			cin >> rocznik;
			cout << "Podaj nazwe" << endl;
			getchar();
			getline(cin, nazwa);
			cout << "Podaj stan" << endl;
			getline(cin, stan);
			items.push_back(new rekopis(nazwa, rocznik, 1, stan));
			con = 0;
			break;
		}
		case '3':
		{
			//dodaj obraz
			cout << "Podaj rocznik" << endl;
			cin >> rocznik;
			cout << "Podaj nazwe" << endl;
			getchar();
			getline(cin, nazwa);
			cout << "Podaj autora" << endl;
			getline(cin, autor);
			items.push_back(new obraz(nazwa, rocznik, 0, autor));
			con = 0;
			break;
		}
		case '4':
		{
			//dodaj rzezba
			cout << "Podaj rocznik" << endl;
			cin >> rocznik;
			cout << "Podaj nazwe" << endl;
			getchar();
			getline(cin, nazwa);
			cout << "Podaj autora" << endl;
			getline(cin, autor);
			items.push_back(new rzezba(nazwa, rocznik, 0, autor));
			con = 0;
			break;
		}case '5':
		{
			//dodaj mebel
			cout << "Podaj rocznik" << endl;
			cin >> rocznik;
			cout << "Podaj nazwe" << endl;
			getchar();
			getline(cin, nazwa);
			cout << "Podaj wage" << endl;
			cin >> waga;
			items.push_back(new mebel(nazwa, rocznik, 0, waga));
			con = 0;
			break;
		}case '6':
		{
			//dodaj przedmiot uzytkowy
			cout << "Podaj rocznik" << endl;
			cin >> rocznik;
			cout << "Podaj nazwe" << endl;
			getchar();
			getline(cin, nazwa);
			cout << "Podaj wage" << endl;
			cin >> waga;
			items.push_back(new mebel(nazwa, rocznik, 0, waga));
			con = 0;
			break;
		}
		default:
		{
			cout << "Cos poszlo nie tak, sprobuj ponownie." << endl << endl;
			break;
		}
		}

	}
}

void database::usun()
{
	int i = 1;
	int w = 0;
	cout << endl;
	cout << "Ktory element chcesz usunac?" << endl;
	for (auto item : items)
	{
		cout << i++ << ") ";
		item->wypiszk();
	}
	cout << "Wybierz liczbe" << endl;
	cin >> w;
	delete items[w - 1];
	items.erase(items.begin()+ w - 1);
	cout << "Usunieto element nr " << w << "." << endl;
}

void database::wczytaj()
{
	string t;
	string nazwa = "";
	ifstream plo;
	string s="";
	string s2 = "";
	int rok = 0;
	string stan = "";
	char chr;
	double waga;
	cout << "Podaj nazwe pliku" << endl;
	cin >> nazwa;
	nazwa = nazwa + ".txt";
	plo.open(nazwa);
	if (plo.good())
	{
		while (!plo.eof())
		{
			///////////////////
			if (!getline(plo, t))
			{
				break;
			}
			getline(plo,s);
			chr = s[2];
			//cout << chr << endl;
			switch (chr)
			{
			case 'a':
				{
				//starodruk
				getline(plo, s2);
				plo>>rok;
				plo.ignore();
				getline(plo, stan);
				items.push_back(new starodruk(s2, rok, 1, stan));
				break;
				}
			case 'k':
			{
				//rekopis
				getline(plo, s2);
				plo >> rok;
				plo.ignore();
				getline(plo, stan);
				items.push_back(new rekopis(s2, rok, 1, stan));
				break;
			}
			case 'r':
			{
				//obraz
				getline(plo, s2);
				plo >> rok;
				plo.ignore();
				getline(plo, stan);
				items.push_back(new obraz(s2, rok, 0, stan));
				break;
			}
			case 'e':
			{
				//rzezba
				getline(plo, s2);
				plo >> rok;
				plo.ignore();
				getline(plo, stan);
				items.push_back(new rzezba(s2, rok, 0, stan));
				break;
			}
			case 'b':
			{
				//mebel
				getline(plo, s2);
				plo >> rok;
				plo >> waga;
				plo.ignore();
				items.push_back(new mebel(s2, rok, 0, waga));
				break;
			}
			case 'z':
			{
				//przedmiot uzytkowy
				getline(plo, s2);
				plo >> rok;
				plo >> waga;
				plo.ignore();
				items.push_back(new przedmiotuzytkowy(s2, rok, 0, waga));
				break;
			}
			}
		}
	}
	plo.close();
}

void database::zapisz()
{
	string nazwa = "";
	int i = 1;
	cout << "Podaj nazwe pliku" << endl;
	cin >> nazwa;
	nazwa = nazwa + ".txt";
	ofstream plz;
	plz.open(nazwa);
	for (auto item : items)
	{
		plz << i++ << endl;
		item->dostrumienia(plz);
	}
	plz.close();
}

void database::usunbaze()
{
	int l = items.size();
	for (int i = 0; i<l;i++)
	{
		delete items[0];
		items.erase(items.begin());
	}
	cout << endl;
	cout << "Baza zostala usunieta." << endl;
}

void database::wypisz()
{
	int con = 1;
	int i = 1;
	char chr;
	int l = items.size();
	while (con)
	{
		cout << endl;
		cout << "Co chcesz wypisac?" << endl;
		cout << "1) Wszystko" << endl;
		cout << "2) Eksponaty pisane (starodruki i rekopisy)" << endl;
		cout << "3) Eksponaty niepisane (obrazy, rzezby, meble i przedmioty uzytkowe" << endl;
		cin >> chr;
		switch (chr)
		{
		case '1':
		{
			for (auto item : items)
			{
				cout << endl;
				cout << i++ << endl;
				item->wypisz();
			}
			con = 0;
			break;
		}
		case '2':
		{
			for (auto item: items)
			{
				item->wyppis();
			}
			con = 0;
			break;
		}
		case '3':
		{
			for (auto item : items)
			{
				item->wypnie();
			}
			con = 0;
			break;
		}
		default:
		{
			cout << "Cos poszlo nie tak, sproboj ponownie" << endl;
			break;
		}
		}
	}
	
}

void database::edytujelement()
{
	int i = 1;
	int w;
	cout << "Ktory element chcesz edytowac?" << endl;
	for (auto item : items)
	{
		cout << i++ << ") ";
		item->wypiszk();
	}
	cout << "Wybierz liczbe" << endl;
	//getchar();
	cin >> w;
	delete items[w - 1];
	char wybor = 0;
	int con = 1;
	string nazwa;
	string stan;
	string autor;
	int rocznik;
	double waga;
	while (con)
	{
		cout << "Podaj nowy typ eksponatu. Wybierz liczbe." << endl;
		cout << "1 - starodruk" << endl;
		cout << "2 - rekopis" << endl;
		cout << "3 - obraz" << endl;
		cout << "4 - rzezba" << endl;
		cout << "5 - mebel" << endl;
		cout << "6 - przedmiot uzytkowy" << endl;
		cin >> wybor;
		switch (wybor)
		{
		case '1':
		{
			cout << "Podaj nowy rocznik" << endl;
			cin >> rocznik;
			cout << "Podaj nowa nazwe" << endl;
			getchar();
			getline(cin, nazwa);
			cout << "Podaj nowy stan" << endl;
			getline(cin, stan);
			items[w - 1] = new starodruk(nazwa, rocznik, 1, stan);
			con = 0;
			break;
		}
		case '2':
		{
			cout << "Podaj nowy rocznik" << endl;
			cin >> rocznik;
			cout << "Podaj nowa nazwe" << endl;
			getchar();
			getline(cin, nazwa);
			cout << "Podaj nowy stan" << endl;
			getline(cin, stan);
			items[w - 1] = new rekopis(nazwa, rocznik, 1, stan);
			con = 0;
			break;
		}
		case '3':
		{
			cout << "Podaj nowy rocznik" << endl;
			cin >> rocznik;
			cout << "Podaj nowa nazwe" << endl;
			getchar();
			getline(cin, nazwa);
			cout << "Podaj nowego autora" << endl;
			getline(cin, autor);
			items[w - 1] = new obraz(nazwa, rocznik, 0, autor);
			con = 0;
			break;
		}
		case '4':
		{
			cout << "Podaj nowy rocznik" << endl;
			cin >> rocznik;
			cout << "Podaj nowa nazwe" << endl;
			getchar();
			getline(cin, nazwa);
			cout << "Podaj nowego autora" << endl;
			getline(cin, autor);
			items[w - 1] = new rzezba(nazwa, rocznik, 0, autor);
			con = 0;
			break;
		}case '5':
		{
			cout << "Podaj nowy rocznik" << endl;
			cin >> rocznik;
			cout << "Podaj nowa nazwe" << endl;
			getchar();
			getline(cin, nazwa);
			cout << "Podaj nowa wage" << endl;
			cin >> waga;
			items[w - 1] = new mebel(nazwa, rocznik, 0, waga);
			con = 0;
			break;
		}case '6':
		{
			cout << "Podaj nowy rocznik" << endl;
			cin >> rocznik;
			cout << "Podaj nowa nazwe" << endl;
			getchar();
			getline(cin, nazwa);
			cout << "Podaj nowa wage" << endl;
			cin >> waga;
			items[w - 1] = new mebel(nazwa, rocznik, 0, waga);
			con = 0;
			break;
		}
		default:
		{
			cout << "Cos poszlo nie tak, sprobuj ponownie." << endl << endl;
			break;
		}
		}

	}
}

void database::menu()
{
	int con = 1;
	char wyb;
	while (con)
	{
		cout << "Co chcesz zrobic?" << endl;
		cout << "1) Wczytaj plik" << endl;
		cout << "2) Dodaj eksponat" << endl;
		cout << "3) Edytuj eksponat" << endl;
		cout << "4) Usun eksponat" << endl;
		cout << "5) Wypisz eksponaty" << endl;
		cout << "6) Zapisz do pliku" << endl;
		cout << "7) Usun baze" << endl;
		cout << "8) Zamknij program" << endl;
		cout << "Wybierz liczbe" << endl;
		cin >> wyb;
		switch (wyb)
		{
		case '1':
		{
			this->wczytaj();
			break;
		}
		case '2':
		{
			this->dodaj();
			break;
		}
		case '3':
		{
			this->edytujelement();
			break;
		}
		case '4':
		{
			this->usun();
			break;
		}
		case '5':
		{
			this->wypisz();
			break;
		}
		case '6':
		{
			this->zapisz();
			break;
		}
		case '7':
		{
			this->usunbaze();
			break;
		}
		case '8':
		{
			con = 0;
			break;
		}
		default:
		{
			cout << "Cos poszlo nie tak, sproboj ponownie" << endl;
			break;
		}
		}
	}
}

void database::usunbaze2()
{
	int l = items.size();
	for (int i = 0; i < l; i++)
	{
		delete items[0];
		items.erase(items.begin());
	}
}

starodruk::starodruk(string nazwa, int rocznik, int czypisane, string stan)
{
	this->nazwa = nazwa;
	this->rocznik = rocznik;
	this->czypisane = czypisane;
	this->stan = stan;
}

void starodruk::wypisz()
{
	//cout << endl;
	cout << "Typ: starodruk" << endl;
	cout << "Nazwa: " << nazwa << endl;
	cout << "Rocznik: " << rocznik << endl;
	cout << "Stan: " << stan << endl;
	cout << endl;
}

void starodruk::wypiszk()
{
	cout << "Starodruk \"" << nazwa << "\" " << rocznik << endl;
}

void starodruk::dostrumienia(ostream& strumien)
{
	strumien << "Starodruk" << endl << nazwa << endl << rocznik << endl << stan << endl;
}

void starodruk::wyppis()
{
	if (czypisane == 1)
	{
		cout << "Typ: starodruk" << endl;
		cout << "Nazwa: " << nazwa << endl;
		cout << "Rocznik: " << rocznik << endl;
		cout << "Stan: " << stan << endl;
		cout << endl;
	}
}

void starodruk::wypnie()
{
	if (czypisane == 0)
	{
		cout << "Typ: starodruk" << endl;
		cout << "Nazwa: " << nazwa << endl;
		cout << "Rocznik: " << rocznik << endl;
		cout << "Stan: " << stan << endl;
		cout << endl;
	}
}

rekopis::rekopis(string nazwa, int rocznik, int czypisane, string stan)
{
	this->nazwa = nazwa;
	this->rocznik = rocznik;
	this->czypisane = czypisane;
	this->stan = stan;
}

void rekopis::wypisz()
{
	//cout << endl;
	cout << "Typ: rekopis" << endl;
	cout << "Nazwa: " << nazwa << endl;
	cout << "Rocznik: " << rocznik << endl;
	cout << "Stan: " << stan << endl;
	cout << endl;
}

void rekopis::wypiszk()
{
	cout << "Rekopis \"" << nazwa << "\" " << rocznik << endl;
}

void rekopis::dostrumienia(ostream& strumien)
{
	strumien << "Rekopis" << endl << nazwa << endl << rocznik << endl << stan << endl;
}

void rekopis::wyppis()
{
	if (czypisane == 1)
	{
		cout << "Typ: rekopis" << endl;
		cout << "Nazwa: " << nazwa << endl;
		cout << "Rocznik: " << rocznik << endl;
		cout << "Stan: " << stan << endl;
		cout << endl;
	}
}

void rekopis::wypnie()
{
	if (czypisane == 0)
	{
		cout << "Typ: rekopis" << endl;
		cout << "Nazwa: " << nazwa << endl;
		cout << "Rocznik: " << rocznik << endl;
		cout << "Stan: " << stan << endl;
		cout << endl;
	}
}

obraz::obraz(string nazwa, int rocznik, int czypisane, string autor)
{
	this->nazwa = nazwa;
	this->rocznik = rocznik;
	this->czypisane = czypisane;
	this->autor = autor;
}

void obraz::wypisz()
{
	//cout << endl;
	cout << "Typ: obraz" << endl;
	cout << "Nazwa: " << nazwa << endl;
	cout << "Rocznik: " << rocznik << endl;
	cout << "Autor: " << autor << endl;
	cout << endl;
}

void obraz::wypiszk()
{
	cout << "Obraz \"" << nazwa << "\" " << rocznik << endl;
}

void obraz::dostrumienia(ostream& strumien)
{
	strumien << "Obraz" << endl << nazwa << endl << rocznik << endl << autor << endl;
}

void obraz::wyppis()
{
	if (czypisane == 1)
	{
		cout << "Typ: obraz" << endl;
		cout << "Nazwa: " << nazwa << endl;
		cout << "Rocznik: " << rocznik << endl;
		cout << "Autor: " << autor << endl;
		cout << endl;
	}
}

void obraz::wypnie()
{
	if (czypisane == 0)
	{
		cout << "Typ: obraz" << endl;
		cout << "Nazwa: " << nazwa << endl;
		cout << "Rocznik: " << rocznik << endl;
		cout << "Autor: " << autor << endl;
		cout << endl;
	}
}

rzezba::rzezba(string nazwa, int rocznik, int czypisane, string autor)
{
	this->nazwa = nazwa;
	this->rocznik = rocznik;
	this->czypisane = czypisane;
	this->autor = autor;
}

void rzezba::wypisz()
{
	//cout << endl;
	cout << "Typ: rzezba" << endl;
	cout << "Nazwa: " << nazwa << endl;
	cout << "Rocznik: " << rocznik << endl;
	cout << "Autor: " << autor << endl;
	cout << endl;
}

void rzezba::wypiszk()
{
	cout << "Rzezba \"" << nazwa << "\" " << rocznik << endl;
}

void rzezba::dostrumienia(ostream& strumien)
{
	strumien << "Rzezba" << endl << nazwa << endl << rocznik << endl << autor << endl;
}

void rzezba::wyppis()
{
	if (czypisane == 1)
	{
		cout << "Typ: rzezba" << endl;
		cout << "Nazwa: " << nazwa << endl;
		cout << "Rocznik: " << rocznik << endl;
		cout << "Autor: " << autor << endl;
		cout << endl;
	}
}

void rzezba::wypnie()
{
	if (czypisane == 0)
	{
		cout << "Typ: rzezba" << endl;
		cout << "Nazwa: " << nazwa << endl;
		cout << "Rocznik: " << rocznik << endl;
		cout << "Autor: " << autor << endl;
		cout << endl;
	}
}

mebel::mebel(string nazwa, int rocznik, int czypisane, double waga)
{
	this->nazwa = nazwa;
	this->rocznik = rocznik;
	this->czypisane = czypisane;
	this->waga = waga;
}

void mebel::wypisz()
{
	//cout << endl;
	cout << "Typ: mebel" << endl;
	cout << "Nazwa: " << nazwa << endl;
	cout << "Rocznik: " << rocznik << endl;
	cout << "Waga: " << waga << endl;
	cout << endl;
}

void mebel::wypiszk()
{
	cout << "Mebel \"" << nazwa << "\" " << rocznik << endl;
}

void mebel::dostrumienia(ostream& strumien)
{
	strumien << "Mebel" << endl << nazwa << endl << rocznik << endl << waga << endl;
}

void mebel::wyppis()
{
	if (czypisane == 1)
	{
		cout << "Typ: mebel" << endl;
		cout << "Nazwa: " << nazwa << endl;
		cout << "Rocznik: " << rocznik << endl;
		cout << "Waga: " << waga << endl;
		cout << endl;
	}
}

void mebel::wypnie()
{
	if (czypisane == 0)
	{
		cout << "Typ: mebel" << endl;
		cout << "Nazwa: " << nazwa << endl;
		cout << "Rocznik: " << rocznik << endl;
		cout << "Waga: " << waga << endl;
		cout << endl;
	}
}

przedmiotuzytkowy::przedmiotuzytkowy(string nazwa, int rocznik, int czypisane, double waga)
{
	this->nazwa = nazwa;
	this->rocznik = rocznik;
	this->czypisane = czypisane;
	this->waga = waga;
}

void przedmiotuzytkowy::wypisz()
{
	//cout << endl;
	cout << "Typ: przedmiot uzytkowy" << endl;
	cout << "Nazwa: " << nazwa << endl;
	cout << "Rocznik: " << rocznik << endl;
	cout << "Waga: " << waga << endl;
	cout << endl;
}

void przedmiotuzytkowy::wypiszk()
{
	cout << "Przedmiot uzytkowy \"" << nazwa << "\" " << rocznik << endl;
}

void przedmiotuzytkowy::dostrumienia(ostream& strumien)
{
	strumien << "Przedmiot uzytkowy" << endl << nazwa << endl << rocznik << endl << waga << endl;
}

void przedmiotuzytkowy::wyppis()
{
	if (czypisane == 1)
	{
		cout << "Typ: przedmiot uzytkowy" << endl;
		cout << "Nazwa: " << nazwa << endl;
		cout << "Rocznik: " << rocznik << endl;
		cout << "Waga: " << waga << endl;
		cout << endl;
	}
}

void przedmiotuzytkowy::wypnie()
{
	if (czypisane == 0)
	{
		cout << "Typ: przedmiot uzytkowy" << endl;
		cout << "Nazwa: " << nazwa << endl;
		cout << "Rocznik: " << rocznik << endl;
		cout << "Waga: " << waga << endl;
		cout << endl;
	}
}
