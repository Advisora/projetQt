/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *horizontalWidget;
    QLineEdit *searchResourceInput;
    QLabel *label_8;
    QLabel *label_11;
    QComboBox *comboBox;
    QPushButton *pushButton_14;
    QPushButton *pushButton_15;
    QPushButton *pushButton_16;
    QPushButton *searchbutt;
    QTableView *tableView;
    QPushButton *deletebutt;
    QTabWidget *tabWidget;
    QWidget *widget;
    QGroupBox *horizontalGroupBox;
    QLabel *label_3;
    QLineEdit *nomResourceInput;
    QLabel *label_4;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *typeResourceInput;
    QLineEdit *categorieResourceInput;
    QLineEdit *quantiteResourceInput;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QLabel *label_9;
    QLineEdit *dernierDetectionInput;
    QLabel *label_12;
    QLabel *label_10;
    QLineEdit *nomCandidatInput;
    QPushButton *pushButton_18;
    QLineEdit *telephoneResourceInput;
    QLabel *label_5;
    QLineEdit *emailResourceInput;
    QLineEdit *experienceResourceInput;
    QLabel *label_13;
    QWidget *tab_6;
    QFrame *barreverticale;
    QLabel *label;
    QPushButton *GestionEvenementsButton;
    QPushButton *gestionClientsButton;
    QPushButton *GestionProjetsButton;
    QPushButton *GestionRessourcesButton;
    QPushButton *GestionStrategiesButton;
    QPushButton *GestionEmployeesButton;
    QPushButton *GestionParamtresButton;
    QPushButton *GestionParamtresButton_2;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1061, 801);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalWidget = new QWidget(centralwidget);
        horizontalWidget->setObjectName("horizontalWidget");
        horizontalWidget->setGeometry(QRect(200, 290, 971, 491));
        horizontalWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        searchResourceInput = new QLineEdit(horizontalWidget);
        searchResourceInput->setObjectName("searchResourceInput");
        searchResourceInput->setGeometry(QRect(10, 40, 281, 16));
        searchResourceInput->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        label_8 = new QLabel(horizontalWidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(10, 10, 261, 21));
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
" font-size: 13px;\n"
"    font-weight: bold;\n"
"    font-family: \"Poppins\";"));
        label_11 = new QLabel(horizontalWidget);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(440, 30, 71, 21));
        label_11->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
" font-size: 13px;\n"
"    font-weight: bold;\n"
"    font-family: \"Poppins\";"));
        comboBox = new QComboBox(horizontalWidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(510, 30, 71, 21));
        pushButton_14 = new QPushButton(horizontalWidget);
        pushButton_14->setObjectName("pushButton_14");
        pushButton_14->setGeometry(QRect(40, 310, 81, 31));
        QFont font;
        font.setFamilies({QString::fromUtf8("Tw Cen MT")});
        font.setBold(true);
        pushButton_14->setFont(font);
        pushButton_14->setStyleSheet(QString::fromUtf8("background-color: rgb(115, 115, 115);\n"
"    color: #1E2350;\n"
"    border-radius: 10px;\n"
"    font-size: 14px;\n"
"    padding: 8px;"));
        pushButton_15 = new QPushButton(horizontalWidget);
        pushButton_15->setObjectName("pushButton_15");
        pushButton_15->setGeometry(QRect(410, 310, 81, 31));
        pushButton_15->setFont(font);
        pushButton_15->setStyleSheet(QString::fromUtf8("background-color: rgb(115, 115, 115);\n"
"    color: #1E2350;\n"
"    border-radius: 10px;\n"
"    font-size: 14px;\n"
"    padding: 8px;"));
        pushButton_16 = new QPushButton(horizontalWidget);
        pushButton_16->setObjectName("pushButton_16");
        pushButton_16->setGeometry(QRect(520, 310, 81, 31));
        pushButton_16->setFont(font);
        pushButton_16->setStyleSheet(QString::fromUtf8("background-color: rgb(115, 115, 115);\n"
"    color: #1E2350;\n"
"    border-radius: 10px;\n"
"    font-size: 14px;\n"
"    padding: 8px;"));
        searchbutt = new QPushButton(horizontalWidget);
        searchbutt->setObjectName("searchbutt");
        searchbutt->setGeometry(QRect(300, 30, 51, 31));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/ressources/search-3-48.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        searchbutt->setIcon(icon);
        tableView = new QTableView(horizontalWidget);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(10, 70, 581, 201));
        tableView->setStyleSheet(QString::fromUtf8("  background-color: rgb(255, 255, 240);\n"
"color:#6563FF;\n"
"font-size:16px;"));
        deletebutt = new QPushButton(horizontalWidget);
        deletebutt->setObjectName("deletebutt");
        deletebutt->setGeometry(QRect(360, 30, 61, 31));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Tw Cen MT")});
        font1.setBold(true);
        font1.setItalic(true);
        deletebutt->setFont(font1);
        deletebutt->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"  \n"
