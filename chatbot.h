
using namespace std;
#ifndef chatbot_h
#define chatbot_h
//main.cpp function
int init();
//chatbot main function
int chatbot(myitem[],int);
//chatbot other function
int eat(string, myitem[],int);
int getobj(string, myitem[],int);
void help();
void hint();
int invo(myitem[],int);
int kick(string, myitem[] ,int);
int look(string, myitem[] ,int);
void printallitem(myitem[],int);
void savegame(int , myitem[]);
#endif
