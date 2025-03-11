#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlQueryModel>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_11_clicked(); // Add resource
    void on_pushButton_18_clicked(); // Modify resource
    void on_deletebutt_clicked();    // Delete resource
    void on_searchbutt_clicked();    // Search resource
    void onResourcesTableViewClicked(const QModelIndex &index); // Handle table selection

private:
    Ui::MainWindow *ui;
    QSqlQueryModel *model;
    int selectedId;

    void loadResources(); // Load resources from the database
};

#endif // MAINWINDOW_H
