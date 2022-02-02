#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <string>
using namespace std;

enum Menu {ADD=1, PRINT_ALL, PRINT_FLAVOR, EDIT, EXIT};

struct Node
{
    string title;
    int quantity;
    double cost;
};

void addItem(fstream &file);
void printAll(fstream &file);


int main()
{
    fstream datFile;
    datFile.open("elements.dat", ios::in | ios::out | ios::app | ios::binary);
    
    if(datFile.fail())
    {
        cout << "no file. creating...";
        datFile.open("elements.dat", ios::out);
    }
    else
    {
        cout << "file exists.";
    }
    datFile.close();

    int selection = 0;

    do{
            datFile.open("elements.dat", ios::in | ios::out | ios::app | ios::binary);
            cout << "\nChoose an Option...\n";
            cout << "1: Add items\n";
            cout << "2: Print All\n";
            cout << "3: Exit\n";
            cin >> selection;
            switch(selection){
                case ADD:{
                    addItem(datFile);
                    break;
                    }
                case PRINT_ALL: {
                    printAll(datFile);
                    break;
                }
                case EXIT: {
                    cout << "\nExiting..." << endl;
                    break;
                }
            }
        }while(selection != 3);

    datFile.close();

    return 0;
}

void addItem(fstream &file) 
{
    Node newNode = Node();
    
    cout << "Enter element one:" << endl;
    cin >> newNode.title;
    cout << "Enter element two:" << endl;
    cin >> newNode.quantity;
    cout << "Enter element three:" << endl;
    cin >> newNode.cost;

    //write temp structure to file
    file.write(reinterpret_cast<char *>(&newNode), sizeof(newNode));
    file.close();
    return ;
}

void printAll(fstream &file)
{
    Node list;

    cout << "\ndat file contents: " << endl;
    file.read(reinterpret_cast<char *>(&list), sizeof(list));
    
    while(!file.eof())
    {
        cout << setw(12) << list.title;
        cout << setw(12) << list.quantity;
        cout << setw(12) << setprecision(4) << list.cost << endl;

        file.read(reinterpret_cast<char *>(&list), sizeof(list));
    }

    file.close();
}