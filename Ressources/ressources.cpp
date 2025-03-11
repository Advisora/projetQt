#include "Ressources.h"
#include <QSqlError>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>  // Recommended for error handling
#include <QVariant>   // If you use QVariant for SQL bindings
#include <QSqlQueryModel>

// Constructeurs
Ressources::Ressources() : id(0), nom(""), type(""), categorie(""), quantite(0), dernierDetection(""),
    nomCandidat(""), telephone(""), email(""), experience("") {}

Ressources::Ressources(int id, QString nom, QString type, QString categorie, int quantite,
                       QString dernierDetection, QString nomCandidat, QString telephone, QString email, QString experience)
    : id(id), nom(nom), type(type), categorie(categorie), quantite(quantite),
    dernierDetection(dernierDetection), nomCandidat(nomCandidat), telephone(telephone),
    email(email), experience(experience) {}

// Getters
int Ressources::getId() const { return id; }
QString Ressources::getNom() const { return nom; }
QString Ressources::getType() const { return type; }
QString Ressources::getCategorie() const { return categorie; }
int Ressources::getQuantite() const { return quantite; }
QString Ressources::getDernierDetection() const { return dernierDetection; }
QString Ressources::getNomCandidat() const { return nomCandidat; }
QString Ressources::getTelephone() const { return telephone; }
QString Ressources::getEmail() const { return email; }
QString Ressources::getExperience() const { return experience; }

// Setters
void Ressources::setId(int id) { this->id = id; }
void Ressources::setNom(QString nom) { this->nom = nom; }
void Ressources::setType(QString type) { this->type = type; }
void Ressources::setCategorie(QString categorie) { this->categorie = categorie; }
void Ressources::setQuantite(int quantite) { this->quantite = quantite; }
void Ressources::setDernierDetection(QString dernierDetection) { this->dernierDetection = dernierDetection; }
void Ressources::setNomCandidat(QString nomCandidat) { this->nomCandidat = nomCandidat; }
void Ressources::setTelephone(QString telephone) { this->telephone = telephone; }
void Ressources::setEmail(QString email) { this->email = email; }
void Ressources::setExperience(QString experience) { this->experience = experience; }

// Ajouter une ressource à la base de données
bool Ressources::ajouter() {
    QSqlQuery query;
    query.prepare("INSERT INTO RESSOURCES (ID_RESSOURCE, NOM_RESSOURCE, TYPE_RESSOURCE, CATEGORIE, QUANTITE, "
                  "DERNIER_DETECTION, NOML_CONDIDAT, TELEPHONE, EMAIL, EXPERIENCE) "
                  "VALUES (:id, :nom, :type, :categorie, :quantite, :dernierDetection, :nomCandidat, :telephone, :email, :experience)");

    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":type", type);
    query.bindValue(":categorie", categorie);
    query.bindValue(":quantite", quantite);
    query.bindValue(":dernierDetection", dernierDetection);
    query.bindValue(":nomCandidat", nomCandidat);
    query.bindValue(":telephone", telephone);
    query.bindValue(":email", email);
    query.bindValue(":experience", experience);

    if (query.exec()) {
        qDebug() << "Ressource ajoutée avec succès!";
        return true;
    } else {
        qDebug() << "Erreur d'ajout: " << query.lastError().text();
        return false;
    }
}

// Modifier une ressource existante
bool Ressources::modifier(int id, QString nom, QString type, QString categorie, int quantite,
                          QString dernierDetection, QString nomCandidat, QString telephone, QString email, QString experience)
{
    QSqlQuery query;
    query.prepare("UPDATE RESSOURCES SET NOM_RESSOURCE=:nom, TYPE_RESSOURCE=:type, CATEGORIE=:categorie, QUANTITE=:quantite, "
                  "DERNIER_DETECTION=:dernierDetection, NOML_CONDIDAT=:nomCandidat, TELEPHONE=:telephone, EMAIL=:email, EXPERIENCE=:experience "
                  "WHERE ID_RESSOURCE=:id");

    query.bindValue(":nom", nom);
    query.bindValue(":type", type);
    query.bindValue(":categorie", categorie);
    query.bindValue(":quantite", quantite);
    query.bindValue(":dernierDetection", dernierDetection);
    query.bindValue(":nomCandidat", nomCandidat);
    query.bindValue(":telephone", telephone);
    query.bindValue(":email", email);
    query.bindValue(":experience", experience);
    query.bindValue(":id", id);

    return query.exec();
}

// Supprimer une ressource par ID
bool Ressources::supprimer(int id) {
    QSqlQuery query;
    query.prepare("DELETE FROM RESSOURCES WHERE ID_RESSOURCE = :id");
    query.bindValue(":id", id);
    return query.exec();
}

// Afficher la liste des ressources
QSqlQueryModel* Ressources::afficher() {
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM RESSOURCES");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID Ressource"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom Ressource"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type Ressource"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Catégorie"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Quantité"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Dernière Détection"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Nom Candidat"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("Téléphone"));
    model->setHeaderData(8, Qt::Horizontal, QObject::tr("Email"));
    model->setHeaderData(9, Qt::Horizontal, QObject::tr("Expérience"));
    return model;
}

// Rechercher une ressource par ID
QSqlQueryModel* Ressources::rechercher(int id)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    QSqlQuery query;

    query.prepare("SELECT * FROM RESSOURCES WHERE ID_RESSOURCE = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        qDebug() << "❌ Erreur de recherche: " << query.lastError().text();
        return nullptr;  // Return null if the query fails
    }

    model->setQuery(query);
    return model;
}
