#include "Booklet.h"

Booklet::Booklet(){} // this should usually not be called

Booklet::~Booklet(){}

Booklet::Booklet(string t){
    title = t;
}

void Booklet::addAuthor(Person a){
    author.push_back(a);
}

void Booklet::addAuthors(vector<Person> vp){
    for (int i = 0, max = vp.size(); i < max; i++){
        author.push_back(vp[i]);
    }
}
    
void Booklet::addHowPublished(string s){
    howpublished = s;
}

void Booklet::addAddress(string a){
    address = a;
}

void Booklet::addMonth(int m){
    if (m >= 1 && m <= 12) { month = m; }
}

void Booklet::addYear(int y){
    year = y;
}

void Booklet::addNote(string s){
    note = s;
}

// TODO: implement
string Booklet::generateLatexKey(){
    
}

string Booklet::generateBibTex(){
    if (LatexKey.empty()) { LatexKey = generateLatexKey(); }
    string bibtex = "BOOKLET{";
    bibtex.append(LatexKey);
    bibtex.append(",\n");
    // necessary fields: title
    bibtex.append("TITLE = {");
    bibtex.append(title);
    bibtex.append("}");
    // optional fields: author, howpublished, address, month, year, note
    if (!author.empty()){
        bibtex.append(",\n");
        string aut = "AUTHOR =  {";
        for (int i = 0, max = author.size(); i < max; i++){
            aut.append(author[i].spellings[0]);
            if (i != (max - 1)) { aut.append(" AND "); }
        }
        aut.append("}");
        bibtex.append(aut);
    }
    if (!howpublished.empty()){
        bibtex.append(",\n");
        bibtex.append("HOWPUBLISHED = {");
        bibtex.append(howpublished);
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