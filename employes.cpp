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

    if (query.exec())
    {
        qDebug() << "Employé ajouté avec succès";
        return true;
    }
    else
    {
        qDebug() << "Erreur lors de l'ajout :" << query.lastError().text();
        return false;
    }
}
