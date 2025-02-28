#ifndef LISTPROJET_H
#define LISTPROJET_H

#include <QDialog>

namespace Ui {
class listprojet;  // Déclaration de la classe UI
}

class listprojet : public QDialog
{
    Q_OBJECT

public:
    explicit listprojet(QWidget *parent = nullptr);
    ~listprojet();

private:
    Ui::listprojet *ui;
};

#endif // LISTPROJET_H
