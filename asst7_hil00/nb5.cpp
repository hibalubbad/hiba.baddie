#include <iostream>
#include <string>
using namespace std;

void swap(int arr[], int i, int j){
    int  temp= arr[i];
    arr[i]=arr[j];
    arr[j]= temp;
}

void sort(int *arr, int size){
    for (int i=0; i<size; i++){
        if (arr[i]>arr[i+1]){
            swap(arr, i, i+1);
        }
    }
    if (size-1>1){
        sort(arr,size-1);
    }
}

int main(){
    int arr[]={3,12,7,24,5,23};
    int size=6;
    sort(arr,size);
    cout<<"{";
    for (int i=0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<'}'<<endl;
    return 0;
}