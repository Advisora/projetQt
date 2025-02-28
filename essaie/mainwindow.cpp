#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QSqlError>
#include <QProgressBar>
#include <QPropertyAnimation>
#include <QTimer>
#include "dialog.h"
#include <QListWidgetItem>
#include <QCalendarWidget>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->delete_projet, &QPushButton::clicked, this, &MainWindow::on_delete_projet_clicked);
    connect(ui->edit_projet, &QPushButton::clicked, this, &MainWindow::on_edit_projet_clicked);

    // Connexion à la base de données au démarrage
    if (cnx.createconnect()) {
        qDebug() << "Connexion réussie à Oracle!";
    } else {
        QMessageBox::critical(this, "Erreur", "Connexion à Oracle échouée!");
    }


}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ajouter_clicked()
{
    // Récupérer les valeurs du formulaire
    int id = ui->lineEdit_id->text().toInt();  // Assurez-vous que ce champ existe
    QString titre = ui->lineEdit_titre->text();
    QString description = ui->textEdit_description->text();  // Utilisation de QLineEdit
    double budget = ui->lineEdit_budget->text().toDouble();
    QDate dateL = ui->dateEdit_dateL->date();  // Supposons que tu utilises un QDateEdit
    QString avancement = ui->lineEdit_avancement->text();  // Le type a changé en QString

    // Vérifier que les champs obligatoires ne sont pas vides
    if (titre.isEmpty() || description.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Les champs Titre et Description ne peuvent pas être vides.");
        return;
    }

    // Préparer la requête SQL
    QSqlQuery query;
    query.prepare("INSERT INTO PROJETS (ID_PROJET, TITREPROJET, DESCRIPTIONP, BUDGETPROJET, DATELP, AVANCEMENTP) "
                  "VALUES (:ID_PROJET, :TITREPROJET, :DESCRIPTIONP, :BUDGETPROJET, TO_DATE(:DATELP, 'YYYY-MM-DD'), :AVANCEMENTP)");

    query.bindValue(":ID_PROJET", id);
    query.bindValue(":TITREPROJET", titre);  // Correspond au champ "TITREPROJET"
    query.bindValue(":DESCRIPTIONP", description);  // Correspond au champ "DESCRIPTIONP"
    query.bindValue(":BUDGETPROJET", budget);  // Correspond au champ "BUDGETPROJET"
    query.bindValue(":DATELP", dateL.toString("yyyy-MM-dd"));  // Format SQL pour les dates
    query.bindValue(":AVANCEMENTP", avancement);  // Correspond au champ "AVANCEMENTP"

    // Exécuter la requête et afficher le message correspondant
    if (query.exec()) {
        QMessageBox::information(this, "Succès", "Projet ajouté avec succès !");
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de l'insertion: " + query.lastError().text());
    }
}



#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"

void MainWindow::on_btnAfficherProjets_clicked()
{
    Dialog dialog;
    dialog.exec();  // Ouvre la boîte de dialogue et affiche les projets
}


void MainWindow::on_delete_projet_clicked()
{
    QString titre = ui->barrederecherche_id->text();

    if (titre.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un titre valide !");
        return;
    }

    // Confirmation avant suppression
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmation", "Voulez-vous vraiment supprimer ce projet ?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::No) {
        return; // Annulation de la suppression
    }

    QSqlQuery query;
    query.prepare("DELETE FROM PROJETS WHERE TITREPROJET = :titre");
    query.bindValue(":titre", titre);

    if (query.exec()) {
        if (query.numRowsAffected() > 0) {  // Vérifier si un projet a été supprimé
            QMessageBox::information(this, "Succès", "Le projet a été supprimé !");
        } else {
            QMessageBox::warning(this, "Aucun projet trouvé", "Aucun projet avec ce titre !");
        }
    } else {
        QMessageBox::critical(this, "Erreur", "Erreur lors de la suppression : " + query.lastError().text());
    }
}




