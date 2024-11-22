#include <iostream>
#include <cstring>
using namespace std;

// Constants defining maximum limits for various elements
const int MAX_PEOPLE = 10; // Max number of people (commuters, persons)
const int MAX_BUSES = 5; // Max number of buses
const int MAX_MOSQUITOES = 10; // Max number of mosquitoes in an apartment
const int MAX_STATIONS = 5; // Max number of stations for a bus

// Class representing an Address (used for locations like street and city)
class Address {
public:
    char street[50]; // Street name
    char city[50]; // City name

    // Constructor to initialize street and city
    Address(const char* street, const char* city) {
        strcpy_s(this->street, sizeof(this->street), street); // Copy street name
        strcpy_s(this->city, sizeof(this->city), city); // Copy city name
    }
};

// Class representing a Mosquito
class Mosquito {
public:
    char id[20]; // Unique ID for the mosquito
    char currentLocation[50]; // Current location of the mosquito (e.g., apartment, bus)

    // Constructor to initialize mosquito ID and its location
    Mosquito(const char* id) {
        strcpy_s(this->id, sizeof(this->id), id); // Set mosquito ID
        strcpy_s(this->currentLocation, sizeof(this->currentLocation), "Apartment"); // Default location
    }

    // Function to move the mosquito to a new location (e.g., from apartment to bus)
    void move(const char* location) {
        strcpy_s(currentLocation, sizeof(currentLocation), location); // Change location
    }
};

// Base class representing a Person (generic class for all types of people)
class Person {
protected:
    char name[50]; // Name of the person
    Address address; // Address associated with the person

public:
    // Constructor to initialize name and address
    Person(const char* name, Address address) : address(address) {
        strcpy_s(this->name, sizeof(this->name), name); // Set the name
    }

    // Function to get the name of the person
    const char* getName() {
        return name; // Return the name of the person
    }

    // Function to get the address of the person
    Address getAddress() {
        return address; // Return the address of the person
    }
};

// Derived class representing a Driver (inherits from Person)
class Driver : public Person {
public:
    // Constructor for Driver, calls the base class (Person) constructor
    Driver(const char* name, Address address) : Person(name, address) {}
};

// Derived class representing a Commuter (inherits from Person)
class Commuter : public Person {
public:
    // Constructor for Commuter, calls the base class (Person) constructor
    Commuter(const char* name, Address address) : Person(name, address) {}
};

// Derived class representing a Student (inherits from Commuter)
class Student : public Commuter {
public:
    // Constructor for Student, calls the base class (Commuter) constructor
    Student(const char* name, Address address) : Commuter(name, address) {}
};

// Class representing an Apartment, where people and mosquitoes live
class Apartment {
public:
    Address address; // Address of the apartment
    Person* owner; // Owner of the apartment
    Mosquito* mosquitoes[MAX_MOSQUITOES] = { nullptr }; // List of mosquitoes in the apartment
    int mosquitoCount; // Counter for the number of mosquitoes in the apartment

    // Constructor for the apartment
    Apartment(Address address, Person* owner) : address(address), owner(owner), mosquitoCount(0) {}

    // Function to add a mosquito to the apartment
    void addMosquito(Mosquito* mosquito) {
        if (mosquitoCount < MAX_MOSQUITOES) {
            mosquitoes[mosquitoCount++] = mosquito; // Add mosquito if there is space
        }
        else {
            cout << "Cannot add more mosquitoes, apartment is full.\n"; // Error message if full
        }
    }

    // Function to move a mosquito from the apartment to another location
    void moveMosquito(Mosquito* mosquito, const char* location) {
        for (int i = 0; i < mosquitoCount; ++i) {
            if (mosquitoes[i] == mosquito) {
                mosquito->move(location); // Move mosquito to the new location
                for (int j = i; j < mosquitoCount - 1; ++j) {
                    mosquitoes[j] = mosquitoes[j + 1]; // Shift mosquitoes to fill the gap
                }
                mosquitoes[--mosquitoCount] = nullptr; // Remove mosquito from list
                break;
            }
        }
    }
};

// Class representing a Vehicle (generic class for vehicles like buses)
class Vehicle {
protected:
    char id[20]; // Vehicle ID

public:
    // Constructor for Vehicle, initializes its ID
    Vehicle(const char* id) {
        strcpy_s(this->id, sizeof(this->id), id); // Set the vehicle ID
    }

