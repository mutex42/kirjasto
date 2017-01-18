#include "Person.h"
#include "MediaManagement.h"

Person::Person(){
    MediaManagement& mm = MediaManagement::getMM();
    uid = mm.getPersonUID();
}

Person::Person( string sp ){
    MediaManagement& mm = MediaManagement::getMM();
    uid = mm.getPersonUID();
    this->addSpelling( sp );
}

Person::~Person(){}

void Person::addSpelling( string sp ){
    spellings.push_back( sp );
}