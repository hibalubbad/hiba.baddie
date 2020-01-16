#include "LinkedList.cpp"

int main()
{
    LinkedList my;
    LinkedList *other= new LinkedList; 
    other->addFront(1);
    other->addFront(2);
    other->addFront(3);    
    my.addFront(5);
    my.addFront(5);
    my.addFront(34);
    my.addFront(24);
    my.addEnd(13);
    my.showList();
    my.toString();
    my.removeValue(34);
    my.toString();
    my.printDuplicates();
    my.transferFrom(other);
    my.toString();
    my.reverse();   
    my.toString();
    Node *head= my.head; 
    cout<<my.checkRange(24, 2)<<endl;
    cout<<my.size()<< endl;
    cout<<my.EvenNodes(head)<< endl;
    cout<<my.OddNodes(head)<< endl;
    my.sortList();
    my.toString();


   return 0;
}