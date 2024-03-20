#include <iostream>
#include <string>
#include <algorithm>

class Animal {
protected:
    std::string name;
    double weight;
    int numberOfLegs;

public:
    Animal(const std::string name = "brak", double weight = 0.0, int numberOfLegs = 0) // parametric constructor
            : name(name), weight(weight), numberOfLegs(numberOfLegs) {}

    void display() // can display everything that inherits from the base class
    {
        std::cout << "name: " << name << " weight: " << weight << " number of legs: " << numberOfLegs << std::endl;
    }

    double getWeight()
    {
        return weight;
    }
};

class Dog : public Animal // public inheritance, Dog inherits from Animal class
{
public:
    Dog(std::string name = " none ", double weight = 0.0, int numberOfLegs = 0, std::string breed = " kundel ", std::string coatColor = " brak ")
            : Animal(name, weight, numberOfLegs), breed(breed), coatColor(coatColor) {} // can use the constructor of the older (inherited) class

    void display() // can display everything that inherits from the base class
    {
        std::cout << "name: " << name << " weight: " << weight << " number of legs: " << numberOfLegs << " breed: " << breed << " color: " << coatColor << std::endl;
    }

private:
    std::string breed;
    std::string coatColor;
};

class Parrot : public Animal
{
public:
    Parrot(std::string name, double weight, int numberOfLegs, std::string featherColor)
            : Animal(name, weight, numberOfLegs), featherColor(featherColor) {}

    Parrot(const Parrot& other)
    {
        name = other.name + " copy ";
        weight = other.weight + 1;
        numberOfLegs = other.numberOfLegs;
        featherColor = other.featherColor;
    }

    void display() // can display everything that inherits from the base class
    {
        std::cout << "name: " << name << " weight: " << weight << " number of legs: " << numberOfLegs << " color: " << featherColor << std::endl;
    }

private:
    std::string featherColor;
};

bool compareWeight(Animal* a, Animal* b)
{
    return a->getWeight() < b->getWeight(); // true when b is bigger
}

void sort(Animal* array[], int size)
{
    std::sort(array, array + size, compareWeight); // array is a pointer to the beginning and array plus size is a pointer to the end
}

int main()
{

    Animal animal1("Animal", 10.0, 4);
    animal1.display();


    Dog* dogPtr = new Dog("Simba", 12.0, 4, "mutt", "ginger");
    dogPtr->display(); // dynamic dog


    Parrot parrot1("bumbum", 5.0, 2, "colorful");
    Parrot parrot2 = parrot1;
    parrot2.display();


    Animal** animalArray = new Animal* [4];
    animalArray[0] = &animal1;
    animalArray[1] = dogPtr;
    animalArray[2] = &parrot1;
    animalArray[3] = &parrot2;
    std::cout << std::endl << "Array: " << std::endl;

    // Displaying array data
    for (int i = 0; i < 4; i++) {
        animalArray[i]->display();
    }

    // Sorting the array of pointers
    sort(animalArray, 4);

    // Displaying the sorted array
    std::cout << "Sorted array:" << std::endl;
    for (int i = 0; i < 4; i++) {
        animalArray[i]->display();
    }

    delete dogPtr;

