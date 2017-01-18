#ifndef MASTERSTHESIS_H
#define MASTERSTHESIS_H

#include "Publication.h" // Base class: Publication

class Mastersthesis : protected Publication
{
    // necessary fields: author, title, school, year
    vector<Person> author;
    string title;
    Organization school;
    int year;
    // optional fields: type, address, month, note
    string typ;
    string address;
    int month;
    string note;
public:
    Mastersthesis();
    ~Mastersthesis();
    Mastersthesis(Person, string, Organization, int);
    Mastersthesis(vector<Person>, string, Organization, int);
    void addType(string);
    void addAddress(string);
    void addMonth(int);
    void addNote(string);

public:
    virtual string generateLatexKey();
    virtual string generateBibTex();
};

#endif // MASTERSTHESIS_H
