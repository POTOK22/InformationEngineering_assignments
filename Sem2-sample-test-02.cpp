#include <iostream>
#include <vector>
#include <memory>
#include <string>

class ElectronicDevice{
protected:
    std::string brand_;
    std::string model_;
public:
    ElectronicDevice(std::string brand, std::string model)
        : brand_(brand), model_(model) {}
    void display(){
        std::cout<<"brand: "<<brand_<<" model: "<<model_<<std::endl;
    }
};

class Smartwatch : public ElectronicDevice{
protected:
    bool hasGPS_;
public:
    Smartwatch(std::string brand, std::string model, bool hasGPS)
        : ElectronicDevice(brand, model), hasGPS_(hasGPS) {}
    void display(){
        ElectronicDevice::display();
        if(hasGPS_==true){
            std::cout<<"GPS included"<<std::endl;
        }
        else{
            std::cout<<"GPS not inclueded"<<std::endl;
        }
    }
};

class Smartphone : public ElectronicDevice{
protected:
    int storageCapacity_;
public:
    Smartphone(std::string brand, std::string model, int storageCapacity)
        : ElectronicDevice(brand, model), storageCapacity_(storageCapacity) {}
    void display(){
        ElectronicDevice::display();
        std::cout<<"Storage capacity: "<<storageCapacity_<<" GB"<<std::endl;
    }
};

class Laptop : public ElectronicDevice{
protected:
    int ramSize_;
public:
    Laptop(std::string brand, std::string model, int ramSize)
        : ElectronicDevice(brand, model), ramSize_(ramSize) {}
    void display(){
        ElectronicDevice::display();
        std::cout<<"Ram Size: "<<ramSize_<<" GB"<<std::endl;
    }
};

class GamingLaptop : public Laptop{
protected:
    std::string gpuModel_;
public:
    GamingLaptop(std::string brand, std::string model, int ramSize, std::string gpuModel)
        : Laptop(brand, model, ramSize), gpuModel_(gpuModel) {}
    void display(){
        Laptop::display();
        std::cout<<"GPU model :"<<gpuModel_<<std::endl;
    }
};

class Store{
private:
    std::vector<std::unique_ptr<ElectronicDevice>> devices;
public:
    void addDevice(std::unique_ptr<ElectronicDevice> device){
        devices.push_back(std::move(device));
    }
    void displayDevices(){
        std::cout<<"Devices: "<<std::endl;
        for(auto &el : devices){
            el->display();
            std::cout<<std::endl;
        }
    }
};

class Time{
public:
    /*constructor of class time, important to do it in the same maner as other classes with initialization list!!*/
    Time(int hours = 0, int minutes = 0, int seconds = 0)
        : hours(hours), minutes(minutes), seconds(seconds) {}

    /*OPERATOR OVERLOADING*/
    /*all parts of class must be added with other proper parts e.g.: seconds + seconds etc.*/
    Time operator+(const Time& other) const {
        int total_seconds = seconds + other.seconds;
        int total_minutes = minutes + other.minutes + (total_seconds / 60);
        int total_hours = hours + other.hours + (total_minutes / 60);

        return Time(total_hours % 24, total_minutes % 60, total_seconds % 60);
    }

    Time operator-(const Time& other) const {
        int total_seconds = seconds - other.seconds;
        int total_minutes = minutes - other.minutes - (total_seconds < 0 ? 1 : 0);
        int total_hours = hours - other.hours - (total_minutes < 0 ? 1 : 0);

        total_seconds = (total_seconds + 60) % 60;
        total_minutes = (total_minutes + 60) % 60;
        total_hours = (total_hours + 24) % 24;

        return Time(total_hours, total_minutes, total_seconds);
    }

    bool operator==(const Time& other) const {
        return hours == other.hours && minutes == other.minutes && seconds == other.seconds;
    }

    friend std::ostream& operator<<(std::ostream& os, const Time& time) {
        os << time.hours << "h " << time.minutes << "m " << time.seconds << "s";
        return os;
    }
private:
    int hours, minutes, seconds;
};

int main()
{
    Time time1(3, 15, 45);
    Time time2(1, 50, 30);

    std::cout<<"Time 1:"<<time1<<std::endl;
    std::cout<<"Time 2:"<<time2<<std::endl;

    Time sum = time1 + time2;
    std::cout<<"Sum: "<<sum<<std::endl;

    Time difference = time1 - time2;
    std::cout<<"Difference: "<<difference<<std::endl;

    bool areEqual = time1 == time2;
    std::cout<<"Are equal? "<<(areEqual ? "Yes" : "No")<<std::endl;



//    Store store;
//    auto smartwatch = std::make_unique<Smartwatch>("Apple", "WatchSE", 1);
//    auto smartphone = std::make_unique<Smartphone>("Apple", "iPhone14", 256);
//    auto laptop = std::make_unique<Laptop>("HP", "Pavilion", 16);
//    auto laptop2 = std::make_unique<Laptop>("Apple", "Macbook Air", 16);
//    auto gaminglaptop = std::make_unique<GamingLaptop>("Asus", "TUF", 32, "GeForce GTX 1650");

//    store.addDevice(std::move(smartwatch));
//    store.addDevice(std::move(smartphone));
//    store.addDevice(std::move(laptop));
//    store.addDevice(std::move(laptop2));
//    store.addDevice(std::move(gaminglaptop));

//    store.displayDevices();
    return 0;
}
