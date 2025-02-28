#include "connexion.h"
#include <QSqlError>
#include <QDebug>


Connection::Connection() {}

bool Connection::createconnect() {
    bool test = false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");

    db.setDatabaseName("advisora");  // Nom de la source ODBC
    db.setUserName("lamis");         // Nom d'utilisateur Oracle
    db.setPassword("lamis");         // Mot de passe Oracle

    if (db.open()) {
        test = true;
        qDebug() << "Connexion réussie!";
    } else {
        qDebug() << "Erreur de connexion: " << db.lastError().text();
    }

    return test;
}
