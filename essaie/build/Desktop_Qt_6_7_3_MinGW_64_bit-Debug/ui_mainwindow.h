/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *barreverticale;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QLabel *label;
    QFrame *barrehorizontalle;
    QLineEdit *lineEditRecherche1;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QFrame *frame;
    QPushButton *pushButton_8;
    QLabel *label_5;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLineEdit *lineEdit_id;
    QLineEdit *lineEdit_titre;
    QLineEdit *lineEdit_budget;
    QLineEdit *lineEdit_avancement;
    QPushButton *ajouter;
    QDateEdit *dateEdit_dateL;
    QLineEdit *textEdit_description;
    QPushButton *btnAfficherProjets;
    QPushButton *listTodoButton;
    QPushButton *pushButton_14;
    QLineEdit *barrederecherche_id;
    QPushButton *delete_projet;
    QPushButton *edit_projet;
    QPushButton *detail;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1074, 660);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        barreverticale = new QFrame(centralwidget);
        barreverticale->setObjectName("barreverticale");
        barreverticale->setGeometry(QRect(0, 10, 201, 591));
        QPalette palette;
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(98, 135, 55, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush2(QColor(159, 207, 54, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush2);
        QBrush brush3(QColor(132, 172, 45, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush3);
        QBrush brush4(QColor(53, 69, 18, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Dark, brush4);
        QBrush brush5(QColor(71, 92, 24, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        QBrush brush6(QColor(255, 255, 255, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Active, QPalette::Shadow, brush);
        QBrush brush7(QColor(180, 196, 145, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush7);
        QBrush brush8(QColor(255, 255, 220, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Active, QPalette::ToolTipText, brush);
        QBrush brush9(QColor(0, 0, 0, 127));
        brush9.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush9);
#endif
        palette.setBrush(QPalette::Active, QPalette::Accent, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Shadow, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush9);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::Accent, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Dark, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Mid, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush4);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Shadow, brush);
        QBrush brush10(QColor(106, 138, 36, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush10);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush);
        QBrush brush11(QColor(53, 69, 18, 127));
        brush11.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush11);
#endif
        QBrush brush12(QColor(138, 179, 47, 255));
        brush12.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::Accent, brush12);
        barreverticale->setPalette(palette);
        barreverticale->setMouseTracking(false);
        barreverticale->setStyleSheet(QString::fromUtf8("background-color: rgb(98, 135, 55);\n"
""));
        barreverticale->setFrameShape(QFrame::Shape::Box);
        barreverticale->setFrameShadow(QFrame::Shadow::Raised);
        pushButton = new QPushButton(barreverticale);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(0, 210, 201, 61));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: rgb(98, 135, 55);\n"
"font: 10pt \"Sylfaen\";\n"
"border-radius: 10px;\n"
"}\n"
"QPushButton:hover {\n"
"background-color: #7E9C5A;\n"
"}"));
        pushButton_2 = new QPushButton(barreverticale);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(0, 270, 201, 61));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: rgb(98, 135, 55);\n"
"font: 10pt \"Sylfaen\";\n"
"border-radius: 10px;\n"
"}\n"
"QPushButton:hover {\n"
"background-color: #7E9C5A;\n"
"}"));
        pushButton_3 = new QPushButton(barreverticale);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(0, 330, 201, 61));
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: rgb(98, 135, 55);\n"
"font: 10pt \"Sylfaen\";\n"
"border-radius: 10px;\n"
"}\n"
"QPushButton:hover {\n"
"background-color: #7E9C5A;\n"
"}"));
        pushButton_4 = new QPushButton(barreverticale);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(0, 400, 201, 61));
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: rgb(98, 135, 55);\n"
"font: 10pt \"Sylfaen\";\n"
"border-radius: 10px;\n"
"}\n"
"QPushButton:hover {\n"
"background-color: #7E9C5A;\n"
"}"));
        pushButton_5 = new QPushButton(barreverticale);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(0, 470, 201, 61));
        pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: rgb(98, 135, 55);\n"
"font: 10pt \"Sylfaen\";\n"
"border-radius: 10px;\n"
"}\n"
"QPushButton:hover {\n"
"background-color: #7E9C5A;\n"
"}"));
        pushButton_6 = new QPushButton(barreverticale);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(0, 530, 201, 61));
        pushButton_6->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: rgb(98, 135, 55);\n"
"font: 10pt \"Sylfaen\";\n"
"border-radius: 10px;\n"
"}\n"
"QPushButton:hover {\n"
"background-color: #7E9C5A;\n"
"}"));
        pushButton_7 = new QPushButton(barreverticale);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(0, 150, 201, 61));
        pushButton_7->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: rgb(98, 135, 55);\n"
