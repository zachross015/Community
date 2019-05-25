#include <iostream>
#include <string>
#include <vector>
#include "Combatable.h"
#include "Action.h"

class Person: public Combatable {
    int h, mh;
    int ba, bd;
    std::string n;
public:

    bool shouldBeDestroyed() { return h < 0; };
    int& health() { return h; };
    int maxHealth() { return mh; };

    int baseAttackStat() { return ba; };
    int baseDefenseStat() { return bd; };

    Person(std::string na, int ma, int a, int d) {
        n = na;
        mh = h = ma;
        ba = a;
        bd = d;
    }

    std::string name() { return n; };

};

void printPerson(Person p) {
	std::cout << p.name() << " | Health : " << p.health() << " / " << p.maxHealth();
	std::cout << " | Attack : " << p.baseAttackStat() << " | Defense : " << p.baseDefenseStat();
	std::cout << std::endl;
}

class Hit : public Action {
public:
	void performOnTargets(std::vector<Targetable*> t) {
		Combatable* combatParent = (Combatable*)(parent);
		for (size_t i = 0; i < t.size(); i++) {
			Combatable* target = (Combatable*)(t[i]);
			target->health() -= (combatParent->baseAttackStat() - target->baseDefenseStat());
		}
	}
};

class Heal : public Action {
public:

	void performOnTargets(std::vector<Targetable*> t) {
		Combatable* combatParent = (Combatable*)(parent);
		for (size_t i = 0; i < t.size(); i++) {
			Combatable* target = (Combatable*)(t[i]);
			target->health() += (combatParent->baseAttackStat());
		}
	}

};

int main(int argc, char const *argv[]) {
      std::cout << "Hello World!" << std::endl;
      Person billy("Billy", 100, 15, 5);
      Person joe("Joe", 100, 15, 5);
	  Person tim("Tim", 100, 15, 5);
      printPerson(billy);
      printPerson(joe);
	  printPerson(tim);
	  std::vector<Targetable*> t;
	  t.push_back(&joe);
	  t.push_back(&tim);
	  billy.performActionOnTargets<Hit>(t);
      printPerson(billy);
      printPerson(joe);
	  printPerson(tim);
      billy.performActionOnTargets<Heal>(t);
      printPerson(billy);
      printPerson(joe);
	  printPerson(tim);

	  int temp;
	  std::cin >> temp;
      return 0;
}
