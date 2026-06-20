#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QQmlApplicationEngine>  
#include "../core/DataGenrator/dataGenrator.hpp"
#include "../ui/components/graph/Ploter.hpp"


int main(int argc, char *argv[]) {
    QApplication app(argc , argv );

 qmlRegisterType<Ploter>("CustomGraph", 1, 0, "Ploter");

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/qt/qml/ANNUi/qml/components/Presentor.qml"_qs);
    
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed,
        &app, []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
        
    engine.load(url);

    QWidget window;
    window.setWindowTitle("ANN from scratch");
    window.resize(300,200);

    QVBoxLayout *layout = new QVBoxLayout(&window);
    QPushButton *button = new QPushButton("It works!");
    layout->addWidget(button);


    DataGenrator gen; 
    gen.genrateLenearData(1, 2.0f, 2.0f, 2.3f);


    window.show();
    return app.exec();
}