#include <iostream>
#include <cmath>
#include <vector>
using namespace std;


class Formula {
public:
	double a;
	double b;
	double c;
	double d;

	Formula() {
	}

	Formula(double aa, double ab, double ac, double ad) {
		a = aa;
		b = ab;
		c = ac;
		d = ad;
	}

	double Calculate() {
		if ((24 + d - c) < 0) {
			throw "illegal d or c value";
		}
		if (b == 0) {
			throw "illegal b value, cannot be divided by zero";
		}
		if ((sqrt(24 + d - c) + a / b) == 0) {
			throw "cannot be divided by zero";
		}
		return ((1 + a - b / 2) / ((sqrt(24 + d - c) + a / b)));
	}
};


void ElementPrint(Formula element) {
	try {
		cout << "a=" << element.a << " b=" << element.b << " c=" << element.c << " d=" << element.d << " f=" << element.Calculate() << endl;
	}
	catch (const char* e) {
		cout << "print error: " << e << endl;
	}
}


int main()
{
	vector<Formula> Items;
	Items.push_back(Formula(1, 2, 3, 4));
	Items.push_back(Formula(2, 3, 4, 5));
	Items.push_back(Formula(2, 3, 40, 5));
	Items.push_back(Formula(2, 0, 4, 5));
	Items.push_back(Formula(0, 2, 25, 1));
	Formula element;
	for (int i = 0; i < Items.size(); i++) {
		element = Items[i];
		ElementPrint(element);
	};
	return 0;
};