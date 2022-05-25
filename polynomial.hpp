#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Polynomial {
	private:
		string		str;	// исходная строка
		string		ans;	// строка с ответом
		double		a;		// аргумент перед X^2
		double		b;		// аргумент перед X^1
		double		c;		// аргумент перед X^0
		int			degree;	// степень уравнения

		// Определение степени уранения и вывод его корней, если степень не превышает 2
		void	degree_polynomial();
		// Формирвование ответа для квадратного уравнения
		void	count_roots_2();
		// Вычисление дискриминанта в квадрате
		double	discriminant_2();
		// Общий парсер строки (ДОДЕЛЫВАТЬ!!!)
		bool	parser();
		// Парсер на запрещённые символы и наличи одного символа '='
		bool	parser_forbidden();
		// Парсер коэффициентов до знака '=' или конца. Предполагается, что форма записи корректна
		// Возвращает индекс элемента на котором закончилась обработка
		int		parser_coef(vector<double> &coef, int start = 0);
		// Приводит подобные слагаемые из левой и правой части уравнения
		// Возвращает степень уравнения
		int		coef_reduction(vector<double> &coef1, vector<double> &coef2, vector<double> &coef);
		// Формирование сокращённой формы уравнения в ответ
		string	reduced_form(vector<double> &coef);

	public:
		// Конструктор по заданию
		Polynomial(string str);
		// Дополнительный конструктор для предварительной проверки метода решения
		Polynomial(double a, double b, double c);

		// Вычисление квадратного корня для положительных чисел
		// Итерационная формула Герона (быстро сойдётся при любом x)
		double	ft_sqrt(double n);
		// Вычисление модуля числа
		double	ft_abs(double n);
		// Возвращает максимум
		double	ft_max(double n1, double n2);
};