"    color: #1E2350;\n"
"    border-radius: 10px;\n"
"    font-size: 14px;\n"
"    padding: 8px;"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(200, 0, 601, 291));
        tabWidget->setStyleSheet(QString::fromUtf8("/* Style the entire TabWidget */\n"
"QTabWidget::pane {\n"
"    background: white; /* Background of the tab widget */\n"
"    border: 2px solid #A9A8FF;\n"
"    border-radius: 10px;\n"
"}\n"
"\n"
"/* Style for the Tab Bar (tab headers) */\n"
"QTabBar::tab {\n"
"    background: #8685F5; /* Default tab background */\n"
"    color: white; /* Text color */\n"
"    padding: 8px 16px;\n"
"    border-radius: 8px;\n"
"    margin: 2px;\n"
"    border: 1px solid #6563FF;\n"
"}\n"
"\n"
"/* Selected Tab */\n"
"QTabBar::tab:selected {\n"
"    background: #6563FF; /* Active tab color */\n"
"    font-weight: bold;\n"
"    border-bottom: 3px solid white;\n"
"}\n"
"\n"
"/* Hover effect on tabs */\n"
"QTabBar::tab:hover {\n"
"    background: #7A79FF;\n"
"}\n"
"\n"
"/* Disabled tabs */\n"
"QTabBar::tab:disabled {\n"
"    background: #D3D3D3;\n"
"    color: gray;\n"
"}\n"
""));
        widget = new QWidget();
        widget->setObjectName("widget");
        horizontalGroupBox = new QGroupBox(widget);
        horizontalGroupBox->setObjectName("horizontalGroupBox");
        horizontalGroupBox->setGeometry(QRect(-10, -20, 621, 271));
        horizontalGroupBox->setContextMenuPolicy(Qt::ContextMenuPolicy::CustomContextMenu);
        horizontalGroupBox->setStyleSheet(QString::fromUtf8("  background-color: rgb(255, 255, 240);"));
        label_3 = new QLabel(horizontalGroupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(40, 40, 101, 21));
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
" font-size: 13px;\n"
"    font-weight: bold;\n"
"    font-family: \"Poppins\";"));
        nomResourceInput = new QLineEdit(horizontalGroupBox);
        nomResourceInput->setObjectName("nomResourceInput");
        nomResourceInput->setGeometry(QRect(160, 40, 111, 16));
        nomResourceInput->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        label_4 = new QLabel(horizontalGroupBox);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(40, 60, 101, 31));
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
" font-size: 13px;\n"
"    font-weight: bold;\n"
"    font-family: \"Poppins\";"));
        label_6 = new QLabel(horizontalGroupBox);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(40, 90, 81, 31));
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
" font-size: 13px;\n"
"    font-weight: bold;\n"
"    font-family: \"Poppins\";"));
        label_7 = new QLabel(horizontalGroupBox);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(40, 130, 81, 20));
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
" font-size: 13px;\n"
"    font-weight: bold;\n"
"    font-family: \"Poppins\";"));
        typeResourceInput = new QLineEdit(horizontalGroupBox);
        typeResourceInput->setObjectName("typeResourceInput");
        typeResourceInput->setGeometry(QRect(160, 70, 111, 16));
        typeResourceInput->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        categorieResourceInput = new QLineEdit(horizontalGroupBox);
        categorieResourceInput->setObjectName("categorieResourceInput");
        categorieResourceInput->setGeometry(QRect(160, 100, 111, 16));
        categorieResourceInput->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        quantiteResourceInput = new QLineEdit(horizontalGroupBox);
        quantiteResourceInput->setObjectName("quantiteResourceInput");
        quantiteResourceInput->setGeometry(QRect(160, 130, 111, 16));
        quantiteResourceInput->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        pushButton_11 = new QPushButton(horizontalGroupBox);
        pushButton_11->setObjectName("pushButton_11");
        pushButton_11->setGeometry(QRect(420, 210, 80, 31));
        pushButton_11->setFont(font1);
        pushButton_11->setStyleSheet(QString::fromUtf8("  background-color: #FFFFFF;\n"
"  \n"
"    color: #1E2350;\n"
"    border-radius: 10px;\n"
"    font-size: 14px;\n"
"    padding: 8px;"));
        pushButton_12 = new QPushButton(horizontalGroupBox);
        pushButton_12->setObjectName("pushButton_12");
        pushButton_12->setGeometry(QRect(520, 210, 80, 31));
        pushButton_12->setFont(font);
        pushButton_12->setStyleSheet(QString::fromUtf8("  background-color: #FFFFFF;\n"
"    color: #1E2350;\n"
"    border-radius: 10px;\n"
"    font-size: 14px;\n"
"    padding: 8px;"));
        label_9 = new QLabel(horizontalGroupBox);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(40, 160, 121, 20));
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
" font-size: 13px;\n"
"    font-weight: bold;\n"
"    font-family: \"Poppins\";"));
        dernierDetectionInput = new QLineEdit(horizontalGroupBox);
        dernierDetectionInput->setObjectName("dernierDetectionInput");
        dernierDetectionInput->setGeometry(QRect(160, 160, 111, 16));
        dernierDetectionInput->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        label_12 = new QLabel(horizontalGroupBox);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(40, 220, 91, 20));
        label_12->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
