#include <iostream>
#include <string>

class Vehicle {
public:
    /*getters*/
    std::string name(){
        return name_;
    }
    int number_of_wheels(){
        return number_of_wheels_;
    }
    std::string propulsion_type(){
        return propulsion_type_;
    }
    double max_speed(){
        return max_speed_;
    }
protected:
    Vehicle(const std::string &name, int number_of_wheels,
            const std::string &propulsion_type, double max_speed)
        : name_(name), number_of_wheels_(number_of_wheels),
        propulsion_type_(propulsion_type), max_speed_(max_speed) {}

    std::string name_;
    int number_of_wheels_;
    std::string propulsion_type_;
    double max_speed_;
};

/*new class initialization - bike*/
class Bike : public Vehicle {
public:
    Bike() : Vehicle("Bike", 2, "Muscles", 30) {}
    /*name = bike, number_of_wheels = 2, propulsion_type = Muscles, max_speed = 30*/
};

class Car : public Vehicle {
public:
    Car(const std::string &name, const std::string &propulsion_type,
        double max_speed, bool has_abs)
        : Vehicle(name, 4, propulsion_type, max_speed),
        has_abs_(has_abs) {}

    bool has_abs() {
        return has_abs_;
    }
private:
    bool has_abs_;
};

/*assgnment*/
class Tractor : public Vehicle{
public:
    Tractor(const std::string &name, const std::string &proplusionm_type,
        double max_speed, bool has_trailer)
        : Vehicle(name, 4, proplusionm_type, max_speed),
        has_trailer_(has_trailer) {}
    bool has_trailer() {
        return has_trailer_;
    }
private:
    bool has_trailer_;
};


int main(){
    /*Car passat("Volkswagen Passat", "Diesel", 200, true);
    std::cout << "Name: " << passat.name() << std::endl;
    std::cout << "Has ABS: " << passat.has_abs() << std::endl;
    std::cout << "Max speed: " << passat.max_speed() << std::endl;*/


    return 0;
}
