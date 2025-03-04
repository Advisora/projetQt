#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "employes.h"
#include <QMainWindow>

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
    void on_supprimerButton_clicked();  // Slot for deleting employee

    void on_ajout_clicked();  // Ajout du slot pour le bouton "ajout"
    void on_pushButton_ajouter_clicked();

    void on_comboBox_currentTextChanged(const QString &arg1);
    void on_lineEdit_search_textChanged(const QString &text); // Slot for search functionality

private:
    Ui::MainWindow *ui;
    Employes employe;
};

#endif // MAINWINDOW_H
