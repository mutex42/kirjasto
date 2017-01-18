#include "Article.h"

Article::Article(){} // empty constructor, this usually shouldn't be called

Article::~Article(){}

// constructor with the necessary fields
Article::Article(vector<Person> a, string t, Journal j, int y){
    authors = a;
    title = t;
    journal = j;
    year = y;
}

// convenience function: constructor with just one author
Article::Article(Person a, string t, Journal j, int y){
    vector<Person> av;
    av.push_back(a);
    authors = av;
    title = t;
    journal = j;
    year = y;
}

// functions to add optional fields: volume, number, pages, month, note

void Article::addVolume(int v){
    volume = v;
}

void Article::addNumber(int n){
    number = n;
}

void Article::addPages(pair<int,int> p){
    pages = p;
}

void Article::addPages(int first, int second){
    pages = make_pair(first, second);
}

void Article::addMonth(int m){
    if (m >= 1 && m <= 12) month = m;
}

void Article::addNote(string s){
    note = s;
}

//TODO: implement
string Article::generateLatexKey(){
    return "";
}

string Article::generateBibTex(){
    if (LatexKey.empty()) { LatexKey = generateLatexKey(); }
    string bibtex = "ARTICLE{";
    bibtex.append(LatexKey);
    bibtex.append(",\n");
    // necessary fields: author, title, journal, year
    string aut = "AUTOR = {";
    for (int i = 0, max = authors.size(); i < max; i++){
        aut.append(authors[i].spellings[0]);
        if (i != (max - 1)) { aut.append(" AND "); }
    }
    aut.append("},\n");
    bibtex.append(aut);
    bibtex.append("TITLE = {");
    bibtex.append(title);
    bibtex.append("},\n");
    bibtex.append("JOURNAL = {");
    bibtex.append(journal.name);
    bibtex.append("},\n");
    bibtex.append("YEAR = {");
    bibtex.append(to_string(year));
    bibtex.append("}");
    // optional fields: volume, number, pages, month, note
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
    if (!(pages.first == 0 && pages.second == 0)){
        bibtex.append(",\n");
        bibtex.append("PAGES = {");
        bibtex.append(to_string(pages.first));
        bibtex.append(" -- ");
        bibtex.append(to_string(pages.second));
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

string Article::generateInsertStatement(){
	string sql = "INSERT INTO TABLE ARTICLES VALUES (";
	string null = "NULL";
	sql.append(to_string(this->uid));
	sql.append(",");
	sql.append(this->title);
	sql.append(",");
	sql.append(to_string(this->year));
	sql.append(",");
	if (this->volume != 0) sql.append(to_string(this->volume));
	else sql.append(null);
	sql.append(",");
	if (this->number != 0) sql.append(to_string(this->number));
	else sql.append(null);
	sql.append(",");
	if (this->pages.first != 0 || this->pages.second != 0){
		sql.append(to_string(this->pages.first));
		sql.append(",");
		sql.append(to_string(this->pages.second));
	} else sql.append("NULL,NULL");
	sql.append(",");
	if (this->month >= 1 && this->month <= 12) sql.append(to_string(this->month));
	else sql.append(null);
	sql.append(",");
	if (!this->note.empty()) sql.append(note);
	else sql.append(null);
	sql.append(");\n");
	sql.append("\n");
	
	
	
	return sql;
}
