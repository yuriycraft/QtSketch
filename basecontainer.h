#ifndef BASECONTAINER_H
#define BASECONTAINER_H

#include <QObject>

class BaseContainer : public QObject
{
    Q_OBJECT

public:
    explicit BaseContainer(QObject *parent = nullptr);
};

#endif // BASECONTAINER_H
