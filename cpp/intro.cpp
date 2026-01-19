/* https://www.youtube.com/watch?v=0NwsayeOsd4 */
#include <iostream>
#include <string>

class Person {
    private:
        std::string firstName;
        std::string lastName;
    public:
        Person(std::string fname, std::string lname) : firstName(fname), lastName(lname) {}
        std::string getName() {
            return firstName + " " + lastName;
        }

        virtual void getInfo() {
           std::cout << "Name: " << getName() << std::endl;
        }
};

class Employee : public Person {
    private:
        std::string department;
    public:
        Employee(std::string fname, std::string lname, std::string dept) : Person(fname, lname), department(dept) {}
        std::string getDepartment() {
            return department;
        }
        void getInfo() override {
           std::cout << "Name: " << getName() << " | Department: " << getDepartment() << std::endl;
        }
};

int main() {
    Person* p = new Person("Sam", "Altman");
    p->getInfo() ;

    Person* e = new Employee("John", "Doe", "Sales");
    e->getInfo();
    return 0;
}