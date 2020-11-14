//for testing chatbot.cpp only
#include "structure.h"
#include "chatbot.h"

using namespace std;

int main(){
/**
string identity;// constant
string subtype;//constant
int exist;//whether it exist/still exist in this game
int getable; //0or1 depends on object property, and presence of obstacles
int knowexistance;//initially setted to 0, becomes 1 when user sees it
//if getable && knowexistance --> can be picked up
int inPossession;//in inventory = 1, not in= 0
string location;**/
  int all_items_length = 4;
  myitem all_items[10]={
    {"table","table",1,0,0,0,"room"},
    {"fish","fish",1,1,0,0,"table"},
    {"cat","cat",1,0,0,0,"room"},
    {"key","silver key", 1,0,0,0, "cat"},

  };
  printallitem(all_items_length,all_items);
  while (chatbot(all_items,all_items_length));//ADD THIS LINE TO THE REAL MAIN FUNCTION
}
