#include "Inbook.h"

Inbook::Inbook(){}

Inbook::~Inbook(){}

Inbook::Inbook(vector<Person> p, int ae, string t, string bt, int chap, pair<int,int> pg, Publisher pub, int y){
    if (ae == 0) authors = p;
    if (ae == 1) editors = p;
    title = t;
    booktitle = bt;
    chapter = chap;
    pages = pg;
    publisher = pub;
    year = y;
}

Inbook::Inbook(Person p, int ae, string t, string bt, int chap, pair<int,int> pg, Publisher pub, int y){
    if (ae == 0) authors.push_back(p);
    if (ae == 1) editors.push_back(p);
    title = t;
    booktitle = bt;
    chapter = chap;
    pages = pg;
    publisher = pub;
    year = y;
}

Inbook::Inbook(vector<Person> p, int ae,string t, string bt, pair<int,int> pg, Publisher pub,int y){
    if (ae == 0) authors = p;
    if (ae == 1) editors = p;
    title = t;
    booktitle = bt;
    pages = pg;
    publisher = pub;
    year = y;
}

Inbook::Inbook(Person p,int ae,string t, string bt,pair<int,int> pg, Publisher pub, int y){
    if (ae == 0) authors.push_back(p);
    if (ae == 1) editors.push_back(p);    
    booktitle = bt;
    pages = pg;
    publisher = pub;
    year = y;
}

Inbook::Inbook(vector<Person> p,int ae, string t, string bt, int chap ,Publisher pub,int y){
    if (ae == 0) authors = p;
    if (ae == 1) editors = p;   
    title = t;
    booktitle = bt;
    chapter = chap;
    publisher = pub;
    year = y;
}

Inbook::Inbook(Person p, int ae, string t, string bt, int chap, Publisher pub, int y){
    if (ae == 0) authors.push_back(p);
    if (ae == 1) editors.push_back(p);    
    title = t;
    booktitle = bt;
    chapter = chap;
    publisher = pub;
    year = y;
}

void Inbook::addVolume(int v){
    volume = v;
}

void Inbook::addNumber(int n){
    number = n;
}

void Inbook::addSeries(string s){
    series = s;
}

void Inbook::addType(string t){
    typ = t;
}

void Inbook::addEdition(int e){
    edition = e;
}

void Inbook::addMonth(int m){
    if (m >= 1 && m <= 12) { month = m; }
}

void Inbook::addNote(string n){
    note = n;
}

string Inbook::generateLatexKey(){} // TODO: implement

string Inbook::generateBibTex(){
    string bibtex = "INBOOK{";
    if (LatexKey.empty()) { LatexKey = generateLatexKey(); }
    bibtex.append(LatexKey);
    bibtex.append(",\n");
    // necessary fields: author or editor, title, booktitle, chapter and/or pages, publisher, year
    if (authors.empty() && editors.empty()){
        cerr << "author and editor cannot both be empty!" << endl;
        return NULL;
    }
    if (!(authors.empty()) && !(editors.empty())){
        cerr << "Inbook can only have either an author or an editor!" << endl;
        return NULL;
    }
    if (editors.empty() && !(authors.empty())){
        bibtex.append("AUTHOR = {");
        for (int i = 0, max = authors.size(); i < max; i++){
            bibtex.append(authors[i].spellings[0]);
            if (i != (max - 1)) { bibtex.append(" AND "); }
        }
        bibtex.append("},\n");
    }
    if (authors.empty() && !(editors.empty())){
        bibtex.append("EDITOR = {");
        for (int i = 0, max = editors.size(); i < max; i++){
            bibtex.append(editors[i].spellings[0]);
            if (i != (max - 1)) { bibtex.append(" AND "); }
        }
        bibtex.append("},\n");
    }
    bibtex.append("TITLE = {");
    bibtex.append(title);
    bibtex.append("},\n");
    bibtex.append("BOOKTITLE = {");
    bibtex.append(booktitle);
    bibtex.append("},\n");
    if (chapter == 0 && (pages.first == 0 && pages.second == 0)){
        cerr << "Inbook must have a chapter or pages!" << endl;
        return NULL;
    }
    if (chapter != 0){
        bibtex.append("CHAPTER = {");
        bibtex.append(to_string(chapter));
        bibtex.append("},\n");
    }
    if (pages.first != 0 || pages.second != 0){
        bibtex.append("PAGES = {");
        bibtex.append(to_string(pages.first));
        bibtex.append(" -- ");
        bibtex.append(to_string(pages.second));
        bibtex.append("},\n");
    }
    bibtex.append("PUBLISHER = {");
    bibtex.append(publisher.name);
    bibtex.append("},\n");
    bibtex.append("YEAR = {");
    bibtex.append(to_string(year));
    bibtex.append("}");
    
    // optional fields: volume or number, series, type, address, edition, month, note
    if (!(volume == 0 && number == 0)){
        cerr << "Inbook cannot have both volume and number!" << endl;
        return NULL;
    }
    if (volume != 0){
        bibtex.append(",\n");
        bibtex.append("VOLUME = {");
        bibtex.append(to_string(volume));
        bibtex.append("}");
    }
    if (number != 0){
        bibtex.append(",\n");
        bibtex.append("NUMBER = {");
        bibtex.append(to_string(number));
        bibtex.append("}");
    }
    if (!series.empty()){
        bibtex.append(",\n");
        bibtex.append("SERIES = {");
        bibtex.append(series);
        bibtex.append("}");
    }
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
    return bibtex;
}
