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
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QFrame *barreverticale;
    QLabel *label;
    QPushButton *GestionEvenementsButton;
    QPushButton *gestionClientsButton;
    QPushButton *GestionProjetsButton;
    QPushButton *GestionRessourcesButton;
    QPushButton *GestionStrategiesButton;
    QPushButton *GestionEmployeesButton;
    QPushButton *GestionParamtresButton;
    QTabWidget *tabWidget;
    QWidget *tab;
    QFrame *frame_4;
    QPushButton *favorisProjet_3;
    QPushButton *notifications_3;
    QFrame *frame_31;
    QPushButton *ajout;
    QLabel *label_206;
    QLabel *label_207;
    QLabel *label_208;
    QLineEdit *locationLineEdit;
    QLineEdit *priceLineEdit;
    QLineEdit *nameLineEdit;
    QLabel *label_209;
    QLineEdit *maxNbLineEdit;
    QLabel *label_210;
    QLineEdit *durationLineEdit;
    QPushButton *pushButton_86;
    QLabel *label_201;
    QDateEdit *dateEdit;
    QFrame *frame_32;
    QLabel *label_228;
    QLabel *label_229;
    QLabel *label_230;
    QLineEdit *locationLineEdit_5;
    QLineEdit *priceLineEdit_5;
    QLineEdit *nameLineEdit_5;
    QLabel *label_231;
    QLineEdit *maxNbLineEdit_5;
    QLabel *label_232;
    QLineEdit *durationLineEdit_5;
    QPushButton *pushButton_90;
    QLabel *label_205;
    QDateEdit *dateEdit_5;
    QPushButton *modif;
    QLineEdit *id_modif;
    QLabel *label_233;
    QWidget *tab_2;
    QFrame *frame_list;
    QPushButton *pushButton_12;
    QLineEdit *searchLineEdit;
    QLineEdit *supp_line;
    QPushButton *consulterProjet_2;
    QTableView *tableView;
    QPushButton *supp;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1303, 729);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName("centralWidget");
        barreverticale = new QFrame(centralWidget);
        barreverticale->setObjectName("barreverticale");
        barreverticale->setGeometry(QRect(10, 30, 201, 591));
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
        label->setGeometry(QRect(30, 20, 141, 121));
        label->setStyleSheet(QString::fromUtf8("image: url(:/res/prof.png);"));
        GestionEvenementsButton = new QPushButton(barreverticale);
        GestionEvenementsButton->setObjectName("GestionEvenementsButton");
        GestionEvenementsButton->setGeometry(QRect(0, 160, 199, 61));
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
        gestionClientsButton->setGeometry(QRect(0, 220, 199, 61));
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
        GestionProjetsButton->setGeometry(QRect(0, 280, 199, 61));
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
        GestionRessourcesButton->setGeometry(QRect(0, 340, 199, 61));
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
        GestionStrategiesButton->setGeometry(QRect(0, 400, 199, 61));
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
        GestionEmployeesButton->setGeometry(QRect(0, 450, 199, 61));
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
        GestionParamtresButton->setGeometry(QRect(0, 510, 199, 61));
        GestionParamtresButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: rgb(98, 135, 55);\n"
