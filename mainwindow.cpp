#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "employes.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QComboBox>
#include <QDebug>
#include <QSqlQueryModel>
#include <QSqlRecord>
#include <QSqlError>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Populate comboBox for genre selection
    ui->comboBox_genre->addItem("Homme");
    ui->comboBox_genre->addItem("Femme");
    ui->comboBox_genre->addItem("Autre");

    // Populate comboBox for etat
    ui->comboBox_etat->addItem("Actif");
    ui->comboBox_etat->addItem("Inactif");

    // Connect navigation buttons to their respective slots
    connect(ui->gestionClientsButton, &QPushButton::clicked, this, &MainWindow::on_gestionClientsButton_clicked);
    connect(ui->GestionEvenementsButton, &QPushButton::clicked, this, &MainWindow::on_GestionEvenementsButton_clicked);
    connect(ui->GestionProjetsButton, &QPushButton::clicked, this, &MainWindow::on_GestionProjetsButton_clicked);
    connect(ui->GestionRessourcesButton, &QPushButton::clicked, this, &MainWindow::on_GestionRessourcesButton_clicked);
    connect(ui->GestionStrategiesButton, &QPushButton::clicked, this, &MainWindow::on_GestionStrategiesButton_clicked);
    connect(ui->GestionEmployeesButton, &QPushButton::clicked, this, &MainWindow::on_GestionEmployeesButton_clicked);

    // Set initial page index
    ui->stackedWidget->setCurrentIndex(0);
    qDebug() << "Initial page index:" << ui->stackedWidget->currentIndex();

    // Connect search bar to live search function
    connect(ui->lineEdit_search, &QLineEdit::textChanged, this, &MainWindow::on_lineEdit_search_textChanged);
    connect(ui->comboBox_genre, &QComboBox::currentTextChanged, this, &MainWindow::on_comboBox_currentTextChanged);

    // Display employees on startup
    ui->tableView->setModel(employe.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_gestionClientsButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->PageGestionClients);
}

void MainWindow::on_GestionEvenementsButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->PageGestionEvenements);
}

void MainWindow::on_GestionProjetsButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->PageGestionProjets);
}

void MainWindow::on_GestionRessourcesButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->PageGestionRessources);
}

void MainWindow::on_GestionStrategiesButton_clicked()
{
    // Logic for Gestion Strategies
}

void MainWindow::on_GestionEmployeesButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->PageGestionEmployees);
    ui->tableView->setModel(employe.afficher());
}

void MainWindow::on_lineEdit_search_textChanged(const QString &text)
{
    QSqlQueryModel* model = employe.chercher(text);
    ui->tableView->setModel(model);
}

void MainWindow::on_comboBox_currentTextChanged(const QString &text)
{
    qDebug() << "Genre selected:" << text;
}

void MainWindow::on_supprimerButton_clicked()
{
    int idToDelete = ui->lineEdit_search->text().toInt();

    if (idToDelete <= 0) {
        QMessageBox::warning(this, "Avertissement", "Veuillez entrer un ID valide d'employé à supprimer.");
        return;
    }

    QMessageBox::StandardButton reply = QMessageBox::question(
        this, "Confirmation", "Êtes-vous sûr de vouloir supprimer l'employé avec l'ID " + QString::number(idToDelete) + " ?",
        QMessageBox::Yes | QMessageBox::No
        );

    if (reply == QMessageBox::No)
        return;

    if (employe.supprimer(idToDelete)) {
        QMessageBox::information(this, "Succès", "Employé supprimé avec succès.");
    } else {
        QMessageBox::critical(this, "Erreur", "Erreur lors de la suppression de l'employé.");
    }

    ui->tableView->setModel(employe.afficher());
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

    if (nom.isEmpty() || prenom.isEmpty() || mail.isEmpty() || password.isEmpty() || poste.isEmpty() || num.isEmpty()) {
        QMessageBox::warning(this, "Avertissement", "Veuillez remplir tous les champs !");
        return;
    }

    Employes newEmp(nom, prenom, mail, password, dateN, genre, poste, etat, num);
    if (newEmp.ajouter()) {
        QMessageBox::information(this, "Succès", "Employé ajouté avec succès.");
        ui->tableView->setModel(newEmp.afficher());
    } else {
        QMessageBox::critical(this, "Erreur", "Erreur lors de l'ajout de l'employé.");
    }

    ui->stackedWidget_2->setCurrentWidget(ui->page_2);
}

void MainWindow::on_ajout_clicked()
{
    ui->stackedWidget_2->setCurrentWidget(ui->page);
}

void MainWindow::on_pushButton_search_clicked()
{
    QString searchText = ui->lineEdit_recherche->text();

    if (searchText.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un nom à rechercher.");
        return;
    }

    Employes emp;
    QSqlQueryModel* model = emp.chercherParNom(searchText);

    if (model->rowCount() > 0) {
        ui->tableView->setModel(model);
    } else {
        QMessageBox::information(this, "Aucune correspondance", "Aucun employé trouvé avec ce nom.");
    }
}

void MainWindow::on_buttonModifier_clicked() {
    int id = ui->idLineEdit->text().toInt();

    if (id <= 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un ID valide !");
        return;
    }

    // Charger les données de l'employé dans les champs de modification
    employe.chargerEmploye(id);

    // Afficher les valeurs chargées dans les champs correspondants
    ui->lineEdit_nom->setText(employe.nom);
    ui->lineEdit_prenom->setText(employe.prenom);
    ui->lineEdit_mail->setText(employe.mail);
    ui->lineEdit_password->setText(employe.password);
    ui->dateEdit_dateN->setDate(QDate::fromString(employe.date, "yyyy-MM-dd"));
    ui->comboBox_genre->setCurrentText(employe.genre);
    ui->lineEdit_poste->setText(employe.poste);
    ui->comboBox_etat->setCurrentText(employe.etat);
    ui->lineEdit_num->setText(employe.num);

    // Informer l'utilisateur que les données ont été chargées
    QMessageBox::information(this, "Chargement", "Données de l'employé chargées avec succès !");
}

void MainWindow::on_sauvegarderButton_clicked() {
    int id = ui->idLineEdit->text().toInt();

    if (id <= 0) {
        QMessageBox::warning(this, "Error", "Please enter a valid ID!");
        return;
    }

    QString nom = ui->lineEdit_nom->text();
    QString prenom = ui->lineEdit_prenom->text();
    QString mail = ui->lineEdit_mail->text();
    QString password = ui->lineEdit_password->text();
    QString dateN = ui->dateEdit_dateN->date().toString("yyyy-MM-dd");
    QString genre = ui->comboBox_genre->currentText();
    QString poste = ui->lineEdit_poste->text();
    QString etat = ui->comboBox_etat->currentText();
    QString num = ui->lineEdit_num->text();

    if (nom.isEmpty() || prenom.isEmpty() || mail.isEmpty() || password.isEmpty() || poste.isEmpty() || num.isEmpty()) {
        QMessageBox::warning(this, "Error", "All fields are required!");
        return;
    }

    if (employe.modifier(id, nom, prenom, mail, password, dateN, genre, poste, etat, num)) {
        QMessageBox::information(this, "Success", "Employee updated successfully!");
        ui->tableView->setModel(employe.afficher());
    } else {
        QMessageBox::critical(this, "Error", "Failed to update employee. Please check the details.");
    }
}
