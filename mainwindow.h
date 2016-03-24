#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QThread>


#include "receiveosc.h"

QT_BEGIN_NAMESPACE
class QAbstractItemView;
class QLabel;
class QModelIndex;
class QPushButton;
class QSlider;
class QLineEdit;
class QStandardItemModel;
class QStandardItem;
QT_END_NAMESPACE


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QString messageTxtIn;
    QString messageValueIn;
    QString messageTypeIn;

    QString messageTxtOut;
    QString messageValueOut;
    QString messageTypeOut;

    QString messageValOkIn;
    QString messageValOkOut;


private slots:
    void save();
    void load();
    void cleanlistOSC();
    void setindx(const QModelIndex &index);

    void valideNomTransl(QString);
    void validePortSend(QString);
    void validePortIn(QString);
    void valideTxtIn(QString);
    void valideValIn(QString);
    void valideTypeIn(QString);
    void valideTxtOut(QString);
    void valideValOut(QString);
    void valideTypeOut(QString);
    void valideValOkIn(bool);
    void valideValOkOut(bool);


    void inMess(QString, QVariant);
    void portErrorIn();

    void startOSC();
    void addToList();
    void send();


private:
    Ui::MainWindow *ui;

    QThread *thread;
    Listener *listener;
    QStandardItemModel *modele;
};

#endif // MAINWINDOW_H
