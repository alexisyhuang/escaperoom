#include "randgame.h"
#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;
void randgame(string room[6][2][5], string items[5][7], int seed){
  srand(seed);
  for (int i =0; i<6; i++){
    for (int j =0; j<2; j++){
      for (int k =0; k<5; k++){
      cout<< room[i][j][k]<<' ';
      }
      cout  << endl;
    }
    cout <<endl;
  }
  for (int i =0; i<5; i++){
    for (int j =0; j<7; j++){
      cout<< items[i][j]<<' ';
    }
    cout <<endl;
  }
}
