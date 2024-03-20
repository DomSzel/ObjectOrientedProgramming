#include <iostream>
#include <string>
#include <cstdlib>

class Item {
public:
    Item() {
        name = "none";
        attack = (rand() % 101) + 100; // maximum remainder from dividing a large number by 101 is 100, it should start from 100 that's why "+100"
        defense = rand() % 101; // should start from 0
    }
    Item(std::string _n) {
        name = _n;
        attack = (rand() % 101) + 100;
        defense = rand() % 101;
    }
    void displayItem() {
        std::cout << "name: " << name << " attack: " << attack << " defense: " << defense << std::endl;
    }
    int getAttack() { return attack; }
    int getDefense() { return defense; }
private:
    std::string name;
    int attack;
    int defense;
};

class Hero {
    std::string pseudonym;
    std::string class_;
    int lifePoints;
    Item equipment[4];
public:
    Hero() {
        pseudonym = "none";
        class_ = "human";
        lifePoints = 1200;
        equipment[0] = Item("p1");
        equipment[1] = Item("p2");
        equipment[2] = Item("p3");
        equipment[3] = Item("p4");
        std::cout << "Hero()" << std::endl;
    }
    Hero(std::string _p, std::string _k, int _pz, Item _e[]) { // multi-argument constructor
        pseudonym = _p;
        class_ = _k;
        lifePoints = _pz;
        equipment[0] = _e[0];
        equipment[1] = _e[1];
        equipment[2] = _e[2];
        equipment[3] = _e[3];
        std::cout << "Hero(multi)" << std::endl;
    }

    std::string getPseudonym() { return pseudonym; }
    int getLifePoints() { return lifePoints; }

    void displayHero() {
        std::cout << "pseudonym: " << pseudonym << " class: " << class_ << " life points: " << lifePoints << std::endl;
        for (int i = 0; i < 4; i++) {
            equipment[i].displayItem(); // calls the method of the item object
        }
    }

    int sumAttack() {
        int sumA = 0;

        for (int j = 0; j < 4; j++) {
            sumA += equipment[j].getAttack(); // add the attack of the j-th item from the equipment to zero
        }
        return sumA;
    }

    int sumDefense() {
        int sumO = 0;

        for (int k = 0; k < 4; k++) {
            sumO += equipment[k].getDefense(); // add the defense of the k-th item from the equipment to zero
        }
        return sumO;
    }

    void reduceLife(int damage) {
        lifePoints -= damage;
        //if (lifePoints < 0)
        // std::cout << "hero" << pseudonym << "dies!!!" << std::endl;
    }
};

void Duel(Hero& hero1, Hero& hero2) { // thanks to the reference we pass the heroes from main to the duel function instead of a copy
    hero1.reduceLife(hero2.sumAttack() - hero1.sumDefense()); // reducing the life of hero 1/attacks hero 2
    hero2.reduceLife(hero1.sumAttack() - hero2.sumDefense()); // reducing the life of hero 2/attacks hero 1

    if (hero1.getLifePoints() > hero2.getLifePoints())
        std::cout << "The winner is : " << hero1.getPseudonym() << std::endl;

    if (hero1.getLifePoints() < hero2.getLifePoints())
        std::cout << "The winner is : " << hero2.getPseudonym() << std::endl;

    if (hero1.getLifePoints() == hero2.getLifePoints())
        std::cout << "It's a tie!" << std::endl;

    int main() {
        srand(time(NULL));
        Item tab[4] = { Item("knife"), Item("bazooka"), Item("saber"), Item("spike") };

        Hero hero1; // automatically creates a default hero (= Bohater bohater1= Bohater();

        // Multi-argument constructor used to create hero2 with specific values
        Hero hero2("Dominika", "krasnolod", 1000, tab);

        std::cout << std::endl;
        hero1.displayHero();
        std::cout << std::endl;
        hero2.displayHero();

        Duel(hero1, hero2);


         hero1.displayHero();
         std::cout << std::endl;
         hero2.displayHero(); // check if life points are correct

        return 0;
    }
