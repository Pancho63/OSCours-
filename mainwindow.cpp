#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "receiveosc.h"
#include <QHostAddress>
#include <QNetworkInterface>
#include <QSettings>
#include <QDebug>
#include "receiveosc.h"
#include "oscpkt.hh"
#include "udp.hh"
#include <QtWidgets>
#include <QMetaType>

using namespace oscpkt;
using std::string;


QString ipAdrr = "127.0.0.1";

QString nomTransl = "transl";
QString PORT_NUMin =  "7001";
    int PORT = PORT_NUMin.toInt();
QString ipOut = "127.0.0.1";
QString PORT_NUMsend =  "7000";
    int listenVal = 0;
QString path;
int indx = 0;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    thread = new QThread();
    listener = new Listener();
    listener->moveToThread(thread);
    modele = new QStandardItemModel(0,7);

    ui->listOsc->setModel(modele);
    ui->listOsc->setColumnWidth(0,180);
    ui->listOsc->setColumnWidth(1,60);
    ui->listOsc->setColumnWidth(2,65);
    ui->listOsc->setColumnWidth(3,180);
    ui->listOsc->setColumnWidth(4,70);
    ui->listOsc->setColumnWidth(5,75);
    ui->listOsc->setColumnHidden(6, true);
    ui->listOsc->setColumnHidden(7, true);

    QStringList names;
    names << "Message In" << "Type In" << "Value In" << "Message Out" << "Type Out" << "Value Out";
    modele->setHorizontalHeaderLabels(names);



    connect(listener, SIGNAL(workRequested()), thread, SLOT(start()));
    connect(thread, SIGNAL(started()), listener, SLOT(goOSC()));
    connect(listener, SIGNAL(reboot()), listener, SLOT(goOSC()));
    thread->start();

    connect(ui->saveButton, SIGNAL(clicked()), this, SLOT(save()));
    connect(ui->loadButton, SIGNAL(clicked()), this, SLOT(load()));
    connect(ui->clearButton, SIGNAL(clicked()), this, SLOT(cleanlistOSC()));
    connect(ui->oscButton, SIGNAL(clicked()), this, SLOT(startOSC()));
    connect(ui->addToList, SIGNAL(clicked()), this, SLOT(addToList()));

    connect(ui->linePortOscOut, SIGNAL(textEdited(QString)), this, SLOT(validePortSend(QString)));
    connect(ui->linePortOscIn, SIGNAL(textEdited(QString)), this, SLOT(validePortIn(QString)));
    connect(ui->lineNomTransl, SIGNAL(textEdited(QString)), this, SLOT(valideNomTransl(QString)));

    connect(ui->lineMsgTxtIn, SIGNAL(textChanged(QString)), this, SLOT(valideTxtIn(QString)));
    connect(ui->lineMsgValIn, SIGNAL(textChanged(QString)), this, SLOT(valideValIn(QString)));
    connect(ui->boxMsgTypeIn, SIGNAL(currentTextChanged(QString)), this, SLOT(valideTypeIn(QString)));

    connect(ui->lineMsgTxtOut, SIGNAL(textEdited(QString)), this, SLOT(valideTxtOut(QString)));
    connect(ui->lineMsgValOut, SIGNAL(textEdited(QString)), this, SLOT(valideValOut(QString)));
    connect(ui->boxMsgTypeOut, SIGNAL(currentTextChanged(QString)), this, SLOT(valideTypeOut(QString)));

    connect(ui->checkValueIn, SIGNAL(toggled(bool)), this, SLOT(valideValOkIn(bool)));
    connect(ui->checkValueOut, SIGNAL(toggled(bool)), this, SLOT(valideValOkOut(bool)));


    connect(listener, SIGNAL(messReceived(QString,QVariant)), this, SLOT(inMess(QString, QVariant)));
    connect(listener, SIGNAL(portError()), this, SLOT(portErrorIn()));

    connect(ui->listOsc, SIGNAL(pressed(QModelIndex)),this, SLOT(setindx(QModelIndex)));

    connect (ui->sendButton, SIGNAL(pressed()), this, SLOT(send()));


    ui->linePortOscIn->setText(PORT_NUMin);
    ui->linePortOscOut->setText(PORT_NUMsend);
    ui->lineNomTransl->setText(nomTransl);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::addToList()
{
if (messageTxtIn=="" || messageTxtOut=="")
    {
    QMessageBox msgBox;
    msgBox.setWindowTitle("OSCours!!");
    msgBox.setText("You MUST enter In and Out Messages !");
    msgBox.exec();
    return;
    }

    QList<QStandardItem *> rowList;
    rowList << new QStandardItem(QString(messageTxtIn));
    rowList << new QStandardItem(QString(messageTypeIn));
    rowList << new QStandardItem(QString(messageValueIn));
    rowList << new QStandardItem(QString(messageTxtOut));
    rowList << new QStandardItem(QString(messageTypeOut));
    rowList << new QStandardItem(QString(messageValueOut));
    rowList << new QStandardItem(QString(messageValOkIn));
    rowList << new QStandardItem(QString(messageValOkOut));
    modele->appendRow(rowList);
    ui->listOsc->setColumnHidden(6, true);
    ui->listOsc->setColumnHidden(7, true);
}

