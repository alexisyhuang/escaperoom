#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;
struct myitem{// can add more if you wish
    string identity;
    string subtype;
    int getable; // 1
    int inPossession;
    string location;
};
int printallitem(int, myitem[]);

int main(){

  int all_items_length = 2;
  myitem all_items[10]={
    {"key","silver key", 1, 0, "cat"},
    {"food","cake",1,0,"table"}
  };

  printallitem(all_items_length,all_items);
}

int printallitem(int all_items_length, myitem all_items[  ]){
  for(int i=0; i < all_items_length; i++){
    cout<< "identity: "<< all_items[i].identity<<endl
    <<"subtype: "<<all_items[i].subtype<<endl
    <<"getable: "<< all_items[i].getable<<endl
    <<"inPossession: "<< all_items[i].inPossession<< endl
    <<"location: "<< all_items[i].location<<endl<<endl;
  }
}
/**
string verb[4]={"eat","get","look","hit"};
int verblength = 4;
void chatbot(string, )

**/




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
