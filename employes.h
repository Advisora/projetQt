#ifndef EMPLOYES_H
#define EMPLOYES_H

#include <QString>
#include <QSqlQueryModel>

class Employes {
public:
    Employes(QString nom = "", QString prenom = "", QString mail = "", QString password = "", QString date = "", QString genre = "", QString poste = "", QString etat = "", QString num = "");

    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int id);
    QSqlQueryModel* chercher(const QString& text);
    QSqlQueryModel* chercherParNom(const QString& nom);
    void chargerEmploye(int id);  // ✅ Fonction pour charger les infos d'un employé

    bool modifier(int id, const QString &nom, const QString &prenom, const QString &mail,
                            const QString &password, const QString &dateN, const QString &genre,
                            const QString &poste, const QString &etat, const QString &num);// Déclaration de la fonction modifier
    bool existe(int id);
public:
    QString nom, prenom, mail, password, date, genre, poste, etat, num;

};

#endif // EMPLOYES_H
