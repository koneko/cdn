#include <iostream>
#include <vector>
using namespace std;

class Zaposlenik
{
public:
	string ime;
	string prezime;
	int starost;

	Zaposlenik(string _ime, string _prezime, int _starost)
	{
		cout << "Zaposlenik constructor called" << endl;
		ime = _ime;
		prezime = _prezime;
		starost = _starost;
	}
	~Zaposlenik()
	{
		cout << "Zaposlenik destructor called" << endl;
	}
};

class Firma
{
public:
	Firma(string _naziv, int _oib, string _adresaSjedista)
	{
		if (_naziv.length() < 5)
		{
			cout << "naziv pre kratak" << endl;
		}
		else
			naziv = _naziv;

		if (to_string(_oib).length() != 11)
		{
			cout << "oib nije 11 znamenki" << endl;
		}
		else
			oib = _oib;

		adresaSjedista = _adresaSjedista;
	}

	void dodajZaposlenika1(Zaposlenik z)
	{
		zaposlenici.push_back(z);
	}

	void dodajZaposlenika2(Zaposlenik &z)
	{
		zaposlenici.push_back(z);
	}

	void dodajZaposlenika3(Zaposlenik *z)
	{
		zaposlenici.push_back(*z);
	}

	void ispisSvihZaposlenika()
	{
		for (int i = 0; i < zaposlenici.size(); i++)
		{
			Zaposlenik &z = zaposlenici[i];
			cout << z.ime << " " << z.prezime << ", " << z.starost << " godina" << endl;
		}
	}

	Zaposlenik nadjiZaposlenika1(string ime, string prezime)
	{
		for (int i = 0; i < zaposlenici.size(); i++)
		{
			if (zaposlenici[i].ime == ime && zaposlenici[i].prezime == prezime)
				return zaposlenici[i];
		}
	}

	Zaposlenik *nadjiZaposlenika2(string ime, string prezime)
	{
		for (int i = 0; i < zaposlenici.size(); i++)
		{
			if (zaposlenici[i].ime == ime && zaposlenici[i].prezime == prezime)
				return &zaposlenici[i];
		}
	}

	// vraća referencu
	Zaposlenik &nadjiZaposlenika3(string ime, string prezime)
	{
		for (int i = 0; i < zaposlenici.size(); i++)
		{
			if (zaposlenici[i].ime == ime && zaposlenici[i].prezime == prezime)
				return zaposlenici[i];
		}
	}

private:
	string naziv;
	int oib;
	string adresaSjedista;
	vector<Zaposlenik> zaposlenici;
};

int main()
{
	Firma f("MojaFirma", 12345678901, "Zagreb");

	Zaposlenik z1("Ivan", "Ivic", 30);
	Zaposlenik z2("Ana", "Anic", 25);

	f.dodajZaposlenika1(z1);
	f.dodajZaposlenika2(z2);

	f.nadjiZaposlenika1("Ivan", "Ivic").ime = "abc";
	(*f.nadjiZaposlenika2("Ivan", "Ivic")).ime = "abc";
	f.nadjiZaposlenika3("Ivan", "Ivic").ime = "abc";

	return 0;
}
