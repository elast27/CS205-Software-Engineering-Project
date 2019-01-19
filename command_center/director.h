#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "../public/person.h"

/**
 * @brief The Director class runs the command center and dispatches first responders
 */
class Director : public Person
{
public:
    Director();
    ~Director();
};

#endif // DIRECTOR_H
