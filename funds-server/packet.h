#ifndef PACKET_H
#define PACKET_H

#include <QObject>

class packet : public QObject
{
    Q_OBJECT
public:
    explicit packet(QObject *parent = 0);

signals:

public slots:

};

#endif // PACKET_H
