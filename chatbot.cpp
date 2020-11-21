//STAND ALONE CHATBOT.cpp
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <cstdlib>
#include "structure.h"
#include "chatbot.h"
//#include "main.cpp"
using namespace std;







int chatbot(myitem all_items[],int all_items_length){
  /**
  function: the most important function to be called by main. processes user input and call other functions
  input: array of structure holding game data, and the length of the array(int)as parameters
  output: 1 to tell while loop in main function to call again. 0 when the game ends .
  **/
  //cout<<endl;
  string varline, firstword;
  cout<<">>> ";
  getline(cin, varline);

  stringstream line(varline);
  //cout<<endl;
  line>>firstword;
  if(firstword=="eat") {
    string obj;
    line>>obj;
    eat(obj, all_items,all_items_length);
  } else if(firstword=="get") {
    string obj;
    line>>obj;
    getobj(obj, all_items,all_items_length);
  }else if(firstword=="help") help();
  else if(firstword=="hint") hint();
  else if(firstword=="inventory") invo(all_items,all_items_length);
  else if((firstword=="kick")||(firstword =="hit")||(firstword=="fight")) {
    string obj;
    line>>obj;
    kick(obj, all_items,all_items_length);
  }
  else if((firstword=="look")||(firstword =="inspect")||(firstword=="see")||(firstword=="view")||(firstword=="examine")||(firstword=="read")) {
    string obj;
    line>>obj;
    look(obj, all_items,all_items_length);
  }
  else if(firstword=="print") printallitem(all_items,all_items_length);
  else if((firstword=="quit")||(firstword =="exit")||(firstword=="close")) {
    cout<<"Do you want to save the game before quitting? [Y/N]";
    string response;
    cin>> response;
    if (response=="Y"||response=="yes") savegame(all_items_length,all_items);
    return 0;// quits
  }
  else if(firstword=="save") savegame(all_items_length,all_items);


  else{

    cout<<"Sorry, I don't understand what you mean. Try rephrasing your input."<<endl;

  }
  if(all_items[0].getable == 1)return 0;// change to 0 after implementation


  //cout<<endl;
  return 1;
  }


//other function implementation

int eat(string obj,myitem all_items[],int all_items_length){
  /**
  function:  eats an object
  input: name of object (string), array of structure holding game data, and the length of the array(int)as parameters
  output: 0(for terminating the function without running all the scripts in some cases)
  **/
  if (obj==""){
    cout<<"Eat What???"<<endl;
    return 0;
  }
  int i;
  for (i=1; i<=all_items_length; i++){// find id of corresponding item
    if (all_items[i].identity==obj) break;
  }if (i>all_items_length){// no item found
    cout<< "Sorry, I don't know what "<<obj<<" is."<<endl;
      return 0;
  }
  if (all_items[i].knowExistence == 1 && all_items[i].inPossession == 1){

    if ((obj == "turkey")){//eat turkey
      cout<<"You ate the turkey. You now have the its bone."<<endl
        <<"The bone is now in your inventory"<<endl;
          all_items[i].inPossession = 0;
          all_items[i].location =""; //switch to 0 DIES
          all_items[i].knowExistence=0;
          all_items[i].getable=0;
          all_items[4].inPossession = 1;
          all_items[4].location ="inventory";
          all_items[4].knowExistence=1;
          all_items[4].getable=0;
    }else if ((obj == "fish")){
      cout<<"The fish is slimy and raw. You decide not to eat it."<<endl;
    }else {
      cout<<"This item is not edible. meh."<<endl;
    }

  }else if (all_items[i].knowExistence == 0){
    cout<< "What "<< obj <<"? *doge*"<<endl;
  }else if (all_items[i].inPossession == 0){
    cout<<"You can only eat items in your inventory."<<endl;
  }
}

