//Team Members: Mustafa Aljishi, Ali Abu Hulaigah, Mohammed AlAjmi, Ali AlBaqqal, Omar AlSubgh, Baqer AlHaddad
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <ctime>

using namespace std;
//Struct for Patients
struct Patients
{
    string name;
    string ID;
    string age;
    string PhoneNumber;
    string medicine;
    string dose;
};

//Global Variables:
string fName="data.txt"; //where the patients info are stored
const int LIMIT = 300; //300 patients only
int Size=0; //How many students are inputted in the txt file
Patients lib[LIMIT]; //the array where we will write to

//Functions Declarations:
void read();
void loadData(Patients lib[]);
void displayData(Patients lib[]);
void UpdateData(Patients lib[]);
void saveData(Patients lib[] );
void addPatients(Patients lib[]);
void deletePatients(Patients lib[]);
void DisplayAll(Patients lib[]);
void Sort(Patients lib[]);
bool sortByID(Patients &a, Patients &b);
bool sortByName(Patients &a, Patients &b);
void choose(int x);
void Menu();
void report();

int main()
{
    Here:
    read(); // opening the file "data.txt"
    
    loadData(lib); //loading the data from txt file "data.txt"

    Menu(); //loading the main menu
    
    int choice;
    cout<<"\nPlease enter your choice:\n";
    cin>>choice;
    choose(choice);
    
    saveData(lib); //saving the data written in the console to the txt file "data.txt"
    
    //The end of the program:
    int back;
    cout<<"Do you wish to go back to the main menu? (type 1 to go back, type anything to exit program)";
    cin>>back;
    if(back==1)
    {
        goto Here;
    }
}

