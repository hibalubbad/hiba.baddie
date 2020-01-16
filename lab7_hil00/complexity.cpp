#include <iostream>
using namespace std;
// a.
void function(int n) {
if (n == 1) return;
for(int i = 1; i <= n; i++) {
    for(int j = 1; j<= n; j++) {
    printf("*");
break; 
}
} 
}
// the complexity is n^2 because we are using 2 for loops of iterating from 1 till n

//b.

void function2(int n){
    int count=0;
    for (int i=n/2; i<=n; i++)
        for (int j=1; j<=n; j=2*j)
            for (int k=1; k<=n; k=k*2)
            count ++;
}
// n log^2n


void function3(int n){
    int count=0;
    for (int i=n/2; i<=n; i++)
        for (int j=1; j+n/2<=n; j++)
            for (int k=1; k<=n; k=k*2)
                count++;

}
// n/2 *n *n = n^2 logn


void function4(int n) {
    int count = 0;
    for(int i = 0; i < n; i++)
        for(int j = i; j < i*i; j++) 
            if (j%i == 0){
                for(int k = 0; k < j; k++)
                printf("*");
            }
}
// n*n^2*n^2 = n^5; because the second loop goes from 0 to n^2 so as the third loop ; 
