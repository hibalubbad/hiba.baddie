#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

int main(){
    stack <int> index;
    index.push(0);
    int price[]={100, 80, 60, 70, 60, 75, 85};
    int s= sizeof(price)/sizeof(price[0]);
    int *S= new int[s];
    S[0]= 1;
    for (int i=1; i<s;i++){
        while(price[index.top()]<=price[i])
            index.pop();
        if(index.empty()){
            S[i]= i+1;
        }
        else{
            S[i] = i-index.top();
        }
        index.push(i);

}
for(int i=0 ;i<s;i++){
    cout<<S[i]<<" ";
}
}