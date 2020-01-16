#include <iostream>
#include <string>
#include  <list>
#include <cstdio>
#include <algorithm>
#include <math.h>
#include <ctime>
#include <random>
#include <cstdlib>
using namespace std; 
bool randomBool() {
    return 0 + (rand() % (1 - 0 + 1)) == 1;
}

int main(){
    int size = 10;
    int count = 0;
     int a[size][size];
     int count2 = 0; 

    for(int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++){
            a[i][j] = randomBool();
             if(a[i][j]==1)
            count+=1; 
            if( a[i][j] == 0){
                j=-1;
                i++;
                if(i==size)
                break;
        }
        }
        }
         
        for(int i = 0; i < size; i++) {
		for(int j = 0; j < size; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
    cout<<"1's are :"<<count<<endl;
        for (int i = 0; i < size; i++)
    {
        int check = size/2;
        int nextLow = 0, nextHigh = size-1;
        while (!(a[i][check] == 1 && a[i][check+1] == 0) && (nextLow < nextHigh-1))
        {
            if (a[i][0] == 0)
            {
                check = -1;
                break;
            }
            else if (a[i][size-1] == 1)
            {
                check = size-1;
                break;
            }
            else if (a[i][check] == 1)
            {
                nextLow = check;
                check = (check + nextHigh)/2;
            }
            else
            {
                nextHigh = check;
                check = (check + nextLow)/2;
            }
        }
        count2 = count2 + check + 1;
    }
    cout<<"1's are :"<<count2<<endl;

   
}