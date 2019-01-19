#include "citizen.h"

Citizen::Citizen(QObject *parent) : Person(parent)
{
    this->m_priority = Citizen::Priority::VeryLow;

}

Citizen::~Citizen()
{

}

Citizen::Priority Citizen::priority() const {
    return m_priority;
}

void Citizen::setPriority(Priority priority)
{
    if (priority != m_priority) {
           m_priority = priority;
           emit priorityChanged(priority);
       }
}

void Citizen::send_distress_message()
{
    this->m_active = true;
    qDebug() << "Person " << this->m_ID << " needs help!";
    this->m_priority = Citizen::Priority::Low;
    emit activeChanged(m_active);
}

void Citizen::get_saved()
{
    this->m_active =false;
    qDebug() << "Person " << this->m_ID << " is no longer in danger";
    this->m_priority = Citizen::Priority::VeryLow;
    emit activeChanged(m_active);
}

