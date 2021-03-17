#include <iostream>
#include <cmath>

using namespace std;

double scan_double();
int scan_natural_number();
int scan_whole_number();


int main()
{
	double number_array[20];
	double chance_array[20];

	cout << "Enter order k: ";
	int k = scan_whole_number();

	cout << "Enter the number of random values: ";
	int n = scan_natural_number();

	double max_chance = 1;

	for (int i = 1 ; i <= n; i++) 
	{
		cout << "Enter the value E" << i << ": ";
		number_array[i] = scan_double(); 
		cout << "Enter probability p" << i << ": ";
		if (i != n) 
		{
			chance_array[i] = scan_double();
			while (chance_array[i] > max_chance)
			{
				cout << "Error: Maximum Probability Exceeded! (left " << max_chance << ") Re-enter: ";
				chance_array[i] = scan_double();
			}
			max_chance -= chance_array[i];
			if (max_chance == 0)
			{
				cout << "The maximum probability has been exhausted. The rest of the values cannot be assigned a probability.";
				n = i;
				break;
			}
			else {}
		}
		else 
		{
			cout << "The last element is automatically assigned the remaining probability:" << max_chance;
			chance_array[i] = max_chance;
			max_chance = 0;
		}
	}
	
	double sum_moment = 0;

	for (int i = 1; i <= n; i++) 
	{
		sum_moment = pow((number_array[i]), k) * chance_array[i];
	}
	cout << "Moment of order k = " << sum_moment;
	return 0;
}


double scan_double() 
{
	while (true)
	{
		double input_data;
		cin >> input_data;

		if (cin.fail())  
		{
			cout << "Invalid value entered. Try again: ";
			cin.clear();
			cin.ignore(32767, '\n');
		}
		else
		{
			return input_data;
		}
	}
}

int scan_natural_number() 
{
	while (true)
	{
		int input_data;
		cin >> input_data;

		if (cin.fail() || input_data <= 0)  
		{
			cout << "Invalid value entered. Try again: ";
			cin.clear();
			cin.ignore(32767, '\n');
		}
		else
		{
			return input_data;
		}
	}
}

int scan_whole_number()
{
	while (true)
	{
		int input_data;
		cin >> input_data;

		if (cin.fail())  
		{
			cout << "Invalid value entered. Try again: ";
			cin.clear();
			cin.ignore(32767, '\n');
		}
		else
		{
			return input_data;
		}
	}
}