/********************************************************************
***  NAME       :Neil Rolf                                        ***
***  CLASS      :CSc 300                                          ***
***  ASSIGNMENT :Program 2                                        ***
***  DUE DATE   :02/04/2022                                       ***
***  INSTRUCTOR :Kurtenbach                                       ***
*********************************************************************
***  DESCRIPTION :Stack ADT implemented with linked list giving   ***
***               user access to grocery item purchase history.   ***
********************************************************************/
#include "Stack.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

enum Menu {PRINT_PREV=1, PRINT_TOTAL, EXIT};

struct Node
    {
        string title;
        int quantity;
        double cost;
    };

int ingestData();
void printPrevious(int);
void printTotal(int);

double total = 0;
bool inToggle = 0;
string userFile;
GroceryStack GroceryList;

int main()
{
    //initial data ingest and user file name prompt
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
            case PRINT_PREV:{
                printPrevious(itemsCount);
                break;
                }
            case PRINT_TOTAL:{
                total = 0;
                printTotal(itemsCount);
                cout << "\n\nTotal cost of items purchased: $";
                cout << setprecision(2) << std::fixed << total << "\n\n";
                ingestData();
                break;
                }
            case EXIT:{
                cout << "\nExiting...\n";
                break;
                }
        }
    }while(selection != 3);

    //debug
    // cout << "Displaying all elements..." << endl;
    // GroceryList.view();

    return 0;
}

/********************************************************************
*** FUNCTION ingestData                                           ***
*********************************************************************
*** DESCRIPTION : displays all nodes in the stack                 ***
*** INPUT ARGS : none                                             ***
*** OUTPUT ARGS : none                                            ***
*** RETURN : number of items pushed to stack                      ***
********************************************************************/
int ingestData()
{
    //get file name from user
    if(inToggle == 0)
    {
        cout << "enter file name: \"file.dat\"" << endl;
        cin >> userFile;
        inToggle = 1;
    }
    
    //check for file
    ifstream infile;
    infile.open(userFile);
        if(!infile)
        {
            cout << "Error opening file." << endl;
            exit(102);
        }
    
    //read from file to temporary node, push from temp to stack
    Node tempNode;
    int count = 0;

    while(!infile.eof())
    {
        infile >> tempNode.title >> tempNode.quantity >> tempNode.cost;
        GroceryList.push(tempNode.title, tempNode.quantity, tempNode.cost);     
        count ++;
        infile.ignore();
        
    }
    
    infile.close();
    return count;
}

/********************************************************************
*** FUNCTION printPrevious                                        ***
*********************************************************************
*** DESCRIPTION : displays user defined number of entries from    ***
***               top of stack                                    ***
*** INPUT ARGS : number of elements in stack                      ***
*** OUTPUT ARGS : none                                            ***
*** RETURN : none                                                 ***
********************************************************************/
void printPrevious(int num)
{
    int selection = 0;
    int i=0;
    //user prompt for number of items
    cout << "The file contains " << num << " items." << endl;
    cout << "How many items would you like to view? (enter a whole number)" << endl;
    cin >> selection;
    if(selection > num)     //prevent reading beyond stack size
        selection = num;

    Node tempNode[selection];

    cout << "\nHere are the " << selection << " most recently purchased items.";
    cout << "\n____________________________________________________________\n\n";
    cout << setw(12) << std::left << "Item:" << setw(12) << "Quantity:" << setw(12) << "Cost:" << endl;

    //read selection from stack to array of temp structures for display
    for(i=0; i<selection; i++)
    {
        GroceryList.pop(tempNode[i].title, tempNode[i].quantity, tempNode[i].cost);
        cout << setw(12) << std::left << tempNode[i].title;
        cout << setw(12) << std::left << tempNode[i].quantity;
        cout << setw(12) << std::left << tempNode[i].cost << endl;
    }

    cout << "\n____________________________________________________________\n";

    //rebuild stack
    for(i=selection-1; i>-1; i--)
    {
        GroceryList.push(tempNode[i].title, tempNode[i].quantity, tempNode[i].cost);
    }
    return;
}

/********************************************************************
*** FUNCTION printTotal                                           ***
*********************************************************************
*** DESCRIPTION : calculates total value of items purchased       ***
***               in stack                                        ***
*** INPUT ARGS : number of elements in stack                      ***
*** OUTPUT ARGS : none                                            ***
*** RETURN : none                                                 ***
********************************************************************/
void printTotal(int num)
{
    //recursively reads elements from stack to temporary structure and sums total
    Node tempNode;
    if(num > 0)
        {
            GroceryList.pop(tempNode.title, tempNode.quantity, tempNode.cost);
            total += (tempNode.cost*tempNode.quantity);
            --num;
            printTotal(num);
        }
}