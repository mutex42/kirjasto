#include "Incollecion.h"

Incollecion::Incollecion(){}

Incollecion::~Incollecion(){}

Incollecion::Incollecion(vector<Person> a, string t, string bt, Publisher pub, int y){
    authors = a;
    title = t;
    booktitle = bt;
    publisher = pub;
    year = y;
}

Incollecion::Incollecion(Person a, string t, string bt, Publisher pub, int y){
    authors.push_back(a);
    title = t;
    booktitle = bt;
    publisher = pub;
    year = y;
}

void Incollecion::addAuthor(Person a){
    authors.push_back(a);
}

void Incollecion::addEditor(Person e){
    editors.push_back(e);
}

void Incollecion::addEditors(vector<Person> e){
    for (int i = 0, max = e.size(); i < max; i++){
        editors.push_back(e[i]);
    }
}

void Incollecion::addVolume(int v){
    volume = v;
}

void Incollecion::addNumber(int n){
    number = n;
}

void Incollecion::addSeries(string s){
    series = s;
}

void Incollecion::addType(string t){
    typ = t;
}

void Incollecion::addChapter(int chap){
    chapter = chap;
}

void Incollecion::addPages(int first, int second){
    pages = make_pair(first, second);
}

void Incollecion::addPages(pair<int, int> pg){
    pages = pg;
}

void Incollecion::addAddress(string a){
    address = a;
}

void Incollecion::addEdition(int e){
    edition = e;
}

void Incollecion::addMonth(int m){
    if (m >= 1 && m <= 12) { month = m; }
}

void Incollecion::addNote(string n){
    note = n;
}

string Incollecion::generateLatexKey(){} // TODO: implement

string Incollecion::generateBibTex(){
    string bibtex = "INCOLLECTION{";
    if (LatexKey.empty()) { LatexKey = generateLatexKey(); }
    bibtex.append(LatexKey);
    bibtex.append(",\n");

    // necessary fields: author, title, booktitle, publisher, year
    for (int i = 0, max = authors.size(); i < max; i++){
        bibtex.append(authors[i].spellings[0]);
        if (i != (max - 1)) { bibtex.append(" AND"); }
    }
    bibtex.append("},\n");
    bibtex.append("TITLE = {");
    bibtex.append(title);
    bibtex.append("},\n");
    bibtex.append("BOOKTITLE = {");
    bibtex.append(booktitle);
    bibtex.append("},\n");
    bibtex.append("PUBLISHER = {");
    bibtex.append(publisher.name);
    bibtex.append("},\n");
    bibtex.append("YEAR = {");
    bibtex.append(to_string(year));
    bibtex.append("}");
    
    // optional fields: editor, volume or number, series, type, chapter, pages, address, edition, month, note
    if (!editors.empty()){
        bibtex.append(",\n");
        bibtex.append("EDITOR = {");
        for (int i = 0, max = editors.size(); i < max; i++){
            bibtex.append(editors[i].spellings[0]);
            if (i != (max - 1)) { bibtex.append(" AND "); }
        }
        bibtex.append("}");
    }
    if (volume != 0 && number != 0){
        cerr << "Incollection can only have either a volume or a number!" << endl;
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
    if (chapter != 0){
        bibtex.append(",\n");
        bibtex.append("CHAPTER = {");
        bibtex.append(to_string(chapter));
        bibtex.append("}");
    }
    if (pages.first != 0 || pages.second != 0){
        bibtex.append("PAGES = {");
        bibtex.append(to_string(pages.first));
        bibtex.append(" -- ");
        bibtex.append(to_string(pages.second));
        bibtex.append("},\n");
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


