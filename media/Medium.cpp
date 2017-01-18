#include "Medium.h"
#include "MediaManagement.h"

// constructor
Medium::Medium(){
    MediaManagement& mm = MediaManagement::getMM();
    uid = mm.getMediaUID();
}

// destructor
Medium::~Medium(){}

void Medium::addLink(string link, string t){
    links.push_back(make_pair(link,t));
}

string Medium::generateInsertStatement(){
	return NULL;
}