void MainWindow::startOSC()
{
        listener->reStart();
}

void MainWindow::load()
{
    path = (QCoreApplication::applicationDirPath() + "/savesTranslatorOSC/");
    QDir dir(path);
    if (!dir.exists()) {dir.mkpath(".");}

    QString file = QFileDialog::getOpenFileName(this, tr("Open Player"), path , tr("ini Files (*.ini)"));

    if(file.isEmpty()) { return; }

    QFileInfo fileInfo(file);
    nomTransl = fileInfo.baseName();
    QString loadpath = fileInfo.absolutePath();

QFile f( loadpath +"/"+ nomTransl + ".csv");

   if( f.open( QIODevice::ReadOnly ) ){
       QTextStream ts( &f );
       QList<QStringList> list;
       int row = 0, col = 0;

       // read entire file and parse lines into list of stringlist's
       while( !ts.atEnd() ){
           list << ts.readLine().split( "," );
       }

       f.close();  // done with file

       // prep table
       modele->setRowCount( list.count() );  // number of stringlists give row count
       modele->setColumnCount( list[0].count() );  // count of entries from intial stringlist for column count

       foreach( QStringList l, list ){
           foreach( QString str, l ){
               modele->setItem( row, col++, new QStandardItem( str ));
           }
           row++; col=0;
       }
       ui->listOsc->setColumnHidden(6, true);
       ui->listOsc->setColumnHidden(7, true);
   }


    QSettings settings(path + nomTransl + ".ini", QSettings::IniFormat) ;

    PORT_NUMin = settings.value("portin", "7001").toString();
    PORT_NUMsend = settings.value("portsend", "7000").toString();

    ui->lineNomTransl->setText(nomTransl);
    ui->linePortOscIn->setText(PORT_NUMin);
    PORT = PORT_NUMin.toInt();
    startOSC();
    ui->linePortOscOut->setText(PORT_NUMsend);

}
void MainWindow::save()
{
    path = (QCoreApplication::applicationDirPath() + "/savesTranslatorOSC/");
    QDir dir(path);
    if (!dir.exists()) {
        dir.mkpath(".");}
    if (!(modele->rowCount()==0))
    {
        QFile f( path + nomTransl + ".csv" );

        if( f.open( QIODevice::WriteOnly ) ){
            QTextStream ts( &f );
            QStringList strList;

            for( int r = 0; r < modele->rowCount(); ++r ){
                strList.clear();
                for( int c = 0; c < modele->columnCount(); ++c ){
                    strList << ""+ modele->item( r, c )->text()+"";
                }
                                    qDebug() << strList;
                ts << strList.join( "," )+"\n";
            }
            f.close();
        }
    }
    QSettings settings(path + nomTransl + ".ini", QSettings::IniFormat) ;
    settings.setValue("portin", PORT_NUMin);
    settings.setValue("portsend", PORT_NUMsend);
    QMessageBox msgBox;
    msgBox.setWindowTitle("OSCours!!");
     msgBox.setText("Saved");
     msgBox.exec();

}

void MainWindow::setindx(const QModelIndex &index)
{
   indx = index.row();
}


void MainWindow::cleanlistOSC()
{
   if (!(modele->rowCount()==0))
        {
            modele->removeRow(indx);
        }
}

void MainWindow::valideNomTransl(QString nom)
{
    nomTransl = nom;
}

void MainWindow::validePortSend(QString por)
{
    path = (QCoreApplication::applicationDirPath() + "/savesTranslatorOSC/");
    PORT_NUMsend = por;
    QDir dir(path);
        if (!dir.exists()) {
           dir.mkpath(".");}
    QSettings settings(path + nomTransl + ".ini", QSettings::IniFormat) ;
    settings.setValue("portsend", por);
}

void MainWindow::validePortIn(QString por)
{
    path = (QCoreApplication::applicationDirPath() + "/savesTranslatorOSC/");
    PORT_NUMin = por;
    QDir dir(path);
    if (!dir.exists()) {
        dir.mkpath(".");}
    QSettings settings(path + nomTransl + ".ini", QSettings::IniFormat) ;
    settings.setValue("portin", por);
        PORT = PORT_NUMin.toInt();
}

void MainWindow::valideTxtIn(QString txt)
{
        messageTxtIn = txt;
}

void MainWindow::valideValIn(QString txt)
{
        if (messageValOkIn=="true")
        {messageValueIn = txt;}
        else messageValueIn = "";
}

void MainWindow::valideTypeIn(QString txt)
{
        messageTypeIn = txt;
}

void MainWindow::valideTxtOut(QString txt)
{
        messageTxtOut = txt;
}

void MainWindow::valideValOut(QString txt)
{
    if (messageValOkOut=="true")
    {messageValueOut = txt;}
    else messageValueOut = "";
}

void MainWindow::valideTypeOut(QString txt)
{
        messageTypeOut = txt;
}