void MainWindow::on_edit_projet_clicked()
{
    // Récupérer le titre du projet dans la barre de recherche
    QString titreRecherche = ui->barrederecherche_id->text();

    if (titreRecherche.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Veuillez entrer un titre valide !");
        return;
    }

    // Vérifier si les champs sont vides (d'abord charger les données)
    if (ui->lineEdit_titre->text().isEmpty()) {
        // 📌 1️⃣ Charger les données du projet dans les champs
        QSqlQuery query;
        query.prepare("SELECT ID_PROJET, TITREPROJET, DESCRIPTIONP, BUDGETPROJET, DATELP, AVANCEMENTP FROM PROJETS WHERE TITREPROJET = :titre");
        query.bindValue(":titre", titreRecherche);

        if (query.exec() && query.next()) {
            // Remplir les champs avec les données existantes
            ui->lineEdit_id->setText(query.value(0).toString());
            ui->lineEdit_titre->setText(query.value(1).toString());
            ui->textEdit_description->setText(query.value(2).toString());
            ui->lineEdit_budget->setText(query.value(3).toString());
            ui->dateEdit_dateL->setDate(query.value(4).toDate());
            ui->lineEdit_avancement->setText(query.value(5).toString());

            QMessageBox::information(this, "Info", "Modifiez les informations puis cliquez sur 'Edit' pour enregistrer.");
        } else {
            QMessageBox::warning(this, "Erreur", "Aucun projet trouvé avec ce titre.");
        }
    } else {
        // 📌 2️⃣ Comparer les valeurs dans les champs avec celles de la base de données
        QString titre = ui->lineEdit_titre->text();
        QString description = ui->textEdit_description->text();
        double budget = ui->lineEdit_budget->text().toDouble();
        QDate dateL = ui->dateEdit_dateL->date();
        QString avancement = ui->lineEdit_avancement->text();  // Avancement est maintenant un texte
        int id = ui->lineEdit_id->text().toInt();  // Récupérer l'ID du projet

        // Requête pour récupérer les anciennes valeurs depuis la base de données
        QSqlQuery query;
        query.prepare("SELECT TITREPROJET, DESCRIPTIONP, BUDGETPROJET, DATELP, AVANCEMENTP FROM PROJETS WHERE ID_PROJET = :id");
        query.bindValue(":id", id);

        if (query.exec() && query.next()) {
            bool modification = false;

            // Comparer les valeurs actuelles avec celles de la base de données
            if (titre != query.value(0).toString()) modification = true;
            if (description != query.value(1).toString()) modification = true;
            if (budget != query.value(2).toDouble()) modification = true;
            if (dateL != query.value(3).toDate()) modification = true;
            if (avancement != query.value(4).toString()) modification = true;

            // Si une modification a été faite
            if (modification) {
                // Préparer la requête UPDATE pour enregistrer les modifications
                query.prepare("UPDATE PROJETS SET TITREPROJET = :TITRE, DESCRIPTIONP = :DESCRIPTION, BUDGETPROJET = :BUDGET, "
                              "DATELP = TO_DATE(:DATEL, 'YYYY-MM-DD'), AVANCEMENTP = :AVANCEMENT WHERE ID_PROJET = :ID_PROJET");
                query.bindValue(":ID_PROJET", id);
                query.bindValue(":TITRE", titre);
                query.bindValue(":DESCRIPTION", description);
                query.bindValue(":BUDGET", budget);
                query.bindValue(":DATEL", dateL.toString("yyyy-MM-dd"));
                query.bindValue(":AVANCEMENT", avancement);

                if (query.exec()) {
                    QMessageBox::information(this, "Succès", "Le projet a été mis à jour !");
                    // Réinitialiser les champs après la mise à jour
                    ui->lineEdit_id->clear();
                    ui->lineEdit_titre->clear();
                    ui->textEdit_description->clear();
                    ui->lineEdit_budget->clear();
                    ui->dateEdit_dateL->clear();
                    ui->lineEdit_avancement->clear();
                    ui->barrederecherche_id->clear();
                } else {
                    QMessageBox::critical(this, "Erreur", "Erreur lors de la mise à jour : " + query.lastError().text());
                }
            } else {
                QMessageBox::information(this, "Pas de modification", "Aucune modification détectée.");
            }
        }
    }
}



#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QTableWidget>
#include <QHeaderView>
#include <QLabel>
#include <QProgressBar>
#include <QPropertyAnimation>