"font: 10pt \"Sylfaen\";\n"
"border-radius: 10px;\n"
"}\n"
"QPushButton:hover {\n"
"background-color: #7E9C5A;\n"
"}"));
        label = new QLabel(barreverticale);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 20, 141, 121));
        label->setStyleSheet(QString::fromUtf8("image: url(:/res/prof.png);"));
        barrehorizontalle = new QFrame(centralwidget);
        barrehorizontalle->setObjectName("barrehorizontalle");
        barrehorizontalle->setGeometry(QRect(200, 10, 841, 591));
        barrehorizontalle->setAutoFillBackground(false);
        barrehorizontalle->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"font: 15pt \"Segoe UI\";"));
        barrehorizontalle->setFrameShape(QFrame::Shape::WinPanel);
        barrehorizontalle->setFrameShadow(QFrame::Shadow::Raised);
        barrehorizontalle->setLineWidth(1);
        lineEditRecherche1 = new QLineEdit(barrehorizontalle);
        lineEditRecherche1->setObjectName("lineEditRecherche1");
        lineEditRecherche1->setGeometry(QRect(80, 20, 651, 41));
        lineEditRecherche1->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        lineEditRecherche1->setCursorMoveStyle(Qt::CursorMoveStyle::LogicalMoveStyle);
        label_2 = new QLabel(barrehorizontalle);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 20, 51, 41));
        label_2->setStyleSheet(QString::fromUtf8("image: url(:/res/search.png)"));
        label_3 = new QLabel(barrehorizontalle);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(740, 20, 41, 41));
        label_3->setStyleSheet(QString::fromUtf8("image:url(:/res/likes.png)"));
        label_4 = new QLabel(barrehorizontalle);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(780, 20, 51, 41));
        label_4->setStyleSheet(QString::fromUtf8("image:url(:/res/notif.png)"));
        frame = new QFrame(barrehorizontalle);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(10, 70, 371, 521));
        frame->setStyleSheet(QString::fromUtf8("QFrame {\n"
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
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        pushButton_8 = new QPushButton(frame);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(0, 0, 371, 61));
        pushButton_8->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color:rgb(209, 199, 161);\n"
"font: 10pt \"Sylfaen\";\n"
"border-radius: 10px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #F5F5DC; /* Beige soft */\n"
"}"));
        label_5 = new QLabel(frame);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(10, 130, 181, 31));
        label_5->setStyleSheet(QString::fromUtf8("label->setStyleSheet(\"QLabel { color: black; font-size: 10px; border: none; }\");\n"
""));
        label_7 = new QLabel(frame);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(10, 180, 181, 31));
        label_7->setStyleSheet(QString::fromUtf8("label->setStyleSheet(\"QLabel { color: black; font-size: 10px; border: none; }\");\n"
""));
        label_8 = new QLabel(frame);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(10, 230, 181, 31));
        label_8->setStyleSheet(QString::fromUtf8("label->setStyleSheet(\"QLabel { color: black; font-size: 10px; border: none; }\");\n"
""));
        label_9 = new QLabel(frame);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(10, 280, 181, 31));
        label_9->setStyleSheet(QString::fromUtf8("label->setStyleSheet(\"QLabel { color: black; font-size: 10px; border: none; }\");\n"
""));
        label_10 = new QLabel(frame);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(10, 330, 181, 31));
        label_10->setStyleSheet(QString::fromUtf8("label->setStyleSheet(\"QLabel { color: black; font-size: 10px; border: none; }\");\n"
""));
        label_11 = new QLabel(frame);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(10, 380, 181, 31));
        label_11->setStyleSheet(QString::fromUtf8("label->setStyleSheet(\"QLabel { color: black; font-size: 10px; border: none; }\");\n"
""));
        lineEdit_id = new QLineEdit(frame);
        lineEdit_id->setObjectName("lineEdit_id");
        lineEdit_id->setGeometry(QRect(210, 130, 131, 31));
        lineEdit_titre = new QLineEdit(frame);
        lineEdit_titre->setObjectName("lineEdit_titre");
        lineEdit_titre->setGeometry(QRect(210, 180, 131, 31));
        lineEdit_budget = new QLineEdit(frame);
        lineEdit_budget->setObjectName("lineEdit_budget");
        lineEdit_budget->setGeometry(QRect(210, 280, 131, 31));
        lineEdit_avancement = new QLineEdit(frame);
        lineEdit_avancement->setObjectName("lineEdit_avancement");
        lineEdit_avancement->setGeometry(QRect(210, 380, 131, 31));
        ajouter = new QPushButton(frame);
        ajouter->setObjectName("ajouter");
        ajouter->setGeometry(QRect(260, 10, 71, 41));
        ajouter->setStyleSheet(QString::fromUtf8("image :url(:/res/ajouter.png)"));
        ajouter->setFlat(true);
        dateEdit_dateL = new QDateEdit(frame);
        dateEdit_dateL->setObjectName("dateEdit_dateL");
        dateEdit_dateL->setGeometry(QRect(210, 340, 151, 31));
        dateEdit_dateL->setMaximumSize(QSize(1177720, 1177721));
        textEdit_description = new QLineEdit(frame);
        textEdit_description->setObjectName("textEdit_description");
        textEdit_description->setGeometry(QRect(210, 230, 131, 31));
        btnAfficherProjets = new QPushButton(frame);
        btnAfficherProjets->setObjectName("btnAfficherProjets");
        btnAfficherProjets->setGeometry(QRect(10, 470, 351, 41));
        btnAfficherProjets->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color:rgb(209, 199, 161);\n"
