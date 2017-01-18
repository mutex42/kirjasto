#ifndef MANUAL_H
#define MANUAL_H

#include "Publication.h" // Base class: Publication

class Manual : protected Publication
{
    // necessary fields: title
    string title;
    // optional fields: author, organization, address, edition, month, year, note
    vector<Person> authors;
    Organization org;
    string address;
    int edition;
    int month;
    int year;
    string note;
public:
    Manual();
    ~Manual();
    Manual(string);
    void addAuthor(Person);
    void addAuthors(vector<Person>);
    void addOrganization(Organization);
    void addAddress(string);
    void addEdition(int);
    void addMonth(int);
    void addYear(int);
    void addNote(string);


public:
    virtual string generateLatexKey();
    virtual string generateBibTex();
};

#endif // MANUAL_H
