#include <iostream>

class Vehicle {
public:
    virtual void drive() = 0;
    virtual ~Vehicle() = default;
};

class Car : public Vehicle {
public:
    void drive() override {
        std::cout << "Driving a car\n";
    }
};

class Bike : public Vehicle {
public:
    void drive() override {
        std::cout << "Riding a bike\n";
    }
};

// Factory Method
Vehicle* createVehicle(const std::string& type) {
    if (type == "car")
        return new Car();
    else if (type == "bike")
        return new Bike();
    return nullptr;
}

int main() {
    Vehicle* v1 = createVehicle("car");
    Vehicle* v2 = createVehicle("bike");
    Vehicle* v3 = createVehicle("truck"); // Invalid type
    if(v3 == nullptr) {
        std::cout << "Invalid vehicle type requested.\n";
        return 1;
    }
    v1->drive();
    v2->drive();
    v3->drive();

    delete v1;
    delete v2;
    delete v3;
}
