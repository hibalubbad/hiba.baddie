#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string>
using namespace std;

int main(){

char q= ' ';

while (q== ' '){
int grade;
    vector <int> grades;
cout<<"Enter each grade and then -1 to stop."<<endl;
while (grade != -1){
cin>>grade;
grades.push_back(grade);
}
int max = *max_element(grades.begin(), grades.end());

int *gradearray= new int[max];

for (int i = 0; i < max+1; ++i){
    gradearray[i] = 0;
}  

for (int i=0; i<grades.size(); i++){
    int index= grades[i];
    gradearray[index]+=1;
}
for (int i=0; i<max+1; i++){
    cout<<gradearray[i]<<" grade(s) of "<<i<<endl;
}

delete [] gradearray;
cout<<"Enter a character to exit."<<endl;
cin>> q;
}

return 0;
}
