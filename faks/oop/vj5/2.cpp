#include <iostream>
using namespace std;

class TimeSpan
{
public:
	int h, m, s;
	void provjeri()
	{
		if (s >= 60)
		{
			m += s / 60;
			s = s % 60;
		}

		if (m >= 60)
		{
			h += m / 60;
			m = m % 60;
		}

		if (h < 0)
			h = 0;
		if (m < 0)
			m = 0;
		if (s < 0)
			s = 0;
	}
	TimeSpan(int _h, int _m, int _s)
	{
		h = _h;
		m = _m;
		s = _s;
	}

	TimeSpan operator+(int sec)
	{
		TimeSpan temp(*this);
		temp.s += sec;
		temp.provjeri();
		return temp;
	}

	TimeSpan operator--(int)
	{
		TimeSpan stari = *this;

		if (h == 0 && m == 0 && s == 0)
			return stari;

		if (s > 0)
			s--;
		else
		{
			s = 59;
			if (m > 0)
				m--;
			else
			{
				m = 59;
				if (h > 0)
					h--;
			}
		}

		return stari;
	}
};

TimeSpan operator+(int sec, TimeSpan t)
{
	t.s += sec;
	t.provjeri();
	return t;
}

ostream &operator<<(ostream &out, TimeSpan t)
{
	out << t.h << ":" << t.m << ":" << t.s << endl;
	return out;
}

int main()
{
	TimeSpan a(1, 0, 0);

	a = a + 10;
	cout << a; // 1:0:10

	a = 65 + a;
	cout << a; // 1:1:15

	for (int i = 0; i < 60 * 60 + 74; i++)
		a--;

	cout << a; // 0:0:1

	a--;
	a--;

	cout << a; // 0:0:0

	return 0;
}
