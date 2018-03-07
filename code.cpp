#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <stdio.h>

using namespace std;

struct MedRec  
{
    string Name;
    string location;
    double price;
    int freq;
    int alert;
    
};

void displayMenu(MedRec medicines[100])
{
    cout << "Medicines Records / Autopharm" << endl;
    cout << endl;
    cout << "Please Choose:" << endl;
    cout << "(1) Add a medicine record" << endl;
    cout << "(2) Delete a medicine record" << endl;
    cout << "(3) Find a medicine's information" << endl;
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
        case 1: addsrecord(medicines);
                save(medicines);
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
MedRec medicines[100];
read_a_record(medicines);
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
