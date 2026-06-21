#include "mainWindow.hpp"
#include <QDebug>  

 
mainWindow::mainWindow(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("ANN Data Generator Dashboard");
    setMinimumSize(800, 600);

     QVBoxLayout* mainLayout = new QVBoxLayout(this);

     QHBoxLayout* controlsLayout = new QHBoxLayout();

     controlsLayout->addWidget(new QLabel("Dataset:"));
    m_dataSelector = new QComboBox();
    m_dataSelector->addItem("Spiral Data");  
    m_dataSelector->addItem("Linear Data");  
    controlsLayout->addWidget(m_dataSelector);

     controlsLayout->addWidget(new QLabel("Points:"));
    m_quantitySpinBox = new QSpinBox();
    m_quantitySpinBox->setRange(10, 100000);  
    m_quantitySpinBox->setValue(500);
    controlsLayout->addWidget(m_quantitySpinBox);

     m_linearParamsContainer = new QWidget();
    QHBoxLayout* linearLayout = new QHBoxLayout(m_linearParamsContainer);
    linearLayout->setContentsMargins(10, 0, 10, 0);  
    
    m_slopeInput = new QLineEdit("2.0");
    m_interceptInput = new QLineEdit("0.0");
    m_noiseInput = new QLineEdit("1.5");
    
     m_slopeInput->setFixedWidth(50);
    m_interceptInput->setFixedWidth(50);
    m_noiseInput->setFixedWidth(50);

    linearLayout->addWidget(new QLabel("m:"));
    linearLayout->addWidget(m_slopeInput);
    linearLayout->addWidget(new QLabel("b:"));
    linearLayout->addWidget(m_interceptInput);
    linearLayout->addWidget(new QLabel("Noise:"));
    linearLayout->addWidget(m_noiseInput);
    
    controlsLayout->addWidget(m_linearParamsContainer);

     m_generateBtn = new QPushButton("Generate Data");
    controlsLayout->addWidget(m_generateBtn);
    
     controlsLayout->addStretch(); 

    m_qmlView = new QQuickWidget();
    m_qmlView->setResizeMode(QQuickWidget::SizeRootObjectToView);  
    m_qmlView->setSource(QUrl(u"qrc:/qt/qml/ANNUi/qml/components/Presentor.qml"_qs));

     QObject* root = m_qmlView->rootObject();
    if (root) {
         m_ploter = root->findChild<Ploter*>("myPloter"); 
    }

     mainLayout->addLayout(controlsLayout);
    mainLayout->addWidget(m_qmlView, 1);

      connect(m_dataSelector, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &mainWindow::onDataSelectionChanged);
    
     connect(m_generateBtn, &QPushButton::clicked, this, &mainWindow::onGenerateClicked);

     onDataSelectionChanged(m_dataSelector->currentIndex()); 
}

mainWindow::~mainWindow() {}

void mainWindow::onDataSelectionChanged(int index)
{
     if (index == 1) {
        m_linearParamsContainer->show();
    } else {
        m_linearParamsContainer->hide();
    }
}

void mainWindow::onGenerateClicked()
{
    int points = m_quantitySpinBox->value();
    QString type = m_dataSelector->currentText();
    
    if (type == "Linear Data") {
        float m = m_slopeInput->text().toFloat();
        float b = m_interceptInput->text().toFloat();
        float noise = m_noiseInput->text().toFloat();
        
        qDebug() << "Generating Linear Data...";

         if (m_ploter) {
            DataGenrator gen;
            auto dataset = gen.genrateLenearData(points, m, b, noise);
            
             m_ploter->setData(dataset); 
        } else {
            qDebug() << "ERROR: Ploter UI not found in QML tree!";
        }
    }
}