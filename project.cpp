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
int choose;

cout << "------------------------------------------------------------------------------------" << endl;
cout << "\t\t\t welcome to the hospetal system" << endl;
cout << "------------------------------------------------------------------------------------" << endl << endl;

cout << "choose one of the options: " << endl
     << "1- adding new item. " << endl
     << "2- Search " << endl
     << "3- update existing record " << endl
     << "4- delete patient " << endl
     << "5- Sort patients" << endl 
     << "6- print all patients ";
      cin >> choose;
}
