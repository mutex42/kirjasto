#ifndef UNPUBLISHED_H
#define UNPUBLISHED_H

#include "Publication.h" // Base class: Publication

class Unpublished : protected Publication
{
    // necessary fields: author, title, note
    vector<Person> authors;
    string title;
    string note;
    // optional fields: month, year
    int month;
    int year;
public:
    Unpublished();
    ~Unpublished();
    Unpublished(vector<Person>, string, string);
    Unpublished(Person, string, string);
    void addAuthor(Person);
    void addAuthors(vector<Person>);
    void addMonth(int);
    void addYear(int);

public:
    virtual string generateLatexKey();
    virtual string generateBibTex();
};

#endif // UNPUBLISHED_H
