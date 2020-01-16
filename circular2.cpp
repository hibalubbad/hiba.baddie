#include <iostream>

using namespace std;

class CircArrayQueue{
private:
  int head;
  int tail;
  int* arr;
  int size;
public:
  CircArrayQueue(){
    head = 0;
    tail = 0;
    arr = new int[5];
    size = 5;

  }
  CircArrayQueue(int n){
    head = 0;
    tail = 0;
    arr = new int[n];
    size = n;
  }
  ~CircArrayQueue(){
    head = 0;
    tail = 0;
    delete arr;
  }
    CircArrayQueue(CircArrayQueue & a){
        size = a.size;
        arr = new int[size];
        for(int i=0; i<size;i++)
            arr[i]=a.arr[i];
    }
    CircArrayQueue operator =(CircArrayQueue & a){
        if(this!=&a){
            delete [] arr;
            size =a.size;
            arr = new int[size];
            for(int i=0; i<size;i++)
                arr[i]=a.arr[i];
            
        }
        return a;
    }
    
  void enqueue(int element){
    if (((tail - head)%size == -1)) {
      cout << "Queue is full"<<endl;
    } else {
      arr[tail] = element;
      tail++;
      tail = tail%size;
    }
  }
  int dequeue(){
    int element = arr[head];
    head = (head+1)%size;
    return element;
  }
  bool isEmpty(){
    return tail == head;
  }
  bool isFull(){
    return ((tail - head)%size == 1 || (tail - head)%size == -1);
  }
  int getHead(){
    return arr[head];
  }
  int getTail(){
    return arr[tail];
  }
  int getsize(){
    if (tail >= head)
      return tail-head;
    return (size-head)+tail;
  }
    string toString(){
        string list= "[";
        if(head<=tail){
            for(int i =0; i<tail;i++){
                list +=to_string(arr[i]);
                list+= ",";
            }
            list+= "]";
            
        }
        else{
            int i = head;
            while(i<size){
                list +=to_string(arr[i]);
                list+= ",";
                i++;
            }
            i=0;
            
            while(i<=tail){
                list +=to_string(arr[i]);
                list+= ",";
                i++;
            }
            list+= "]";
            
        }
        return list;
    }
};
int main(){
CircArrayQueue queue;
cout << queue.isEmpty() << endl;
queue.enqueue(5);
queue.enqueue(1);
 queue.enqueue(6);
 queue.enqueue(7);
cout<<queue.toString()<<endl;
int x = queue.dequeue();
queue.dequeue();
cout<<queue.toString()<<endl;
cout << queue.isFull() << endl; 
cout << queue.getsize() << endl; 
cout << queue.getHead() << endl; 
cout << queue.getTail() << endl; 
queue.enqueue(10);
cout<<queue.toString()<<endl;
cout << queue.isFull() << endl;
 cout << queue.getsize() << endl; 
cout << queue.getHead() << endl; 
cout << queue.getTail() << endl; 


    }
