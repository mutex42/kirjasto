#ifndef MISC_H
#define MISC_H

#include "Publication.h" // Base class: Publication

class Misc : protected Publication
{
    // optional fields: author, title, howpublished, month, year, note
    vector<Person> authors;
    string title;
    string howpublished;
    int month;
    int year;
    string note;
public:
    Misc();
    ~Misc();
    void addAuthor(Person);
    void addAuthors(vector<Person>);
    void addTitle(string);
    void addHowPublished(string);
    void addMonth(int);
    void addYear(int);
    void addNote(string);

public:
    virtual string generateLatexKey();
    virtual string generateBibTex();
};

#endif // MISC_H
