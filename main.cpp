//#include "randgame.h"
#include <iostream>
#include <time.h>
#include "chatbot.cpp"
using namespace std;

struct myitem{// can add more if you wish
    string identity;
    string subtype;
    int getable; // 1
  	int inPossession;
    string location;
};

int main(){
    myitem all_items[10];
    int all_items_length = 4;
    string possibleItems[2][2] = {{"steel", "wooden"}, {"cat", "dog"}};
    bool savefile = false;
    if (savefile == false) {
      //initialise room
      srand(time(NULL));
      int num1 = rand() % 2;
      int num2 = rand() % 2;
      struct myitem animal;
      animal.identity = possibleItems[1][num1];
      animal.getable = 0;
      animal.inPossession = 0;
      animal.location = "floor";
      
      struct myitem door;
      door.identity = possibleItems[0][num2];
      door.getable = 0;
      door.inPossession = 0;
      door.location = "on the wall";
        
      struct myitem specialItem;
      struct myitem usedItem;
      if (animal.identity == "cat") {
          specialItem.identity = "fishtank";
          specialItem.getable = 1;
          specialItem.inPossession = 0;
          specialItem.location = "table";
          usedItem.identity = "fish";
          specialItem.getable = 1;
          specialItem.inPossession = 0;
          specialItem.location = "fishtank";
        } else {
          specialItem.identity = "turkey leg";
          specialItem.getable = 1;
          specialItem.inPossession = 0;
          specialItem.location = "table";
          usedItem.identity = "turkey bone";
          usedItem.getable = 1;
          usedItem.inPossession = 0;
          usedItem.location = "turkey leg";
        }
        all_items[0] = door;
        all_items[1] = animal;
        all_items[2] = specialItem;
        all_items[3] = usedItem;
    } else {
        cout << "figure this out " << endl;
    }
    //story segment
    cout << i;
    cout << all_items[0].identity << endl;
    cout << all_items[1].identity << endl;
    cout << "Let the story begin..." << endl;
    cout << "You awaken in a small room, your last memory having been peacefully snuggling into bed after a long night of working on your programming assignment." << endl;
    cout << "A quick glance across the room reveals a " << all_items[0].identity << " door." << endl;
    if (all_items[0].identity == "wooden") {
        cout << "It looks weak enough that you might be able to kick it down, if you try hard enough..." << endl;
    } else {
        cout << "It looks pretty strong, but maybe you could kick it down if you tried hard enough." << endl;
    }
    cout << "Luckily, there's a number pad on the door which you could use to make your escape. You need to get home soon to submit that programming assignment, after all." << endl;
    cout << "You see a table across the room, and there's also a " << all_items[1].identity << " staring at you judgingly as it sits by a large treasure chest." << endl;
    cout << "Examine and interact with the objects in the room to make your escape!" << endl;
    
    //call chatbot.cpp
    chatbot(all_items, all_items_length);
    
    //I DID THE DATA STRUCTURE PART SO THERES STH TO REFERENCE ON WHEN WORKING WITH THE CHATBOT.  ~dawn
    
    /*
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
  }*/

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
