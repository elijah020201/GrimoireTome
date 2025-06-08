#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>
#include <QFileDialog>
#include <QMessageBox>
#include "addspelldialog.h"
#include <QNetworkReply>
#include <QUrl>
#include <QDebug>
#include <QMessageBox>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Create the label for the moon phase and add it to the status bar
    m_moonPhaseLabel = new QLabel("Loading moon data...", this);
    ui->statusbar->addWidget(m_moonPhaseLabel);

    // Create the network manager
    m_networkManager = new QNetworkAccessManager(this);

    // Connect the finished signal to our new slot
    connect(m_networkManager, &QNetworkAccessManager::finished,
            this, &MainWindow::onMoonDataReceived);

    // Make the initial call to get data when the app starts
    fetchMoonData();
    refreshUi();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::refreshUi()
{
    // First, clear any old items from the page list
    ui->pagesListWidget->clear();

    // Now, loop through all the pages in our grimoire
    for (const auto& page : m_grimoire.pages)
    {
        // For each page, create a string for its title and add it to the list widget
        std::string pageTitle = "Page " + std::to_string(page.pageNumber);
        ui->pagesListWidget->addItem(QString::fromStdString(pageTitle));
    }


}

void MainWindow::on_AddPageButton_clicked()
{
    // 1. Create a new page object. Its number will be the current count + 1.
    Page newPage(m_grimoire.pages.size() + 1);

    // 2. Add the new page to our grimoire engine.
    m_grimoire.AddPage(newPage);

    // 3. Call our refresh function to update the screen with the new data.
    refreshUi();
}


void MainWindow::on_pagesListWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    // First, clear any spells that might be showing from a previously selected page.
    ui->spellsListWidget->clear();
    ui->spellDetailTextEdit->clear();

    // This gets the row number of the item the user just clicked on.
    // The first item is 0, second is 1, etc.
    int selectedRow = ui->pagesListWidget->currentRow();

    // This is a safety check. If the row is valid (not -1, which means nothing is selected)
    // and it's a valid index in our vector of pages...
    if (selectedRow >= 0 && selectedRow < m_grimoire.pages.size())
    {
        // ...then get a reference to the actual Page object from our grimoire.
        const Page& selectedPage = m_grimoire.pages[selectedRow];

        // Now, loop through all the spells that belong to ONLY that selected page.
        for (const Spell& spell : selectedPage.spells)
        {
            // Add each spell's name to the middle list widget.
            ui->spellsListWidget->addItem(QString::fromStdString(spell.name));
        }
    }
}


void MainWindow::on_AddSpellB_clicked()
{
    int selectedPageIndex = ui->pagesListWidget->currentRow();
    if (selectedPageIndex < 0) {
        // Instead of just returning, show a helpful pop-up warning message.
        QMessageBox::warning(this, "No Page Selected", "Please select a page from the list before adding a spell.");
        return; // Then exit.
    }

    // Create an instance of our new dialog
    AddSpellDialog dialog(this);
    // This line shows the dialog and waits until the user clicks OK or Cancel
    if (dialog.exec() == QDialog::Accepted)
    {
        // If the user clicked OK, get the data from the dialog
        std::string name = dialog.spellName().toStdString();
        std::string category = dialog.spellCategory().toStdString();
        std::string description = dialog.spellDescription().toStdString();

        // Create a new spell object with the data
        Spell newSpell(name, description, category);

        // Add the spell to the correct page in our grimoire
        m_grimoire.pages[selectedPageIndex].AddSpell(newSpell);

        // And finally, refresh the UI to show the new spell in the list
        on_pagesListWidget_currentItemChanged(nullptr, nullptr);
    }
}


void MainWindow::on_spellsListWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    // First, we need to know which page is selected to find the spell data.
    int selectedPageRow = ui->pagesListWidget->currentRow();

    // Then, get the index of the spell the user just clicked in the middle list.
    int selectedSpellRow = ui->spellsListWidget->currentRow();

    // Safety check: Only proceed if both a page and a spell are actually selected.
    if (selectedPageRow >= 0 && selectedSpellRow >= 0)
    {
        // Using the indexes, navigate our data to get the exact spell object.
        const Spell& selectedSpell = m_grimoire.pages[selectedPageRow].spells[selectedSpellRow];

        // We use QString, Qt's string class, and \n creates a new line.
        QString details;
        details += "Name: " + QString::fromStdString(selectedSpell.name) + "\n";
        details += "Category: " + QString::fromStdString(selectedSpell.category) + "\n\n";
        details += "Description:\n" + QString::fromStdString(selectedSpell.description);

        // Finally, set the text of our large text box to show the details.
        ui->spellDetailTextEdit->setText(details);
    }
    else
    {
        // If nothing is selected, make sure the detail box is empty.
        ui->spellDetailTextEdit->clear();
    }
}


