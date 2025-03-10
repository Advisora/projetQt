#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "events.h"
#include <QMessageBox>
#include <QSqlRecord>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Assuming `model` is already declared as QSqlQueryModel* model
    QSqlQueryModel *model = E.showEventsList();  // Assuming `E` is your Event class instance
    ui->tableView->setModel(E.showEventsList());
    // Check if the model is valid
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ajout_clicked()
{
    // Retrieve values from the UI (assuming you have corresponding input fields)
    int id = 1;
    QString date = ui->dateEdit->text();
    QString name = ui->nameLineEdit->text().trimmed();
    double price = ui->priceLineEdit->text().toDouble();
    QString location = ui->locationLineEdit->text().trimmed();
    int maxNb = ui->maxNbLineEdit->text().toInt();
    QString duration = ui->durationLineEdit->text().trimmed();

    // Validation conditions before adding the event

    if (id <= 0) {
        QMessageBox::warning(this, "Invalid Input", "ID must be a positive number.");
        return;
    }

    if (name.isEmpty()) {
        QMessageBox::warning(this, "Invalid Input", "Event name cannot be empty.");
        return;
    }

    if (price < 0) {
        QMessageBox::warning(this, "Invalid Input", "SET THE PRICE.");
        return;
    }

    if (location.isEmpty()) {
        QMessageBox::warning(this, "Invalid Input", "Location cannot be empty.");
        return;
    }

    if (maxNb <= 0) {
        QMessageBox::warning(this, "Invalid Input", "Maximum number must be greater than zero.");
        return;
    }

    if (duration.isEmpty()) {
        QMessageBox::warning(this, "Invalid Input", "Duration cannot be empty.");
        return;
    }

    // Date validation (assuming MM/dd/yyyy format)
    //QDate validDate = QDate::fromString(date, "MM/dd/yyyy");  // Ensure correct format
    //QDate today = QDate::currentDate();  // Get today's date

    //if (!validDate.isValid() || validDate < today) {
      //  QMessageBox::warning(this, "Invalid Input", "Please enter today's date or a future date in MM/DD/YYYY format.");
        //return;
    //}

    // Add event if all validations pass
    if (E.addEvent(id, date, name, price, location, maxNb, duration)) {
        QMessageBox::information(this, "Success", "Event added successfully!");
            ui->tableView->setModel(E.showEventsList());
    } else {
        QMessageBox::critical(this, "Error", "Error adding the event!");
    }
}

/*void MainWindow::on_delete_clicked() {
    int id = ui->idLineEditDelete->text().toInt();  // Get ID from input field

    if (id <= 0) {  // Ensure valid ID
        QMessageBox::warning(this, "Invalid Input", "Please enter a valid event ID.");
        return;
    }

    // Confirm deletion
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Confirm Deletion",
                                  "Are you sure you want to delete this event?",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        if (E.deleteEvent(id)) {  // Call the delete function from `events.cpp`
            QMessageBox::information(this, "Success", "Event deleted successfully!");
        } else {
            QMessageBox::critical(this, "Error", "Failed to delete the event. Please check the ID.");
        }
    }
}
*/


/*bool MainWindow::on_update_clicked() {
    int id = ui->idLineEdit->text().toInt();
    QString date = ui->dateEdit->text();
    QString name = ui->nameLineEdit->text();
    double price = ui->priceLineEdit->text().toDouble();
    QString location = ui->locationLineEdit->text();
    int maxNb = ui->maxNbLineEdit->text().toInt();
    QString duration = ui->durationLineEdit->text();

    if (id <= 0) {
        QMessageBox::warning(this, "Invalid Input", "Please enter a valid event ID.");
        return;
    }

    if (E.updateEvent(id, date, name, price, location, maxNb, duration)) {
        QMessageBox::information(this, "Success", "Event updated successfully!");
    } else {
        QMessageBox::critical(this, "Error", "Failed to update the event.");
    }

    // Refresh the table
    QSqlQueryModel *model = E.showEventsList();
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(model->rowCount());
    ui->tableWidget->setColumnCount(model->columnCount());

    for (int i = 0; i < model->rowCount(); ++i) {
        for (int j = 0; j < model->columnCount(); ++j) {
            ui->tableWidget->setItem(i, j, new QTableWidgetItem(model->record(i).value(j).toString()));
        }
    }
}*/



void MainWindow::on_consulterProjet_2_clicked()
{
        ui->tableView->setModel(E.showEventsList());
}


void MainWindow::on_supp_clicked()
{
    int id = ui->supp_line->text().toInt(); // Get ID from input field

    if (id <= 0) { // Ensure ID is valid
        QMessageBox::warning(this, "Invalid ID", "Please enter a valid event ID.");
        return;
    }

    // Call delete function
    if (E.deleteEvent(id)) {
        QMessageBox::information(this, "Success", "Event deleted successfully!");
            ui->tableView->setModel(E.showEventsList());
    } else {
        QMessageBox::critical(this, "Error", "Failed to delete the event. ID may not exist.");
    }
}


void MainWindow::on_id_modif_textChanged(const QString &arg1)
{
    int id = arg1.toInt(); // Convert text input to an integer

    if (id <= 0) { // Ensure the ID is valid
        return;
    }

    QSqlQueryModel* model = E.loadEventForEdit(id); // Call the function

    if (model && model->rowCount() > 0) {
        // Set values from the first row of the model
        ui->id_modif->setText(model->record(0).value("IDEV").toString());
        ui->dateEdit_5->setDate(QDate::fromString(model->record(0).value("DATEEV").toString(), "MM/dd/yyyy"));
        ui->nameLineEdit_5->setText(model->record(0).value("NOMEV").toString());
        ui->priceLineEdit_5->setText(QString::number(model->record(0).value("PRIXEV").toDouble()));
        ui->locationLineEdit_5->setText(model->record(0).value("LOCALISATIONEV").toString());
        ui->maxNbLineEdit_5->setText(QString::number(model->record(0).value("NBMAXEV").toInt()));
        ui->durationLineEdit_5->setText(model->record(0).value("DUREEEV").toString());
    } else {
        QMessageBox::warning(this, "Error", "Event not found!");
    }

    delete model; // Clean up dynamically allocated model
}


void MainWindow::on_modif_clicked()
{
    // Retrieve values from UI input fields
    int id = ui->id_modif->text().toInt();
    QString date = ui->dateEdit_5->text();
    QString name = ui->nameLineEdit_5->text();
    double price = ui->priceLineEdit_5->text().toDouble();
    QString location = ui->locationLineEdit_5->text();
    int maxNb = ui->maxNbLineEdit_5->text().toInt();
    QString duration = ui->durationLineEdit_5->text();

    // Check if ID is valid
    if (id <= 0) {
        QMessageBox::warning(this, "Invalid Input", "Please enter a valid Event ID.");
        return;
    }

    // Call the update function
    if (E.updateEvent(id, date, name, price, location, maxNb, duration)) {
        QMessageBox::information(this, "Success", "Event updated successfully!");
          ui->tableView->setModel(E.showEventsList());
    } else {
        QMessageBox::critical(this, "Error", "Failed to update the event.");
    }
}
