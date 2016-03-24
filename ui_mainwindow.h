/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QLineEdit *lineMsgValIn;
    QLabel *label_12;
    QLabel *label;
    QPushButton *oscButton;
    QLabel *label_8;
    QLineEdit *linePortOscIn;
    QLabel *label_14;
    QLabel *label_3;
    QLineEdit *lineMsgTxtOut;
    QLineEdit *lineMsgValOut;
    QComboBox *boxMsgTypeOut;
    QCheckBox *checkListen;
    QLabel *label_2;
    QPushButton *clearButton;
    QPushButton *sendButton;
    QLabel *label_6;
    QLabel *label_10;
    QLineEdit *linePortOscOut;
    QLabel *label_5;
    QPushButton *addToList;
    QFrame *frame;
    QGridLayout *gridLayout_2;
    QLabel *label_9;
    QLineEdit *lineNomTransl;
    QPushButton *saveButton;
    QPushButton *loadButton;
    QLineEdit *lineMsgTxtIn;
    QLabel *label_4;
    QFrame *line;
    QComboBox *boxMsgTypeIn;
    QLabel *label_13;
    QTableView *listOsc;
    QCheckBox *checkValueIn;
    QCheckBox *checkValueOut;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(680, 570);
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(680, 321));
        MainWindow->setBaseSize(QSize(500, 0));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(10);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        lineMsgValIn = new QLineEdit(centralWidget);
        lineMsgValIn->setObjectName(QStringLiteral("lineMsgValIn"));
        lineMsgValIn->setEnabled(false);
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineMsgValIn->sizePolicy().hasHeightForWidth());
        lineMsgValIn->setSizePolicy(sizePolicy1);
        lineMsgValIn->setMinimumSize(QSize(50, 0));
        lineMsgValIn->setMaximumSize(QSize(55, 16777215));
        lineMsgValIn->setInputMethodHints(Qt::ImhFormattedNumbersOnly);
        lineMsgValIn->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lineMsgValIn, 5, 3, 1, 1);

        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout->addWidget(label_12, 4, 8, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);
        QFont font;
        font.setPointSize(24);
        label->setFont(font);
        label->setLayoutDirection(Qt::LeftToRight);
        label->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);

        gridLayout->addWidget(label, 0, 4, 1, 2);

        oscButton = new QPushButton(centralWidget);
        oscButton->setObjectName(QStringLiteral("oscButton"));
        sizePolicy1.setHeightForWidth(oscButton->sizePolicy().hasHeightForWidth());
        oscButton->setSizePolicy(sizePolicy1);
        oscButton->setMaximumSize(QSize(66, 16777215));

        gridLayout->addWidget(oscButton, 3, 3, 1, 1);

        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        sizePolicy2.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy2);
        label_8->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_8, 4, 4, 1, 2);

        linePortOscIn = new QLineEdit(centralWidget);
        linePortOscIn->setObjectName(QStringLiteral("linePortOscIn"));
        sizePolicy1.setHeightForWidth(linePortOscIn->sizePolicy().hasHeightForWidth());
        linePortOscIn->setSizePolicy(sizePolicy1);
        linePortOscIn->setMaximumSize(QSize(70, 16777215));

        gridLayout->addWidget(linePortOscIn, 3, 4, 1, 1);

        label_14 = new QLabel(centralWidget);
        label_14->setObjectName(QStringLiteral("label_14"));

        gridLayout->addWidget(label_14, 4, 2, 1, 1);

        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        sizePolicy2.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(label_3, 2, 4, 1, 1);

        lineMsgTxtOut = new QLineEdit(centralWidget);
        lineMsgTxtOut->setObjectName(QStringLiteral("lineMsgTxtOut"));
        QSizePolicy sizePolicy3(QSizePolicy::Ignored, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(lineMsgTxtOut->sizePolicy().hasHeightForWidth());
        lineMsgTxtOut->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(lineMsgTxtOut, 5, 7, 1, 2);

        lineMsgValOut = new QLineEdit(centralWidget);
        lineMsgValOut->setObjectName(QStringLiteral("lineMsgValOut"));
        lineMsgValOut->setEnabled(false);
        sizePolicy1.setHeightForWidth(lineMsgValOut->sizePolicy().hasHeightForWidth());
        lineMsgValOut->setSizePolicy(sizePolicy1);
        lineMsgValOut->setMaximumSize(QSize(55, 16777215));
        lineMsgValOut->setInputMethodHints(Qt::ImhFormattedNumbersOnly);

        gridLayout->addWidget(lineMsgValOut, 5, 9, 1, 1);

        boxMsgTypeOut = new QComboBox(centralWidget);
        boxMsgTypeOut->setObjectName(QStringLiteral("boxMsgTypeOut"));
        sizePolicy1.setHeightForWidth(boxMsgTypeOut->sizePolicy().hasHeightForWidth());
        boxMsgTypeOut->setSizePolicy(sizePolicy1);
        boxMsgTypeOut->setMaximumSize(QSize(70, 16777215));

        gridLayout->addWidget(boxMsgTypeOut, 5, 10, 1, 1);

        checkListen = new QCheckBox(centralWidget);
        checkListen->setObjectName(QStringLiteral("checkListen"));

        gridLayout->addWidget(checkListen, 6, 0, 1, 1);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);

        gridLayout->addWidget(label_2, 0, 7, 1, 1);

        clearButton = new QPushButton(centralWidget);
        clearButton->setObjectName(QStringLiteral("clearButton"));
        sizePolicy1.setHeightForWidth(clearButton->sizePolicy().hasHeightForWidth());
        clearButton->setSizePolicy(sizePolicy1);
        clearButton->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(clearButton, 6, 7, 1, 1);

        sendButton = new QPushButton(centralWidget);
        sendButton->setObjectName(QStringLiteral("sendButton"));

        gridLayout->addWidget(sendButton, 6, 10, 1, 1);

        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 4, 7, 1, 1);

        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_10, 4, 10, 1, 1);

        linePortOscOut = new QLineEdit(centralWidget);
        linePortOscOut->setObjectName(QStringLiteral("linePortOscOut"));
        sizePolicy1.setHeightForWidth(linePortOscOut->sizePolicy().hasHeightForWidth());
        linePortOscOut->setSizePolicy(sizePolicy1);
        linePortOscOut->setMaximumSize(QSize(70, 16777215));

        gridLayout->addWidget(linePortOscOut, 3, 7, 1, 1);

        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        addToList = new QPushButton(centralWidget);
        addToList->setObjectName(QStringLiteral("addToList"));
        sizePolicy1.setHeightForWidth(addToList->sizePolicy().hasHeightForWidth());
        addToList->setSizePolicy(sizePolicy1);
        addToList->setMaximumSize(QSize(80, 16777215));

        gridLayout->addWidget(addToList, 6, 4, 1, 2);

        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(frame);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_9 = new QLabel(frame);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_2->addWidget(label_9, 0, 0, 1, 1);

        lineNomTransl = new QLineEdit(frame);
        lineNomTransl->setObjectName(QStringLiteral("lineNomTransl"));

        gridLayout_2->addWidget(lineNomTransl, 0, 1, 1, 2);

        saveButton = new QPushButton(frame);
        saveButton->setObjectName(QStringLiteral("saveButton"));

        gridLayout_2->addWidget(saveButton, 1, 1, 1, 1);

        loadButton = new QPushButton(frame);
        loadButton->setObjectName(QStringLiteral("loadButton"));

        gridLayout_2->addWidget(loadButton, 1, 2, 1, 1);


        gridLayout->addWidget(frame, 0, 8, 4, 3);

        lineMsgTxtIn = new QLineEdit(centralWidget);
        lineMsgTxtIn->setObjectName(QStringLiteral("lineMsgTxtIn"));
        QSizePolicy sizePolicy4(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(lineMsgTxtIn->sizePolicy().hasHeightForWidth());
        lineMsgTxtIn->setSizePolicy(sizePolicy4);

        gridLayout->addWidget(lineMsgTxtIn, 5, 0, 1, 3);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        sizePolicy2.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy2);

        gridLayout->addWidget(label_4, 2, 7, 1, 1);

        line = new QFrame(centralWidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 2, 5, 2, 1);

        boxMsgTypeIn = new QComboBox(centralWidget);
        boxMsgTypeIn->setObjectName(QStringLiteral("boxMsgTypeIn"));
        sizePolicy1.setHeightForWidth(boxMsgTypeIn->sizePolicy().hasHeightForWidth());
        boxMsgTypeIn->setSizePolicy(sizePolicy1);
        boxMsgTypeIn->setMaximumSize(QSize(70, 16777215));

        gridLayout->addWidget(boxMsgTypeIn, 5, 4, 1, 2);

        label_13 = new QLabel(centralWidget);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout->addWidget(label_13, 4, 1, 1, 1);

        listOsc = new QTableView(centralWidget);
        listOsc->setObjectName(QStringLiteral("listOsc"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(listOsc->sizePolicy().hasHeightForWidth());
        listOsc->setSizePolicy(sizePolicy5);
        listOsc->setMinimumSize(QSize(580, 0));
        listOsc->setStyleSheet(QStringLiteral(""));
        listOsc->setMidLineWidth(0);
        listOsc->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        listOsc->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listOsc->setTabKeyNavigation(false);
        listOsc->setAlternatingRowColors(true);
        listOsc->setSelectionMode(QAbstractItemView::SingleSelection);
        listOsc->setSelectionBehavior(QAbstractItemView::SelectRows);
        listOsc->setShowGrid(false);
        listOsc->verticalHeader()->setVisible(false);

        gridLayout->addWidget(listOsc, 7, 0, 1, 11);

        checkValueIn = new QCheckBox(centralWidget);
        checkValueIn->setObjectName(QStringLiteral("checkValueIn"));
        sizePolicy1.setHeightForWidth(checkValueIn->sizePolicy().hasHeightForWidth());
        checkValueIn->setSizePolicy(sizePolicy1);
        checkValueIn->setTristate(false);

        gridLayout->addWidget(checkValueIn, 4, 3, 1, 1);

        checkValueOut = new QCheckBox(centralWidget);
        checkValueOut->setObjectName(QStringLiteral("checkValueOut"));

        gridLayout->addWidget(checkValueOut, 4, 9, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        frame->raise();
        label_2->raise();
        linePortOscOut->raise();
        lineMsgTxtIn->raise();
        label_5->raise();
        label_6->raise();
        lineMsgTxtOut->raise();
        label_8->raise();
        boxMsgTypeIn->raise();
        label_10->raise();
        lineMsgValOut->raise();
        addToList->raise();
        boxMsgTypeOut->raise();
        clearButton->raise();
        listOsc->raise();
        sendButton->raise();
        checkListen->raise();
        label_4->raise();
        label_13->raise();
        label_14->raise();
        label_12->raise();
        linePortOscIn->raise();
        label_3->raise();
        label->raise();
        line->raise();
        lineMsgValIn->raise();
        oscButton->raise();
        checkValueIn->raise();
        checkValueOut->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 680, 27));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);
        QObject::connect(checkValueIn, SIGNAL(toggled(bool)), lineMsgValIn, SLOT(setEnabled(bool)));
        QObject::connect(checkValueOut, SIGNAL(toggled(bool)), lineMsgValOut, SLOT(setEnabled(bool)));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "OSCours!!", 0));
        label_12->setText(QString());
        label->setText(QApplication::translate("MainWindow", "IN", 0));
        oscButton->setText(QApplication::translate("MainWindow", "Reboot", 0));
        label_8->setText(QApplication::translate("MainWindow", "Type", 0));
        label_14->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "OSC Port", 0));
        boxMsgTypeOut->clear();
        boxMsgTypeOut->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("MainWindow", "int", 0)
         << QApplication::translate("MainWindow", "float", 0)
        );
        checkListen->setText(QApplication::translate("MainWindow", "Listen", 0));
        label_2->setText(QApplication::translate("MainWindow", "OUT", 0));
        clearButton->setText(QApplication::translate("MainWindow", "Delete", 0));
        sendButton->setText(QApplication::translate("MainWindow", "Send", 0));
        label_6->setText(QApplication::translate("MainWindow", "message", 0));
        label_10->setText(QApplication::translate("MainWindow", "Type", 0));
        label_5->setText(QApplication::translate("MainWindow", "message", 0));
        addToList->setText(QApplication::translate("MainWindow", "Add", 0));
        label_9->setText(QApplication::translate("MainWindow", "Patch", 0));
        saveButton->setText(QApplication::translate("MainWindow", "save", 0));
        loadButton->setText(QApplication::translate("MainWindow", "load", 0));
        label_4->setText(QApplication::translate("MainWindow", "OSC Port", 0));
        boxMsgTypeIn->clear();
        boxMsgTypeIn->insertItems(0, QStringList()
         << QString()
         << QApplication::translate("MainWindow", "int", 0)
         << QApplication::translate("MainWindow", "float", 0)
        );
        label_13->setText(QString());
        checkValueIn->setText(QApplication::translate("MainWindow", "Value", 0));
        checkValueOut->setText(QApplication::translate("MainWindow", "Value", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
