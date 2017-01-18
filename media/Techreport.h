#ifndef TECHREPORT_H
#define TECHREPORT_H

#include "Publication.h" // Base class: Publication

class Techreport : protected Publication
{
    // necessary fields: author, title, institution, year
    vector<Person> authors;
    string title;
    Organization institution;
    int year;
    // optional fields: type, number, address, month, note
    string typ;
    int number;
    string address;
    int month;
    string note;
public:
    Techreport();
    ~Techreport();
    Techreport(vector<Person>, string, Organization, int);
    Techreport(Person, string, Organization, int);
    void addAuthor(Person);
    void addAuthors(vector<Person>);
    void addType(string);
    void addNumber(int);
    void addAddress(string);
    void addMonth(int);
    void addNote(string);

public:
    virtual string generateLatexKey();
    virtual string generateBibTex();
};

#endif // TECHREPORT_H
