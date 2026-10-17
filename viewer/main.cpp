#include <QApplication>
#include <QtQml/qqml.h>

#include "panels/scatter/Ploter.hpp"
#include "windows/mainWindow.hpp"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    qmlRegisterType<Ploter>("CustomGraph", 1, 0, "Ploter");

    mainWindow window;
    window.show();
    return app.exec();
}
