#include "employes.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

Employes::Employes(QString nom, QString prenom, QString mail, QString password, QString date, QString genre, QString poste, QString etat, QString num) {
    this->nom = nom;
    this->prenom = prenom;
    this->mail = mail;
    this->password = password;
    this->date = date;
    this->genre = genre;
    this->poste = poste;
    this->etat = etat;
    this->num = num;
}

bool Employes::ajouter() {
    QSqlQuery query;
    query.prepare("INSERT INTO EMPLOYES (NOMEMP, PRENOMEMP, MAILEMP, PASSWORDEMP, DATENEMP, GENREEMP, POSTEEMP, ETATEMP, NUMEMP) "
                  "VALUES (:nom, :prenom, :mail, :password, TO_DATE(:date, 'YYYY-MM-DD'), :genre, :poste, :etat, :num)");

    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":mail", mail);
    query.bindValue(":password", password);
    query.bindValue(":date", date);
    query.bindValue(":genre", genre);
    query.bindValue(":poste", poste);
    query.bindValue(":etat", etat);
    query.bindValue(":num", num);

    return query.exec();
}

QSqlQueryModel* Employes::afficher() {
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT IDEMP, NOMEMP, PRENOMEMP, POSTEEMP, MAILEMP, DATENEMP, GENREEMP, ETATEMP, NUMEMP FROM EMPLOYES");
    return model;
}

bool Employes::supprimer(int id) {
    QSqlQuery query;
    query.prepare("DELETE FROM EMPLOYES WHERE IDEMP = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "❌ Erreur SQL lors de la suppression:" << query.lastError().text();
        return false;
    }

    qDebug() << "✅ Suppression réussie pour l'ID:" << id;
    return true;
}

QSqlQueryModel* Employes::chercher(const QString& text) {
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("SELECT IDEMP, NOMEMP, PRENOMEMP, POSTEEMP, MAILEMP, DATENEMP, GENREEMP, ETATEMP, NUMEMP "
                  "FROM EMPLOYES WHERE IDEMP LIKE :search OR NOMEMP LIKE :search");
    QString searchPattern = "%" + text + "%";
    query.bindValue(":search", searchPattern);

    if (!query.exec()) {
        qDebug() << "Erreur lors de la recherche :" << query.lastError().text();
    }

    model->setQuery(query);
    return model;
}

QSqlQueryModel* Employes::chercherParNom(const QString& nom) {
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("SELECT IDEMP, NOMEMP, PRENOMEMP, POSTEEMP, MAILEMP, DATENEMP, GENREEMP, ETATEMP, NUMEMP "
                  "FROM EMPLOYES WHERE NOMEMP LIKE :nom");
    query.bindValue(":nom", "%" + nom + "%");

    if (!query.exec()) {
        qDebug() << "Erreur lors de la recherche par nom :" << query.lastError().text();
    }

    model->setQuery(query);
    return model;
}
bool Employes::modifier(int id, const QString &nom, const QString &prenom, const QString &mail,
                        const QString &password, const QString &dateN, const QString &genre,
                        const QString &poste, const QString &etat, const QString &num) {
    QSqlQuery query;

    // Prepare the SQL query
    query.prepare("UPDATE EMPLOYES SET "
                  "NOMEMP = :nom, "
                  "PRENOMEMP = :prenom, "
                  "MAILEMP = :mail, "
                  "PASSWORDEMP = :password, "
                  "DATENEMP = TO_DATE(:dateN, 'YYYY-MM-DD'), "
                  "GENREEMP = :genre, "
                  "POSTEEMP = :poste, "
                  "ETATEMP = :etat, "
                  "NUMEMP = :num "
                  "WHERE IDEMP = :id");

    // Bind values to the query
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":mail", mail);
    query.bindValue(":password", password);
    query.bindValue(":dateN", dateN);
    query.bindValue(":genre", genre);
    query.bindValue(":poste", poste);
    query.bindValue(":etat", etat);
    query.bindValue(":num", num);
    query.bindValue(":id", id);

    // Execute the query
    if (!query.exec()) {
        qDebug() << "❌ Error in modifier function:" << query.lastError().text();
        qDebug() << "Query:" << query.lastQuery();
        return false;
    }

    qDebug() << "✅ Employee with ID" << id << "updated successfully.";
    return true;
}

void Employes::chargerEmploye(int id) {
    QSqlQuery query;
    query.prepare("SELECT NOMEMP, PRENOMEMP, MAILEMP, PASSWORDEMP, DATENEMP, GENREEMP, POSTEEMP, ETATEMP, NUMEMP FROM EMPLOYES WHERE IDEMP = :id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        // Charger les valeurs dans l'objet Employes
        nom = query.value("NOMEMP").toString();
        prenom = query.value("PRENOMEMP").toString();
        mail = query.value("MAILEMP").toString();
        password = query.value("PASSWORDEMP").toString();
        date = query.value("DATENEMP").toString();
        genre = query.value("GENREEMP").toString();
        poste = query.value("POSTEEMP").toString();
        etat = query.value("ETATEMP").toString();
        num = query.value("NUMEMP").toString();
    } else {
        qDebug() << "❌ Erreur: Impossible de charger l'employé" << query.lastError();
    }
}
bool Employes::existe(int id)
{
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM EMPLOYES WHERE IDEMP = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "Erreur lors de l'exécution de la requête : " << query.lastError().text();
        return false;
    }

    if (query.next()) {
        int count = query.value(0).toInt();
        qDebug() << "Count for ID" << id << ":" << count;
        return count > 0;
    }
    return false;
}