    // Function to get the vehicle ID
    const char* getId() {
        return id; // Return the vehicle ID
    }
};

// Class representing a Bus (inherits from Vehicle)
class Bus : public Vehicle {
private:
    char stations[MAX_STATIONS][50] = { "" }; // List of bus stations
    Commuter* commuters[MAX_PEOPLE] = { nullptr }; // List of commuters on the bus
    int stationCount; // Number of stations the bus stops at
    int commuterCount; // Number of commuters on the bus

public:
    // Constructor for Bus, initializes ID and other counts
    Bus(const char* id) : Vehicle(id), stationCount(0), commuterCount(0) {}

    // Function to add a station to the bus
    void addStation(const char* stationName) {
        if (stationCount < MAX_STATIONS) {
            strcpy_s(stations[stationCount++], sizeof(stations[stationCount]), stationName); // Add station
        }
    }

    // Function to add a commuter to the bus
    void addCommuter(Commuter* commuter) {
        if (commuterCount < MAX_PEOPLE) {
            commuters[commuterCount++] = commuter; // Add commuter to bus
        }
    }

    // Function to list all stations the bus stops at
    void listStations() {
        cout << "Bus stops at:\n";
        for (int i = 0; i < stationCount; ++i) {
            cout << "- " << stations[i] << endl; // Print each station
        }
    }

    // Function to list all commuters on the bus
    void listCommuters() {
        cout << "Commuters on the bus:\n";
        for (int i = 0; i < commuterCount; ++i) {
            cout << "- " << commuters[i]->getName() << endl; // Print each commuter's name
        }
    }

    // Function to get the number of commuters on the bus
    int getCommuterCount() {
        return commuterCount; // Return the number of commuters
    }
};

// Class representing a Bus Station
class BusStation {
private:
    char name[50]; // Name of the station
    Bus* buses[MAX_BUSES] = { nullptr }; // List of buses at the station
    Person* people[MAX_PEOPLE] = { nullptr }; // List of people at the station
    int busCount; // Number of buses at the station
    int personCount; // Number of people at the station

public:
    // Constructor for the station, initializes name and other counts
    BusStation(const char* name) : busCount(0), personCount(0) {
        strcpy_s(this->name, sizeof(this->name), name); // Set station name
    }

    // Function to add a bus to the station
    void addBus(Bus* bus) {
        if (busCount < MAX_BUSES) {
            buses[busCount++] = bus; // Add bus to the station
        }
    }

    // Function to add a person to the station
    void addPerson(Person* person) {
        if (personCount < MAX_PEOPLE) {
            people[personCount++] = person; // Add person to the station
        }
    }

    // Function to list all buses at the station
    void listBuses() {
        cout << "Buses stopping at " << name << ":\n";
        for (int i = 0; i < busCount; ++i) {
            cout << "- " << buses[i]->getId() << endl; // Print each bus ID
        }
    }

    // Function to get the name of the station
    const char* getName() {
        return name; // Return the station name
    }

    // Function to get the number of people at the station
    int getPersonCount() {
        return personCount; // Return the number of people
    }
};

// Main function that demonstrates the use of all the classes
int main() {
    Address addr1("Main Street", "City A");
    Address addr2("Second Avenue", "City B");

    Driver driver1("John", addr1); // Create a driver
    Student student1("Alice", addr2); // Create a student
    Commuter commuter1("Bob", addr1); // Create a commuter

    Apartment apartment(addr1, &student1); // Create an apartment
    Mosquito mosquito1("M001"); // Create a mosquito
    apartment.addMosquito(&mosquito1); // Add mosquito to the apartment

    Bus bus1("B001"); // Create a bus
    bus1.addStation("Station A"); // Add station to bus
    bus1.addStation("Station B");
    bus1.addCommuter(&commuter1); // Add commuter to bus

    BusStation station("Station A"); // Create a bus station
    station.addBus(&bus1); // Add bus to station
    station.addPerson(&student1); // Add person to station

    station.listBuses(); // List buses at the station
    bus1.listStations(); // List stations for the bus
    bus1.listCommuters(); // List commuters on the bus

    // Move mosquito to the bus
    apartment.moveMosquito(&mosquito1, "Bus");

    return 0;
}
