
#include <iostream>
#include <string>
using namespace std;

template <class T>
T sum(T a[],int size){
    T count = 0;
    for(int i=0;i<size;i++){
        count = count+a[i];
    }
    return count;
}

class student {
public:
student(int a) : age(a) {} 
student operator+(student &other){
    return (age+ other.age);
}
int getAge(){
    return age;
}
private:
int age; 
};

ostream& operator<<(ostream &os, student c){
    os<< c.getAge()<<endl;
    return os;
}

int main(){
    int a[] = {1,2,3,4};
    float b[] = {1.2,3.4,6.7};
    student x(21);
    student y(20);
    student z(22);
    student arr[] = {z,y,x};
    cout << sum(a,4) << endl; 
    cout << sum(b,3) << endl; 
    cout<<sum(arr,3); 

}