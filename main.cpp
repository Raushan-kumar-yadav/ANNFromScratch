#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>


int main(int argc, char *argv[]) {
    QApplication app(argc , argv );

    QWidget window;
    window.setWindowTitle("ANN from scratch");
    window.resize(300,200);

    QVBoxLayout *layout = new QVBoxLayout(&window);
    QPushButton *button = new QPushButton("It works!");
    layout->addWidget(button);

    window.show();
    return app.exec();
}