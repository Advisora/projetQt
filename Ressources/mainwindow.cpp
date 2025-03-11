
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ressources.h"
#include "connection.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QRegularExpression>
#include <QRegularExpressionValidator>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), model(new QSqlQueryModel(this)), selectedId(0)
{
    ui->setupUi(this);
    Connection conn;

    if (conn.createconnect()) {
        loadResources();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la connexion à la base de données !");
    }

    // Connect buttons to resource management functions
    connect(ui->pushButton_11, &QPushButton::clicked, this, &MainWindow::on_pushButton_11_clicked);
    connect(ui->pushButton_18, &QPushButton::clicked, this, &MainWindow::on_pushButton_18_clicked);
    connect(ui->deletebutt, &QPushButton::clicked, this, &MainWindow::on_deletebutt_clicked);
    connect(ui->searchbutt, &QPushButton::clicked, this, &MainWindow::on_searchbutt_clicked);

    // Connect table view selection for resources
    connect(ui->tableView, &QTableView::clicked, this, &MainWindow::onResourcesTableViewClicked);

}

MainWindow::~MainWindow()
{
    delete ui;
}

// Load resources into the table
// Load resources into the table
void MainWindow::loadResources()
{
    if (!QSqlDatabase::database().isOpen()) {
        QMessageBox::critical(this, "Erreur", "La connexion à la base de données est fermée !");
        return;
    }

    QSqlQuery query;
    query.prepare("SELECT * FROM RESSOURCES");

    if (query.exec()) {
        model->setQuery(std::move(query));  // Use std::move to avoid copying
        ui->tableView->setModel(model);
        ui->tableView->resizeColumnsToContents();
    } else {
        QMessageBox::critical(this, "Erreur", "Impossible de charger les données : " + query.lastError().text());
    }
}

// Add a new resource


// Modify a selected resource


// Delete a selected resource


// Search for a resource by ID


// Handle resource selection in the table
void MainWindow::onResourcesTableViewClicked(const QModelIndex &index) {
    if (!index.isValid()) return;

    int row = index.row();

    // Retrieve selected ID (from the first column)
    QModelIndex idIndex = model->index(row, 0);
    selectedId = model->data(idIndex).toInt();

    // Set selected resource details in the UI
    ui->nomResourceInput->setText(model->data(model->index(row, 1)).toString());
    ui->typeResourceInput->setText(model->data(model->index(row, 2)).toString());
    ui->categorieResourceInput->setText(model->data(model->index(row, 3)).toString());
    ui->quantiteResourceInput->setText(model->data(model->index(row, 4)).toString());
    ui->dernierDetectionInput->setText(model->data(model->index(row, 5)).toString());
    ui->nomCandidatInput->setText(model->data(model->index(row, 6)).toString());
    ui->telephoneResourceInput->setText(model->data(model->index(row, 7)).toString());
    ui->emailResourceInput->setText(model->data(model->index(row, 8)).toString());
    ui->experienceResourceInput->setText(model->data(model->index(row, 9)).toString());
}

    void MainWindow::on_pushButton_11_clicked()
    {
        QString nom = ui->nomResourceInput->text();
        QString type = ui->typeResourceInput->text();
        QString categorie = ui->categorieResourceInput->text();
        int quantite = ui->quantiteResourceInput->text().toInt();
        QString dernierDetection = ui->dernierDetectionInput->text();
        QString nomCandidat = ui->nomCandidatInput->text();
        QString telephone = ui->telephoneResourceInput->text();
        QString email = ui->emailResourceInput->text();
        QString experience = ui->experienceResourceInput->text();

        // Check for empty fields
        if (nom.isEmpty() || type.isEmpty() || categorie.isEmpty() || quantite <= 0 || telephone.isEmpty() || email.isEmpty()) {
            QMessageBox::warning(this, "Erreur", "Veuillez remplir tous les champs !");
            return;
        }

        // Check for valid email format

        // Inside your MainWindow constructor, modify like this:

        // Control for email input (validates email format)
        QRegularExpression emailRegExp("[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}");
        QRegularExpressionValidator *emailValidator = new QRegularExpressionValidator(emailRegExp, this);
        ui->emailResourceInput->setValidator(emailValidator);

        // Control for phone input (simple validation for phone numbers)
        QRegularExpression phoneRegExp("^[0-9]{10}$"); // Only 10 digits (can be adapted to other formats)
        QRegularExpressionValidator *phoneValidator = new QRegularExpressionValidator(phoneRegExp, this);
        ui->telephoneResourceInput->setValidator(phoneValidator);


        // Add resource if validation passed
        Ressources resource(0, nom, type, categorie, quantite, dernierDetection, nomCandidat, telephone, email, experience);
        if (resource.ajouter()) {
            QMessageBox::information(this, "Succès", "Ressource ajoutée avec succès !");
            loadResources();
        } else {
            QMessageBox::critical(this, "Erreur", "Impossible d'ajouter la ressource.");
        }
    }




void MainWindow::on_pushButton_18_clicked()
{
    if (selectedId == 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner une ressource à modifier !");
        return;
    }

    QString nom = ui->nomResourceInput->text();
    QString type = ui->typeResourceInput->text();
    QString categorie = ui->categorieResourceInput->text();
    int quantite = ui->quantiteResourceInput->text().toInt();
    QString dernierDetection = ui->dernierDetectionInput->text();
    QString nomCandidat = ui->nomCandidatInput->text();
    QString telephone = ui->telephoneResourceInput->text();
    QString email = ui->emailResourceInput->text();
    QString experience = ui->experienceResourceInput->text();

    Ressources resource(selectedId, nom, type, categorie, quantite, dernierDetection, nomCandidat, telephone, email, experience);

    if (resource.modifier(selectedId, nom, type, categorie, quantite, dernierDetection, nomCandidat, telephone, email, experience)) {
        QMessageBox::information(this, "Succès", "Ressource modifiée avec succès !");
        loadResources();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la mise à jour de la ressource.");
    }
}


void MainWindow::on_deletebutt_clicked()
{
    if (selectedId == 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner une ressource à supprimer !");
        return;
    }

    Ressources resource;
    if (resource.supprimer(selectedId)) {
        QMessageBox::information(this, "Succès", "Ressource supprimée avec succès !");
        loadResources();
        selectedId = 0;  // Reset the selection
    } else {
        QMessageBox::critical(this, "Erreur", "Impossible de supprimer la ressource.");
    }
}


void MainWindow::on_searchbutt_clicked()
{
    QString searchText = ui->searchResourceInput->text().trimmed();

    if (searchText.isEmpty()) {
        loadResources();
        return;
    }

    int id = searchText.toInt();
    if (id == 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un ID valide !");
        return;
    }

    Ressources resource;
    QSqlQueryModel* model = resource.rechercher(id);

    if (model && model->rowCount() > 0) {
        ui->tableView->setModel(model);
        ui->tableView->resizeColumnsToContents();
    } else {
        QMessageBox::information(this, "Résultat", "Aucune ressource trouvée avec cet ID.");
    }
}

