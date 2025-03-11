#ifndef EVENTS_H
#define EVENTS_H

#include <QString>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QVector>
#include <QVariantMap>
#include <QSqlQueryModel>
#include <QDebug>
class Event {
public:
    Event();
    ~Event();

    bool addEvent(int id, const QString &date, const QString &name, double price, const QString &location, int maxNb, const QString &duration);
    bool deleteEvent(int id);
    QSqlQueryModel* showEventsList() ;

    QSqlQueryModel* loadEventForEdit(int id);
    bool updateEvent(int id, const QString &date, const QString &name, double price, const QString &location, int maxNb, const QString &duration);
private:
    // Private member variables (attributes)
    int eventId;
    QString eventDate;
    QString eventName;
    double eventPrice;
    QString eventLocation;
    int eventMaxNb;
    QString eventDuration;

    // Database connection
    QSqlDatabase db;
};

#endif // EVENTS_H
