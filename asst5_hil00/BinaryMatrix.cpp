#include <iostream>
#include <string>
using namespace std;

class BinaryMatrix{
private:
int row;
int col;
bool **arr;
public:
static int count; 
BinaryMatrix(int row, int col){
    this->row= row;
    this->col = col;
    arr = new bool *[row];
    for(int i = 0; i < row; i++)
		arr[i] = new bool[col];
    for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			arr[i][j] = 0;
        }  
}
count++;
}
BinaryMatrix(){
    this->row= 3; 
    this->col = 3;
        arr = new bool *[3];
    for(int i = 0; i < 3; i++)
		arr[i] = new bool[3];
    for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			arr[i][j] = 0;
        }  
}
count++;
}
BinaryMatrix intersection(BinaryMatrix & other){
    BinaryMatrix third;
    third.row = max(row,other.row);
    third.col = max(col,other.col);
    for(int i = 0; i < third.row; i++){
		for(int j = 0; j < third.col; j++){
            if((arr[i][j]&&other.arr[i][j]) == 1)
			    third.arr[i][j] = 1;
            else
            {
               third.arr[i][j] = 0;
            }
        }  
}
count++;
return third;
}
BinaryMatrix Union(BinaryMatrix & other){
    BinaryMatrix third;
    third.row = max(row,other.row);
    third.col = max(col,other.col);
    for(int i = 0; i < third.row; i++){
		for(int j = 0; j < third.col; j++){
            if((arr[i][j]||other.arr[i][j]) == 1)
			    third.arr[i][j] = 1;
            else
            {
               third.arr[i][j] = 0;
            }
        }  
}
return third;
count++;
}
void print(){
    for(int i = 0; i < row; i++) {
		for(int j = 0; j < col; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
    cout << endl;
}
bool*operator [](int index){
    return arr[index];
}
~BinaryMatrix(){
    for(int i = 0; i < col; i++)
		delete[] arr[i];
	delete[] arr;
}
    static int getCount();
};

int BinaryMatrix::count=0;
int BinaryMatrix:: getCount(){
    count++;
    return count;
} int main(){
    cout<<"a intersection b"<< endl<<endl;
    BinaryMatrix a;
    a[0][1]=a[1][2]=a[2][0]=1;
    a.print();
    BinaryMatrix b;
    b[0][1]=b[1][2]=b[0][2]=b[1][1]=b[1][0]=1;
    b.print();
    BinaryMatrix d = a.intersection(b);
    d.print();
    cout<<"a intersection c"<< endl<<endl;
    BinaryMatrix c(3,2);
    c[0][1]=c[1][0]=c[1][1]=1;
    a.print();
    c.print();
    BinaryMatrix f = a.intersection(c);
    f.print();
    cout<<"a union b"<< endl<<endl;
    a.print();
    b.print();
    BinaryMatrix e = a.Union(b);
    e.print();
    cout<<"a union c"<< endl<<endl;
    a.print();
    c.print();
    BinaryMatrix g = a.Union(c);
    g.print();
    cout<<BinaryMatrix::getCount()<<endl;
return 0; 
}
