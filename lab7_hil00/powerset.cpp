#include <iostream>
#include <string>
using namespace std;

void powerset(string str,int index = -1,string curr = "")
{
    int n = str.length(); 
    if (index == n) 
        return; 
  
    cout << curr << " "; 
  

    for (int i = index + 1; i < n; i++) { 
  
        curr += str[i]; 
        powerset(str, i, curr); 

        curr.erase(curr.size() - 1); 
    } 
    return; 

    }

int main() 
{ 
    string str = "abc"; 
    powerset(str); 
    return 0; 
} 
