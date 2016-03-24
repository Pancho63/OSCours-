#include "receiveosc.h"
#include <QDebug>

#include "oscpkt.hh"
#include "udp.hh"
using namespace oscpkt;
using std::string;


void Listener::requestWork()
{

    emit workRequested();
}


void Listener::goOSC()
{
  extern int PORT;
    sock.bindTo(PORT);
    if (!sock.isOk()) {
      qDebug() << "Error opening port " << PORT << ": " << endl;
      emit portError();
    } else {
      qDebug() << "Server started, will listen to packets on port " << PORT << endl;
      PacketReader pr;
      while (sock.isOk()) {
        if (sock.receiveNextPacket(30 /* timeout, in ms */)) {
          pr.init(sock.packetData(), sock.packetSize());
          oscpkt::Message *msg;
          while (pr.isOk() && (msg = pr.popMessage()) != 0) {

            float farg;
            int iarg;


           const string  mess = msg->addressPattern();
                if (msg->match(mess).isOkNoMoreArgs()) {
                    emit messReceived(QString::fromStdString(mess), QVariant::Invalid);
                    }
                else if (msg->match(mess).popInt32(iarg).isOkNoMoreArgs()) {
                    emit messReceived(QString::fromStdString(mess), iarg);
                    }
                else if (msg->match(mess).popFloat(farg).isOkNoMoreArgs()) {
                    emit messReceived(QString::fromStdString(mess), farg);
                    }

       }


        }
      }
    }
}

void Listener::reStart()
{
 sock.close();
sleep(0.2);
emit reboot();
}
