#include "Unpublished.h"

Unpublished::Unpublished(){}

Unpublished::~Unpublished(){}

Unpublished::Unpublished(vector<Person> p, string t, string n){
    authors = p;
    title = t;
    note = n;
}

Unpublished::Unpublished(Person p, string t, string n){
    authors.push_back(p);
    title = t;
    note = n;
}

void Unpublished::addAuthor(Person p){
    authors.push_back(p);
}

void Unpublished::addAuthors(vector<Person> p){
    for (int i = 0, max = p.size(); i < max; i++){
        authors.push_back(p[i]);
    }
}

void Unpublished::addMonth(int m){
    if (m >= 1 && m <= 12) { month = m; }
}

void Unpublished::addYear(int y){
    year = y;
}

string Unpublished::generateLatexKey(){}

string Unpublished::generateBibTex(){
    if (LatexKey.empty()) LatexKey = generateLatexKey();
    string bibtex = "UNPUBLISHED{";
    bibtex.append(LatexKey);
    bibtex.append(",\n");
    
    // necessary fields: author, title, note
    bibtex.append("AUTHOR = {");
    for (int i = 0, max = authors.size(); i < max; i++){
        bibtex.append(authors[i].spellings[0]);
        if (i != (max - 1)) { bibtex.append(" AND "); }
    }
    bibtex.append("},\n");
    bibtex.append("TITLE = {");
    bibtex.append(title);
    bibtex.append("},\n");
    bibtex.append("NOTE = {");
    bibtex.append(note);
    bibtex.append("}");
    
    // optional fields: month, year
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

    return bibtex;
}