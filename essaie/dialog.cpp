#include "dialog.h"
#include "ui_dialog.h"
#include <QListWidgetItem>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QMessageBox>
#include <QProgressBar>
#include <QIcon>
#include <QVBoxLayout>
#include <QLabel>
#include <QDialog>
#include <QPushButton>
#include <QTextEdit>
#include <QFormLayout>
#include <QDateTimeEdit>
#include <QListWidget>
#include <QGridLayout>
#include <QSqlError>
#include <QDebug>
#include <QEvent>
#include <QMouseEvent>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>
#include <QListWidgetItem>
#include <QCursor>
#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog),
    m_searchMenu(new QMenu(this)),
    m_searchMode("titre")  // Mode par défaut
{
    ui->setupUi(this);
    ui->searchLineEdit->installEventFilter(this);

    m_searchMenu->addAction("Recherche par titre", this, SLOT(setSearchOptionTitle()));
    m_searchMenu->addAction("Recherche par id", this, SLOT(setSearchOptionId()));
    m_searchMenu->addAction("Recherche par description", this, SLOT(setSearchOptionDescription()));

    // Optionnel : changer le placeholder pour indiquer le mode par défaut
    ui->searchLineEdit->setPlaceholderText("Recherche par titre");

    // Connecter le signal pour lancer la recherche quand l'utilisateur valide (ex: appui sur Entrée)
    connect(ui->searchLineEdit, &QLineEdit::textChanged,
            this, &Dialog::on_searchLineEdit_textChanged);

    chargerProjets();  // Charger automatiquement les projets quand la boîte de dialogue s'affiche
     connect(ui->listWidget, &QListWidget::itemClicked, this, &Dialog::afficherDetailsProjet);

    connect(ui->telechargerPDF, &QPushButton::clicked, this, &::Dialog::on_telechargerPDF_clicked);



    ui->listWidget->setStyleSheet(
        "QListWidget {"
        "   background-color: #f8f9fa;"
        "   border: none;"
        "   border-radius: 10px;"
        "   padding: 5px;"
        "   overflow-y: auto;"
        "}"
        "QListWidget::item {"
        "   background: #ffffff;"
        "   border: 1px solid #dddddd;"
        "   border-radius: 10px;"
        "   padding: 10px;"
        "   margin: 5px;"
        "   transition: all 0.3s ease;"
        "}"
        "QListWidget::item:selected {"
        "   background: #3498db;"
        "   color: white;"
        "   font-weight: bold;"
        "   border: 1px solid #2980b9;"
        "}"
        "QListWidget::item:hover {"
        "   background: #ecf0f1;"
        "   box-shadow: 0 4px 8px rgba(0, 0, 0, 0.1);"
        "}"
        "QLabel {"
        "   font-size: 14px;"
        "   color: #34495e;"
        "   font-family: 'Arial', sans-serif;"
        "   padding: 5px;"
        "}"
        "QProgressBar {"
        "   height: 10px;"
        "   background-color: #ecf0f1;"
        "   border-radius: 5px;"
        "}"
        "QProgressBar::chunk {"
        "   background-color: #2ecc71;"
        "   border-radius: 5px;"
        "}"
        );


}

Dialog::~Dialog()
{
    delete ui;
}



// Event Filter pour détecter le clic sur la searchLineEdit
bool Dialog::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == ui->searchLineEdit && event->type() == QEvent::MouseButtonPress) {
        // Afficher le menu de sélection du mode à la position du curseur
        m_searchMenu->exec(QCursor::pos());
    }
    return QDialog::eventFilter(obj, event);
}

// Slots pour définir l'option de recherche
void Dialog::setSearchOptionTitle()
{
    m_searchMode = "titre";
    ui->searchLineEdit->setPlaceholderText("Recherche par titre");
    // Relancer la recherche avec le texte déjà saisi
    on_searchLineEdit_textChanged(ui->searchLineEdit->text());
}

void Dialog::setSearchOptionId()
{
    m_searchMode = "id";
    ui->searchLineEdit->setPlaceholderText("Recherche par id");
    on_searchLineEdit_textChanged(ui->searchLineEdit->text());
}

void Dialog::setSearchOptionDescription()
{
    m_searchMode = "description";
    ui->searchLineEdit->setPlaceholderText("Recherche par description");
    on_searchLineEdit_textChanged(ui->searchLineEdit->text());
}

