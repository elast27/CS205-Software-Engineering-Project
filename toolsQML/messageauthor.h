#ifndef MESSAGEAUTHOR_H
#define MESSAGEAUTHOR_H

#include <QObject>

/**
 * @brief The MessageAuthor class represents the author of a message, contains ID and name
 */
class MessageAuthor : public QObject
{
    Q_OBJECT

    //*********************************PROPERTIES*********************************//
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(int ID READ ID WRITE setID NOTIFY IDChanged)

public:
    explicit MessageAuthor(QObject *parent = nullptr);
    virtual ~MessageAuthor();

     //*********************************PUBLIC METHOD*********************************//

    /**
     * @brief createAuthor creats a MessageAuthor
     * @param name the name for the author
     * @param id the id for the author
     */
    void createAuthor(QString name, int id);

    /**
     * @brief name returns this MessageAuthor's name
     * @return m_Name
     */
    QString name() const;

    /**
     * @brief ID returns this MessageAuthor's ID
     * @return m_ID
     */
    int ID() const;

signals:
    void nameChanged(QString name);
    void IDChanged(int ID);

public slots:
    void setName(QString name);
    void setID(int ID);


private:
    QString m_Name;
    int m_ID;
};

#endif // MESSAGEAUTHOR_H
