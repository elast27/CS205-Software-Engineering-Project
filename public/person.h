#ifndef PERSON_H
#define PERSON_H

#include <QObject>
#include <QWidget>
#include <QDebug>

class Person : public QObject
{
    Q_OBJECT
public:
    explicit Person(QObject *parent = nullptr);
    virtual ~Person();
signals:

public slots:
};

#endif // PERSON_H
