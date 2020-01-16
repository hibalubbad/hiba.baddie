#include <iostream>
using namespace std;
#include "Node.cpp"

class LinkedList {
    private:
    //    Node *head; // A pointer to element of type Node
        int evenNodes(Node *t, int index);
        int oddNodes(Node *t, int index);
    public:
           Node *head; // A pointer to element of type Node
         LinkedList();
         ~LinkedList();
        void addEnd(int value);// Adds the given value to the end of the list.
        void addFront(int value);// add to front of list./
        bool empty() const; // is list empty?
        int front() const; // get front element
        void removeFront(); // remove front item list
        void removeEnd(); //remove tail node
        int size();
        int get(int index); // Returns value in list at given index.
        void remove(int index); // Removes value at given index from list.
        void showList();
        void toString();
        void removeValue(int val);
        void printDuplicates();
        void transferFrom(LinkedList* other);
        void sortList();
        void reverse();
        int EvenNodes(Node* head);
        int OddNodes(Node* head);
        bool checkRange(int max, int min);


        
        
        

};