" font-size: 13px;\n"
"    font-weight: bold;\n"
"    font-family: \"Poppins\";"));
        label_10 = new QLabel(horizontalGroupBox);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(40, 190, 91, 20));
        label_10->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
" font-size: 13px;\n"
"    font-weight: bold;\n"
"    font-family: \"Poppins\";"));
        nomCandidatInput = new QLineEdit(horizontalGroupBox);
        nomCandidatInput->setObjectName("nomCandidatInput");
        nomCandidatInput->setGeometry(QRect(160, 190, 111, 16));
        nomCandidatInput->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        pushButton_18 = new QPushButton(horizontalGroupBox);
        pushButton_18->setObjectName("pushButton_18");
        pushButton_18->setGeometry(QRect(320, 210, 80, 31));
        pushButton_18->setFont(font1);
        pushButton_18->setStyleSheet(QString::fromUtf8("  background-color: #FFFFFF;\n"
"  \n"
"    color: #1E2350;\n"
"    border-radius: 10px;\n"
"    font-size: 14px;\n"
"    padding: 8px;"));
        telephoneResourceInput = new QLineEdit(horizontalGroupBox);
        telephoneResourceInput->setObjectName("telephoneResourceInput");
        telephoneResourceInput->setGeometry(QRect(160, 220, 111, 16));
        telephoneResourceInput->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        label_5 = new QLabel(horizontalGroupBox);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(320, 50, 101, 21));
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
" font-size: 13px;\n"
"    font-weight: bold;\n"
"    font-family: \"Poppins\";"));
        emailResourceInput = new QLineEdit(horizontalGroupBox);
        emailResourceInput->setObjectName("emailResourceInput");
        emailResourceInput->setGeometry(QRect(440, 60, 111, 16));
        emailResourceInput->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        experienceResourceInput = new QLineEdit(horizontalGroupBox);
        experienceResourceInput->setObjectName("experienceResourceInput");
        experienceResourceInput->setGeometry(QRect(440, 90, 111, 16));
        experienceResourceInput->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);"));
        label_13 = new QLabel(horizontalGroupBox);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(320, 80, 101, 21));
        label_13->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
