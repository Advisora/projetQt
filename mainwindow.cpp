#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QDebug>
#include <QMessageBox>
#include <QTextDocument>
#include <QTextCursor>
#include <QTextTable>
#include <QPdfWriter>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QPainter>
#include <QDate>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
    // Inside the constructor of `MainWindow`
    ui->dateN->clear();
    ui->tableView->verticalHeader()->setVisible(false);

    ui->dateN->setButtonSymbols(QDateEdit::NoButtons);
    ui->dateN->setStyleSheet(
        "QDateEdit {"

        "   border-radius: 10px;"       // Slightly rounded corners
        "   font: 12px;"               // Normal font size
        "   color: black;"             // Dark gray text color
        "   background-color: white;"  // White background
        "}"
        "QDateEdit::down-arrow, QDateEdit::up-arrow, QDateEdit::drop-down {"
        "   width: 0px;"               // No width
        "   height: 0px;"              // No height
        "   border: none;"             // No border
        "   padding: 0px;"             // No padding
        "   background: none;"         // No background
        "   image: none;"              // No image
        "}"
        );
    ui->tableView->setStyleSheet(
        "QTableView {"
        "    gridline-color: #DDDDDD;" // Light grey grid lines
        "    selection-background-color: #A8DADC;" // Light blue selection
        "    selection-color: black;" // Selected text color
        "    background: white;"
        "    alternate-background-color: #F1F1F1;" // Subtle row alternation
        "    border: 1px solid #CCCCCC;"
        "}"

        "QHeaderView::section {"
        "     background-color: rgb(98, 135, 55);" // Header background color
        "    color: white;" // Header text color
        "    padding: 5px;"
        "    font-size: 10pt;" // Reduce header text size
        "    border: none;"
        "}"

        "QScrollBar:vertical {"
        "    border: none;"
        "    background: #F0F0F0;" // Light background
        "    width: 8px;" // Slim scrollbar
        "    margin: 0px 0px 0px 0px;"
        "}"

        "QScrollBar::handle:vertical {"
        "    background: #8D99AE;" // Darker handle
        "    min-height: 20px;"
        "    border-radius: 4px;"
        "}"

        "QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical {"
        "    height: 0px;" // Remove arrows
        "}"

        "QScrollBar:horizontal {"
        "    border: none;"
        "    background: #F0F0F0;"
        "    height: 8px;"
        "    margin: 0px 0px 0px 0px;"
        "}"

        "QScrollBar::handle:horizontal {"
        "    background: #8D99AE;"
        "    min-width: 20px;"
        "    border-radius: 4px;"
        "}"

        "QScrollBar::add-line:horizontal, QScrollBar::sub-line:horizontal {"
        "    width: 0px;"
        "}"
        );


    loadClients();
    // page client
    connect(ui->gestionClientsButton, &QPushButton::clicked, this, &MainWindow::on_gestionClientsButton_clicked);
    ui->stackedWidget->setCurrentIndex(0); // Set to the first page (or another correct index)
    qDebug() << "Initial page index: " << ui->stackedWidget->currentIndex();

    // page evenements
    connect(ui->GestionEvenementsButton, &QPushButton::clicked, this, &MainWindow::on_GestionEvenementsButton_clicked);
    ui->stackedWidget->setCurrentIndex(0);
    qDebug() << "Initial page index: " << ui->stackedWidget->currentIndex();

    // page projets
    connect(ui->GestionProjetsButton, &QPushButton::clicked, this, &MainWindow::on_GestionProjetsButton_clicked);
    ui->stackedWidget->setCurrentIndex(0);
    qDebug() << "Initial page index: " << ui->stackedWidget->currentIndex();

    // page ressources
    connect(ui->GestionRessourcesButton, &QPushButton::clicked, this, &MainWindow::on_GestionRessourcesButton_clicked);
    ui->stackedWidget->setCurrentIndex(0);
    qDebug() << "Initial page index: " << ui->stackedWidget->currentIndex();

    // page stratégies
    connect(ui->GestionStrategiesButton, &QPushButton::clicked, this, &MainWindow::on_GestionStrategiesButton_clicked);
    ui->stackedWidget->setCurrentIndex(0);
    qDebug() << "Initial page index: " << ui->stackedWidget->currentIndex();

    // gestion employees
    connect(ui->GestionEmployeesButton, &QPushButton::clicked, this, &MainWindow::on_GestionEmployeesButton_clicked);
    ui->stackedWidget->setCurrentIndex(0);

}

