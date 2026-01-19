#include <iostream>
#include <memory>
#include <string>

class Vehicle {
protected:
    std::string brand;
    std::string model;
public:
    Vehicle(std::string brand, std::string model) : brand(brand), model(model) {}
    virtual std::string getVehicle() {
        return "Vehicle is - " + brand + " " + model;
    }
    virtual ~Vehicle() = default;
};

class Car : public Vehicle {
private:
    int move;
public:
    Car(std::string brand, std::string model, int move) : Vehicle(brand, model), move(move) {}
    std::string getVehicle() override {
        return "Car is - " + brand + " " + model;
    }
    virtual int move_vehicle() {
        return move * 4;
    }
    int getMove() {
        return move;
    }
};

class SportsCar : public Car {
private:
    int speed_multiplier;
    int turbo;
public:
    SportsCar(std::string brand, std::string model, int move, int multiplier, int turbo) : Car(brand, model, move), speed_multiplier(multiplier), turbo(turbo) {}
    std::string getVehicle() override {
        return "Sports Car is - " + brand + " " + model;
    }
    int move_vehicle() override {
        return (getMove() * 4 * speed_multiplier) + turbo;
    }
};

int main() {
    Vehicle* v1 = new Vehicle("Force", "Truck");
    Vehicle* v2 = new Car("Toyota", "Hyryder", 5);
    auto c1 = std::make_unique<Car>("Maruti Suzuki", "Grand Vitara", 6);
    auto f1 = std::make_unique<SportsCar>("Ferrari", "F8", 6, 2, 10);

    std::cout << v1->getVehicle() << std::endl;
    std::cout << v2->getVehicle() << std::endl;
    std::cout << c1->move_vehicle() << std::endl;
    std::cout << f1->getVehicle() << std::endl;
    std::cout << f1->move_vehicle() << std::endl;

    delete v1;
    delete v2;

    return 0;
}
