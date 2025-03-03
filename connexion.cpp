#include "connexion.h"
#include <QDebug>

Connection::Connection()
{

}

bool Connection::createconnect()
{
    bool test = false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("advisora"); // Nom de la source de données
    db.setUserName("lamis");       // Nom d'utilisateur
    db.setPassword("lamis");       // Mot de passe

    qDebug() << "Drivers disponibles:" << QSqlDatabase::drivers(); // Vérification des drivers

    if (db.open()) {
        qDebug() << "Connexion réussie";
        test = true;
    } else {
        qDebug() << "Erreur de connexion:" << db.lastError().text();
    }

    return test;
}
