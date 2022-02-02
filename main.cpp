#include "Stack.h"
#include <iostream>
#include <fstream>
#include <iomanip>
//#include <cstdlib>
#include <cstring>
#include <string>
using namespace std;

void ingestData();

Stack GroceryList;

int main()
{

    

    
    string catchItem;
    int catchQty;
    double catchPrice;
    

    ingestData();

    cout << "Displaying all elements..." << endl;
    GroceryList.view();

    cout << "Popping..." << endl;
    GroceryList.pop(catchItem, catchQty, catchPrice);
    cout << "Popped items: " << catchItem << ", " << catchQty << ", " << catchPrice << endl;

    cout << "\n\nTest Complete." << endl;

    return 0;
}

void ingestData()
{
    //get file name from user
    string userFile;
    cout << "enter file name: \"file.dat\"" << endl;
    //cin >> userFile;
    cout << "override..." << endl;
    userFile = "Items.dat";
    
    ifstream infile;
    infile.open(userFile);
        if(!infile)
        {
            cout << "Error opening file." << endl;
            exit(102);
        }
    
    struct Node
        {
            string title;
            int quantity;
            double cost;
        };

    
    Node tempNode;

    while(getline(infile, tempNode.title))
    {
        infile >> tempNode.quantity >> tempNode.cost;
        infile.ignore();
        GroceryList.push(tempNode.title, tempNode.quantity, tempNode.cost);
    }
    infile.close();
    
}

//current 9:40 2.1.22