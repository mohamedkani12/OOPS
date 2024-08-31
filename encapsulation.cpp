#include <iostream>
using namespace std;

// Base class with a pure virtual function
class Askpromotion {
public:
    virtual void promotion() = 0; // Pure virtual function
};

// Derived class that implements the base class's pure virtual function
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

// Function that uses base class pointers to call derived class methods
void performPromotion(Askpromotion* ap) {
    ap->promotion();
}

int main() {
    Employee employee("Mohamed", "Amazon", 40);
    Employee* employee1 = new Employee("Kani", "Apple", 71);

    // Display information
    employee.introduceyourself();
    employee1->introduceyourself();

    cout << "\nName of the Employee : " << employee.getname() << endl;
    cout << "Age of the Employee : " << employee.getage() << endl;
    cout << "Name of the company he works at : " << employee.getcompany() << endl;

    cout << "\nPromotion ? ";
    employee.promotion();

    cout << "\nPromotion ? ";
    employee1->promotion();

    // Using base class pointer to call derived class method
    Askpromotion* ask = &employee;
    performPromotion(ask);

    // Clean up dynamically allocated memory
    delete employee1;

    return 0;
}
