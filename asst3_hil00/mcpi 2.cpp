#include <iostream>
#include <string>
#include <math.h>
#include <random>
using namespace std;

int main(){
long n;
int count =0;
cin >> n;
for(int i=0; i<=n; i++){
    double x = (double)rand() / (double)RAND_MAX;
    double y = (double)rand() / (double)RAND_MAX;
    if(pow(x,2) + pow(y,2) <= 1){
        count +=1;
    }
}
double pi = (double(count)/ double(n))*4;

cout<<pi;
}

