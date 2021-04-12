
#include <iostream>
using namespace std;


struct second_struct
{
    int second_value;
};

struct first_struct
{
    int first_value;
    first_struct* to_next;
    second_struct* to_second;
};

void print_list(first_struct*, int);

int main()
{
    int n = 0;
    first_struct* first_f,* current_f,* last_f;
    second_struct* first_s, * current_s,* last_s;
    first_f = new first_struct;
    first_s = new second_struct;
    current_f = first_f;
    current_s = first_s;
    last_f = nullptr;
    last_s = nullptr;
    cout << "\nEnter number of strings: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter first value: ";
        cin >> current_f->first_value;
        cout << "\nEnter second value: ";
        cin >> current_s->second_value;
        last_f = new first_struct;
        last_s = new second_struct;
        current_f->to_next = last_f;
        current_f->to_second = current_s;
        current_f = last_f;
        current_s = last_s;
    }
    current_f->to_next = first_f;
    print_list(first_f, n);
    for (int i = 0; i < n; i++)
    {
        current_f = last_f->to_next;
        delete last_f;
        last_f = current_f;
        current_s = current_f->to_second;
        delete last_s;
        last_s = current_s;
    }
}

void print_list(first_struct* first_f, int n)
{
    first_struct* current_f;
    second_struct* current_s;
    current_f = first_f;
    current_s = current_f->to_second;
    for (int i = 0; i < n; i++)
    {
        cout << "\nFirst element: " << current_f->first_value << "  Second elemnt: " << current_s->second_value;
        current_f = current_f->to_next;
        current_s = current_f->to_second;
    }
}