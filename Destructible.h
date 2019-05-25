#ifndef DESTRUCTIBLE_H
#define DESTRUCTIBLE_H

/**
 * Defines the requirements for an object to be destructible. Generally,
 * something destructible should have health values and should only be destroyed
 * once this health value reaches zero, but this abstraction allows for other
 * definitions on destructibility.
 */
class Destructible {

public:
    /**
     * Boolean exclaiming whether or not this destructible object has reached
     * a low enough health to be destroyed (Health below 0).
     * @return True if health has reached 0, False if above
     */
    virtual bool shouldBeDestroyed() = 0;

    /**
     * Getter for the value of this destructible object's health
     * @return Integer representing health value
     */
    virtual int& health() = 0;

    /**
     * Getter for the value of this destructible object's maximum health
     * @return Integer representing max health value
     */
    virtual int maxHealth() = 0;
};

#endif
