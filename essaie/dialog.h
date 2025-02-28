#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QStringList>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QListWidgetItem>
#include <QMenu>
#include <QTableWidget>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    void chargerProjets(); // Nouvelle fonction pour récupérer les projets depuis la base de données

protected:
    // Pour capter l'événement de clic sur la searchLineEdit
    bool eventFilter(QObject *obj, QEvent *event) override;

private slots:
   void afficherDetailsProjet(QListWidgetItem *item);

   void setSearchOptionTitle();
   void setSearchOptionId();
   void setSearchOptionDescription();
   // Slot pour lancer la recherche lors de la validation (ex: appui sur Entrée)
   void on_searchLineEdit_textChanged(const QString &searchText);
   void on_telechargerPDF_clicked();
   void on_listWidget_itemClicked(QListWidgetItem *item);
   private:
    Ui::Dialog *ui;
    QMenu *m_searchMenu;
    QString m_searchMode; // "titre", "id", "description"
    int projetSelectionneID; // Stocke l'ID du projet sélectionné


};

#endif // DIALOG_H
