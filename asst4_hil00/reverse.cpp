#include <iostream>
#include <string>
#include <vector>
using namespace std;


int main(){
    string str;
    char *head,*tail,*cstr;
    cout << "Enter a string: ";  
    getline(cin, str); 
    cstr = new char[str.size() + 1];
    strcpy(cstr, str.c_str());
    head = &cstr[0];  
    tail = &cstr[str.size()- 1];  
    char temp;
    cout << "String inverted is: ";

    while(head <= tail){
        temp = *head;
        head= *tail;
        *tail= temp;
        tail--;
        head++;
    }
    cout << cstr;
    cout <<"\n";
    return 0;
     
}
