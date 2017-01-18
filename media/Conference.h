#ifndef CONFERENCE_H
#define CONFERENCE_H

#include "Publication.h" // Base class: Publication
#include "Organization.h"

class Conference : protected Publication
{
    // necessary fields: author, title, booktitle, year
    vector<Person> authors;
    string title;
    string booktitle;
    int year;
    // optional fields: editor, volume or number, series, pages, address, month, organization, publisher, note
    vector<Person> editor;
    int volume;
    int number;
    string series;
    pair<int,int> pages;
    string address;
    int month;
    Organization org; 
    Publisher publisher;
    string note;
public:
    ~Conference();
    Conference(vector<Person>, string, string, int);
    Conference(Person, string, string, int);
    void addAuthor(Person);
    void addEditor(Person);
    void addEditors(vector<Person>);
    void addVolume(int);
    void addNumber(int);
    void addSeries(string);
    void addPages(int,int);
    void addPages(pair<int,int>);
    void addAddress(string);
    void addMonth(int);
    void addOrg(Organization);
    void addPublisher(Publisher);
    void addNote(string);
private:
    Conference();

public:
    virtual string generateLatexKey();
    virtual string generateBibTex();
};

#endif // CONFERENCE_H
