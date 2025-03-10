#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
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

};

#endif // MAINWINDOW_H