"font: 10pt \"Sylfaen\";\n"
"border-radius: 10px;\n"
"}\n"
"QPushButton:hover {\n"
"background-color: #7E9C5A;\n"
"}"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(220, 20, 1041, 601));
        tab = new QWidget();
        tab->setObjectName("tab");
        frame_4 = new QFrame(tab);
        frame_4->setObjectName("frame_4");
        frame_4->setGeometry(QRect(0, 10, 1051, 601));
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe Ui")});
        font.setPointSize(20);
        font.setBold(false);
        font.setItalic(false);
        font.setKerning(true);
        frame_4->setFont(font);
        frame_4->setCursor(QCursor(Qt::CursorShape::WaitCursor));
        frame_4->setStyleSheet(QString::fromUtf8("background-color:rgb(255,255,255);\n"
"font:20pt \"Segoe Ui\";"));
        frame_4->setFrameShape(QFrame::Shape::StyledPanel);
        frame_4->setFrameShadow(QFrame::Shadow::Raised);
        favorisProjet_3 = new QPushButton(frame_4);
        favorisProjet_3->setObjectName("favorisProjet_3");
        favorisProjet_3->setGeometry(QRect(440, 20, 51, 51));
        favorisProjet_3->setStyleSheet(QString::fromUtf8("background-color:rgb(255,255,255);\n"
"font: 10pt \"Sylfaen\";\n"
"border-radius: 10px;"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/res/likes.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        favorisProjet_3->setIcon(icon);
        favorisProjet_3->setIconSize(QSize(50, 50));
        notifications_3 = new QPushButton(frame_4);
        notifications_3->setObjectName("notifications_3");
        notifications_3->setGeometry(QRect(500, 20, 51, 51));
        notifications_3->setStyleSheet(QString::fromUtf8("background-color:rgb(255,255,255);\n"
"font: 10pt \"Sylfaen\";\n"
"border-radius: 10px;"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/res/notif.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        notifications_3->setIcon(icon1);
        notifications_3->setIconSize(QSize(50, 50));
        frame_31 = new QFrame(frame_4);
        frame_31->setObjectName("frame_31");
        frame_31->setGeometry(QRect(10, 10, 401, 531));
        frame_31->setStyleSheet(QString::fromUtf8("QFrame {\n"
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
        frame_31->setFrameShape(QFrame::Shape::StyledPanel);
        frame_31->setFrameShadow(QFrame::Shadow::Raised);
        ajout = new QPushButton(frame_31);
        ajout->setObjectName("ajout");
        ajout->setGeometry(QRect(100, 470, 171, 51));
        ajout->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: rgb(98, 135, 55);\n"
"font: 10pt \"Sylfaen\";\n"
"border-radius: 10px;\n"
"}\n"
"QPushButton:hover {\n"
"background-color: #7E9C5A;\n"
"}"));
        label_206 = new QLabel(frame_31);
        label_206->setObjectName("label_206");
        label_206->setGeometry(QRect(10, 340, 191, 44));
        label_206->setStyleSheet(QString::fromUtf8("label->setStyleSheet(\"QLabel { color: black; font-size: 10px; border: none; }\");\n"
""));
        label_207 = new QLabel(frame_31);
        label_207->setObjectName("label_207");
        label_207->setGeometry(QRect(10, 70, 191, 44));
        label_207->setStyleSheet(QString::fromUtf8("label->setStyleSheet(\"QLabel { color: black; font-size: 10px; border: none; }\");\n"
""));
        label_208 = new QLabel(frame_31);
        label_208->setObjectName("label_208");
        label_208->setGeometry(QRect(10, 210, 191, 44));
        label_208->setStyleSheet(QString::fromUtf8("label->setStyleSheet(\"QLabel { color: black; font-size: 10px; border: none; }\");\n"
""));
        locationLineEdit = new QLineEdit(frame_31);
        locationLineEdit->setObjectName("locationLineEdit");
        locationLineEdit->setGeometry(QRect(220, 280, 159, 44));
        locationLineEdit->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        priceLineEdit = new QLineEdit(frame_31);
        priceLineEdit->setObjectName("priceLineEdit");
        priceLineEdit->setGeometry(QRect(220, 210, 159, 44));
        priceLineEdit->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        nameLineEdit = new QLineEdit(frame_31);
        nameLineEdit->setObjectName("nameLineEdit");
        nameLineEdit->setGeometry(QRect(220, 70, 159, 44));
        nameLineEdit->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_209 = new QLabel(frame_31);
        label_209->setObjectName("label_209");
        label_209->setGeometry(QRect(10, 280, 191, 44));
        label_209->setStyleSheet(QString::fromUtf8("label->setStyleSheet(\"QLabel { color: black; font-size: 10px; border: none; }\");\n"
""));
        maxNbLineEdit = new QLineEdit(frame_31);
        maxNbLineEdit->setObjectName("maxNbLineEdit");
        maxNbLineEdit->setGeometry(QRect(220, 340, 159, 44));
        maxNbLineEdit->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_210 = new QLabel(frame_31);
        label_210->setObjectName("label_210");
        label_210->setGeometry(QRect(10, 400, 191, 44));
        label_210->setStyleSheet(QString::fromUtf8("label->setStyleSheet(\"QLabel { color: black; font-size: 10px; border: none; }\");\n"
""));
        durationLineEdit = new QLineEdit(frame_31);
        durationLineEdit->setObjectName("durationLineEdit");
        durationLineEdit->setGeometry(QRect(220, 400, 159, 44));
        durationLineEdit->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        pushButton_86 = new QPushButton(frame_31);
        pushButton_86->setObjectName("pushButton_86");
        pushButton_86->setGeometry(QRect(0, 0, 401, 51));
        pushButton_86->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color:rgb(209, 199, 161);\n"
"font: 10pt \"Sylfaen\";\n"
"border-radius: 10px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #F5F5DC; /* Beige soft */\n"
"}"));
        label_201 = new QLabel(frame_31);
        label_201->setObjectName("label_201");
        label_201->setGeometry(QRect(10, 140, 191, 44));
        label_201->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(245, 245, 220); /* Beige */"));
        dateEdit = new QDateEdit(frame_31);
        dateEdit->setObjectName("dateEdit");
        dateEdit->setGeometry(QRect(220, 140, 151, 51));
        dateEdit->setStyleSheet(QString::fromUtf8("QDateEdit {\n"
"    background-color: #f5f5f5; /* Light gray background */\n"
"    color: #333; /* Text color */\n"
"    border: 1px solid #aaa; /* Light gray border */\n"
"    border-radius: 5px; /* Rounded corners */\n"
"    padding: 5px; /* Padding inside the widget */\n"
"    font-size: 14px; /* Font size */\n"
"}\n"
"\n"
"QDateEdit::drop-down {\n"
"    background-color: #ddd; /* Background color for the drop-down */\n"
"    border-left: 1px solid #aaa; /* Border for the drop-down */\n"
"    width: 20px; /* Adjust the width of the drop-down button */\n"
"}\n"
"\n"
"QDateEdit::down-arrow {\n"
"    image: url(:/icons/down_arrow.png); /* Custom down arrow image */\n"
"}\n"
""));
        frame_32 = new QFrame(frame_4);
        frame_32->setObjectName("frame_32");
        frame_32->setGeometry(QRect(500, 20, 401, 531));
        frame_32->setStyleSheet(QString::fromUtf8("QFrame {\n"
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
        frame_32->setFrameShape(QFrame::Shape::StyledPanel);
        frame_32->setFrameShadow(QFrame::Shadow::Raised);
        label_228 = new QLabel(frame_32);
        label_228->setObjectName("label_228");
        label_228->setGeometry(QRect(10, 330, 191, 44));
        label_228->setStyleSheet(QString::fromUtf8("label->setStyleSheet(\"QLabel { color: black; font-size: 10px; border: none; }\");\n"
""));
        label_229 = new QLabel(frame_32);
        label_229->setObjectName("label_229");
        label_229->setGeometry(QRect(10, 120, 191, 44));
        label_229->setStyleSheet(QString::fromUtf8("label->setStyleSheet(\"QLabel { color: black; font-size: 10px; border: none; }\");\n"
""));
        label_230 = new QLabel(frame_32);
        label_230->setObjectName("label_230");
        label_230->setGeometry(QRect(10, 230, 191, 44));
        label_230->setStyleSheet(QString::fromUtf8("label->setStyleSheet(\"QLabel { color: black; font-size: 10px; border: none; }\");\n"
""));
        locationLineEdit_5 = new QLineEdit(frame_32);
        locationLineEdit_5->setObjectName("locationLineEdit_5");
        locationLineEdit_5->setGeometry(QRect(220, 280, 159, 44));
        locationLineEdit_5->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        priceLineEdit_5 = new QLineEdit(frame_32);
        priceLineEdit_5->setObjectName("priceLineEdit_5");
        priceLineEdit_5->setGeometry(QRect(220, 230, 159, 44));
        priceLineEdit_5->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        nameLineEdit_5 = new QLineEdit(frame_32);
        nameLineEdit_5->setObjectName("nameLineEdit_5");
        nameLineEdit_5->setGeometry(QRect(210, 120, 159, 44));
        nameLineEdit_5->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_231 = new QLabel(frame_32);
        label_231->setObjectName("label_231");
        label_231->setGeometry(QRect(10, 280, 191, 44));
        label_231->setStyleSheet(QString::fromUtf8("label->setStyleSheet(\"QLabel { color: black; font-size: 10px; border: none; }\");\n"
""));
        maxNbLineEdit_5 = new QLineEdit(frame_32);
        maxNbLineEdit_5->setObjectName("maxNbLineEdit_5");
        maxNbLineEdit_5->setGeometry(QRect(220, 330, 159, 44));
        maxNbLineEdit_5->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_232 = new QLabel(frame_32);
        label_232->setObjectName("label_232");
        label_232->setGeometry(QRect(10, 380, 191, 44));
        label_232->setStyleSheet(QString::fromUtf8("label->setStyleSheet(\"QLabel { color: black; font-size: 10px; border: none; }\");\n"
""));
        durationLineEdit_5 = new QLineEdit(frame_32);
        durationLineEdit_5->setObjectName("durationLineEdit_5");
        durationLineEdit_5->setGeometry(QRect(220, 380, 159, 44));
        durationLineEdit_5->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        pushButton_90 = new QPushButton(frame_32);
        pushButton_90->setObjectName("pushButton_90");
        pushButton_90->setGeometry(QRect(0, 0, 401, 51));
        pushButton_90->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color:rgb(209, 199, 161);\n"
"font: 10pt \"Sylfaen\";\n"
"border-radius: 10px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #F5F5DC; /* Beige soft */\n"
"}"));
        label_205 = new QLabel(frame_32);
        label_205->setObjectName("label_205");
        label_205->setGeometry(QRect(10, 180, 191, 44));
        label_205->setStyleSheet(QString::fromUtf8("\n"
"background-color: rgb(245, 245, 220); /* Beige */"));
        dateEdit_5 = new QDateEdit(frame_32);
        dateEdit_5->setObjectName("dateEdit_5");
        dateEdit_5->setGeometry(QRect(220, 170, 151, 51));
        dateEdit_5->setStyleSheet(QString::fromUtf8("QDateEdit {\n"
"    background-color: #f5f5f5; /* Light gray background */\n"
"    color: #333; /* Text color */\n"
"    border: 1px solid #aaa; /* Light gray border */\n"
"    border-radius: 5px; /* Rounded corners */\n"
"    padding: 5px; /* Padding inside the widget */\n"
"    font-size: 14px; /* Font size */\n"
"}\n"
"\n"
"QDateEdit::drop-down {\n"
"    background-color: #ddd; /* Background color for the drop-down */\n"
"    border-left: 1px solid #aaa; /* Border for the drop-down */\n"
"    width: 20px; /* Adjust the width of the drop-down button */\n"
"}\n"
"\n"
"QDateEdit::down-arrow {\n"
"    image: url(:/icons/down_arrow.png); /* Custom down arrow image */\n"
"}\n"
""));
        modif = new QPushButton(frame_32);
        modif->setObjectName("modif");
        modif->setGeometry(QRect(130, 450, 171, 51));
        modif->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: rgb(98, 135, 55);\n"
"font: 10pt \"Sylfaen\";\n"
"border-radius: 10px;\n"
"}\n"
"QPushButton:hover {\n"
"background-color: #7E9C5A;\n"
"}"));
        id_modif = new QLineEdit(frame_32);
        id_modif->setObjectName("id_modif");
        id_modif->setGeometry(QRect(210, 60, 159, 44));
        id_modif->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));
        label_233 = new QLabel(frame_32);
        label_233->setObjectName("label_233");
        label_233->setGeometry(QRect(10, 60, 191, 44));
        label_233->setStyleSheet(QString::fromUtf8("label->setStyleSheet(\"QLabel { color: black; font-size: 10px; border: none; }\");\n"
""));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        frame_list = new QFrame(tab_2);
        frame_list->setObjectName("frame_list");
        frame_list->setGeometry(QRect(0, 10, 1021, 541));
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
        pushButton_12 = new QPushButton(frame_list);
        pushButton_12->setObjectName("pushButton_12");
        pushButton_12->setGeometry(QRect(830, 110, 151, 51));
        pushButton_12->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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
        searchLineEdit->setGeometry(QRect(40, 40, 921, 41));
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
        supp_line = new QLineEdit(frame_list);
        supp_line->setObjectName("supp_line");
        supp_line->setGeometry(QRect(30, 460, 191, 41));
        supp_line->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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
        supp_line->setCursorMoveStyle(Qt::CursorMoveStyle::LogicalMoveStyle);
        consulterProjet_2 = new QPushButton(frame_list);
        consulterProjet_2->setObjectName("consulterProjet_2");
        consulterProjet_2->setGeometry(QRect(830, 170, 151, 51));
        consulterProjet_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: rgb(160, 82, 45);\n"
