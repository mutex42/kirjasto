#include "Publication.h"

Publication::Publication(){}

Publication::~Publication(){}

// TODO: check if key is unique
void Publication::addLatexKey(string s){ 
    LatexKey = s;
}

// TODO: check if key is unique
string Publication::generateLatexKey(){ // this should be overwritten by all subclasses
    return to_string(uid);
}

string Publication::generateBibTex(){ // this should be overwritten by all subclasses
    return "";
}