#pragma once

// Base Geometry Classes
//
//    Copyright 0000

#include "objParser.hxx"

#include <vector>

/*
 * Integer vector for polygon indices.  These are of the form "##[/[##][/##]]",
 * and we set the bool vector to show which components were present. The order
 * of the components is: vertex / uv / normal
 */
#define IP_VRT  0
#define IP_UV   1
#define IP_NORM 2
#define IP_NUM  3

/*
 * We have classes for normals and texture coordinates that have a "less-than"
 * operator to allow them to be part of maps.
 *
 * CVertex, CNormal, and CTexture are used for saving and loading mesh items.
 *
 * CVector, C2Vector, C3Vector, C4Vector, CVectorList, and CPolyElt are used for loading
 * triSurf items.
 */
class CVertex
{
public:
    float vec[3];
};

class CNormal
{
public:
    float vec[3];
    bool  operator<(const CNormal& x) const
    {
        float d;

        if (d = vec[0] - x.vec[0]; d)
            return (d > 0.0f);
        if (d = vec[1] - x.vec[1]; d)
            return (d > 0.0f);
        if (d = vec[2] - x.vec[2]; d)
            return (d > 0.0f);
        return false;
    }
};

class CTexture
{
public:
    float vec[2];
    bool  operator<(const CTexture& x) const
    {
        float d;

        if (d = vec[0] - x.vec[0]; d)
            return (d > 0.0f);
        if (d = vec[1] - x.vec[1]; d)
            return (d > 0.0f);
        return false;
    }
};

class CVector
{
public:
    int N();
};

class C2Vector : public CVector
{
public:
    float f_vec[2];
    int   N()
    {
        return 2;
    }
};

class C3Vector : public CVector
{
public:
    float f_vec[3];
    int   N()
    {
        return 3;
    }
};

class C4Vector : public CVector
{
public:
    float f_vec[4];
    int   N()
    {
        return 4;
    }
};

template <class T>
class CVectorList
{
public:
    std::vector<T> cv_list;
    unsigned       i_base;

    CVectorList()
    {
        Clear();
    }

    void Clear()
    {
        i_base = 1;
        cv_list.clear();
    }

    bool Read(COBJParser* par, double unitScale = 1.0)
    {
        T vec;

        if (!par->PullVec(vec.f_vec, vec.N(), unitScale))
            return false;

        cv_list.push_back(vec);
        return true;
    }

    void Grab(unsigned index, float* dest)
    {
        T   vec;
        int i;

        index -= i_base;
        if (index >= cv_list.size())
        {
            for (i = 0; i < vec.N(); i++)
                dest[i] = 1.0e6;

            return;
        }

        vec = cv_list[index];
        for (i = 0; i < vec.N(); i++)
            dest[i] = vec.f_vec[i];
    }

    void Reset()
    {
        i_base += static_cast<unsigned>(cv_list.size());
        cv_list.clear();
    }

    void Dump()
    {
        T vec;

        printf("elt = %d, dim = %d\n", cv_list.size(), vec.N());
        for (int i = 0; i < cv_list.size(); i++)
        {
            printf("  ");
            vec = cv_list[i];
            for (int j = 0; j < vec.N(); j++)
                printf("%f ", vec.f_vec[j]);
            printf("\n");
        }
    }
};

class CPolyElt
{
    unsigned vrt, uv, norm, vrtColor;

public:
    bool operator<(const CPolyElt& x) const
    {
        int d;

        if (d = vrt - x.vrt; d)
            return (d > 0);
        if (d = uv - x.uv; d)
            return (d > 0);
        if (d = norm - x.norm; d)
            return (d > 0);
        if (d = vrtColor - x.vrtColor; d)
            return (d > 0);
        return false;
    }

    void Set(unsigned idx[IP_NUM], bool exist[IP_NUM])
    {
        vrt      = idx[IP_VRT];
        uv       = (exist[IP_UV] ? idx[IP_UV] + 1 : 0);
        norm     = (exist[IP_NORM] ? idx[IP_NORM] + 1 : 0);
        vrtColor = 0;
    }

    void SetVrtColor(unsigned idx[IP_NUM], bool exist)
    {
        vrtColor = exist ? idx[IP_VRT] + 1 : 0;
    }

    unsigned Vrt()
    {
        return vrt;
    }
    bool HasUV()
    {
        return uv != 0;
    }
    bool HasNorm()
    {
        return norm != 0;
    }
    bool HasVrtColor()
    {
        return vrtColor != 0;
    }
    unsigned UV()
    {
        return uv - 1;
    }
    unsigned Norm()
    {
        return norm - 1;
    }
    unsigned VrtColor()
    {
        return vrtColor - 1;
    }
};
