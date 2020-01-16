#include <iostream>
#include <algorithm>
#include <array>       
#include <random> 
#include <ctime> 
#include <string>
using namespace std;
template <class T>
T getMinimum(T arr[],int size){
    return *min_element(arr,arr+size);

    }
template <class T>
int indexOf(T arr[],int size, T element){
    for(int i=0;i<size;i++){
        if(arr[i] == element)
            return i;
}
    return -1;
}
template <class T>
T *shuffleArray(T arr[],int size){
    T *sharr= new T[size];
    memcpy(sharr, arr, sizeof(T)*size);
    random_shuffle (sharr, sharr+size);
    return sharr; 
}
template <class T>
void printArray(T arr[],int size){
    for(int i=0;i<size;i++){
        cout<< arr[i]<<" ";
    }
    cout<<endl;
}
template <class T>
void reverseArray(T arr[],int size){
    reverse(arr,arr+size);
}
template <class T>
T *sortArray(T arr[],int size,bool ascending, bool inPlace){
    if(inPlace){
        if(ascending)
            sort(arr,arr+size);
        else{
            sort(arr,arr+size);
            reverseArray(arr,size);
        }
    }
    return arr; 
}
int main(){
    int size = 10;
    int arr[]= {1,4,7,22,43,2,9,30,98,16};
    cout<<getMinimum(arr,size)<<endl;
    cout<<indexOf(arr,size,43)<<endl;
    printArray(arr,size);
    shuffleArray(arr,size);
    printArray(shuffleArray(arr,size),size);
    sortArray(arr,size,true,true);
    printArray(sortArray(arr,size,false,true),size);
    int stringsize = 5;
    string stringarr[] = {"kourt","lama","string","hop","can"};
    string element = "kourt";
    cout<<getMinimum(stringarr,stringsize)<<endl;
    cout<<indexOf(stringarr,stringsize,element)<<endl;
    printArray(stringarr,stringsize);
    shuffleArray(stringarr,stringsize);
    printArray(shuffleArray(stringarr,stringsize),stringsize);
    sortArray(stringarr,stringsize,true,true);
    printArray(sortArray(stringarr,stringsize,false,true),stringsize);


    return 0;
}