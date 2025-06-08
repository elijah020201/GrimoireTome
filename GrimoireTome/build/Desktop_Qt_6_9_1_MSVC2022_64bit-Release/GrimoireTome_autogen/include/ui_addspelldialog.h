/********************************************************************************
** Form generated from reading UI file 'addspelldialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDSPELLDIALOG_H
#define UI_ADDSPELLDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_AddSpellDialog
{
public:
    QFormLayout *formLayout;
    QLineEdit *nameLineEdit;
    QLabel *label;
    QLineEdit *categoryLineEdit;
    QLabel *label_2;
    QTextEdit *descriptionTextEdit;
    QLabel *label_3;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *AddSpellDialog)
    {
        if (AddSpellDialog->objectName().isEmpty())
            AddSpellDialog->setObjectName("AddSpellDialog");
        AddSpellDialog->resize(400, 300);
        formLayout = new QFormLayout(AddSpellDialog);
        formLayout->setObjectName("formLayout");
        nameLineEdit = new QLineEdit(AddSpellDialog);
        nameLineEdit->setObjectName("nameLineEdit");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, nameLineEdit);

        label = new QLabel(AddSpellDialog);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, label);

        categoryLineEdit = new QLineEdit(AddSpellDialog);
        categoryLineEdit->setObjectName("categoryLineEdit");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, categoryLineEdit);

        label_2 = new QLabel(AddSpellDialog);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, label_2);

        descriptionTextEdit = new QTextEdit(AddSpellDialog);
        descriptionTextEdit->setObjectName("descriptionTextEdit");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, descriptionTextEdit);

        label_3 = new QLabel(AddSpellDialog);
        label_3->setObjectName("label_3");

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, label_3);

        buttonBox = new QDialogButtonBox(AddSpellDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);

        formLayout->setWidget(3, QFormLayout::ItemRole::SpanningRole, buttonBox);


        retranslateUi(AddSpellDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, AddSpellDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, AddSpellDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(AddSpellDialog);
    } // setupUi

    void retranslateUi(QDialog *AddSpellDialog)
    {
        AddSpellDialog->setWindowTitle(QCoreApplication::translate("AddSpellDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("AddSpellDialog", "Spell Name", nullptr));
        label_2->setText(QCoreApplication::translate("AddSpellDialog", "Category", nullptr));
        label_3->setText(QCoreApplication::translate("AddSpellDialog", "Description", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddSpellDialog: public Ui_AddSpellDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDSPELLDIALOG_H
