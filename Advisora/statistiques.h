#ifndef STATISTIQUES_H
#define STATISTIQUES_H

#include <QDialog>
#include <QtCharts>
#include <QSqlQuery>
#include <QSqlError>
#include <QChartView>
#include <QBarSeries>
#include <QBarSet>
#include <QValueAxis>
#include <QBarCategoryAxis>

namespace Ui {
class Statistiques;
}

class Statistiques : public QDialog
{
    Q_OBJECT

public:
    explicit Statistiques(QWidget *parent = nullptr);
    ~Statistiques();

private:
    Ui::Statistiques *ui;  // Pointeur vers l'objet UI
};

#endif // STATISTIQUES_H
