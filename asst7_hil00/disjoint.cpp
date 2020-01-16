#include <iostream>
#include <algorithm>
#include <set>
#include <iterator>
using namespace std;
int binarySearch(int arr[], int left, int right, int x) { 
    if (right >= left) { 
        int mid = left + (right - left) / 2; 

        if (arr[mid] == x) 
            return mid; 
        if (arr[mid] > x) 
            return binarySearch(arr, left, mid - 1, x); 
        return binarySearch(arr, mid + 1, right, x); 
    } 
    return -1; 
} 
bool areDisjoint(int s1[], int s2[], int s3[],int size1,int size2,int size3){ 


    int x = -1, y = -1;

    for (int i = 0; i < size1; i++){
            x = binarySearch(s2, 0, size2, s1[i]);
            y = binarySearch(s3, 0, size3, s1[i]);
            if (x >= 0 && y >= 0){
                return true;
            }
    }
    return false;
}
int main(){
    int s1[]= {1,2,3};
    int s2[]={7,9,2};
    int s3[]={17,19,2};
    int size1 = sizeof(s1) / sizeof(s1[0]);  
    int size2 = sizeof(s2) / sizeof(s2[0]); 
    int size3 = sizeof(s3) / sizeof(s3[0]); 

    sort(s1,s1+size1); 
     sort(s2,s2+size2); 
    sort(s3,s3+size3);  
    cout<<areDisjoint(s1,s2,s3,size1,size2,size3)<<endl;

}