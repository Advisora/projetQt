/* mainwindow.cpp */
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>
#include <QDebug>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QFileDialog>
#include "stat_pdf_s.h"

using namespace QtCharts;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    loadData();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::loadData() {
    QSqlQuery query("SELECT IDSTRG, NOMSTRG, TYPESTRG, PRIXSTRG, DESCRIPTIONSTRG, NBRE_S, DATESTRG FROM STRATEGIES");
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery(query);
    ui->strategiesView->setModel(model);
}

void MainWindow::on_stat_s_clicked() {
    generateStatistics();
}

void MainWindow::generateStatistics() {
    QSqlQuery query("SELECT DATESTRG, COUNT(*) FROM STRATEGIES GROUP BY DATESTRG");
    QBarSeries *series = new QBarSeries();
    QBarSet *set = new QBarSet("Strategies");
    QStringList categories;

    while (query.next()) {
        categories << query.value(0).toString();
        *set << query.value(1).toInt();
    }

    series->append(set);
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Nombre de stratégies par date");

    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->resize(600, 400);
    chartView->show();
}

void MainWindow::on_pdf_s_clicked() {
    generatePDF();
}

void MainWindow::generatePDF() {
    QString fileName = QFileDialog::getSaveFileName(this, "Save PDF", "strategies.pdf", "PDF Files (*.pdf)");
    if (fileName.isEmpty()) return;

    QPdfWriter writer(fileName);
    writer.setPageSize(QPageSize(QPageSize::A4));
    QPainter painter(&writer);

    QSqlQuery query;
    if (ui->cher_nom->text().isEmpty()) {
        query.prepare("SELECT * FROM STRATEGIES");
    } else {
        query.prepare("SELECT * FROM STRATEGIES WHERE IDSTRG = :id");
        query.bindValue(":id", ui->cher_nom->text().toInt());
    }
    query.exec();

    int y = 100;
    painter.setFont(QFont("Arial", 12));
    painter.drawText(100, y, "ID    Nom    Type    Prix    Description    Nbre_S    Date");
    y += 30;

    while (query.next()) {
        QString row = QString("%1    %2    %3    %4    %5    %6    %7")
        .arg(query.value(0).toString())
            .arg(query.value(1).toString())
            .arg(query.value(2).toString())
            .arg(query.value(3).toString())
            .arg(query.value(4).toString())
            .arg(query.value(5).toString())
            .arg(query.value(6).toString());
        painter.drawText(100, y, row);
        y += 30;
    }

    painter.end();
    QMessageBox::information(this, "Succès", "Le PDF a été généré avec succès!");
}
