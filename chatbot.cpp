//STAND ALONE CHATBOT.cpp
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include "structure.h"
#include "chatbot.h"
#include "main.cpp"
using namespace std;


//functions
/**
int chatbot(myitem[],int);
int getobj(string, myitem[],int);
int help();
int hint();
int invo(myitem[],int);
int printallitem(int, myitem[]);
int savegame();//to to be implemented by Alexis
**/
//fake main
/**int main(){

  int all_items_length = 2;
  myitem all_items[10]={
    {"key","silver key", 1, 0, "cat"},
    {"food","cake",1,0,"table"}
  };
  printallitem(all_items_length,all_items);
  while (chatbot(all_items,all_items_length));//ADD THIS LINE TO THE REAL MAIN FUNCTION
}
**/

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

  /**if(firstword=="help") help();
  if(firstword=="help") help();**/
  cout<<endl;
  return 1;
  }


//other function implementation


int getobj(string obj, myitem all_items[], int all_items_length){

  int i,j;
  for (i=0; i<=all_items_length; i++){// find id of corresponding item
    if (all_items[i].identity==obj) break;
  }if (i>all_items_length){
    for(j=0; j<all_items_length; j++){
      if (all_items[j].catagory==obj) {
        i=j;
        break;
      }
    }
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
    <<"use <object(tool)> to <object(target)> (eg use key with door)"<<endl
    <<"<other verb> <object(target)> with <object(tool)> (eg open door with key)"<<endl;
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
    cout<<"This item is "<<endl;
  }else if (all_items[i].getable == 0){
    cout<<"You can't get it."<<endl;
  }
}


int printallitem(myitem all_items[],int all_items_length){
  for(int i=0; i < all_items_length; i++){
    cout<< "catagory: "<< all_items[i].catagory<<endl
    <<"identity: "<<all_items[i].identity<<endl
    <<"getable: "<< all_items[i].getable<<endl
    <<"knowExistence: "<< all_items[i].knowExistence<<endl
    <<"inPossession: "<< all_items[i].inPossession<< endl
    <<"location: "<< all_items[i].location<<endl<<endl;
  }
}











/**
string verb[4]={"eat","get","look","hit"};
int verblength = 4;

int findverb(int length, string uinputA[]);
int main(){
  string uinput;
  getline(cin,uinput);
  int uinputlength = count(uinput.begin(), uinput.end(), ' ')+ 1;
  stringstream uinputS(uinput);
  string uinputA[5];//maximum numbers of worlds in the getline
  if (uinputlength > 5){
    cout<< "Wait a minute. Your sentance is too complicate for me to understand. Can you simplify it a bit?";
  }else{
    for (int i=0; i<uinputlength; i++){
      uinputS >> uinputA[i];
    }
    for (int i=0; i<uinputlength; i++){
      cout<< uinputA[i]<<endl;
  }// by this point, user input is stored in an array of words.
  string actionA[4]={};/**action array: 0= subject(omittable), 1= verb, 2= object
  findverb(uinputlength,uinputA);
  cout << actionA[1];
  }
}

int findverb(int length, string uinputA[]){
  for (int i=0; i<length; i++){
    for (int j=0; j<verblength; j++){
      if (uinputA[i]==verb[j]){
        cout<< uinputA[i];
        break;
      }
    }
  }
}
**/
