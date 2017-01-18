#include "Mastersthesis.h"

Mastersthesis::Mastersthesis(){}

Mastersthesis::~Mastersthesis(){}

Mastersthesis::Mastersthesis(Person p, string t, Organization s, int y){
    author.push_back(p);
    title = t;
    school = s;
    year = y;
}

Mastersthesis::Mastersthesis(vector<Person> p, string t, Organization s, int y){
    author = p;
    title = t;
    school = s;
    year = y;
}

void Mastersthesis::addType(string t){
    typ = t;
}

void Mastersthesis::addAddress(string a){
    address = a;
}

void Mastersthesis::addMonth(int m){
    if (m >= 1 && m <= 12) { month = m; }
}

void Mastersthesis::addNote(string n){
    note = n;
}

string Mastersthesis::generateLatexKey(){}

string Mastersthesis::generateBibTex(){
    string bibtex = "MASTERSTHESIS{";
    if (LatexKey.empty()) { LatexKey = generateLatexKey(); }
    bibtex.append(LatexKey);
    bibtex.append(",\n");
    
    // necessary fields: author, title, school, year
    bibtex.append("AUTHOR = {");
    for (int i = 0, max = author.size(); i < max; i++){
        bibtex.append(author[i].spellings[0]);
        if (i != (max - 1)) { bibtex.append(" AND "); }
    }
    bibtex.append("},\n");
    bibtex.append("TITLE = {");
    bibtex.append(title);
    bibtex.append("},\n");
    bibtex.append("SCHOOL = {");
    bibtex.append(school.name);
    bibtex.append("},\n");
    bibtex.append("YEAR = {");
    bibtex.append(to_string(year));
    bibtex.append("}");
    
    // optional fields: type, address, month, note
    if (!typ.empty()){
        bibtex.append(",\n");
        bibtex.append("TYPE = {");
        bibtex.append(typ);
        bibtex.append("}");
    }
    if (!address.empty()){
        bibtex.append(",\n");
        bibtex.append("ADDRESS = {");
        bibtex.append(address);
        bibtex.append("}");
    }
    if (month >= 1 && month <= 12){
        bibtex.append(",\n");
        bibtex.append("MONTH = {");
        bibtex.append(to_string(month));
        bibtex.append("}");
    }
    if (!note.empty()){
        bibtex.append(",\n");
        bibtex.append("NOTE = {");
        bibtex.append(note);
        bibtex.append("}");
    }
    
    return bibtex;
}