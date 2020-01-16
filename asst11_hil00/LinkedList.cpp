#include <iostream>
using namespace std;
#include "LinkedList.h"


LinkedList::LinkedList(){
    head = NULL;
}

LinkedList::~LinkedList(){
    while (!empty()) removeFront();
}


bool LinkedList::empty() const{
        return (head==NULL);
}

string LinkedList::front() const {
    return head->elem;
}

void LinkedList::removeFront(){
        Node *v = head;
        head = head->next;
        delete v;
        v=NULL;
}

void LinkedList::showList(){
        Node *v = head;
        while (v!=NULL){
            cout << v->elem << " ";
            v=v->next;
        }
        cout << endl ;
}

void LinkedList::addEnd(string value){
        Node *v = new Node(value);
        if (head==NULL) head=v;
        else{    
            Node *current =  head;
            while (current->next!=NULL){
                current=current->next;
            }
            current->next=v;
        }
}

void LinkedList::removeEnd(){
        if (head->next==NULL) 
                removeFront();
        else{    
            Node *v =  head;
            while (v->next->next!=NULL){
                v=v->next;
            }
            delete v->next;
            v->next = NULL;
        }
        
}

int LinkedList::size(){
        int count = 0;
        Node * current = head;
       while( current != NULL) {
		current = current->next;
		count++;
       }
        return count;
}

void LinkedList::toString(){
	Node *v = head;
    if (empty()){
        cout<<"[]"<<endl;
    }
    else{
	cout << "[";
	while (v -> next!= NULL){
		cout << v->elem << ",";
		v = v->next;
    }
    cout<<v->elem;
	cout << "]" << endl;
    }
}
bool LinkedList::get(string s){
    Node * v= head;
    while (v->next!=NULL){
        if(v->elem == s)
            return 1;
        else
            v=v->next;
    }
    return 0;
}

void LinkedList::removeValue(string val){
    Node *v = head;
    if (head->elem==val){
        removeFront();
        v=head;
    } 
    while (v->next!=NULL){
        if (v-> next->elem==val){
            Node* temp = v->next;
            v->next=v->next->next;
            delete temp;
        }
        else{
            v=v->next;
        }}
}

void LinkedList::printDuplicates(){
    Node *v = head;
    while (v->next!=NULL){
        if (v->elem==v->next->elem){
            cout<<v->elem<<endl;
        }
        v=v->next;
    }
}


