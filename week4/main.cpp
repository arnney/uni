#include <iostream>
#include "Book.h"

using namespace std;

int main()
{
    try
    {
        Book test1("Crime and Punishment", "Fyodor Dostoevsky", 1866, 671);
        Book test2("Dievu miskas", "Balys Sruoga", 1957, 493);
        Book test3;

        cout << test1 << endl;
        cout << test2 << endl;
        cout << "Input book info" << endl;
        cin >> test3;
        cout << test3 << endl;

        cout << (test1 == test2) << endl;
        cout << (test1 != test2) << endl;
        cout << (test1 < test2) << endl;
        cout << (test1 <= test2) << endl;
        cout << (test1 >test2) << endl;
        cout << (test1 >= test2) << endl;

        ++test1; // Incrementing release year value
        cout << test1 << endl;
        test1++;
        cout << test1 << endl;
    }

    catch(invalid_argument &err)
    {
        cerr << err.what() << endl;
    }
    catch(...)
    {
        cerr << "Unknown exception" << endl;
    }
    return 0;
}
