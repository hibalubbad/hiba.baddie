#include <iostream>
using namespace std;
#include "LinkedList.h"


LinkedList::LinkedList(){
    head = NULL;
}

LinkedList::~LinkedList(){
    while (!empty()) removeFront();
}

void LinkedList::addFront(int value){
        Node *v = new Node(value);
        v->next = head;
        head = v;
}
void LinkedList::push(int element){
    addFront(element);
}

bool LinkedList::empty() {
        return (head==NULL);
}

int LinkedList::front()  {
    return head->elem;
}

void LinkedList::removeFront(){
        Node *v = head;
        head = head->next;
        delete v;
        v=NULL;
}

void LinkedList::pop(){
    removeFront();
}
int LinkedList::seek(){
    return front();
}

int main(){
    LinkedList my;
    LinkedList *other= new LinkedList;    
    my.push(5);
    my.push(19);
    my.push(34);
    my.push(24);
    my.pop();
    cout<<my.seek()<<endl;
    cout<<my.empty();
}

 



