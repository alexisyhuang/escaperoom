#include <string>
using namespace std;
#ifndef structure_h
#define structure_h

struct myitem{// can add more if you wish
    //string catagory;//constant
    string identity;// constant
    //int exist;//whether it exist/still exist in this game
    int getable; //0or1 depends on object property, and presence of obstacles //1=recall main
    int knowExistence;//initially setted to 0, becomes 1 when user sees it
    //if getable && knowexistance --> can be picked up
    int inPossession;//in inventory = 1, not in= 0
    string location;
};
#endif
