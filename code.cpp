#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <stdio.h>

using namespace std;

int count=0;
struct MedRec  
{
    string Name;
    int Location;
    int Stock;
    double Price;
    int Freq;
    bool Alert;
    string Exp;
    bool Exp_Alert
};

int end()
{
    return 0;
}

void add_record (MedRec medicines[10], int count)
{
MedRec temp;

string name;
int location = count;
int stock;
double price;
int freq = 0;
bool alert = false
string exp;
bool exp_alert = false;
if(location == 10)
{
    cout << "Error, array has been exceded!!" << endl;
    return;
}
count ++;

cout << "Please enter the medicine name" << endl;
    cin >> name;
    temp.Name = name;
    temp.Location = location;
cout << "Please enter the medicine name" << endl;
    cin >> stock;
    temp.Stock = stock;
cout << "Please enther the price of medicine" << endl;
    cin >> price;
    temp.Price = price;
    temp.Freq = freq;
    temp.Alert = alert;
cout << "Please enter the expiry date of medicine" << endl;
    cin >> exp;
    temp.Exp = exp;
    temp.Exp_Alert = exp_alert
students[location] = temp;

}

void save (MedRec medicines [], int count)
{
    ofstream file;
    file.open("MedicinesRecords.txt");
    for(int p =0; p <=limit; p++)
    {
        file << medicines[p].Name<< " " << medicines[p].Location << " " << medicines[p].Stock<< " " << medicines[p].Price<< " " << medicines[p].Freq<< " "<< students[p].Alert<< " " << students[p].Exp<< " " << medicines[p].Exp_Alert<< endl;
    }
    file.close ();
}

void displayMenu(MedRec medicines[10])
{
    cout << "Medicines Records / Autopharm" << endl;
    cout << endl;
    cout << "Please Choose:" << endl;
    cout << "(1) Add a medicine record" << endl;
    cout << "(2) Delete a medicine record" << endl;
    cout << "(3) Find a medicine's information" << endl;
    cout << "(4) Dispence a medicine" << endl;
    cout << "(4) Display all information in the database" << endl;
    cout << "(5) Exit Program" << endl;
    int input;
    cin >> input;
    
    while (input < 1 || input > 5)
    {
        cout << "You did not enter a correct choice!!" << endl;
            cin >> input;
    }
    switch(input)
    {
        case 1: add_record(medicines, count);
                save(medicines, count);
                break;
        case 2: delete_record;
                break;
        case 3: find_record(medicines);
                break;
        case 4: display_all(medicines);
                break;
        case 5: end ();
                break;
        //default: cout << "You did not enter a correct choice!!" << endl;
          //       break;
    }
}

int main()
{
//char key;
MedRec medicines[10];
//read_a_record(medicines, count);
do
{
    displayMenu(medicines);
    cout << "To continue, Please press Y, otherwise any key to quit" << endl;
    cin >> loop;
}
while(key =='Y' || key =='y');
{
return 0;
}

return 0;
}
