#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Grimoire.h"
#include <QListWidgetItem>
#include <QNetworkAccessManager>
#include <QMainWindow>

class QNetworkReply;
class QLabel;

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_AddPageButton_clicked();

    void on_pagesListWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

    void on_AddSpellB_clicked();

    void on_spellsListWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

    void on_SaveGrimoireButton_clicked();

    void on_loadButton_clicked();

private:
    Ui::MainWindow *ui;
    Grimoire m_grimoire;
    QNetworkAccessManager *m_networkManager;
    QLabel *m_moonPhaseLabel;
     void refreshUi();
    void fetchMoonData();
     void onMoonDataReceived(QNetworkReply *reply);
};
#endif // MAINWINDOW_H
