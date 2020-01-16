#include <iostream>
#include <algorithm>
using namespace std;

bool pairsum(int arr[],int size,int k,int r,int l){
    if(l==r)
        return 0;
    if(arr[l] + arr[r] <k) 
        return pairsum(arr,size,k,r,l+1); 
    else if(arr[l] + arr[r] > k) 
        return pairsum(arr,size,k,r-1,l); 
    else 
        return 1; 

}

int main(){
    int arr[] = {1,2, 3, 4,9, 10, 40 }; 
    int size = sizeof(arr) / sizeof(arr[0]); 
    int k = 10; 
    int z = 13;
    cout << boolalpha << pairsum(arr, size,k, size - 1, 0) << endl 
        << pairsum(arr, size,z, size - 1, 0);
}