void MainWindow::on_SaveGrimoireButton_clicked()
{
    // This opens a standard "Save As" dialog.
    // It suggests a starting directory, and filters for JSON files.
    QString fileName = QFileDialog::getSaveFileName(this,
                                                    tr("Save Grimoire"), "",
                                                    tr("JSON Files (*.json);;All Files (*)"));

    // If the user clicked "Cancel", the fileName will be empty.
    if (fileName.isEmpty()) {
        return; // Do nothing if the user canceled.
    }

    // We have a valid filename, so let's try to save.
    try {
        m_grimoire.saveToFile(fileName.toStdString());
        // Show a simple success message.
        QMessageBox::information(this, tr("Success"), tr("Grimoire saved successfully!"));
    } catch (const std::exception &e) {
        // If anything went wrong during saving, show an error message.
        QMessageBox::critical(this, tr("Error"), tr("Failed to save grimoire: ") + e.what());
    }
}


void MainWindow::on_loadButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                    tr("Load Grimoire"), "",
                                                    tr("JSON Files (*.json);;All Files (*)"));

    if (fileName.isEmpty()) {
        return; // User canceled.
    }

    try {
        // Use the static loadFromFile method to create a new grimoire object.
        m_grimoire = Grimoire::loadFromFile(fileName.toStdString());

        // CRUCIAL STEP: After loading, we must refresh the entire UI
        // to display the new data.
        refreshUi();

        QMessageBox::information(this, tr("Success"), tr("Grimoire loaded successfully!"));
    } catch (const std::exception &e) {
        QMessageBox::critical(this, tr("Error"), tr("Failed to load grimoire: ") + e.what());
    }

}

void MainWindow::fetchMoonData()
{
    QNetworkRequest request(QUrl("https://moon-phase.p.rapidapi.com/advanced"));

    // Add the special headers required by this API.
    // REPLACE "YOUR_API_KEY_HERE" with your actual key from RapidAPI.
    request.setRawHeader("X-RapidAPI-Key", "abf7069ef0msha88d13818279f83p1127d5jsnc0768e4a1f7f");
    request.setRawHeader("X-RapidAPI-Host", "moon-phase.p.rapidapi.com");

    // Send the final request.
    m_networkManager->get(request);
}

void MainWindow::onMoonDataReceived(QNetworkReply *reply)
{
    // First, check for any network-level errors.
    if (reply->error() != QNetworkReply::NoError) {
        m_moonPhaseLabel->setText("Network Error: " + reply->errorString());
        qDebug() << "Network error:" << reply->errorString();
        reply->deleteLater();
        return;
    }

    // Read all the data from the reply.
    QByteArray responseData = reply->readAll();
    qDebug() << "API Response:" << responseData; // Keep this for debugging!

    try {
        std::string responseString = responseData.toStdString();
        json data = json::parse(responseString);

        // --- SAFE PARSING LOGIC ---

        // Check if the main 'moon' object exists before trying to access it.
        if (data.contains("moon") && !data["moon"].is_null())
        {
            json moonData = data["moon"]; // Get a reference to the moon object.

            // Use the .value() method for safe access.
            // .value("key", "default_value") returns a default if the key is not found.
            std::string phaseName = moonData.value("phase_name", "N/A");
            std::string illumination = moonData.value("illumination", "N/A");

            std::string nextFullMoonName = "N/A";
            int daysToFullMoon = 0;

            // Safely check for the nested 'full_moon' object.
            if (moonData.contains("upcoming_phases") &&
                moonData["upcoming_phases"].contains("full_moon") &&
                moonData["upcoming_phases"]["full_moon"].contains("next"))
            {
                json nextMoonData = moonData["upcoming_phases"]["full_moon"]["next"];
                nextFullMoonName = nextMoonData.value("name", "Unnamed Moon");
                daysToFullMoon = nextMoonData.value("days_ahead", 0);
            }

            // Build the final string for display.
            QString moonInfo = QString("Phase: %1 (%2)")
                                   .arg(QString::fromStdString(phaseName),
                                        QString::fromStdString(illumination));
            moonInfo += QString(" | Next Full Moon: The %1 (in %2 days)")
                            .arg(QString::fromStdString(nextFullMoonName),
                                 QString::number(daysToFullMoon));

            m_moonPhaseLabel->setText(moonInfo);
        }
        else {
            m_moonPhaseLabel->setText("Error: 'moon' data not found in response.");
        }

    } catch (const std::exception& e) {
        m_moonPhaseLabel->setText("Error: Could not parse moon data.");
        qDebug() << "JSON parsing error:" << e.what();
    }

    // Clean up the reply object to prevent memory leaks.
    reply->deleteLater();
}