// Slot exécuté à chaque modification du texte dans la barre de recherche
void Dialog::on_searchLineEdit_textChanged(const QString &searchText)
{
    // Si la barre est vide, on peut par exemple vider la liste ou afficher tous les éléments
    if (searchText.isEmpty()) {
        ui->listWidget->clear();
        return;
    }

    // Construction de la requête SQL en fonction du mode de recherche sélectionné
    QString requete = "SELECT ID_PROJET, TITREPROJET, DESCRIPTIONP, BUDGETPROJET, DATELP, AVANCEMENTP FROM LAMIS.PROJETS ";

    if (m_searchMode == "titre") {
        requete += "WHERE TITREPROJET LIKE :searchText";
    } else if (m_searchMode == "id") {
        requete += "WHERE ID_PROJET = :searchText";
    } else if (m_searchMode == "description") {
        requete += "WHERE DESCRIPTIONP LIKE :searchText";
    } else {
        // Par défaut, recherche par titre
        requete += "WHERE TITREPROJET LIKE :searchText";
    }

    QSqlQuery query;
    query.prepare(requete);

    // Lier la valeur du paramètre en fonction du mode sélectionné
    if (m_searchMode == "id") {
        // Convertir le texte en entier pour la recherche par id
        query.bindValue(":searchText", searchText.toInt());
    } else {
        // Pour titre et description, utiliser le LIKE avec des wildcards
        query.bindValue(":searchText", "%" + searchText + "%");
    }

    if (!query.exec()) {
        qDebug() << "Erreur lors de l'exécution de la requête:" << query.lastError().text();
        return;
    }

    // Vider la liste avant de la remplir avec les nouveaux résultats
    ui->listWidget->clear();

    // Remplissage de la liste avec les résultats
    while (query.next()) {
        int idProjet = query.value("ID_PROJET").toInt();
        QString titreProjet = query.value("TITREPROJET").toString();

        QListWidgetItem *item = new QListWidgetItem(titreProjet);
        item->setData(Qt::UserRole, idProjet);
        ui->listWidget->addItem(item);
    }
}





void Dialog::chargerProjets()
{
    // Nettoyer la liste avant de la remplir
    ui->listWidget->clear();

    QSqlQuery query;
    query.prepare("SELECT ID_PROJET, TITREPROJET, DESCRIPTIONP, BUDGETPROJET, DATELP, AVANCEMENTP "
                  "FROM LAMIS.PROJETS");

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur",
                              "Échec de récupération des projets : " + query.lastError().text());
        return;
    }

    while (query.next()) {
        // Récupération des données
        int id = query.value("ID_PROJET").toInt();
        QString titre = query.value("TITREPROJET").toString();
        QString description = query.value("DESCRIPTIONP").toString();
        double budget = query.value("BUDGETPROJET").toDouble();
        QString dateL = query.value("DATELP").toString(); // DATE en QString
        QString avancementStr = query.value("AVANCEMENTP").toString(); // VARCHAR2(50)

        // Convertir l'avancement en nombre (ex: "50" ou "50%")
        QString avancementCopy = avancementStr;
        int avancement = avancementCopy.remove("%").toInt();

        // Créer un widget pour l'affichage
        QWidget *widget = new QWidget();
        QGridLayout *layout = new QGridLayout();

        layout->setHorizontalSpacing(15);
        layout->setVerticalSpacing(10);

        // Affichage de l'ID
        QLabel *idLabel = new QLabel(QString::number(id));
        idLabel->setStyleSheet("font-weight: bold; color: #34495e;");
        layout->addWidget(idLabel, 0, 0);

        // Titre du projet
        QLabel *titreLabel = new QLabel(titre);
        titreLabel->setStyleSheet("font-weight: bold; color: #2980b9;");
        layout->addWidget(titreLabel, 0, 1);

        // Budget
        QLabel *budgetLabel = new QLabel(QString::number(budget, 'f', 2) + " €");
        budgetLabel->setStyleSheet("color: #2ecc71;");
        layout->addWidget(budgetLabel, 0, 2);

        // Date
        QLabel *dateLabel = new QLabel(dateL);
        dateLabel->setStyleSheet("color: #95a5a6;");
        layout->addWidget(dateLabel, 0, 3);

        // Avancement sous forme de barre de progression
        QProgressBar *progressBar = new QProgressBar();
        progressBar->setMaximum(100);
        progressBar->setValue(avancement);
        progressBar->setTextVisible(true);
        progressBar->setStyleSheet(
            "QProgressBar {"
            "   height: 12px;"
            "   background-color: #ecf0f1;"
            "   border-radius: 5px;"
            "} "
            "QProgressBar::chunk {"
            "   background-color: #2ecc71;"
            "   border-radius: 5px;"
            "}"
            );
        layout->addWidget(progressBar, 0, 4);

        // Appliquer le layout
        widget->setLayout(layout);

        // Créer un QListWidgetItem pour la liste
        QListWidgetItem *item = new QListWidgetItem();
        // Ajuste la hauteur des éléments
        item->setSizeHint(QSize(0, 80));

        // **Stocker l'ID du projet** dans l'item
        item->setData(Qt::UserRole, id);

        // Ajouter l'item et le widget dans la liste
        ui->listWidget->addItem(item);
        ui->listWidget->setItemWidget(item, widget);
    }
}




