#include "structure.h"
#include <iostream>
#include <time.h>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
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
    int knowExistence;
};
**/
void savegame(int all_items_length, myitem all_items[10]){
  cout << "saving game..." << endl;
  ofstream myfile;
  myfile.open("savefile.txt");
  if (myfile.is_open()){
    for(int i = 0; i < all_items_length; i ++){
        myfile << all_items[i].identity << ' ' << all_items[i].getable << ' ' << all_items[i].inPossession << ' ' << all_items[i].location << ' ' << all_items[i].knowExistence << ' ';
    }
    myfile.close();
  } else {
  	cout << "Unable to open file." << endl;
  }
  cout<<"game saved."<<endl;
}

int main(){
    myitem all_items[10];
    int all_items_length = 8;
    //string possibleItems[3][2] = {{"steel", "wooden"}, {"cat", "dog"}, {"painting", "poster"}};
    string possibleItems[3][2] = {{"cat", "dog"}, {"painting", "poster"},{"table", "shelve"}};

    cout << "Do you want to load a previous save file? [Y/N]" << endl
      << ">>> ";
    string saveYesNo;
    getline(cin, saveYesNo);
    bool savefile = false;
    if ((saveYesNo == "Y")||(saveYesNo == "Y")) {
        savefile = true;
    }
    if (savefile == false) {
      //initialise room

      cout<<"Please input integer seed(type -1 to use random seed): ";
      int seed;
      string seed_string;
      getline(cin,seed_string);
      stringstream seed_stream(seed_string);
      seed_stream>>seed;//not directly using cin>> seed because i don't want an extra EOL at the beginning of the file
      if (seed==-1){
        seed = time(NULL);
      }
      srand(seed);
      int num1 = rand() % 2;
      int num2 = rand() % 2;
      int num3 = rand() % 2;
      struct myitem animal;
      animal.identity = possibleItems[0][num1];
      animal.getable = 1;
      animal.inPossession = 0;
      animal.location = "floor";
      animal.knowExistence = 0;

      struct myitem life;
      life.identity = "life";
      life.getable = 0;
      life.inPossession = 0;
      life.location = "none";
      life.knowExistence = 0;

      struct myitem door;
      door.identity = "door";
      door.getable = 0;
      door.inPossession = 0;
      door.location = "wall";
      door.knowExistence = 0;

      struct myitem useless;
      useless.identity = possibleItems[1][num2];
      useless.getable = 0;
      useless.inPossession = 0;
      useless.location = "wall";
      useless.knowExistence = 0;

      struct myitem key;
      key.identity = "key";
      key.getable = 1;
      key.inPossession = 0;
      key.location = "chest";
      key.knowExistence = 0;

      struct myitem chest;
      chest.identity = "chest";
      chest.getable = 1;
      chest.inPossession = 0;
      chest.location = "floor";
      chest.knowExistence = 0;

      struct myitem furniture;
      furniture.identity = possibleItems[1][num3];
      furniture.getable = 0;
      furniture.inPossession = 0;
      furniture.location = "floor";
      furniture.knowExistence = 0;

      struct myitem specialItem;
      struct myitem usedItem;
      if (animal.identity == "cat") {
          specialItem.identity = "tank";
          specialItem.getable = 1;
          specialItem.inPossession = 0;
          specialItem.location = furniture.identity;
          specialItem.knowExistence = 0;
          usedItem.identity = "fish";
          usedItem.getable = 1;
          usedItem.inPossession = 0;
          usedItem.location = "fishtank";
          usedItem.knowExistence = 0;

        } else {
          usedItem.identity = "bone";
          usedItem.getable = 1;
          usedItem.inPossession = 0;
          usedItem.location = furniture.identity;
          usedItem.knowExistence = 0;
          specialItem.identity = "turkey";
          specialItem.getable = 1;
          specialItem.inPossession = 0;
          specialItem.location = *&usedItem.location;
          specialItem.knowExistence = 0;

        }
        all_items[0] = life;
        all_items[1] = door;
        all_items[2] = animal;
        all_items[3] = specialItem;
        all_items[4] = usedItem;
        all_items[5] = useless;
        all_items[6] = chest;
        all_items[7] = key;
        all_items[8] = furniture;
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
            if (words[vectorcount] == "0") {
                name.knowExistence = 0;
            } else {
                name.knowExistence = 1;
            }
            vectorcount++;
	          all_items[i] = name;
        }
    }
    //story segment
    //cout << i;
    //cout << all_items[0].identity << endl;
    //cout << all_items[1].identity << endl;
    cout << "Let the story begin..." << endl;
    cout << "You awaken in a small room, your last memory having been peacefully snuggling into bed after a long night of working on your programming assignment." << endl;
    cout << "A quick glance across the room reveals a door. It looks weak enough that you might be able to kick it down, if you try hard enough..." << endl;
    cout << "Luckily, there's a number pad on the door which you could use to make your escape. You need to get home soon to submit that programming assignment, after all." << endl;
    cout << "You see a table across the room, and there's also a " << all_items[2].identity << " staring at you judgingly as it sits by a large treasure chest." << endl;
    cout<< "On the wall, there's a " << all_items[5].identity << ". Maybe that could be useful?" << endl;
    cout << "Examine and interact with the objects in the room to make your escape!" << endl;

    //savegame(all_items_length, all_items);
    //call chatbot.cpp


    while(chatbot(all_items, all_items_length));


}
