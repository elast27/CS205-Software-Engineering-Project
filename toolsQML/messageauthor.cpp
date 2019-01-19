#include "messageauthor.h"

MessageAuthor::MessageAuthor(QObject *parent) : QObject(parent)
{

}

MessageAuthor::~MessageAuthor()
{

}

void MessageAuthor::createAuthor(QString name, int id)
{
    m_Name = name;
    m_ID     = id;
}

int MessageAuthor::ID() const
{
    return m_ID;
}

QString MessageAuthor::name() const
{
    return m_Name;
}

void MessageAuthor::setName(QString author)
{
    if(m_Name != author){
      m_Name = author;
      emit nameChanged(author);
    }
}

void MessageAuthor::setID(int ID)
{
    if(m_ID != ID){
        m_ID = ID;
        emit IDChanged(ID);

    }
}
