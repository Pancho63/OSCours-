#ifndef RECEIVEOSC_H
#define RECEIVEOSC_H

#include <QDebug>
#include "udp.hh"
#include "oscpkt.hh"
using namespace oscpkt;

class Listener : public QObject
        {
            Q_OBJECT
     void requestWork();

signals:
     void workRequested();
     void finished();
     void reboot();
     void messReceived(QString, QVariant);
     void portError();

public slots:
    void goOSC();
    void reStart();

private :

    UdpSocket sock;
};

#endif // RECEIVEOSC_H

