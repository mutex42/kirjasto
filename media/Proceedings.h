#ifndef PROCEEDINGS_H
#define PROCEEDINGS_H

#include "Publication.h" // Base class: Publication

class Proceedings : protected Publication
{
    // necessary fields: title, year
    string title;
    int year;
    // optional fields: editor, volume or number, series, address, month, organization, publisher, note
    vector<Person> editors;
    int volume;
    int number;
    string series;
    string address;
    int month;
    Organization org;
    Publisher publisher;
    string note;
public:
    Proceedings();
    ~Proceedings();
    Proceedings(string, int);
    void addEditor(Person);
    void addEditors(vector<Person>);
    void addVolume(int);
    void addNumber(int);
    void addSeries(string);
    void addAddress(string);
    void addMonth(int);
    void addOrganization(Organization);
    void addPublisher(Publisher);
    void addNote(string);
public:
    virtual string generateLatexKey();
    virtual string generateBibTex();
};

#endif // PROCEEDINGS_H
