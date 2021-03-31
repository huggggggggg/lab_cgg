#include <iostream>
#include <cmath>
using namespace std;

void matrix_entry(double**, const int, const int);
int scan_natural_value();
void matrix_print(double**, const int);
void matrix_multiplication(double**, const int);

	int main()
	{
		cout << "Enter the dimension of square matrices: ";
		const int n = scan_natural_value();

		cout << "\nEnter the elements of the matrix A: ";
		double** matrix_a = new double* [n];
		for (int i = 0; i < n; i++)
		{
			matrix_a[i] = new double[n];
		}
		matrix_entry(matrix_a, n, 1);
		cout << "\n A = ";
		matrix_print(matrix_a, n);

		matrix_multiplication(matrix_a, n);
		for (int i = 0; i < n; i++)
		{
			delete[]matrix_a[i];
		}
		delete[]matrix_a;
	}

	void matrix_entry(double** M_a, const int n, const int num_a)
	{
		if (num_a == 1)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					cout << "\na[" << i + 1 << "][" << j + 1 << "] = ";
					cin >> M_a[i][j];
				}
			}
		}

		else
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					cout << "\n[" << i + 1 << "][" << j + 1 << "] = ";
					cin >> M_a[i][j];
				}
			}
		}
	}

	void matrix_print(double** M_a, const int n)
	{

		for (int i = 0; i < n; i++)
		{
			cout << "( ";
			for (int j = 0; j < n; j++)
			{
				cout << M_a[i][j] << " ";
			}
			cout << ")\n     ";
		}
	}


	void matrix_multiplication(double** M_a, const int n)
	{
		double b;
		cout << "\nEnter the number to multiply matrix A: ";
		cin >> b;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				M_a[i][j] = M_a[i][j] * b;
			}
		}
		cout << "\n A = ";
		matrix_print(M_a, n);

	}

	int scan_natural_value()
	{
		while (true)
		{
			int entered_value;
			cin >> entered_value;

			if (cin.fail() || entered_value <= 0)
			{
				cout << "\nInvalid value entered. Please try again: ";
				cin.clear();
				cin.ignore(32767, '\n');
			}
			else
			{
				return entered_value;
			}
		}
	}