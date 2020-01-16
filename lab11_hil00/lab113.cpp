#include <iostream>
#include <string>
#include  <list>
#include <cstdio>
#include <algorithm>
#include <math.h>
#include <fstream>
#include <sstream>
#include <unordered_map> 
#include "LinkedList.cpp"
using namespace std; 

int hashh(int K,int N){
    return K % N; 
 }
void print(int inx,  LinkedList * arr){
    arr[inx].toString();
    cout<<endl;
    
}
int main(){
    int index;
    int num[10]= {1,2,4,6,7,2,4,3,5,8};
    LinkedList * arr= new LinkedList[10];
    for(int i = 0; i<10;i++){
        index= hashh(num[i],10); 
        arr[index].addEnd(num[i]);
    }
print(2,arr);
}