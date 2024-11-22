#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Class to represent the Address of a place
class Address {
private:
    string street;
    string city;
    string zipCode;

public:
    // Constructor to initialize address details
    Address(string street, string city, string zipCode)
        : street(street), city(city), zipCode(zipCode) {}

    // Getter methods
    string getStreet() { return street; }
    string getCity() { return city; }
    string getZipCode() { return zipCode; }

    // Display method for address
    void displayAddress() {
        cout << street << ", " << city << ", " << zipCode << endl;
    }
};

// Class to represent a Driver
class Driver {
private:
    string name;
    int age;

public:
    // Constructor to initialize driver details
    Driver(string name, int age) : name(name), age(age) {}

    // Getter methods
    string getName() { return name; }
    int getAge() { return age; }

    // Display method for driver details
    void displayDriver() {
        cout << "Driver: " << name << ", Age: " << age << endl;
    }
};

// Class to represent a Commuter
class Commuter {
private:
    string name;
    string ticketType;

public:
    // Constructor to initialize commuter details
    Commuter(string name, string ticketType) : name(name), ticketType(ticketType) {}

    // Getter methods
    string getName() { return name; }
    string getTicketType() { return ticketType; }

    // Display method for commuter details
    void displayCommuter() {
        cout << "Commuter: " << name << ", Ticket Type: " << ticketType << endl;
    }
};

// Class to represent the Engine of a vehicle
class Engine {
private:
    string model;
    int horsepower;

public:
    // Constructor to initialize engine details
    Engine(string model, int horsepower) : model(model), horsepower(horsepower) {}

    // Getter methods
    string getModel() { return model; }
    int getHorsepower() { return horsepower; }

    // Display method for engine details
    void displayEngine() {
        cout << "Engine Model: " << model << ", Horsepower: " << horsepower << endl;
    }
};

// Class to represent a Bus
class Bus {
private:
    string busNumber;
    Engine engine;
    Driver driver;

public:
    // Constructor to initialize bus details
    Bus(string busNumber, Engine engine, Driver driver)
        : busNumber(busNumber), engine(engine), driver(driver) {}

    // Getter methods
    string getBusNumber() { return busNumber; }
    Engine getEngine() { return engine; }
    Driver getDriver() { return driver; }

    // Display method for bus details
    void displayBusDetails() {
        cout << "Bus Number: " << busNumber << endl;
        engine.displayEngine();
        driver.displayDriver();
    }
};

// Class to represent a Bus Station
class BusStation {
private:
    string name;
    Address address;
    vector<Bus> buses;

public:
    // Constructor to initialize bus station details
    BusStation(string name, Address address) : name(name), address(address) {}

    // Getter methods
    string getName() { return name; }
    Address getAddress() { return address; }

    // Add a bus to the station
    void addBus(const Bus& bus) {
        buses.push_back(bus);
    }

    // Display method for bus station details
    void displayBusStationDetails() {
        cout << "Bus Station: " << name << endl;
        address.displayAddress();
        cout << "Buses at this station:" << endl;
        for (int i = 0; i < buses.size(); ++i) {
            buses[i].displayBusDetails();
        }
    }
};

// Class to represent a Mosquito
class Mosquito {
private:
    string species;
    bool isInfected;

public:
    // Constructor to initialize mosquito details
    Mosquito(string species, bool isInfected) : species(species), isInfected(isInfected) {}

    // Getter methods
    string getSpecies() { return species; }
    bool getIsInfected() { return isInfected; }

    // Display method for mosquito details
    void displayMosquito() {
        string infectedStatus = (isInfected == true) ? "Infected" : "Not Infected";
        cout << "Mosquito species: " << species << ", Status: " << infectedStatus << endl;
    }
};

// Class to represent a Car
class Car {
private:
    string model;
    Engine engine;
    Driver driver;

public:
    // Constructor to initialize car details
    Car(string model, Engine engine, Driver driver)
        : model(model), engine(engine), driver(driver) {}

    // Getter methods
    string getModel() { return model; }
    Engine getEngine() { return engine; }
    Driver getDriver() { return driver; }

    // Display method for car details
    void displayCarDetails() {
        cout << "Car Model: " << model << endl;
        engine.displayEngine();
        driver.displayDriver();
    }
};

// Common operations to manage all objects (bus, car, mosquito, etc.)
class FleetManagement {
public:
    // Function to display vehicle details
    static void displayVehicleDetails(Bus& bus) {
        bus.displayBusDetails();
    }

    static void displayVehicleDetails(Car& car) {
        car.displayCarDetails();
    }

    // Function to display all commuters
    static void displayCommuterDetails(Commuter& commuter) {
        commuter.displayCommuter();
    }

    // Function to display all mosquitoes
    static void displayMosquitoDetails(Mosquito& mosquito) {
        mosquito.displayMosquito();
    }
};

// Main application
int main() {
    // Create Address instances
    Address stationAddress("123 Main St", "Cityville", "12345");

    // Create Driver instances
    Driver busDriver("John Doe", 30);
    Driver carDriver("Jane Smith", 28);

    // Create Engine instances
    Engine busEngine("V8", 300);
    Engine carEngine("V6", 250);

    // Create Bus and Car instances
    Bus bus1("BUS001", busEngine, busDriver);
    Car car1("Sedan", carEngine, carDriver);

    // Create Commuter instances
    Commuter commuter1("Alice", "Monthly");
    Commuter commuter2("Bob", "One-time");

    // Create Mosquito instances
    Mosquito mosquito1("Anopheles", true);
    Mosquito mosquito2("Aedes", false);

    // Create BusStation instance
    BusStation busStation("Main Bus Station", stationAddress);
    busStation.addBus(bus1);

    // Display all details using FleetManagement
    FleetManagement::displayVehicleDetails(bus1);
    FleetManagement::displayVehicleDetails(car1);
    FleetManagement::displayCommuterDetails(commuter1);
    FleetManagement::displayMosquitoDetails(mosquito1);
    busStation.displayBusStationDetails();

    return 0;
}
