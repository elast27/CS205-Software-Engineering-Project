#ifndef ERP_H
#define ERP_H
#include "../public/person.h"

/**
 * @brief The ERP class represents an Emergency Response Planner: the person who oversees/coordinates first responders, and recieves information from first responders
 */
class ERP : public Person
{
public:
    ERP();
    ~ERP();
};

#endif // ERP_H
