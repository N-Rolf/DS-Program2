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
#include <string>
using namespace std;

/********************************************************************
*** FUNCTION Stack                                                ***
*********************************************************************
*** DESCRIPTION : the default constructor for Stack class         ***
*** INPUT ARGS : none                                             ***
*** OUTPUT ARGS : none                                            ***
*** IN/OUT ARGS : none                                            ***
*** RETURN : none                                                 ***
********************************************************************/
GroceryStack::GroceryStack ()
{
    top = nullptr;
}

/********************************************************************
*** FUNCTION ~Stack                                               ***
*********************************************************************
*** DESCRIPTION : the destructor for Stack class                  ***
*** INPUT ARGS : none                                             ***
*** OUTPUT ARGS : none                                            ***
*** IN/OUT ARGS : none                                            ***
*** RETURN : none                                                 ***
********************************************************************/
GroceryStack::~GroceryStack()
{
    StackNode * np;
    //cout << "\ndestroying the list\n";

    np = top;
    while (np != nullptr)
    {
        //cout << "deleting" << np->element << " node" << endl;
        top = top->next;
        delete np;
        np = top;
    }
    top = nullptr;
}

/********************************************************************
*** FUNCTION push                                                 ***
*********************************************************************
*** DESCRIPTION : inserts a list node at top of the stack         ***
*** INPUT ARGS : elements                                         ***
*** OUTPUT ARGS : none                                            ***
*** IN/OUT ARGS : none                                            ***
*** RETURN : none                                                 ***
********************************************************************/
void GroceryStack::push(SElement title, int quantity, double cost)
{
    struct StackNode* temp;
    temp = new StackNode();

    temp->title = title;
    temp->quantity = quantity;
    temp->cost = cost;
    temp->next = top;
    top = temp;
}

/********************************************************************
*** FUNCTION pop                                                  ***
*********************************************************************
*** DESCRIPTION : deletes a list node at top of the stack         ***
*** INPUT ARGS : elements                                         ***
*** OUTPUT ARGS : none                                            ***
*** IN/OUT ARGS : none                                            ***
*** RETURN : none                                                 ***
********************************************************************/
void GroceryStack::pop(SElement & catchTitle, int & catchQuantity, double & catchCost )
{
    struct StackNode* temp;

    if(top!=nullptr)
    {
        catchTitle = top->title;
        catchQuantity = top->quantity;
        catchCost = top->cost;
        temp = top;
        top = top->next;
        temp->next = nullptr;
    }
    return ;
}

/********************************************************************
*** FUNCTION view                                                 ***
*********************************************************************
*** DESCRIPTION : displays all nodes in the stack                 ***
*** INPUT ARGS : none                                             ***
*** OUTPUT ARGS : none                                            ***
*** IN/OUT ARGS : none                                            ***
*** RETURN : none                                                 ***
********************************************************************/
void GroceryStack::view()
{
    struct StackNode* temp;

    temp = top;
    cout << "TOP->";
    while(temp!=nullptr)
    {
        cout << temp->title << "->";
        cout << temp->quantity << "->";
        cout << temp->cost << "->";
        temp = temp->next;
    }
    cout << "BOTTOM" << endl;
}
