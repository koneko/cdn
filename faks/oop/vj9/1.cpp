#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Niz
{
private:
	vector<T> podaci;

public:
	Niz(vector<T> v) : podaci(v) {}

	int manje_od(const Niz &drugi) const
	{
		for (auto &x : podaci)
		{
			for (auto &y : drugi.podaci)
			{
				if (x > y)
				{
					return 0;
				}
			}
		}
		return 1;
	}
};

template <typename T>
int operator<(Niz<T> a, Niz<T> b)
{
	return a.manje_od(b);
}

template <typename T>
int operator>=(Niz<T> a, Niz<T> b)
{
	return !(a < b);
}

template <typename T>
class Niz2
{
private:
	vector<T> podaci;

public:
	Niz2(vector<T> v) : podaci(v) {}

	int manje_od(const Niz2 &drugi) const
	{
		for (auto &x : podaci)
		{
			for (auto &y : drugi.podaci)
			{
				if (!(x < y))
				{
					return 0;
				}
			}
		}
		return 1;
	}

	int operator<(Niz2 drugi) const
	{
		return manje_od(drugi);
	}
};

int main()
{

	vector<int> v1 = {1, 2, 3};
	vector<int> v2 = {11, 0, 13};

	Niz<int> p1(v1);
	Niz<int> p2(v2);

	cout << (p1 < p2) << endl;
	cout << (p1 >= p2) << endl;

	cout << "----------------" << endl;

	Niz2<int> n1(v1);
	Niz2<int> n2(v2);

	cout << (n1 < n2) << endl;

	return 0;
}
