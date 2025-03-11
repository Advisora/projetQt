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

void MainWindow::loadData() {
    static QSqlQueryModel *model = new QSqlQueryModel(this);
    QSqlQuery query("SELECT IDSTRG, NOMSTRG, TYPESTRG, PRIXSTRG, DESCRIPTIONSTRG, NBRE_S, DATESTRG FROM STRATEGIES");
    model->setQuery(query);

}

void MainWindow::loadStrategyById(int id) {
    QSqlQuery query;
    query.prepare("SELECT NOMSTRG, TYPESTRG, PRIXSTRG, DESCRIPTIONSTRG, NBRE_S FROM STRATEGIES WHERE IDSTRG = :id");
    query.bindValue(":id", id);
    if (query.exec() && query.next()) {
        ui->nom_s->setText(query.value(0).toString());
        ui->type_s->setCurrentText(query.value(1).toString());
        ui->prix_s->setText(query.value(2).toString());
        ui->des_s->setPlainText(query.value(3).toString());
        ui->nbre_s->setText(query.value(4).toString());
    } else {
        qDebug() << "Erreur: ID non trouvé ou erreur SQL: " << query.lastError().text();
    }
}

void MainWindow::on_add_s_clicked() {
    QString nom = ui->nom_s->text().trimmed();
    QString type = ui->type_s->currentText();
    QString description = ui->des_s->toPlainText().trimmed();
    int nbre = ui->nbre_s->text().toInt();
    double prix = ui->prix_s->text().toDouble();

    if (nom.isEmpty() || type.isEmpty() || description.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Tous les champs doivent être remplis.");
        return;
    }

    QSqlQuery query;
    query.prepare("INSERT INTO STRATEGIES (NOMSTRG, TYPESTRG, PRIXSTRG, DESCRIPTIONSTRG, NBRE_S) VALUES (:nom, :type, :prix, :description, :nbre)");
    query.bindValue(":nom", nom);
    query.bindValue(":type", type);
    query.bindValue(":prix", prix);
    query.bindValue(":description", description);
    query.bindValue(":nbre", nbre);

    if (query.exec()) {
        qDebug() << "Ajout réussi !";
        loadData();
    } else {
        qDebug() << "Erreur d'ajout: " << query.lastError().text() << " | Requête: " << query.lastQuery();
    }
}

void MainWindow::on_del_s_clicked() {
    int id = ui->cher_nom->text().toInt();
    if (id <= 0) {
        QMessageBox::warning(this, "Erreur", "ID non valide.");
        return;
    }

    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT COUNT(*) FROM STRATEGIES WHERE IDSTRG = :id");
    checkQuery.bindValue(":id", id);
    if (!checkQuery.exec() || !checkQuery.next() || checkQuery.value(0).toInt() == 0) {
        QMessageBox::warning(this, "Erreur", "ID inexistant.");
        return;
    }

    if (QMessageBox::question(this, "Confirmation", "Voulez-vous vraiment supprimer cette stratégie ?", QMessageBox::Yes | QMessageBox::No) == QMessageBox::No)
        return;

    QSqlQuery query;
    query.prepare("DELETE FROM STRATEGIES WHERE IDSTRG = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "Erreur SQL de suppression: " << query.lastError().text();
    } else {
        qDebug() << "Suppression réussie pour ID:" << id;
        loadData();
    }
}

void MainWindow::on_mod_s_clicked() {
    int id = ui->cher_nom->text().toInt();
    if (id <= 0) return;

    QString nom = ui->nom_s->text().trimmed();
    QString type = ui->type_s->currentText();
    QString description = ui->des_s->toPlainText().trimmed();
    int nbre = ui->nbre_s->text().toInt();
    double prix = ui->prix_s->text().toDouble();

    if (nom.isEmpty() || type.isEmpty() || description.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Tous les champs doivent être remplis.");
        return;
    }

    QSqlDatabase::database().transaction();
    QSqlQuery query;
    query.prepare("UPDATE STRATEGIES SET NOMSTRG = :nom, TYPESTRG = :type, PRIXSTRG = :prix, DESCRIPTIONSTRG = :description, NBRE_S = :nbre WHERE IDSTRG = :id");
    query.bindValue(":nom", nom);
    query.bindValue(":type", type);
    query.bindValue(":prix", prix);
    query.bindValue(":description", description);
    query.bindValue(":nbre", nbre);
    query.bindValue(":id", id);

    if (query.exec()) {
        QSqlDatabase::database().commit();
        qDebug() << "Modification réussie !";
        loadData();
    } else {
        QSqlDatabase::database().rollback();
        qDebug() << "Erreur de modification:" << query.lastError().text();
    }
}

