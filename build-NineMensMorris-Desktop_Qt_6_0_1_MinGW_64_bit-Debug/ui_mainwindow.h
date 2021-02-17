/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *Home_Page;
    QPushButton *pushButton;
    QTextEdit *textEdit;
    QWidget *Game_Page;
    QFrame *frame;
    QFrame *frame_2;
    QLabel *Board_Image;
    QFrame *Button_Layout;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton_21;
    QPushButton *pushButton_14;
    QPushButton *pushButton_15;
    QPushButton *pushButton_12;
    QPushButton *pushButton_18;
    QPushButton *pushButton_23;
    QPushButton *pushButton_26;
    QPushButton *pushButton_27;
    QPushButton *pushButton_29;
    QPushButton *pushButton_31;
    QPushButton *pushButton_32;
    QPushButton *pushButton_35;
    QPushButton *pushButton_36;
    QPushButton *pushButton_39;
    QPushButton *pushButton_43;
    QPushButton *pushButton_44;
    QPushButton *pushButton_17;
    QPushButton *pushButton_45;
    QPushButton *pushButton_46;
    QPushButton *pushButton_47;
    QPushButton *pushButton_49;
    QPushButton *pushButton_51;
    QPushButton *pushButton_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(784, 570);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(9, 9, 771, 511));
        Home_Page = new QWidget();
        Home_Page->setObjectName(QString::fromUtf8("Home_Page"));
        pushButton = new QPushButton(Home_Page);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(310, 390, 171, 61));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        pushButton->setFont(font);
        textEdit = new QTextEdit(Home_Page);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(0, 20, 791, 111));
        stackedWidget->addWidget(Home_Page);
        Game_Page = new QWidget();
        Game_Page->setObjectName(QString::fromUtf8("Game_Page"));
        frame = new QFrame(Game_Page);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(-11, 9, 781, 501));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        frame_2 = new QFrame(frame);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(170, 30, 411, 411));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        Board_Image = new QLabel(frame_2);
        Board_Image->setObjectName(QString::fromUtf8("Board_Image"));
        Board_Image->setGeometry(QRect(0, -10, 461, 431));
        Board_Image->setMinimumSize(QSize(461, 0));
        Board_Image->setMaximumSize(QSize(461, 16777215));
        Button_Layout = new QFrame(frame_2);
        Button_Layout->setObjectName(QString::fromUtf8("Button_Layout"));
        Button_Layout->setGeometry(QRect(20, 0, 371, 421));
        Button_Layout->setFrameShape(QFrame::StyledPanel);
        Button_Layout->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(Button_Layout);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        pushButton_2 = new QPushButton(Button_Layout);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout_2->addWidget(pushButton_2, 0, 0, 1, 1);

        pushButton_21 = new QPushButton(Button_Layout);
        pushButton_21->setObjectName(QString::fromUtf8("pushButton_21"));

        gridLayout_2->addWidget(pushButton_21, 5, 3, 1, 1);

        pushButton_14 = new QPushButton(Button_Layout);
        pushButton_14->setObjectName(QString::fromUtf8("pushButton_14"));

        gridLayout_2->addWidget(pushButton_14, 1, 3, 1, 1);

        pushButton_15 = new QPushButton(Button_Layout);
        pushButton_15->setObjectName(QString::fromUtf8("pushButton_15"));

        gridLayout_2->addWidget(pushButton_15, 2, 3, 1, 1);

        pushButton_12 = new QPushButton(Button_Layout);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));

        gridLayout_2->addWidget(pushButton_12, 0, 6, 1, 1);

        pushButton_18 = new QPushButton(Button_Layout);
        pushButton_18->setObjectName(QString::fromUtf8("pushButton_18"));

        gridLayout_2->addWidget(pushButton_18, 4, 3, 1, 1);

        pushButton_23 = new QPushButton(Button_Layout);
        pushButton_23->setObjectName(QString::fromUtf8("pushButton_23"));

        gridLayout_2->addWidget(pushButton_23, 6, 3, 1, 1);

        pushButton_26 = new QPushButton(Button_Layout);
        pushButton_26->setObjectName(QString::fromUtf8("pushButton_26"));

        gridLayout_2->addWidget(pushButton_26, 3, 2, 1, 1);

        pushButton_27 = new QPushButton(Button_Layout);
        pushButton_27->setObjectName(QString::fromUtf8("pushButton_27"));

        gridLayout_2->addWidget(pushButton_27, 3, 1, 1, 1);

        pushButton_29 = new QPushButton(Button_Layout);
        pushButton_29->setObjectName(QString::fromUtf8("pushButton_29"));

        gridLayout_2->addWidget(pushButton_29, 3, 0, 1, 1);

        pushButton_31 = new QPushButton(Button_Layout);
        pushButton_31->setObjectName(QString::fromUtf8("pushButton_31"));

        gridLayout_2->addWidget(pushButton_31, 3, 4, 1, 1);

        pushButton_32 = new QPushButton(Button_Layout);
        pushButton_32->setObjectName(QString::fromUtf8("pushButton_32"));

        gridLayout_2->addWidget(pushButton_32, 3, 5, 1, 1);

        pushButton_35 = new QPushButton(Button_Layout);
        pushButton_35->setObjectName(QString::fromUtf8("pushButton_35"));

        gridLayout_2->addWidget(pushButton_35, 1, 1, 1, 1);

        pushButton_36 = new QPushButton(Button_Layout);
        pushButton_36->setObjectName(QString::fromUtf8("pushButton_36"));

        gridLayout_2->addWidget(pushButton_36, 2, 2, 1, 1);

        pushButton_39 = new QPushButton(Button_Layout);
        pushButton_39->setObjectName(QString::fromUtf8("pushButton_39"));

        gridLayout_2->addWidget(pushButton_39, 4, 2, 1, 1);

        pushButton_43 = new QPushButton(Button_Layout);
        pushButton_43->setObjectName(QString::fromUtf8("pushButton_43"));

        gridLayout_2->addWidget(pushButton_43, 4, 4, 1, 1);

        pushButton_44 = new QPushButton(Button_Layout);
        pushButton_44->setObjectName(QString::fromUtf8("pushButton_44"));

        gridLayout_2->addWidget(pushButton_44, 2, 4, 1, 1);

        pushButton_17 = new QPushButton(Button_Layout);
        pushButton_17->setObjectName(QString::fromUtf8("pushButton_17"));

        gridLayout_2->addWidget(pushButton_17, 3, 6, 1, 1);

        pushButton_45 = new QPushButton(Button_Layout);
        pushButton_45->setObjectName(QString::fromUtf8("pushButton_45"));

        gridLayout_2->addWidget(pushButton_45, 1, 5, 1, 1);

        pushButton_46 = new QPushButton(Button_Layout);
        pushButton_46->setObjectName(QString::fromUtf8("pushButton_46"));

        gridLayout_2->addWidget(pushButton_46, 5, 1, 1, 1);

        pushButton_47 = new QPushButton(Button_Layout);
        pushButton_47->setObjectName(QString::fromUtf8("pushButton_47"));

        gridLayout_2->addWidget(pushButton_47, 6, 0, 1, 1);

        pushButton_49 = new QPushButton(Button_Layout);
        pushButton_49->setObjectName(QString::fromUtf8("pushButton_49"));

        gridLayout_2->addWidget(pushButton_49, 6, 6, 1, 1);

        pushButton_51 = new QPushButton(Button_Layout);
        pushButton_51->setObjectName(QString::fromUtf8("pushButton_51"));

        gridLayout_2->addWidget(pushButton_51, 5, 5, 1, 1);

        pushButton_4 = new QPushButton(Button_Layout);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        gridLayout_2->addWidget(pushButton_4, 0, 3, 1, 1);

        stackedWidget->addWidget(Game_Page);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 784, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "New Game", nullptr));
        textEdit->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:48pt; font-weight:600; text-decoration: underline;\">NINE MEN'S MORRIS</span></p></body></html>", nullptr));
        Board_Image->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><img src=\":/img/img/board.jpg\"/></p></body></html>", nullptr));
        pushButton_2->setText(QString());
        pushButton_21->setText(QString());
        pushButton_14->setText(QString());
        pushButton_15->setText(QString());
        pushButton_12->setText(QString());
        pushButton_18->setText(QString());
        pushButton_23->setText(QString());
        pushButton_26->setText(QString());
        pushButton_27->setText(QString());
        pushButton_29->setText(QString());
        pushButton_31->setText(QString());
        pushButton_32->setText(QString());
        pushButton_35->setText(QString());
        pushButton_36->setText(QString());
        pushButton_39->setText(QString());
        pushButton_43->setText(QString());
        pushButton_44->setText(QString());
        pushButton_17->setText(QString());
        pushButton_45->setText(QString());
        pushButton_46->setText(QString());
        pushButton_47->setText(QString());
        pushButton_49->setText(QString());
        pushButton_51->setText(QString());
        pushButton_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
