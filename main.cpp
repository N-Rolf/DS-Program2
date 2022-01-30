#include "Stack.h"
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>

using namespace std;

int main()
{
    Stack testStack;

    struct example
    {
        string item = "pizza";
        int qty = 1;
        double price = 7.99;
    };
    
    string food = "pasta";
    int howMany = 2;
    double money = 15.50;


    cout << "Pushing: Pizza, 1, 7.99..." << endl;
    testStack.push(food, howMany, money);

    string catchItem;
    int catchQty;
    double catchPrice;

    cout << "Displaying all elements..." << endl;
    testStack.view();

    cout << "Popping..." << endl;
    testStack.pop(catchItem, catchQty, catchPrice);
    cout << "Popped items: " << catchItem << ", " << catchQty << ", " << catchPrice << endl;

    cout << "Displaying all elements..." << endl;
    testStack.view();

    cout << "\n\nTest Complete." << endl;

    return 0;
}