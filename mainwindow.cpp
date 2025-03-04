#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employes.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
    ui->comboBox_genre->addItem("Homme");
    ui->comboBox_genre->addItem("Femme");
    ui->comboBox_genre->addItem("Autre");

    connect(ui->gestionClientsButton, &QPushButton::clicked, this, &MainWindow::on_gestionClientsButton_clicked);
    connect(ui->GestionEvenementsButton, &QPushButton::clicked, this, &MainWindow::on_GestionEvenementsButton_clicked);
    connect(ui->GestionProjetsButton, &QPushButton::clicked, this, &MainWindow::on_GestionProjetsButton_clicked);
    connect(ui->GestionRessourcesButton, &QPushButton::clicked, this, &MainWindow::on_GestionRessourcesButton_clicked);
    connect(ui->GestionStrategiesButton, &QPushButton::clicked, this, &MainWindow::on_GestionStrategiesButton_clicked);
    connect(ui->GestionEmployeesButton, &QPushButton::clicked, this, &MainWindow::on_GestionEmployeesButton_clicked);
    ui->stackedWidget->setCurrentIndex(0);
    qDebug() << "Initial page index: " << ui->stackedWidget->currentIndex();

    connect(ui->lineEdit_search, &QLineEdit::textChanged, this, &MainWindow::on_lineEdit_search_textChanged); // Connect search bar

    connect(ui->comboBox_genre, &QComboBox::currentTextChanged, this, &MainWindow::on_comboBox_currentTextChanged);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_gestionClientsButton_clicked() {
    ui->stackedWidget->setCurrentWidget(ui->PageGestionClients);
    qDebug() << "Switched to Gestion Clients page.";
}

void MainWindow::on_GestionEvenementsButton_clicked() {
    ui->stackedWidget->setCurrentWidget(ui->PageGestionEvenements);
    qDebug() << "Switched to Gestion Evenements page.";
}

void MainWindow::on_GestionProjetsButton_clicked() {
    ui->stackedWidget->setCurrentWidget(ui->PageGestionProjets);
    qDebug() << "Switched to Gestion Projets page.";
}

void MainWindow::on_GestionRessourcesButton_clicked() {
    ui->stackedWidget->setCurrentWidget(ui->PageGestionRessources);
    qDebug() << "Switched to Gestion Ressources page.";
}

void MainWindow::on_GestionStrategiesButton_clicked() {
    qDebug() << "Switched to Gestion Strategies page.";
}

void MainWindow::on_GestionEmployeesButton_clicked() {
    ui->stackedWidget->setCurrentWidget(ui->PageGestionEmployees);
    qDebug() << "Switched to Gestion Employees page.";
    Employes emp;
    ui->tableView->setModel(emp.afficher()); // Affiche les employés dans le tableau
}

void MainWindow::on_lineEdit_search_textChanged(const QString &text) {
    QSqlQueryModel* model = employe.chercher(text);  // Search employees by name
    ui->tableView->setModel(model);  // Display search results in the table
}

void MainWindow::on_supprimerButton_clicked() {
    QModelIndexList selectedRows = ui->tableView->selectionModel()->selectedRows();

    if (selectedRows.isEmpty()) {
        QMessageBox::warning(this, "Avertissement", "Veuillez sélectionner un employé à supprimer.");
        return;
    }

    // Get the employee number (ID) from the selected row (assuming it's in the 7th column)
    QString numToDelete = ui->tableView->model()->data(selectedRows.first().sibling(selectedRows.first().row(), 7)).toString();

    if (employe.supprimer(numToDelete)) {
        QMessageBox::information(this, "Succès", "Employé supprimé avec succès.");
        on_lineEdit_search_textChanged(ui->lineEdit_search->text());  // Refresh the list after deletion
    } else {
        QMessageBox::critical(this, "Erreur", "Erreur lors de la suppression de l'employé.");
    }
}

void MainWindow::on_pushButton_ajouter_clicked() {
    // Implement the addition logic here
}