"font: 10pt \"Sylfaen\";\n"
"border-radius: 10px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #F5F5DC; /* Beige soft */\n"
"}"));
        listTodoButton = new QPushButton(barrehorizontalle);
        listTodoButton->setObjectName("listTodoButton");
        listTodoButton->setGeometry(QRect(610, 220, 211, 191));
        listTodoButton->setStyleSheet(QString::fromUtf8("image :url(:/res/list to do.png)"));
        listTodoButton->setFlat(true);
        pushButton_14 = new QPushButton(barrehorizontalle);
        pushButton_14->setObjectName("pushButton_14");
        pushButton_14->setGeometry(QRect(410, 260, 161, 151));
        pushButton_14->setStyleSheet(QString::fromUtf8("image :url(:/res/vocal.png)"));
        pushButton_14->setFlat(true);
        barrederecherche_id = new QLineEdit(barrehorizontalle);
        barrederecherche_id->setObjectName("barrederecherche_id");
        barrederecherche_id->setGeometry(QRect(430, 80, 361, 41));
        barrederecherche_id->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        barrederecherche_id->setCursorMoveStyle(Qt::CursorMoveStyle::LogicalMoveStyle);
        delete_projet = new QPushButton(barrehorizontalle);
        delete_projet->setObjectName("delete_projet");
        delete_projet->setGeometry(QRect(450, 140, 71, 61));
        delete_projet->setStyleSheet(QString::fromUtf8("image :url(:/res/suppr.png)"));
        delete_projet->setFlat(true);
        edit_projet = new QPushButton(barrehorizontalle);
        edit_projet->setObjectName("edit_projet");
        edit_projet->setGeometry(QRect(540, 140, 81, 61));
        edit_projet->setStyleSheet(QString::fromUtf8("image:url(:/res/modif.png)"));
        edit_projet->setFlat(true);
        detail = new QPushButton(barrehorizontalle);
        detail->setObjectName("detail");
        detail->setGeometry(QRect(630, 150, 161, 41));
        detail->setStyleSheet(QString::fromUtf8(" background-color: #7E9C5A; color: white; font-size: 14px; border-radius: 8px; padding: 10px;\n"
"  hover  background-color: #5A7E3A; "));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1074, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Gestion Projets", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Gestion Clients ", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Gestion Ressources", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Gestion Strat\303\251gies", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "Gestion \303\251vennements", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "Gestionn User", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "Acceuil", nullptr));
        label->setText(QString());
        label_2->setText(QString());
        label_3->setText(QString());
        label_4->setText(QString());
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "Ajouter Projet", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">Id projet :</span></p></body></html>", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">Titre Projet:</span></p></body></html>", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">DescriptionP :</span></p></body></html>", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">Budget Projet :</span></p></body></html>", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">DateLP :</span></p></body></html>", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">AvancementP :</span></p></body></html>", nullptr));
        ajouter->setText(QString());
        dateEdit_dateL->setDisplayFormat(QCoreApplication::translate("MainWindow", "dd-MM-yyyy", nullptr));
        btnAfficherProjets->setText(QCoreApplication::translate("MainWindow", "Liste de Projets", nullptr));
        listTodoButton->setText(QString());
        pushButton_14->setText(QString());
        barrederecherche_id->setText(QString());
        barrederecherche_id->setPlaceholderText(QCoreApplication::translate("MainWindow", "Entrez le titre du projet ici", nullptr));
        delete_projet->setText(QString());
        edit_projet->setText(QString());
        detail->setText(QCoreApplication::translate("MainWindow", "Acc\303\251der au Projet", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
