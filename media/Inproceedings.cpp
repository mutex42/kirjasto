#include "Inproceedings.h"

Inproceedings::Inproceedings(){}

Inproceedings::~Inproceedings(){}

Inproceedings::Inproceedings(vector<Person> a, string t, string bt, int y){
    authors = a;
    title = t;
    booktitle = bt;
    year = y;
}

Inproceedings::Inproceedings(Person a, string t, string bt, int y){
    authors.push_back(a);
    title = t;
    booktitle = bt;
    year = y;
}

void Inproceedings::addAuthor(Person a){
    authors.push_back(a);
}

void Inproceedings::addAuthors(vector<Person> v){
    for (int i = 0, max = v.size(); i < max; i++){
        authors.push_back(v[i]);
    }
}

void Inproceedings::addEditor(Person e){
    editors.push_back(e);
}

void Inproceedings::addEditors(vector<Person> v){
    for (int i = 0, max = v.size(); i < max; i++){
        editors.push_back(v[i]);
    }
}

void Inproceedings::addVolume(int v){
    volume = v;
}

void Inproceedings::addNumber(int n){
    number = n;
}

void Inproceedings::addSeries(string s){
    series = s;
}

void Inproceedings::addPages(pair<int, int> pg){
    pages = pg;
}

void Inproceedings::addPages(int first, int second){
    pages = make_pair(first, second);
}

void Inproceedings::addAddress(string a){
    address = a;
}

void Inproceedings::addMonth(int m){
    if (m >= 1 && m <= 12) { month = m; }
}

void Inproceedings::addOrganization(Organization o){
    org = o;
}

void Inproceedings::addPublisher(Publisher p){
    publisher = p;
}

void Inproceedings::addNote(string n){
    note = n;
}

string Inproceedings::generateLatexKey(){}

string Inproceedings::generateBibTex(){
    string bibtex = "INPROCEEDINGS{";
    if (LatexKey.empty()) { LatexKey = generateLatexKey(); }
    bibtex.append(LatexKey);
    bibtex.append(",\n");
    
    // necessary fields: author, title, booktitle, year
    bibtex.append("AUTHOR = {");
    for (int i = 0, max = authors.size(); i < max; i++){
        bibtex.append(authors[i].spellings[0]);
        if (i != (max - 1)) { bibtex.append(" AND "); }
    }
    bibtex.append("},\n");
    bibtex.append("TITLE = {");
    bibtex.append(title);
    bibtex.append("},\n");
    bibtex.append("BOOKTITLE = {");
    bibtex.append(booktitle);
    bibtex.append("},\n");
    bibtex.append("YEAR = {");
    bibtex.append(to_string(year));
    bibtex.append("}");
    
    // optional fields: editor, volume or number, series, pages, address, month, organization, publisher, note
    if (!editors.empty()){
        bibtex.append("EDITOR = {");
        for (int i = 0, max = editors.size(); i < max; i++){
            bibtex.append(editors[i].spellings[0]);
            if (i != (max - 1)) { bibtex.append(" AND "); }
        }
        bibtex.append("}");
    }
    if (!(volume == 0 && number == 0)){
        cerr << "Inproceedings cannot have both volume and number!" << endl;
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