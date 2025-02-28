#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include "connexion.h"
#include <QTableWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_ajouter_clicked();
    void on_btnAfficherProjets_clicked();
    void on_delete_projet_clicked();
    void on_edit_projet_clicked();
    void on_listTodoButton_clicked();

private:
    Ui::MainWindow *ui;
    Connection cnx;

};

#endif // MAINWINDOW_H
