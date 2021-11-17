#ifndef CLICKABLELABEL_H
#define CLICKABLELABEL_H

#include <QApplication>
#include "../../meta/ui_chatmainwindow.h"
#include "MessageEditor.h"
#include "../MessageClient.h"

class ClickableLabel : public QLabel { 
    Q_OBJECT 

    int _payloadId;
public:
    MessageClient* messageClient;
    MessageArrived &messageArrived;
    ClickableLabel(MessageArrived &messageArrived_) : messageArrived(messageArrived_), QLabel(Q_NULLPTR)
    {

    };
    ~ClickableLabel();

signals:
    void clicked();

public:
    void Setup(int payloadId, MessageClient* _messageClient);

protected:
    void mousePressEvent(QMouseEvent* event);

};

#endif