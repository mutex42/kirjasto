#ifndef JOURNAL_H
#define JOURNAL_H

#include <string>

using namespace std;

class Journal
{
public:
    Journal(string);
    ~Journal();
    Journal();
    int uid;
    string name;
private:
};

#endif // JOURNAL_H
