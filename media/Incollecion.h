#ifndef INCOLLECION_H
#define INCOLLECION_H

#include "Publication.h" // Base class: Publication

class Incollecion : protected Publication
{
    // necessary fields: author, title, booktitle, publisher, year
    vector<Person> authors;
    string title;
    string booktitle;
    Publisher publisher;
    int year;
    // optional fields: editor, volume or number, series, type, chapter, pages, address, edition, month, note
    vector<Person> editors;
    int volume;
    int number;
    string series;
    string typ;
    int chapter;
    pair<int,int> pages;
    string address;
    int edition;
    int month;
    string note;
public:
    Incollecion();
    ~Incollecion();
    Incollecion(vector<Person>, string, string, Publisher, int);
    Incollecion(Person, string, string, Publisher, int);
    void addAuthor(Person);
    void addEditor(Person);
    void addEditors(vector<Person>);
    void addVolume(int);
    void addNumber(int);
    void addSeries(string);
    void addType(string);
    void addChapter(int);
    void addPages(int, int);
    void addPages(pair<int, int>);
    void addAddress(string);
    void addEdition(int);
    void addMonth(int);
    void addNote(string);
public:
    virtual string generateLatexKey();
    virtual string generateBibTex();
};

#endif // INCOLLECION_H
