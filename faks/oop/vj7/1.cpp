#include <iostream>
#include <vector>
using namespace std;

class Filter {
public:
    virtual vector<int> uvjet(vector<int> vec) final {
        vector<int> rezultat;
        for (int element : vec) {
            if (provjera(element)) {
                rezultat.push_back(element);
            }
        }
        return rezultat;
    }

    virtual bool provjera(int element) = 0;
    virtual ~Filter() {}
};

class FilterVeciOd : public Filter {
private:
    int granica;
public:
    FilterVeciOd(int g) : granica(g) {}

    bool provjera(int element) override {
        return element > granica;
    }
};

class FilterManjiOd : public Filter {
private:
    int granica;
public:
    FilterManjiOd(int g) : granica(g) {}

    bool provjera(int element) override {
        return element < granica;
    }
};

ostream& operator<<(ostream& os, const vector<int>& v) {
    for (int x : v) {
        os << x << " ";
    }
    os << endl;
    return os;
}

int main() {
    vector<int> v = {14, 3, 18, 5, 6, 10, 2, 8, 1, 7};

    Filter* filter = new FilterVeciOd(5);
    vector<int> rezultat = filter->uvjet(v);
    cout << rezultat;        // 14 18 6 10 8 7
    delete filter;

    filter = new FilterManjiOd(5);
    rezultat = filter->uvjet(v);
    cout << rezultat;        // 3 2 1
    delete filter;

    return 0;
}
