#include <iostream>
#include <memory>

class Person {
    private:
        int age;
        std::string fullname;
    public:
        Person(int age, std::string fname) : age(age), fullname(fname) {};
        void getInfo() {
            std::cout << fullname << " is of " << age << " years old" << std::endl;
        }
        std::string getName() {
            return fullname;
        }
        virtual void makeSound() {
            std::cout << fullname << " says hello" << std::endl;
        }
};

class Baby : public Person {
    public:
        Baby(int age, std::string name) : Person(age, name) {}
        void makeSound() override {
            std::cout << getName() << " baby cries" << std::endl;
        }
};

int main() {
    auto p1 = std::make_unique<Person>(32, "Alice");
    p1->getInfo();

    std::unique_ptr<Person> b1 = std::make_unique<Baby>(1, "Angel");
    b1->makeSound();
    return 0;
}