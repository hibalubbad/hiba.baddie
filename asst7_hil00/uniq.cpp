#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool uniq(vector <int> v,int i,int j){
    if(i>=j)
        return 1;
    else {
        for(int k = i+1;k<=j;k++){
            if(v[k]==v[i])
                return 0;
            else{
                return uniq(v,i+1,j);
            }
        }
    }
    return 0;
}
int main(){
    vector <int> v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(3);
    v.push_back(1);
    v.push_back(3);
    v.push_back(2);
    v.push_back(1);
    cout<<uniq(v,5,6)<<endl;
}
// the problem is of complexity O(n) but could be of O(logn) if binary search was used instead of linear. 