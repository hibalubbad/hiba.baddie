#include <iostream>
#include <string>
#include  <list>
#include <cstdio>
#include <algorithm>
#include <math.h>
#include <fstream>
#include <vector>
#include <sstream>
#include <unordered_map> 
using namespace std; 

int main(){
    string str;
    unordered_map<char, int> umap; 
    fstream fin;
    char ch;
    fin.open("words-4.txt");
    while(getline(fin,str)){
        for(int i =0 ; i<str.length();i++){
            ch = str[i];
            umap[ch]++;
        }
    unordered_map<char, int> :: iterator p;
    for(p = umap.begin(); p != umap.end(); p++)
        cout<< "("<< p->first<< ":"<<p->second<<")"<<endl;
    }
    return 0;
}


