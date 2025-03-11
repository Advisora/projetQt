#ifndef RESSOURCES_H
#define RESSOURCES_H
#include <QSqlQueryModel>
#include <QString>

class Ressources {
private:
    int id;
    QString nom;
    QString type;
    QString categorie;
    int quantite;
    QString dernierDetection;
    QString nomCandidat;
    QString telephone;
    QString email;
    QString experience;

public:
    Ressources();
    Ressources(int id, QString nom, QString type, QString categorie, int quantite,
               QString dernierDetection, QString nomCandidat, QString telephone, QString email, QString experience);
     QSqlQueryModel* afficher();

    int getId() const;
    QString getNom() const;
    QString getType() const;
    QString getCategorie() const;
    int getQuantite() const;
    QString getDernierDetection() const;
    QString getNomCandidat() const;
    QString getTelephone() const;
    QString getEmail() const;
    QString getExperience() const;

    void setId(int id);
    void setNom(QString nom);
    void setType(QString type);
    void setCategorie(QString categorie);
    void setQuantite(int quantite);
    void setDernierDetection(QString dernierDetection);
    void setNomCandidat(QString nomCandidat);
    void setTelephone(QString telephone);
    void setEmail(QString email);
    void setExperience(QString experience);

    bool ajouter();
    bool modifier(int id, QString nom, QString type, QString categorie, int quantite,
                  QString dernierDetection, QString nomCandidat, QString telephone,
                  QString email, QString experience);
    bool supprimer(int id);
     QSqlQueryModel* rechercher(int id);
};

#endif // RESSOURCES_H
