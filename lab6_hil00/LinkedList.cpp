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

bool LinkedList::empty() const{
        return (head==NULL);
}

int LinkedList::front() const {
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

void LinkedList::toString(){
    Node *v = head;
    cout<<"[";
    cout << v->elem;
    v= v->next;
    while (v!=NULL){
        cout << ","<< v->elem ;
        v=v->next;
    }
    cout<<"]";
    cout << endl ;
}
void LinkedList::printDuplicates(){
    Node*ptr = head;
    bool check = false;
    cout<< "the duplicates present in the list are:";
    while (ptr->next!=NULL){
        Node *cur = ptr->next;
        check = false;
        while(cur->elem == ptr->elem) {
            cur = cur->next;
            check = true;
        }
        if(check){
            cout << ptr->elem <<" ";
            check = false;
            
        }
        ptr = cur;
}
        cout<<endl;

}
void LinkedList::addEnd(int value){
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
void LinkedList::sortList(){
    if(head != 0)
    {
        Node* current = head;
        Node* prev = 0;
        Node* tempNode = 0;
        bool changeFlag = false;
        for (int i = 0; i < size(); i++)
        {
            while (current->next != 0)
            {
                tempNode = current->next;
                
                if (current->elem > tempNode->elem)
                {
                    changeFlag = true;
                    current->next = tempNode->next;
                    tempNode->next = current;
                    if (prev != 0)
                        prev->next = tempNode;
                    prev = tempNode;
                    if (head == current)
                        head = tempNode;
                    // if (current->next == 0)
                    //     end = current;
                }
                else
                {
                    prev = current;
                    current = current->next;
                }
            }
            if (changeFlag == false)
                break;
            else
            {
                prev = 0;
                current = head;
                changeFlag = false;
            }
        }
    }
}


void LinkedList::transferFrom(LinkedList *other){
    Node *v = other->head;
    Node *first = head;
    while(first->next != NULL)
        first = first->next;
    while (v!=NULL){
        first->next = new Node(v->elem);
        first = first->next;
        v= v->next;
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
void  LinkedList::removeValue(int val){
    Node *current = head;                
    if (head->elem==val){
        
        removeFront();
        current=head;
        } 
        else{
        while(current->next !=NULL){
            if(current->next->elem == val){
                Node* temp = current->next;
                current->next=current->next->next;
                delete temp; 
            }
            else
            current = current ->next;            
        }
    }
}

void LinkedList::reverse(){
    Node *current = head; 
    Node *prev = NULL, *next = NULL; 
    while(current != NULL){
        next = current->next; 
        current->next = prev; 
        prev = current; 
        current = next; 
        } 
        head = prev; 
}

bool LinkedList::checkRange(int max, int min){
     Node *current = head; 
     bool answer = 1; 
     while(current != NULL){
        if((current->elem<min)||(current->elem>max)){
            answer = 0; 
            break;

        }
        else{
            current =current->next; 
        }
    }
    return answer;
}
int LinkedList::EvenNodes(Node* head){
    if(head == NULL)
        return 0;
    else{
        if((head->elem)%2==0)
            return 1+ EvenNodes(head->next); 
        else{
            return EvenNodes(head->next); 
        }
    }
}
int LinkedList::OddNodes(Node* head){
    if(head == NULL)
        return 0;
    else{
        if((head->elem)%2!=0)
            return 1+ OddNodes(head->next);
        else{
            return OddNodes(head->next);
        }
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


