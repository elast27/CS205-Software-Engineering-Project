#include "messageboard.h"

MessageBoard::MessageBoard(QObject *parent) : QObject(parent)
{

}

MessageBoard::~MessageBoard()
{
    for(auto itr = m_messages.begin(); itr != m_messages.end(); itr++)
    {
        delete *itr;
    }

}

QList<Message *> MessageBoard::messages()
{
    return m_messages;
}

void MessageBoard::append_message(Message *msg)
{
   m_messages.append(msg);
   emit messageAdded(msg);
}

bool MessageBoard::postMessage( Message* msg)
{
    qDebug() << "Calling postMessage from MessageBoard with " << msg;
    return true;
}

void MessageBoard::clear()
{
    m_messages.clear();
    emit boardCleared();
}
