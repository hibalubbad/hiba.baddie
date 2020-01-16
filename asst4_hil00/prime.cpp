#include <iostream>
#include <string>
#include <vector>
using namespace std;

class PrimeNumber{

    private:
    int number;

    public:

        PrimeNumber(){
            number = 1;
        }

        PrimeNumber(int number){
            this->number = number;
        }

        int getnumber(){
            return number;
        }
        PrimeNumber operator++(){//Prefix version 
            ++number; 
            for(int i = 2; i <= number / 2; ++i){
                while(number % i == 0){
                    number +=1;
            }
            }
            return PrimeNumber(number);
        }
        PrimeNumber operator++(int ignoreMe){
            int temp= number;
            ++number; 
            for(int i = 2; i <= number / 2; ++i){
                while(number % i == 0){
                    number +=1;
            }
            }
            return PrimeNumber(temp);
        } //Postfix version
        PrimeNumber operator--(){
             --number; 
            for(int i = 2; i <= number / 2; ++i){
                while(number % i == 0){
                    number -=1;
            }
            }
            return PrimeNumber(number);
        } //Prefix version 
        PrimeNumber operator--(int){
             int temp= number;
            --number; 
            for(int i = 2; i <= number / 2; ++i){
                while(number % i == 0){
                    number -=1;
            }
            }
            return PrimeNumber(temp);
        } //Postfix version
};
int main(){
    int x;
    cin>>x;
    PrimeNumber you;
    PrimeNumber my(x);
    cout<<my.getnumber()<<endl;
    IntPair b = my++;
    cout<<b.getnumber()<<endl;
    IntPair c= my++;
    cout<<c.getnumber()<<endl;
    d= --my;
    cout<<d.getnumber()<<endl;
    IntPair e= ++my;
    cout<<e.getnumber()<<endl;
    return 0; 





}
