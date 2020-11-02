#include "choices.cpp"
#include <bits/stdc++.h>
int main(){

/** These lines won't work  random shuffle only shuffle the order. It's not picking one of them
string animalType = random_shuffle(animals[0], animals[3]);
string doorType = random_shuffle(animals[0], animals[3]);
**/
string tool;
if (animalType == "cat") {
  tool = "fishtank";
} else if (animalType == "dog") {
  tool = "turkey leg";
}
double doorBreakProb;
if (doorType = "steel") {
  doorBreakProb = 0.05;
} else {
  doorBreakProb = 0.2;
}
}
