#ifndef BOOK_H
#define BOOK_H

#include "Publication.h" // Base class: Publication
#include "Person.h"
#include "Publisher.h"

class Book : protected Publication
{
    // necessary fields: author oder editor, title, publisher, year
    vector<Person> authors;
    vector<Person> editors;
    vector<string> title;
    Publisher publisher;
    int year;
    
    // optional fields: volume or number, series, address, edition, month, note, isbn
    int volume;
    int number;
    string series;
    string address;
    int edition;
    int month;
    string note;
    string isbn;
    
public:
    Book(vector<Person>, int, vector<string>, Publisher, int);
    Book(vector<Person>, int, string, Publisher, int);
    Book(Person, int, vector<string>, Publisher, int);
    Book(Person, int, string, Publisher, int);
    void addVolume(int);
    void addNumber(int);
    void addSeries(string);
    void addAddress(string);
    void addEdition(int);
    void addMonth(int);
    void addNote(string);
    void addISBN(string);
    ~Book();
    
private:
    Book();

public:  virtual string generateLatexKey();
            virtual string generateBibTex();

};

#endif // BOOK_H
