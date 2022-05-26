#include "polynomial.hpp"

// https://planetcalc.ru/168/
int main(int argc, char **argv) {
	if (argc != 2)
		cout << "Error\nInvalid number of arguments\n";
	else
		Polynomial Test(argv[1]);
	return (0);
}
