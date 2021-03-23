#include <iostream>
#include <cmath>
using namespace std;

double verify_value();
void receive_coordinates(double**, int);
int scan_natural_value();
void calculating_scalar_product(double*, double*, int);

	int main()
	{
		cout << "Enter the dimension of the space: \n";

		int measurement = scan_natural_value();
		double* V_a;
		double* V_b;

		cout << "Enter the coordinates of the vector a: \n";
		receive_coordinates(&V_a, measurement);

		cout << "Enter the coordinates of the vector b: \n";
		receive_coordinates(&V_b, measurement);

		cout << "Coordinates of vector a: ";
		for (int i = 1; i <= measurement; i++)
		{
			cout << " " << V_a[i];
		}

		cout << "\nCoordinates of vector b: ";
		for (int i = 1; i <= measurement; i++)
		{
			cout << " " << V_b[i];
		}

		calculating_scalar_product(V_a, V_b, measurement);
	}


	void calculating_scalar_product(double* a, double* b, int n) 
	{
		double scalar_product = 0;
		for (int i = 1; i <= n; i++)
		{
			scalar_product += a[i] * b[i];
		}
		cout << "\nThe scalar product of a and b is equal to "<< scalar_product << ".";
	}


	void receive_coordinates(double** vector, int n)
	{
		double* specify_vector = new double[n];
		for (int i = 1; i <= n; i++)
		{
			specify_vector[i] = verify_value();
		}
		*vector = specify_vector;
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

	double verify_value() 
	{
		while (true)
		{
			double entered_value;
			cin >> entered_value;

			if (cin.fail())  
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