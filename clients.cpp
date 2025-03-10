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
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QJsonObject>
#include <QJsonDocument>
#include <QRandomGenerator>
#include <QtNetwork>
const QString NEXMO_API_KEY = "490d4997";
const QString NEXMO_API_SECRET = "t79sPZqbhJlIZy5C";
const QStringList NEXMO_PHONE_NUMBERS = {
    "+21693004165",  // Your first Nexmo phone number
    "+21692524765",  // Your second Nexmo phone number
    "+21692137340"   // Your third Nexmo phone number
};

// Example: Choose the first number from the list
const QString NEXMO_PHONE_NUMBER = NEXMO_PHONE_NUMBERS[0];  // You can change this index dynamically



void MainWindow::loadClients() {
    static QSqlQueryModel *model = new QSqlQueryModel(this);
    QSqlQuery query;
    query.prepare("SELECT IDCLIENT, NOMCLIENT, PRENOMCLIENT, DATEN, DESCRIPTION, BUDGET, EMAILCLIENT, GENRE, NUMCLIENT FROM CLIENTS");

    if (!query.exec()) {
        qDebug() << "Erreur de chargement des clients:" << query.lastError().text();
        return;
    }


}


void MainWindow::on_loadClientById_clicked() {
    qDebug() << "Chargement de tous les clients...";

    if (!QSqlDatabase::database().isOpen()) {
        qDebug() << "Erreur: Base de données non ouverte!";
        return;
    }

    QSqlQueryModel *model = new QSqlQueryModel(this);
    QSqlQuery query;
    query.prepare("SELECT IDCLIENT, NOMCLIENT, PRENOMCLIENT, DATEN, DESCRIPTION, BUDGET, EMAILCLIENT, GENRE, NUMCLIENT FROM CLIENTS");

    if (!query.exec()) {
        qDebug() << "Erreur SQL: " << query.lastError().text();
        delete model;
        return;
    }

    model->setQuery(query);
    ui->tableView->setModel(model);
    qDebug() << "Clients chargés: " << model->rowCount();
}


void MainWindow::on_ajouterC_clicked() {
    // Get data from the form
    QString nom = ui->nomC->text().trimmed();
    QString prenom = ui->prenomC->text().trimmed();
    QString description = ui->desc->text().trimmed();
    float budget = ui->budgetC->text().toFloat();
    QString email = ui->emailC->text().trimmed();
    QString genre = ui->genreC->text().trimmed();
    QString num = ui->numC->text().trimmed();  // Phone number
    QDate date = ui->dateN->date();  // Get the date from QDateEdit

    // Check if the date is invalid (01/01/0000 in QDateEdit is considered invalid)
    if (!date.isValid() || date == QDate(0, 1, 1)) {
        QMessageBox::warning(this, "Erreur", "La date n'est pas valide.");
        return;
    }

    // Validate name (only alphabetic characters allowed)
    QRegularExpression nameRegex("^[A-Za-zÀ-ÿ]+$");  // Supports international letters
    if (!nameRegex.match(nom).hasMatch() || !nameRegex.match(prenom).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "Le nom et le prénom doivent contenir uniquement des lettres.");
        return;
    }

    // Validate budget (must be at least 1000 and not negative)
    if (budget < 1000) {
        QMessageBox::warning(this, "Erreur", "Le budget doit être au minimum de 1000.");
        return;
    }

    // Validate email format
    QRegularExpression emailRegex(R"(^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$)");
    if (!emailRegex.match(email).hasMatch()) {
        QMessageBox::warning(this, "Erreur", "L'adresse e-mail n'est pas valide.");
        return;
    }

    // Validate phone number and ensure it starts with +216
    if (!num.startsWith("+216")) {
        if (num.startsWith("216")) {
            num = "+" + num;  // Add the '+' sign if it's missing
        } else if (num.startsWith("0")) {
            num = "+216" + num.mid(1);  // Remove leading 0 and add +216
        } else {
            QMessageBox::warning(this, "Erreur", "Le numéro doit être un numéro tunisien commençant par +216.");
            return;
        }
    }

    // Prepare SQL query for inserting the client
    QSqlQuery query;
    query.prepare("INSERT INTO CLIENTS (NOMCLIENT, PRENOMCLIENT, DATEN, DESCRIPTION, BUDGET, EMAILCLIENT, GENRE, NUMCLIENT) "
                  "VALUES (:nom, :prenom, TO_DATE(:dateN, 'YYYY-MM-DD'), :description, :budget, :email, :genre, :num)");
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":dateN", date.toString("yyyy-MM-dd"));  // Pass valid date
    query.bindValue(":description", description);
    query.bindValue(":budget", budget);
    query.bindValue(":email", email);
    query.bindValue(":genre", genre);
    query.bindValue(":num", num);

    if (query.exec()) {
        qDebug() << "Ajout réussi !";

        // Fetch the last inserted client by using the last inserted ID
        QSqlQuery lastIdQuery;
        lastIdQuery.prepare("SELECT MAX(IDCLIENT) FROM CLIENTS");
        if (lastIdQuery.exec() && lastIdQuery.next()) {
            int lastInsertedId = lastIdQuery.value(0).toInt();

            // Now retrieve the data for that client
            QSqlQuery clientQuery;
            clientQuery.prepare("SELECT IDCLIENT, NOMCLIENT, PRENOMCLIENT, DATEN, DESCRIPTION, BUDGET, EMAILCLIENT, GENRE, NUMCLIENT "
                                "FROM CLIENTS WHERE IDCLIENT = :id");
            clientQuery.bindValue(":id", lastInsertedId);

            if (clientQuery.exec() && clientQuery.next()) {
                static QSqlQueryModel *model = new QSqlQueryModel(this);
                model->setQuery(clientQuery);  // Set the query for the specific client
                ui->tableView->setModel(model);  // Set the updated model to the table view
                ui->tableView->resizeColumnsToContents();  // Adjust column widths

                // Send SMS with the generated ID and client info
                sendSMS(num, nom, prenom);
            } else {
                qDebug() << "Erreur lors de la récupération du dernier client: " << clientQuery.lastError().text();
            }
        } else {
            qDebug() << "Erreur lors de la récupération de l'ID du dernier client: " << lastIdQuery.lastError().text();
        }

        // Clear the input fields after successful insertion
        ui->nomC->clear();
        ui->prenomC->clear();
        ui->desc->clear();
        ui->budgetC->clear();
        ui->emailC->clear();
        ui->genreC->clear();
        ui->numC->clear();
        ui->dateN->setDate(QDate::currentDate());  // Reset date to current date

    } else {
        qDebug() << "Erreur d'ajout: " << query.lastError().text();
    }
}