void MainWindow::on_listTodoButton_clicked()
{
    // 🏷️ Fenêtre Kanban
    QDialog *kanbanDialog = new QDialog(this);
    kanbanDialog->setWindowTitle("📌 Organisation des tâches");
    kanbanDialog->resize(800, 600);
    kanbanDialog->setStyleSheet("background-color: #F5F5DC; border-radius: 10px;");

    // 📌 Layout principal
    QVBoxLayout *mainLayout = new QVBoxLayout(kanbanDialog);

    // ✅ Titre stylisé
    QLabel *titleLabel = new QLabel("📌Gestion des tâches");
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setStyleSheet("font-size: 24px; font-weight: bold; color: #7E9C5A;");
    mainLayout->addWidget(titleLabel);

    // ✅ Zone d'ajout de tâche
    QHBoxLayout *inputLayout = new QHBoxLayout();
    QLineEdit *taskInput = new QLineEdit(kanbanDialog);
    taskInput->setPlaceholderText("Ajouter une tâche...");
    taskInput->setStyleSheet("padding: 12px; border: 2px solid #7E9C5A; border-radius: 8px; background: white;");

    QPushButton *addButton = new QPushButton("➕ Ajouter", kanbanDialog);
    addButton->setStyleSheet(
        "QPushButton { background-color: #7E9C5A; color: white; font-size: 14px; border-radius: 8px; padding: 10px; }"
        "QPushButton:hover { background-color: #5A7E3A; }"
        );

    inputLayout->addWidget(taskInput);
    inputLayout->addWidget(addButton);
    mainLayout->addLayout(inputLayout);

    // ✅ Tableau Kanban
    QTableWidget *kanbanTable = new QTableWidget(kanbanDialog);
    kanbanTable->setColumnCount(3);
    kanbanTable->setRowCount(8);
    kanbanTable->setHorizontalHeaderLabels({"⏳ To Do", "🚀 Doing", "✅ Done"});
    kanbanTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    kanbanTable->verticalHeader()->setVisible(false);

    kanbanTable->setStyleSheet(
        "QTableWidget { background-color: white; border-radius: 8px; border: 2px solid #7E9C5A; }"
        "QHeaderView::section { background-color: #7E9C5A; color: white; font-size: 14px; padding: 8px; }"
        );

    kanbanTable->setDragDropMode(QAbstractItemView::InternalMove);
    kanbanTable->setAcceptDrops(true);
    kanbanTable->setDragEnabled(true);
    kanbanTable->setDropIndicatorShown(true);

    mainLayout->addWidget(kanbanTable);

    // ✅ Barre de progression avec **ANIMATION**
    QLabel *progressLabel = new QLabel("Avancement des tâches", kanbanDialog);
    progressLabel->setAlignment(Qt::AlignCenter);
    progressLabel->setStyleSheet("font-size: 16px; font-weight: bold; color: #7E9C5A;");
    mainLayout->addWidget(progressLabel);

    QProgressBar *progressBar = new QProgressBar(kanbanDialog);
    progressBar->setRange(0, 100);
    progressBar->setValue(0);
    progressBar->setTextVisible(true);
    progressBar->setFormat("%p% ✅");
    progressBar->setStyleSheet(
        "QProgressBar { border: 2px solid #7E9C5A; border-radius: 10px; background: white; height: 30px; font-size: 16px; font-weight: bold; text-align: center; }"
        "QProgressBar::chunk { background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #5A7E3A, stop:1 #A1D490); border-radius: 10px; }"
        );

    mainLayout->addWidget(progressBar);

    // 🔄 Fonction d'animation pour mettre à jour la barre de progression
    auto updateProgress = [=]() {
        int totalTasks = 0;
        int completedTasks = 0;

        for (int row = 0; row < kanbanTable->rowCount(); ++row) {
            for (int col = 0; col < 3; ++col) {
                if (kanbanTable->item(row, col)) {
                    totalTasks++;
                    if (col == 2) {  // Si la tâche est dans "Done"
                        completedTasks++;
                    }
                }
            }
        }

        int progress = (totalTasks > 0) ? (completedTasks * 100 / totalTasks) : 0;

        // 🔄 Animation fluide de la barre de progression
        QPropertyAnimation *animation = new QPropertyAnimation(progressBar, "value");
        animation->setDuration(500);  // Durée de 0.5s
        animation->setStartValue(progressBar->value());
        animation->setEndValue(progress);
        animation->setEasingCurve(QEasingCurve::InOutQuad);
        animation->start();
    };

    // ✅ Ajout dynamique d'une tâche
    connect(addButton, &QPushButton::clicked, [=]() {
        QString taskText = taskInput->text().trimmed();
        if (!taskText.isEmpty()) {
            for (int row = 0; row < kanbanTable->rowCount(); ++row) {
                if (!kanbanTable->item(row, 0)) {
                    QTableWidgetItem *newTask = new QTableWidgetItem(taskText);
                    newTask->setBackground(QColor("#D2B48C"));  // Couleur "To Do"
                    newTask->setTextAlignment(Qt::AlignCenter);
                    kanbanTable->setItem(row, 0, newTask);
                    taskInput->clear();
                    updateProgress();  // Mise à jour avec animation
                    break;
                }
            }
        }0;
    });

    // ✅ Ajout via Entrée
    connect(taskInput, &QLineEdit::returnPressed, addButton, &QPushButton::click);

    // 🔄 Mise à jour animée quand une tâche change de colonne
    connect(kanbanTable, &QTableWidget::itemChanged, updateProgress);

    // ✅ Affichage de la fenêtre
    kanbanDialog->exec();
}
