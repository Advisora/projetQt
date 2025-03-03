/********************************************************************************
** Form generated from reading UI file 'log.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOG_H
#define UI_LOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QGroupBox *groupBox;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *label_5;
    QFrame *frame_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_7;
    QPushButton *pushButton_3;
    QWidget *tab_2;
    QFrame *frame;
    QLabel *label_4;
    QLabel *label_2;
    QPushButton *pushButton;
    QLineEdit *lineEdit;
    QLabel *label;
    QLabel *label_3;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit_2;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(832, 490);
        groupBox = new QGroupBox(Dialog);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(-20, 0, 1291, 521));
        tabWidget = new QTabWidget(groupBox);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(20, 0, 801, 511));
        tabWidget->setStyleSheet(QString::fromUtf8("QTabWidget::pane {\n"
"    border: 2px solid #D35400;\n"
"    border-radius: 8px;\n"
"    background-color: #FFFFFF;\n"
"}\n"
""));
        tab = new QWidget();
        tab->setObjectName("tab");
        label_5 = new QLabel(tab);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(-230, 0, 1401, 471));
        label_5->setStyleSheet(QString::fromUtf8("image:url(:/res/interface2.png)"));
        frame_2 = new QFrame(tab);
        frame_2->setObjectName("frame_2");
        frame_2->setGeometry(QRect(0, 0, 151, 571));
        frame_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        lineEdit_3 = new QLineEdit(tab);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(280, 200, 113, 26));
        lineEdit_4 = new QLineEdit(tab);
        lineEdit_4->setObjectName("lineEdit_4");
        lineEdit_4->setGeometry(QRect(280, 240, 113, 26));
        lineEdit_5 = new QLineEdit(tab);
        lineEdit_5->setObjectName("lineEdit_5");
        lineEdit_5->setGeometry(QRect(280, 280, 113, 26));
        lineEdit_6 = new QLineEdit(tab);
        lineEdit_6->setObjectName("lineEdit_6");
        lineEdit_6->setGeometry(QRect(280, 160, 113, 26));
        lineEdit_7 = new QLineEdit(tab);
        lineEdit_7->setObjectName("lineEdit_7");
        lineEdit_7->setGeometry(QRect(280, 90, 270, 41));
        lineEdit_7->setStyleSheet(QString::fromUtf8("/* --- QLineEdit Styling (Fine Border with Olive Green) --- */\n"
"QLineEdit {\n"
"    padding: 8px;\n"
"    border: 1.5px solid #A3A37A; /* Olive Green fine border */\n"
"    border-radius: 6px; /* Smooth rounded edges */\n"
"    font-size: 16px;\n"
"    color: #2C3E50; /* Dark grey text */\n"
"    background-color: #FAFAF8; /* Soft white background */\n"
"    height: 30px; /* Ensures consistency */\n"
"    min-width: 250px; /* Keeps input size uniform */\n"
"    transition: all 0.3s ease-in-out;\n"
"}\n"
"\n"
"/* --- Focus Effect for QLineEdit --- */\n"
"QLineEdit:focus {\n"
"    border: 1.5px solid #808000; /* Darker Olive Green when focused */\n"
"    background-color: #FFFFFF; /* White background */\n"
"    box-shadow: 0px 0px 6px rgba(128, 128, 0, 0.4); /* Soft glow */\n"
"    outline: none;\n"
"}\n"
"\n"
"/* --- Placeholder Styling --- */\n"
"QLineEdit::placeholder {\n"
"    color: #A9A9A9; /* Soft grey placeholder text */\n"
"    font-style: italic;\n"
"}\n"
"\n"
"/* --- Password Field Styling --- */\n"
""
                        "QLineEdit[echoMode=\"2\"] {  \n"
