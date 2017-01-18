#ifndef PUBLICATION_H
#define PUBLICATION_H

#include "Medium.h"
#include "Person.h"
#include "Publisher.h"
#include "Organization.h"

using namespace std;

class Publication : protected Medium
{
public:
    void addLatexKey(string);
    virtual string generateLatexKey();
    virtual string generateBibTex();
protected:
    Publication();
    ~Publication();
    string LatexKey;
};

#endif // PUBLICATION_H
