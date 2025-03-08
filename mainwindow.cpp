#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);

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
     qDebug() << "Initial page index: " << ui->stackedWidget->currentIndex();

     //parametres
     connect(ui->GestionParamtresButton, &QPushButton::clicked, this, &MainWindow::on_ParamtresButton_clicked);
     ui->stackedWidget->setCurrentIndex(0);
     qDebug() << "Initial page index: " << ui->stackedWidget->currentIndex();
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


void MainWindow::on_ParamtresButton_clicked()
{

}

