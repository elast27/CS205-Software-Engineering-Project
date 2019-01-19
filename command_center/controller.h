#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <QObject>
#include <QDebug>

/**
 * @brief The Controller class represents the control flow of information from command center to the stakeholders
 */
class Controller : public QObject
{
public:
    Controller();
    ~Controller();
};

#endif // CONTROLLER_H
