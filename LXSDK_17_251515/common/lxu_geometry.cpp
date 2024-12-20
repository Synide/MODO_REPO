/*
 * Plug-in SDK Source: Geometry Utilities
 *
 * Copyright 0000
 *
 * Provides geometry utility functions for C++ plug-ins.
 */
#include <lxu_geometry.hpp>

#include <cmath>

const double MIN_VECTOR_LENGTH = 1e-20;

/*
 * Helper function for triangle normal generation - zeroes
 * out the normal array.
 */
void ZeroOutArray(std::vector<lx::GeoPoint>& normals, unsigned normalsCount)
{
    lx::GeoPoint zeroVec;

    normals.clear();

    LXx_VCLR(zeroVec.vec);
    for (unsigned i = 0; i < normalsCount; ++i)
    {
        normals.push_back(zeroVec);
    }
}

/*
 * Helper function for triangle normal generation - calculates
 * triangle normal and adds it to the polygon normals.
 */
void CalcTriangleNormal(std::vector<lx::GeoPoint>& points, unsigned pi0, unsigned pi1, unsigned pi2, std::vector<lx::GeoPoint>& normals)
{
    /*
     * Fetch the points indexed by the triangle.
     */
    lx::GeoPoint* p0 = &points[pi0];
    lx::GeoPoint* p1 = &points[pi1];
    lx::GeoPoint* p2 = &points[pi2];

    /*
     * Compute the face normal.
     */
    LXtVector edge1, edge2, normal;
    LXx_VSUB3(edge1, p1->vec, p0->vec);
    LXx_VSUB3(edge2, p2->vec, p0->vec);
    LXx_VCROSS(normal, edge1, edge2);

    /*
     * Normalize it.
     */
    double mag = LXx_VLEN(normal);
    if (mag < MIN_VECTOR_LENGTH)
    {
        /*
         * For normals with a length too close to zero,
         * make a valid normal to avoid problems.
         */
        LXx_VSET3(normal, 1.0, 0.0, 0.0);
    }
    else
    {
        double invMag = 1.0 / mag;
        LXx_VSCL(normal, invMag);
    }

    /*
     * Accumulate the normals at vertices shared by
     * more than one face.
     */
    lx::GeoPoint* n0 = &normals[pi0];
    lx::GeoPoint* n1 = &normals[pi1];
    lx::GeoPoint* n2 = &normals[pi2];

    LXx_VADD(n0->vec, normal);
    LXx_VADD(n1->vec, normal);
    LXx_VADD(n2->vec, normal);
}

/*
 * Helper function for triangle normal generation - normalizes
 * final smoothed normals.
 */
void NormalizeSmoothedNormals(std::vector<lx::GeoPoint>& normals)
{
    size_t normalsCount = normals.size();
    for (unsigned normalIndex = 0; normalIndex < normalsCount; ++normalIndex)
    {
        double mag = LXx_VLEN(normals[normalIndex].vec);
        if (mag < MIN_VECTOR_LENGTH)
        {
            /*
             * For normals with a length too close to zero,
             * make a valid normal to avoid problems.
             */
            LXx_VSET3(normals[normalIndex].vec, 1.0, 0.0, 0.0);
        }
        else
        {
            double invMag = 1.0 / mag;
            LXx_VSCL(normals[normalIndex].vec, invMag);
        }
    }
}

/*
 * Generate vertex normals for a triangle list,
 * with normal smoothing for shared vertices.
 */
void lx::GenerateNormals(std::vector<GeoPoint>& points, std::vector<unsigned>& triangles, std::vector<GeoPoint>& normals)
{
    ZeroOutArray(normals, (unsigned) points.size());

    for (unsigned triIndex = 0; triIndex < triangles.size(); triIndex += 3)
    {
        unsigned pi0 = triangles[triIndex + 0];
        unsigned pi1 = triangles[triIndex + 1];
        unsigned pi2 = triangles[triIndex + 2];

        CalcTriangleNormal(points, pi0, pi1, pi2, normals);
    }

    NormalizeSmoothedNormals(normals);
}

/*
 * Generate vertex normals for a convex polygon list,
 * with normal smoothing for shared vertices.
 */
void lx::GeneratePolyNormals(std::vector<GeoPoint>& points,
                             std::vector<unsigned>& polyInds,
                             std::vector<unsigned>& polyCounts,
                             std::vector<GeoPoint>& normals)
{
    ZeroOutArray(normals, (unsigned) points.size());

    unsigned nPolys     = static_cast<unsigned>(polyCounts.size());
    unsigned curPolyInd = 0;

    for (unsigned k = 0; k < nPolys; k++)
    {
        unsigned curPolyCount = polyCounts[k];

        if (curPolyCount <= 2)
            continue;

        /*
         * Concave polygons are simply triangulated by making
         * a triangle fan.
         */
        for (unsigned i = 0; i < curPolyCount - 2; i++)
        {
            unsigned pi0 = polyInds[curPolyInd];
            unsigned pi1 = polyInds[curPolyInd + i + 1];
            unsigned pi2 = polyInds[curPolyInd + i + 2];

            CalcTriangleNormal(points, pi0, pi1, pi2, normals);
        }

        curPolyInd += curPolyCount;
    }

    NormalizeSmoothedNormals(normals);
}

