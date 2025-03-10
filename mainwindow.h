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
    // Navigation
    void on_gestionClientsButton_clicked();
    void on_GestionEvenementsButton_clicked();
    void on_GestionProjetsButton_clicked();
    void on_GestionRessourcesButton_clicked();
    void on_GestionStrategiesButton_clicked();
    void on_GestionEmployeesButton_clicked();
    QString generateRandomID();

    // Function to send the SMS
    void sendSMS(const QString &toPhoneNumber, const QString &nom, const QString &prenom);

    // Function to send SMS via Twilio API
    void sendNexmoSMS(const QString &toPhoneNumber, const QString &message);
    // Client Management
    void loadClients(); // ✅ Load clients automatically
    void on_refreshButton_clicked(); // ✅ Refresh clients
    void loadData();
    void on_trier_clicked();
    void on_modifierProjet_3_clicked();
    void on_cher_nom_textChanged(const QString &arg1);
    void on_modifierC_clicked();
    void on_input_textChanged(const QString &arg1);
    void on_supprimerC_clicked();
    void on_ajouterC_clicked();
    void loadClientById(int id);
    void on_loadClientById_clicked();
private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
    bool triAscendant = true;
};

#endif // MAINWINDOW_H
