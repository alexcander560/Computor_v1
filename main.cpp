#include <iostream>
#include <cmath>

using namespace std;

// Класс для решения квадратных уранений
class MyMath {
	private:
		string		str;	// исходная строка
		string		ans;	// строка с ответом
		double		a;		// аргумент перед X^2
		double		b;		// аргумент перед X^1
		double		c;		// аргумент перед X^0

		// Определение степени уранения
		void	degree_polynomial() {
			ans += "Polynomial degree: ";
			if (a != 0) {
				ans += to_string(2) + "\n";
				count_roots_2();
			}
			else if (b != 0) {
				ans += to_string(1) + "\n";
				count_roots_1();
			}
			else if (c != 0)
				ans += to_string(0) + "\n" + "No solution.";
			else
				ans = "No Polynom. Each real number is a solution.\n";
			cout << ans;
		}
		// Формирвоание ответа для квадратного уравнения
		void	count_roots_2() {
			double	d = discriminant_2(), root_1, root_2, temp = -b / (2 * a);

			if (d == 0)
				ans += "Discriminant = 0. The solution is:\n" + to_string(temp) + "\n";
			else if (d > 0) {
				d = ft_sqrt(d);
				root_1 = (-b + d) / (2 * a);
				root_2 = (-b - d) / (2 * a);
				ans += "Discriminant > 0. The two solutions is:\n" + to_string(root_1) + "\n" + to_string(root_2) + "\n";
			}
			else {
				d = ft_sqrt(-d);
				root_1 = (-b + d) / (2 * a);
				root_2 = (-b - d) / (2 * a);
				ans += "Discriminant < 0. The two solution(imaginary numbers) is:\n" +
				to_string(temp) + " + " + to_string(d / (2 * a)) + " * √-1\n" +
				to_string(temp) + " - " + to_string(d / (2 * a)) + " * √-1\n";
			}
		}
		// Формирвоание ответа для линейного уравнения
		void	count_roots_1()		{ ans+= "The solution is:\n" + to_string(-c / b); }
		// Вычисление дискриминанта в квадрате
		double	discriminant_2()	{ return (b * b - 4 * a * c); }
	public:
		// Конструкторы
		MyMath(string str):str(str), a(0), b(0), c(0) {}
		MyMath(double a, double b, double c):a(a), b(b), c(c) { degree_polynomial(); }

		// Вычисление квадратного корня
		// Итерационная формула Герона (быстро сойдётся при любом x)
		double	ft_sqrt(double n) {
			double	pred, x = 1;

			do {
				pred = x;
				x = (x + n / x) / 2.0;
			} while (x != pred);
			return (x);
		}
		// Вычисление модуля числа
		double	ft_abs(double n) { return (n >= 0 ? n : -n); }
};

int main() {
	//MyMath A(1, -2, -3);
	//MyMath B(6, 5, -4);
	//MyMath C(4, 1, 12);
	MyMath C(0, 0, 0);
}