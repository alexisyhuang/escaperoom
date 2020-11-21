//STAND ALONE CHATBOT.cpp
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include "structure.h"
#include "chatbot.h"
#include "updatedmain.cpp"
using namespace std;




//chatbot function
int chatbot(myitem all_items[],int all_items_length){
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
  }
  if(firstword=="get") {
    string obj;
    line>>obj;
    getobj(obj, all_items,all_items_length);
  }
  if(firstword=="help") help();
  if(firstword=="hint") hint();
  if(firstword=="inventory") invo(all_items,all_items_length);
  if((firstword=="kick")||(firstword =="hit")||(firstword=="fight")) {
    string obj;
    line>>obj;
    kick(obj, all_items,all_items_length);
  }
  if((firstword=="look")||(firstword =="inspect")||(firstword=="see")||(firstword=="view")||(firstword=="examine")) {
    string obj;
    line>>obj;
    look(obj, all_items,all_items_length);
  }
  if(firstword=="print") printallitem(all_items,all_items_length);
  if((firstword=="quit")||(firstword =="exit")||(firstword=="close")) {
    cout<<"Do you want to save the game before quitting? [Y/N]";
    string response;
    cin>> response;
    if (response=="Y"||response=="yes") savegame(all_items_length,all_items);
    return 0;// quits
  }
  if(firstword=="save") savegame(all_items_length,all_items);


  if(all_items[0].getable == 1){// change to 0 after implementation
    return 0;
  }

  //cout<<endl;
  return 1;
  }


//other function implementation
int eat(string obj,myitem all_items[],int all_items_length){
  if (obj==""){
    cout<<"Eat What???"<<endl;
    return 0;
  }
  int i;
  for (i=1; i<=all_items_length; i++){// find id of corresponding item
    if (all_items[i].identity==obj) break;
  }if (i>all_items_length){// no item found
    cout<< "Sorry, I don't know what is "<<obj<<endl;
      return 0;
  }
  if (all_items[i].knowExistence == 1 && all_items[i].inPossession == 1){
    if ((obj == "turkey")){//kick animal orz.. why...
      cout<<"You ate the turkey. Remaining is the bone."<<endl
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
      cout<<"It's raw. You decided not to eat it."<<endl;
    }else {
      cout<<"This item is not edible. meh."<<endl;
    }

  }else if (all_items[i].knowExistence == 0){
    cout<< "What "<< obj <<"? *doge*"<<endl;
  }else if (all_items[i].inPossession == 0){
    cout<<"You can only eat items in your inventory"<<endl;
  }
}

int getobj(string obj, myitem all_items[], int all_items_length){
  int i;
  if (obj==""){
    cout<<"You've got to tell me what you wanna get as well."<<endl;
    return 0;
  }
  for (i=1; i<=all_items_length; i++){// find id of corresponding item
    if (all_items[i].identity==obj) break;
  }
  if (i>all_items_length){
    cout<< "Sorry, I don't know what is "<<obj<<endl;

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
int help(){
  cout<<"You're trapped in a room. Find your way out!"<<endl
    <<"Phrase your sentances as follow:"<<endl
    <<"<verb> (eg. look, save, quit,)" <<endl
    <<"<verb> <object> (eg get key, look table)"<<endl;

}
int hint(){
  cout<<"huh what hint do you want"<<endl;
}
int invo(myitem all_items[],int all_items_length){
  int i, itemcount = 0;
  for (i=1; i<all_items_length; i++){// find id of corresponding item
    if (all_items[i].inPossession==1){
      if (itemcount==0) cout<<"Inventory"<<endl<<"---------"<<endl;
      cout<<"- "<<all_items[i].identity<<endl;
      itemcount++;
    }

  }
  if (itemcount==0) cout<<"There's nothing in your inventory"<<endl;
}

int kick(string obj,myitem all_items[],int all_items_length){
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
      cout<<"The "<<obj<< " is angry. It scratches and bites you non stop."<<endl
        <<"You die."<<endl
        <<"Learn the lesson. Do not abuse animal.(Programmer: Animal abuser doesn't deserve to play our game)"<<endl;
        all_items[0].getable = 1;//switch to 0 DIES
    }else if ((obj == "door")){
      if (rand()%5 == 0){
        cout<<"Congratulations! You broke the door and escpaed. Time to continue with your coding homework!:D:D:D (Every thing occurs too suddenly right?)"<<endl;
      }else{
        cout<<"Nothing interesting happens. Do you want to do that again?"<<endl;
      }
    }else {
      cout<<"Control your temper. Doing so doesn't help.(i.e. programmer did not write any script for kicking this object)"<<endl;
    }

  }else if (all_items[i].knowExistence == 0){
    cout<< "What "<< obj <<"? *doge*"<<endl;
  }else if (all_items[i].inPossession == 1){
    cout<<"This item is in your inventory. You cannot kick it."<<endl;
  }
}

