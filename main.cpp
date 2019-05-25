#include <iostream>
#include <string>

#include "Combatable.h"

class Person: Combatable {
    int h, mh;
    int ba, bd;
    std::string n;
public:

    Person(std::string na, int ma, int a, int d) { n = na; mh = h = ma; ba = a; bd = d; }

    bool shouldBeDestroyed() { return h < 0; };
    int health() { return h; };
    int maxHealth() { return mh; };

    int attack() { return ba; };
    int defense() { return bd; };

    std::string name() { return n; };

    void hit(Person &p) {
        p.h -= (attack() - p.defense());
    }
};

void printPerson(Person p) {
    std::cout << p.name() << " | Health : " << p.health() << " / " << p.maxHealth();
    std::cout << " | Attack : " << p.attack() << " | Defense : " << p.defense();
    std::cout << std::endl;
}

int main(int argc, char const *argv[]) {
      std::cout << "Hello World!" << std::endl;
      Person billy("Billy", 100, 15, 5);
      Person joe("Joe", 100, 15, 5);
      printPerson(billy);
      printPerson(joe);
      billy.hit(joe);
      printPerson(billy);
      printPerson(joe);
      return 0;
}
