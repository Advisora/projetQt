#ifndef MAINWINDOW_H
#define MAINWINDOW_H

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

    void on_ajout_clicked();  // Ajout du slot pour le bouton "ajout"
    void on_pushButton_ajouter_clicked();

    // Ajout du slot pour la gestion du changement de texte dans le QComboBox
    void on_comboBox_currentTextChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
