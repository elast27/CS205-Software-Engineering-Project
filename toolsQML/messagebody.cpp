#include "messagebody.h"

MessageBody::MessageBody(QObject *parent) : QObject(parent)
{

}

MessageBody::~MessageBody()
{

}

void MessageBody::initialize(QString text)
{
    this->m_text = text;
}

QString MessageBody::text() const
{
    return m_text;
}

void MessageBody::setText(QString text)
{
    if(text != m_text)
    {
        m_text = text;
        emit textChanged(text);

    }
}
