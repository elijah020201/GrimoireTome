#ifndef ADDSPELLDIALOG_H
#define ADDSPELLDIALOG_H

#include <QDialog>

namespace Ui {
class AddSpellDialog;
}

class AddSpellDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddSpellDialog(QWidget *parent = nullptr);
    ~AddSpellDialog();
    QString spellName() const;
    QString spellCategory() const;
    QString spellDescription() const;

private:
    Ui::AddSpellDialog *ui;
};

#endif // ADDSPELLDIALOG_H
