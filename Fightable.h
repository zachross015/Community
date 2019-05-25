#ifndef FIGHTABLE_H
#define FIGHTABLE_H

/**
 * Defines the requirements for a class to be able to fight.
 *
 * The only base stats right now are attack and defense levels, but eventually
 * this should include things such as special stats, stamina, mana, etc.
 */
class Fightable {

public:

    /**
     * The base attack level getter for an object of the fightable class. This can be
     * mutated to include various external sources as part of the base attack.
     * @return An integer representing the base attack stat for this fightable object.
     */
    virtual int baseAttackStat() = 0;

    /**
     * The base defense level getter for an object of the fightable class. This can be
     * mutated to include various external sources as part of the base defense.
     * @return An integer representing the base defense stat for this fightable object.
     */
    virtual int baseDefenseStat() = 0;

};

#endif
