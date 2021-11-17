#ifndef MESSAGEDITOR_H
#define MESSAGEDITOR_H

#include "../../meta/ui_chatmessageeditor.h"
#include "../MessageClient.h"
#include "MessageArrived.h"

class MessageEditor: public QDialog, Ui::ChatMessageEditor 
{
    Q_OBJECT
public:
    MessageClient* messageClient;
    MessageArrived* messageArrived;
    MessageEditor(int payloadId, MessageClient* _messageClient, MessageArrived &messageArrived_);
    ~MessageEditor();
private:
    int _payloadId;
public:
    void buildMessage();
private slots:
    void updateButtonSlot();
    void cancelButtonSlot();
    void deleteButtonSlot();

};

#endif