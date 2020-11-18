//STAND ALONE CHATBOT.cpp
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include "structure.h"
#include "chatbot.h"
#include "main.cpp"
using namespace std;




//chatbot function
int chatbot(myitem all_items[],int all_items_length){
  cout<<endl;
  string varline, firstword;
  cout<<">>> ";
  getline(cin, varline);
  stringstream line(varline);
  cout<<endl;
  line>>firstword;
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
  if(firstword=="print") printallitem(all_items,all_items_length);
  if((firstword=="quit")||(firstword =="exit")||(firstword=="close")) {
    cout<<"Do you want to save the game before quitting? [Y/N]";
    string response;
    cin>> response;
    if (response=="Y"||response=="yes") savegame(all_items_length,all_items);
    return 0;// quits
  }
  if(firstword=="save") savegame(all_items_length,all_items);


  if(all_items[1].getable == 1){// change to 0 after implementation
    return 0;
  }

  cout<<endl;
  return 1;
  }


//other function implementation


int getobj(string obj, myitem all_items[], int all_items_length){
  int i;
  if (obj==""){
    cout<<"You've got to tell me what you wanna get as well."<<endl;
    return 0;
  }
  for (i=0; i<=all_items_length; i++){// find id of corresponding item
    if (all_items[i].identity==obj) break;
  }
  if (i>all_items_length){
    cout<< "Sorry, I don't know what is "<<obj<<endl
      << "Type \"help\" to get a list of possbile items";

  }

  if (all_items[i].getable == 1 && all_items[i].knowExistence == 1 && all_items[i].inPossession == 0){
    all_items[i].inPossession =1;
    cout<<"You got the "<< all_items[i].identity<<". It's now in your inventory."<<endl;
  }else if (all_items[i].knowExistence == 0){
    cout<< "What "<< obj <<"? *doge*";
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
    <<"<verb> <object> (eg get key, look at table)"<<endl
    <<"use <object(tool)> to <object(target)> (eg use key with door)"<<endl;
}
int hint(){
  cout<<"huh what hint do you want"<<endl;
}
int invo(myitem all_items[],int all_items_length){
  int i, itemcount = 0;
  for (i=0; i<all_items_length; i++){// find id of corresponding item
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
  int i=0;
  for (i=0; i<=all_items_length; i++){// find id of corresponding item
    if (all_items[i].identity==obj) break;
  }if (i>all_items_length){// no item found
    cout<< "Sorry, I don't know what is "<<obj<<endl
      << "Type \"help\" to get a list of possbile items";
  }
  if (all_items[i].knowExistence == 1 && all_items[i].inPossession == 0){
    if ((obj == "cat")||(obj == "dog")){
      cout<<"The "<<obj<< " is angry. It scratches and bites you non stop."<<endl
        <<"You die."<<endl
        <<"Learn the lesson. Do not abuse animal.";
        all_items[1].getable = 1;//switch to 0
    }else {
      cout<<"Control your temper. Doing so doesn't help.(i.e. programmer did not write any script for kicking this object)";
    }
    cout<<"You got the "<< all_items[i].identity<<". It's now in your inventory."<<endl;
  }else if (all_items[i].knowExistence == 0){
    cout<< "What "<< obj <<"? *doge*";
  }else if (all_items[i].inPossession == 1){
    cout<<"This item is in your inventory. You cannot kick it."<<endl;
  }
}

int look(string obj,myitem all_items[],int all_items_length){


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