void MainWindow::valideValOkIn(bool ok)
{
       if (ok) {messageValOkIn = "true";}
             else  messageValOkIn = "";
}
void MainWindow::valideValOkOut(bool ok)
{
    if (ok) {messageValOkOut = "true";}
          else  messageValOkOut = "";
                valideValOut("");
                ui->lineMsgValOut->setText("");
}

void MainWindow::send()
{
UdpSocket sock;
 sock.connectTo(ipOut.toStdString(), PORT_NUMsend.toStdString());
 if (!sock.isOk()) {
    qDebug() << "Error connection to port " << PORT_NUMsend << endl;}

 else
 {
   if (messageTxtOut=="") {QMessageBox msgBox;
       msgBox.setWindowTitle("OSCours!!");
        msgBox.setText("You MUST enter a Out Message !");
        msgBox.exec();}

   else
   if (messageTypeOut==0)
     {
     Message msg(messageTxtOut.toStdString());
     PacketWriter pw;
     pw.startBundle().startBundle().addMessage(msg).endBundle().endBundle();
     sock.sendPacket(pw.packetData(), pw.packetSize());
     sock.close();
     }

   if (messageTypeOut=="float")
     {
     Message msg(messageTxtOut.toStdString());msg.pushFloat(messageValueOut.toFloat());
     PacketWriter pw;
     pw.startBundle().startBundle().addMessage(msg).endBundle().endBundle();
     sock.sendPacket(pw.packetData(), pw.packetSize());
     sock.close();
     }
   if (messageTypeOut=="int")
     {
     Message msg(messageTxtOut.toStdString());msg.pushInt32(messageValueOut.toInt());
     PacketWriter pw;
     pw.startBundle().startBundle().addMessage(msg).endBundle().endBundle();
     sock.sendPacket(pw.packetData(), pw.packetSize());
     sock.close();
     }
 }
}


void MainWindow::inMess(QString mess, QVariant val)
{
    UdpSocket sock;
     sock.connectTo(ipOut.toStdString(), PORT_NUMsend.toStdString());
     if (!sock.isOk()) {
        qDebug() << "Error connection to port " << PORT_NUMsend << endl;}

else
{
    QString type = val.typeName();

    if (ui->checkListen->isChecked())
        {
        ui->lineMsgTxtIn->setText(mess);
        if (type == "")
            {
            ui->lineMsgValIn->setText("");
            ui->boxMsgTypeIn->setCurrentIndex(0);
            }
        if (type=="int")
            {
            ui->lineMsgValIn->setText(val.toString());
            ui->boxMsgTypeIn->setCurrentIndex(1);
            }
        if (type == "float")
            {
            ui->lineMsgValIn->setText(val.toString());
            ui->boxMsgTypeIn->setCurrentIndex(2);
            }
        if (type=="bool")
            {
            ui->lineMsgValIn->setText(val.toString());
            ui->boxMsgTypeIn->setCurrentIndex(3);
            }
        }

    QString mesTxIn;
    QString mesTyIn;
    QString mesValIn;
    QString mesTxOut;
    QString mesTyOut;
    QString mesValOut;
    QString mesValInOk;
    QString mesValOutOk;

for(int i=0; i<modele->rowCount(); ++i)
    {
     mesTxIn = modele->item( i, 0 )->text();
     mesTyIn = modele->item( i, 1 )->text();
     mesValIn = modele->item( i, 2 )->text();
     mesTxOut = modele->item( i, 3 )->text();
     mesTyOut = modele->item( i, 4 )->text();
     mesValOut = modele->item( i, 5 )->text();
     mesValInOk = modele->item( i, 6 )->text();
     mesValOutOk = modele->item( i, 7 )->text();



     if (mesValOutOk=="true")
     {val=mesValOut;}



     if (!(mesValInOk=="true") || val==mesValIn)
     {
if (mesTxIn == mess && mesTyIn == type)
        {

    if (mesTyOut == "")
            {
            Message msg(mesTxOut.toStdString());msg.pushFloat(val.toFloat());
            PacketWriter pw;
            pw.startBundle().startBundle().addMessage(msg).endBundle().endBundle();
            sock.sendPacket(pw.packetData(), pw.packetSize());
            sock.close();
            }
    else if (mesTyOut == "int")
            {
            Message msg(mesTxOut.toStdString());msg.pushInt32(val.toInt());
            PacketWriter pw;
            pw.startBundle().startBundle().addMessage(msg).endBundle().endBundle();
            sock.sendPacket(pw.packetData(), pw.packetSize());
            sock.close();
            }
        else if (mesTyOut == "float")
            {
            Message msg(mesTxOut.toStdString());msg.pushFloat(val.toFloat());
            PacketWriter pw;
            pw.startBundle().startBundle().addMessage(msg).endBundle().endBundle();
            sock.sendPacket(pw.packetData(), pw.packetSize());
            sock.close();
            }
        }
    }

     }

}
}

void MainWindow::portErrorIn()
{
    QMessageBox msgBoxNA;
msgBoxNA.setWindowTitle("OSCours!!");
 msgBoxNA.setText("Port non accessible");
 msgBoxNA.exec();
 ui->linePortOscIn->setText("0000");
}
