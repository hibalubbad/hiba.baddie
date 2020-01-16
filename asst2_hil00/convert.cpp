#include <iostream>
using namespace std;

const double metertofoot =  0.3048;
const double centtoinch = 2.54;
int inputFeet(int feet){
    cin>>feet;
    return feet;
    
    
}
double inputInches(double inches){
    cin>>inches;
    return inches;
}

void conversion(double inches, int feet){
    double feets = double(feet) * metertofoot;
    inches *= centtoinch;
    cout<< "converted to meters,centimenters is "<< feets << ", " << inches<< endl;
}


int main(){
    char quit = 'y';
    while (quit == 'Y' || quit == 'y'){
        cout<< "Enter feet as an integer:";
        int feet  = inputFeet(feet); 
        cout<< "Enter inches as a double:";
        double inches = inputInches(inches);
        cout<< " the value of feet, inches " << feet << ", " << inches << endl ;
        conversion(inches, feet);
        cout<< "Y or y continues, any other character quits" << endl;
        cin >> quit;
    }

    


}