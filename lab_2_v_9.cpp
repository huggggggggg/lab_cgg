#include <iostream>
#include <cmath> 

using namespace std;
int scan_int();
double endless_row(int);

int main()
{
	cout << "Enter the upper bound (integer): ";
	int n = scan_int();
	double result = endless_row(n);
	cout << "The product is: " << result;
}

int scan_int(){ 

	while (true){

		int input_data;
		cin >> input_data;
			if (cin.fail() || input_data < 0){ 
				cout << "Invalid value entered. Try again: \n";
				cin.clear();
				cin.ignore(32767, '\n');
			}
			else{
				return input_data;
			}
		}
}

double endless_row(int n){

	double production = 1;
	for (int i = 1; i <= n; i++){
		production = production * (1 + (pow((0.5), i*2)));
	}
	return production;
}
