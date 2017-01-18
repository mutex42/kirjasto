#include "Proceedings.h"

Proceedings::Proceedings(){}

Proceedings::~Proceedings(){}

Proceedings::Proceedings(string t, int y){
    title = t;
    year = y;
}

void Proceedings::addEditor(Person p){
    editors.push_back(p);
}

void Proceedings::addEditors(vector<Person> p){
    for (int i = 0, max = p.size(); i < max; i++){
        editors.push_back(p[i]);
    }
}

void Proceedings::addVolume(int v){
    volume = v;
}

void Proceedings::addNumber(int n){
    number = n;
}

void Proceedings::addSeries(string s){
    series = s;
}

void Proceedings::addAddress(string a){
    address = a;
}

void Proceedings::addMonth(int m){
    month = m;
}

void Proceedings::addOrganization(Organization o){
    org = o;
}

void Proceedings::addPublisher(Publisher p){
    publisher = p;
}

void Proceedings::addNote(string n){
    note = n;
}

string Proceedings::generateLatexKey(){}

string Proceedings::generateBibTex(){
    if (LatexKey.empty()) LatexKey = generateLatexKey();
    string bibtex = "PROCEEDINGS{";
    bibtex.append(LatexKey);
    bibtex.append(",\n");
    
    // necessary fields: title, year
    bibtex.append("TITLE = {");
    bibtex.append(title);
    bibtex.append("},\n");
    bibtex.append("YEAR = {");
    bibtex.append(to_string(year));
    bibtex.append("}");
    
    // optional fields: editor, volume or number, series, address, month, organization, publisher, note
   if (!editors.empty()){
        bibtex.append(",\n");
        bibtex.append("EDITOR = {");
        for (int i = 0, max = editors.size(); i < max; i++){
            bibtex.append(editors[i].spellings[0]);
            if (i != (max - 1)) { bibtex.append(" AND "); }
        }
        bibtex.append("},\n");
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