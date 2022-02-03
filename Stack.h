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
#ifndef _STACK_H
#define _STACK_H
#include <string>

typedef std::string SElement;

class GroceryStack {
    public:
        GroceryStack();
        ~GroceryStack();
        void push(SElement, int, double);
        void pop(SElement &, int &, double &);
        void view();
    private:    
        struct StackNode 
        {
            SElement title;
            int quantity;
            double cost;
            StackNode *next;
        };
        StackNode *top;
};
#endif