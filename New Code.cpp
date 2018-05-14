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
    bool Exp_Alert;
};

int end()
{
    return 0;
}

void print_format(void)
{
    cout
    << left << setw(20) << "Name"
    << setw(10) << "Location"
    << setw(8) << "Stock"
    << setw(8) << "Price"
    << setw(8) << "Freq"
    << setw(8) << "Alert"
    << setw(10) << "Exp"
    << setw(10) << "Exp_Alert" << endl;
}

void print_a_record(MedRec show)
{
    cout
    << left << setw(20) << show.Name
    << setw(10) << show.Location
    << setw(8) << show.Stock
    << setw(8) << show.Price
    << setw(8) << show.Freq
    << setw(8) << show.Alert
    << setw(10) << show.Exp
    << setw(10) << show.Exp_Alert << endl;
}

void save (MedRec medicines [], int count)
{
    ofstream file;
    file.open("MedicinesRecords.txt");
    for(int p =1; p <=count; p++)
    {
        file << medicines[p].Name<< " " 
            << medicines[p].Location << " " 
            << medicines[p].Stock<< " " 
            << medicines[p].Price<< " " 
            << medicines[p].Freq<< " " 
            << medicines[p].Alert<< " " 
            << medicines[p].Exp<< " " 
            << medicines[p].Exp_Alert<< endl;
    }
    file.close ();
}


void add_record (MedRec medicines[], int count)
{
    MedRec temp;
    string name;
    int location = count+1;
    int stock;
    double price;
    int freq = 0;
    bool alert = false;
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
    temp.Exp_Alert = exp_alert;
    medicines[location] = temp;
    save (medicines, count);

}

MedRec find_record(MedRec medicines[], int count)
{
    string input;
    cout << "Enter the name of the medicine" << endl;
    cin >> input;
    int check=0;
    for (int m = 1; m <= count; m++)
    {
        if(medicines[m].Name == input)
        {
        //cout << "Medicine has been found." << endl;
        check = 1;
        return medicines[m];
        //print_format(void);
        //print_a_record(medicines[m]);
        
        /*cout << "Name: " << medicines[m].Name<< endl  
            << "Location: " << medicines[m].Location << endl 
            << "Stock: " << medicines[m].Stock<< endl 
            << "Price: " << medicines[m].Price<< endl 
            << "Freq: " << medicines[m].Freq<< endl 
            << "Alert: " << medicines[m].Alert<< endl 
            << "Exp: " << medicines[m].Exp<< endl 
            << "Exp_Alert: " << medicines[m].Exp_Alert<< endl;
        */
        //return;
        }
        if (check == 0)
        {
            cout << "Can't find medicine!" << endl;
        }
        /*cout << m << count << endl;
        if (m==count)
        {
            cout << "Can't find student!" << endl;
        }
        else
        {
            continue;
        }*/
    }
}

void refill_med(MedRec medicines[], int count)
{
    MedRec med = find_record(medicines, count);
    int in_stock;
    double price;
    string exp;
    cout << "Enter the refill amount" << endl;
    cin >> in_stock;
    cout << "Enter the new expiry" << endl;
    cin >> exp;
    cout << "Enter the price per medicine" << endl;
    cin >> price;
    med.Stock += in_stock;
    med.Price = price;
    med.Exp = exp;
    medicines[med.Location] = med;
}
void delete_record(MedRec medicines[], int count)
{
    MedRec med = find_record(medicines, count);
    medicines[med.Location] = {};
}

void display_record(MedRec medicines[], int count)
{
    print_format();
    for(int i = 1; i<=count; i++)
    {
        print_a_record(medicines[i]);
    }
}

void dispense_medicines(MedRec medicines[], int count)
{
    int n;
    cout << "Enter the number of different medicines to dispence" << endl;
    cin >> n;
    MedRec order[n];
    int num[n];
    cout << "Enter the order" << endl;
    for (int i=0; i<n; i++)
    {
        order[i] = find_record(medicines, count);
        //cin >> order[i];
        cout << "Enter the number required" << endl;
        cin >> num[i];
    }
    for (int i=0; i<n; i++)
    {
        double fare = 0.0;
        if(order[i].Stock >= num[i])
        {
            order[i].Stock -= num[i];
            fare = order[i].Price * num[i];
            order[i].Freq += num[i];
            /*if(order[i].Stock <= 5)
            {
                order[i].Alert = true;
            }
            */ 
            //cout << order[i].Location << " " <<
            cout
            //<< left << setw(20) << order[i].Name
            << setw(10) << order[i].Location
            << setw(8) << order[i].Stock
            << setw(8) << order[i].Price
            << setw(10) << fare << endl;
            /*
            << setw(8) << order[i].Freq
            << setw(8) << order[i].Alert
            << setw(10) << order[i].Exp
            << setw(10) << order[i].Exp_Alert << endl;
            */
        }
        else
        {
            cout << "medicine stock is not sufficient" << endl;

        }
    }
}

void displayMenu(MedRec medicines[], int count)
{
    cout << "Medicines Records / Autopharm" << endl;
    cout << endl;
    cout << "Please Choose:" << endl;
    cout << "(1) Add a medicine record" << endl;
    cout << "(2) Refill a medicine" << endl;
    cout << "(3) Delete a medicine record" << endl;
    cout << "(4) Find a medicine's information" << endl;
    cout << "(5) Dispence a medicine" << endl;
    cout << "(6) Display all information in the database" << endl;
    cout << "(7) Exit Program" << endl;
    int input;
    cin >> input;
    MedRec med;
    
    while (input < 1 || input > 5)
    {
        cout << "You did not enter a correct choice!!" << endl;
            cin >> input;
    }
    switch(input)
    {
        case 1: add_record(medicines, count);
                //save(medicines, count);
                break;
        case 2: refill_med(medicines, count);
                break;
        case 3: delete_record(medicines, count);
                break;
        case 4: med = find_record(medicines, count);
                print_format();
                print_a_record(med);
                break;
        case 5: med = find_record(medicines, count);
                break;
        case 6: display_record(medicines, count);
                break;
        case 7: end ();
                break;
        //default: cout << "You did not enter a correct choice!!" << endl;
          //       break;
    }
}

int main()
{
char key;
MedRec medicines[10];
//read_a_record(medicines, count);
do
{
    displayMenu(medicines, count);
    cout << "To continue, Please press Y, otherwise any key to quit" << endl;
    cin >> key;
}
while(key =='Y' || key =='y');
{
return 0;
}

return 0;
}
