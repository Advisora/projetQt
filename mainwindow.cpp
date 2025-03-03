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

    // Connexion du signal currentTextChanged du QComboBox avec le slot
    connect(ui->comboBox_genre, &QComboBox::currentTextChanged, this, &MainWindow::on_comboBox_currentTextChanged);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_gestionClientsButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->PageGestionClients);
    qDebug() << "Switched to Gestion Clients page.";
}

void MainWindow::on_GestionEvenementsButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->PageGestionEvenements);
    qDebug() << "Switched to Gestion Evenements page.";
}

void MainWindow::on_GestionProjetsButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->PageGestionProjets);
    qDebug() << "Switched to Gestion Projets page.";
}

void MainWindow::on_GestionRessourcesButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->PageGestionRessources);
    qDebug() << "Switched to Gestion Ressources page.";
}

void MainWindow::on_GestionStrategiesButton_clicked()
{
    qDebug() << "Switched to Gestion Strategies page.";
}

void MainWindow::on_GestionEmployeesButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->PageGestionEmployees);
    qDebug() << "Switched to Gestion Employees page.";
}

void MainWindow::on_ajout_clicked()
{
    ui->stackedWidget_2->setCurrentWidget(ui->page);
    qDebug() << "Switched to 'page' in stackedWidget_2.";
}

void MainWindow::on_pushButton_ajouter_clicked()
{
    QString nom = ui->lineEdit_nom->text();
    QString prenom = ui->lineEdit_prenom->text();
    QString mail = ui->lineEdit_mail->text();
    QString password = ui->lineEdit_password->text();
    QString dateN = ui->dateEdit_dateN->date().toString("yyyy-MM-dd");
    QString genre = ui->comboBox_genre->currentText();
    QString poste = ui->lineEdit_poste->text();
    QString etat = ui->comboBox_etat->currentText();
    QString num = ui->lineEdit_num->text();

    Employes e(nom, prenom, mail, password, dateN, genre, poste, etat, num);
    if (e.ajouter())
    {
        QMessageBox::information(this, "Ajout", "Employé ajouté avec succès");
    }
    else
    {
        QMessageBox::warning(this, "Erreur", "Erreur lors de l'ajout de l'employé");
    }
}

// Slot pour le signal currentTextChanged du QComboBox
void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{
    qDebug() << "ComboBox value changed: " << arg1;
}
