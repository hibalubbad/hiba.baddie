#include <iostream>
#include <string>
#include  <list>
#include  <vector>
#include <cstdio>
#include <algorithm>
#include <math.h>
#include <fstream>
#include <random>
#include <cstdlib>
#include "LinkedList.cpp"

using namespace std;
int Hash(string s){
    int hash = 0;
    int n = s.length();
    int a = 41;
for (int i = 0; i < n; i ++) 
	hash = a * hash + s[i];
return hash;
}
 int MAD(int N,int k){
     int y1=0;
     int y2= 1 + rand() % ( N);
     while(y1 % N ==0 || y1<1){
         y1 = 1 + rand() % ( N);
     }

    return abs(y1*k + y1)% N;
    cout<<y1<<endl<<y2<<endl;
 }

class hashset{
 
    private:
        int size;    
        int N;
        vector<LinkedList*> my;
        int collisions;
    public:
    
        hashset(){
            N = 997; 
            size = 0;
            my.resize(997);
        }
        int Size(){
            return size;
        }
        bool empty(){
            return Size()==0;
        }
        bool find(string s){
             int l = Hash(s);
             int h = MAD(N,l);
             if(my[h]== NULL)
                return 0;
            else{
                LinkedList *entry = my[h];
                return entry->get(s);
            }
        }
        bool insert(string s){
             int l = Hash(s);
             int h = MAD(N,l);
             if(my[h]==NULL){
                my[h] = new LinkedList;
                my[h]->addEnd(s);
                size++;
                return 1;
            }
            else{
                if(find(s)!=0){
                    return 0;
                 }
                 if(find(s)==0){ 
                    LinkedList *entry = my[h];
                    entry->removeEnd();
                    entry->addEnd(s);
                    size++;
                    collisions++; 
                    return 1;
                 }
             
            }
         return 0 ; 
        }

        bool remove(string s){
           int l = Hash(s);
            int h = MAD(N,h);
            if(find(s)!=0){
                return 0; 
            }
            else{
                LinkedList *entry = my[h];
                entry->removeValue(s);
                return 1;
                size--;
            }
            
        }

        int Collisions(){
            return collisions; 
        }



};
int main(){
// int h= Hash("trash");
// cout<<h<<endl;
// cout<<MAD(997, h)<<endl;
fstream fin;
string in;
fin.open("words-4.txt"); 
hashset dic;
cout<<dic.Size()<<endl;
// cout<<dic.find("whore")<<endl;
// cout<<dic.insert("whore")<<endl;
while(getline(fin,in)){
    cout<<dic.insert(in)<<endl;
}      

cout<<dic.Collisions()<<endl;

}