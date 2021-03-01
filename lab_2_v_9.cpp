#include <iostream>
#include <cmath> 
using namespace std;

int verify_value();
double endless_row(int);


int main()
{
	cout << "Enter the upper bound: "
	int n = scan_int();
	double result = endless_row(n);
	cout << "The product is: " << result;
}

int verify_value(){ 
	
	while (true){

		int entered_value;
		cin >> entered_value;
		if (cin.fail() || entered_value < 0){
		cout << "Invalid value entered. Try again: \n";
			cin.clear();
			cin.ignore(32767, '\n');
		}
		else{
			return entered_value;
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
