#include <iostream>
#include <string>
#include <fstream>
using namespace std;
//Struct for patients
struct Patients
{
    string name;
    string ID;
    string age;
    string PhoneNumber;
    string medicine;
    string dose;
};

//DON'T CHANGE OR SORT OR EDIT
string fName="Information.txt";
const int LIMIT = 300; //300 patients only
int Size=0;
Patients lib[LIMIT];
//DON'T CHANGE OR SORT, THE TOP DECLARATIONS ARE INTEGRATED WITH THE ONES BELOW
void loadData(string fName,Patients lib[]);
void displayData(Patients lib[]);
void saveData(string fName, Patients lib[]);
void addPatients(Patients lib[] );
void deletePatients(Patients lib[]); //Still not defined
void Menu();
void choose(int x);
int main()
{
    Menu();
    int choice;
    cout<< "Please enter your choice: ";
    cin >> choice;
    choose(choice);
//I updated the menu ~Mustafa
}

//Functions Definitions ~Mustafa
void addPatients(Patients lib[] )
{
    string name,ID,age,phoneNumber,medicine,dose;
    int choice;
        cout<< "Enter Patient name: ";
        cin>> name;
        cout<< "Enter Patient ID: ";
        cin>> ID;
        cout<<"Enter Patient age: ";
        cin>> age;
        cout<<"Enter Patient Phone Number: ";
        cin>> phoneNumber;
        cout<<"Enter Patient medicine: ";
        cin>> medicine;
        cout<<"Enter Patient dose: ";
        cin>> dose;

        lib[Size].name=name;
        lib[Size].ID=ID;
        lib[Size].age=age;
        lib[Size].PhoneNumber=phoneNumber;
        lib[Size].medicine=medicine;
        lib[Size].dose=dose;
        Size++;

    cout<< "Patient have been added successfully.\n";
}
void saveData(string fName, Patients lib[])
{
    ofstream oFile(fName);
    if (oFile.is_open())
    {
        for (int i=0;i<Size;i++)
        {
            oFile<<lib[i].name<<endl;
            oFile<<lib[i].ID<<endl;
            oFile<<lib[i].age<<endl;
            oFile<<lib[i].PhoneNumber<<endl;
            oFile<<lib[i].medicine<<endl;
            oFile<<lib[i].dose<<"\n"<<endl;
        }
    }
}
void displayData(Patients lib[])
{
    for(int i=0;i<Size;i++)
    {
        cout<<"Students ["<<i+1<<"]"<<endl;
        cout<<"ID:\t\t"<<lib[i].name<<endl;
        cout<<"Name:\t\t"<<lib[i].ID<<endl;
        cout<<"Age:\t\t"<<lib[i].age<<endl;
        cout<<"PhoneNumber:\t\t"<<lib[i].PhoneNumber<<endl;
        cout<<"Medicine:\t\t"<<lib[i].medicine<<endl;
        cout<<"Dose:\t\t"<<lib[i].dose<<"\n"<<endl;
    }
}
void loadData(string fName,Patients lib[])
{
    ifstream inFile(fName.c_str());
    if (inFile.is_open())
    {
        int counter = 0;
        while(!inFile.eof())
        {
            getline(inFile, lib[counter].name);
            getline(inFile, lib[counter].ID);
            getline(inFile, lib[counter].age);
            getline(inFile, lib[counter].PhoneNumber);
            getline(inFile, lib[counter].medicine);
            getline(inFile, lib[counter].dose);
            counter++;
        }
        Size=counter-1;
        inFile.close();
    }
    else cout<<"Fail\n";
}
void Menu()
{
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
         << "[7] Exit Program "<<endl;
}
void choose(int x)
{
    switch (x)
    {
        case 1:
            addPatients(lib);
    }
}
