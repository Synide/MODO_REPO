/*
 * Plug-in SDK Header: C++ Services
 *
 * Copyright 0000
 *
 * Helper class for doing math with modo vectors.
 */

#ifndef LX_OCTREE_HPP
#define LX_OCTREE_HPP

#include <lxu_vector.hpp>
#include <lxu_vectorarray.hpp>

#include <vector>

class CLxOcTree {
	void *data;
public:
	CLxOcTree () ;
	~CLxOcTree () ;
	
	void    clear ()  ;
	size_t  size () ;
	bool    empty () ;
	
	int     addPoint      (const CLxVector &pos, void *data = nullptr) ;

	void    addPoints     (const CLxVectorArray &posArray) ;
	
	int     nearestNeighbors (CLxVector &pos, double radius, int maxRet, std::vector<int> &indices, std::vector<double> &dists,
				    std::vector<void*> &datas) const ;
	
	int     nearestNeighbors (CLxVector &pos, double radius, int maxRet, std::vector<int> &indices, std::vector<double> &dists) const ;
};


#endif	/* LX_OCTREE_HPP */
