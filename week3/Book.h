#include <string>
#include <iostream>
#include <vector>

#ifndef BOOK_H
#define BOOK_H

using namespace std;

class Book
{
    private:
        static int ID;
        int currentID;
        string title;
        string author;
        string genre;
        int releaseYear;
        int pageCount;
        vector<int> ratings;

    public:
        //Constructors
        Book();
        Book(string bookTitle, string nameSurname);
        Book(string bookTitle, string nameSurname, string bookGenre, int year, int pageNum);

        //Destructor
        ~Book();

        //Setters
        void setTitle(string bookTitle);
        void setAuthor(string nameSurname);
        void setGenre(string bookGenre);
        void setReleaseYear(int year);
        void setPageCount(int pageNum);

        //Getters
        string getTitle();
        string getAuthor();
        string getGenre();
        int getReleaseYear();
        int getPageCount();
        int getID();

        //Methods
        void addRating(int rating);
        void removeRating(int index);
        string toString();
};

#endif // BOOK_H
