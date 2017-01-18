#ifndef INBOOK_H
#define INBOOK_H

#include "Publication.h" // Base class: Publication

using namespace std;

class Inbook : protected Publication
{
    // necessary fields: author or editor, title, booktitle, chapter and/or pages, publisher, year
    vector<Person> authors;
    vector<Person> editors;
    string title;
    string booktitle;
    int chapter;
    pair<int,int> pages;
    Publisher publisher;
    int year;
    // optional fields: volume or number, series, type, address, edition, month, note
    int volume;
    int number;
    string series;
    string typ;
    string address;
    int edition;
    int month;
    string note;
public:
    Inbook();
    ~Inbook();
    Inbook(vector<Person>,int,string,string,int,pair<int,int>,Publisher,int);
    Inbook(Person,int,string,string,int,pair<int,int>,Publisher,int);
    Inbook(vector<Person>,int,string,string,pair<int,int>,Publisher,int);
    Inbook(Person,int,string,string,pair<int,int>,Publisher,int);
    Inbook(vector<Person>,int,string,string,int,Publisher,int);
    Inbook(Person,int,string,string,int,Publisher,int);
    void addVolume(int);
    void addNumber(int);
    void addSeries(string);
    void addType(string);
    void addEdition(int);
    void addMonth(int);
    void addNote(string);
public:
    virtual string generateLatexKey();
    virtual string generateBibTex();
};

#endif // INBOOK_H
