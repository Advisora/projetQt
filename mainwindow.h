#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "employes.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_gestionClientsButton_clicked();
    void on_GestionEvenementsButton_clicked();
    void on_GestionProjetsButton_clicked();
    void on_GestionRessourcesButton_clicked();
    void on_GestionStrategiesButton_clicked();
    void on_GestionEmployeesButton_clicked();
    void on_lineEdit_search_textChanged(const QString &text);
    void on_comboBox_currentTextChanged(const QString &text);
    void on_supprimerButton_clicked();
    void on_pushButton_ajouter_clicked();
    void on_ajout_clicked();
    void on_pushButton_search_clicked();
    void on_sauvegarderButton_clicked();
    void on_buttonModifier_clicked();
private:
    Ui::MainWindow *ui;
    Employes employe; // Instance de la classe Employes
    Employes tmpEmploye;
};


#endif // MAINWINDOW_H
