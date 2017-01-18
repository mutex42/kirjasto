#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <vector>

using namespace std;

class Person
{
public:
    Person(string spelling);
    ~Person();
    void addSpelling(string);
    int uid;
    vector<string> spellings;    
private:
    Person();
};

#endif // PERSON_H
