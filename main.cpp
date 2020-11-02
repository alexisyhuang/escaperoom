#include "randgame.h"
#include <iostream>
using namespace std;
int main(){
  string room[6][2][5] = {};
  // 6 possible locations: door, table, floor, shelf, wall, ceiling
  // each location has 2 "attribute": what other items it contains, other attribute
  // attribute: important? (only important ones are mentioned in the )
  // 5 is for the items a location contains
  string items[5][7]={};
  // possible items: door, chest, animal, food, key,
  // attribute: identity, adj(wooden/steel; cat/dog), exist?, visible?, getable?, usable?, location,
  randgame(room, items,1);

  for (int i =0; i<6; i++){
    cout<< room[i]<<endl;
  }

}
