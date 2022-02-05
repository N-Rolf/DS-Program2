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
                //user prompt for number of items
                int selection = 0;
                cout << "The file contains " << itemsCount << " items." << endl;
                cout << "How many items would you like to view? (enter a whole number)" << endl;
                cin >> selection;
                if(selection > itemsCount)     //prevent reading beyond stack size
                    selection = itemsCount;

                GroceryList.setSelection(selection);
                GroceryList.peek();
                break;
                }
            case PRINT_TOTAL:{
                double newTotal = 0;
                newTotal = GroceryList.total();
                cout << "\n\nTotal cost of items purchased: $";
                cout << setprecision(2) << std::fixed << newTotal << "\n\n";
                break;
                }
            case EXIT:{
                cout << "\nExiting...\n";
                break;
                }
        }
    }while(selection != 3);

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
    cout << "enter file name: \"file.dat\"" << endl;
    cin >> userFile;

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
