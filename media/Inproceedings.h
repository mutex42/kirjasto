#ifndef INPROCEEDINGS_H
#define INPROCEEDINGS_H

#include "Publication.h" // Base class: Publication

class Inproceedings : protected Publication
{
    // necessary fields: author, title, booktitle, year
    vector<Person> authors;
    string title;
    string booktitle;
    int year;
    // optional fields: editor, volume or number, series, pages, address, month, organization, publisher, note
    vector<Person> editors;
    int volume;
    int number;
    string series;
    pair<int, int> pages;
    string address;
    int month;
    Organization org;
    Publisher publisher;
    string note;
public:
    Inproceedings();
    ~Inproceedings();
    Inproceedings(vector<Person>, string, string, int);
    Inproceedings(Person, string, string, int);
    void addAuthor(Person);
    void addAuthors(vector<Person>);
    void addEditor(Person);
    void addEditors(vector<Person>);
    void addVolume(int);
    void addNumber(int);
    void addSeries(string);
    void addPages(pair<int, int>);
    void addPages(int, int);
    void addAddress(string);
    void addMonth(int);
    void addOrganization(Organization);
    void addPublisher(Publisher);
    void addNote(string);

public:
    virtual string generateLatexKey();
    virtual string generateBibTex();
};

#endif // INPROCEEDINGS_H
