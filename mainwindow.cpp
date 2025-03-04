#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connexion.h"
#include <QMessageBox>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QSqlError>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Initialize database connection
    Connection conn;
    if (conn.createconnect()) {
        QMessageBox::information(this, "Connexion", "Connexion à la base de données réussie !");
        loadDatabase();  // Load data when UI opens
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la connexion à la base de données !");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadDatabase() {
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("SELECT * FROM RESSOURCES");
    if (query.exec()) {
        model->setQuery(query);
        ui->tableView->setModel(model);  // Assuming `tableView` is your QTableView
    } else {
        QMessageBox::critical(this, "Erreur", "Impossible de récupérer les données : " + query.lastError().text());
    }
}

void MainWindow::on_statProjet_clicked()
{
    QString nom_ressource = ui->nom_input->text();
    QString type_ressource = ui->ressource->text();
    QString categorie = ui->categ->text();
    int quantite = ui->quantite->text().toInt();
    QString dernier_detection = ui->detection->text();
    QString nom_condidat = ui->condidat->text();
    QString telephone = ui->teleph->text();
    QString email = ui->emqil->text();
    QString experience = ui->experience->text();

    // Prepare the SQL query
    QSqlQuery query;
    query.prepare("INSERT INTO RESSOURCES (NOM_RESSOURCE, TYPE_RESSOURCE, CATEGORIE, QUANTITE, DERNIER_DETECTION, NOML_CONDIDAT, TELEPHONE, EMAIL, EXPERIENCE) "
                  "VALUES (:nom_ressource, :type_ressource, :categorie, :quantite, :dernier_detection, :nom_condidat, :telephone, :email, :experience)");

    // Bind values
    query.bindValue(":nom_ressource", nom_ressource);
    query.bindValue(":type_ressource", type_ressource);
    query.bindValue(":categorie", categorie);
    query.bindValue(":quantite", quantite);
    query.bindValue(":dernier_detection", dernier_detection);
    query.bindValue(":nom_condidat", nom_condidat);
    query.bindValue(":telephone", telephone);
    query.bindValue(":email", email);
    query.bindValue(":experience", experience);

    // Execute the query
    if (query.exec()) {
        QMessageBox::information(this, "Succès", "Les données ont été insérées avec succès !");
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'insertion : " + query.lastError().text());
    }

}

