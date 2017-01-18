#include "Book.h"

Book::Book(){} 

Book::~Book(){}

// constructor with all necessary fields
Book::Book(vector<Person> aued, int auedb, vector<string> t, Publisher p, int y){
    if (auedb == 0) authors = aued;
    if (auedb == 1) editors = aued;
    title = t;
    publisher = p;
    year = y;
}

// convenience function: constructor with only one version of the title
Book::Book(vector<Person> aued, int auedb, string t, Publisher p, int y){
    if (auedb == 0) authors = aued;
    if (auedb == 1) editors = aued;
    vector<string> tv;
    tv.push_back(t);
    title = tv;
    publisher = p;
    year = y;
}

// convenience function: constructor with only one author/editor
Book::Book(Person aued, int auedb, vector<string> t, Publisher p, int y){
    vector<Person> pv;
    pv.push_back(aued);
    if (auedb == 0) authors = pv;
    if (auedb == 1) editors = pv;
    title = t;
    publisher = p;
    year = y;
}

// convenience function: constructor with only one author/editor and only one version of the title
Book::Book(Person aued, int auedb, string t, Publisher p, int y){
    vector<Person> pv;
    pv.push_back(aued);
    if (auedb == 0) authors = pv;
    if (auedb == 1) editors = pv;
    vector<string> tv;
    tv.push_back(t);
    title = tv;
    publisher = p;
    year = y;
}

// functions to add optional fields:  volume or number, series, address, edition, month, note, isbn
void Book::addVolume(int v){
    volume = v;
}

void Book::addNumber(int n){
    number = n;
}

void Book::addSeries(string s){
    series = s;
}

void Book::addAddress(string a){
    address = a;
}

void Book::addEdition(int e){
    edition = e;
}

void Book::addMonth(int m){
    if (m >= 1 && m <= 12) month = m;
}

void Book::addNote(string n){
    note = n;
}

// TODO: check if this is a correct isbn
void Book::addISBN(string s){
    isbn = s;
}

string Book::generateLatexKey(){} // TODO: implement

string Book::generateBibTex(){
    if (LatexKey.empty()) LatexKey = generateLatexKey();
    string bibtex = "@BOOK{";
    bibtex.append(LatexKey);
    bibtex.append(",\n");
    //necessary fields: author oder editor, title, publisher, year
    string s = "";
    if (!authors.empty()){ 
        s = "AUTHOR = {";
        for (int i = 0, max = authors.size(); i < max; i++){
            s.append(authors[i].spellings[0]);
            if (i != (max-1)){
                s.append(" AND ");
            } else {
                s.append("},\n");
            }
        }
    } else {
        if (!editors.empty()){
            s = "EDITOR = {";
             for (int i = 0, max = editors.size(); i < max; i++){
                s.append(editors[i].spellings[0]);
                if (i != (max-1)){ 
                    s.append(" AND ");
                } else {
                    s.append("},\n");
                }
            }
        } else { 
            cerr << "The fields author and editor cannot both be empty!" << endl;
            return NULL;
        }
    }
    bibtex.append(s);
    
    bibtex.append("TITLE = {");
    bibtex.append(title[0]);
    bibtex.append("},\n");
    
    bibtex.append("PUBLISHER = {");
    bibtex.append(publisher.name);
    bibtex.append("},\n");
    
    bibtex.append("YEAR = ");
    bibtex.append(to_string(year));
    bibtex.append("}");
    
    // optional fields: volume or number, series, address, edition, month, note, isbn
    if (volume != 0){
        bibtex.append(",\n");
        bibtex.append("VOLUME = {");
        bibtex.append(to_string(volume));
        bibtex.append("}");
    } else {
        if (number != 0){
            bibtex.append(",\n");
            bibtex.append("NUMBER = {");
            bibtex.append(to_string(number));
            bibtex.append("}");
        }
    }
    if (!series.empty()){
        bibtex.append(",\n");
        bibtex.append("SERIES = {");
        bibtex.append(series);
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
    if (!note.empty()){
        bibtex.append(",\n");
        bibtex.append("NOTE = {");
        bibtex.append(note);
        bibtex.append("}");
    }
    if (!isbn.empty()){
        bibtex.append(",\n");
        bibtex.append("ISBN = {");
        bibtex.append(isbn);
        bibtex.append("}");
    }
    return bibtex;
}
