#ifndef FIRSTRESPONDER_H
#define FIRSTRESPONDER_H
#include "../public/person.h"
#include <string>

class FirstResponder : public Person
{
public:
    FirstResponder();

    std::string occupation;
    int id;
    bool isActive;
};

#endif // FIRSTRESPONDER_H
