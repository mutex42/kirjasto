#ifndef PHDTHESIS_H
#define PHDTHESIS_H

#include "Publication.h" // Base class: Publication

class Phdthesis : protected Publication
{
    // necessary fields: author, title, school, year
    vector<Person> authors; 
    string title;
    Organization school;
    int year;
    // optional fields: type, address, month, note
    string typ;
    string address;
    int month;
    string note;
public:
    Phdthesis();
    ~Phdthesis();
    Phdthesis(vector<Person>, string, Organization, int);
    Phdthesis(Person, string, Organization, int);
    void addType(string);
    void addAddress(string);
    void addMonth(int);
    void addNote(string);
public:
    virtual string generateLatexKey();
    virtual string generateBibTex();
};

#endif // PHDTHESIS_H
