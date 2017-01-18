#include "Phdthesis.h"

Phdthesis::Phdthesis(){}

Phdthesis::~Phdthesis(){}

Phdthesis::Phdthesis(vector<Person> a, string t, Organization s, int y){
    authors = a;
    title = t;
    school = s;
    year = y;
}

Phdthesis::Phdthesis(Person a, string t, Organization s, int y){
    authors.push_back(a);
    title = t;
    school = s;
    year = y;
}

void Phdthesis::addType(string t){
    typ = t;
}

void Phdthesis::addAddress(string a){
    address = a;
}

void Phdthesis::addMonth(int m){
    if (m >= 1 && m <= 12) { month = m; }
}

void Phdthesis::addNote(string n){
    note = n;
}

string Phdthesis::generateLatexKey(){}

string Phdthesis::generateBibTex(){
    string bibtex = "PHDTHESIS{";
    if (LatexKey.empty()) { LatexKey = generateLatexKey(); }
    bibtex.append(LatexKey);
    bibtex.append(",\n");
    
    // necessary fields: author, title, school, year
    bibtex.append("AUTHOR = {");
    for (int i = 0, max = authors.size(); i < max; i++){
        bibtex.append(authors[i].spellings[0]);
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
