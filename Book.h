#include <string>
#include <stdexcept>
#include <sstream>

#ifndef Book_H
#define Book_H

using namespace std;

class Book
{
    private:
        string title;
        string author;
        int releaseYear;
        int pageCount;
        static int totalCount;
        int bookID;

    public:
        Book();
        Book(string, string, int, int);
        ~Book();

        //Setters
        void setTitle(string);
        void setAuthor(string);
        void setReleaseYear(int);
        void setPageCount(int);


        //Getters
        string getTitle();
        string getAuthor();
        int getReleaseYear();
        int getPageCount();

        bool operator==(const Book &) const;
        bool operator!=(const Book &) const;
        bool operator<(const Book &) const;
        bool operator<=(const Book &) const;
        bool operator>(const Book &) const;
        bool operator>=(const Book &) const;
        Book &operator++();
        Book operator++(int);

        friend istream &operator>>(istream &, Book &);
        friend ostream &operator<<(ostream &, Book &);

        //Methods
        bool checkAuthorName(string);
        string toString();

};

#endif // Book_H
