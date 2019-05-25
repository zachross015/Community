#ifndef TARGETABLE_H
#define TARGETABLE_H

/**
 * Defines the requirements for a class to be targetable. A targetable class
 * can be the recipient of any `Action` triggered by a class that is `Actionable`.
 */
class Targetable {
public:
	virtual ~Targetable() = default;
};

#endif
