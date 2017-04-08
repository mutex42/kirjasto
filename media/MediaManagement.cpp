#include "MediaManagement.h"

MediaManagement::MediaManagement(){
    char *zErrMsg = 0;
    rc = sqlite3_open("kirjasto.db", &db);
    if ( rc ) { cerr << "Can't open database: " << sqlite3_errmsg(db) << endl; }
    
    lastMediaUID = 0; // TODO: this needs to be changed into something useful.
    lastPersonUID = getlastPersonUID();
    lastJournalUID = 0;
    lastPublisherUID = 0;
}

MediaManagement::~MediaManagement(){
    sqlite3_close(db);
}

int MediaManagement::getlastMediaUID(){}

int MediaManagement::getlastPersonUID(){
	sql = "SELECT Max(PID) FROM PERSONS";
	rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
	if ( rc != SQLITE_OK ) {
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg); 
	}
}

int MediaManagement::getlastJournalUID(){}

int MediaManagement::getlastPublisherUID(){}

void MediaManagement::createPersonTable() {}

void MediaManagement::createAuthorsTable(){}

void MediaManagement::createJournalsTable(){}

void MediaManagement::createJournalArticlesTable(){}

void MediaManagement::createLinksTable(){}

void MediaManagement::createArticlesTable(){}

void MediaManagement::createEditorsTable(){}

void MediaManagement::createPublishersTable(){}

void MediaManagement::createBooksTable(){}

void MediaManagement::createTitleTable(){}

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
    int defaultspelling = 0;
    sql = "INSERT INTO PERSONS (PID,SPELLING,DEFAULTSPELLING) " \
                "VALUES (";
    for (size_t i = 0, max = p.spellings.size(); i < max; i++){
        sql.append(to_string(p.uid));
        sql.append(",");
        sql.append(p.spellings[i]);
        sql.append(to_string(defaultspelling));
        sql.append(")");
        if (i != (p.spellings.size() - 1)) { sql.append(", ("); }
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