#include <iostream>
#include <string>
using namespace std;

class PrevelikBroj
{
public:
	string poruka() const
	{
		return "prevelik broj";
	}
};

class PremaliBroj
{
public:
	string poruka() const
	{
		return "premali broj";
	}
};

void primjer(int x)
{
	cout << "pocetak primjera" << endl;

	if (x > 0)
		throw PrevelikBroj();
	else
		throw PremaliBroj();
}

void test(int x)
{
	cout << "pocetak testa" << endl;
	primjer(x);
}

int main()
{
	try
	{
		test(2);
		cout << "nastavak try-bloka...\n";
	}
	catch (const PrevelikBroj &e)
	{
		cout << e.poruka() << endl;
	}
	catch (const PremaliBroj &e)
	{
		cout << e.poruka() << endl;
	}
	catch (...)
	{
		cout << "... neka druga greska!";
	}

	cout << "nastavak main funkcije\n";
}
