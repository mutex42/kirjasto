#ifndef BOOKLET_H
#define BOOKLET_H

#include "Publication.h" // Base class: Publication

class Booklet : protected Publication
{
    // necessary fields: title
    string title;
    // optional fields: author, howpublished, address, month, year, note
    vector<Person> author;
    string howpublished;
    string address;
    int month;
    int year;
    string note;
public:
    ~Booklet();
    Booklet(string);
    void addAuthor(Person);
    void addAuthors(vector<Person>);
    void addHowPublished(string);
    void addAddress(string);
    void addMonth(int);
    void addYear(int);
    void addNote(string);
private:
    Booklet();    
public:
    virtual string generateLatexKey();
    virtual string generateBibTex();
};

#endif // BOOKLET_H