void MainWindow::on_cher_nom_textChanged(const QString &text) {
    bool isNumber;
    int id = text.toInt(&isNumber);
    if (isNumber && id > 0) {
        loadStrategyById(id);
    } else {
        ui->nom_s->clear();
        ui->type_s->setCurrentIndex(0);
        ui->prix_s->clear();
        ui->des_s->clear();
        ui->nbre_s->clear();

        QSqlQuery query;
        query.prepare("SELECT * FROM STRATEGIES WHERE NOMSTRG LIKE :nom");
        query.bindValue(":nom", "%" + text + "%");
        query.exec();

        static QSqlQueryModel *model = new QSqlQueryModel(this);
        model->setQuery(query);
        ui->strategiesView->setModel(model);
    }
    updateLikesDisplay();  // Mise à jour des étoiles

}




void MainWindow::updateLikesDisplay() {
    QString cherNomText = ui->cher_nom->text().trimmed();

    // Vérifier si `cher_nom` est vide
    if (cherNomText.isEmpty()) {
        ui->like_s->clear();  // Supprime l'affichage des étoiles
        return;
    }

    // Vérifier si l'ID existe
    QSqlQuery query;
    query.prepare("SELECT NBRE_S FROM STRATEGIES WHERE IDSTRG = :id");
    query.bindValue(":id", cherNomText.toInt());
    if (!query.exec() || !query.next()) {
        ui->like_s->clear();  // ID non trouvé, donc pas d'affichage
        return;
    }

    int nbre = query.value(0).toInt();
    int likeCount = 0;

    if (nbre < 10) likeCount = 1;
    else if (nbre < 50) likeCount = 2;
    else if (nbre < 100) likeCount = 3;
    else if (nbre < 300) likeCount = 4;
    else likeCount = 5;

    // Affichage des étoiles
    QPixmap starPixmap(":/res/min_star.png");
    ui->like_s->clear();

    QString starsText;
    for (int i = 0; i < likeCount; ++i) {
        starsText += "⭐";  // Affichage avec emojis en backup si QLabel ne supporte pas d'images répétées
    }
    ui->like_s->setText(starsText);
}




void MainWindow::on_pdf_s_clicked() {
    QString filePath = "strategies.pdf";
    QPdfWriter writer(filePath);
    writer.setPageSize(QPageSize::A4);
    writer.setTitle("Liste des stratégies");

    QTextDocument doc;
    QTextCursor cursor(&doc);
    cursor.insertText("Liste des stratégies\n\n");

    // Création du tableau
    QTextTableFormat tableFormat;
    tableFormat.setBorder(1);
    tableFormat.setCellSpacing(0);
    tableFormat.setCellPadding(5);
    tableFormat.setAlignment(Qt::AlignLeft);

    QTextTable *table = cursor.insertTable(1, 6, tableFormat); // 1 ligne d'en-tête + 6 colonnes

    // Ajouter les en-têtes
    QStringList headers = {"ID", "Nom", "Type", "Prix", "Description", "Date"};
    for (int i = 0; i < headers.size(); ++i) {
        table->cellAt(0, i).firstCursorPosition().insertText(headers[i]);
    }

    QSqlQuery query;
    QString cherNomText = ui->cher_nom->text();
    bool isNumber;
    int id = cherNomText.toInt(&isNumber);

    if (isNumber && id > 0) {
        query.prepare("SELECT IDSTRG, NOMSTRG, TYPESTRG, PRIXSTRG, DESCRIPTIONSTRG, DATESTRG FROM STRATEGIES WHERE IDSTRG = :id");
        query.bindValue(":id", id);
    } else {
        query.prepare("SELECT IDSTRG, NOMSTRG, TYPESTRG, PRIXSTRG, DESCRIPTIONSTRG, DATESTRG FROM STRATEGIES");
    }

    if (!query.exec()) {
        qDebug() << "Erreur SQL lors de la génération du PDF: " << query.lastError().text();
        return;
    }

    while (query.next()) {
        int row = table->rows();
        table->appendRows(1);  // Ajouter une ligne

        table->cellAt(row, 0).firstCursorPosition().insertText(query.value("IDSTRG").toString());
        table->cellAt(row, 1).firstCursorPosition().insertText(query.value("NOMSTRG").toString());
        table->cellAt(row, 2).firstCursorPosition().insertText(query.value("TYPESTRG").toString());
        table->cellAt(row, 3).firstCursorPosition().insertText(query.value("PRIXSTRG").toString());
        table->cellAt(row, 4).firstCursorPosition().insertText(query.value("DESCRIPTIONSTRG").toString());
        table->cellAt(row, 5).firstCursorPosition().insertText(query.value("DATESTRG").toString());
    }

    doc.print(&writer);
    QMessageBox::information(this, "PDF", "Le fichier PDF a été généré avec succès: " + filePath);
}




