MainWindow::~MainWindow() {
    delete ui;
}

// Function to switch to "Gestion Clients" page


void MainWindow::on_gestionClientsButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->PageGestionClients);
    if (ui->stackedWidget->indexOf(ui->PageGestionClients) != -1)
    {
        ui->stackedWidget->setCurrentWidget(ui->PageGestionClients);
        qDebug() << "Switched to Gestion Clients page.";
    }
}







void MainWindow::on_GestionEvenementsButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->PageGestionEvenements);
    if (ui->stackedWidget->indexOf(ui->PageGestionEvenements) != -1)
    {
        ui->stackedWidget->setCurrentWidget(ui->PageGestionEvenements);
        qDebug() << "Switched to Gestion Evenements page.";
    }
}


void MainWindow::on_GestionProjetsButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->PageGestionProjets);
    if (ui->stackedWidget->indexOf(ui->PageGestionProjets) != -1)
    {
        ui->stackedWidget->setCurrentWidget(ui->PageGestionProjets);
        qDebug() << "Switched to Gestion Projets page.";
    }
}


void MainWindow::on_GestionRessourcesButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->PageGestionRessources);
    if (ui->stackedWidget->indexOf(ui->PageGestionRessources) != -1)
    {
        ui->stackedWidget->setCurrentWidget(ui->PageGestionRessources);
        qDebug() << "Switched to Gestion Ressources page.";
    }
}


void MainWindow::on_GestionStrategiesButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->PageGestionStratgies);
    if (ui->stackedWidget->indexOf(ui->PageGestionStratgies) != -1)
    {
        ui->stackedWidget->setCurrentWidget(ui->PageGestionStratgies);
        qDebug() << "Switched to Gestion Strategies page.";
    }
}


void MainWindow::on_GestionEmployeesButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->PageGestionEmployees);
    if (ui->stackedWidget->indexOf(ui->PageGestionEmployees) != -1)
    {
        ui->stackedWidget->setCurrentWidget(ui->PageGestionEmployees);
        qDebug() << "Switched to Gestion Employees age.";
    }
}









void MainWindow::on_input_textChanged(const QString &arg1)
{
    bool isNumber;
    int id = arg1.toInt(&isNumber);

    if (!isNumber || id <= 0) {
        // If invalid input, clear the fields
        ui->nomC->clear();
        ui->prenomC->clear();
        ui->desc->clear();
        ui->budgetC->clear();
        ui->emailC->clear();
        ui->genreC->clear();
        ui->numC->clear();
        ui->dateN->setDate(QDate());  // Reset date field
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT * FROM CLIENTS WHERE IDCLIENT = :id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        // ✅ Populate fields with existing data
        ui->nomC->setText(query.value("NOMCLIENT").toString());
        ui->prenomC->setText(query.value("PRENOMCLIENT").toString());
        ui->desc->setText(query.value("DESCRIPTION").toString());
        ui->budgetC->setText(query.value("BUDGET").toString());
        ui->emailC->setText(query.value("EMAILCLIENT").toString());
        ui->genreC->setText(query.value("GENRE").toString());
        ui->numC->setText(query.value("NUMCLIENT").toString());

        // ✅ Convert QDate from SQL & set in QDateEdit
        QDate date = query.value("DATEN").toDate();
        ui->dateN->setDate(date);
    } else {
        qDebug() << "Aucun client trouvé pour l'ID :" << id;
    }
}