/*
 * Compute the UV gradient, which is the derivative of the world position with
 * respect to U and V. The caller provides the world position of three corners
 * of a triangle, and their corresponding UV coordinates, and the results are
 * returned in dPdU and dPdV. The function returns false if the triangle was
 * degenerate.
 */
static bool UVGradient(const LXtVector   wp0,
                       const LXtVector   wp1,
                       const LXtVector   wp2,
                       const LXtFVector2 uv0,
                       const LXtFVector2 uv1,
                       const LXtFVector2 uv2,
                       LXtVector&        dPdU,
                       LXtVector&        dPdV)
{
    double    du1, du2, dv1, dv2, determinant;
    LXtVector dp1, dp2;
    int       i;

    du1 = uv0[0] - uv2[0];
    du2 = uv1[0] - uv2[0];
    dv1 = uv0[1] - uv2[1];
    dv2 = uv1[1] - uv2[1];

    LXx_VSUB3(dp1, wp0, wp2);
    LXx_VSUB3(dp2, wp1, wp2);

    determinant = du1 * dv2 - dv1 * du2;
    if (determinant == 0.0)
        return false;

    for (i = 0; i < 3; i++)
    {
        dPdU[i] = (dv2 * dp1[i] - dv1 * dp2[i]) / determinant;
        dPdV[i] = (-du2 * dp1[i] + du1 * dp2[i]) / determinant;
    }
    return true;
}

/*
 * Generate vertex dPdu/dPdv values, with smoothing for shared vertices.
 */
void lx::GenerateDPDUs(std::vector<lx::GeoPoint>& points,
                       std::vector<lx::GeoUV>&    uvs,
                       std::vector<unsigned>&     triangles,
                       std::vector<lx::GeoPoint>& dPdus,
                       std::vector<lx::GeoPoint>& dPdvs)
{
    /*
     * Zero out the dPdu arrays.
     */
    dPdus.clear();
    dPdvs.clear();
    GeoPoint zeroVec;
    LXx_VCLR(zeroVec.vec);
    unsigned pointIndex;
    for (pointIndex = 0; pointIndex < points.size(); ++pointIndex)
    {
        dPdus.push_back(zeroVec);
        dPdvs.push_back(zeroVec);
    }

    /*
     * Zero out the point reference counts.
     */
    std::vector<unsigned> refCounts;
    for (pointIndex = 0; pointIndex < points.size(); ++pointIndex)
    {
        refCounts.push_back(0);
    }

    for (unsigned triIndex = 0; triIndex < triangles.size(); triIndex += 3)
    {
        /*
         * Fetch the points indexed by the triangle.
         */
        unsigned pi0 = triangles[triIndex + 0];
        unsigned pi1 = triangles[triIndex + 1];
        unsigned pi2 = triangles[triIndex + 2];

        /*
         * Fetch the points indexed by the triangle.
         */
        GeoPoint* p0 = &points[pi0];
        GeoPoint* p1 = &points[pi1];
        GeoPoint* p2 = &points[pi2];

        GeoUV* uv0 = &uvs[pi0];
        GeoUV* uv1 = &uvs[pi1];
        GeoUV* uv2 = &uvs[pi2];

        LXtVector dPdu, dPdv;
        if (!UVGradient(p0->vec, p1->vec, p2->vec, uv0->uv, uv1->uv, uv2->uv, dPdu, dPdv))
        {
            dPdu[0] = dPdv[0] = 1.0;
            dPdu[1] = dPdv[1] = dPdu[2] = dPdv[2] = 0.0;
        }

        refCounts[pi0]++;
        refCounts[pi1]++;
        refCounts[pi2]++;

        /*
         * Accumulate the dPdus. Vertices shared by more than one
         * face will be finalized in a second pass later on.
         */
        GeoPoint* dPdu0 = &dPdus[pi0];
        GeoPoint* dPdu1 = &dPdus[pi1];
        GeoPoint* dPdu2 = &dPdus[pi2];

        LXx_VADD(dPdu0->vec, dPdu);
        LXx_VADD(dPdu1->vec, dPdu);
        LXx_VADD(dPdu2->vec, dPdu);

        GeoPoint* dPdv0 = &dPdvs[pi0];
        GeoPoint* dPdv1 = &dPdvs[pi1];
        GeoPoint* dPdv2 = &dPdvs[pi2];

        LXx_VADD(dPdv0->vec, dPdv);
        LXx_VADD(dPdv1->vec, dPdv);
        LXx_VADD(dPdv2->vec, dPdv);
    }

    /*
     * Finalize the averages for each dPdu/dPdv vector pair.
     */
    for (pointIndex = 0; pointIndex < points.size(); ++pointIndex)
    {
        unsigned refCount = refCounts[pointIndex];
        if (refCount > 1)
        {
            GeoPoint* dPdu = &dPdus[pointIndex];
            GeoPoint* dPdv = &dPdvs[pointIndex];

            double invN = 1.0 / refCount;

            LXx_VSCL(dPdu->vec, invN);
            LXx_VSCL(dPdv->vec, invN);
        }
    }
}

