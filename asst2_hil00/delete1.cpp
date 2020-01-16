#include <iostream>
#include <string>
using namespace std;
void deleteRepeats(char a[],int &size)
{
    for(int i = 0; i<size;i++){
        for(int j=i+1;j<size;j++){
            if(a[i]== a[j]){
                for(int k= j; k<size;k++){
                    a[k] = a[k+1];             
                }
                size -=1;

            }
        }
    }
}

int main()
{
char a[10];
a[0] = 'a';
a[1] = 'l';
a[2] = 'a';
a[3] = 'c';
a[4]= 'a';
a[5]= 'b';
a[6] = 'f';
int size = 7;
cout<<"The original array: "<<endl;
int i = 0;
while( i < size){
    cout<< a[i] << " ";
    i++;
}
deleteRepeats(a, size);

cout<<"The new array without repeated characters: "<<endl;
for (int i=0; i<size; i++)
{
    cout<<a[i];
}
cout<<endl;
cout<<"The size of the new array: "<<size<<endl;
return 0; 

}