"    letter-spacing: 4px; /* Adjust spacing for password dots */\n"
"}"));
        pushButton_3 = new QPushButton(tab);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(540, 310, 214, 41));
        pushButton_3->setStyleSheet(QString::fromUtf8("/* --- QPushButton Styling (Bright Olive Green with Animation) --- */\n"
"QPushButton {\n"
"    background-color: #8B9B3D;       /* Bright Olive Green */\n"
"    color: white;                    /* White text */\n"
"    padding: 12px 30px;               /* Generous padding */\n"
"    font-size: 16px;                  /* Font size */\n"
"    font-weight: bold;                /* Bold text */\n"
"    border-radius: 8px;               /* Rounded corners */\n"
"    border: 2px solid #6C7C2F;        /* Dark olive border */\n"
"    min-width: 150px;                 /* Minimum button width */\n"
"    text-align: center;               /* Center text */\n"
"    transition: all 0.3s ease-in-out; /* Smooth transition */\n"
"    opacity: 0;                       /* Start with the text hidden */\n"
"    animation: fadeInText 0.5s forwards; /* Text fade-in animation */\n"
"}\n"
"\n"
"/* --- Hover Effect for QPushButton (Bright Olive Green) --- */\n"
"QPushButton:hover {\n"
"    background-color: #A4C73C;        /* Lighter Ol"
                        "ive Green on hover */\n"
"    box-shadow: 0px 5px 20px rgba(139, 155, 61, 0.6); /* Subtle shadow */\n"
"    cursor: pointer;                  /* Pointer cursor on hover */\n"
"    transform: scale(1.05);            /* Button slightly grows on hover */\n"
"}\n"
"\n"
"/* --- Pressed State (Slight Movement and Darker Color) --- */\n"
"QPushButton:pressed {\n"
"    background-color: #7A8F33;        /* Darker Olive Green when pressed */\n"
"    box-shadow: none;                  /* No shadow on press */\n"
"    transform: scale(0.98);            /* Slightly shrinks when pressed */\n"
"}\n"
"\n"
"/* --- Disabled State for QPushButton (Gray) --- */\n"
"QPushButton:disabled {\n"
"    background-color: #BDBDBD;         /* Gray background */\n"
"    color: #888888;                    /* Gray text */\n"
"    cursor: not-allowed;               /* Disable cursor */\n"
"}\n"
"\n"
"/* --- Focused State for QPushButton (Glow Effect) --- */\n"
"QPushButton:focus {\n"
"    outline: none;                     /* Remove default ou"
                        "tline */\n"
"    box-shadow: 0px 0px 10px rgba(139, 155, 61, 0.8); /* Glowing effect */\n"
"}\n"
"\n"
"/* --- Text Fade-in Animation (Button Text Animation) --- */\n"
"@keyframes fadeInText {\n"
"    0% {\n"
"        opacity: 0;    /* Text starts as invisible */\n"
"        transform: translateY(-10px);  /* Text starts slightly above */\n"
"    }\n"
"    100% {\n"
"        opacity: 1;    /* Text becomes fully visible */\n"
"        transform: translateY(0);  /* Text settles into place */\n"
"    }\n"
"}\n"
""));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        frame = new QFrame(tab_2);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(660, 0, 151, 571));
        frame->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        label_4 = new QLabel(tab_2);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(-80, 0, 851, 471));
        label_4->setStyleSheet(QString::fromUtf8("image: url(:/res/INTERCON.png);"));
        label_2 = new QLabel(tab_2);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(360, 300, 91, 20));
        label_2->setStyleSheet(QString::fromUtf8("/* --- QLabel Styling (Titres au-dessus des QLineEdit) --- */\n"
"QLabel {\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    color: #556B2F; /* Olive Green */\n"
"    padding-bottom: 4px; /* Espacement avec le champ */\n"
"}\n"
""));
        pushButton = new QPushButton(tab_2);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(90, 300, 214, 41));
        pushButton->setStyleSheet(QString::fromUtf8("/* --- QPushButton Styling (Bright Olive Green with Animation) --- */\n"
"QPushButton {\n"
"    background-color: #8B9B3D;       /* Bright Olive Green */\n"
"    color: white;                    /* White text */\n"
"    padding: 12px 30px;               /* Generous padding */\n"
"    font-size: 16px;                  /* Font size */\n"
"    font-weight: bold;                /* Bold text */\n"
"    border-radius: 8px;               /* Rounded corners */\n"
"    border: 2px solid #6C7C2F;        /* Dark olive border */\n"
"    min-width: 150px;                 /* Minimum button width */\n"
"    text-align: center;               /* Center text */\n"
"    transition: all 0.3s ease-in-out; /* Smooth transition */\n"
"    opacity: 0;                       /* Start with the text hidden */\n"
"    animation: fadeInText 0.5s forwards; /* Text fade-in animation */\n"
"}\n"
"\n"
"/* --- Hover Effect for QPushButton (Bright Olive Green) --- */\n"
"QPushButton:hover {\n"
"    background-color: #A4C73C;        /* Lighter Ol"
                        "ive Green on hover */\n"
"    box-shadow: 0px 5px 20px rgba(139, 155, 61, 0.6); /* Subtle shadow */\n"
"    cursor: pointer;                  /* Pointer cursor on hover */\n"
"    transform: scale(1.05);            /* Button slightly grows on hover */\n"
"}\n"
"\n"
"/* --- Pressed State (Slight Movement and Darker Color) --- */\n"
"QPushButton:pressed {\n"
"    background-color: #7A8F33;        /* Darker Olive Green when pressed */\n"
"    box-shadow: none;                  /* No shadow on press */\n"
"    transform: scale(0.98);            /* Slightly shrinks when pressed */\n"
"}\n"
"\n"
"/* --- Disabled State for QPushButton (Gray) --- */\n"
"QPushButton:disabled {\n"
"    background-color: #BDBDBD;         /* Gray background */\n"
"    color: #888888;                    /* Gray text */\n"
"    cursor: not-allowed;               /* Disable cursor */\n"
"}\n"
"\n"
"/* --- Focused State for QPushButton (Glow Effect) --- */\n"
"QPushButton:focus {\n"
"    outline: none;                     /* Remove default ou"
                        "tline */\n"
"    box-shadow: 0px 0px 10px rgba(139, 155, 61, 0.8); /* Glowing effect */\n"
"}\n"
"\n"
"/* --- Text Fade-in Animation (Button Text Animation) --- */\n"
"@keyframes fadeInText {\n"
"    0% {\n"
"        opacity: 0;    /* Text starts as invisible */\n"
"        transform: translateY(-10px);  /* Text starts slightly above */\n"
"    }\n"
"    100% {\n"
"        opacity: 1;    /* Text becomes fully visible */\n"
"        transform: translateY(0);  /* Text settles into place */\n"
"    }\n"
"}\n"
""));
        lineEdit = new QLineEdit(tab_2);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(440, 290, 270, 51));
        lineEdit->setStyleSheet(QString::fromUtf8("/* --- QLineEdit Styling (Fine Border with Olive Green) --- */\n"
"QLineEdit {\n"
"    padding: 8px;\n"
"    border: 1.5px solid #A3A37A; /* Olive Green fine border */\n"
"    border-radius: 6px; /* Smooth rounded edges */\n"
"    font-size: 16px;\n"
"    color: #2C3E50; /* Dark grey text */\n"
"    background-color: #FAFAF8; /* Soft white background */\n"
"    height: 30px; /* Ensures consistency */\n"
"    min-width: 250px; /* Keeps input size uniform */\n"
"    transition: all 0.3s ease-in-out;\n"
"}\n"
"\n"
"/* --- Focus Effect for QLineEdit --- */\n"
"QLineEdit:focus {\n"
"    border: 1.5px solid #808000; /* Darker Olive Green when focused */\n"
"    background-color: #FFFFFF; /* White background */\n"
"    box-shadow: 0px 0px 6px rgba(128, 128, 0, 0.4); /* Soft glow */\n"
"    outline: none;\n"
"}\n"
"\n"
"/* --- Placeholder Styling --- */\n"
"QLineEdit::placeholder {\n"
"    color: #A9A9A9; /* Soft grey placeholder text */\n"
"    font-style: italic;\n"
"}\n"
"\n"
"/* --- Password Field Styling --- */\n"
""
                        "QLineEdit[echoMode=\"2\"] {  \n"
"    letter-spacing: 4px; /* Adjust spacing for password dots */\n"
"}"));
        label = new QLabel(tab_2);
        label->setObjectName("label");
        label->setGeometry(QRect(370, 230, 171, 41));
        label->setStyleSheet(QString::fromUtf8("/* --- QLabel Styling (Titres au-dessus des QLineEdit) --- */\n"
"QLabel {\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    color: #556B2F; /* Olive Green */\n"
"    padding-bottom: 4px; /* Espacement avec le champ */\n"
"}\n"
""));
        label_3 = new QLabel(tab_2);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(420, 20, 301, 151));
        label_3->setStyleSheet(QString::fromUtf8("/* --- Title Styling for QLabel with ID 'title' --- */\n"
"    font-size: 50px;            /* Large font size for title */\n"
"    font-weight: bold;          /* Bold title */\n"
"    color: #556B2F;             /* Olive green color */\n"
"    padding-bottom: 20px;       /* Space between title and content */\n"
"    text-align: center;         /* Center align the title */\n"
"    margin-top: 40px;           /* Space at the top */\n"
"    font-family: 'Arial', sans-serif; /* Elegant font */\n"
"\n"
"\n"
"/* --- Optional: Hover Effect for Title --\n"
"    color: #3E4F1F;             /* Slightly darker olive green on hover */\n"
"    cursor: pointer;           /* Makes the title clickable */\n"
""));
        pushButton_2 = new QPushButton(tab_2);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(440, 370, 264, 51));
        pushButton_2->setStyleSheet(QString::fromUtf8("/* --- QPushButton Styling (Bright Olive Green with Animation) --- */\n"
"QPushButton {\n"
"    background-color: #8B9B3D;       /* Bright Olive Green */\n"
"    color: white;                    /* White text */\n"
"    padding: 12px 30px;               /* Generous padding */\n"
"    font-size: 16px;                  /* Font size */\n"
"    font-weight: bold;                /* Bold text */\n"
"    border-radius: 8px;               /* Rounded corners */\n"
"    border: 2px solid #6C7C2F;        /* Dark olive border */\n"
"    min-width: 200px;                 /* Minimum button width */\n"
"    text-align: center;               /* Center text */\n"
"    transition: all 0.3s ease-in-out; /* Smooth transition */\n"
"    opacity: 0;                       /* Start with the text hidden */\n"
"    animation: fadeInText 0.5s forwards; /* Text fade-in animation */\n"
"}\n"
"\n"
"/* --- Hover Effect for QPushButton (Bright Olive Green) --- */\n"
"QPushButton:hover {\n"
"    background-color: #A4C73C;        /* Lighter Ol"
                        "ive Green on hover */\n"
"    box-shadow: 0px 5px 20px rgba(139, 155, 61, 0.6); /* Subtle shadow */\n"
"    cursor: pointer;                  /* Pointer cursor on hover */\n"
"    transform: scale(1.05);            /* Button slightly grows on hover */\n"
"}\n"
"\n"
"/* --- Pressed State (Slight Movement and Darker Color) --- */\n"
"QPushButton:pressed {\n"
"    background-color: #7A8F33;        /* Darker Olive Green when pressed */\n"
"    box-shadow: none;                  /* No shadow on press */\n"
"    transform: scale(0.98);            /* Slightly shrinks when pressed */\n"
"}\n"
"\n"
"/* --- Disabled State for QPushButton (Gray) --- */\n"
"QPushButton:disabled {\n"
"    background-color: #BDBDBD;         /* Gray background */\n"
"    color: #888888;                    /* Gray text */\n"
"    cursor: not-allowed;               /* Disable cursor */\n"
"}\n"
"\n"
"/* --- Focused State for QPushButton (Glow Effect) --- */\n"
"QPushButton:focus {\n"
"    outline: none;                     /* Remove default ou"
                        "tline */\n"
"    box-shadow: 0px 0px 10px rgba(139, 155, 61, 0.8); /* Glowing effect */\n"
"}\n"
"\n"
"/* --- Text Fade-in Animation (Button Text Animation) --- */\n"
"@keyframes fadeInText {\n"
"    0% {\n"
"        opacity: 0;    /* Text starts as invisible */\n"
"        transform: translateY(-10px);  /* Text starts slightly above */\n"
"    }\n"
"    100% {\n"
"        opacity: 1;    /* Text becomes fully visible */\n"
"        transform: translateY(0);  /* Text settles into place */\n"
"    }\n"
"}\n"
""));
        lineEdit_2 = new QLineEdit(tab_2);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(440, 220, 270, 51));
        lineEdit_2->setStyleSheet(QString::fromUtf8("/* --- QLineEdit Styling (Fine Border with Olive Green) --- */\n"
"QLineEdit {\n"
"    padding: 8px;\n"
"    border: 1.5px solid #A3A37A; /* Olive Green fine border */\n"
"    border-radius: 6px; /* Smooth rounded edges */\n"
"    font-size: 16px;\n"
"    color: #2C3E50; /* Dark grey text */\n"
"    background-color: #FAFAF8; /* Soft white background */\n"
"    height: 30px; /* Ensures consistency */\n"
"    min-width: 250px; /* Keeps input size uniform */\n"
"    transition: all 0.3s ease-in-out;\n"
"}\n"
"\n"
"/* --- Focus Effect for QLineEdit --- */\n"
"QLineEdit:focus {\n"
"    border: 1.5px solid #808000; /* Darker Olive Green when focused */\n"
"    background-color: #FFFFFF; /* White background */\n"
"    box-shadow: 0px 0px 6px rgba(128, 128, 0, 0.4); /* Soft glow */\n"
"    outline: none;\n"
"}\n"
"\n"
"/* --- Placeholder Styling --- */\n"
"QLineEdit::placeholder {\n"
"    color: #A9A9A9; /* Soft grey placeholder text */\n"
"    font-style: italic;\n"
"}\n"
"\n"
"/* --- Password Field Styling --- */\n"
""
                        "QLineEdit[echoMode=\"2\"] {  \n"
"    letter-spacing: 4px; /* Adjust spacing for password dots */\n"
"}"));
        tabWidget->addTab(tab_2, QString());

        retranslateUi(Dialog);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Dialog", "GroupBox", nullptr));
        label_5->setText(QString());
        pushButton_3->setText(QCoreApplication::translate("Dialog", "se connecter", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("Dialog", "Tab 1", nullptr));
        label_4->setText(QString());
        label_2->setText(QCoreApplication::translate("Dialog", "password", nullptr));
        pushButton->setText(QCoreApplication::translate("Dialog", "s'inscrire", nullptr));
        label->setText(QCoreApplication::translate("Dialog", "mail:", nullptr));
        label_3->setText(QCoreApplication::translate("Dialog", "connexion", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Dialog", "se connecter", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("Dialog", "Tab 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOG_H
