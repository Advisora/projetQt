#include "events.h"
Event::Event() {
    // Constructor definition (initialize members as needed)
}

Event::~Event() {}

#include <QDate>
bool Event::addEvent(int id, const QString &date, const QString &name, double price, const QString &location, int maxNb, const QString &duration) {
    QSqlQuery query;

    // Debug: Print the date to verify format
    qDebug() << "Date received:" << date;



    // Bind the date directly as a QString
    query.prepare("INSERT INTO evenement (IDEV, DATEEV, NOMEV, PRIXEV, LOCALISATIONEV, NBMAXEV, DUREEEV) "
                  "VALUES (:id, TO_DATE(:date, 'MM/DD/YYYY'), :name, :price, :location, :maxNb, :duration)");

    // Bind the values to the query
    query.bindValue(":id", id);
    query.bindValue(":date", date);  // Bind the raw date string
    query.bindValue(":name", name);
    query.bindValue(":price", price);
    query.bindValue(":location", location);
    query.bindValue(":maxNb", maxNb);
    query.bindValue(":duration", duration);

    return query.exec();
}

bool Event::deleteEvent(int id) {
    QSqlQuery query;
    query.prepare("DELETE FROM evenement WHERE IDEV = :id");
    query.bindValue(":id", id);

    return query.exec();
}

QSqlQueryModel* Event::loadEventForEdit(int id) {
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;

    // Prepare the SQL query to fetch event details based on ID
    query.prepare("SELECT IDEV, DATEEV, NOMEV, PRIXEV, LOCALISATIONEV, NBMAXEV, DUREEEV FROM evenement WHERE IDEV = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        qWarning() << "Error fetching event details: " << query.lastError().text();
        delete model;
        return nullptr;
    }

    model->setQuery(query);
    return model;
}




QSqlQueryModel* Event::showEventsList() {
    // Create a new model
    QSqlQueryModel* model = new QSqlQueryModel();

    // Prepare the query to select events data
    QSqlQuery query;
    query.prepare("SELECT IDEV, DATEEV, NOMEV, PRIXEV, LOCALISATIONEV, NBMAXEV, DUREEEV FROM evenement");

    // Execute the query
    if (!query.exec()) {
        qWarning() << "Error fetching events: " << query.lastError().text();
        return nullptr;  // Return nullptr if the query fails
    }

    // Set the query model's query to the executed query
    model->setQuery(query);

    // Optional: Set headers for the columns (if desired)
    model->setHeaderData(0, Qt::Horizontal, "Event ID");
    model->setHeaderData(1, Qt::Horizontal, "Date");
    model->setHeaderData(2, Qt::Horizontal, "Name");
    model->setHeaderData(3, Qt::Horizontal, "Price");
    model->setHeaderData(4, Qt::Horizontal, "Location");
    model->setHeaderData(5, Qt::Horizontal, "Max Number");
    model->setHeaderData(6, Qt::Horizontal, "Duration");

    return model;
}
bool Event::updateEvent(int id, const QString &date, const QString &name, double price, const QString &location, int maxNb, const QString &duration) {
    QSqlQuery query;

    // Debug: Print the date to verify format
    qDebug() << "Date received for update:" << date;

    // Prepare the query for updating the event
    query.prepare("UPDATE evenement SET DATEEV = TO_DATE(:date, 'MM/DD/YYYY'), NOMEV = :name, PRIXEV = :price, "
                  "LOCALISATIONEV = :location, NBMAXEV = :maxNb, DUREEEV = :duration WHERE IDEV = :id");

    // Bind the values to the query
    query.bindValue(":id", id);
    query.bindValue(":date", date);  // Bind the raw date string
    query.bindValue(":name", name);
    query.bindValue(":price", price);
    query.bindValue(":location", location);
    query.bindValue(":maxNb", maxNb);
    query.bindValue(":duration", duration);

    return query.exec();
}
