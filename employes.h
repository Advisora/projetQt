#ifndef EMPLOYES_H
#define EMPLOYES_H

#include <QString>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlQueryModel>
#include <QDebug>

class Employes
{
public:
    Employes();
    Employes(QString, QString, QString, QString, QString, QString, QString, QString, QString);

    bool ajouter();
    QSqlQueryModel* afficher();
    QSqlQueryModel* chercher(QString nom);  // Search employees by name
    bool supprimer(QString num);  // Delete employee by num

private:
    QString nom, prenom, mail, password, dateN, genre, poste, etat, num;
};

#endif // EMPLOYES_H
