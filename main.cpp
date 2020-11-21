#include "structure.h"
#include <iostream>
#include <time.h>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "chatbot.h"

using namespace std;

void savegame(int all_items_length, myitem all_items[10]){
  /*
  savegame function: saves the current game status into a file called savefile.txt
  inputs: array of myitems all_items, and the length of the array all_items
  output: savefile.txt is created or updated with the current status of the objects in the game
  */
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
    int all_items_length = 10;
    //string possibleItems[3][2] = {{"steel", "wooden"}, {"cat", "dog"}, {"painting", "poster"}};
    string possibleItems[3][2] = {{"cat", "dog"}, {"painting", "poster"},{"table", "shelf"}};

    cout << "Do you want to load a previous save file? [Y/N]" << endl << ">>> ";
    string saveYesNo;
    getline(cin, saveYesNo);
    bool savefile = false;
    if ((saveYesNo == "Y")||(saveYesNo == "yes")) {
        savefile = true;
    }
    if (savefile == false) {
      //initialise room by creating objects, some of which have randomized properties. Every time that you run the file, you may be in a room with different objects.

      cout<<"Please input integer seed(type -1 to use random seed): ";
      int seed;
      string seed_string;
      getline(cin,seed_string);
      stringstream seed_stream(seed_string);
      seed_stream>>seed;//not directly using cin>> seed to avoid an EOL at the beginning of the file
      if (seed == -1){
        seed = time(NULL);
      }
      srand(seed);
      int num1 = rand() % 2;
      int num2 = rand() % 2;
      int num3 = rand() % 2;

      struct myitem animal;
      animal.identity = possibleItems[0][num1];
      animal.getable = 0;
      animal.inPossession = 0;
      animal.location = "floor";
      animal.knowExistence = 0;

      struct myitem life;
      life.identity = "life";
      life.getable = 0;//die
      life.inPossession = 0;
      life.location = to_string(rand() % 10000);//passcode
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
      key.location = animal.identity;
      key.knowExistence = 0;

      struct myitem chest;
      chest.identity = "chest";
      chest.getable = 0;
      chest.inPossession = 0;
      chest.location = "floor";
      chest.knowExistence = 0;

      struct myitem furniture;
      furniture.identity = possibleItems[2][num3];
      furniture.getable = 0;
      furniture.inPossession = 0;
      furniture.location = "floor";
      furniture.knowExistence = 0;

      struct myitem paper;
      paper.identity = "paper";
      paper.getable = 1;
      paper.inPossession = 0;
      paper.location = "chest";
      paper.knowExistence = 0;
      //specialItem and usedItem are dependent on each other and exist in a pair
      struct myitem specialItem;
      struct myitem usedItem;
      if (animal.identity == "cat") {
          specialItem.identity = "aquarium";
          specialItem.getable = 1;
          specialItem.inPossession = 0;
          specialItem.location = furniture.identity;
          specialItem.knowExistence = 0;
          usedItem.identity = "fish";
          usedItem.getable = 1;
          usedItem.inPossession = 0;
          usedItem.location = "aquarium";
          usedItem.knowExistence = 0;

        } else {
          usedItem.identity = "bone";
          usedItem.getable = 1;
          usedItem.inPossession = 0;
          usedItem.location = "turkey";
          usedItem.knowExistence = 0;
          specialItem.identity = "turkey";
          specialItem.getable = 1;
          specialItem.inPossession = 0;
          specialItem.location = furniture.identity;
          specialItem.knowExistence = 0;

        }
	//populate the array all_items with the objects we just created
        all_items[0] = life;
        all_items[1] = door;
        all_items[2] = animal;
        all_items[3] = specialItem;
        all_items[4] = usedItem;
        all_items[5] = useless;
        all_items[6] = chest;
        all_items[7] = key;
        all_items[8] = furniture;
        all_items[9] = paper;

    } else {
	//read from savefile.txt
        string holderString;
        vector<std::string> words;
        ifstream myfile ("savefile.txt");
	//check if the file is able to be opened
        if (myfile.is_open()){
            while (myfile >> holderString) {
                words.push_back(holderString);
            }
            myfile.close();
        } else {
            cout << "Unable to open file" << endl;
            return 0;
        }
	//populate array all_items with items with the properties as dictated by the savefile
        string name;
        int vectorcount=0;
        for(int i = 0; i < all_items_length; i ++){
            name = words[vectorcount];
            struct myitem name;
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
    //brief introduction for the user
    cout << "Let the story begin..." << endl;
    cout << "You awaken in a small room, your last memory having been peacefully snuggling into bed after a long night of working on your programming assignment." << endl;
    cout << "You've got to escape from this room ASAP, or you can't submit your assignment on time!"<<endl;
    cout << "Examine and interact with the objects in the room to make your escape!" << endl;
    cout<< "Tips: phrase your sentences as follow"<<endl
      <<"<verb>(eg. quit, save)"<<endl
      <<"<verb> <object>"<< endl
      << "Incomplete list of possible actions: look, inspect, examine, get, eat, kick..."<<endl;

    //call chatbot.cpp
    while(chatbot(all_items, all_items_length));
}
