#include <iostream>
#include <vector>
using namespace std;

class Matrica
{
public:
	vector<int *> redak;
	vector<int> stupac;

	void dodaj(int brStupaca, int *_redak)
	{
		stupac.push_back(brStupaca);
		int *p = new int[brStupaca];
		for (int i = 0; i < brStupaca; i++)
		{
			p[i] = _redak[i];
		}
		redak.push_back(p);
	}

	Matrica() = default;

	Matrica(const Matrica &m)
	{
		for (int i = 0; i < m.redak.size(); i++)
		{
			int brojStupca = m.stupac[i];
			int *p = new int[brojStupca];

			for (int j = 0; j < brojStupca; j++)
			{
				p[j] = m.redak[i][j];
			}

			redak.push_back(p);
			stupac.push_back(brojStupca);
		}
	}

	Matrica &operator=(const Matrica &m)
	{
		if (this == &m)
			return *this;

		for (int i = 0; i < redak.size(); i++)
		{
			delete[] redak[i];
		}
		redak.clear();
		stupac.clear();

		for (int i = 0; i < m.redak.size(); i++)
		{
			int br = m.stupac[i];
			int *p = new int[br];

			for (int j = 0; j < br; j++)
			{
				p[j] = m.redak[i][j];
			}

			redak.push_back(p);
			stupac.push_back(br);
		}

		return *this;
	}

	Matrica(Matrica &&m)
	{
		redak = m.redak;
		stupac = m.stupac;

		m.redak.clear();
		m.stupac.clear();
	}

	void ispis()
	{
		for (int i = 0; i < redak.size(); i++)
		{
			for (int j = 0; j < stupac[i]; j++)
			{
				cout << redak[i][j] << " ";
			}
			cout << endl;
		}
	}

	~Matrica()
	{
		for (int i = 0; i < redak.size(); i++)
		{
			delete[] redak[i];
		}
		redak.clear();
		stupac.clear();
	}
};

int main()
{
	Matrica m;
	m.dodaj(3, new int[3]{1, 6, 2});
	m.dodaj(5, new int[5]{5, 3, 4, 7, 0});
	m.dodaj(4, new int[4]{6, 2, 6, 5});

	m.ispis();

	// kopirni
	Matrica m2 = m;

	// pridruzivanje
	Matrica m3;
	m3 = m;

	return 0;
}
