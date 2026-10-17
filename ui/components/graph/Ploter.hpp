#pragma once

#include <QtCore/QObject>
#include <QtQml/QQmlEngine>
#include <QtQuick/QQuickItem>
#include <QtQuick/QSGNode>
#include <vector>

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