#include "Manual.h"

Manual::Manual(){}

Manual::~Manual(){}

Manual::Manual(string t){
    title = t;
}

void Manual::addAuthor(Person p){
    authors.push_back(p);
}

void Manual::addAuthors(vector<Person> p){
    for (int i = 0, max = p.size(); i < max; i++){
        authors.push_back(p[i]);
    }
}

void Manual::addOrganization(Organization o){
    org = o;
}

void Manual::addAddress(string a){
    address = a;
}

void Manual::addEdition(int e){
    edition = e;
}

void Manual::addMonth(int m){
    if (m >= 1 && m <= 12) { month = m; }
}

void Manual::addYear(int y){
    year = y;
}

void Manual::addNote(string n){
    note = n;
}

string Manual::generateLatexKey(){}

string Manual::generateBibTex(){
    string bibtex = "MANUAL = {";
    if (LatexKey.empty()) { LatexKey = generateLatexKey(); }
    bibtex.append(LatexKey);
    bibtex.append(",\n");
    
    // necessary fields: title
    bibtex.append("TITLE = {");
    bibtex.append(title);
    bibtex.append("}");
    
    // optional fields: author, organization, address, edition, month, year, note
    if (!authors.empty()){
        bibtex.append(",\n");
        bibtex.append("AUTHOR = {");
        for (int i = 0, max = authors.size(); i < max; i++){
            bibtex.append(authors[i].spellings[i]);
            if (i != (max - 1)) { bibtex.append(" AND "); }
        }
        bibtex.append("}");
    }
    if (!org.name.empty()){
        bibtex.append(",\n");
        bibtex.append("ORGANIZATION = {");
        bibtex.append(org.name);
        bibtex.append("}");
    } 
    if (!address.empty()){
        bibtex.append(",\n");
        bibtex.append("ADDRESS = {");
        bibtex.append(address);
        bibtex.append("}");
    }
    if (edition != 0){
        bibtex.append(",\n");
        bibtex.append("EDITION = {");
        bibtex.append(to_string(edition));
        bibtex.append("}");
    }
    if (month >= 1 && month <= 12){
        bibtex.append(",\n");
        bibtex.append("MONTH = {");
        bibtex.append(to_string(month));
        bibtex.append("}");
    }
    if (year != 0){
        bibtex.append(",\n");
        bibtex.append("YEAR = {");
        bibtex.append(to_string(year));
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
