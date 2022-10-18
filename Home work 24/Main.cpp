#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;

template <typename T>
void fill_arr(T arr[], const int length, int begin, int end) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (end - begin) + begin;
}
template <typename T>
void show_arr(T arr[], const int length) {
	cout << '[';
	for (int i = 0; i < length; i++)
		cout << arr[i] << ", ";
		cout << "\b\b]\n";
}
template <typename T>
void resize_arr(T arr[], const int length,const int newlength) {
	for (int i = 0; i < length; i++)
		arr[i] = arr[newlength];
}
int main() {
	setlocale(LC_ALL, "Russian");
	//Задача 1
	int n, m;
	cout << "Задача 1\nВведите длины массивов A и B\n";
	cin >> n >> m;
	int *A = new int[n];
	int *B = new int[m];
	cout << "Массив A:\n";
	fill_arr(A, n, 20, 150);
	show_arr(A, n);
	cout << "Массив B: \n";
	fill_arr(B, m, 10, 200);
	show_arr(B, m);
	int* C = new int[n + m];
	for (int i = 0; i < n; i++)
		C[i] = A[i];
	for (int i = n; i < n + m; i++)
		C[i] = B[i - n];
	cout << "Массив С: \n";
	show_arr(C, n + m);
	delete[]A;
	delete[]B;

	//Задача 2
	cout << "Задача 2\n ";
	int size;
	cout << "Введите длину массива: \n";
	cin >> size;
	int *mass = new int[size];
	cout << "Изначальный массив: \n";
	fill_arr(mass, size, 10, 200);
	show_arr(mass, size);
	cout << "Введите новую длину массива: \n";
	int newsize;
	cin >> newsize;
	cout << "Массив с новой длиной: \n";
	resize_arr(mass, size, newsize);
	fill_arr(mass, newsize, 10, 200);
	show_arr(mass, newsize);

	return 0;
}