void MainWindow::on_tri_s_clicked() {
    QSqlQueryModel *model = new QSqlQueryModel(this);
    QString order = triAscendant ? "ASC" : "DESC";  // Alterne entre ascendant et descendant

    QSqlQuery query;
    query.prepare("SELECT IDSTRG, NOMSTRG, TYPESTRG, PRIXSTRG, DESCRIPTIONSTRG, NBRE_S, DATESTRG FROM STRATEGIES ORDER BY PRIXSTRG " + order);

    if (!query.exec()) {
        qDebug() << "Erreur lors du tri: " << query.lastError().text();
        return;
    }

    model->setQuery(query);
    ui->strategiesView->setModel(model);

    triAscendant = !triAscendant;  // Inverser l'état du tri pour la prochaine fois
}
  // Assure-toi d'inclure l'interface graphique


void MainWindow::on_stat_s_clicked() {
    QString filePath = "statistiques.pdf";
    QPdfWriter writer(filePath);
    writer.setPageSize(QPageSize::A4);
    writer.setTitle("Statistiques des stratégies");

    QPainter painter(&writer);
    painter.setRenderHint(QPainter::Antialiasing);

    // Définir les dimensions du PDF
    QRectF titleRect(100, 50, 400, 50); // Zone pour le titre
    QRectF chartRect(100, 150, 400, 400); // Zone pour le diagramme circulaire

    // Dessiner le titre correctement centré
    QFont titleFont("Arial", 16, QFont::Bold);
    painter.setFont(titleFont);
    painter.drawText(titleRect, Qt::AlignCenter, "Répartition des stratégies par type");

    // Récupérer les données de la base
    QSqlQuery query("SELECT TYPESTRG, COUNT(*) FROM STRATEGIES GROUP BY TYPESTRG");

    QVector<QPair<QString, int>> data;
    int total = 0;
    while (query.next()) {
        data.append(qMakePair(query.value(0).toString(), query.value(1).toInt()));
        total += query.value(1).toInt();
    }

    // Dessiner un diagramme circulaire à la main
    if (total > 0) {
        painter.setPen(Qt::NoPen);
        int startAngle = 0;

        QVector<QColor> colors = {Qt::red, Qt::blue, Qt::green, Qt::yellow, Qt::cyan, Qt::magenta}; // Palette de couleurs
        int colorIndex = 0;

        for (const auto &item : data) {
            int angleSpan = 360 * (item.second / (double)total); // Calcul de la part
            painter.setBrush(colors[colorIndex % colors.size()]); // Choisir une couleur

            // Dessiner un secteur
            painter.drawPie(chartRect, startAngle * 16, angleSpan * 16);
            startAngle += angleSpan;
            colorIndex++;
        }
    } else {
        painter.drawText(chartRect, Qt::AlignCenter, "Aucune donnée disponible");
    }

    // Fin du dessin
    painter.end();
    QMessageBox::information(this, "PDF", "Le fichier PDF des statistiques graphiques a été généré avec succès: " + filePath);
}





