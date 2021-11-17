#ifndef LOGIN_H
#define LOGIN_H

#include <QStringList>
#include <vector>
#include <map>
#include <string>
#include "Chat.h"
#include "../../meta/ui_chatloginregister.h"
#include "../MessageClient.h"

using namespace std;

class LoginRegisterMainWindow: public QMainWindow, Ui::LoginRegisterMainWindow 
{
    Q_OBJECT
public:
    LoginRegisterMainWindow(QWidget *parent = 0);
    ~LoginRegisterMainWindow();
    
private slots:
    void loginClickedSlot();
    void registerClickedSlot();
};

#endif