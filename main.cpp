#include "randgame.h"
#include <iostream>
using namespace std;
int main(){//I DID THE DATA STRUCTURE PART SO THERES STH TO REFERENCE ON WHEN WORKING WITH THE CHATBOT.  ~dawn
  struct myitem{// can add more if you wish
    string identity;
    string subtype;
    int getable; // 1
  	int inPossession;
    string location;
  };
  int main(){
    int all_items_length = 2;
    myitem all_items[10]={
      {"key","silver key", 1, 0, "cat"},
      {"food","cake",1,0,"table"}
    };
    for(int i=0; i < all_items_length; i++){
      cout<< "identity: "<< all_items[i].identity<<endl
      <<"subtype: "<<all_items[i].subtype<<endl
      <<"getable: "<< all_items[i].getable<<endl
      <<"inPossession: "<< all_items[i].inPossession<< endl
      <<"location: "<< all_items[i].location<<endl<<endl;
    }
  }

  /**old obsolete scripts see if it's useful or not. if not, just delete it
  string room[6][2][5] = {};
  // 6 possible locations: door, table, floor, shelf, wall, ceiling
  // each location has 2 "attribute": what other items it contains, other attribute
  // attribute: important? (only important ones are mentioned in the )
  // 5 is for the items a location contains
  string items[5][7]={};
  // possible items: door, chest, animal, food, key,
  // attribute: identity, adj(wooden/steel; cat/dog), exist?, visible?, getable?, usable?, location,
  randgame(room, items,1);
  **/

}
