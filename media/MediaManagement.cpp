#include "MediaManagement.h"

MediaManagement::MediaManagement(){
    char *zErrMsg = 0;
    rc = sqlite3_open("kirjasto.db", &db);
    if ( rc ) { cerr << "Can't open database: " << sqlite3_errmsg(db) << endl; }
    
    lastMediaUID = 0; // TODO: this needs to be changed into something useful.
    lastPersonUID = 0;
    lastJournalUID = 0;
    lastPublisherUID = 0;
}

MediaManagement::~MediaManagement(){
    sqlite3_close(db);
 //   cout << "Database closed." << endl;
}

void MediaManagement::createPersonTable() {
    sql = "CREATE TABLE PERSONS("\
                "PID INT PRIMARY KEY NOT NULL,"\
                "SPELLING TEXT NOT NULL," \
                "DEFAULTSPELLING INT NOT NULL);";
}

void MediaManagement::createAuthorsTable(){
    sql = "CREATE TABLE AUTHORS("\
                "PID INT NOT NULL," \
                "MID INT NOT NULL);";
}

void MediaManagement::createJournalsTable(){
    sql = "CREATE TABLE JOURNALS(" \
                "JID INT PRIMARY KEY NOT NULL," \
                "NAME TEXT NOT NULL);";
}

void MediaManagement::createJournalArticlesTable(){
    sql = "CREATE TABLE JAT(" \
                "MID INT NOT NULL," \
                "JID INT NOT NULL);";
}

void MediaManagement::createLinksTable(){
    sql = "CREATE TABLE LINKS("\
                "MID INT NOT NULL,"\
                "LINK TEXT NOT NULL);";
}

void MediaManagement::createArticlesTable(){
    sql =   "CREATE TABLE ARTICLES("\
                "MID INT PRIMARY KEY NOT NULL,"\
                "TITLE TEXT NOT NULL,"\
                "YEAR INT NOT NULL," \
                "VOLUME INT," \
                "NUMBER INT," \
                "PAGES1 INT," \
                "PAGES2 INT," \
                "MONTH INT," \
                "NOTE TEXT);";
}

void MediaManagement::createEditorsTable(){
    sql = "CREATE TABLE EDITORS("\
                "PID INT NOT NULL," \
                "MID INT NOT NULL);";
}

void MediaManagement::createPublishersTable(){
    sql = "CREATE TABLE PUBLISHERS("\
                "PUBID INT PRIMARY KEY NOT NULL,"\
                "NAME TEXT NOT NULL);";
}

void MediaManagement::createBooksTable(){
    sql = "CREATE TABLE BOOKS("\
                "MID INT PRIMARY KEY NOT NULL,"\
                "PUBLISHER INT NOT NULL," \
                "YEAR INT NOT NULL,"\
                "VOLUME INT," \
                "NUMBER INT," \
                "SERIES TEXT," \
                "ADDRESS TEXT," \
                "EDITION INT," \
                "MONTH INT," \
                "NOTE TEXT," \
                "ISBN TEXT);";
}

void MediaManagement::createTitleTable(){
    sql = "CREATE TABLE TITLES(" \
                "MID INT NOT NULL," \
                "TITLE TEXT NOT NULL);";
}

int MediaManagement::getMediaUID(){
    lastMediaUID++;
    return lastMediaUID;
}

int MediaManagement::getPersonUID(){
    lastPersonUID++;
    return lastPersonUID;
}

int MediaManagement::getJournalUID(){
    lastJournalUID++;
    return lastJournalUID;
}

int MediaManagement::getPublisherUID(){
    lastPublisherUID++;
    return lastPublisherUID;
}

void MediaManagement::addPerson(Person p) {
    int defaultspelling = 1;
    sql = "INSERT INTO PERSONS (PID,SPELLING,DEFAULTSPELLING) " \
                "VALUES (";
    for (size_t i = 0, max = p.spellings.size(); i < max; i++){
        sql.append(to_string(p.uid));
        sql.append(",");
        sql.append(p.spellings[i]);
        sql.append(to_string(defaultspelling));
        sql.append(")");
        if (i != (p.spellings.size() - 1)) { sql.append(", ("); }
        defaultspelling = 0;
    }
    sql.append(";");
}

// we are assuming that p is already in the persons table
void MediaManagement::addAuthor(Person p, Medium m){
    sql = "INSERT INTO AUTHORS (PID,MID) VALUES (";
    sql.append(to_string(p.uid));
    sql.append(",");
    sql.append(to_string(m.uid));
    sql.append(");");
}

// we are assuming that p is already in the persons table
void MediaManagement::addEditor(Person p, Medium m){
    sql = "INSERT INTO EDITORS (PID,MID) VALUES (";
    sql.append(to_string(p.uid));
    sql.append(",");
    sql.append(to_string(m.uid));
    sql.append(");");
}

void MediaManagement::addLink(Medium m, string l){
    sql = "INSERT INTO LINKS(MID,LINK) VALUES (";
    sql.append(to_string(m.uid));
    sql.append(",");
    sql.append(l);
    sql.append(");");
}

static int callback(void *NotUsed, int argc, char **argv, char **azColName){
   int i;
   for (i = 0; i < argc; i++){
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   return 0;
}