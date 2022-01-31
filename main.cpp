#include "Stack.h"
#include <iostream>
#include <fstream>
#include <iomanip>
//#include <cstdlib>
#include <cstring>
#include <string>
using namespace std;

void ingestData(fstream &file);
void addItem(fstream &file);

struct Node
{
    string title;
    int quantity;
    double cost;
};

int main()
{

    
    //get file name from user
    string userFile;
    cout << "enter file name: \"file.dat\"" << endl;
    //cin >> userFile;
    cout << "override..." << endl;
    userFile = "Items.dat";
    
    //dat file check
    fstream dataFile;
    dataFile.open(userFile, ios::in | ios::out | ios::app | ios::binary);
    
    if(dataFile.fail())
    {
        cout << "no file exists." << endl;
        dataFile.open("Items.dat", ios::out);
    }
    else
    {
        cout << "file exists.";
    }
    dataFile.close();
    
    Stack testStack;
    string catchItem;
    int catchQty;
    double catchPrice;
    
    dataFile.open("elements.dat", ios::in | ios::out | ios::app | ios::binary);
    addItem(dataFile);
    ingestData(dataFile);

    //cout << "Pushing..." << endl;
    //testStack.push(food, howMany, money);



    cout << "Displaying all elements..." << endl;
    testStack.view();

    // cout << "Popping..." << endl;
    // testStack.pop(catchItem, catchQty, catchPrice);
    // cout << "Popped items: " << catchItem << ", " << catchQty << ", " << catchPrice << endl;

    cout << "\n\nTest Complete." << endl;

    return 0;
}

void ingestData(fstream &file)
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