#define _CRT_SECURE_NO_DEPRECATE 
#include <windows.h> 
#include <cstdio> 
#include <cstdlib> 
#include <ctime> 
#include <iostream>

using namespace std;

#define LIGHTGRAY 7 
#define LIGHTRED  12

int IdentNumb(int A[], int N) { 

	int max_num = 0;
	for (int i = 0; i < N; i++)
	{
		int count = 1;
		for (int j = i + 1; j < N; j++)
			if (A[i] == A[j]) 
				count++;
		if (count > max_num) { // поиск самого большого числа в массиве
			max_num = count;
		}if (A[i] == max_num) { // при числах 1,2,3,4,5 не будет подчёркиваться число
			return 0;
		}
	}

	for (int i = 0; i < N; i++)
	{
		int count = 1;
		for (int j = i + 1; j < N; j++)
			if (A[i] == A[j])
				count++;
		if (count == max_num) { // проверяем число и возращаем то которое должно быть отмеченно
			return A[i];
		} 
	}
}




void TextColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void ShowArray(int A[], int N, int IdentNumber) {

	for (int i = 0; i < N; i++) {
		TextColor(A[i] == IdentNumber ? LIGHTRED : LIGHTGRAY); // A[i] == IdentNumbet - это условие чо делает ? Если условие верное, то будет LighRed, в противном случае LightGray. 
		printf("%d ", A[i], i % 10 == 9 ? "\r\n" : " ");
	}
	if (N % 10) printf("\n");
}

int main()
{
	int n, * a; // * показывает значение переменной по заданному адресу
	cout << "Please enter amount of number in array = "; cin >> n;

	a = new int[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	ShowArray(a, n, IdentNumb(a,n));
	return 0;


}

