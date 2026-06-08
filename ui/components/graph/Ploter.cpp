#include "Ploter.hpp"
#include <QSGNode>
#include <QSGFlatColorMaterial>



Ploter::Ploter(QQuickItem *parent) : QQuickItem(parent)
{

}

QSGNode *Ploter::updatePaintNode(QSGNode *oldNode, UpdatePaintNodeData *)
{
    QSGNode* root = oldNode;
    if(!root){
        root = new QSGNode();

        root->appendChildNode(new QSGNode());
        root->appendChildNode(new QSGNode());
        root->appendChildNode(new QSGNode());

        m_dataDirty = true;
        m_selctionDirty = true;
    }

    QSGNode* gridLayer = root->childAtIndex(0);
    QSGNode* dataLayer = root->childAtIndex(1);
    QSGNode* selectionLayer = root->childAtIndex(2);

    if(m_gridDirty ){
        reBuildGridLayer(gridLayer);
    }

    if(m_dataDirty){
        
        reBuildDataLayer(dataLayer);
    }

    if(m_selctionDirty){
        reBuildSelectionLayer(selectionLayer);
    }

    m_dataDirty = false;
    m_selctionDirty  = false;
    m_gridDirty = false;


    return root;
}

void Ploter::reBuildDataLayer(QSGNode *node)
{
    if(node){
        node->removeChildNode(node);
        delete node;
        node = nullptr;
    }

    if(!node){
        QSGGeometryNode* geoNode = new QSGGeometryNode();
        QSGGeometry* geo = new QSGGeometry(QSGGeometry::defaultAttributes_Point2D(),1);
        geo->setDrawingMode(QSGGeometry::DrawPoints);
        geoNode->setGeometry(geo);
        geoNode->setFlag(QSGNode::OwnsGeometry);

        auto* mat = new QSGFlatColorMaterial();
        mat->setColor(QColor(qRgb(1,2,3)));
        geoNode->setMaterial(mat);
        geoNode->setFlag(QSGNode::OwnsMaterial);
        
    }
}
