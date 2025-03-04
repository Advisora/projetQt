#include "employes.h"

Employes::Employes() {}

Employes::Employes(QString nom, QString prenom, QString mail, QString password, QString dateN, QString genre, QString poste, QString etat, QString num)
{
    this->nom = nom;
    this->prenom = prenom;
    this->mail = mail;
    this->password = password;
    this->dateN = dateN;
    this->genre = genre;
    this->poste = poste;
    this->etat = etat;
    this->num = num;
}

bool Employes::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO EMPLOYES (NOMEMP, PRENOMEMP, MAILEMP, PASSWORDEMP, DATENEMP, GENREEMP, POSTEEMP, ETATEMP, NUMEMP) "
                  "VALUES (:nom, :prenom, :mail, :password, TO_DATE(:dateN, 'YYYY-MM-DD'), :genre, :poste, :etat, :num)");

    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":mail", mail);
    query.bindValue(":password", password);
    query.bindValue(":dateN", dateN);
    query.bindValue(":genre", genre);
    query.bindValue(":poste", poste);
    query.bindValue(":etat", etat);
    query.bindValue(":num", num);

    if (query.exec()) {
        qDebug() << "Employé ajouté avec succès";
        return true;
    } else {
        qDebug() << "Erreur lors de l'ajout :" << query.lastError().text();
        return false;
    }
}

QSqlQueryModel* Employes::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("SELECT NOMEMP, PRENOMEMP, MAILEMP, DATENEMP, GENREEMP, POSTEEMP, ETATEMP, NUMEMP FROM EMPLOYES");

    if (query.exec()) {
        model->setQuery(query);
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Prenom"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Email"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date de Naissance"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("Genre"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("Poste"));
        model->setHeaderData(6, Qt::Horizontal, QObject::tr("Etat"));
        model->setHeaderData(7, Qt::Horizontal, QObject::tr("Numéro"));
        qDebug() << "Affichage réussi";
    } else {
        qDebug() << "Erreur lors de l'affichage:" << query.lastError().text();
    }

    return model;
}

QSqlQueryModel* Employes::chercher(QString nom)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;

    // Search for employees by name (nom)
    query.prepare("SELECT NOMEMP, PRENOMEMP, MAILEMP, DATENEMP, GENREEMP, POSTEEMP, ETATEMP, NUMEMP FROM EMPLOYES WHERE NOMEMP LIKE :nom");
    query.bindValue(":nom", "%" + nom + "%");  // Add wildcard for partial match

    if (query.exec()) {
        model->setQuery(query);
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("Prenom"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("Email"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date de Naissance"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("Genre"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("Poste"));
        model->setHeaderData(6, Qt::Horizontal, QObject::tr("Etat"));
        model->setHeaderData(7, Qt::Horizontal, QObject::tr("Numéro"));
        qDebug() << "Recherche réussie";
    } else {
        qDebug() << "Erreur lors de la recherche:" << query.lastError().text();
    }

    return model;
}

bool Employes::supprimer(QString num)
{
    QSqlQuery query;
    query.prepare("DELETE FROM EMPLOYES WHERE NUMEMP = :num");
    query.bindValue(":num", num);

    if (query.exec()) {
        qDebug() << "Employé supprimé avec succès";
        return true;
    } else {
        qDebug() << "Erreur lors de la suppression :" << query.lastError().text();
        return false;
    }
}
