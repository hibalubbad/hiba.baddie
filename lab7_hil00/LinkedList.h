#include <iostream>
using namespace std;
#include "Node.cpp"

class LinkedList {
    private:
    //    Node *head; // A pointer to element of type Node

    public:
           Node *head;
            // A pointer to element of type Node
         LinkedList();
         ~LinkedList();
        void addFront(int value);// add to front of list./
        void push(int value);
        void pop();
        int seek();
        bool empty() ; // is list empty?
        int front() ; // get front element
        void removeFront(); // remove front item list
        void remove(int index); // Removes value at given index from list.
     


        
        
        

};