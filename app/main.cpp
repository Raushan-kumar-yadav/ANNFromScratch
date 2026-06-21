#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QQmlApplicationEngine>  
#include "../core/DataGenrator/dataGenrator.hpp"
#include "../ui/components/graph/Ploter.hpp"
#include "../ui/windows/mainWindow.hpp"


int main(int argc, char *argv[]) {
    QApplication app(argc , argv );


   qmlRegisterType<Ploter>("CustomGraph", 1, 0, "Ploter");

     mainWindow window;
    window.show();
    return app.exec();
}