#include <iostream>
#include <vector>
#include <memory>
#include <string>

class Animal{
protected:
    std::string name_;
    int age_;
    double weight_;
public:
    Animal(std::string name, int age, double weight)
        : name_(name), age_(age), weight_(weight) {}
    void display(){
        std::cout<<"Name: "<<name_<<" age: "<<age_<<" weight: "<<weight_<<std::endl;
    }
};

class Mammal : public Animal{
protected:
    bool isHerbivore_;
public:
    Mammal(std::string name, int age, double weight, bool isHerbivore)
        : Animal(name, age, weight), isHerbivore_(isHerbivore) {}
    void display(){
        Animal::display();
        if(isHerbivore_ == true){
            std::cout<<"Animal is herbivore"<<std::endl;
        }
        else{
            std::cout<<"Animal is not herbivore"<<std::endl;
        }
    }
};

class CarnivoreMammal : public Mammal{
protected:
    bool isPredator_;
public:
    CarnivoreMammal(std::string name, int age, double weight, bool isPredator)
        : Mammal(name, age, weight, false), isPredator_(isPredator) {}
    void display(){
        Mammal::display();
        if(isPredator_ == true){
            std::cout<<"Animal is predator"<<std::endl;
        }
        else{
            std::cout<<"Animal is not predator"<<std::endl;
        }
    }
};

class Reptile : public Animal{
protected:
    bool isVenomous_;
public:
    Reptile(std::string name, int age, double weight, bool isVenomous)
        : Animal(name, age, weight), isVenomous_(isVenomous) {}
    void display(){
        Animal::display();
        if(isVenomous_ == true){
            std::cout<<"Animal is venomous"<<std::endl;
        }
        else{
            std::cout<<"Animal is not venomous"<<std::endl;
        }
    }
};

class Zoo{
private:
    std::vector<std::unique_ptr<Animal>> animals_;
public:
    void addAnimal(std::unique_ptr<Animal> animal){
        animals_.push_back(std::move(animal));
    }
    void displayAnimals(){
        std::cout<<"Animals: "<<std::endl;
        for(auto &el : animals_){
            el->display();
            std::cout<<std::endl;
        }
    }
};

class Vector2D{
public:
    /*constructor*/
    Vector2D(double x=0.0, double y=0.0)
        : x(x), y(y) {}
    /*using friend function to print out the class Vector2D*/
    friend std::ostream& operator<<(std::ostream& os, const Vector2D& vec){
        os << "(" << vec.x << ", " << vec.y << ")";
        return os;
    }
    Vector2D operator+(Vector2D other){
        return Vector2D(x + other.x, y + other.y);
    }
    Vector2D operator-(Vector2D other){
        return Vector2D(x - other.x, y - other.y);
    }
    double operator*(Vector2D other){
        return x*other.x + y*other.y;
    }
    bool operator==(Vector2D other){
        return x==other.x && y==other.y;
    }


private:
    double x, y;
};

int main()
{
    Vector2D vec1(3.0, 4.0);
    Vector2D vec2(1.0, 2.0);

    std::cout<<"Vector 1:"<<vec1<<std::endl;
    std::cout<<"Vector 2:"<<vec2<<std::endl;

    Vector2D sum=vec1+vec2;
    std::cout<<"Sum: "<<sum<<std::endl;

    Vector2D difference=vec1-vec2;
    std::cout<<"Difference :"<<difference<<std::endl;

    double dotProduct=vec1*vec2;
    std::cout<<"Dot Product: "<<dotProduct<<std::endl;

    bool areEqual = vec1==vec2;
    std::cout<<"Are equal? "<<(areEqual ? "Yes" : "No")<<std::endl;


//    Zoo zoo;
//    auto mammal = std::make_unique<Mammal>("Elephant", 10, 5000.0, true);
//    auto mammal2 = std::make_unique<Mammal>("Snake", 3, 15.0, true);
//    auto carnivoremammal = std::make_unique<CarnivoreMammal>("Lion", 7, 300.0, true);
//    auto reptile = std::make_unique<Reptile>("Aligator", 5, 200.0, false);

//    zoo.addAnimal(std::move(mammal));
//    zoo.addAnimal(std::move(mammal2));
//    zoo.addAnimal(std::move(carnivoremammal));
//    zoo.addAnimal(std::move(reptile));

//    zoo.displayAnimals();

    return 0;
}
