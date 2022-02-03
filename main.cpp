#include "Stack.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

int ingestData();
void printPrevious(int);
void printTotal(int);

struct Node
    {
        string title;
        int quantity;
        double cost;
    };

double total = 0;
bool inToggle = 0;
string userFile;
Stack GroceryList;

int main()
{
    //data ingest and user file name prompt
    int itemsCount = ingestData();
    
    //USER MENU
    int selection = 0;
    do{
        cout << "\nChoose an Option...\n";
        cout << "1: Print previous items.\n";
        cout << "2: Display total purchases value. \n";
        cout << "3: Exit. \n";
        cin.clear();
        cin >> selection;
        switch(selection){
            case 1:{
                printPrevious(itemsCount);
                break;
                }
            case 2:{
                total = 0;
                printTotal(itemsCount);
                cout << "Total cost of items purchased: $" << total << endl;
                ingestData();
                break;
                }
            case 3:{
                cout << "\nExiting...\n";
                break;
                }
        }
    }while(selection != 3);

    cout << "Displaying all elements..." << endl;
    GroceryList.view();

    return 0;
}

int ingestData()
{
    //get file name from user
    cout << "enter file name: \"file.dat\"" << endl;
    if(inToggle == 0)
    {
        cin >> userFile;
        inToggle = 1;
    }
    
    ifstream infile;
    infile.open(userFile);
        if(!infile)
        {
            cout << "Error opening file." << endl;
            exit(102);
        }
    
    Node tempNode;
    int count = 0;

    while(!infile.eof())
    {
        infile >> tempNode.title >> tempNode.quantity >> tempNode.cost;
        // cout << "Title: " << tempNode.title << endl;
        // cout << "Quantity: " << tempNode.quantity << endl;
        // cout << "Cost: " << tempNode.cost << endl;
        // cout << "Count: " << count << endl;
        // cout << "\nPushing...\n";
        GroceryList.push(tempNode.title, tempNode.quantity, tempNode.cost);     
        count ++;
        infile.ignore();
        
    }
    
    infile.close();
    return count;
}

void printPrevious(int num)
{
    string catchItem;
    int catchQty;
    double catchPrice;
    int selection = 0;
    int i=0;
    cout << "The file contains " << num << "items." << endl;
    cout << "How many items would you like to view? (enter a whole number)" << endl;
    cin >> selection;
    if(selection > num)
        selection = num;

    Node tempNode[selection];

    //read selection from stack
    for(i=0; i<selection; i++)
    {
        cout << "Popping..." << endl;
        GroceryList.pop(tempNode[i].title, tempNode[i].quantity, tempNode[i].cost);
        cout << "Popped items: " << tempNode[i].title << ", " << tempNode[i].quantity << ", " << tempNode[i].cost << endl;
    }

    //rebuild stack
    for(i=selection-1; i>-1; i--)
    {
        GroceryList.push(tempNode[i].title, tempNode[i].quantity, tempNode[i].cost);
    }
    return;
}

void printTotal(int num)
{
    Node tempNode;
    if(num > 0)
        {
            GroceryList.pop(tempNode.title, tempNode.quantity, tempNode.cost);
            // cout << "Title: " << tempNode.title << endl;
            // cout << "Quantity: " << tempNode.quantity << endl;
            // cout << "Cost: " << tempNode.cost << endl;
            total += (tempNode.cost*tempNode.quantity);
            --num;
            printTotal(num);
        }
}