/********************************************************************
***  NAME       :Neil Rolf       ***
***  CLASS      :CSc 300         ***
***  ASSIGNMENT :Assignment 3    ***
***  DUE DATE   :10/04/2021      ***
***  INSTRUCTOR :  GAMRADT       ***
*********************************************************************
***  DESCRIPTION :Stack ADT implemented with linked list   ***
********************************************************************/
#include "Stack.h"
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
using namespace std;


/********************************************************************
*** FUNCTION Stack                                           ***
*********************************************************************
*** DESCRIPTION : the default constructor for Stack class    ***
*** INPUT ARGS : none                                             ***
*** OUTPUT ARGS : none                                            ***
*** IN/OUT ARGS : none                                            ***
*** RETURN : none                                                 ***
********************************************************************/
Stack::Stack ()
{
    top = nullptr;
}

/********************************************************************
*** FUNCTION Stack (const Stack & old)                  ***
*********************************************************************
*** DESCRIPTION : the copy constructor for Stack class       ***
*** INPUT ARGS : pointer to a Stack object                   ***
*** OUTPUT ARGS : none                                            ***
*** IN/OUT ARGS : none                                            ***
*** RETURN : none                                                 ***
********************************************************************/
// Stack::Stack (Stack & old)
// {
//     StackNode * oldNodePtr;
//     top = nullptr;

//     oldNodePtr = old.top;
//     while (oldNodePtr != nullptr)
//     {
//         push(oldNodePtr->element);
//         oldNodePtr = oldNodePtr->next;
//     }
//     return;
// }

/********************************************************************
*** FUNCTION ~Stack                                          ***
*********************************************************************
*** DESCRIPTION : the destructor for Stack class             ***
*** INPUT ARGS : none                                             ***
*** OUTPUT ARGS : none                                            ***
*** IN/OUT ARGS : none                                            ***
*** RETURN : none                                                 ***
********************************************************************/
Stack::~Stack()
{
    StackNode * np;
    cout << "\ndestroying the list\n";

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
*** INPUT ARGS : element                                          ***
*** OUTPUT ARGS : none                                            ***
*** IN/OUT ARGS : none                                            ***
*** RETURN : none                                                 ***
********************************************************************/
void Stack::push(SElement title, int quantity, double cost)
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
*** INPUT ARGS : element                                          ***
*** OUTPUT ARGS : none                                            ***
*** IN/OUT ARGS : none                                            ***
*** RETURN : none                                                 ***
********************************************************************/
void Stack::pop(SElement & catchTitle, int & catchQuantity, double & catchCost )
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
*** FUNCTION peek                                                 ***
*********************************************************************
*** DESCRIPTION : displays the list node at top of the stack      ***
*** INPUT ARGS : element                                          ***
*** OUTPUT ARGS : none                                            ***
*** IN/OUT ARGS : none                                            ***
*** RETURN : none                                                 ***
********************************************************************/
// void Stack::peek(double & catchElem)
// {
//     struct StackNode* temp;

//     catchElem = top->element;
//     temp = top;
//     cout << temp->element << endl;
   
//     return;
// }

/********************************************************************
*** FUNCTION view                                                 ***
*********************************************************************
*** DESCRIPTION : displays all nodes in the stack                 ***
*** INPUT ARGS : none                                             ***
*** OUTPUT ARGS : none                                            ***
*** IN/OUT ARGS : none                                            ***
*** RETURN : none                                                 ***
********************************************************************/
void Stack::view()
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

