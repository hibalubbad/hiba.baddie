#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

class DynamicStringArray{

    private:
    string *dynamicArray;
    int size; 
    public:
    DynamicStringArray(){
        this->dynamicArray= NULL;
        this->size = 0;
    }
     DynamicStringArray( DynamicStringArray& copy){
         size= copy.getsize();
        dynamicArray = new string[size];
        for(int i = 0; i < size; i++){
		dynamicArray[i] = copy.getEntry(i);
	}

    }
    void operator =( DynamicStringArray& copy){
	DynamicStringArray temp(copy);
	if(this->size !=0)
		delete[] this->dynamicArray;

	this->size = copy.getsize();
	this->dynamicArray = new std::string[this->size];
	for(int i = 0; i < this->size; i++)
		this->dynamicArray[i] = copy.getEntry(i);
}
    ~DynamicStringArray(void){
	delete[] dynamicArray;}
    
    int getsize(){
        return size;
    }


    void addEntry(string entry){
        string * tempPtr = dynamicArray;
        dynamicArray = new string[size+1];
        for(int i =0; i<size;i++){
            dynamicArray[i] = tempPtr[i];
        }
        dynamicArray[size].assign(entry);
        if(size>0){
		delete[] tempPtr;
	}
        size++;
    }
    bool deleteEntry(string entry){
    bool found = false;
    int i;
	for(i = 0; i < size; i++){
		if(entry==dynamicArray[i]){
			found = true;
			break;
		}
	}
	if(found == true){
		string * temp = dynamicArray;
		dynamicArray = new string[size - 1];
		for(int j=0; j < size; j++){
			if(j < i){
				dynamicArray[j] = temp[j];
			}else if(j > i){
				dynamicArray[j - 1] = temp[j];
			}
		}
        delete[] temp;
		size--;
	}
	return found;

    }
    string getEntry(int index){
        if(index >= size){
		return NULL;
	}
    else{
		return dynamicArray[index];
	}

    }

};


int main()
{
	DynamicStringArray names;

	// List of names
	names.addEntry("Frank");
	names.addEntry("Wiggum");
	names.addEntry("Nahasapeemapetilon");
	names.addEntry("Quimby");
	names.addEntry("Flanders");

	// Output list
	cout << "List of names:" << endl;
	for (int i = 0; i < names.getsize(); i++)
		cout << names.getEntry(i) << endl;
	cout << endl;

      // Add and remove some names
      names.addEntry("Spuckler");
      cout << "After adding a name:" << endl;
	for (int i = 0; i < names.getsize(); i++)
		cout << names.getEntry(i) << endl;
	cout << endl;

      names.deleteEntry("Nahasapeemapetilon");
      cout << "After removing a name:" << endl;
	for (int i = 0; i < names.getsize(); i++)
		cout << names.getEntry(i) << endl;
	cout << endl;

      names.deleteEntry("Skinner");
      cout << "After removing a name that isn't on the list:" << endl;
	for (int i = 0; i < names.getsize(); i++)
		cout << names.getEntry(i) << endl;
	cout << endl;

      names.addEntry("Muntz");
      cout << "After adding another name:" << endl;
	for (int i = 0; i < names.getsize(); i++)
		cout << names.getEntry(i) << endl;
	cout << endl;

      // Remove all of the names by repeatedly deleting the last one
      while (names.getsize() > 0) {
        names.deleteEntry(names.getEntry(names.getsize() - 1));
      }

      cout << "After removing all of the names:" << endl;
	for (int i = 0; i < names.getsize(); i++)
		cout << names.getEntry(i) << endl;
	cout << endl;

      names.addEntry("Burns");
      cout << "After adding a name:" << endl;
	for (int i = 0; i < names.getsize(); i++)
		cout << names.getEntry(i) << endl;
	cout << endl;

	cout << "Testing copy constructor" << endl;
	DynamicStringArray names2(names);
	// Remove Burns from names
	names.deleteEntry("Burns");
      cout << "Copied names:" << endl;
	for (int i = 0; i < names2.getsize(); i++)
		cout << names2.getEntry(i) << endl;
	cout << endl;

	cout << "Testing assignment" << endl;
	DynamicStringArray names3 = names2;
	// Remove Burns from names2
	names2.deleteEntry("Burns");
      cout << "Copied names:" << endl;
	for (int i = 0; i < names3.getsize(); i++)
		cout << names3.getEntry(i) << endl;
	cout << endl;

	cout << "Enter a character to exit." << endl;
	char wait;
	cin >> wait;
	return 0;
}