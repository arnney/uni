#include "Book.h"

#define DEFAULT_TITLE "-"
#define DEFAULT_AUTHOR "-"
#define DEFAULT_RELEASE_YEAR 0
#define DEFAULT_PAGE_COUNT 0

int Book::totalCount = 0;

Book::Book()
{
    title = DEFAULT_TITLE;
    author = DEFAULT_AUTHOR;
    releaseYear = DEFAULT_RELEASE_YEAR;
    pageCount = DEFAULT_PAGE_COUNT;
    bookID = totalCount;
    ++totalCount;
}

Book::Book(string inputTitle, string name, int year, int pageNum)
{
    setTitle(inputTitle);
    setAuthor(name);
    setReleaseYear(year);
    setPageCount(pageNum);
    bookID = totalCount;
    ++totalCount;
}

Book::~Book()
{

}


//Setters
void Book::setTitle(string inputTitle)
{
    if (inputTitle[0] == ' ')
    {
        throw invalid_argument("Title must contain characters!");
    }
    else
    {
        title = inputTitle;
    }
}

void Book::setAuthor(string name)
{
    if (!checkAuthorName(name))
    {
        throw invalid_argument("Incorrect name format!");
    }
    else
    {
        author = name;
    }
}

void Book::setReleaseYear(int year)
{
    if (year <= 0)
    {
        throw invalid_argument("Release year value must be higher than 0!");
    }
    else
    {
        releaseYear = year;
    }
}

void Book::setPageCount(int pageNum)
{
    if (pageNum <= 0)
    {
        throw invalid_argument("Page count value must be a positive integer!");
    }
    else
    {
        pageCount = pageNum;
    }
}

bool Book::checkAuthorName(string name)
{
    if (!isupper(name[0]) || !isalpha(name[0]))
    {
        return false;
    }
    else
    {
        for (int i = 1; i < name.length(); ++i)
        {
            if (name[i] == ' ' && isupper(name[i + 1]))
            {
                i++;
            }
            else if (!isalpha(name[i]))
            {
                return false;
            }
        }
    }
    return true;
}

string Book::getTitle()
{
   return title;
}

string Book::getAuthor()
{
    return author;
}

int Book::getReleaseYear()
{
    return releaseYear;
}

int Book::getPageCount()
{
    return pageCount;
}

string Book::toString()
{
    stringstream buffer;
    buffer << "ID: " << bookID << " " << "Title: " << title << " ";
    buffer << "Release year: " << releaseYear << " ";
    buffer << "Page count: " << pageCount;
    return buffer.str();
}

bool Book::operator==(const Book &obj)const
{
    if (this->title == obj.title && this->author == obj.author && this->releaseYear == obj.releaseYear)
    {
        return 1;
    }
    return 0;
}

bool Book::operator!=(const Book &obj) const
{
    return !(*this == obj);
}

bool Book::operator<(const Book &obj) const
{
    if (this->releaseYear < obj.releaseYear)
    {
        return 1;
    }
    return 0;
}

bool Book::operator<=(const Book &obj) const
{
    if (*this < obj || *this == obj)
    {
        return 1;
    }
    return 0;
}

bool Book::operator>(const Book &obj) const
{
    return !(*this < obj);
}

bool Book::operator>=(const Book &obj) const
{
    return (*this > obj || *this == obj);
}

Book &Book::operator++()
{
    this->releaseYear++;
    return *this;
}

Book Book::operator++(int)
{
    Book temp = *this;
    this->releaseYear++;
    return temp;
}

istream &operator>>(istream &in, Book &obj)
{
    Book temp;
    in >> temp.title >> temp.author >> temp.releaseYear >> temp.pageCount;
    obj.setTitle(temp.title);
    obj.setAuthor(temp.author);
    obj.setReleaseYear(temp.releaseYear);
    obj.setPageCount(temp.pageCount);
    return in;
}

ostream &operator<<(ostream &out, Book &obj)
{
    out << obj.bookID << " Title: " << obj.title << " Author: "  << obj.author;
    out << " Release year: " << obj.releaseYear << " Page Count: " << obj.pageCount;
    return out;
}
