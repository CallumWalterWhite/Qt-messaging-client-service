/********************************************************************************
** Form generated from reading UI file 'chatmainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATMAINWINDOW_H
#define UI_CHATMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatMainWindow
{
public:
    QAction *actionQuit;
    QAction *actionAboutQt;
    QAction *actionChangeNickname;
    QWidget *centralwidget;
    QHBoxLayout *hboxLayout;
    QWidget *messageWindow;
    QWidget *layoutWidget;
    QVBoxLayout *messageLayout;
    QScrollArea *scrollArea;
    QWidget *messageScrollArea_widget;
    QHBoxLayout *_4;
    QLabel *label;
    QLineEdit *messageLineEdit;
    QPushButton *sendButton;
    QLabel *concurrentUsername;
    QComboBox *messageSortComboBox;
    QLabel *concurrentUserImageURL_label;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QListWidget *userList;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *Titlt;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *loggedInUsername;
    QHBoxLayout *userImage_layout;
    QLabel *userImageURL_label;
    QPushButton *reportButton;
    QPushButton *settingsButton;
    QLabel *Titlt_2;
    QLineEdit *userListSearch;
    QPushButton *userListSearch_button;
    QWidget *settingPorfileWidget;
    QGroupBox *registerForm_6;
    QVBoxLayout *verticalLayout_34;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_38;
    QVBoxLayout *verticalLayout_36;
    QVBoxLayout *verticalLayout_37;
    QLabel *label_35;
    QLineEdit *usernameSettings;
    QVBoxLayout *verticalLayout_35;
    QLabel *label_34;
    QLineEdit *firstnameSettings;
    QVBoxLayout *verticalLayout_38;
    QVBoxLayout *verticalLayout_40;
    QLabel *label_39;
    QLineEdit *lastnameSettings;
    QLabel *label_36;
    QLineEdit *emailaddressSettings;
    QVBoxLayout *verticalLayout_41;
    QLabel *label_40;
    QLineEdit *imageURLSettings;
    QPushButton *updateSettings;
    QWidget *reportWidget;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_4;
    QTabWidget *tabWidget;
    QWidget *tab;
    QTableView *report_messagePerDay_Table;
    QWidget *tab_2;
    QTableView *report_mostSentMessages_Table;
    QLabel *label_46;

    void setupUi(QDialog *ChatMainWindow)
    {
        if (ChatMainWindow->objectName().isEmpty())
            ChatMainWindow->setObjectName(QString::fromUtf8("ChatMainWindow"));
        ChatMainWindow->resize(1088, 779);
        ChatMainWindow->setAutoFillBackground(false);
        ChatMainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(47,79,79);\n"
"color: white;"));
        actionQuit = new QAction(ChatMainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        actionAboutQt = new QAction(ChatMainWindow);
        actionAboutQt->setObjectName(QString::fromUtf8("actionAboutQt"));
        actionChangeNickname = new QAction(ChatMainWindow);
        actionChangeNickname->setObjectName(QString::fromUtf8("actionChangeNickname"));
        centralwidget = new QWidget(ChatMainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setGeometry(QRect(170, 80, 901, 671));
        hboxLayout = new QHBoxLayout(centralwidget);
        hboxLayout->setSpacing(6);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        hboxLayout->setContentsMargins(9, 9, 9, 9);
        messageWindow = new QWidget(centralwidget);
        messageWindow->setObjectName(QString::fromUtf8("messageWindow"));
        messageWindow->setEnabled(true);
        layoutWidget = new QWidget(messageWindow);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 70, 851, 581));
        messageLayout = new QVBoxLayout(layoutWidget);
        messageLayout->setSpacing(6);
        messageLayout->setObjectName(QString::fromUtf8("messageLayout"));
        messageLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(layoutWidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setWidgetResizable(true);
        messageScrollArea_widget = new QWidget();
        messageScrollArea_widget->setObjectName(QString::fromUtf8("messageScrollArea_widget"));
        messageScrollArea_widget->setGeometry(QRect(0, 0, 847, 546));
        scrollArea->setWidget(messageScrollArea_widget);

        messageLayout->addWidget(scrollArea);

        _4 = new QHBoxLayout();
        _4->setSpacing(6);
        _4->setObjectName(QString::fromUtf8("_4"));
        _4->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        _4->addWidget(label);

        messageLineEdit = new QLineEdit(layoutWidget);
        messageLineEdit->setObjectName(QString::fromUtf8("messageLineEdit"));
        messageLineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));

        _4->addWidget(messageLineEdit);

        sendButton = new QPushButton(layoutWidget);
        sendButton->setObjectName(QString::fromUtf8("sendButton"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(sendButton->sizePolicy().hasHeightForWidth());
        sendButton->setSizePolicy(sizePolicy);

        _4->addWidget(sendButton);


        messageLayout->addLayout(_4);

        concurrentUsername = new QLabel(messageWindow);
        concurrentUsername->setObjectName(QString::fromUtf8("concurrentUsername"));
        concurrentUsername->setEnabled(true);
        concurrentUsername->setGeometry(QRect(0, 10, 81, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font.setPointSize(8);
        font.setBold(true);
        font.setWeight(75);
        concurrentUsername->setFont(font);
        concurrentUsername->setAutoFillBackground(false);
        concurrentUsername->setStyleSheet(QString::fromUtf8("text-align:center"));
        messageSortComboBox = new QComboBox(messageWindow);
        messageSortComboBox->setObjectName(QString::fromUtf8("messageSortComboBox"));
        messageSortComboBox->setGeometry(QRect(730, 10, 131, 21));
        messageSortComboBox->setEditable(false);
        concurrentUserImageURL_label = new QLabel(messageWindow);
        concurrentUserImageURL_label->setObjectName(QString::fromUtf8("concurrentUserImageURL_label"));
        concurrentUserImageURL_label->setGeometry(QRect(100, 0, 71, 61));

        hboxLayout->addWidget(messageWindow);

        horizontalLayoutWidget = new QWidget(ChatMainWindow);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 140, 151, 471));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        userList = new QListWidget(horizontalLayoutWidget);
        userList->setObjectName(QString::fromUtf8("userList"));

        horizontalLayout->addWidget(userList);

        horizontalLayoutWidget_2 = new QWidget(ChatMainWindow);
        horizontalLayoutWidget_2->setObjectName(QString::fromUtf8("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(-1, 0, 401, 80));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        Titlt = new QLabel(horizontalLayoutWidget_2);
        Titlt->setObjectName(QString::fromUtf8("Titlt"));
        Titlt->setEnabled(true);
        QFont font1;
        font1.setFamily(QString::fromUtf8("MS Shell Dlg 2"));
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setWeight(75);
        Titlt->setFont(font1);
        Titlt->setAutoFillBackground(false);
        Titlt->setStyleSheet(QString::fromUtf8("text-align:center"));

        horizontalLayout_2->addWidget(Titlt);

        verticalLayoutWidget = new QWidget(ChatMainWindow);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 610, 161, 129));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        loggedInUsername = new QLabel(verticalLayoutWidget);
        loggedInUsername->setObjectName(QString::fromUtf8("loggedInUsername"));
        loggedInUsername->setEnabled(true);
        loggedInUsername->setFont(font);
        loggedInUsername->setAutoFillBackground(false);
        loggedInUsername->setStyleSheet(QString::fromUtf8("text-align:center"));

        horizontalLayout_3->addWidget(loggedInUsername);

        userImage_layout = new QHBoxLayout();
        userImage_layout->setObjectName(QString::fromUtf8("userImage_layout"));
        userImageURL_label = new QLabel(verticalLayoutWidget);
        userImageURL_label->setObjectName(QString::fromUtf8("userImageURL_label"));
        userImageURL_label->setAutoFillBackground(false);

        userImage_layout->addWidget(userImageURL_label);


        horizontalLayout_3->addLayout(userImage_layout);


        verticalLayout->addLayout(horizontalLayout_3);

        reportButton = new QPushButton(verticalLayoutWidget);
        reportButton->setObjectName(QString::fromUtf8("reportButton"));

        verticalLayout->addWidget(reportButton);

        settingsButton = new QPushButton(verticalLayoutWidget);
        settingsButton->setObjectName(QString::fromUtf8("settingsButton"));

        verticalLayout->addWidget(settingsButton);

        Titlt_2 = new QLabel(ChatMainWindow);
        Titlt_2->setObjectName(QString::fromUtf8("Titlt_2"));
        Titlt_2->setEnabled(true);
        Titlt_2->setGeometry(QRect(10, 90, 101, 21));
        Titlt_2->setFont(font);
        Titlt_2->setAutoFillBackground(false);
        Titlt_2->setStyleSheet(QString::fromUtf8("text-align:center"));
        userListSearch = new QLineEdit(ChatMainWindow);
        userListSearch->setObjectName(QString::fromUtf8("userListSearch"));
        userListSearch->setGeometry(QRect(10, 110, 91, 20));
        userListSearch->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"color: rgb(0, 0, 0);"));
        userListSearch_button = new QPushButton(ChatMainWindow);
        userListSearch_button->setObjectName(QString::fromUtf8("userListSearch_button"));
        userListSearch_button->setGeometry(QRect(110, 110, 51, 23));
        sizePolicy.setHeightForWidth(userListSearch_button->sizePolicy().hasHeightForWidth());
        userListSearch_button->setSizePolicy(sizePolicy);
        settingPorfileWidget = new QWidget(ChatMainWindow);
        settingPorfileWidget->setObjectName(QString::fromUtf8("settingPorfileWidget"));
        settingPorfileWidget->setGeometry(QRect(270, 155, 711, 491));
        registerForm_6 = new QGroupBox(settingPorfileWidget);
        registerForm_6->setObjectName(QString::fromUtf8("registerForm_6"));
        registerForm_6->setGeometry(QRect(0, 0, 711, 491));
        QFont font2;
        font2.setPointSize(20);
        registerForm_6->setFont(font2);
        registerForm_6->setStyleSheet(QString::fromUtf8("#registerForm {\n"
"\n"
"	background-color: rgb(243, 243, 243);\n"
"   border-radius: 10px\n"
"}"));
        verticalLayout_34 = new QVBoxLayout(registerForm_6);
        verticalLayout_34->setObjectName(QString::fromUtf8("verticalLayout_34"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_38 = new QLabel(registerForm_6);
        label_38->setObjectName(QString::fromUtf8("label_38"));
        QFont font3;
        font3.setPointSize(20);
        font3.setBold(true);
        font3.setWeight(75);
        label_38->setFont(font3);

        verticalLayout_2->addWidget(label_38);


        verticalLayout_34->addLayout(verticalLayout_2);

        verticalLayout_36 = new QVBoxLayout();
        verticalLayout_36->setObjectName(QString::fromUtf8("verticalLayout_36"));
        verticalLayout_37 = new QVBoxLayout();
        verticalLayout_37->setObjectName(QString::fromUtf8("verticalLayout_37"));
        label_35 = new QLabel(registerForm_6);
        label_35->setObjectName(QString::fromUtf8("label_35"));
        QFont font4;
        font4.setPointSize(14);
        label_35->setFont(font4);

        verticalLayout_37->addWidget(label_35);

        usernameSettings = new QLineEdit(registerForm_6);
        usernameSettings->setObjectName(QString::fromUtf8("usernameSettings"));
        usernameSettings->setFont(font4);

        verticalLayout_37->addWidget(usernameSettings);


        verticalLayout_36->addLayout(verticalLayout_37);

        verticalLayout_35 = new QVBoxLayout();
        verticalLayout_35->setObjectName(QString::fromUtf8("verticalLayout_35"));
        label_34 = new QLabel(registerForm_6);
        label_34->setObjectName(QString::fromUtf8("label_34"));
        label_34->setFont(font4);

        verticalLayout_35->addWidget(label_34);

        firstnameSettings = new QLineEdit(registerForm_6);
        firstnameSettings->setObjectName(QString::fromUtf8("firstnameSettings"));
        firstnameSettings->setFont(font4);

        verticalLayout_35->addWidget(firstnameSettings);


        verticalLayout_36->addLayout(verticalLayout_35);

        verticalLayout_38 = new QVBoxLayout();
        verticalLayout_38->setObjectName(QString::fromUtf8("verticalLayout_38"));
        verticalLayout_40 = new QVBoxLayout();
        verticalLayout_40->setObjectName(QString::fromUtf8("verticalLayout_40"));
        label_39 = new QLabel(registerForm_6);
        label_39->setObjectName(QString::fromUtf8("label_39"));
        label_39->setFont(font4);

        verticalLayout_40->addWidget(label_39);

        lastnameSettings = new QLineEdit(registerForm_6);
        lastnameSettings->setObjectName(QString::fromUtf8("lastnameSettings"));
        lastnameSettings->setFont(font4);

        verticalLayout_40->addWidget(lastnameSettings);


        verticalLayout_38->addLayout(verticalLayout_40);

        label_36 = new QLabel(registerForm_6);
        label_36->setObjectName(QString::fromUtf8("label_36"));
        label_36->setFont(font4);

        verticalLayout_38->addWidget(label_36);

        emailaddressSettings = new QLineEdit(registerForm_6);
        emailaddressSettings->setObjectName(QString::fromUtf8("emailaddressSettings"));
        emailaddressSettings->setFont(font4);

        verticalLayout_38->addWidget(emailaddressSettings);

        verticalLayout_41 = new QVBoxLayout();
        verticalLayout_41->setObjectName(QString::fromUtf8("verticalLayout_41"));
        label_40 = new QLabel(registerForm_6);
        label_40->setObjectName(QString::fromUtf8("label_40"));
        label_40->setFont(font4);

        verticalLayout_41->addWidget(label_40);

        imageURLSettings = new QLineEdit(registerForm_6);
        imageURLSettings->setObjectName(QString::fromUtf8("imageURLSettings"));
        imageURLSettings->setFont(font4);

        verticalLayout_41->addWidget(imageURLSettings);


        verticalLayout_38->addLayout(verticalLayout_41);


        verticalLayout_36->addLayout(verticalLayout_38);


        verticalLayout_34->addLayout(verticalLayout_36);

        updateSettings = new QPushButton(registerForm_6);
        updateSettings->setObjectName(QString::fromUtf8("updateSettings"));
        QFont font5;
        font5.setPointSize(18);
        updateSettings->setFont(font5);
        updateSettings->setStyleSheet(QString::fromUtf8("#loginBtn {\n"
"\n"
"	color: white;\n"
"	background-color: rgb(114, 159, 207);\n"
"	border-width:0px;\n"
"	border-radius:4px;\n"
"}\n"
"\n"
"#loginBtn:hover {\n"
"\n"
"	background-color: rgb(32, 74, 135);\n"
"\n"
"}"));

        verticalLayout_34->addWidget(updateSettings);

        reportWidget = new QWidget(ChatMainWindow);
        reportWidget->setObjectName(QString::fromUtf8("reportWidget"));
        reportWidget->setGeometry(QRect(270, 155, 711, 491));
        layoutWidget_2 = new QWidget(reportWidget);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(0, 60, 711, 431));
        verticalLayout_4 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(layoutWidget_2);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        report_messagePerDay_Table = new QTableView(tab);
        report_messagePerDay_Table->setObjectName(QString::fromUtf8("report_messagePerDay_Table"));
        report_messagePerDay_Table->setGeometry(QRect(0, 0, 711, 411));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        report_mostSentMessages_Table = new QTableView(tab_2);
        report_mostSentMessages_Table->setObjectName(QString::fromUtf8("report_mostSentMessages_Table"));
        report_mostSentMessages_Table->setGeometry(QRect(0, 0, 711, 411));
        tabWidget->addTab(tab_2, QString());

        verticalLayout_4->addWidget(tabWidget);

        label_46 = new QLabel(reportWidget);
        label_46->setObjectName(QString::fromUtf8("label_46"));
        label_46->setGeometry(QRect(10, 10, 121, 41));
        label_46->setFont(font3);
#ifndef QT_NO_SHORTCUT
        label->setBuddy(messageLineEdit);
#endif // QT_NO_SHORTCUT

        retranslateUi(ChatMainWindow);
        QObject::connect(actionQuit, SIGNAL(triggered(bool)), ChatMainWindow, SLOT(close()));

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(ChatMainWindow);
    } // setupUi

    void retranslateUi(QDialog *ChatMainWindow)
    {
        ChatMainWindow->setWindowTitle(QApplication::translate("ChatMainWindow", "ChatApp", nullptr));
        actionQuit->setText(QApplication::translate("ChatMainWindow", "Quit", nullptr));
#ifndef QT_NO_SHORTCUT
        actionQuit->setShortcut(QApplication::translate("ChatMainWindow", "Ctrl+Q", nullptr));
#endif // QT_NO_SHORTCUT
        actionAboutQt->setText(QApplication::translate("ChatMainWindow", "About Qt...", nullptr));
        actionChangeNickname->setText(QApplication::translate("ChatMainWindow", "Change nickname...", nullptr));
#ifndef QT_NO_SHORTCUT
        actionChangeNickname->setShortcut(QApplication::translate("ChatMainWindow", "Ctrl+N", nullptr));
#endif // QT_NO_SHORTCUT
        label->setText(QApplication::translate("ChatMainWindow", "Message:", nullptr));
#ifndef QT_NO_TOOLTIP
        sendButton->setToolTip(QApplication::translate("ChatMainWindow", "Sends a message to other people", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        sendButton->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        sendButton->setText(QApplication::translate("ChatMainWindow", "Send", nullptr));
        concurrentUsername->setText(QString());
        concurrentUserImageURL_label->setText(QString());
        Titlt->setText(QApplication::translate("ChatMainWindow", "Chat App", nullptr));
        loggedInUsername->setText(QString());
        userImageURL_label->setText(QString());
        reportButton->setText(QApplication::translate("ChatMainWindow", "Report", nullptr));
        settingsButton->setText(QApplication::translate("ChatMainWindow", "Settings", nullptr));
        Titlt_2->setText(QApplication::translate("ChatMainWindow", "Users", nullptr));
#ifndef QT_NO_TOOLTIP
        userListSearch_button->setToolTip(QApplication::translate("ChatMainWindow", "Sends a message to other people", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        userListSearch_button->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        userListSearch_button->setText(QApplication::translate("ChatMainWindow", "Search", nullptr));
        registerForm_6->setTitle(QString());
        label_38->setText(QApplication::translate("ChatMainWindow", "Profile Settings", nullptr));
        label_35->setText(QApplication::translate("ChatMainWindow", "Username", nullptr));
        label_34->setText(QApplication::translate("ChatMainWindow", "First name", nullptr));
        label_39->setText(QApplication::translate("ChatMainWindow", "Last name", nullptr));
        label_36->setText(QApplication::translate("ChatMainWindow", "Email", nullptr));
        label_40->setText(QApplication::translate("ChatMainWindow", "Image URL", nullptr));
        updateSettings->setText(QApplication::translate("ChatMainWindow", "Update", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("ChatMainWindow", "Messages per day", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("ChatMainWindow", "Most sent messages", nullptr));
        label_46->setText(QApplication::translate("ChatMainWindow", "Report", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChatMainWindow: public Ui_ChatMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATMAINWINDOW_H