int getobj(string obj, myitem all_items[], int all_items_length){// get objects.takes in name of object (string),the array of structure holding game data, and the length of the array(int) as parameters
  /**
  function: get an object and put it into inventory
  input: name of object (string), array of structure holding game data, and the length of the array(int)as parameters
  output: 0(for terminating the function without running all the scripts in some cases)
  **/
  int i;
  if (obj==""){
    cout<<"You've got to tell me what you wanna get as well."<<endl;
    return 0;
  }
  for (i=1; i<=all_items_length; i++){// find id of corresponding item
    if (all_items[i].identity==obj) break;
  }
  if (i>all_items_length){
    cout<< "Sorry, I don't know what "<<obj<< " is."<<endl;

  }

  if (all_items[i].getable == 1 && all_items[i].knowExistence == 1 && all_items[i].inPossession == 0){
    all_items[i].inPossession =1;
    cout<<"You got the "<< all_items[i].identity<<". It's now in your inventory."<<endl;
  }else if (all_items[i].knowExistence == 0){
    cout<< "What "<< obj <<"? *doge*"<<endl;
  }else if (all_items[i].inPossession == 1){
    cout<<"It's already in your inventory."<<endl;
  }else if (all_items[i].getable == 0){
    cout<<"You can't get it."<<endl;
  }
}
void help(){
  /**
  function:print several lines of help which doesn't helps much. takes and return nothing
  input: NA
  output: void
  **/
  cout<<"You're trapped in a room. Find your way out!"<<endl
    <<"Phrase your sentences as follows:"<<endl
    <<"<verb> (eg. look, save, quit,)" <<endl
    <<"<verb> <object> (e.g. get key, look table)"<<endl;

}
void hint(){
  /**
  function:print some hint
  input: NA
  output: void
  **/
  cout<<"The door is on the wall. The key is with the animal. The cat (if exists) wants fish. The dog (if exists) wants bone. Look inspect the chest/animal after you find the corresponding action items."<<endl;
}
int invo(myitem all_items[],int all_items_length){
  /**
  function:print inventory
  input: array of structure holding game data, and the length of the array(int)as parameters
  output: 0
  **/
  int i, itemcount = 0;
  for (i=1; i<all_items_length; i++){// find id of corresponding item
    if (all_items[i].inPossession==1){
      if (itemcount==0) cout<<"Inventory"<<endl<<"---------"<<endl;
      cout<<"- "<<all_items[i].identity<<endl;
      itemcount++;
    }

  }
  if (itemcount==0) cout<<"There's nothing in your inventory."<<endl;
}

int kick(string obj,myitem all_items[],int all_items_length){//kick objects. takes in name of object (string),the array of structure holding game data, and the length of the array (int)as parameters
  /**
  function: kick an object
  input: name of object (string), array of structure holding game data, and the length of the array(int)as parameters
  output: 0(for terminating the function without running all the scripts in some cases)
  **/
  if (obj==""){
    cout<<"Kick WHAT???"<<endl;
    return 0;
  }
  int i;
  for (i=1; i<=all_items_length; i++){// find id of corresponding item
    if (all_items[i].identity==obj) break;
  }if (i>all_items_length){// no item found
    cout<< "Sorry, I don't know what is "<<obj<<endl;
      return 0;
  }
  if (all_items[i].knowExistence == 1 && all_items[i].inPossession == 0){
    if ((obj == "cat")||(obj == "dog")){//kick animal orz.. why...
      cout<<"The "<<obj<< " is angry. It scratches and bites you continuously."<<endl
        <<"You die."<<endl
        <<"We hope you've learned your lesson and never abuse animal again. (Programmer: Animal abusers doesn't deserve to play our game!)"<<endl;
        all_items[0].getable = 1;//switch to 0 DIES
    }else if ((obj == "door")){
      if (rand()%5 == 0){
        cout<<"Congratulations! You broke the door and escaped. Time to continue with your coding homework!:D:D:D (Everything occurs too suddenly, right?)"<<endl;
        all_items[0].getable=1;
      }else{
        cout<<"Nothing interesting happens. Do you want to try doing that again?"<<endl;
      }
    }else {
      cout<<"Control your temper- anger won't solve your problems! "<<endl;
    }

  }else if (all_items[i].knowExistence == 0){
    cout<< "What "<< obj <<"? *doge*"<<endl;
  }else if (all_items[i].inPossession == 1){
    cout<<"This item is in your inventory. You cannot kick it."<<endl;
  }
}

