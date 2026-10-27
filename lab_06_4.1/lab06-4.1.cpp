#include<iostream>
#include<string> 
#include<time.h> 
#include<iomanip>
#include<windows.h>
#include<locale>

using namespace std;

void Create(double* a, const int size, const int Low, const int High, int i)
{
	a[i] = Low + (High - Low) * (double)rand() / RAND_MAX;
	if (i < size - 1)
		Create(a, size, Low, High, i + 1);
}

void Print(double* a, const int size, int i)
{
	cout << setw(8) << fixed << setprecision(2) << a[i];
	if (i < size - 1)
		Print(a, size, i + 1);
	else
		cout << endl;
}

int CountPositive(double* a, const int n, int i)
{
	if (i < n)
	{
		if (a[i] > 0)
			return 1 + CountPositive(a, n, i + 1);
		else
			return CountPositive(a, n, i + 1);
	}
	else
		return 0;
}

double ProductPositive(double* a, const int n, int i)
{
	if (i < n)
	{
		if (a[i] > 0)
			return a[i] * ProductPositive(a, n, i + 1);
		else
			return ProductPositive(a, n, i + 1);
	}
	else
		return 1;
}

int IndexMin(double* a, const int n, int i, int imin)
{
	if (i < n)
	{
		if (a[i] < a[imin])
			imin = i;
		return IndexMin(a, n, i + 1, imin);
	}
	else
		return imin;
}

double SumBefore(double* a, const int last, int i)
{
	if (i < last)
		return a[i] + SumBefore(a, last, i + 1);
	else
		return 0;
}

void Swap(double& x, double& y)
{
	double tmp = x;
	x = y;
	y = tmp;
}

int IndexMinStep(double* a, const int n, int j, int imin)
{
	if (j < n)
	{
		if (a[j] < a[imin])
			imin = j;
		return IndexMinStep(a, n, j + 2, imin);
	}
	else
		return imin;
}

void SortStep(double* a, const int n, int i)
{
	if (i + 2 < n)
	{
		int imin = IndexMinStep(a, n, i + 2, i);
		Swap(a[i], a[imin]);
		SortStep(a, n, i + 2);
	}
}

int main()
{
	SetConsoleOutputCP(65001);
	SetConsoleCP(65001);

	srand((unsigned)time(NULL));
	int n;
	cout << "n=";
	cin >> n;
	if (n <= 0)
	{
		cout << "додатній масив" << endl;
		cout << endl;
		return 1;
	}

	double* a = new double[n];

	Create(a, n, -10, 10, 0);
	cout << "Початковий масив" << endl;
	cout << endl;
	Print(a, n, 0);
	cout << endl;
	if (CountPositive(a, n, 0) > 0)
		cout << "Добуток додатніх= " << ProductPositive(a, n, 0) << endl;
	else
		cout << "Додатніх елементів немає" << endl;
	int imin = IndexMin(a, n, 1, 0);
	cout << endl;
	cout << "Індекс мінімального елемента= " << imin << endl;
	cout << endl;
	cout << "Сума елементів до мінімального = " << SumBefore(a, imin, 0) << endl;

	SortStep(a, n, 0);
	SortStep(a, n, 1);
	cout << endl;
	cout << "Після впорядкування" << endl;
	cout << endl;
	Print(a, n, 0);

	delete[] a;
	return 0;
}