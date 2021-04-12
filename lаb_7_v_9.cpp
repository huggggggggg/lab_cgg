#include <iostream>
#include <cmath>

using namespace std;
double verify_value();

    class Calculating
    {
        public:
        double x;
        double y;
        double z;
        double a;

        void modul()
        {
            a = sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
        }

    };

    int main()
    {
        Calculating Obj;
        cout << "Find the modulus of a vector in three-dimensional space.\nEnter the coefficients:";

        do {
            cout << "\nx = ";
            Obj.x = verify_value();
            cout << "y = ";
            Obj.y = verify_value();
            cout << "z = ";
            Obj.z = verify_value();
            
            if (Obj.x == 0 && Obj.y == 0 && Obj.z == 0)
            {
                cout << "The modulus of a three-dimensional space is equal to 0.";
                return 0;
            }
        } 

        while (Obj.x == 0 && Obj.y == 0 && Obj.z == 0);
        Obj.modul();
        if (Obj.a > 0)
        {
            cout << "The modulus of a three-dimensional space is equal to " << Obj.a << ".";
            return 0;
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