void Dialog::afficherDetailsProjet(QListWidgetItem *item)
{
    if (!item) {
        qDebug() << "Erreur : l'élément sélectionné est NULL.";
        return;
    }

    // Récupération de l'ID du projet (stocké dans Qt::UserRole)
    int idProjet = item->data(Qt::UserRole).toInt();
    qDebug() << "ID du projet sélectionné :" << idProjet;

    // Vérifier que l'ID est valide
    if (idProjet <= 0) {
        qDebug() << "Erreur : ID du projet non valide.";
        return;
    }

    // Préparer la requête SQL
    QSqlQuery query;
    query.prepare("SELECT TITREPROJET, DESCRIPTIONP, BUDGETPROJET, "
                  "TO_CHAR(DATELP, 'YYYY-MM-DD'), AVANCEMENTP "
                  "FROM LAMIS.PROJETS WHERE ID_PROJET = :idProjet");
    query.bindValue(":idProjet", idProjet);

    // Exécuter la requête
    if (!query.exec()) {
        qDebug() << "Erreur lors de l'exécution de la requête SQL :" << query.lastError().text();
        return;
    }

    // Vérifier s'il y a un résultat
    if (!query.next()) {
        qDebug() << "Aucun projet trouvé avec l'ID" << idProjet;
        return;
    }

    // Récupérer les champs
    QString titre = query.value(0).toString();
    QString description = query.value(1).toString();
    double budget = query.value(2).toDouble();
    QString dateL = query.value(3).toString();  // Formaté en "YYYY-MM-DD"
    QString avancement = query.value(4).toString(); // VARCHAR2(50) → QString

    // Éviter les budgets négatifs
    if (budget < 0) {
        budget = 0;
    }

    // Créer une fenêtre de détails
    QDialog *detailsDialog = new QDialog(this);
    detailsDialog->setWindowTitle("Détails du Projet");
    detailsDialog->setFixedSize(450, 350);

    QVBoxLayout *mainLayout = new QVBoxLayout(detailsDialog);

    QLabel *titleLabel = new QLabel("Détails du projet");
    titleLabel->setStyleSheet("font-size: 18px; font-weight: bold; color: #333;");
    mainLayout->addWidget(titleLabel);

    QLabel *titreLabel = new QLabel("<b>Titre:</b> " + titre);
    QLabel *descriptionLabel = new QLabel("<b>Description:</b> " + description);
    QLabel *budgetLabel = new QLabel("<b>Budget:</b> " + QString::number(budget, 'f', 2) + " €");
    QLabel *dateLabel = new QLabel("<b>Date de lancement:</b> " + dateL);
    QLabel *avancementLabel = new QLabel("<b>Avancement:</b> " + avancement + "%");

    // Styles
    titreLabel->setStyleSheet("font-size: 14px; color: #333;");
    descriptionLabel->setStyleSheet("font-size: 14px; color: #555;");
    budgetLabel->setStyleSheet("font-size: 14px; color: #000;");
    dateLabel->setStyleSheet("font-size: 14px; color: #777;");
    avancementLabel->setStyleSheet("font-size: 14px; color: #555;");

    mainLayout->addWidget(titreLabel);
    mainLayout->addWidget(descriptionLabel);
    mainLayout->addWidget(budgetLabel);
    mainLayout->addWidget(dateLabel);
    mainLayout->addWidget(avancementLabel);

    // Bouton Fermer
    QPushButton *closeButton = new QPushButton("Fermer");
    closeButton->setStyleSheet("background-color: #333; color: white; "
                               "border-radius: 5px; padding: 8px; margin-top: 20px;");
    connect(closeButton, &QPushButton::clicked, detailsDialog, &QDialog::accept);
    mainLayout->addWidget(closeButton);

    detailsDialog->setLayout(mainLayout);
    detailsDialog->exec();
}




void Dialog::on_listWidget_itemClicked(QListWidgetItem *item) {
    projetSelectionneID = item->data(Qt::UserRole).toInt(); // Récupérer l'ID du projet
}


#include <QPdfWriter>
#include <QPainter>
#include <QFileDialog>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>

