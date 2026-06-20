#pragma once 
#include <QObject>
#include <QQmlEngine>
#include <QQuickItem>
#include <QSGNode>

class Ploter : public QQuickItem
{
    Q_OBJECT
     

protected:
    QSGNode* updatePaintNode(QSGNode* oldNode, UpdatePaintNodeData*) override;

private:
    void reBuildGridLayer(QSGNode* node);
    void reBuildDataLayer(QSGNode* node);
    void reBuildSelectionLayer(QSGNode* node);

    bool m_selctionDirty = false;
    bool m_dataDirty = false;
    bool m_gridDirty = false; 

public:
     explicit Ploter(QQuickItem* parent = nullptr);    
    ~Ploter();
};