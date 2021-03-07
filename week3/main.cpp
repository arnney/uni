#include <iostream>
#include "Book.h"

using namespace std;

int Book::ID = 0;

int main()
{
    try
    {
        //Default constructor
        Book myBook;
        cout << myBook.toString()<< "\n" << endl;

        //Overloaded constructor
        Book myBook2("451 Fahrenheit", "Ray Bradbury", "Novel", 1994, 250);
        myBook2.addRating(10);
        myBook2.addRating(3);
        myBook2.addRating(4);
        cout << myBook2.toString() << "\n" << endl;

        //Overloaded constructor 2
        Book myBook3("Crime and Punishment", "Fyodor Dostoyevsky");
        myBook3.addRating(4);
        myBook3.addRating(9);

        //out_of_range exception. Trying to access index which is out of the possible range
        myBook3.removeRating(3);

        //invalid_argument exception. Name & surname string is in incorrect format
        myBook3.setAuthor("w@sd qwerty");
        cout << myBook3.toString() << endl;
    }

    catch (invalid_argument &error)
    {
        cerr << error.what() << endl;
    }

    catch (out_of_range &error)
    {
        cerr << error.what() << endl;
    }
    return 0;
}
