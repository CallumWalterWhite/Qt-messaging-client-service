/********************************************************************************
** Form generated from reading UI file 'chatmessageeditor.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATMESSAGEEDITOR_H
#define UI_CHATMESSAGEEDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChatMessageEditor
{
public:
    QAction *actionQuit;
    QAction *actionAboutQt;
    QAction *actionChangeNickname;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QTextEdit *messageEditor_text;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *messageEditor_updateButton;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *messageEditor_cancelButton;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *messageEditor_deleteButton;

    void setupUi(QDialog *ChatMessageEditor)
    {
        if (ChatMessageEditor->objectName().isEmpty())
            ChatMessageEditor->setObjectName(QString::fromUtf8("ChatMessageEditor"));
        ChatMessageEditor->resize(479, 220);
        ChatMessageEditor->setAutoFillBackground(false);
        ChatMessageEditor->setStyleSheet(QString::fromUtf8("background-color: rgb(47,79,79);"));
        actionQuit = new QAction(ChatMessageEditor);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        actionAboutQt = new QAction(ChatMessageEditor);
        actionAboutQt->setObjectName(QString::fromUtf8("actionAboutQt"));
        actionChangeNickname = new QAction(ChatMessageEditor);
        actionChangeNickname->setObjectName(QString::fromUtf8("actionChangeNickname"));
        verticalLayoutWidget = new QWidget(ChatMessageEditor);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 481, 131));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        messageEditor_text = new QTextEdit(verticalLayoutWidget);
        messageEditor_text->setObjectName(QString::fromUtf8("messageEditor_text"));
        messageEditor_text->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));

        horizontalLayout_2->addWidget(messageEditor_text);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayoutWidget = new QWidget(ChatMessageEditor);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 130, 151, 91));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        messageEditor_updateButton = new QPushButton(horizontalLayoutWidget);
        messageEditor_updateButton->setObjectName(QString::fromUtf8("messageEditor_updateButton"));
        messageEditor_updateButton->setStyleSheet(QString::fromUtf8("\n"
"	background-color: rgb(255, 255, 255);\n"
"	border-width:0px;\n"
"	border-radius:4px;\n"
"	color: black;"));

        horizontalLayout->addWidget(messageEditor_updateButton);

        horizontalLayoutWidget_3 = new QWidget(ChatMessageEditor);
        horizontalLayoutWidget_3->setObjectName(QString::fromUtf8("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(330, 130, 151, 91));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        messageEditor_cancelButton = new QPushButton(horizontalLayoutWidget_3);
        messageEditor_cancelButton->setObjectName(QString::fromUtf8("messageEditor_cancelButton"));
        messageEditor_cancelButton->setStyleSheet(QString::fromUtf8("\n"
"	background-color: rgb(255, 255, 255);\n"
"	border-width:0px;\n"
"	border-radius:4px;\n"
"	color: black;"));

        horizontalLayout_3->addWidget(messageEditor_cancelButton);

        horizontalLayoutWidget_4 = new QWidget(ChatMessageEditor);
        horizontalLayoutWidget_4->setObjectName(QString::fromUtf8("horizontalLayoutWidget_4"));
        horizontalLayoutWidget_4->setGeometry(QRect(170, 130, 151, 89));
        horizontalLayout_4 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        messageEditor_deleteButton = new QPushButton(horizontalLayoutWidget_4);
        messageEditor_deleteButton->setObjectName(QString::fromUtf8("messageEditor_deleteButton"));
        messageEditor_deleteButton->setStyleSheet(QString::fromUtf8("\n"
"	background-color: rgb(255, 255, 255);\n"
"	border-width:0px;\n"
"	border-radius:4px;\n"
"	color: black;"));

        horizontalLayout_4->addWidget(messageEditor_deleteButton);


        retranslateUi(ChatMessageEditor);

        QMetaObject::connectSlotsByName(ChatMessageEditor);
    } // setupUi

    void retranslateUi(QDialog *ChatMessageEditor)
    {
        ChatMessageEditor->setWindowTitle(QApplication::translate("ChatMessageEditor", "ChatApp", nullptr));
        actionQuit->setText(QApplication::translate("ChatMessageEditor", "Quit", nullptr));
#ifndef QT_NO_SHORTCUT
        actionQuit->setShortcut(QApplication::translate("ChatMessageEditor", "Ctrl+Q", nullptr));
#endif // QT_NO_SHORTCUT
        actionAboutQt->setText(QApplication::translate("ChatMessageEditor", "About Qt...", nullptr));
        actionChangeNickname->setText(QApplication::translate("ChatMessageEditor", "Change nickname...", nullptr));
#ifndef QT_NO_SHORTCUT
        actionChangeNickname->setShortcut(QApplication::translate("ChatMessageEditor", "Ctrl+N", nullptr));
#endif // QT_NO_SHORTCUT
        messageEditor_updateButton->setText(QApplication::translate("ChatMessageEditor", "Update", nullptr));
        messageEditor_cancelButton->setText(QApplication::translate("ChatMessageEditor", "Cancel", nullptr));
        messageEditor_deleteButton->setText(QApplication::translate("ChatMessageEditor", "Delete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ChatMessageEditor: public Ui_ChatMessageEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATMESSAGEEDITOR_H
