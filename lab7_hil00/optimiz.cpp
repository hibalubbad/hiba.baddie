#include <iostream>
using namespace std;

int binarySearch(int arr[], int l, int r, int size ){
if (r >= l) { 
        int mid = l + (r - l) / 2; 

        if (arr[mid] == size) 
            return mid; 
  

        if (arr[mid] > size) 
            return binarySearch(arr, l, mid - 1, size); 
  

        return binarySearch(arr, mid + 1, r, size); 
    } 
  

    return -1; 
}
int main()
{
    int arr[] = { 10, 43, 64, 3, 5 };
    int n = 5;
    int x = 10;
    int result = binarySearch(arr, 0, n - 1, x);
    (result == -1) ? printf("Element is not present in array")
    : printf("Element is present at index %d",
             result);
    return 0;
}
