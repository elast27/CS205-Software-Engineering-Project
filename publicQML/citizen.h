#ifndef CITIZEN_H
#define CITIZEN_H

#include "person.h"

/**
 * @brief The Citizen class represents a public member
 */
class Citizen : public Person
{
    Q_OBJECT
public:
    explicit Citizen(QObject *parent);
    ~Citizen();

    //************************ENUM FOR PRIORITY*******************////
  enum Priority { VeryLow, Low, High, VeryHigh };
  Q_ENUM(Priority)

  /**
     * @brief priority returns this person's priority
     * @return this person's priority as an int
     */
    Priority priority() const;

    /**
      *@brief send_distress_message contacts the command center that this person is in need of help
      * This method sets the person's active status to true
      *
      */
    Q_INVOKABLE void send_distress_message();

    /**
      *@breif get_saved makes this citizen inactive and not in distress
      */
    Q_INVOKABLE void get_saved();

signals:
    void priorityChanged(Priority priority);

public slots:
    void setPriority(Priority priority);

private:
    Priority m_priority;     //priorty for the person

};


#endif // CITIZEN_H