"font: 10pt \"Sylfaen\";\n"
"border-radius: 10px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #D2B48C; /* Marron soft */\n"
"}\n"
""));
        tableView = new QTableView(frame_list);
        tableView->setObjectName("tableView");
        tableView->setGeometry(QRect(30, 100, 791, 351));
        supp = new QPushButton(frame_list);
        supp->setObjectName("supp");
        supp->setGeometry(QRect(240, 460, 151, 41));
        supp->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: rgb(160, 82, 45);\n"
"font: 10pt \"Sylfaen\";\n"
"border-radius: 10px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #D2B48C; /* Marron soft */\n"
"}\n"
""));
        tabWidget->addTab(tab_2, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName("menuBar");
        menuBar->setGeometry(QRect(0, 0, 1303, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName("mainToolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName("statusBar");
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Gestion des Clients", nullptr));
        label->setText(QString());
        GestionEvenementsButton->setText(QCoreApplication::translate("MainWindow", "Gestion \303\251vennements", nullptr));
        gestionClientsButton->setText(QCoreApplication::translate("MainWindow", "Gestion Clients", nullptr));
        GestionProjetsButton->setText(QCoreApplication::translate("MainWindow", "Gestion Projets", nullptr));
        GestionRessourcesButton->setText(QCoreApplication::translate("MainWindow", "Gestion Ressources", nullptr));
        GestionStrategiesButton->setText(QCoreApplication::translate("MainWindow", "Gestion Strat\303\251gies", nullptr));
        GestionEmployeesButton->setText(QCoreApplication::translate("MainWindow", "Gestion Employ\303\251es", nullptr));
        GestionParamtresButton->setText(QCoreApplication::translate("MainWindow", "Param\303\251tres", nullptr));
        favorisProjet_3->setText(QString());
        notifications_3->setText(QString());
        ajout->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        label_206->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">Places :</span></p></body></html>", nullptr));
        label_207->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">Nom :</span></p></body></html>", nullptr));
        label_208->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">Prix :</span></p></body></html>", nullptr));
        label_209->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">localisation :</span></p></body></html>", nullptr));
        label_210->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">Duree :</span></p></body></html>", nullptr));
        pushButton_86->setText(QCoreApplication::translate("MainWindow", "Ajouter Un Projet", nullptr));
        label_201->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">Date :</span></p></body></html>", nullptr));
        label_228->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">Places :</span></p></body></html>", nullptr));
        label_229->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">Nom :</span></p></body></html>", nullptr));
        label_230->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">Prix :</span></p></body></html>", nullptr));
        label_231->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">localisation :</span></p></body></html>", nullptr));
        label_232->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">Duree :</span></p></body></html>", nullptr));
        pushButton_90->setText(QCoreApplication::translate("MainWindow", "Ajouter Un Projet", nullptr));
        label_205->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">Date :</span></p></body></html>", nullptr));
        modif->setText(QCoreApplication::translate("MainWindow", "Modification", nullptr));
        label_233->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">Id :</span></p></body></html>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "ajout", nullptr));
        pushButton_12->setText(QCoreApplication::translate("MainWindow", "PDF", nullptr));
        searchLineEdit->setPlaceholderText(QCoreApplication::translate("MainWindow", "Entrez le titre ici", nullptr));
        supp_line->setPlaceholderText(QCoreApplication::translate("MainWindow", "Entrez le titre ici", nullptr));
        consulterProjet_2->setText(QCoreApplication::translate("MainWindow", "Consulter", nullptr));
        supp->setText(QCoreApplication::translate("MainWindow", "supp", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "consulter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
