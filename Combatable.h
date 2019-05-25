#ifndef COMBATABLE_H
#define COMBATABLE_H

#include "Fightable.h"
#include "Destructible.h"
#include "Targetable.h"
#include "Actionable.h"

/**
 * Defines the requirements for a class to be able to enter combat. There are a
 * couple of desirable traits for such situations, since combat will occur using
 * a series of actions between two fightable and destructible objects.
 */
class Combatable: public Destructible, public Fightable, public Targetable, public Actionable {};

#endif
