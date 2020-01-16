
#include <iostream>
#include <string>
using namespace std; 
 
class Node{
    protected:
    int val;
    Node *next;
    Node *prev;

    public:
    Node(int v){
        val=v;
        next=prev=NULL;
    }

    Node* getNext(Node*v){
        return v->next;
    }

    Node* getPrev(Node*v){
        return v->prev;
    }

    friend class Stack;
};
 
class Stack{
    public:
    Node *head,*tail,*middle;
    int count;

    Stack(){
        head=NULL;
        tail=NULL;
        middle=NULL;
        count=0;
    }

    void push(int v){
        if(head==NULL){
            head=new Node(v);
            tail=head;
        }
        else{
            Node* temp =new Node(v);
            temp->next=head;
            head->prev=temp;
            head=temp;
        }
        ++count;

        if(count==1){
            middle=head;
        }
        else{
            if(!(count&1)){
                middle=middle->prev;
            }
        }
    }
 
    void pop(){
        if(count==0){
            cout<<"Empty Stack!"<<endl;
            return;
        }

        Node* t=head;
        head=head->next;
        delete []t;
        count--;

        if(count==0){
            head=tail=middle=NULL;
            return;
        }
        if(count==1){
            middle=head;
        }
        else{
            if(count&1){
                middle=middle->next;
            }
        }
    }

    int findmiddle(){
        if(count==0){
            cout<<"Empty Stack!"<<endl;
            return -1;
        }
        else{
            return middle->val;
        }
    }

    void deletemiddle(){
        if(count==0){
            cout<<"Empty Stack!"<<endl;
            return;
        }
        count--;

        Node* temp=middle;
        if(count==0){
            delete []temp;
            head=NULL;
            tail=NULL;
            middle=NULL;
            return;
        }
        if((count&1)){
            middle=middle->next;
            if(temp->prev==NULL){
                head=middle;
                if(middle)middle->prev=NULL;
                delete []temp;
            }
            else{
                temp->prev->next=middle;
                if(middle)middle->prev=temp->prev;
                delete []temp;
            }
        }
        else{
            middle=middle->prev;
            middle->next=temp->next;
            if(temp->next!=NULL){
                temp->next->prev=middle;
            }
            delete []temp;
        }
    }
    void print(){
        if(head==NULL){
            cout<<"stack is empty\n";
            return;
        }
        for(Node* t=head;t!=NULL;t=t->next){
            cout<<t->val<<" ";
        }
        cout<<"\n";
    }
};
       
int main(){

    Stack* myStack = new Stack;
    myStack->push(12);
    myStack->push(40);
    myStack->push(1);
    myStack->push(21);
    myStack->push(9);
    myStack->push(13);
    cout<<"Middle Element is: "<<myStack->findmiddle()<<endl;
    myStack->deletemiddle();
    cout<<"Stack with the middle element deleted: ";
    myStack->print();
    cout<<endl;
    return 0;
}