QString MainWindow::generateRandomID() {
    QString chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    QString digits = "0123456789";
    QString randomID;

    for (int i = 0; i < 3; ++i) {
        randomID.append(chars[QRandomGenerator::global()->bounded(chars.length())]);
    }

    randomID.append("-");

    for (int i = 0; i < 3; ++i) {
        randomID.append(digits[QRandomGenerator::global()->bounded(digits.length())]);
    }

    randomID.append("-");

    for (int i = 0; i < 3; ++i) {
        randomID.append(chars[QRandomGenerator::global()->bounded(chars.length())]);
    }

    return randomID;
}

void MainWindow::sendSMS(const QString &toPhoneNumber, const QString &nom, const QString &prenom) {
    // Generate a random ID in the format XXX-123-XXX
    QString randomID = generateRandomID();

    // Compose the message
    QString message = QString(" Bonjour  %1 %2, vous êtes maintenant inscrit avec nous!.Votre ID est: %3 Team Advisora")
                          .arg(nom, prenom, randomID);

    // Send the SMS using Nexmo's API
    sendNexmoSMS(toPhoneNumber, message);
}

void MainWindow::sendNexmoSMS(const QString &toPhoneNumber, const QString &message) {
    QUrl url("https://rest.nexmo.com/sms/json");

    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    // Nexmo API credentials (API key and secret)
    QString apiKey = NEXMO_API_KEY;
    QString apiSecret = NEXMO_API_SECRET;

    // Prepare the POST data for SMS
    QByteArray postData;
    postData.append("api_key=" + apiKey.toUtf8());
    postData.append("&api_secret=" + apiSecret.toUtf8());
    postData.append("&to=" + toPhoneNumber.toUtf8());
    postData.append("&from=" + NEXMO_PHONE_NUMBER.toUtf8());  // Your Nexmo phone number
    postData.append("&text=" + message.toUtf8());  // The message content

    // Make the request
    QNetworkAccessManager *manager = new QNetworkAccessManager(this);
    QNetworkReply *reply = manager->post(request, postData);
    connect(reply, &QNetworkReply::finished, [reply]() {
        if (reply->error() == QNetworkReply::NoError) {
            qDebug() << "SMS sent successfully!";
        } else {
            qDebug() << "SMS failed: " << reply->errorString();
            qDebug() << "Full Response: " << reply->readAll();
        }
        reply->deleteLater();
    });
}




