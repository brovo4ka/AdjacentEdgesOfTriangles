#include "pch.h"
#include <iostream>
#include <vector>

void Graph(short **a, int count) {
	std::vector< std::vector<short>> d;
	d.resize(count);
	int p, r;
	int k = 0;
	for (auto i{ 0 }; i < count / 3; ++i) {
		for (auto j{ 0 }; j < 3; ++j) {
			if (j == 2) {
				k = a[i][j];
				r = a[i][j - 2];
				d[r].push_back(k);
				d[k].push_back(r);
			}
			else
			{
				k = a[i][j];
				r = a[i][j + 1];
				d[r].push_back(k);
				d[k].push_back(r);
			}
		}
	}
	std::cout << std::endl;
	int f = 0;
	for (int i = 0; i < d.size(); i++)
		if (!d[i].empty()) f++;
	d.resize(f);
	std::cout << "Для каждой вершины будет создан список со смежными вершинами: \n" << std::endl;
	for (int i = 0; i < d.size(); i++) {
		if (!d[i].empty()) {
			std::cout << "для " << i << " = ";
			for (int v : d[i])
			{
				std::cout << v << " ";
			}
			std::cout << std::endl;
		}
	}
}



int main() {

	setlocale(LC_ALL, "rus");
	int n, k = 0;
	
	std::cout << "Введите количество вершин треугольников (eсли хотите 3 треугольника, то вершин будет 3x3=9, \nа если надо 20 треугольников, то вводите 60 :) )" << std::endl;
	std::cin >> n;
	short *b = new short[n];
	std::cout << "Введите вершины треугольников " << n << " штук. Например, для 9 вершин: 0 2 7 1 3 5 6 2 0 (можно юзать CTRL+c => CTRL+v :) )\n" << std::endl;
	for (auto i{ 0 }; i < n; ++i)
		std::cin >> b[i];
	std::cout << std::endl<<"Выводим вершины одного треугольника в отдельной строке для удобства:\n "<< std::endl;
	short **a = new short*[n];
	for (auto i{ 0 }; i < n; ++i)
		a[i] = new short[n / 3];

	for (auto i{ 0 }; i < n / 3; ++i)
		for (auto j{ 0 }; j < 3; ++j)
			a[i][j] = b[k++];

	for (auto i{ 0 }; i < n / 3; i++) {
		for (auto j{ 0 }; j < 3; ++j) {
			std::cout << a[i][j] << " ";
		}std::cout << std::endl;
	}
	Graph(a, n);
	for (auto i = 0; i < n / 3; ++i)
		delete[] a[i];
	delete[] a;
	delete[] b;
}
