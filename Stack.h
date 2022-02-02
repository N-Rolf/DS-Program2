#ifndef _STACK_H
#define _STACK_H
#include <string>

typedef std::string SElement;

class Stack {
    public:
        Stack();
        //Stack( Stack & );
        ~Stack();
        //void ingestData();
        void push(SElement, int, double);
        void pop(SElement &, int &, double &);
        //int getSize();
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

//current 9:40 2.1.22