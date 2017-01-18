#include "Techreport.h"

Techreport::Techreport(){}

Techreport::~Techreport(){}

Techreport::Techreport(vector<Person> p, string t, Organization inst, int y){
    authors = p;
    title = t;
    institution = inst;
    year = y;
}

Techreport::Techreport(Person p, string t, Organization inst, int y){
    authors.push_back(p);
    title = t;
    institution = inst;
    year = y;
}

void Techreport::addAuthor(Person p){
    authors.push_back(p);
}

void Techreport::addAuthors(vector<Person> p){
    for (int i = 0, max = p.size(); i < max; i++){
        authors.push_back(p[i]);
    }
}

void Techreport::addType(string t){
    typ = t;
}

void Techreport::addNumber(int n){
    number = n;
}

void Techreport::addAddress(string a){
    address = a;
}

void Techreport::addMonth(int m){
    if (m >= 1 && m <= 12) { month = m; }
}

void Techreport::addNote(string n){
    note = n;
}

string Techreport::generateLatexKey(){}

string Techreport::generateBibTex(){
    if (LatexKey.empty()) LatexKey = generateLatexKey();
    string bibtex = "TECHREPORT{";
    bibtex.append(LatexKey);
    bibtex.append(",\n");
    
    // necessary fields: author, title, institution, year
    bibtex.append("AUTHOR = {");
    for (int i = 0, max = authors.size(); i < max; i++){
        bibtex.append(authors[i].spellings[0]);
        if (i != (max - 1)) { bibtex.append(" AND "); }
    }
    bibtex.append("},\n");
    bibtex.append("TITLE = {");
    bibtex.append(title);
    bibtex.append("},\n");
    bibtex.append("INSTITUTION = {");
    bibtex.append(institution.name);
    bibtex.append("},\n");
    bibtex.append("YEAR = {");
    bibtex.append(to_string(year));
    bibtex.append("}");
    
    // optional fields: type, number, address, month, note
    if (!typ.empty()){
        bibtex.append(",\n");
        bibtex.append("TYPE = {");
        bibtex.append(typ);
        bibtex.append("}");
    }
    if (number != 0){
        bibtex.append(",\n");
        bibtex.append("NUMBER = {");
        bibtex.append(to_string(number));
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