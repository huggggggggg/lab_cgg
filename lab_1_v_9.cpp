#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double k = 0; //
    double w = 0;
    double f_0 = 0;
    double p_2 = asin(1.0); //arcsin(1) = P/2
    double t = 0;

    while (true)
    {
        cout << "k = "; 
        cin >> k;
        cout << "w = "; 
        cin >> w;

        if (w == 0) // w != 0
            cout << "Incorrect entry of the value - the body is at rest.\n"; 
        else
            if (k < 1)
                cout << "The deviation cannot have a ratio greater than the amplitude.\n";
            else
                if (p_2 < (f_0 = asin(1 / k))) // P/2 - arcsin(1/k) > 0
                    cout << "The given 1/k value is invalid.\n";
                else
                    if ((t = (p_2 - f_0) / w) == 0) 
                        cout << "The pendulum has already reached its amplitude deviation.\n";
                    else
                        cout << "The pendulum reaches the amplitude deviation in: " << t << " \n";
    }
    system("pause");
    return 0;
}

