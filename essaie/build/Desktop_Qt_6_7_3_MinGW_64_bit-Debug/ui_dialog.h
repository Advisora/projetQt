/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QFrame *frame_list;
    QListWidget *listWidget;
    QPushButton *telechargerPDF;
    QLineEdit *searchLineEdit;
    QPushButton *pushButton_15;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(1046, 536);
        frame_list = new QFrame(Dialog);
        frame_list->setObjectName("frame_list");
        frame_list->setGeometry(QRect(0, 20, 951, 521));
        frame_list->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    border: 2px solid rgb(209, 199, 161); /* Bordure l\303\251g\303\250rement plus fonc\303\251e */\n"
"    border-radius: 20px; /* Coins arrondis */\n"
"    color: #000; /* Texte noir */\n"
"    padding-left: 20px;\n"
"    padding-right: 20px;\n"
"    background-color: rgb(245, 245, 220); /* Beige */\n"
"}\n"
"\n"
"QLineEdit:hover {\n"
"    border: 2px solid rgb(160, 150, 120); /* Bordure plus fonc\303\251e au survol */\n"
"    background-color: rgb(255, 255, 235); /* Fond l\303\251g\303\250rement plus clair */\n"
"}\n"
"\n"
"QFrame:focus {\n"
"    border: 2px solid rgb(100, 80, 50); /* Bordure encore plus fonc\303\251e lors du focus */\n"
"    background-color: rgb(255, 255, 240); /* Fond encore plus clair lors du focus */\n"
"    box-shadow: 0 0 5px rgba(0, 0, 0, 0.2); /* Ombre autour du champ en focus */\n"
"}\n"
""));
        frame_list->setFrameShape(QFrame::Shape::StyledPanel);
        frame_list->setFrameShadow(QFrame::Shadow::Raised);
        listWidget = new QListWidget(frame_list);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(40, 100, 661, 351));
        telechargerPDF = new QPushButton(frame_list);
        telechargerPDF->setObjectName("telechargerPDF");
        telechargerPDF->setGeometry(QRect(750, 180, 161, 51));
        telechargerPDF->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: rgb(160, 82, 45);\n"
"font: 10pt \"Sylfaen\";\n"
"border-radius: 10px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #D2B48C; /* Marron soft */\n"
"}\n"
""));
        searchLineEdit = new QLineEdit(frame_list);
        searchLineEdit->setObjectName("searchLineEdit");
        searchLineEdit->setGeometry(QRect(40, 40, 661, 41));
        searchLineEdit->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 2px solid rgb(209, 199, 161); /* Bordure l\303\251g\303\250rement plus fonc\303\251e */\n"
"    border-radius: 20px; /* Coins arrondis */\n"
"    color: #000; /* Texte noir */\n"
"    padding-left: 20px;\n"
"    padding-right: 20px;\n"
"    background-color: rgb(245, 245, 220); /* Beige */\n"
"}\n"
"\n"
"QLineEdit:hover {\n"
"    border: 2px solid rgb(160, 150, 120); /* Bordure plus fonc\303\251e au survol */\n"
"    background-color: rgb(255, 255, 235); /* Fond l\303\251g\303\250rement plus clair */\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid rgb(100, 80, 50); /* Bordure encore plus fonc\303\251e lors du focus */\n"
"    background-color: rgb(255, 255, 240); /* Fond encore plus clair lors du focus */\n"
"    box-shadow: 0 0 5px rgba(0, 0, 0, 0.2); /* Ombre autour du champ en focus */\n"
"}\n"
""));
        searchLineEdit->setCursorMoveStyle(Qt::CursorMoveStyle::LogicalMoveStyle);
        pushButton_15 = new QPushButton(frame_list);
        pushButton_15->setObjectName("pushButton_15");
        pushButton_15->setGeometry(QRect(760, 290, 151, 101));
        pushButton_15->setStyleSheet(QString::fromUtf8("image :url(:/res/stat.png)"));
        pushButton_15->setFlat(true);

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        telechargerPDF->setText(QCoreApplication::translate("Dialog", "PDF", nullptr));
        searchLineEdit->setPlaceholderText(QCoreApplication::translate("Dialog", "Entrez le titre ici", nullptr));
        pushButton_15->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
