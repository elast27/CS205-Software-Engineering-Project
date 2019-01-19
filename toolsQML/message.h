#ifndef MESSAGE_H
#define MESSAGE_H

#include <QObject>
#include "messagebody.h"
#include "messageauthor.h"


/**
 * @brief The Message class represents a message that an ERP can send to the public
 */
class Message : public QObject
{
    Q_OBJECT
    Q_PROPERTY(MessageAuthor *author READ author WRITE setAuthor NOTIFY authorChanged)
    Q_PROPERTY(MessageBody* Body READ body WRITE setBody NOTIFY bodyChanged)
public:
    explicit Message(QObject *parent = 0);
    virtual ~Message();

    /**
      * Method initialize
      * @param author the MessageAuthor for the message
      * @param text the text for the message
      */
    Q_INVOKABLE void initialize(MessageAuthor* author, MessageBody* body);

    /**
     * @brief author returns this message's author
     * @return this message's author
     */
    MessageAuthor *author() const;

    /**
     * @brief body returns this message's body
     * @return this message's body
     */
    MessageBody *body() const;


signals:
    void authorChanged(MessageAuthor* a);
    void bodyChanged(MessageBody* b);

public slots:
    void setAuthor(MessageAuthor* a);
    void setBody(MessageBody* b);
private:
    MessageAuthor *m_author;
    MessageBody *m_body;
};

#endif // MESSAGE_H
