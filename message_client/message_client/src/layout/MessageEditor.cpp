#include <iostream>
#include <string>
#include "MessageEditor.h"
#include <QStringList>
#include "../../../../message_common/src/DatabaseAdapter.h"

using namespace std;

static string QStringtoString(QString qstring)
{
    string str = qstring.toUtf8().constData();
    return str;
};

MessageEditor::MessageEditor(int payloadId, MessageClient* _messageClient, MessageArrived &messageArrived_) 
    : _payloadId(payloadId), messageClient(_messageClient), messageArrived(&messageArrived_)
{
    setupUi(this);
    connect(messageEditor_updateButton, SIGNAL(clicked(bool)), this, SLOT(updateButtonSlot()));
    connect(messageEditor_cancelButton, SIGNAL(clicked(bool)), this, SLOT(cancelButtonSlot()));
    connect(messageEditor_deleteButton, SIGNAL(clicked(bool)), this, SLOT(deleteButtonSlot()));
};

MessageEditor::~MessageEditor()
{
};

void MessageEditor::buildMessage()
{
    DatabaseAdapter adapter;
    Payload payload = adapter.GetPayloadById(_payloadId);
    string payloadMessage = payload.GetPayloadMessage();
    QString payloadQString = QString::fromStdString(payloadMessage);
    messageEditor_text->setText(payloadQString);
};

void MessageEditor::updateButtonSlot()
{
    DatabaseAdapter adapter;
    Payload payload = adapter.GetPayloadById(_payloadId);
    QString qsMessage = messageEditor_text->toPlainText();
    string textMessage = QStringtoString(qsMessage);
    Payload updateplayload(textMessage, payload.GetTopicId(), messageClient->UserId, "update"); 
    updateplayload.SetId(_payloadId);
    adapter.UpdatePayloadMessage(_payloadId, textMessage);
    messageClient->DirectMessage(updateplayload);
    messageArrived->recieveAction(_payloadId, "update");
    cout << "update" << endl;
    this->hide();
};

void MessageEditor::deleteButtonSlot()
{
    DatabaseAdapter adapter;
    Payload payload = adapter.GetPayloadById(_payloadId);
    QString qsMessage = messageEditor_text->toPlainText();
    string textMessage = QStringtoString(qsMessage);
    Payload updateplayload(textMessage, payload.GetTopicId(), messageClient->UserId, "update"); 
    updateplayload.SetId(_payloadId);
    adapter.DeletePayload(_payloadId);
    messageClient->DirectMessage(updateplayload);
    messageArrived->recieveAction(_payloadId, "update");
    this->hide();
};

void MessageEditor::cancelButtonSlot()
{
    this->hide();
};