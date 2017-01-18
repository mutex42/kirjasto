#include "media/Journal.h"
#include "media/Person.h"
#include "media/Article.h"

using namespace std;

int main(int argc, char* argv[])
{
    Journal j = Journal("Journal McJournface");
    Person a = Person("McWriteface, Writer");
    Article m =  Article(a, "test", j, 2015);
    return 0;
}
