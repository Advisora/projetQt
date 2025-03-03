#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QDebug>
#include <QMessageBox>
#include "mainwindow.h"
#include "ui_mainwindow.h"
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

void MainWindow::loadData() {
    static QSqlQueryModel *model = new QSqlQueryModel(this);
    QSqlQuery query("SELECT IDCLIENT, NOMCLIENT, , DATEN, DESCRIPTION, BUDGET, EMAILCLIENT,GENRE,NUMCLIENT FROM CLIENTS");
    model->setQuery(query);

}


void MainWindow::on_loadClientById_clicked() {
    qDebug() << "Button clicked! Loading all clients...";

    // Ensure database is open
    if (!QSqlDatabase::database().isOpen()) {
        qDebug() << "Error: Database is not open!";
        return;
    }

    // Create a new model
    QSqlQueryModel *model = new QSqlQueryModel();

    // Execute SQL query to get all clients
    QSqlQuery query;
    query.prepare("SELECT IDCLIENT, NOMCLIENT, PRENOMCLIENT, DATEN, DESCRIPTION, BUDGET, EMAILCLIENT, GENRE, NUMCLIENT FROM CLIENTS");

    if (!query.exec()) {
        qDebug() << "SQL Error: " << query.lastError().text();
        delete model;
        return;
    }

    // Set query result in model
    model->setQuery(query);

    // Check if any data was returned
    if (model->rowCount() == 0) {
        qDebug() << "No clients found in database!";
        delete model;
        return;
    }

    qDebug() << "Clients loaded: " << model->rowCount();

    // Set column headers
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Vertical, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date de Naissance"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Description"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Budget"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Email"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Genre"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("NumClient"));
    ui->tableView->horizontalHeader()->setVisible(true);

    // Set model in table
    ui->tableView->setModel(model);
    ui->tableView->setSelectionMode(QAbstractItemView::NoSelection);
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableView->setFocusPolicy(Qt::NoFocus); // Prevent keyboard focus
    // Adjust table display
    ui->tableView->resizeColumnsToContents();
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    // Make text inside cells aligned and readable
    ui->tableView->setStyleSheet(
        "QTableView {"
        "    background-color: rgb(245, 245, 220);" /* Beige */
        "    gridline-color: #d0d0d0;" /* Light gray grid lines */
        "    font-size: 12px;" /* Larger font */
        "    color: #000;" /* Black text */
        "    border: 1px solid rgb(209, 199, 161);" /* Slightly darker border */
        "    border-radius: 5px;" /* Rounded corners */
        "    padding: 1px;" /* Internal padding */
        "}"


        "QHeaderView::section {"
        "    background-color: rgb(209, 199, 161);" /* Beige headers */
        "    font-weight: bold;"
        "    padding: 8px;"
        "    border: 1px solid #a0a0a0;" /* Light gray borders */
        "    text-align: center;"
        "}"



        "QHeaderView::section {"
        "    background-color: rgb(209, 199, 161);" /* Beige headers */
        "    padding: 6px;"
        "    font-weight: bold;"
        "    border: 1px solid #a0a0a0;" /* Light gray borders */
        "}"


        );


    // Make columns adjust to content
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // Make rows adjust dynamically
    ui->tableView->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
    ui->tableView->verticalHeader()->setVisible(false);

    // Make headers clickable for sorting
    ui->tableView->setSortingEnabled(true);

    // Resize columns automatically to fit content
    ui->tableView->resizeColumnsToContents();
    ui->tableView->horizontalHeader()->setStretchLastSection(true);

    // Enable word wrapping so text doesn't get cut off
    ui->tableView->setWordWrap(true);
    ui->tableView->setTextElideMode(Qt::ElideNone); // Don't cut off text

    // Adjust row height for better visibility
    ui->tableView->verticalHeader()->setDefaultSectionSize(40); // Increase row height

}



void MainWindow::on_ajouterC_clicked() {
    QString nom = ui->nomC->text();
    QString prenom = ui->prenomC->text();
    QString description = ui->desc->text().trimmed();
    float budget = ui->budgetC->text().toFloat();
    QString email = ui->emailC->text();
    QString genre = ui->genreC->text();
    QString num = ui->numC->text();

    if (nom.isEmpty() || prenom.isEmpty() || description.isEmpty() || budget <= 0 || email.isEmpty() || genre.isEmpty() || num.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Tous les champs doivent être remplis.");
        return;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO CLIENTS(NOMCLIENT, PRENOMCLIENT, DATEN, DESCRIPTION, BUDGET, EMAILCLIENT, GENRE, NUMCLIENT) "
                  "VALUES (:nom, :prenom, CURRENT_DATE, :description, :budget, :email, :genre, :num)");

    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":description", description);
    query.bindValue(":budget", budget);
    query.bindValue(":email", email);
    query.bindValue(":genre", genre);
    query.bindValue(":num", num);

    if (query.exec()) {
        qDebug() << "Ajout réussi !";
        loadData();
    } else {
        qDebug() << "Erreur d'ajout: " << query.lastError().text() << " | Requête: " << query.lastQuery();
    }
}