" font-size: 13px;\n"
"    font-weight: bold;\n"
"    font-family: \"Poppins\";"));
        label_3->raise();
        label_4->raise();
        label_6->raise();
        label_7->raise();
        pushButton_11->raise();
        pushButton_12->raise();
        nomResourceInput->raise();
        typeResourceInput->raise();
        categorieResourceInput->raise();
        quantiteResourceInput->raise();
        label_9->raise();
        dernierDetectionInput->raise();
        label_12->raise();
        label_10->raise();
        nomCandidatInput->raise();
        pushButton_18->raise();
        telephoneResourceInput->raise();
        label_5->raise();
        emailResourceInput->raise();
        experienceResourceInput->raise();
        label_13->raise();
        tabWidget->addTab(widget, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName("tab_6");
        tabWidget->addTab(tab_6, QString());
        barreverticale = new QFrame(centralwidget);
        barreverticale->setObjectName("barreverticale");
        barreverticale->setGeometry(QRect(0, 0, 201, 871));
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
        label = new QLabel(barreverticale);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 10, 131, 111));
        label->setStyleSheet(QString::fromUtf8("image: url(:/res/prof.png);"));
        GestionEvenementsButton = new QPushButton(barreverticale);
        GestionEvenementsButton->setObjectName("GestionEvenementsButton");
        GestionEvenementsButton->setGeometry(QRect(0, 210, 199, 81));
        GestionEvenementsButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: rgb(98, 135, 55);\n"
"font: 10pt \"Sylfaen\";\n"
"border-radius: 10px;\n"
"}\n"
"QPushButton:hover {\n"
"background-color: #7E9C5A;\n"
"}"));
        gestionClientsButton = new QPushButton(barreverticale);
        gestionClientsButton->setObjectName("gestionClientsButton");
        gestionClientsButton->setGeometry(QRect(0, 290, 199, 81));
        gestionClientsButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: rgb(98, 135, 55);\n"
"font: 10pt \"Sylfaen\";\n"
"border-radius: 10px;\n"
"}\n"
"QPushButton:hover {\n"
"background-color: #7E9C5A;\n"
"}"));
        GestionProjetsButton = new QPushButton(barreverticale);
        GestionProjetsButton->setObjectName("GestionProjetsButton");
        GestionProjetsButton->setGeometry(QRect(0, 370, 199, 81));
        GestionProjetsButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: rgb(98, 135, 55);\n"
"font: 10pt \"Sylfaen\";\n"
"border-radius: 10px;\n"
"}\n"
"QPushButton:hover {\n"
"background-color: #7E9C5A;\n"
"}"));
        GestionRessourcesButton = new QPushButton(barreverticale);
        GestionRessourcesButton->setObjectName("GestionRessourcesButton");
        GestionRessourcesButton->setGeometry(QRect(0, 450, 199, 81));
        GestionRessourcesButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: rgb(98, 135, 55);\n"
