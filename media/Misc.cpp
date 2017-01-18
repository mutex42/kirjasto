#include "Misc.h"

Misc::Misc(){}

Misc::~Misc(){}

void Misc::addAuthor(Person p){
    authors.push_back(p);
}

void Misc::addAuthors(vector<Person> p){
    for (int i = 0, max = p.size(); i < max; i++){
        authors.push_back(p[i]);
    }
}

void Misc::addTitle(string t){
    title = t;
}

void Misc::addHowPublished(string s){
    howpublished = s;
}

void Misc::addMonth(int m){
    if (m >= 1 && m <= 12) { month = m; } 
}

void Misc::addYear(int y){
    year = y;
}

void Misc::addNote(string n){
    note = n;
}

string Misc::generateBibTex(){
    string bibtex = "MISC{";
    if (LatexKey.empty()) LatexKey = generateLatexKey();
    bibtex.append(LatexKey);
    bibtex.append(",\n");
    
    // no necessary fields, so...
    // optional fields: author, title, howpublished, month, year, note
    if ( !authors.empty() ){
        string auth = "AUTHOR = {";
        for (int i = 0, max = authors.size(); i < max; i++){
            auth.append(authors[i].spellings[0]);
            if (i == (max - 1)) { 
                auth.append("}");
            } else {
                auth.append(" AND "); 
            }
        }
        bibtex.append(auth);
    }
    if (!title.empty()){
        bibtex.append(",\n");
        bibtex.append("TITLE = {");
        bibtex.append(title);
        bibtex.append("}");
    }
    if (!howpublished.empty()){
        bibtex.append(",\n");
        bibtex.append("HOWPUBLISHED = {");
        bibtex.append(howpublished);
        bibtex.append("}");
    }
    if (!(month >= 1 && month <= 12)){
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

string Misc::generateLatexKey(){}