void Dialog::on_telechargerPDF_clicked() {
    if (projetSelectionneID == 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un projet avant de générer le PDF !");
        return;
    }

    // Récupération des détails du projet
    QSqlQuery query;
    query.prepare("SELECT TITREPROJET, DESCRIPTIONP, BUDGETPROJET, DATELP, AVANCEMENTP "
                  "FROM LAMIS.PROJETS WHERE ID_PROJET = :id");
    query.bindValue(":id", projetSelectionneID);

    if (!query.exec() || !query.next()) {
        QMessageBox::critical(this, "Erreur", "Impossible de récupérer les détails du projet !");
        return;
    }

    QString titre = query.value("TITREPROJET").toString();
    QString description = query.value("DESCRIPTIONP").toString();
    double budget = query.value("BUDGETPROJET").toDouble();
    QString dateL = query.value("DATELP").toString();
    QString avancement = query.value("AVANCEMENTP").toString();

    // Choisir l'emplacement de sauvegarde
    QString filePath = QFileDialog::getSaveFileName(this, "Enregistrer le PDF", "", "PDF Files (*.pdf)");
    if (filePath.isEmpty()) {
        return;
    }

    // Création du PDF
    QPdfWriter writer(filePath);
    writer.setPageSize(QPageSize::A4);
    writer.setResolution(300);

    QPainter painter(&writer);
    painter.setRenderHint(QPainter::Antialiasing);

    // Fond beige (rgb(245, 245, 220))
    painter.fillRect(writer.pageLayout().fullRectPixels(writer.resolution()), QColor(245, 245, 220));

    // Logo
    QImage logo("C:/Users/Lamis/Documents/essaie/logo.png");
    if (!logo.isNull()) {
        painter.drawImage(QRect(100, 100, 200, 200), logo); // Ajustez la position et la taille du logo
    }

    // Titre principal du document centré (sans style particulier)
    painter.setFont(QFont("Helvetica", 24)); // Police simple sans gras
    painter.setPen(QColor(0, 0, 0)); // Couleur noire par défaut

    // Calculer la position du titre pour qu'il soit centré horizontalement
    int titleY = 100; // Position verticale du titre (ajustez selon vos besoins)
    QString titleText = "Détails du Projet";
    int textWidth = painter.fontMetrics().horizontalAdvance(titleText); // Largeur du texte
    int pageWidth = writer.pageLayout().fullRectPixels(writer.resolution()).width();
    int titleX = (pageWidth - textWidth) / 2; // Centrer horizontalement

    // Dessiner le texte du titre
    painter.drawText(titleX, titleY, titleText);

    // Position initiale pour les détails
    int x = 100;
    int y = 430;
    int lineSpacing = 100;

    painter.setFont(QFont("Calibri", 14));  // Texte normal
    painter.setPen(QColor(0, 0, 0));  // Noir

    // Titre du projet
    painter.drawText(x, y, "📌 Titre du projet :");
    y += lineSpacing;
    painter.setFont(QFont("Calibri", 12, QFont::Bold));
    painter.drawText(x + 20, y, titre);
    y += lineSpacing * 2;

    // Description
    painter.setFont(QFont("Calibri", 14));
    painter.drawText(x, y, "📝 Description :");
    y += lineSpacing;
    painter.setFont(QFont("Calibri", 12, QFont::Bold));
    painter.drawText(QRect(x + 20, y, writer.pageLayout().fullRectPixels(writer.resolution()).width() - 100, 100), Qt::TextWordWrap, description);
    y += lineSpacing * 2;

    // Budget
    painter.setFont(QFont("Calibri", 14));
    painter.drawText(x, y, "💰 Budget :");
    y += lineSpacing;
    painter.setFont(QFont("Calibri", 12, QFont::Bold));
    painter.drawText(x + 20, y, QString::number(budget, 'f', 2) + " €");
    y += lineSpacing * 2;

    // Date de lancement
    painter.setFont(QFont("Calibri", 14));
    painter.drawText(x, y, "📅 Date de lancement :");
    y += lineSpacing;
    painter.setFont(QFont("Calibri", 12, QFont::Bold));
    painter.drawText(x + 20, y, dateL);
    y += lineSpacing * 2;

    // Avancement
    painter.setFont(QFont("Calibri", 14));
    painter.drawText(x, y, "📊 Avancement :");
    y += lineSpacing;
    painter.setFont(QFont("Calibri", 12, QFont::Bold));
    painter.drawText(x + 20, y, avancement + "%");

    // Finaliser le PDF
    painter.end();

    QMessageBox::information(this, "Succès", "Le fichier PDF a été généré avec succès !");
}