"font: 10pt \"Sylfaen\";\n"
"border-radius: 10px;\n"
"}\n"
"QPushButton:hover {\n"
"background-color: #7E9C5A;\n"
"}"));
        GestionStrategiesButton = new QPushButton(barreverticale);
        GestionStrategiesButton->setObjectName("GestionStrategiesButton");
        GestionStrategiesButton->setGeometry(QRect(0, 619, 199, 81));
        GestionStrategiesButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: rgb(98, 135, 55);\n"
"font: 10pt \"Sylfaen\";\n"
"border-radius: 10px;\n"
"}\n"
"QPushButton:hover {\n"
"background-color: #7E9C5A;\n"
"}"));
        GestionEmployeesButton = new QPushButton(barreverticale);
        GestionEmployeesButton->setObjectName("GestionEmployeesButton");
        GestionEmployeesButton->setGeometry(QRect(0, 540, 199, 81));
        GestionEmployeesButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: rgb(98, 135, 55);\n"
"font: 10pt \"Sylfaen\";\n"
"border-radius: 10px;\n"
"}\n"
"QPushButton:hover {\n"
"background-color: #7E9C5A;\n"
"}"));
        GestionParamtresButton = new QPushButton(barreverticale);
        GestionParamtresButton->setObjectName("GestionParamtresButton");
        GestionParamtresButton->setGeometry(QRect(0, 710, 199, 81));
        GestionParamtresButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: rgb(98, 135, 55);\n"
"font: 10pt \"Sylfaen\";\n"
"border-radius: 10px;\n"
"}\n"
"QPushButton:hover {\n"
"background-color: #7E9C5A;\n"
"}"));
        GestionParamtresButton_2 = new QPushButton(barreverticale);
        GestionParamtresButton_2->setObjectName("GestionParamtresButton_2");
        GestionParamtresButton_2->setGeometry(QRect(0, 130, 199, 81));
        GestionParamtresButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: rgb(98, 135, 55);\n"
"font: 10pt \"Sylfaen\";\n"
"border-radius: 10px;\n"
"}\n"
"QPushButton:hover {\n"
"background-color: #7E9C5A;\n"
"}"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1061, 21));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Recherche d'equipement avec son cin :", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Trier par :", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "ID", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("MainWindow", "Type", nullptr));

        pushButton_14->setText(QCoreApplication::translate("MainWindow", "Exportation", nullptr));
        pushButton_15->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        pushButton_16->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        searchbutt->setText(QString());
        deletebutt->setText(QCoreApplication::translate("MainWindow", "DELETE", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Nom Ressource:", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Type ressource", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "categorie:", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Quantite", nullptr));
        pushButton_11->setText(QCoreApplication::translate("MainWindow", "Valider", nullptr));
        pushButton_12->setText(QCoreApplication::translate("MainWindow", "Annuler", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "dernier_detection", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "telephone", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Nom condidat", nullptr));
        pushButton_18->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "email", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "experience", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(widget), QCoreApplication::translate("MainWindow", "Ajouter Employ\303\251", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QCoreApplication::translate("MainWindow", "Fonctionalit\303\251s", nullptr));
        label->setText(QString());
        GestionEvenementsButton->setText(QCoreApplication::translate("MainWindow", "Gestion \303\251vennements", nullptr));
        gestionClientsButton->setText(QCoreApplication::translate("MainWindow", "Gestion Clients", nullptr));
        GestionProjetsButton->setText(QCoreApplication::translate("MainWindow", "Gestion Projets", nullptr));
        GestionRessourcesButton->setText(QCoreApplication::translate("MainWindow", "Gestion Ressources", nullptr));
        GestionStrategiesButton->setText(QCoreApplication::translate("MainWindow", "Gestion Strat\303\251gies", nullptr));
        GestionEmployeesButton->setText(QCoreApplication::translate("MainWindow", "Gestion Employ\303\251es", nullptr));
        GestionParamtresButton->setText(QCoreApplication::translate("MainWindow", "Param\303\251tres", nullptr));
        GestionParamtresButton_2->setText(QCoreApplication::translate("MainWindow", "Acceuil", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
