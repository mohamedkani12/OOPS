#include<bits/stdc++.h>
using namespace std;
class Askpromotion{
  virtual void promotion()=0;
};
class Employee : public Askpromotion {
private:
    string ename;
    string company;
    int age;

public:
    Employee() : ename(""), company(""), age(0) {}

    Employee(string name, string c, int a) : ename(name), company(c), age(a) {}

    void introduceyourself() {
        cout << "Name : " << ename << endl;
        cout << "Age : " << age << endl;
        cout << "Company : " << company << endl;
    }

    void setname(string name) {
        ename = name;
    }

    void setage(int ag) {
        if (ag >= 18) age = ag;
    }

    void setcompany(string c) {
        company = c;
    }

    int getage() {
        return age;
    }

    string getcompany() {
        return company;
    }

    string getname() {
        return ename;
    }

    void promotion() override { // Implement the pure virtual function
        if (age >= 30) {
            cout << "Promotion Got" << endl;
        } else {
            cout << "Rejected" << endl;
        }
    }
};
class Developer:public Employee{
    string favLanguage;
public:
    Developer(string name,int age,string company,string langauge):Employee(name,company,age){
        favLanguage=langauge;
    }
    void fixbug(){
        cout<<getname()<<" fixed bug by using "<<favLanguage;
    }
};
class Teacher:public Employee{
    string subject;
public:
    Teacher(string n,string c,int a,string s):Employee(n,c,a)
    {
        subject=s;
    }
    void preparedSub(){
        cout<<endl<<getname()<<" prepared "<<subject<<" for Students";
    }
};
int main(){
    Developer D=Developer("Mohamed",22,"Amazon","C++");
    D.fixbug();
    Teacher t=Teacher("Mohamed Kani","Accenture",22,"Java");
    t.preparedSub();
    cout<<"\n Teacher Promotion ? ";
    t.promotion();
    return 0;
}