/*
 * Generate vertex dPdu/dPdv values, with smoothing for shared vertices.
 * This function variant supports convex polygons.
 *
 * If uvsFacevarying boolean parameter is true, that means uvs are specified
 * for each polygon vertex separately, or they are indexed polyInds, via similar
 * to points. In other words, uvsFacevarying means that there is SUM(polyCounts)
 * uvs, for each polygon vertex, one separate uv. This option was introduced for
 * the purpouses of Alembic streaming mesh dpduv calculation.
 */
void lx::GeneratePolyDPDUs(std::vector<GeoPoint>& points,
                           std::vector<GeoUV>&    uvs,
                           bool                   uvsFacevarying,
                           std::vector<unsigned>& polyInds,
                           std::vector<unsigned>& polyCounts,
                           std::vector<GeoPoint>& dPdus,
                           std::vector<GeoPoint>& dPdvs)
{
    /*
     * Zero out the dPdu arrays.
     */
    dPdus.clear();
    dPdvs.clear();
    GeoPoint zeroVec;
    LXx_VCLR(zeroVec.vec);
    unsigned pointIndex;
    for (pointIndex = 0; pointIndex < points.size(); ++pointIndex)
    {
        dPdus.push_back(zeroVec);
        dPdvs.push_back(zeroVec);
    }

    /*
     * Zero out the point reference counts.
     */
    std::vector<unsigned> refCounts;
    for (pointIndex = 0; pointIndex < points.size(); ++pointIndex)
    {
        refCounts.push_back(0);
    }

    int curPolyInd = 0;
    for (unsigned k = 0; k < polyCounts.size(); k++)
    {
        unsigned curPolyCount = polyCounts[k];

        if (curPolyCount <= 2)
            continue;

        /*
         * Concave polygons are simply triangulated by making
         * a triangle fan.
         */
        for (unsigned i = 0; i < curPolyCount - 2; i++)
        {
            /*
             * Fetch the points indexed by the triangle.
             */
            unsigned pi0 = polyInds[curPolyInd];
            unsigned pi1 = polyInds[curPolyInd + i + 1];
            unsigned pi2 = polyInds[curPolyInd + i + 2];

            /*
             * Fetch the points indexed by the triangle.
             */
            GeoPoint* p0 = &points[pi0];
            GeoPoint* p1 = &points[pi1];
            GeoPoint* p2 = &points[pi2];

            GeoUV* uv0;
            GeoUV* uv1;
            GeoUV* uv2;
            if (uvsFacevarying)
            {
                uv0 = &uvs[curPolyInd];
                uv1 = &uvs[curPolyInd + 1];
                uv2 = &uvs[curPolyInd + 2];
            }
            else
            {
                uv0 = &uvs[pi0];
                uv1 = &uvs[pi1];
                uv2 = &uvs[pi2];
            }

            LXtVector dPdu, dPdv;
            if (!UVGradient(p0->vec, p1->vec, p2->vec, uv0->uv, uv1->uv, uv2->uv, dPdu, dPdv))
            {
                dPdu[0] = dPdv[0] = 1.0;
                dPdu[1] = dPdv[1] = dPdu[2] = dPdv[2] = 0.0;
            }

            refCounts[pi0]++;
            refCounts[pi1]++;
            refCounts[pi2]++;

            /*
             * Accumulate the dPdus. Vertices shared by more than one
             * face will be finalized in a second pass later on.
             */
            GeoPoint* dPdu0 = &dPdus[pi0];
            GeoPoint* dPdu1 = &dPdus[pi1];
            GeoPoint* dPdu2 = &dPdus[pi2];

            LXx_VADD(dPdu0->vec, dPdu);
            LXx_VADD(dPdu1->vec, dPdu);
            LXx_VADD(dPdu2->vec, dPdu);

            GeoPoint* dPdv0 = &dPdvs[pi0];
            GeoPoint* dPdv1 = &dPdvs[pi1];
            GeoPoint* dPdv2 = &dPdvs[pi2];

            LXx_VADD(dPdv0->vec, dPdv);
            LXx_VADD(dPdv1->vec, dPdv);
            LXx_VADD(dPdv2->vec, dPdv);
        }

        curPolyInd += curPolyCount;
    }

    /*
     * Finalize the averages for each dPdu/dPdv vector pair.
     */
    for (unsigned _pointIndex = 0; _pointIndex < points.size(); ++_pointIndex)
    {
        unsigned refCount = refCounts[_pointIndex];
        if (refCount > 1)
        {
            GeoPoint* dPdu = &dPdus[_pointIndex];
            GeoPoint* dPdv = &dPdvs[_pointIndex];

            double invN = 1.0 / refCount;

            LXx_VSCL(dPdu->vec, invN);
            LXx_VSCL(dPdv->vec, invN);
        }
    }
}
