#include <iostream>
#include <string>
#include <math.h>
#include <vector>
using namespace std;

class IntegerSet{
    public:
    int size;
    vector<int> set;
    static int count;
    IntegerSet(int size){
        this->size = size;
        set.resize(size);
        count++;

    }
    IntegerSet(){
        this->size = 101;
        set.resize(size);    
        count++   ;
        }

    IntegerSet intersection(IntegerSet &other){
        IntegerSet ans;
        for(int i = 0; i<set.size(); i++){
            if (this->set[i] == 1 && other.set[i] == 1)
			    ans.InsertElement(i);
	}
            count++;
	    return ans;
        }
    IntegerSet Union(IntegerSet &other){
        IntegerSet ans;
        for(int i = 0; i<set.size(); i++){
            if (this->set[i] == 1 || other.set[i] == 1)
			    ans.InsertElement(i);
	    }
        count++;
	    return ans;
    }
    void InsertElement(int element){
                set[element] = 1;
    }

    void DeleteElemet(int element){
        if (set.empty()== 1) {
		cout << "ERROR: Delete operation failed: Set is already empty." << endl;
        }

        if (set[element] == 0) {
            cout << "ERROR: Delete operation failed: element " << element << " is not a member of the set." << endl;
        }

        set[element] = 0;
    }
    void printSet() {
        if (set.size() == 0) 
            cout << "(Empty set)" << endl;
        else {
            cout << "(";
            for (int i=0, j=0; i<set.size(); i++) {
                if (set[i]==1) {
                    cout << i;
                    cout << ", ";
                }
            }
            cout << ")\n";
        }
    }

    bool isEqualTo( IntegerSet& other){
        for(int i = 0; i<set.size(); i++){
            if(set[i]!=other.set[i])
                return false;
        }
        return true;
    }
    
 static int getCount();
};  

int IntegerSet::count=0;
int IntegerSet:: getCount(){
    count++;
    return count;
} 

int main(){
    IntegerSet my;
    IntegerSet you;
    int i, j;
    for (i=0; i<101; i++){
    if (i%2==0)
        you.InsertElement(i);
    
    }
    for (j=0; j<101; j++){
    if (j%2!=0)
        my.InsertElement(j);
    }
    you.DeleteElemet(2);
    you.InsertElement(3);
    my.printSet() ;
    IntegerSet uni = my.Union(you);
    IntegerSet inter= you.intersection(my);
    you.printSet() ;
    cout<< "Their union is: ";
    uni.printSet();
    cout<< "Their intersection is: ";
    inter.printSet();
    cout<<you.isEqualTo(my)<<endl;
    cout<<"The number of sets created is: ";
    cout<<IntegerSet::getCount()<<endl;
    return 0;

}
