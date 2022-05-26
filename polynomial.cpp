#include "polynomial.hpp"

//====================================================================================
//=                               Конструкторы                                       =
//====================================================================================
// Конструкторы по заданию
Polynomial::Polynomial(string str):str(str), a(0), b(0), c(0), degree(0) {
	if (parser())
		degree_polynomial();
	cout << ans;
}
// Дополнительный конструктор для предварительной проверки метода решения
Polynomial::Polynomial(double a, double b, double c):a(a), b(b), c(c), degree(0) {
	degree_polynomial();
	cout << ans;
}
//====================================================================================
//=               Методы для решения уранения не больше 2 степени                    =
//====================================================================================
// Определение степени уранения и вывод его корней, если степень не превышает 2
void	Polynomial::degree_polynomial() {
	ans += "Polynomial degree: " + (degree >= 0 ? to_string(degree) : "no polynomial") + "\n";
	if (degree > 2) {
		ans += "The polynomial degree is strictly greater than 2, I can't solve.\n";
		return ;
	}
	if (a != 0)
		count_roots_2();
	else if (b != 0)
		ans+= "The solution is:\n" + to_string(c != 0 ? (-c / b) : 0) + "\n";
	else if (c != 0)
		ans += "No solution.\n";
	else
		ans += "Each number is a solution.\n";
}
// Формирвование ответа для квадратного уравнения
void	Polynomial::count_roots_2() {
	double	d = discriminant_2(), temp1 = ft_sqrt(ft_abs(d)) / (2 * a), temp2 = (b == 0 ? 0 : -b / (2 * a));

	if (d == 0)
		ans += "Discriminant = 0. The solution:\n" + to_string(temp2) + "\n";
	else if (d > 0)
		ans += "Discriminant > 0. The two solutions:\n" +
		to_string(temp2 + temp1) + "\n" +
		to_string(temp2 - temp1) + "\n";
	else
		ans += "Discriminant < 0. The two solution(imaginary numbers):\n" +
		(temp2 != 0 ? to_string(temp2) + " + " : "") + to_string(ft_abs(temp1)) + " * √-1\n" +
		(temp2 != 0 ? to_string(temp2) + " - " : "-") + to_string(ft_abs(temp1)) + " * √-1\n";
}
// Вычисление дискриминанта в квадрате
double	Polynomial::discriminant_2()	{ return (b * b - 4 * a * c); }

//====================================================================================
//=                     Функции для парсинга уравнения                               =
//====================================================================================
// Общий парсер строки
bool	Polynomial::parser() {
	int				ind = 0;
	vector<double>	coef, coef1, coef2;
	
	if (!parser_forbidden())
		return (false);

	ind = parser_coef(coef1);
	parser_coef(coef2, ind);
	degree = coef_reduction(coef1, coef2, coef);
	ans += reduced_form(coef);
	c = coef.size() > 0 ? coef[0] : 0;
	b = coef.size() > 1 ? coef[1] : 0;
	a = coef.size() > 2 ? coef[2] : 0;

	return (true);
}
// Парсер на запрещённые символы и наличи одного символа '='
bool	Polynomial::parser_forbidden() {
	string	dict = "0123456789X^*+-=. ";
	int		size = str.size(), check = 0;

	for (int i = 0; i < size; i++) {
		if (dict.find(str[i]) == string::npos) {
			ans = "Error\nForbidden characters\n";
			return (false);
		}
		if (str[i] == '=')
			check++;
	}
	if (check != 1) {
		ans = "Error\nSymbol '=' no 1\n";
		return (false);
	}
	return (true);
}
// Парсер коэффициентов до знака '=' или конца. Предполагается, что форма записи корректна
// Возвращает индекс элемента на котором закончилась обработка
int		Polynomial::parser_coef(vector<double> &coef, int start) {
	int	size = str.size(), m = 1;
	string			temp = "";

	for (int i = start; i < size; i++) {
		if (str[i] == '-')
			m = -1;
		else if ((str[i] >= '0' && str[i] <= '9') || str[i] == '.')
			temp += str[i];
		else if (str[i] == '^') {
			while (i < size) {
				i++;
				if (str[i] == '-') {
					m = -1;
					break ;
				}
				if (str[i] == '+' || str[i] == '=')
					break ;
			}
		}
		else if (temp != "") {
			try {
				coef.push_back(m * stod(temp));
			}
			catch (std::out_of_range& e) {
				cout << e.what() << endl;
				exit (1);
			}
			m = 1;
			temp = "";
		}
		if (str[i] == '=')
			return (i+1);
	}
	return (size);
}
// Приводит подобные слагаемые из левой и правой части уравнения
// Возвращает степень уравнения
int		Polynomial::coef_reduction(vector<double> &coef1, vector<double> &coef2, vector<double> &coef) {
	int	len1 = coef1.size(), len2 = coef2.size(), len = ft_max(len1, len2);

	for (int i = 0; i < len; i++)
		coef.push_back((i < len1 ? coef1[i] : 0) - (i < len2 ? coef2[i] : 0));
	for (int i = len - 1; i >= 0; i--) {
		if (coef[i] == 0)
			coef.erase(coef.end() - 1);
		else
			break ;
	}
	return (coef.size() - 1);
}
// Формирование сокращённой формы уравнения в ответ
string	Polynomial::reduced_form(vector<double> &coef) {
	string	temp = "Reduced form: ";
	int		size = coef.size();

	if (size == 0)
		return (temp + "0 * X^0 = 0\n");
	if (coef[0] < 0)
		temp += "-";
	for (int i = 0; i < size; i++) {
		temp += to_string(ft_abs(coef[i])) + " * X^" + to_string(i);
		if (i+1 < size)
			temp += (coef[i+1] >= 0 ? " + " : " - ");
	}
	return (temp + " = 0\n");
}
//====================================================================================
//=                 Вспомогательные математические функции                           =
//====================================================================================
// Вычисление квадратного корня для положительных чисел
// Итерационная формула Герона (быстро сойдётся при любом x)
double	Polynomial::ft_sqrt(double n) {
	double	pred, x = 1;

	if (n <= 0)
		return (0);
	do {
		pred = x;
		x = (x + n / x) / 2.0;
	} while (x != pred);
	return (x);
}
// Вычисление модуля числа
double	Polynomial::ft_abs(double n) { return (n >= 0 ? n : -n); }
// Возвращает максимум
double	Polynomial::ft_max(double n1, double n2) { return (n1 >= n2 ? n1 : n2); }
