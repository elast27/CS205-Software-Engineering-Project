#ifndef MESSAGEBOARD_H
#define MESSAGEBOARD_H

#include <QObject>
#include <QDebug>
#include "message.h"

/**
 * @brief The MessageBoard class represents a board of messages that the ERP can post to
 * Inspiration: http://doc.qt.io/qt-5/qtqml-cppintegration-exposecppattributes.html
 */
class MessageBoard : public QObject
{
    Q_OBJECT
     //*********************************PROPERTIES*********************************//
    Q_PROPERTY(QList<Message*> messages READ messages)
public:
    explicit MessageBoard(QObject *parent = 0);
    virtual ~MessageBoard();

    /**
      * @brief postMessage posts a visible message to the message board
      * @return if posting was successful
      */
    Q_INVOKABLE bool postMessage(Message* msg);

    /**
     * @brief messages returns the list of messages on the board
     * @return m_messages
     */
    QList<Message *> messages();

    /**
     * @brief append_message appends a message to MessageBoard
     * @param a QQmlListProperty that will be casted to a MessageBoard
     * @param msg
     */
    void append_message(Message *msg);

signals:
    void boardCleared();
    void newMessagePosted();
    void messageAdded(Message *msg);

public slots:
    void clear();

private:
    QList<Message *> m_messages;

};

#endif // MESSAGEBOARD_H
