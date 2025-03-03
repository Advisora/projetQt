#include "chat_s.h"
#include "ui_chat_s.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QMessageBox>

#define OPENAI_API_KEY "TA_CLE_API_ICI"  // Remplace par ta clé API OpenAI

chat_s::chat_s(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::chat_s),
    networkManager(new QNetworkAccessManager(this)) {

    ui->setupUi(this);
    connect(networkManager, &QNetworkAccessManager::finished, this, &chat_s::onReplyFinished);
}

chat_s::~chat_s() {
    delete ui;
}

// Fonction appelée quand on clique sur "Envoyer"
void chat_s::on_sendButton_clicked() {
    QString userMessage = ui->inputText->text().trimmed(); // Récupérer le texte entré
    if (userMessage.isEmpty()) return;

    // Afficher le message de l'utilisateur dans la zone de chat
    ui->chatBox->append("<b>Vous :</b> " + userMessage);
    ui->inputText->clear();

    // Préparer la requête API
    QUrl url("https://api.openai.com/v1/chat/completions");
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader("Authorization", "Bearer " OPENAI_API_KEY);

    // Construire le JSON pour la requête
    QJsonObject json;
    json["model"] = "gpt-3.5-turbo";
    QJsonArray messages;
    messages.append(QJsonObject{{"role", "system"}, {"content", "Tu es un assistant intelligent."}});
    messages.append(QJsonObject{{"role", "user"}, {"content", userMessage}});
    json["messages"] = messages;
    json["temperature"] = 0.7;

    // Envoyer la requête
    QJsonDocument doc(json);
    networkManager->post(request, doc.toJson());
}

// Fonction pour traiter la réponse de l'API
void chat_s::onReplyFinished(QNetworkReply *reply) {
    if (reply->error() != QNetworkReply::NoError) {
        QMessageBox::warning(this, "Erreur", "Impossible d'obtenir une réponse.");
        return;
    }

    QByteArray responseData = reply->readAll();
    QJsonDocument doc = QJsonDocument::fromJson(responseData);
    QJsonObject jsonObj = doc.object();

    if (jsonObj.contains("choices")) {
        QJsonArray choices = jsonObj["choices"].toArray();
        if (!choices.isEmpty()) {
            QString botResponse = choices.first().toObject()["message"].toObject()["content"].toString();
            ui->chatBox->append("<b>Bot :</b> " + botResponse);
        }
    }

    reply->deleteLater();
}
