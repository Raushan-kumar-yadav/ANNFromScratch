#include "Ploter.hpp"
#include <QtCore/QDebug>
#include <QtGui/QColor>
#include <QtQuick/QSGFlatColorMaterial>
#include <QtQuick/QSGGeometryNode>

Ploter::Ploter(QQuickItem *parent) : QQuickItem(parent)
{
     setFlag(ItemHasContents, true);
}

Ploter::~Ploter()
{
}

void Ploter::setData(std::vector<neurolens::data::Point> points)
{
    m_vertexData = points;

    m_dataDirty = true;

    update();
}

QSGNode *Ploter::updatePaintNode(QSGNode *oldNode, UpdatePaintNodeData *)
{
    QSGNode* root = oldNode;
    if(!root){
        root = new QSGNode();

         root->appendChildNode(new QSGNode()); // Index 0: Grid
        root->appendChildNode(new QSGNode()); // Index 1: Data
        root->appendChildNode(new QSGNode()); // Index 2: Selection

        m_dataDirty = true;
        m_selctionDirty = true;
        m_gridDirty = true;  
    }

    QSGNode* gridLayer = root->childAtIndex(0);
    QSGNode* dataLayer = root->childAtIndex(1);
    QSGNode* selectionLayer = root->childAtIndex(2);

    if(m_gridDirty){
        reBuildGridLayer(gridLayer);
        m_gridDirty = false;
    }

    if(m_dataDirty){
        reBuildDataLayer(dataLayer);
        m_dataDirty = false;
    }

    if(m_selctionDirty){
        reBuildSelectionLayer(selectionLayer);
        m_selctionDirty = false;
    }

    return root;
}

void Ploter::reBuildGridLayer(QSGNode *node)
{
}

void Ploter::reBuildDataLayer(QSGNode *node)
{
    if(!node) return;
    node->removeAllChildNodes(); 

    if (m_vertexData.empty()) return; 

    QSGGeometryNode* geoNode = new QSGGeometryNode();
    
     int numVertices = m_vertexData.size() * 6;
    QSGGeometry* geo = new QSGGeometry(QSGGeometry::defaultAttributes_Point2D(), numVertices);
    
     geo->setDrawingMode(QSGGeometry::DrawTriangles);

    QSGGeometry::Point2D* vertices = geo->vertexDataAsPoint2D();

     float pointRadius = 3.0f; 
    qDebug() << "Rebuilding Layer! Point Count:" << m_vertexData.size();
    qDebug() << "Ploter Dimensions:" << width() << "x" << height();
     for(size_t i = 0; i < m_vertexData.size(); ++i) {
        
        float screenX = (width() / 2.0f)  + (m_vertexData[i].x * 20.0f);
        float screenY = (height() / 2.0f) - (m_vertexData[i].y * 20.0f); 

        int vIndex = i * 6;


        vertices[vIndex + 0].set(screenX - pointRadius, screenY - pointRadius); 
        vertices[vIndex + 1].set(screenX - pointRadius, screenY + pointRadius); 
        vertices[vIndex + 2].set(screenX + pointRadius, screenY - pointRadius); 


        vertices[vIndex + 3].set(screenX + pointRadius, screenY - pointRadius); 
        vertices[vIndex + 4].set(screenX - pointRadius, screenY + pointRadius); 
        vertices[vIndex + 5].set(screenX + pointRadius, screenY + pointRadius); 
    }

    geoNode->setGeometry(geo);
    geoNode->setFlag(QSGNode::OwnsGeometry);

    auto* mat = new QSGFlatColorMaterial();
    mat->setColor(QColor(255, 50, 50)); 
    geoNode->setMaterial(mat);
    geoNode->setFlag(QSGNode::OwnsMaterial);

    node->appendChildNode(geoNode);
}

void Ploter::reBuildSelectionLayer(QSGNode *node)
{
}