int look(string obj,myitem all_items[],int all_items_length){ //look at objects. takes in a name of object (string), the array of structure holding game data, and the length of the array (int)as parameters
  /**
  function: look at an object and describe it.
  input: name of object (string), array of structure holding game data, and the length of the array(int)as parameters
  output: 0(for terminating the function without running all the scripts in some cases)
  **/
  if (obj==""||obj == "floor"||obj == "around"||obj == "room"){ //for non item locations
      cout<< "You look around the room. It's a tiny crowded room surrounded by four walls. On the floor, there is";
      int i,last=0;
      for (i=1; i< all_items_length; i++){
        if (all_items[i].location == "floor"){
          cout<<" a "<< all_items[i].identity<< ",";
          all_items[i].knowExistence=1;
          last=i;
        }
      }
      cout<< string(all_items[last].identity.length()+3,'\b')<<"and a "<<all_items[last].identity<<"."<<endl;
      return 0;
  }
  if (obj=="wall"){//for non item locations
      cout<< "On the wall there is a door and a "<<all_items[5].identity<<endl;
      all_items[1].knowExistence=1;
      all_items[5].knowExistence=1;
      return 0;
  }
  if (obj=="roof"||obj=="ceiling"||obj =="up"){//for non item locations
      cout<< "There's nothing on the ceiling."<<endl;
      return 0;
  }
  int i;
  for (i=1; i<=all_items_length; i++){// find id of corresponding item
    if (all_items[i].identity==obj) break;
  }if (i>all_items_length){// no item found
    cout<< "Sorry, I don't know what "<<obj<<" is."<<endl;
      return 0;
  }
  if (i==1){//door is obviously existing object. So it's coded separatedly
    if (all_items[i].knowExistence==0){
      cout<<"There has to be a door in the room. But where is it?"<<endl;
      return 0;
    }
    cout<< "The door is locked. On the door, there's a number pad."<<endl
      <<"Enter the passcode to open the door: ";
    string input,x;
    getline(cin,input);
    stringstream input_stream(input);
    input_stream >>x;
    if (x== all_items[0].location){
      cout<<"Congratulations! You've escaped from the room. Time to continue with your coding assignment!"<<endl;
      all_items[0].getable=1;
    }else{
      cout<<"Incorrect password!"<<endl;
    }
  }else if (all_items[i].knowExistence==0){// if existence is not known yet
    cout<<"I don't know what is this... yet(?)...(Programmer is trying to tell you: this item exists but you have to find it first!)"<<endl;
  }else if (i==2){ //look animal
    if (all_items[7].knowExistence){
      cout<<"It's playing happily in the corner."<<endl;
      return 0;
    }
    cout<<"You look at the "<<obj<<". It's quite cute :3 There's a shiny object hanging from its neck, but it doesn't want give it to you so easily. Why not exchange it with something else?"<<endl;
    int i, itemcount = 0;
    for (i=1; i<all_items_length; i++){// find id of corresponding item
      if (all_items[i].inPossession==1){
        if (itemcount==0) cout<<"Here is a list of the items in your inventory. Which item would you like to give the the "<<obj<<" in exchange for the shiny object?(Enter to skip)"<<endl;
        cout<<"- "<<all_items[i].identity<<endl;
        itemcount++;
      }
    }
    if (itemcount==0){
      cout<<"There's nothing in your inventory"<<endl;
      return 0;
    }
    string exchange;
    cout<<">>> ";
    getline(cin,exchange);
    if (exchange==""){
      return 0;
    }else if (exchange == all_items[4].identity){
      cout<<"The "<< obj<<" gives you the shiny item. It's a key!"<<endl
        <<"You put the key in your inventory."<<endl;
      all_items[7].inPossession =1;
      all_items[4].inPossession =0;
      all_items[7].knowExistence =1;
    }
  }else if (obj == "turkey"){//look turkey
    cout<<"A beautifully roasted turkey. Looks delicious..."<<endl;
    all_items[4].knowExistence=1;
  }else if (obj == "aquarium"){//look aquarium
    if(all_items[4].inPossession==0){
      cout<<"A fish is swimming in the aquarium."<<endl;
      all_items[4].knowExistence=1;
    }else{
      cout<<"A half full/ half empty aquarium. Well, it depends on how you see it, but the fact is that it's useless now."<<endl;
    }
  } else if (i==4){//look fish/ look bone
    cout<< "It doesn't seems like anything which can be safely consumed by a human. And I'm not *that* hungry."<<endl;
  }else if (i==5){// look painting/ look poster
    cout<< "It's just a simple, ordinary, useless "<<obj<<". Well, it's useful as a decoration, I suppose."<<endl;
  }else if (i==6){//look chest
    if (all_items[9].knowExistence==1){//chest opened
      cout<< "The chest is unlocked."<<endl;
      if (all_items[9].location=="chest"&&all_items[9].inPossession==0){

        cout<<" There's a piece of paper in the chest."<<endl;

      }
    }else {//chest locked
      cout<<"The chest is locked. You need to open it with a key."<<endl;
      if(all_items[7].inPossession==1){
        cout<<"You have a key in your inventory. You opened the chest with the key. There's a piece of paper in the chest"<<endl;
        all_items[9].knowExistence=1;
        all_items[7].inPossession =0;
      }
    }
  }else if (i==7){
    cout<<"A key. Where can we use it?"<<endl;
  }else if (i==8){
    int i, itemcount = 0;
    for (i=1; i<all_items_length; i++){// find id of corresponding item
      if (all_items[i].location==obj){
        if (itemcount==0) cout<<"On the "<< obj<<", there is: "<<endl;
        cout<<"a "<<all_items[i].identity<<endl;
        itemcount++;
        all_items[i].knowExistence=1;

      }

    }
    if (itemcount==0) cout<<"There's nothing on the "<<obj<<endl;
  }else if(i==9){
    cout<< "There's a line of word on the paper. It says: "<< all_items[0].location<<endl;
  }




}


void printallitem(myitem all_items[],int all_items_length){
  /**
  function: print array of data structure
  input: array of structure holding game data, and the length of the array(int)as parameters
  output: void
  **/
  for(int i=0; i < all_items_length; i++){
    cout<<"identity: "<<all_items[i].identity<<endl
    <<"getable: "<< all_items[i].getable<<endl
    <<"knowExistence: "<< all_items[i].knowExistence<<endl
    <<"inPossession: "<< all_items[i].inPossession<< endl
    <<"location: "<< all_items[i].location<<endl<<endl;
  }
}
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
