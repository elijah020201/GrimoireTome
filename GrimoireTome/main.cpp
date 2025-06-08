#include "mainwindow.h"

#include <QApplication>
#include <QFile>
#include <QFontDatabase>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // --- Font Loading ---
    // This line loads your new, more readable font from the resources.
    int fontId = QFontDatabase::addApplicationFont(":/Cinzel-VariableFont_wght.ttf");

    // This is a check to ensure the font was loaded correctly.
    if (fontId == -1) {
        qDebug() << "Warning: Could not load the custom font 'Cinzel-VariableFont_wght.ttf'.";
    }

    // --- Stylesheet Loading ---
    // This loads and applies your style.qss file to the entire application.
    QFile styleSheetFile(":/style.qss");
    if (styleSheetFile.open(QFile::ReadOnly)) {
        QString styleSheet = QLatin1String(styleSheetFile.readAll());
        a.setStyleSheet(styleSheet);
        styleSheetFile.close();
    } else {
        qDebug() << "Warning: Could not load the stylesheet file 'style.qss'.";
    }

    MainWindow w;
    w.show();
    return a.exec();
}
