#include <iostream>

class Passenger {
    std::string name;
    std::string surname;
    int yearOfBirth;

public:
    Passenger() {
        name = "none";
        surname = "none";
        yearOfBirth = 0;
    }

    Passenger(std::string i, std::string n, int yob) {
        name = i;
        surname = n;
        yearOfBirth = yob;
    }

    Passenger(const Passenger& copy) {
        name = copy.name;
        surname = copy.surname;
        yearOfBirth = copy.yearOfBirth;
        std::cout << "Copying passenger data: " << copy.name << " " << copy.surname << " " << std::endl;
    }

    void display() {
        std::cout << " Name: " << name << std::endl << " Surname: " << surname << std::endl << "Year of birth: " << yearOfBirth << std::endl;
    }
};

class Coach {
    std::string destination;
    int maxSpeed;
    const static int seats = 8;
    Passenger* passengers[seats]; // array of 8 pointers
    int firstFree = 0;

public:
    Coach(std::string d, int ms, Passenger* tab[]) {
        destination = d;
        maxSpeed = ms;
        int seatsTaken = 0;
        if (tab != nullptr) // if 0(tab[]=nullptr) passengers then we will not enter the loop
            for (int i = 0; i < seats; i++) {
                if (sizeof(tab) >= i) {
                    passengers[i] = tab[i]; // we add to the coach only when tab[] >i
                    firstFree++;
                }
            }
    }

    Coach(const Coach& other) {
        destination = other.destination;
        for (int i = 0; i < seats; i++) {
            passengers[i] = other.passengers[i];
        }
        maxSpeed = 130; // changed as requested
        firstFree = other.firstFree;
    }

    void addPassenger(Passenger* newPassenger) {
        if (firstFree < seats) {
            passengers[firstFree] = newPassenger;
            firstFree++;
        } else {
            std::cout << "Seat limit exceeded." << std::endl;
        }
    }

    void display() {
        std::cout << "Free seats: " << seats - firstFree << std::endl;
        std::cout << "Destination: " << destination << std::endl;
        std::cout << "Maximum coach speed: " << maxSpeed << " km/h" << std::endl;
        std::cout << "Passengers:" << std::endl;

        for (int i = 0; i < seats; i++) {
            passengers[i]->display(); // passengers[i] is a pointer to a passenger, so instead of a dot there is an arrow
        }
    }
};


int main() {

    Passenger passenger1; //default
    Passenger passenger2("Mike", "Wazowski", 1999); //multi-argument
    Passenger passenger3(passenger2);  //copy
    passenger1.display();
    passenger2.display();
    passenger3.display();
    std::cout << std::endl;
    std::cout << std::endl;

    Passenger passengers[50]; // 50 default passengers


    Coach first("Cracow", 170, nullptr); // NULL -> we pass an empty array

    Passenger* a = &passenger1;
    Passenger* b = &passenger2;
    Passenger* c = &passenger3;
    first.addPassenger(a);
    first.addPassenger(b);
    first.addPassenger(c);

    for (int i = 0; i < 50; i++) {
        first.addPassenger(&passengers[i]);
    }

    std::cout << std::endl;
    std::cout << std::endl;

    first.display();

    std::cout << std::endl;
    std::cout << std::endl;

    Coach second(first);//second from first
    second.display();
    return 0;
}