//Functions Definitions:
void loadData(Patients lib[])
{
    ifstream inFile("data.txt");
    if(inFile.is_open()) {
        int counter=0;
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
    else cout<< "Fail\n";
}
void saveData(Patients lib[] )
{
   ofstream oFile("data.txt");
    if(oFile.is_open()) {
        for (int i=0;i<Size;i++)
        {
            oFile << lib[i].name << "\n";
            oFile << lib[i].ID << "\n";
            oFile << lib[i].age << "\n";
            oFile << lib[i].PhoneNumber << "\n";
            oFile << lib[i].medicine <<"\n";
            oFile << lib[i].dose <<"\n";
        }
        oFile.close();
    }
    else
        cout<<"fail\n";
}
void UpdateData(Patients lib[])
{
    string name;
    string element;
    cout<<"Please enter the name of the patient you are looking forward to update: "<<endl;
    cin>>name;
    int index;
    bool found;
    for(int i=0; i<Size; i++)
    {
        if(lib[i].name==name)
        {
            found=true;
            index=i;
            break;
        }
    }
    if (found==true)
    {
        cout<<"\nDo you wish to update the information of the patient you searched for? (1 for yes, anything for no)\n";
        int display;
        cin>>display;
        if (display==1)
        {
            string name,ID,age,phoneNumber,medicine,dose;
            int choice;
            cout<< "\nEnter Updated Patient name: ";
            getline(cin >>ws, name);
            cout<< "Enter Updated Patient ID: ";
            cin>> ID;
            cout<<"Enter Updated Patient age: ";
            cin>> age;
            cout<<"Enter Updated Patient Phone Number: ";
            cin>> phoneNumber;
            cout<<"Enter Updated Patient medicine: ";
            getline(cin >>ws, medicine);
            cout<<"Enter Updated Patient dose: ";
            cin>> dose;

            lib[index].name=name;
            lib[index].ID=ID;
            lib[index].age=age;
            lib[index].PhoneNumber=phoneNumber;
            lib[index].medicine=medicine;
            lib[index].dose=dose;


            cout<< "Patient have been updated successfully.\n";
        }
    }
    else
    {
        cout<<"\nPatient not found.\n";
    }

}
void addPatients(Patients lib[] )
{
    string name,ID,age,phoneNumber,medicine,dose;
    int choice;
    cout<< "\nEnter Patient name: ";
    getline(cin >>ws, name);
    cout<< "Enter Patient ID: ";
    cin>> ID;
    cout<<"Enter Patient age: ";
    cin>> age;
    cout<<"Enter Patient Phone Number: ";
    cin>> phoneNumber;
    cout<<"Enter Patient medicine: ";
    getline(cin >>ws, medicine);
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
    report();
}
void displayData(Patients lib[])
{
    string name;
    string element;
    cout<<"Please enter the name of the patient you are looking for: "<<endl;
    cin>>name;
    int index;
    bool found;
    for(int i=0; i<Size; i++)
    {
        if(lib[i].name==name)
        {
            found=true;
            index=i;
            break;
        }
    }
    if (found==true)
    {
        cout<<"\nDo you wish to display the information of the patient you searched for? (1 for yes, anything for no)\n";
        int display;
        cin>>display;
        if (display==1)
        {
            cout<<"\nID:\t\t"<<lib[index].name<<endl;
            cout<<"Name:\t\t"<<lib[index].ID<<endl;
            cout<<"Age:\t\t"<<lib[index].age<<endl;
            cout<<"PhoneNumber:\t\t"<<lib[index].PhoneNumber<<endl;
            cout<<"Medicine:\t\t"<<lib[index].medicine<<endl;
            cout<<"Dose:\t\t"<<lib[index].dose<<endl;
        }
    }
    else
    {
        cout<<"\nPatient not found.\n";
    }

}
void read()
{
    ifstream inFile;
    inFile.open("data.txt");
    if(inFile.is_open())
    {
        cout<<"\n\n";
    }
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
void deletePatients(Patients lib[])
{
    string name;
    string element;
    cout<<"Please enter the Patient name you want to delete: "<<endl;
    cin>>name;
    int index;
    bool found;
    for(int i=0; i<Size; i++)
    {
        if(lib[i].name==name)
        {
            found=true;
            index=i;
            for (int j=index; j<Size-1;j++)
            {
                lib[j]=lib[j+1];
            }
            cout<<"\nDeleted.\n";
            Size--;
            break;
        }
    }
    if (found==false)
    {
        cout<<"\nPatient not found\n";
    }
}
void choose(int x)
{
    switch(x)
    {
        case 1:
            addPatients(lib);
            break;
        case 2:
            displayData(lib);
            break;
        case 3:
            UpdateData(lib);
            break;
        case 4:
            deletePatients(lib);
            break;
        case 5:
            Sort(lib);
            break;
        case 6:
            DisplayAll(lib);
            break;
        default:
            cout<<"\n\n";
            break;
    }
}
void DisplayAll(Patients lib[])
{
    cout<<"Patient-Number\tName\t\tID\tAge\tPhoneNumber\tMedicine\tDose\n";
    for (int i=0;i<Size;i++)
    {
        cout<<"\t"<<i+1<<"\t"<<lib[i].name<<"\t\t"<<lib[i].ID<<"\t"<<lib[i].age<<"\t"<<lib[i].PhoneNumber<<"\t\t"<<lib[i].medicine<<"\t\t"<<lib[i].dose<<endl;
    }
    cout<<endl;
}
bool sortByID(Patients &a, Patients &b)
{
    return a.ID < b.ID;
}
bool sortByName(Patients &a, Patients &b)
{
    return a.name < b.name;
}
void Sort(Patients lib[])
{
    int i, j;
    cout<<"\nHow would you like to sort the data?\n";
    cout<<"[1] By Name\n";
    cout<<"[2] By ID\n";
    int chosi;
    cin>>chosi;

    if (chosi==1)
    {
        cout<<"Sorting the data by Name: \n";
        sort(&lib[0],&lib[Size],sortByName);
        cout<<"Patient-Number\tName\t\tID\tAge\tPhoneNumber\tMedicine\tDose\n";
        for (int i=0;i<Size;i++)
        {
          cout<<"\t"<<i+1<<"\t"<<lib[i].name<<"\t\t"<<lib[i].ID<<"\t"<<lib[i].age<<"\t"<<lib[i].PhoneNumber<<"\t\t"<<lib[i].medicine<<"\t\t"<<lib[i].dose<<endl;
        }
        cout<<endl;
    }
    else
    {
        cout<<"Sorting the data by ID: \n";
        sort(&lib[0],&lib[Size],sortByID);
        cout<<"Patient-Number\tName\t\tID\tAge\tPhoneNumber\tMedicine\tDose\n";
        for (int i=0;i<Size;i++)
        {
          cout<<"\t"<<i+1<<"\t"<<lib[i].name<<"\t\t"<<lib[i].ID<<"\t"<<lib[i].age<<"\t"<<lib[i].PhoneNumber<<"\t\t"<<lib[i].medicine<<"\t\t"<<lib[i].dose<<endl;
        }
        cout<<endl;
    }

}
void report()
{
	time_t t; // t passed as argument in function time()
    struct tm * tt; // decalring variable for localtime()
    time (&t); //passing argument to time()
    tt = localtime(&t);
    
   	ifstream input; //creates input file object named inFile	
    input.open("report.txt");
    
    ofstream output;// creates output file object
	output.open("report.txt");
	if(output.is_open()==true)
	    {
	 	output << "Number of Records: "<<Size<<" \nLast updated date and time: "<< asctime(tt);
	    
           	output.close();
        }
        else
          cout << "Failed  !" <<endl;

}
