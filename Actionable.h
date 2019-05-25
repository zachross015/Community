#ifndef ACTIONABLE_H
#define ACTIONABLE_H

#include <map>
#include <string>
#include <type_traits>
#include "Action.h"

/**
 * Defines the requirements for a class to be able to illicit actions.
 */
class Actionable {

public:

    /**
     * Perform the action given as a template parameter on a set of targets. Given
     * the type of action, this uses `Action::performOnTargets` on the target list.
     * @param targets The list of `Targetable` pointers to perform the aciton on.
     */
    template <class A>
    void performActionOnTargets(std::vector<Targetable*> targets) {

        // Ensure the template parameter is an action
		static_assert(std::is_base_of<Action, A>::value == true, "Actionable::performActionOnTargets template must be an action.");

        // Create the action and perform it on the targets
        A a;
        a.parent = this;
		a.performOnTargets(targets);
    };

	virtual ~Actionable() = default;

};

#endif
