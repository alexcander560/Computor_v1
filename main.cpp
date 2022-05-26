#include "polynomial.hpp"

// https://planetcalc.ru/168/
int main(int argc, char **argv) {
	if (argc != 2)
		cout << "Error\nInvalid number of arguments\n";
	else
		Polynomial Test(argv[1]);

	// Polynomial A1(1, 7, 12);		// -> 2 корня(d=)(-3, -4)
	// cout << "========" << endl;
	// Polynomial A2(2, 4, 2);		// -> 1 корень (-1)
	// cout << "========" << endl;
	// Polynomial A3(13, 14, 15);		// -> 2 корня (-0.54+0.93i, -0.54-0.93i)
	// cout << "========" << endl;
	// Polynomial A4(0, 10, 20); // a=0 -> 1 корень (-2)
	// cout << "========" << endl;
	// Polynomial A5(10, 0, -2); // b=0 -> 2 кореня (0,45, -0,45)
	// cout << "========" << endl;
	// Polynomial A6(10, 3, 0); // c=0 -> 2 кореня (0, -0.3)
	// cout << "========" << endl;
	// Polynomial A7(0, 0, 42); // a=0 b=0 -> 0 кореней ()
	// cout << "========" << endl;
	// Polynomial A8(169, 0, 0); // b=0 c=0 ->1 корень (0)
	// cout << "========" << endl;
	// Polynomial A9(0, 21, 0); // a=0 c=0 ->1 корень (0)
	// cout << "========" << endl;
	// Polynomial A10(0, 0, 0); // любое число
	// cout << "========" << endl;

	return (0);
}
