#ifndef SWAT_H
#define SWAT_H
#include "firstresponder.h"

/**
 * @brief The SWAT class represents SWAT officers in the field
 * @extends FirstResponder
 */
class SWAT : public FirstResponder
{
public:
    SWAT();
    ~SWAT();
};

#endif // SWAT_H
