#ifndef POLICE_H
#define POLICE_H
#include "firstresponder.h"

/**
 * @brief The Police class represents a policeman in the field
 * @extends FirstResponder
 */
class Police : public FirstResponder
{
public:
    Police();
    ~Police();
};

#endif // POLICE_H
