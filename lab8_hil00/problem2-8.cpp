#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

bool check(string file){
    fstream fin;
    fin.open(file);
    string symb;
    stack <char> my;
    while(getline(fin, symb)){
        for(int i=0;i<symb.length();i++){
            if(symb[i]== '['||'{'||'(')
                my.push(symb[i]);
            else{
            switch(symb[i]){
                case ']':
                    if(!my.empty() && my.top()=='[')
                        my.pop();
                    else{
                        return 0;
                    }
                    break;
                case '}':
                    if(!my.empty() &&my.top()=='{')
                        my.pop();
                    else{
                        return 0;
                    }
                    break;
                case ')':
                    if(!my.empty() &&my.top()=='(')
                        my.pop();
                    else{
                        return 0;
                    }
                    break;
            }
        
        }

        }
    if(my.empty()){
        return 1; 
    }
    else{
        return 0;
    }
}
}

int main(){
string file = "exp.txt";
cout<<check(file);
}