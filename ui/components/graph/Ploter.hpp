#pragma once 
#include <QObject>
#include <QQmlEngine>
#include <QQuickItem>
#include <QSGNode>
#include "../core/dataTypes/dataTypes.hpp"
 
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

    std::vector< Point> m_vertexData;
public:
     explicit Ploter(QQuickItem* parent = nullptr);    
    ~Ploter();

    void setData(std::vector< Point> points);
};