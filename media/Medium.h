#ifndef MEDIUM_H
#define MEDIUM_H

#include <string>
#include <vector>
#include <stdio.h>
#include <iostream>

using namespace std;

class Medium
{
public:
	int uid;
    vector<pair<string,string> > links;
    void addLink(string, string);
	virtual string generateInsertStatement();
protected:
    Medium();
    ~Medium();
};

#endif // MEDIUM_H
