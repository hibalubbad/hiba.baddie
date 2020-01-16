#include <iostream>
#include <string>
#include <math.h>
using namespace std;

class complex{

    public:
    friend ostream& operator<<(ostream &os, const complex &c);
    friend istream& operator>>(ostream &os, complex &c);
        double real;
        double imaginery;
        complex(double real,double imaginery){
            this->real = real;
            this->imaginery= imaginery;
        }
        complex(){
            real = 0;
            imaginery= 0;
        }
        complex operator+( const complex & ) const;

};

ostream& operator<<(ostream &os,const complex &c){
            if(c.imaginery>0)
            os<< c.real<< "+"<<c.imaginery<<"i"<<endl;
            if(c.imaginery<0)
            os<< c.real<< c.imaginery<<"i"<<endl;
            return os;
}
istream & operator >> (istream &os, complex &c) 
{
    int real;
    int imag;
    char l;
    os >> real >> imag>>l; 
    c = complex(real,imag);
    return os; 
} 
complex complex::operator+( const complex &operand2 ) const
{
 return complex(real + operand2.real,imaginery + operand2.imaginery );
}

int main(){
    complex c1;
    complex c2;
    complex c3;
    cin>>c1; 
    cin>>c2; // sign of C2 should not be spaced away from c2 for proper input
    cout<< "C1 =";
    cout<< c1;
    cout<< "C2 =";
    cout<< c2;
    c3 = c1 + c2;
    cout<<"C3 = C1 +C2 = ";
    cout << c3;

}

