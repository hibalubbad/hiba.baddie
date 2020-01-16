
#include <iostream>
#include <array>
#include <string>

using namespace std;

class Date{
    private:
    int day, month, year;

    public:
    Date(){
        day=0;
        month=0;
        year=0000;
    }
    Date(int day, int month, int year){
        this->day=day;
        this->month=month;
        this->year=year;
    }

    int getDay(){
        return this->day;
    }
    int getMonth(){
        return this->month;
    }
    int getYear(){
        return this->year;
    }
    void setDay(int day){
        this->day=day;
    }
    void setMonth(int month){
        this->month=month;
    }
    void setYear(int year){
        this->year=year;
    }

    void print(){
        cout<<day<<"/"<<month<<"/"<<year<<endl;
    }
};

class Person: public Date{
    private:
    string fname, lname;
    bool gender;

    public:
    Person(){
        fname= "NONAME";
        lname= "NOLASTNAME";
        gender=false;
    }

    Person(string firstname, string lastname,Date dd, bool gendertf):
        Date(dd), fname(firstname), lname(lastname), gender(gendertf){}

    string getFname(){
        return this->fname;
    }
    string getLname(){
        return this->lname;
    }
    string getGender(){
        bool genderof=this->gender;
        if (genderof==true){
            return "male";
        }
        else{
            return "female";
        }
    }
    void setFname(string fname){
        this->fname=fname;
    }
    void setLname(string lname){
        this->lname=lname;
    }
    void setGender(bool gender){
        this->gender=gender;
    }

    virtual void print() {
        cout<<fname<<" "<<lname<<": "<<getGender()<<",born on ";
        Date::print();
    }
};

class Student: public Person{
    private:
    int id;

    public:
    Student(string fname, string lname,Date dd, bool gender, int id):
        Person(fname, lname, dd, gender),
        id(id){}
    
    int getId() const{
        return this->id;
    }
    void setId(int id){
        this->id=id;
    }

    virtual void print() {
        Person::print();
        cout<<",student number: "<<id<<endl;
    }

};

int main(){
    Date d(1,2,2000);
    d.print();

    Person p("Amer", "Mouawad", d, true);
    p.print();

    Date d2(21,8,1995);
    Person p2("Eva", "Mendosa", d2, false);
    p2.print();

    Date d3(13,5,1985);
    Person *p3=new Student ("Karen", "Karma", d3, false, 1234);
    p3->print();
    return 0;
}
