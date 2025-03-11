#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
<<<<<<< HEAD

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

    void on_ParamtresButton_clicked();

private:
    Ui::MainWindow *ui;
=======
#include "events.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ajout_clicked();
    //bool on_delete_clicked();  // Function to delete event
    //bool on_update_clicked();


    void on_consulterProjet_2_clicked();

    void on_supp_clicked();

    void on_id_modif_textChanged(const QString &arg1);

    void on_modif_clicked();

private:
    Ui::MainWindow *ui;
    Event E;

>>>>>>> 5d6594f (Initial commit)
};

#endif // MAINWINDOW_H
