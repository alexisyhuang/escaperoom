//for testing chatbot.cpp only
#include "structure.h"
#include "chatbot.h"

using namespace std;

int main(){

  int all_items_length = 2;
  myitem all_items[10]={
    {"key","silver key", 1, 0, "cat"},
    {"food","cake",1,0,"table"}
  };
  printallitem(all_items_length,all_items);
  while (chatbot(all_items,all_items_length));//ADD THIS LINE TO THE REAL MAIN FUNCTION
}
