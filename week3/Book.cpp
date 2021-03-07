#include "Book.h"
#include <stdexcept>
#include <sstream>

//Constructors
Book::Book()
{
    title = "";
    author = "";
    genre = "";
    releaseYear = 0;
    pageCount = 0;
    currentID = ++ID;
}

Book::Book(string bookTitle, string nameSurname)
{
    setTitle(bookTitle);
    setAuthor(nameSurname);
    genre = " ";
    releaseYear = 0;
    pageCount = 0;
    ++ID;
    currentID = ID;
}

Book::Book(string bookTitle, string nameSurname, string bookGenre, int year, int pageNum)
{
    setTitle(bookTitle);
    setAuthor(nameSurname);
    setGenre(bookGenre);
    setReleaseYear(year);
    setPageCount(pageNum);
    ++ID;
    currentID = ID;
}

//Destructor
Book::~Book()
{

}

//Setters
void Book::setTitle(string bookTitle)
{
    title = bookTitle;
}

void Book::setAuthor(string nameSurname)
{
    if (isalpha(nameSurname[0]) && isupper(nameSurname[0]))
    {
        for (int i = 1; i < nameSurname.length(); ++i)
        {
            if (!isalpha(nameSurname[i]) && nameSurname[i] != ' ')
            {
                throw invalid_argument ("Invalid characters in name string!");
            }

            if (nameSurname[i] == ' ' && !isupper(nameSurname[i + 1]))
            {
                throw invalid_argument ("Surname must start with a capital letter!");
            }
        }
        author = nameSurname;
    }

    else
    {
        throw invalid_argument ("Incorrect name format!");
    }
}

void Book::setGenre(string bookGenre)
{
    for (int i = 0; i < bookGenre.length(); ++i)
    {
        if (!isalpha(bookGenre[i]) && bookGenre[i] != ' ')
        {
            throw invalid_argument ("Incorrect string format!");
        }
    }
    genre = bookGenre;
}

void Book::setReleaseYear(int year)
{
    if (year >= 0)
    {
         releaseYear = year;
    }
    else
    {
        throw invalid_argument ("Release year must be a positive integer");
    }
}

void Book::setPageCount(int pageNum)
{
    if (pageNum > 0)
    {
        pageCount = pageNum;
    }
    else
    {
        throw invalid_argument ("Release year must be a positive integer");
    }
}

//Getters
string Book::getTitle()
{
    return title;
}
string Book::getAuthor()
{
    return author;
}

string Book::getGenre()
{
    return genre;
}

int Book::getReleaseYear()
{
    return releaseYear;
}

int Book::getPageCount()
{
    return pageCount;
}
int Book::getID()
{
    return currentID;
}

//Methods
void Book::addRating(int rating)
{
    if (rating < 0 || rating > 10)
    {
        throw invalid_argument("Rating value must be in the range of 1-10!");
    }
    else
    {
        ratings.push_back(rating);
    }
}

void Book::removeRating(int index)
{
    if (index < 1 || index > ratings.size())
    {
        throw out_of_range("Entered index is out of the bounds!");
    }
    else
    {
        ratings.erase(ratings.begin() + index - 1);
    }
}

string Book::toString()
{
    stringstream buffer;
    buffer << "Title: " << title << "\nAuthor: " << author;
    buffer << "\nGenre: " << genre << "\nRelease year: " << releaseYear;
    buffer << "\nPage count: " << pageCount << "\nID: " << currentID << endl;
    buffer << "Ratings: ";
    for (int i = 0; i < ratings.size(); ++i)
    {
        buffer << ratings[i] << " ";
    }
    return buffer.str();
}

