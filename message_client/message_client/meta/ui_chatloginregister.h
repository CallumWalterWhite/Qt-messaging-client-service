/********************************************************************************
** Form generated from reading UI file 'chatloginregister.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATLOGINREGISTER_H
#define UI_CHATLOGINREGISTER_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginRegisterMainWindow
{
public:
    QWidget *loginRegisterWindow;
    QWidget *topPanel;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QGroupBox *registerForm;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QLineEdit *usernameRegister;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_4;
    QLineEdit *emailAddressRegister;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QLineEdit *passwordRegister;
    QPushButton *registerBtn;
    QGroupBox *loginForm;
    QVBoxLayout *verticalLayout_9;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_7;
    QLineEdit *usernameLogin;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_8;
    QLineEdit *passwordLogin;
    QPushButton *loginBtn;

    void setupUi(QMainWindow *LoginRegisterMainWindow)
    {
        if (LoginRegisterMainWindow->objectName().isEmpty())
            LoginRegisterMainWindow->setObjectName(QString::fromUtf8("LoginRegisterMainWindow"));
        LoginRegisterMainWindow->setEnabled(true);
        LoginRegisterMainWindow->resize(1043, 751);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        LoginRegisterMainWindow->setWindowIcon(icon);
        LoginRegisterMainWindow->setAutoFillBackground(true);
        LoginRegisterMainWindow->setStyleSheet(QString::fromUtf8("loginRegisterWindow {\n"
"	background-color: rgb(0,128,128);\n"
"}"));
        loginRegisterWindow = new QWidget(LoginRegisterMainWindow);
        loginRegisterWindow->setObjectName(QString::fromUtf8("loginRegisterWindow"));
        loginRegisterWindow->setAutoFillBackground(false);
        loginRegisterWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(47,79,79);\n"
"color: rgb(255, 255, 255);"));
        topPanel = new QWidget(loginRegisterWindow);
        topPanel->setObjectName(QString::fromUtf8("topPanel"));
        topPanel->setGeometry(QRect(0, 0, 1101, 101));
        topPanel->setAutoFillBackground(false);
        topPanel->setStyleSheet(QString::fromUtf8(""));
        layoutWidget = new QWidget(topPanel);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(380, 10, 301, 81));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("Ubuntu Condensed"));
        font.setPointSize(48);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(label);

        registerForm = new QGroupBox(loginRegisterWindow);
        registerForm->setObjectName(QString::fromUtf8("registerForm"));
        registerForm->setGeometry(QRect(170, 250, 321, 281));
        QFont font1;
        font1.setPointSize(20);
        registerForm->setFont(font1);
        registerForm->setStyleSheet(QString::fromUtf8("#registerForm {\n"
"   border-radius: 10px\n"
"}"));
        verticalLayout_6 = new QVBoxLayout(registerForm);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_2 = new QLabel(registerForm);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font2;
        font2.setPointSize(14);
        label_2->setFont(font2);

        verticalLayout->addWidget(label_2);

        usernameRegister = new QLineEdit(registerForm);
        usernameRegister->setObjectName(QString::fromUtf8("usernameRegister"));
        usernameRegister->setFont(font2);

        verticalLayout->addWidget(usernameRegister);


        verticalLayout_6->addLayout(verticalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_4 = new QLabel(registerForm);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font2);

        verticalLayout_3->addWidget(label_4);

        emailAddressRegister = new QLineEdit(registerForm);
        emailAddressRegister->setObjectName(QString::fromUtf8("emailAddressRegister"));
        emailAddressRegister->setFont(font2);

        verticalLayout_3->addWidget(emailAddressRegister);


        verticalLayout_6->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_3 = new QLabel(registerForm);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font2);

        verticalLayout_2->addWidget(label_3);

        passwordRegister = new QLineEdit(registerForm);
        passwordRegister->setObjectName(QString::fromUtf8("passwordRegister"));
        passwordRegister->setFont(font2);
        passwordRegister->setEchoMode(QLineEdit::Password);

        verticalLayout_2->addWidget(passwordRegister);


        verticalLayout_6->addLayout(verticalLayout_2);

        registerBtn = new QPushButton(registerForm);
        registerBtn->setObjectName(QString::fromUtf8("registerBtn"));
        QFont font3;
        font3.setPointSize(18);
        registerBtn->setFont(font3);
        registerBtn->setStyleSheet(QString::fromUtf8("#registerBtn {\n"
"	background-color: rgb(255, 255, 255);\n"
"	border-width:0px;\n"
"	border-radius:4px;\n"
"	color: black;\n"
"}\n"
"\n"
"#registerBtn:hover {\n"
"\n"
"	background-color: rgb(32, 74, 135);\n"
"	color: white;\n"
"\n"
"}"));

        verticalLayout_6->addWidget(registerBtn);

        loginForm = new QGroupBox(loginRegisterWindow);
        loginForm->setObjectName(QString::fromUtf8("loginForm"));
        loginForm->setGeometry(QRect(560, 250, 321, 281));
        loginForm->setFont(font3);
        loginForm->setStyleSheet(QString::fromUtf8("#loginForm {\n"
"   border-radius: 10px\n"
"}"));
        verticalLayout_9 = new QVBoxLayout(loginForm);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        label_7 = new QLabel(loginForm);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font2);

        verticalLayout_7->addWidget(label_7);

        usernameLogin = new QLineEdit(loginForm);
        usernameLogin->setObjectName(QString::fromUtf8("usernameLogin"));
        usernameLogin->setFont(font2);

        verticalLayout_7->addWidget(usernameLogin);


        verticalLayout_9->addLayout(verticalLayout_7);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        label_8 = new QLabel(loginForm);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font2);

        verticalLayout_8->addWidget(label_8);

        passwordLogin = new QLineEdit(loginForm);
        passwordLogin->setObjectName(QString::fromUtf8("passwordLogin"));
        passwordLogin->setFont(font2);
        passwordLogin->setEchoMode(QLineEdit::Password);

        verticalLayout_8->addWidget(passwordLogin);


        verticalLayout_9->addLayout(verticalLayout_8);

        loginBtn = new QPushButton(loginForm);
        loginBtn->setObjectName(QString::fromUtf8("loginBtn"));
        loginBtn->setFont(font3);
        loginBtn->setStyleSheet(QString::fromUtf8("#loginBtn {\n"
"	background-color: rgb(255, 255, 255);\n"
"	border-width:0px;\n"
"	border-radius:4px;\n"
"	color: black;\n"
"}\n"
"\n"
"#loginBtn:hover {\n"
"	background-color: rgb(32, 74, 135);\n"
"	color: white;\n"
"\n"
"}"));

        verticalLayout_9->addWidget(loginBtn);

        LoginRegisterMainWindow->setCentralWidget(loginRegisterWindow);

        retranslateUi(LoginRegisterMainWindow);

        QMetaObject::connectSlotsByName(LoginRegisterMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *LoginRegisterMainWindow)
    {
        LoginRegisterMainWindow->setWindowTitle(QApplication::translate("LoginRegisterMainWindow", "ChatApp", nullptr));
        label->setText(QApplication::translate("LoginRegisterMainWindow", "Chat App", nullptr));
        registerForm->setTitle(QApplication::translate("LoginRegisterMainWindow", "Register", nullptr));
        label_2->setText(QApplication::translate("LoginRegisterMainWindow", "Username", nullptr));
        label_4->setText(QApplication::translate("LoginRegisterMainWindow", "Email", nullptr));
        label_3->setText(QApplication::translate("LoginRegisterMainWindow", "Password", nullptr));
        registerBtn->setText(QApplication::translate("LoginRegisterMainWindow", "Register", nullptr));
        loginForm->setTitle(QApplication::translate("LoginRegisterMainWindow", "Login", nullptr));
        label_7->setText(QApplication::translate("LoginRegisterMainWindow", "Username", nullptr));
        label_8->setText(QApplication::translate("LoginRegisterMainWindow", "Password", nullptr));
        loginBtn->setText(QApplication::translate("LoginRegisterMainWindow", "Login", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginRegisterMainWindow: public Ui_LoginRegisterMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATLOGINREGISTER_H