int look(string obj,myitem all_items[],int all_items_length){
  if (obj==""||obj == "floor"||obj == "around"){ //for non item locations
      cout<< "You look around the room. It's a tiny crowded room. On the floor, there is";
      int i,last=0;
      for (i=1; i< all_items_length; i++){
        if (all_items[i].location == "floor"){
          cout<<" a "<< all_items[i].identity<< ",";
          all_items[i].knowExistence=1;
          last=i;
        }
      }
      cout<< string(all_items[last].identity.length()+4,'\b')<<"and a "<<all_items[last].identity<<"."<<endl;
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
    cout<< "Sorry, I don't know what is "<<obj<<endl;
      return 0;
  }
  if (i==1){//door is obviously existing object. So it's coded separatedly
    if (all_items[i].knowExistence==0){
      cout<<"There has to be a door in the room. But where is it?"<<endl;
      return 0;
    }
    cout<< "The door is locked.On the door, there's a number pad."<<endl
      <<"Enter the pass code to open the door: ";
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
      cout<<"It's playing happily in the corner"<<endl;
      return 0;
    }
    cout<<"You look at the "<<obj<<". There's a shiniy object hanging from its neck, but it wouldn't give it to you. Why not exchange it with something else?"<<endl;
    int i, itemcount = 0;
    for (i=1; i<all_items_length; i++){// find id of corresponding item
      if (all_items[i].inPossession==1){
        if (itemcount==0) cout<<"Here is a list of item in your inventory. Which item would you give the the "<<obj<<" in exchange for the shiny object?(Enter to skip)"<<endl;
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
      all_items[7].knowExistence =1;
    }
  }else if (obj == "turkey"){//look turkey
    cout<<"A beautifully roasted turkey. Looks delicious..."<<endl;
    all_items[4].knowExistence=1;
  }else if (obj == "tank"){//look tank
    if(all_items[4].inPossession==0){
      cout<<"A fish is swimming in the fish tank"<<endl;
      all_items[4].knowExistence=1;
    }else{
      cout<<"There's nothing in the tank"<<endl;
    }
  } else if (i==4){//look fish/ look bone
    cout<< "It doesn't seems like something safely edible by human. And I'm not *that* hungry."<<endl;
  }else if (i==5){// look painting/ look poster
    cout<< "It's just a simple ordinary useless "<<obj<<". Well, a decoration."<<endl;
  }else if (i==6){//look chest
    if (all_items[9].knowExistence==1){//chest opened
      cout<< "The chest is unlocked."<<endl;
      if (all_items[9].location=="chest"&&all_items[9].inPossession==0){
        cout<<" There's a piece of paper in the chest"<<endl;
      }
    }else {//chest locked
      cout<<"The chest is locked. You need to open it with a key."<<endl;
      if(all_items[7].inPossession==1){
        cout<<"You have a key in your inventory. You opened the chest with the key. There's a piece of paper in the chest"<<endl;
        all_items[9].knowExistence=1;
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
    cout<< "There's a line of word on the paper. It writes: "<< all_items[0].location<<endl;
  }




}

int printallitem(myitem all_items[],int all_items_length){
  for(int i=0; i < all_items_length; i++){
    cout<<"identity: "<<all_items[i].identity<<endl
    <<"getable: "<< all_items[i].getable<<endl
    <<"knowExistence: "<< all_items[i].knowExistence<<endl
    <<"inPossession: "<< all_items[i].inPossession<< endl
    <<"location: "<< all_items[i].location<<endl<<endl;
  }
}
