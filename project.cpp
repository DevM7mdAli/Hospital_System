#include <iostream>
#include <string>
#include <fstream>


using namespace std;

//prototype the functions
void add();
void search();
void update();
void del();
void sort();
void print();

//omar_Alsubgh;

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
    int choice;

    cout << "|----------------------------------------------------------------------------------|" << endl;
    cout << "\t\t\t HOSPITAL MANAGEMENT SYSTEM" << endl;
    cout << "|----------------------------------------------------------------------------------|" << endl << endl;

    cout << "Choose one of the options below: " << endl
         << "[1] Add a patient " << endl
         << "[2] Search for a patient" << endl
         << "[3] Update patient information " << endl
         << "[4] Delete patient " << endl
         << "[5] Sort patients" << endl
         << "[6] Display all patients "<<endl
         << "[7] Exit Program "<<endl
         << "Please enter your choice: ";
    cin >> choice;
//I updated the menu ~Mustafa
}
