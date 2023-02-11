#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <ctime>
#include <sstream>

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

//Global Variables
const int LIMIT = 100000; //100000 patients only
int Size=0; //How many students are inputted in the txt file
Patients lib[LIMIT]; //the array where we will write to

//Functions Declarations:
void Menu();// just for cout the menu
void choose(int x); // switch for the menu
void loadData(Patients lib[]); 
void addPatients(Patients lib[]);
void displayData(Patients lib[]);
void search(Patients lib[], string x);
void search(Patients lib[], int x);
void UpdateData(Patients lib[]);
void saveData(Patients lib[] );
void deletePatients(Patients lib[]);
void DisplayAll(Patients lib[]);
void Sort(Patients lib[]);
bool sortByID(Patients &a, Patients &b);
bool sortByName(Patients &a, Patients &b);
void report();

int main()
{
    Here:

    loadData(lib); //opening and reading the data from txt file "data.txt"

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
    bool found=false;
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
    	cout<<"\nPatient Found!\n";
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
    string id;
    string element;
    cout<<"\n Choose an option below: ";
    cout<<"\n [1] Search by Name\n[2] Search by ID\n";
    int chos;
    cout<<"Your choice: ";
    cin >> chos;
    if (chos==1)
    {
    	cout<<"Please enter the name of the patient you are looking for: "<<endl;
        getline(cin >>ws, name);
    	search(lib, name);
	}
	else if(chos==2)
	{
	    cout<<"Please enter the ID of the patient you are looking for: "<<endl;
        cin>>id;
        stringstream geek(id);
        int AyD=0;
        geek >> AyD;
		search(lib, AyD);
	}
	else
	{
		cout<<"\nWrong entry\n";
		exit(1);
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
    getline(cin >>ws, name);
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
    else if(chosi==2)
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
    else
	{
		cout<<"\nWrong entry\n";
		exit(1);
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
void search(Patients lib[], string x)
{
    int index;
    bool found;
    for(int i=0; i<Size; i++)
    {
        if(lib[i].name==x)
        {
            found=true;
            index=i;
            break;
        }
    }
    if (found==true)
    {
        cout<<"\nPatient Found!\n";
        cout<<"\nName:\t\t"<<lib[index].name<<endl;
        cout<<"ID:\t\t"<<lib[index].ID<<endl;
        cout<<"Age:\t\t"<<lib[index].age<<endl;
        cout<<"PhoneNumber:\t\t"<<lib[index].PhoneNumber<<endl;
        cout<<"Medicine:\t\t"<<lib[index].medicine<<endl;
        cout<<"Dose:\t\t"<<lib[index].dose<<endl;
    }
    else
    {
        cout<<"\nPatient not found.\n";
    }

}
void search(Patients lib[], int x)
{
    stringstream ss;
    ss << x;
    string id = ss.str();
    int index;
    bool found;
    for(int i=0; i<Size; i++)
    {
        if(lib[i].ID==id)
        {
            found=true;
            index=i;
            break;
        }
    }
    if (found==true)
    {
            cout<<"\nPatient Found!\n";
            cout<<"\nName:\t\t"<<lib[index].name<<endl;
            cout<<"ID:\t\t"<<lib[index].ID<<endl;
            cout<<"Age:\t\t"<<lib[index].age<<endl;
            cout<<"PhoneNumber:\t\t"<<lib[index].PhoneNumber<<endl;
            cout<<"Medicine:\t\t"<<lib[index].medicine<<endl;
            cout<<"Dose:\t\t"<<lib[index].dose<<endl;
    }
    else
    {
        cout<<"\nPatient not found.\n";
    }
    
}
