#include "Journal.h"
#include "MediaManagement.h"

Journal::Journal(){
    MediaManagement& mm = MediaManagement::getMM();
    uid = mm.getJournalUID();
}

Journal::Journal(string n){
    MediaManagement& mm = MediaManagement::getMM();
    uid = mm.getJournalUID();
    name = n;
}

Journal::~Journal(){}

