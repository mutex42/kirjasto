#ifndef ARTICLE_H
#define ARTICLE_H

#include "Publication.h" // Base class: Publication
#include "Journal.h"
#include "Person.h"

class Article : protected Publication
{
    // necessary fields: author, title, journal, year
    vector<Person> authors;
    string title; 
    Journal journal;
    int year;
    // optional fields: volume, number, pages, month, note
    int volume;
    int number;
    pair<int,int> pages;
    int month;
    string note;
public:
    Article(vector<Person>, string, Journal, int);
    Article(Person, string, Journal, int);
    ~Article();
    void addVolume(int);
    void addNumber(int);
    void addPages(pair<int,int>);
    void addPages(int, int);
    void addMonth(int);
    void addNote(string);
    virtual string generateBibTex();
    virtual string generateLatexKey();
	virtual string generateInsertStatement();
private:
    Article();

};

#endif // ARTICLE_H
