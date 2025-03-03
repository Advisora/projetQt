#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QTableWidget>
#include <QtSql/QSqlQueryModel>
#include <QPdfWriter>
#include <QPainter>
#include <QSortFilterProxyModel>

// Ajout des inclusions pour QtCharts
#include <QtCharts/QChartView>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarSeries>
#include <QtCharts/QChart>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    // Navigation entre les pages
    void on_gestionClientsButton_clicked();
    void on_GestionEvenementsButton_clicked();
    void on_GestionProjetsButton_clicked();
    void on_GestionRessourcesButton_clicked();
    void on_GestionStrategiesButton_clicked();
    void on_GestionEmployeesButton_clicked();

    // Gestion des stratégies
    void loadData();
    void loadStrategyById(int id);
    void on_add_s_clicked();
    void on_del_s_clicked();
    void on_mod_s_clicked();
    void on_cher_nom_textChanged(const QString &text);
    //   void loadDataa();
    // Génération de statistiques
    void on_pdf_s_clicked();
    void on_tri_s_clicked();
    void on_stat_s_clicked();
    void updateLikesDisplay();

private:

    Ui::MainWindow *ui;
    QSqlDatabase db;  // Ajout pour éviter des problèmes de connexion répétée
    bool triAscendant = true;  // Indique si le tri est ascendant ou descendant
};
#endif // MAINWINDOW_H
