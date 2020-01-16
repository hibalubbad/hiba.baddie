#include <iostream>
#include <string>
using namespace std;

class Counter {
    private:

        int ones, tens ,hundreds,thousands;


    public:
        

        Counter( int ones=0,int tens=0 ,int hundreds=0,int thousands=0)
        {
            this->ones = ones; 
            this-> tens = tens;
            this -> hundreds = hundreds;
            this -> thousands = thousands;
        }

        int getones(){
            return ones;
        }
        int gethundreds(){
            return hundreds;
        }
        int gettens(){

            return tens;
        }
        int getthousands(){

            return thousands;
        }


        void setones(int ones){
            this->ones = ones;

        }
         void sethundreds(int hundreds){
            this->hundreds = hundreds;

        }
         void settens(int tens){
            this->tens = tens;

        }
         void setthousands(int thousands){
            this->thousands = thousands;
        }


    void incr1(int other){
        ones+=other;
        if((ones + other)>9){
            ones= other+ones-10;
            tens+=1;
            }

    }

    void incr10(int other){
        if((tens + other)>9){
            tens= other+tens-10;
            hundreds+=1;
        }
        else
            tens+=other;
    }

    void incr100(int other){
        if((hundreds + other)>9){
            hundreds= other+hundreds-10;
            thousands+=1;
        }
        else
            hundreds+=other;
    }

    void incr1000(int other){
        thousands+=other;
    }

    void reset(){
        int ones=0;
        int tens=0;
        int hundreds=0;
        int thousands=0;
    }
    void display(){
        cout<<thousands<<hundreds<<"."<<tens<<ones<<endl;

    }
        
    bool overflow(){
        if(thousands >9 || hundreds >9 || tens>9)
            return false;
        return true;
    }




};

int main(){
    char letter= ' '; 
    int digit;
    Counter c1;
    c1.display();
    while((c1.overflow() == true )&& (letter != 'q'||letter != 'Q')){
        cout<< "Enter a character followed by a digit 1-9:"<<endl; 
        cout<< "Enter a for units"<<endl;  
        cout<<"s for tens"<< endl; 
        cout<<"d for hundreds"<< endl;
        cout<<"f for thousands"<< endl;
        cout<<"Q or q at any time to quit."<< endl;
        cin >> letter>> digit; 
        switch(letter){
        case 'a':
		    c1.incr1(digit);
		    break;
	    case 's':
		    c1.incr10(digit);
		    break;
	    case 'd':
		    c1.incr100(digit);
		    break;
	    case 'f':
            c1.incr1000(digit);
            break;
		case'o':
            c1.overflow();
            break;
        case'r':
            c1.reset();
            break;
        case 'q':
            exit(0);
        case 'Q':
            exit(0);
        }
        c1.display();

    }

    if(c1.overflow()== false)
    {
        cout<<"ALERT: OVERFLOW HAS OCCURRED.RESULTS ARE NOT RELIABLE. Press Q to quit.";
        while(letter != 'Q'){
            cin>> letter;
        }
    }
    
    
}