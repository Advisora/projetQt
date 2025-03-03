#ifndef EMPLOYES_H
#define EMPLOYES_H

#include <QString>
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

class Employes
{
public:
    Employes();
    Employes(QString, QString, QString, QString, QString, QString, QString, QString, QString);

    bool ajouter();

private:
    QString nom, prenom, mail, password, dateN, genre, poste, etat, num;
};

#endif // EMPLOYES_H
