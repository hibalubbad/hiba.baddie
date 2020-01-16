#include <iostream>
#include <math.h>
using namespace std;

double standarddev(double a[], int position){
    double sum=0;
    for (int i=0; i<position; i++){
        sum += a[i];
    } 
    double average= sum/position;
    double standarddev=0;
    for (int i=0; i<position; i++){
        standarddev += pow(a[i] - average, 2);
    }
    double s= sqrt(standarddev/position);
    return s;
}                  

int main(){
    int position= 10;
    double inarray[10];
    char y= 'Y';
    while(y == 'Y' || y == 'y'){
    cout<<"Enter 10 values, separated by white space, Terminated each with <cr>. I will compute the standard deviation."<<endl;
    for(int i = 0; i < position; i++){
    cin >> inarray[i];
    }

    cout<<"The Standard Deviation is: "<<standarddev(inarray, position)<<endl;;
    cout<< "Y/y continues, any other quits."<<endl;
    cin>>y;
    }
    return 0;
}
