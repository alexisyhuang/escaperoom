//#include "randgame.h"
#include <iostream>
#include <time.h>
#include <fstream>
#include <vector>
#include "structure.h"
#include "chatbot.h"
using namespace std;
/**
struct myitem{
    string identity;
    //string subtype;
    //no need for subtype anymore because this is indicated by the position in the array?
    int getable; // 1 = yes, 0 = no
  	int inPossession; // 1 = yes, 0 = no
    string location;
};**/

void savegame(int all_items_length, myitem all_items[10]){
  cout << "saving game..." << endl;
  ofstream myfile;
  myfile.open("savefile.txt");
  if (myfile.is_open()){
    for(int i = 0; i < all_items_length; i ++){
        myfile << all_items[i].identity << ' ' << all_items[i].catagory << ' ' << all_items[i].getable << ' ' << all_items[i].inPossession << ' ' << all_items[i].location << ' ' << all_items[i].knowExistence << ' ';
    }
    myfile.close();
  } else {
  	cout << "Unable to open file." << endl;
  }
  cout<<"game saved."<<endl;
}

int main(){
    myitem all_items[10];
    int all_items_length = 7;
    string possibleItems[3][2] = {{"steel", "wooden"}, {"cat", "dog"}, {"painting", "poster"}};

    cout << "Do you want to load a previous save file? Type Y for yes or N for no." << endl;
    string saveYesNo;
    cin >> saveYesNo;
    bool savefile = false;
    if (saveYesNo == "Y") {
        savefile = true;
    }
    if (savefile == false) {
      //initialise room
      //srand(time(NULL));
      int randSeed = 5;
      srand(randSeed);
      int num1 = rand() % 2;
      int num2 = rand() % 2;
      int num3 = rand() % 2;
      struct myitem animal;
      animal.catagory = "animal";
      animal.identity = possibleItems[1][num1];
      animal.getable = 0;
      animal.inPossession = 0;
      animal.location = "floor";
      animal.knowExistence = 0;

      struct myitem door;
      door.catagory = "door";
      door.identity = possibleItems[0][num2];
      door.getable = 1;
      door.inPossession = 0;
      door.location = "room";
      door.knowExistence = 0;

      struct myitem useless;
      useless.catagory = "decoration";
      useless.identity = possibleItems[2][num3];
      useless.getable = 1;
      useless.inPossession = 0;
      useless.location = "wall";
      useless.knowExistence = 0;

      struct myitem key;
      key.catagory = "key";
      key.identity = "key";
      key.getable = 1;
      key.inPossession = 0;
      key.location = animal.identity;
      key.knowExistence = 0;

      struct myitem chest;
      chest.catagory = "chest";
      chest.identity = "chest";
      chest.getable = 0;
      chest.inPossession = 0;
      chest.location = "floor";
      chest.knowExistence = 0;

      struct myitem table;
      table.catagory = "table";
      table.identity = "table";
      table.getable = 0;
      table.inPossession = 0;
      table.location = "floor";
      table.knowExistence = 0;

      struct myitem specialItem;
      struct myitem usedItem;
      if (animal.identity == "cat") {
          specialItem.identity = "fishtank";
          specialItem.getable = 1;
          specialItem.inPossession = 0;
          specialItem.location = "table";
	  specialItem.knowExistence = 0;
          usedItem.identity = "fish";
          usedItem.getable = 1;
          usedItem.inPossession = 0;
          usedItem.location = "fishtank";
	  usedItem.knowExistence = 0;
        } else {
          specialItem.identity = "turkeyleg";
          specialItem.getable = 1;
          specialItem.inPossession = 0;
          specialItem.location = "table";
	  specialItem.knowExistence = 0;
          usedItem.identity = "turkeybone";
          usedItem.getable = 1;
          usedItem.inPossession = 0;
          usedItem.location = "turkeyleg";
	  usedItem.knowExistence = 0;
        }
        all_items[0] = door;
        all_items[1] = animal;
        all_items[2] = specialItem;
        all_items[3] = usedItem;
        all_items[4] = useless;
        all_items[5] = chest;
        all_items[6] = key;
	all_items[7] = table;
    } else {
        string holderString;
        vector<std::string> words;
        ifstream myfile ("savefile.txt");
        if (myfile.is_open()){
            while (myfile >> holderString) {
                words.push_back(holderString);
            }
            myfile.close();
        } else {
            cout << "Unable to open file" << endl;
            return 0;
        }
        string name;
        string holderStringer2;
        int vectorcount=0;
        for(int i = 0; i < all_items_length; i ++){
            name = words[vectorcount];
            struct myitem name;
            //vectorcount++;
            name.identity = words[vectorcount];
            vectorcount++;
	    name.catagory = words[vectorcount];
	    vectorcount++;
            if (words[vectorcount] == "0") {
                name.getable = 0;
            } else {
                name.getable = 1;
            }
            vectorcount++;
            if (words[vectorcount] == "0") {
                name.inPossession = 0;
            } else {
                name.inPossession = 1;
            }
            vectorcount++;
            name.location = words[vectorcount];
            vectorcount++;
	    name.knowExistence = stoi(words[vectorcount]);
            vectorcount++;
	    all_items[i] = name;
        }
    }
    //story segment
    //cout << i;
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
    cout<< "On the wall, there's a " << all_items[4].identity << ". Maybe that could be useful?" << endl;
    cout << "Examine and interact with the objects in the room to make your escape!" << endl;


    //savegame(all_items_length, all_items);
    //call chatbot.cpp


    while(chatbot(all_items, all_items_length));
}
