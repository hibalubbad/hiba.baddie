#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int arr[]={1,2,3,4,5,12,6,33,45,7,23,8,9,11,10};
    int size = 15;
    sort(arr,arr+size,greater<int>());
    for(int i=0; i<10;i++){
        cout<<arr[i]<<";";
    }
    // int max= arr[0];
    // int newarr[10];
    // int j=0;
    // for(int i; i<=size;i++){
    //     if(arr[i]>*max_element(arr,arr+(size))){
    //         newarr[j]=i;
    //         j++;
    //     }
    // }
    return 0;
}