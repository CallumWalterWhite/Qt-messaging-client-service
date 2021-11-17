#include "ClickableLabel.h"

ClickableLabel::~ClickableLabel() {
};

void ClickableLabel::mousePressEvent(QMouseEvent* event) 
{
    MessageEditor editor(_payloadId, messageClient, messageArrived);
    editor.buildMessage();
    editor.show();
    editor.exec();
    emit clicked();
}

void ClickableLabel::Setup(int payloadId, MessageClient* _messageClient)
{
    _payloadId = payloadId;
    messageClient = _messageClient;
};