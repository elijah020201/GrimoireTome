#include "addspelldialog.h"
#include "ui_addspelldialog.h"

AddSpellDialog::AddSpellDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddSpellDialog)
{
    ui->setupUi(this);
}

AddSpellDialog::~AddSpellDialog()
{
    delete ui;
}

QString AddSpellDialog::spellName() const
{
    return ui->nameLineEdit->text();
}

QString AddSpellDialog::spellCategory() const
{
    return ui->categoryLineEdit->text();
}

QString AddSpellDialog::spellDescription() const
{
    return ui->descriptionTextEdit->toPlainText();
}
