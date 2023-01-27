#include <iostream>
#include <cmath>
#include <string>


using namespace std;

//prototype the functions 
void add();
void serch();
void update();
void del();
void sort();
void print();




//Struct for patients
struct patients
{
string name;
int ID;
int age;
int PhoneNumber;
string medicine;
string dose;
};



int main()
{
int Size;




}


/*
o adding new item.
o search for specific item.
o update existing record.
o delete.
o Sort.
o Display.
o At the start, your program should populate the array(s) from a file and allow the user to edit it. At
the end overwrite the same file with the latest contents of the array(s).
o Provide another statistical report as separate text file e.g. the number of records, with date, time
of last update.
*/