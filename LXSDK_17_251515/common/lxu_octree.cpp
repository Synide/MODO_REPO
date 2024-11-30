/*
 * Plug-in SDK Header: Vector Wrapper
 *
 * Copyright 0000
 *
 * vector
 */
#include <lxu_octree.hpp>
#include <lxu_oqtree.hpp>
#include <lxu_vectorarray.hpp>

#define OCTREE_DIM 3

struct ocTreeData
{
    void* data;
};

CLxOcTree::CLxOcTree()
{
    data = new oqTree<ocTreeData, OCTREE_DIM>;
}

CLxOcTree::~CLxOcTree()
{
    delete (oqTree<ocTreeData, OCTREE_DIM>*) data;
}

void CLxOcTree::clear()
{
    oqTree<ocTreeData, OCTREE_DIM>* tree = (oqTree<ocTreeData, OCTREE_DIM>*) (this->data);
    tree->clear();
}

size_t CLxOcTree::size()
{
    oqTree<ocTreeData, OCTREE_DIM>* tree = (oqTree<ocTreeData, OCTREE_DIM>*) (this->data);
    return tree->size();
}

bool CLxOcTree::empty()
{
    oqTree<ocTreeData, OCTREE_DIM>* tree = (oqTree<ocTreeData, OCTREE_DIM>*) (this->data);
    return tree->empty();
}

int CLxOcTree::addPoint(const CLxVector& pos, void* in_data)
{
    oqTree<ocTreeData, OCTREE_DIM>* tree = (oqTree<ocTreeData, OCTREE_DIM>*) (this->data);
    return tree->AddPoint(pos.v, (ocTreeData*) in_data);
}
/*
void
CLxOcTree::addPoints (const CLxVectorArray &posArray) {
        oqTree<ocTreeData,OCTREE_DIM> *tree =  (oqTree<ocTreeData,OCTREE_DIM>*)(this->data);

        for( unsigned int ii = 0, ni = posArray.size() ; ii < ni ; ++ii ) {
                tree->AddPoint(posArray[ii].v, (ocTreeData*)NULL);
        }
}
*/
int CLxOcTree::nearestNeighbors(CLxVector&           pos,
                                double               maxDist,
                                int                  max,
                                std::vector<int>&    indices,
                                std::vector<double>& dists,
                                std::vector<void*>&  datas) const
{
    oqTree<ocTreeData, OCTREE_DIM>*           tree  = (oqTree<ocTreeData, OCTREE_DIM>*) (this->data);
    oqTree<ocTreeData, OCTREE_DIM>::Neighbor* reslt = new oqTree<ocTreeData, OCTREE_DIM>::Neighbor[max];

    int n = tree->NearestNeighbors(pos.v, maxDist, reslt, max);

    indices.reserve(n);
    datas.reserve(n);
    dists.reserve(n);

    for (int ii = 0; ii < n; ++ii)
    {
        indices.push_back(reslt[ii].index);
        datas.push_back(reslt[ii].data);
        dists.push_back(sqrt(reslt[ii].d2));
    }

    delete[] reslt;

    return n;
}

int CLxOcTree::nearestNeighbors(CLxVector& pos, double maxDist, int max, std::vector<int>& indices, std::vector<double>& dists) const
{
    oqTree<ocTreeData, OCTREE_DIM>*           tree  = (oqTree<ocTreeData, OCTREE_DIM>*) (this->data);
    oqTree<ocTreeData, OCTREE_DIM>::Neighbor* reslt = new oqTree<ocTreeData, OCTREE_DIM>::Neighbor[max];

    int n = tree->NearestNeighbors(pos.v, maxDist, reslt, max);

    indices.reserve(n);
    dists.reserve(n);

    for (int ii = 0; ii < n; ++ii)
    {
        indices.push_back(reslt[ii].index);
        dists.push_back(sqrt(reslt[ii].d2));
    }

    delete[] reslt;

    return n;
}
