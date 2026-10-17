#pragma once 
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QComboBox>
#include <QQuickWidget>
#include <QSpinBox>
#include <QLineEdit>
#include "panels/scatter/Ploter.hpp"

class mainWindow : public QWidget
{
    Q_OBJECT  

private:
    // UI Elements
    QComboBox* m_dataSelector;
    QSpinBox* m_quantitySpinBox;
    
     QWidget* m_linearParamsContainer;  
    QLineEdit* m_noiseInput;
    QLineEdit* m_slopeInput;
    QLineEdit* m_interceptInput;
    
    QPushButton* m_generateBtn;
    QWidget* m_plotPlaceholder;  

    QQuickWidget* m_qmlView;
    Ploter* m_ploter; 

private slots:
  
    void onDataSelectionChanged(int index);
    void onGenerateClicked();

public:
    explicit mainWindow(QWidget* parent = nullptr);
    ~mainWindow();
};