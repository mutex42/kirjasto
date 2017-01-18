#include "Conference.h"

Conference::Conference(){}

Conference::~Conference(){}

Conference::Conference(vector<Person> a, string t, string bt, int y){
    authors = a;
    title = t;
    booktitle = bt;
    year = y;
}

// convenience function: constructor with only one author
Conference::Conference(Person a, string t, string bt, int y){
    authors.push_back(a);
    title = t;
    booktitle = bt;
    year = y;
}

void Conference::addAuthor(Person p){
    authors.push_back(p);
}

void Conference::addEditor(Person p){
    editor.push_back(p);
}

void Conference::addEditors(vector<Person> vp){
    for (int i = 0, max = vp.size(); i < max; i++){
        editor.push_back(vp[i]);
    }
}

void Conference::addVolume(int v){
    volume = v;
}

void Conference::addNumber(int n){
    number = n;
}

void Conference::addSeries(string s){
    series = s;
}

void Conference::addPages(int first,int second){
    pages = make_pair(first, second);
}

void Conference::addPages(pair<int,int> p){
    pages = p;
}

void Conference::addAddress(string a){
    address = a;
}

void Conference::addMonth(int m){
    if (m >= 1 && m <= 12) { month = m; }
}

void Conference::addOrg(Organization o){
    org = o;
}

void Conference::addPublisher(Publisher p){
    publisher = p;
}

void Conference::addNote(string n){
    note = n;
}

// TODO: implement
string Conference::generateLatexKey(){}

string Conference::generateBibTex(){
    if (LatexKey.empty()) LatexKey = generateLatexKey();
    string bibtex = "CONFERENCE{";
    bibtex.append(LatexKey);
    bibtex.append(",\n");
    // necessary fields: author, title, booktitle, year
    string aut = "AUTHOR = {";
    for (int i = 0, max = authors.size(); i < max; i++){
        aut.append(authors[i].spellings[0]);
        if (i != (max - 1)) { aut.append(" AND "); }
    }
    aut.append("},\n");
    bibtex.append(aut);
    bibtex.append("TITLE = {");
    bibtex.append(title);
    bibtex.append("},\n");
    bibtex.append("BOOKTITLE =  {");
    bibtex.append(booktitle);
    bibtex.append("},\n");
    bibtex.append("YEAR = {");
    bibtex.append(to_string(year));
    bibtex.append("}");

    // optional fields: editor, volume or number, series, pages, address, month, organization, publisher, note
    if (!editor.empty()){
        bibtex.append(",\n");
        string ed = "EDITOR = {";
        for (int i = 0, max = editor.size(); i < max; i++){
            ed.append(editor[i].spellings[0]);
            if (i != (max - 1)) { ed.append(" AND "); }
        }
        ed.append("},\n");
        bibtex.append(ed);
    }
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
    if (!(pages.first == 0 && pages.second == 0)){
        bibtex.append(",\n");
        bibtex.append("PAGES = {");
        bibtex.append(to_string(pages.first));
        bibtex.append(" -- ");
        bibtex.append(to_string(pages.second));
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
    if (!org.name.empty()){
        bibtex.append(",\n");
        bibtex.append("ORGANIZATION = {");
        bibtex.append(org.name);
        bibtex.append("}");
    }
    if (!publisher.name.empty()){
        bibtex.append(",\n");
        bibtex.append("PUBLISHER = {");
        bibtex.append(publisher.name);
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