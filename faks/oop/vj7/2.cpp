#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Proizvod
{
protected:
	string naziv;
	double cijena;

public:
	Proizvod(string n, double c) : naziv(n), cijena(c) {}

	virtual void print()
	{
		cout << "Naziv: " << naziv << ", Cijena: " << cijena << endl;
	}

	virtual double getKoefKvalitete() = 0;

	virtual ~Proizvod() {}
};

class Automobil : public Proizvod
{
private:
	int godProizvodnje;
	double maxBrzina;

public:
	Automobil(string n, double c, int g, double mb)
		: Proizvod(n, c), godProizvodnje(g), maxBrzina(mb) {}

	double getKoefKvalitete() override
	{
		return (1.0 / (2015 - godProizvodnje)) *
			   (maxBrzina / 100.0) *
			   (cijena / 100000.0);
	}

	void print() override
	{
		cout << "Automobil -> ";
		Proizvod::print();
		cout << "Godina: " << godProizvodnje
			 << ", Max brzina: " << maxBrzina << endl;
	}
};

class LegoIgracka : public Proizvod
{
private:
	int brKomada;

public:
	LegoIgracka(string n, double c, int br)
		: Proizvod(n, c), brKomada(br) {}

	double getKoefKvalitete() override
	{
		return brKomada / cijena;
	}

	void print() override
	{
		cout << "Lego -> ";
		Proizvod::print();
		cout << "Broj komada: " << brKomada << endl;
	}
};

int main()
{
	vector<Proizvod *> vp = {
		new LegoIgracka("Star Wars - Millenium Falcon", 2250.99, 756),
		new Automobil("BMW", 51230, 2013, 207.34),
		new LegoIgracka("Vlakic na upravljanje", 1750.99, 877),
		new Automobil("Yugo 45", 14500, 1988, 127.88),
	};

	for (int i = 0; i < vp.size(); i++)
	{
		vp[i]->print();
	}

	Proizvod *najbolji = vp[0];
	double maxKoef = vp[0]->getKoefKvalitete();

	for (int i = 1; i < vp.size(); i++)
	{
		double k = vp[i]->getKoefKvalitete();
		if (k > maxKoef)
		{
			maxKoef = k;
			najbolji = vp[i];
		}
	}

	cout << "\nProizvod s najvećim koeficijentom:\n";
	najbolji->print();
	cout << "Koeficijent: " << maxKoef << endl;

	return 0;
}