void MainWindow::on_trier_clicked() {
    QSqlQueryModel *model = new QSqlQueryModel(this);
    QString order = triAscendant ? "ASC" : "DESC";

    QSqlQuery query;
    query.prepare("SELECT * FROM CLIENTS ORDER BY BUDGET " + order);

    if (!query.exec()) {
        qDebug() << "Erreur lors du tri: " << query.lastError().text();
        return;
    }

    model->setQuery(query);
    ui->tableView->setModel(model);
    triAscendant = !triAscendant;
}
void MainWindow::loadClientById(int id)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM CLIENTS WHERE IDCLIENT = :id");
    query.bindValue(":id", id);

    if (!query.exec() || !query.next()) {
        qDebug() << "Aucun client trouvé avec l'ID:" << id;
        return;
    }

    // ✅ Use setText() for QLineEdit
    ui->prenomC->setText(query.value("PRENOMCLIENT").toString());
    ui->nomC->setText(query.value("NOMCLIENT").toString());

    // ✅ Get the date correctly from the database
    QVariant dateVariant = query.value("DATEN");
    if (dateVariant.isValid() && !dateVariant.isNull()) {
        QDate date = dateVariant.toDate();
        ui->dateN->setDate(date);  // ✅ Pass a QDate directly to QDateEdit
    } else {
        ui->dateN->clear();  // Clear if date is null
    }

    ui->desc->setText(query.value("DESCRIPTION").toString());
    ui->budgetC->setText(query.value("BUDGET").toString());
    ui->emailC->setText(query.value("EMAILCLIENT").toString());

    // ✅ If `genreC` is a QComboBox, use setCurrentText(), otherwise use setText()
    ui->genreC->setText(query.value("GENRE").toString());

    ui->numC->setText(query.value("NUMCLIENT").toString());
}



void MainWindow::on_cher_nom_textChanged(const QString &arg1)
{
    bool isNumber;
    int id = arg1.toInt(&isNumber);

    if (isNumber && id > 0) {
        loadClientById(id);  // Load specific client by ID
    } else {
        // 🔹 Reset form fields
        ui->prenomC->clear();
        ui->nomC->clear();
        ui->dateN->clear();
        ui->desc->clear();
        ui->budgetC->clear();
        ui->emailC->clear();
        ui->genreC->clear();
        ui->numC->clear();

        // 🔹 Search in database by `NOMCLIENT`
        QSqlQuery query;
        query.prepare("SELECT * FROM CLIENTS WHERE NOMCLIENT LIKE :nom");
        query.bindValue(":nom", "%" + arg1 + "%");

        if (!query.exec()) {
            qDebug() << "Erreur lors de la recherche :" << query.lastError().text();
            return;
        }

        // 🔹 Memory management: Delete old model if it exists
        static QSqlQueryModel *model = nullptr;
        if (model) {
            delete model;
        }

        // 🔹 Set the new model
        model = new QSqlQueryModel(this);
        model->setQuery(query);
        ui->tableView->setModel(model);
    }
}



void MainWindow::on_modifierC_clicked() {
    int id = ui->input->text().toInt();
    if (id <= 0) {
        QMessageBox::warning(this, "Erreur", "ID invalide!");
        return;
    }

    QString nom = ui->nomC->text().trimmed();
    QString prenom = ui->prenomC->text().trimmed();
    QString description = ui->desc->text().trimmed();
    float budget = ui->budgetC->text().toFloat();
    QString email = ui->emailC->text().trimmed();
    QString genre = ui->genreC->text().trimmed();
    QString num = ui->numC->text().trimmed();
    QDate date = ui->dateN->date();

    QSqlQuery query;
    query.prepare("UPDATE CLIENTS SET NOMCLIENT = :nom, PRENOMCLIENT = :prenom, DESCRIPTION = :description, "
                  "DATEN = TO_DATE(:date, 'YYYY-MM-DD'), BUDGET = :budget, EMAILCLIENT = :email, GENRE = :genre, NUMCLIENT = :num "
                  "WHERE IDCLIENT = :id");
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":date", date.toString("yyyy-MM-dd"));
    query.bindValue(":description", description);
    query.bindValue(":budget", budget);
    query.bindValue(":email", email);
    query.bindValue(":genre", genre);
    query.bindValue(":num", num);
    query.bindValue(":id", id);

    if (query.exec()) {
          QMessageBox::information(this, "Succès", "Le client avec l'ID " + QString::number(id) + " a été mis à jour avec succès.");
        qDebug() << "Modification réussie !";
         loadClients();
    } else {
        qDebug() << "Erreur de modification:" << query.lastError().text();
    }
}


void MainWindow::on_supprimerC_clicked() {
    int id = ui->input->text().toInt();
    if (id <= 0) {
        QMessageBox::warning(this, "Erreur", "ID invalide.");
        return;
    }

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirmation",
                                  "Voulez-vous vraiment supprimer le client avec l'ID " + QString::number(id) + " ?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::No) {
        return; // Annuler la suppression
    }

    QSqlQuery query;
    query.prepare("DELETE FROM CLIENTS WHERE IDCLIENT = :id");
    query.bindValue(":id", id);

    if (query.exec()) {
        QMessageBox::information(this, "Succès", "Le client avec l'ID " + QString::number(id) + " a été supprimé.");
        qDebug() << "Suppression réussie.";
        loadClients();
    } else {
        QMessageBox::critical(this, "Erreur", "Échec de la suppression: " + query.lastError().text());
        qDebug() << "Erreur de suppression: " << query.lastError().text();
    }
}

