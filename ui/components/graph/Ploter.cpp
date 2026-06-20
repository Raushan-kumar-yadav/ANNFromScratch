#include "Ploter.hpp"
#include <QSGGeometryNode>
#include <QSGFlatColorMaterial>

Ploter::Ploter(QQuickItem *parent) : QQuickItem(parent)
{
    // Tell Qt this item actually needs to be drawn
    setFlag(ItemHasContents, true);
}

Ploter::~Ploter()
{
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

     QSGGeometryNode* geoNode = new QSGGeometryNode();
    
     QSGGeometry* geo = new QSGGeometry(QSGGeometry::defaultAttributes_Point2D(), 1);
    geo->setDrawingMode(QSGGeometry::DrawPoints);
    geo->setLineWidth(5);  

     geo->vertexDataAsPoint2D()[0].set(width() / 2.0f, height() / 2.0f);

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