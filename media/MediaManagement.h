#ifndef MEDIAMANAGEMENT_H
#define MEDIAMANAGEMENT_H

#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <sqlite3.h> 
#include <iostream>
#include "Person.h"
#include "Article.h"

using namespace std;

class MediaManagement
{
public:
    static MediaManagement& getMM(){
            static MediaManagement mm;
            return mm;
    }
    int getMediaUID();
    int getPersonUID();
    int getJournalUID();
    int getPublisherUID();
    void addPerson(Person);
    void addPersonSpelling(Person);
    void addAuthor(Person, Medium);
    void addEditor(Person, Medium);
    void addLink(Medium, string);
private:
    MediaManagement();
    ~MediaManagement();
    static MediaManagement* mm;
    int lastMediaUID;
    int lastPersonUID;
    int lastJournalUID;
    int lastPublisherUID;
    sqlite3 *db;
    char *zErrMsg;
    int rc;
    string sql;
    void createPersonTable();
    void createAuthorsTable();
    void createEditorsTable();
    void createJournalsTable();
    void createPublishersTable();
    void createJournalArticlesTable();
    void createArticlesTable();
    void createBooksTable();
    void createTitleTable();
    void createLinksTable();
    
    static int callback(void*, int, char**, char**);

};

#endif // MEDIAMANAGEMENT_H
