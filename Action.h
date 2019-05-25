#ifndef ACTION_H
#define ACTION_H

#include <vector>
#include "Targetable.h"

class Actionable;

/**
 * Abstract class that defines the requirements for an `Action` in the game.
 */
class Action {

public:
    Actionable* parent;
    Action(){};

    /**
     * The abstract function that acts as the action to place on a set of targets.
     * Overriding this will define the action to be used on the target list.
     * @param targets The list of targets that the action is performed on
     */
    virtual void performOnTargets(std::vector<Targetable*>) {};

};

#endif
