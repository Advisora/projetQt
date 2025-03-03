#include <QDebug> // Don't forget to include QDebug
#include "connection.h"
Connection::Connection()
{
}

bool Connection::createconnect()
{
    bool test = false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("advisora"); // Insert the name of the data source
    db.setUserName("lamis"); // Insert the username
    db.setPassword("lamis"); // Insert the password for this user

    qDebug() << "Attempting to connect to the database...";

    if (db.open()) {
        test = true;
        qDebug() << "Connection successful!";
    } else {
        qDebug() << "Connection failed: " << db.lastError().text();
    }

    return test;
}
void Connection::closeconnection(){db.close();}
