#include <iostream>
using namespace std;
int gcd(int x, int y){
       while(x != y){
            if (x > y)
                x = x - y;
            else if (x < y)
                y = y -x;
       }
        return x;

}
class Fraction{
    public:
        int num;
        int denom;
        Fraction(int num,int denom){
            this->num= num;
            this->denom = denom;
        }
    void display()   {
         cout<< num << "/" << denom;
    }
    void setnum(int num){
        this->num = num;
    }
    void setdenom(int denom){
        this->denom = denom;
    }

    double getdouble(int num){
        double division = (double)num/(double)denom;
        return division;
    }
    

    Fraction simplify(){
        int divisor = gcd(this->num, this->denom);
        this->num /= divisor;
        this->denom /= divisor;
            return Fraction(this->num, this->denom);

    }

};

int main() { 
    int num;
    int denom;
    cout<< "Enter Numerator :"<< endl;
    cin>> num; 
    cout<<"Enter Denominator: "<< endl;
    cin >> denom;
    Fraction myf = Fraction(num,denom);
    cout<< "Fraction ";
    myf.display();
    cout<< " can be reduced to ";
    myf.simplify();
    myf.display(); 
    cout<< endl << "Would you like to enter another fraction (y/n)?";
    return 0;
}

