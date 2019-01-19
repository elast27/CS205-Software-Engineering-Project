#include "message.h"

Message::Message(QObject *parent) : QObject(parent)
{

}

Message::~Message()
{
    delete m_author;
    delete m_body;
}

void Message::initialize(MessageAuthor *author, MessageBody *body)
{
    this->m_author = author;
    this->m_body   = body;
}

void Message::setAuthor(MessageAuthor *author)
{
    if(author != m_author){
        m_author = author;
        emit authorChanged(author);
    }
}

void Message::setBody(MessageBody * b)
{
    if(b != m_body){
        m_body = b;
        emit bodyChanged(b);
    }
}

MessageAuthor* Message::author() const
{
    return m_author;
}

MessageBody* Message::body() const
{
    return m_body;
}
