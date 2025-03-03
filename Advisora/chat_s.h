#ifndef CHAT_S_H
#define CHAT_S_H

#include <QDialog>
#include <QNetworkAccessManager>
#include <QNetworkReply>

namespace Ui {
class chat_s;
}

class chat_s : public QDialog {
    Q_OBJECT

public:
    explicit chat_s(QWidget *parent = nullptr);
    ~chat_s();

private slots:
    void on_sendButton_clicked();  // Fonction pour envoyer le message
    void onReplyFinished(QNetworkReply *reply);  // Fonction pour traiter la réponse de l'API

private:
    Ui::chat_s *ui;
    QNetworkAccessManager *networkManager;  // Gestionnaire de requêtes
};

#endif // CHAT_S_H
