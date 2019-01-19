#ifndef MESSAGEBODY_H
#define MESSAGEBODY_H

#include <QObject>

/**
 * @brief The MessageBody class represents a message body
 */
class MessageBody : public QObject
{
    Q_OBJECT
      //******************************PROPERTIES***************************//
    Q_PROPERTY(QString text READ text WRITE setText NOTIFY textChanged)
public:
    explicit MessageBody(QObject *parent = 0);
    virtual ~MessageBody();
     //******************************PUBLIC METHODS***************************//
    /**
     * @brief initializeText initializes the text of this message body
     * @param text the text to give the MessageBody
     */
    Q_INVOKABLE void initialize(QString text);

    /**
     * @brief text the text of this message body
     * @return m_text
     */
    QString text() const;


signals:
    void textChanged(QString text);

public slots:
    void setText(QString text);

private:
    QString m_text;
};

#endif // MESSAGEBODY_H
