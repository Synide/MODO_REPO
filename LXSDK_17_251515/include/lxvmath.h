/*
 * LX vmath module
 *
 * Copyright 0000
 */
#ifndef LX_vmath_H
#define LX_vmath_H

	#define LXdND		 3


typedef struct vt_ILxCloudElement ** ILxCloudElementID;
typedef struct vt_ILxSampleCloud ** ILxSampleCloudID;

        
	#include <cmath>
	#include <cfloat>
	#include <lxcom.h>

/*
 * Some definitions for vectors with different underlying types.  The
 * indices are 0=X, 1=Y, 2=Z.
 */

	typedef double		 LXtVector[LXdND];
	typedef float		LXtFVector[LXdND];
	typedef short		LXtSVector[LXdND];
	typedef unsigned int	LXtUVector[LXdND];
	typedef double		 LXtVector2[2];
	typedef float		LXtFVector2[2];
	typedef unsigned int	LXtUVector2[2];
	typedef double		 LXtVector4[4];
	typedef float		LXtFVector4[4];
	typedef unsigned int	LXtUVector4[4];
    // See Also:  LXtVector LXtFVector LXtSVector LXtUVector LXtFVector2 LXtUVector2 LXtVector2 LXtUVector4 LXtFVector4 LXtVector4

/*
 * A matrix is a three by three array of doubles representing a linear system
 * over three variables.  These functions perform the common manipulations
 * over matrices of this type.
 */

	typedef double		 LXtMatrix[LXdND][LXdND];
	typedef float		 LXtFMatrix[LXdND][LXdND];

/*
 * The 4x4 matrix type combines a 3x3 rotation matrix in the upper left corner
 * with a translation vector in the bottom row. The matrix is transposed compared to the
 * 3x3 matrix above. This is to provide compatiblity with other application SDKs (Maya, XSI,
 * Max) allowing our matrices to be used directly and to allow concatentation of matrices to
 * be simplified, the order in which the matrices are multiplied is the order in which they
 * occur.
 * Matrix operations are applied on the right, e.g. multiplying a vector by a matrix is
 * performed as v * m, treating v as a row vector.
 */

	typedef double		 LXtMatrix4[4][4];
	typedef float		 LXtFMatrix4[4][4];


	typedef double		 LXtQuaternion[4];
	typedef float		 LXtFQuaternion[4];


typedef struct st_LXtCloudElementEval {
	const float		*wp;
	const float		*op;
	const float		*wn;
	const float		*wv;	
} LXtCloudElementEval;

/*
 * A bounding box is defined by a min and max pair, or by an extent and center.
 * Either pair can set the other.
 */
typedef struct st_LXtBBox {
	LXtVector		 min;
	LXtVector		 max;
	LXtVector		 extent;
	LXtVector		 center;
} LXtBBox;


typedef struct vt_ILxCloudElement {
	ILxUnknown	 iunk;
	LXxMETHOD(  LxResult,
Density) (
	LXtObjectID		 self,
	LXtObjectID		 sampleVector,
	const LXtFVector	 pos,
	float			*dens);
	
	LXxMETHOD(  LxResult,
AllocSample) (
	LXtObjectID		 self,
	void			*userData,
	void			**data);
	
	LXxMETHOD(  LxResult,
FreeSample) (
	LXtObjectID		 self,
	void			*data);
	
	LXxMETHOD(  LxResult,
EvalSample) (
	LXtObjectID		 self,
	LXtObjectID		 sampleVector,
	void			*userData,
	LXtCloudElementEval	*eval,
	void			*data,
	float			*rad);
	
	LXxMETHOD(  LxResult,
VisitSample) (
	LXtObjectID		 self,
	void			*userData,
	const LXtFVector	 pos,
	void			*data);
	
	LXxMETHOD(  LxResult,
InterpolateSample) (
	LXtObjectID		 self,
	void			*userData,
	const void		*data[3],
	const float		 wgt[3],
	int			 vrtsPerPoly,
	void			*res);	
} ILxCloudElement;

/*
 * - SurfSample
 * This method will sample the current surface given the state of the sample vector.
 * The max and min distances set the how far the samples are from each other and the seed
 * changes the pseudo random sequence.
 * 
 * - BoxSample
 * This method will sample the volume set by the given bbox (in world space).
 * 
 * - SpotSample
 * This method will add a single sample placed at the current spot as set in the sample vector.
 * 
 * - VertexSample
 * This method sample the vertices of the current triangle in the trinagle soup.
 * If 'addElement' is true it will add an element, fi not the xtra data will be attched to the vertex but
 * no octree element will be created thus saving on memory but disabling enumeration.
 * Once the vertices have been sampled, the result is interpolated and set in 'res'
 * 
 * - Enumerate
 * This method will enumerate all the samples in the cloud and call 'VisitSample' for each one.
 * 
 * - BoxEnumerate
 * Same as previous but only enumerates the samples inside the given bounding box.
 */
typedef struct vt_ILxSampleCloud {
	ILxUnknown	 iunk;
	LXxMETHOD(  LxResult,
SurfSample) (
	LXtObjectID		 self,
	LXtObjectID		 sampleVector,
	void			*userData,
	float			 minDist,
	float			 maxDist,
	int			 seed);
	
	LXxMETHOD(  LxResult,
BoxSample) (
	LXtObjectID		 self,
	LXtObjectID		 sampleVector,
	void			*userData,
	LXtBBox			*bbox,
	float			 minDist,
	float			 maxDist,
	int			 seed);
	
	LXxMETHOD(  LxResult,
SpotSample) (
	LXtObjectID		 self,
	LXtObjectID		 sampleVector,
	void			*userData);
	
	LXxMETHOD(  LxResult,
VertexSample) (
	LXtObjectID		 self,
	LXtObjectID		 sampleVector,
	void			*userData,
	int			 addElement,
	int			 all,
	void			*res);

	LXxMETHOD(  LxResult,
Enumerate) (
	LXtObjectID		 self,
	void			*userData);
	
	LXxMETHOD(  LxResult,
BoxEnumerate) (
	LXtObjectID		 self,
	LXtBBox			*bbox,
	void			*userData);
} ILxSampleCloud;

/*
 * These value remapping functions were described by Christophe Schlick in
 * Graphics Gems IV.  Bias moves values toward 0.0 or 1.0, while gain moves them
 * toward or away from 0.5.  A bias or gain of 0.5 leaves the value unchanged.
 */

	#define SCHLICK_BIAS(x, b)	(x) / ((1.0f / (b) - 2.0f) * (1.0f - (x)) + 1.0f)

	#define SCHLICK_GAIN(x, g)	((x) < 0.5f) ?\
					(x) / ((1.0f / (g) - 2.0f) * (1.0f - 2.0f * (x)) + 1.0f) :\
					      ((1.0f / (g) - 2.0f) * (1.0f - 2.0f * (x)) - (x)) /\
					      ((1.0f / (g) - 2.0f) * (1.0f - 2.0f * (x)) - 1.0f)

/*
 * SDK versions don't need the 'ifndef' checks.
 */

	#define LXx_PI		(3.1415926535897932384626433832795)
	#define LXx_TWOPI	(6.2831853071795864769252867665590)
	#define LXx_HALFPI	(1.5707963267948966192313216916398)
	#define LXx_INVPI	(0.31830988618379069121644420192752)
	#define LXx_DEG2RAD	(0.017453292519943295769236907684886)
	#define LXx_RAD2DEG	(57.295779513082320876798154814105)
	#define LXx_ROOT2	(1.4142135623730950488016887242097)
	#define LXx_INVROOT2	(0.70710678118654752440084436210485)
	#define LXx_ROOT3	(1.7320508075688772935274463415059)


	#define LXxMAX(a,b)		((a) > (b) ? (a) : (b))
	#define LXxMIN(a,b)		((a) <= (b) ? (a) : (b))
	#define LXxCLAMP(a,b,c)		(((a) < (b)) ? (b) : (((a) > (c)) ? (c) : (a)))
	#define LXxABS(a)		((a) < 0 ? -(a) : (a))
	#define LXxSIGN(a)		((a) < 0 ? -1 : 1)

/*
 * The '$$' in the code fragment above is replaced with 'LXx_' in all the
 * SDK headers. This allows the same macros to have slightly different forms in
 * different contexts.
 */

	// QWEB_MACRO_BEGIN - Unary $$ macros
	template <typename T, typename U>
	static inline void LXx_VSET (T *a, U const x)
	{
		using arrElemType = decltype(+a[0]);
		auto const value = static_cast<arrElemType> (x);

		a[0] = value;
		a[1] = value;
		a[2] = value;
	}
	template <typename T, typename U>
	static inline void LXx_VSET (T &a, U const x)
	{
		using arrElemType = decltype(+a[0]);
		auto const value = static_cast<arrElemType> (x);

		a[0] = value;
		a[1] = value;
		a[2] = value;
	}

	#define LXx_VCLR(a)		LXx_VSET(a,0.0)

	template <typename T, typename U, typename V, typename W>
	static inline void LXx_VSET3 (T *a, U const x, V const y, W const z)
	{
		using arrElemType = decltype(+a[0]);

		a[0] = static_cast<arrElemType> (x);
		a[1] = static_cast<arrElemType> (y);
		a[2] = static_cast<arrElemType> (z);
	}

	template <typename T, typename U, typename V, typename W>
	static inline void LXx_VSET3 (T &a, U const x, V const y, W const z)
	{
		using arrElemType = decltype(+a[0]);

		a[0] = static_cast<arrElemType> (x);
		a[1] = static_cast<arrElemType> (y);
		a[2] = static_cast<arrElemType> (z);
	}

	
	template <typename T, typename U, typename V, typename W>
	[[deprecated("LXx_V3SET is deprecated, please replace with LXx_VSET3 before the next release, or your code will not compile")]]
	static inline void LXx_V3SET (T *a, U const x, V const y, W const z)
	{
		using arrElemType = decltype(+a[0]);

		a[0] = static_cast<arrElemType> (x);
		a[1] = static_cast<arrElemType> (y);
		a[2] = static_cast<arrElemType> (z);
	}

	template <typename T, typename U, typename V, typename W>
	[[deprecated("LXx_V3SET is deprecated, please replace with LXx_VSET3 before the next release, or your code will not compile")]]
	static inline void LXx_V3SET (T &a, U const x, V const y, W const z)
	{
		using arrElemType = decltype(+a[0]);

		a[0] = static_cast<arrElemType> (x);
		a[1] = static_cast<arrElemType> (y);
		a[2] = static_cast<arrElemType> (z);
	}

	template <typename T, typename U>
	static inline bool LXx_VEQS (T *a, U const x)
	{
		using arrElemType = decltype(+a[0]);
		auto const value = static_cast<arrElemType> (x);

		return a[0] == value && a[1] == value && a[2] == value;
	}

	template <typename T, typename U>
	static inline bool LXx_VEQS (T &a, U const x)
	{
		using arrElemType = decltype(+a[0]);
		auto const value = static_cast<arrElemType> (x);

		return a[0] == value && a[1] == value && a[2] == value;
	}
	
	template <typename T, typename U>
	static inline void LXx_VUNIT (T *a, U const k)
	{
		LXx_VCLR (a);

		using arrElemType = decltype(+a[0]);
		a[k] = static_cast<arrElemType> (1.0);
	}

	template <typename T, typename U>
	static inline void LXx_VUNIT (T &a, U const k)
	{
		LXx_VCLR (a);

		using arrElemType = decltype(+a[0]);
		a[k] = static_cast<arrElemType> (1.0);
	}

	#define LXx_VNEG(v)		((v)[0] = -((v)[0]), (v)[1] = -((v)[1]), (v)[2] = -((v)[2]))
	#define LXx_VUOP(v,op)		((v)[0] = op((v)[0]), (v)[1] = op((v)[1]), (v)[2] = op((v)[2]))
	#define LXx_VUOP2(x,v,op)		((x)[0] = op((v)[0]), (x)[1] = op((v)[1]), (x)[2] = op((v)[2]))
	
	template <typename T, typename U>
	static inline void LXx_V1MIN (T *a, U const x)
	{
		using arrElemType = decltype(+a[0]);
		auto const value = static_cast<arrElemType> (x);

		a[0] = a[0] > value ? value : a[0];
		a[1] = a[1] > value ? value : a[1];
		a[2] = a[2] > value ? value : a[2];
	}

	template <typename T, typename U>
	static inline void LXx_V1MIN (T &a, U const x)
	{
		using arrElemType = decltype(+a[0]);
		auto const value = static_cast<arrElemType> (x);

		a[0] = a[0] > value ? value : a[0];
		a[1] = a[1] > value ? value : a[1];
		a[2] = a[2] > value ? value : a[2];
	}

	template <typename T, typename U>
	static inline void LXx_V1MAX (T *a, U const x)
	{
		using arrElemType = decltype(+a[0]);
		auto const value = static_cast<arrElemType> (x);

		a[0] = a[0] < value ? value : a[0];
		a[1] = a[1] < value ? value : a[1];
		a[2] = a[2] < value ? value : a[2];
	}

	template <typename T, typename U>
	static inline void LXx_V1MAX (T &a, U const x)
	{
		using arrElemType = decltype(+a[0]);
		auto const value = static_cast<arrElemType> (x);

		a[0] = a[0] < value ? value : a[0];
		a[1] = a[1] < value ? value : a[1];
		a[2] = a[2] < value ? value : a[2];
	}
	
	#define LXx_VNEZERO(a)		((a)[0] || (a)[1] || (a)[2])
	// QWEB_MACRO_END - Unary $$ macros


	// QWEB_MACRO_BEGIN - Binary $$ macros

	template <typename T, typename U>
	static inline bool LXx_VEQ (T *a, U *b)
	{
		using arrElemType = decltype(+a[0]);

		return	a[0] == static_cast<arrElemType> (b[0]) &&
			    a[1] == static_cast<arrElemType> (b[1]) &&
			    a[2] == static_cast<arrElemType> (b[2]);
	}

	template <typename T, typename U>
	static inline bool LXx_VEQ (T &a, U &b)
	{
		using arrElemType = decltype(+a[0]);

		return	a[0] == static_cast<arrElemType> (b[0]) &&
			    a[1] == static_cast<arrElemType> (b[1]) &&
			    a[2] == static_cast<arrElemType> (b[2]);
	}

	template <typename T, typename U>
	static inline void LXx_VCPY (T *a, U *b)
	{
		using arrElemType = decltype(+a[0]);

		a[0] = static_cast<arrElemType> (b[0]);
		a[1] = static_cast<arrElemType> (b[1]);
		a[2] = static_cast<arrElemType> (b[2]);
	}

	template <typename T, typename U>
	static inline void LXx_VCPY (T &a, U &b)
	{
		using arrElemType = decltype(+a[0]);

		a[0] = static_cast<arrElemType> (b[0]);
		a[1] = static_cast<arrElemType> (b[1]);
		a[2] = static_cast<arrElemType> (b[2]);
	}

	template <typename T, typename U>
	static inline void LXx_VCPY (T *a, U &b)
	{
		using arrElemType = decltype(+a[0]);

		a[0] = static_cast<arrElemType> (b[0]);
		a[1] = static_cast<arrElemType> (b[1]);
		a[2] = static_cast<arrElemType> (b[2]);
	}

	template <typename T, typename U>
	static inline void LXx_VCPY (T &a, U *b)
	{
		using arrElemType = decltype(+a[0]);

		a[0] = static_cast<arrElemType> (b[0]);
		a[1] = static_cast<arrElemType> (b[1]);
		a[2] = static_cast<arrElemType> (b[2]);
	}

	template <typename T, typename U>
	static inline void LXx_VSCL (T *a, U const x)
	{
		using arrElemType = decltype(+a[0]);
		auto const value = static_cast<arrElemType> (x);

		a[0] *= value;
		a[1] *= value;
		a[2] *= value;
	}

	template <typename T, typename U>
	static inline void LXx_VSCL (T &a, U const x)
	{
		using arrElemType = decltype(+a[0]);
		auto const value = static_cast<arrElemType> (x);

		a[0] *= value;
		a[1] *= value;
		a[2] *= value;
	}
	
	template <typename T, typename U>
	static inline void LXx_VADD (T *a, U *b)
	{
		using arrElemType = decltype(+a[0]);

		a[0] += static_cast<arrElemType> (b[0]);
		a[1] += static_cast<arrElemType> (b[1]);
		a[2] += static_cast<arrElemType> (b[2]);
	}

	template <typename T, typename U>
	static inline void LXx_VADD (T *a, U &b)
	{
		using arrElemType = decltype(+a[0]);

		a[0] += static_cast<arrElemType> (b[0]);
		a[1] += static_cast<arrElemType> (b[1]);
		a[2] += static_cast<arrElemType> (b[2]);
	}

	template <typename T, typename U>
	static inline void LXx_VADD (T &a, U *b)
	{
		using arrElemType = decltype(+a[0]);

		a[0] += static_cast<arrElemType> (b[0]);
		a[1] += static_cast<arrElemType> (b[1]);
		a[2] += static_cast<arrElemType> (b[2]);
	}

	template <typename T, typename U>
	static inline void LXx_VADD (T &a, U &b)
	{
		using arrElemType = decltype(+a[0]);

		a[0] += static_cast<arrElemType> (b[0]);
		a[1] += static_cast<arrElemType> (b[1]);
		a[2] += static_cast<arrElemType> (b[2]);
	}

	template <typename T, typename U>
	static inline void LXx_VSUB (T *a, U *b)
	{
		using arrElemType = decltype(+a[0]);

		a[0] -= static_cast<arrElemType> (b[0]);
		a[1] -= static_cast<arrElemType> (b[1]);
		a[2] -= static_cast<arrElemType> (b[2]);
	}

	template <typename T, typename U>
	static inline void LXx_VSUB (T &a, U &b)
	{
		using arrElemType = decltype(+a[0]);

		a[0] -= static_cast<arrElemType> (b[0]);
		a[1] -= static_cast<arrElemType> (b[1]);
		a[2] -= static_cast<arrElemType> (b[2]);
	}

	template <typename T, typename U, typename V>
	static inline void LXx_VADDS (T *a, U *b, V const x)
	{
		using arrElemType = decltype(+a[0]);
		auto const value = static_cast<arrElemType> (x);

		a[0] += static_cast<arrElemType> (b[0])*value;
		a[1] += static_cast<arrElemType> (b[1])*value;
		a[2] += static_cast<arrElemType> (b[2])*value;
	}

	template <typename T, typename U, typename V>
	static inline void LXx_VADDS (T *a, U &b, V const x)
	{
		using arrElemType = decltype(+a[0]);
		auto const value = static_cast<arrElemType> (x);

		a[0] += static_cast<arrElemType> (b[0])*value;
		a[1] += static_cast<arrElemType> (b[1])*value;
		a[2] += static_cast<arrElemType> (b[2])*value;
	}

	template <typename T, typename U, typename V>
	static inline void LXx_VADDS (T &a, U *b, V const x)
	{
		using arrElemType = decltype(+a[0]);
		auto const value = static_cast<arrElemType> (x);

		a[0] += static_cast<arrElemType> (b[0])*value;
		a[1] += static_cast<arrElemType> (b[1])*value;
		a[2] += static_cast<arrElemType> (b[2])*value;
	}

	template <typename T, typename U, typename V>
	static inline void LXx_VADDS (T &a, U &b, V const x)
	{
		using arrElemType = decltype(+a[0]);
		auto const value = static_cast<arrElemType> (x);

		a[0] += static_cast<arrElemType> (b[0])*value;
		a[1] += static_cast<arrElemType> (b[1])*value;
		a[2] += static_cast<arrElemType> (b[2])*value;
	}

	template <typename T, typename U>
	static inline void LXx_VMUL (T *a, U *b)
	{
		using arrElemType = decltype(+a[0]);

		a[0] *= static_cast<arrElemType> (b[0]);
		a[1] *= static_cast<arrElemType> (b[1]);
		a[2] *= static_cast<arrElemType> (b[2]);
	}

	template <typename T, typename U>
	static inline void LXx_VMUL (T &a, U &b)
	{
		using arrElemType = decltype(+a[0]);

		a[0] *= static_cast<arrElemType> (b[0]);
		a[1] *= static_cast<arrElemType> (b[1]);
		a[2] *= static_cast<arrElemType> (b[2]);
	}

	template <typename T, typename U>
	static inline void LXx_VDIV (T *a, U *b)
	{
		using arrElemType = decltype(+a[0]);

		a[0] /= static_cast<arrElemType> (b[0]);
		a[1] /= static_cast<arrElemType> (b[1]);
		a[2] /= static_cast<arrElemType> (b[2]);
	}

	template <typename T, typename U>
	static inline void LXx_VDIV (T &a, U &b)
	{
		using arrElemType = decltype(+a[0]);

		a[0] /= static_cast<arrElemType> (b[0]);
		a[1] /= static_cast<arrElemType> (b[1]);
		a[2] /= static_cast<arrElemType> (b[2]);
	}
	
	template <typename T, typename U>
	static inline void LXx_V3MIN (T *a, U const *b)
	{
		using arrElemType = decltype(+a[0]);
		arrElemType const vec[] = {static_cast<arrElemType> (b[0]), static_cast<arrElemType> (b[1]), static_cast<arrElemType> (b[2])};

		a[0] = LXxMIN (a[0], vec[0]);
		a[1] = LXxMIN (a[1], vec[1]);
		a[2] = LXxMIN (a[2], vec[2]);
	}

	template <typename T, typename U>
	static inline void LXx_V3MIN (T &a, U const &b)
	{
		using arrElemType = decltype(+a[0]);
		arrElemType const vec[] = {static_cast<arrElemType> (b[0]), static_cast<arrElemType> (b[1]), static_cast<arrElemType> (b[2])};

		a[0] = LXxMIN (a[0], vec[0]);
		a[1] = LXxMIN (a[1], vec[1]);
		a[2] = LXxMIN (a[2], vec[2]);
	}

	template <typename T, typename U>
	static inline void LXx_V3MAX (T *a, U const *b)
	{
		using arrElemType = decltype(+a[0]);
		arrElemType const vec[] = {static_cast<arrElemType> (b[0]), static_cast<arrElemType> (b[1]), static_cast<arrElemType> (b[2])};

		a[0] = LXxMAX (a[0], vec[0]);
		a[1] = LXxMAX (a[1], vec[1]);
		a[2] = LXxMAX (a[2], vec[2]);
	}

	template <typename T, typename U>
	static inline void LXx_V3MAX (T &a, U const &b)
	{
		using arrElemType = decltype(+a[0]);
		arrElemType const vec[] = {static_cast<arrElemType> (b[0]), static_cast<arrElemType> (b[1]), static_cast<arrElemType> (b[2])};

		a[0] = LXxMAX (a[0], vec[0]);
		a[1] = LXxMAX (a[1], vec[1]);
		a[2] = LXxMAX (a[2], vec[2]);
	}

	template <typename T, typename U>
	static inline void LXx_V2CPY (T *a, U *b)
	{
		using arrElemType = decltype(+a[0]);

		a[0] = static_cast<arrElemType> (b[0]);
		a[1] = static_cast<arrElemType> (b[1]);
	}

	template <typename T, typename U>
	static inline void LXx_V2CPY(T& a, U& b)
	{
		using arrElemType = decltype(+a[0]);

		a[0] = static_cast<arrElemType> (b[0]);
		a[1] = static_cast<arrElemType> (b[1]);
	}

	#define LXx_V2SCL(a,x)             ((a)[0]*= (x),   (a)[1]*= (x))
	#define LXx_V2ADD(a,b)             ((a)[0]+=(b)[0], (a)[1]+=(b)[1])
	#define LXx_V2SUB(a,b)             ((a)[0]-=(b)[0], (a)[1]-=(b)[1])
	#define LXx_V2ADDS(a,b,x)          ((a)[0]+=(b)[0]*(x), (a)[1]+=(b)[1]*(x))
	#define LXx_V2MUL(a,b)             ((a)[0] *=(b)[0], (a)[1] *=(b)[1])
	#define LXx_V2DIV(a,b)             ((a)[0] /=(b)[0], (a)[1] /=(b)[1])

	// QWEB_MACRO_END - Binary $$ macros


	// QWEB_MACRO_BEGIN - Trinary $$ macros
	template <typename T, typename U, typename V>
	static inline void LXx_VADD3 (T *r, U const *a, V const *b)
	{
		using arrElemType = decltype(+r[0]);
		arrElemType const vec1[] = {static_cast<arrElemType> (a[0]), static_cast<arrElemType> (a[1]), static_cast<arrElemType> (a[2])};
		arrElemType const vec2[] = {static_cast<arrElemType> (b[0]), static_cast<arrElemType> (b[1]), static_cast<arrElemType> (b[2])};

		r[0] = vec1[0] + vec2[0];
		r[1] = vec1[1] + vec2[1];
		r[2] = vec1[2] + vec2[2];
	}

	template <typename T, typename U, typename V>
	static inline void LXx_VADD3 (T &r, U const &a, V const &b)
	{
		using arrElemType = decltype(+r[0]);
		arrElemType const vec1[] = {static_cast<arrElemType> (a[0]), static_cast<arrElemType> (a[1]), static_cast<arrElemType> (a[2])};
		arrElemType const vec2[] = {static_cast<arrElemType> (b[0]), static_cast<arrElemType> (b[1]), static_cast<arrElemType> (b[2])};
		
		r[0] = vec1[0] + vec2[0];
		r[1] = vec1[1] + vec2[1];
		r[2] = vec1[2] + vec2[2];
	}
	
	template <typename T, typename U, typename V>
	static inline void LXx_VSUB3 (T *r, U const *a, V const *b)
	{
		using arrElemType = decltype(+r[0]);
		arrElemType const vec1[] = {static_cast<arrElemType> (a[0]), static_cast<arrElemType> (a[1]), static_cast<arrElemType> (a[2])};
		arrElemType const vec2[] = {static_cast<arrElemType> (b[0]), static_cast<arrElemType> (b[1]), static_cast<arrElemType> (b[2])};
		
		r[0] = vec1[0] - vec2[0];
		r[1] = vec1[1] - vec2[1];
		r[2] = vec1[2] - vec2[2];
	}

	template <typename T, typename U, typename V>
	static inline void LXx_VSUB3 (T &r, U const &a, V const &b)
	{
		using arrElemType = decltype(+r[0]);
		arrElemType const vec1[] = {static_cast<arrElemType> (a[0]), static_cast<arrElemType> (a[1]), static_cast<arrElemType> (a[2])};
		arrElemType const vec2[] = {static_cast<arrElemType> (b[0]), static_cast<arrElemType> (b[1]), static_cast<arrElemType> (b[2])};

		r[0] = vec1[0] - vec2[0];
		r[1] = vec1[1] - vec2[1];
		r[2] = vec1[2] - vec2[2];
	}

	template <typename T, typename U, typename V>
	static inline void LXx_VSCL3 (T *r, U const *a, V const x)
	{
		using arrElemType = decltype(+r[0]);
		auto const value = static_cast<arrElemType> (x);

		r[0] = static_cast<arrElemType> (a[0])*value;
		r[1] = static_cast<arrElemType> (a[1])*value;
		r[2] = static_cast<arrElemType> (a[2])*value;
	}

	template <typename T, typename U, typename V>
	static inline void LXx_VSCL3 (T *r, U const &a, V const x)
	{
		using arrElemType = decltype(+r[0]);
		auto const value = static_cast<arrElemType> (x);

		r[0] = static_cast<arrElemType> (a[0])*value;
		r[1] = static_cast<arrElemType> (a[1])*value;
		r[2] = static_cast<arrElemType> (a[2])*value;
	}

	template <typename T, typename U, typename V>
	static inline void LXx_VSCL3 (T &r, U const *a, V const x)
	{
		using arrElemType = decltype(+r[0]);
		auto const value = static_cast<arrElemType> (x);

		r[0] = static_cast<arrElemType> (a[0])*value;
		r[1] = static_cast<arrElemType> (a[1])*value;
		r[2] = static_cast<arrElemType> (a[2])*value;
	}

	template <typename T, typename U, typename V>
	static inline void LXx_VSCL3 (T &r, U const &a, V const x)
	{
		using arrElemType = decltype(+r[0]);
		auto const value = static_cast<arrElemType> (x);

		r[0] = static_cast<arrElemType> (a[0])*value;
		r[1] = static_cast<arrElemType> (a[1])*value;
		r[2] = static_cast<arrElemType> (a[2])*value;
	}
	
	template <typename T, typename U, typename V>
	static inline void LXx_VMUL3 (T *r, U const *a, V const *b)
	{
		using arrElemType = decltype(+r[0]);
		arrElemType const vec1[] = {static_cast<arrElemType> (a[0]), static_cast<arrElemType> (a[1]), static_cast<arrElemType> (a[2])};
		arrElemType const vec2[] = {static_cast<arrElemType> (b[0]), static_cast<arrElemType> (b[1]), static_cast<arrElemType> (b[2])};
		
		r[0] = vec1[0] * vec2[0];
		r[1] = vec1[1] * vec2[1];
		r[2] = vec1[2] * vec2[2];
	}

	template <typename T, typename U, typename V>
	static inline void LXx_VMUL3 (T &r, U const &a, V const &b)
	{
		using arrElemType = decltype(+r[0]);
		arrElemType const vec1[] = {static_cast<arrElemType> (a[0]), static_cast<arrElemType> (a[1]), static_cast<arrElemType> (a[2])};
		arrElemType const vec2[] = {static_cast<arrElemType> (b[0]), static_cast<arrElemType> (b[1]), static_cast<arrElemType> (b[2])};

		r[0] = vec1[0] * vec2[0];
		r[1] = vec1[1] * vec2[1];
		r[2] = vec1[2] * vec2[2];
	}

	#define LXx_VBOP3(r,a,b,op)	((r)[0]=op((a)[0],(b)[0]), (r)[1]=op((a)[1],(b)[1]), (r)[2]=op((a)[2],(b)[2]))

	template <typename T, typename U, typename V, typename W>
	static inline void LXx_V2ADDS3 (T *r, U const *a, V const *b, W const &x)
	{
		using arrElemType = decltype(+r[0]);
		arrElemType const vec1[] = {static_cast<arrElemType> (a[0]), static_cast<arrElemType> (a[1])};
		arrElemType const vec2[] = {static_cast<arrElemType> (b[0]), static_cast<arrElemType> (b[1])};
		auto const value = static_cast<arrElemType> (x);

		r[0] = vec1[0] + vec2[0]*value;
		r[1] = vec1[1] + vec2[1]*value;
	}

	template <typename T, typename U, typename V, typename W>
	static inline void LXx_V2ADDS3 (T &r, U const &a, V const &b, W const &x)
	{
		using arrElemType = decltype(+r[0]);
		arrElemType const vec1[] = {static_cast<arrElemType> (a[0]), static_cast<arrElemType> (a[1])};
		arrElemType const vec2[] = {static_cast<arrElemType> (b[0]), static_cast<arrElemType> (b[1])};
		auto const value = static_cast<arrElemType> (x);

		r[0] = vec1[0] + vec2[0]*value;
		r[1] = vec1[1] + vec2[1]*value;
	}
	
	template <typename T, typename U, typename V>
	static inline void LXx_VMIN3 (T *r, U const *a, V const *b)
	{
		using arrElemType = decltype(+r[0]);
		arrElemType const vec1[] = {static_cast<arrElemType> (a[0]), static_cast<arrElemType> (a[1]), static_cast<arrElemType> (a[2])};
		arrElemType const vec2[] = {static_cast<arrElemType> (b[0]), static_cast<arrElemType> (b[1]), static_cast<arrElemType> (b[2])};

		r[0] = LXxMIN (vec1[0], vec2[0]);
		r[1] = LXxMIN (vec1[1], vec2[1]);
		r[2] = LXxMIN (vec1[2], vec2[2]);
	}

	template <typename T, typename U, typename V>
	static inline void LXx_VMIN3 (T &r, U const &a, V const &b)
	{
		using arrElemType = decltype(+r[0]);
		arrElemType const vec1[] = {static_cast<arrElemType> (a[0]), static_cast<arrElemType> (a[1]), static_cast<arrElemType> (a[2])};
		arrElemType const vec2[] = {static_cast<arrElemType> (b[0]), static_cast<arrElemType> (b[1]), static_cast<arrElemType> (b[2])};

		r[0] = LXxMIN (vec1[0], vec2[0]);
		r[1] = LXxMIN (vec1[1], vec2[1]);
		r[2] = LXxMIN (vec1[2], vec2[2]);
	}

	template <typename T, typename U, typename V>
	static inline void LXx_VMAX3 (T *r, U const *a, V const *b)
	{
		using arrElemType = decltype(+r[0]);
		arrElemType const vec1[] = {static_cast<arrElemType> (a[0]), static_cast<arrElemType> (a[1]), static_cast<arrElemType> (a[2])};
		arrElemType const vec2[] = {static_cast<arrElemType> (b[0]), static_cast<arrElemType> (b[1]), static_cast<arrElemType> (b[2])};

		r[0] = LXxMAX (vec1[0], vec2[0]);
		r[1] = LXxMAX (vec1[1], vec2[1]);
		r[2] = LXxMAX (vec1[2], vec2[2]);
	}

	template <typename T, typename U, typename V>
	static inline void LXx_VMAX3 (T &r, U const &a, V const &b)
	{
		using arrElemType = decltype(+r[0]);
		arrElemType const vec1[] = {static_cast<arrElemType> (a[0]), static_cast<arrElemType> (a[1]), static_cast<arrElemType> (a[2])};
		arrElemType const vec2[] = {static_cast<arrElemType> (b[0]), static_cast<arrElemType> (b[1]), static_cast<arrElemType> (b[2])};

		r[0] = LXxMAX (vec1[0], vec2[0]);
		r[1] = LXxMAX (vec1[1], vec2[1]);
		r[2] = LXxMAX (vec1[2], vec2[2]);
	}

	template <typename T, typename U, typename V>
	static inline void LXx_V2ADD3 (T *r, U const *a, V const *b)
	{
		using arrElemType = decltype(+r[0]);
		arrElemType const vec1[] = {static_cast<arrElemType> (a[0]), static_cast<arrElemType> (a[1])};
		arrElemType const vec2[] = {static_cast<arrElemType> (b[0]), static_cast<arrElemType> (b[1])};

		r[0] = vec1[0] + vec2[0];
		r[1] = vec1[1] + vec2[1];
	}

	template <typename T, typename U, typename V>
	static inline void LXx_V2ADD3 (T &r, U const &a, V const &b)
	{
		using arrElemType = decltype(+r[0]);
		arrElemType const vec1[] = {static_cast<arrElemType> (a[0]), static_cast<arrElemType> (a[1])};
		arrElemType const vec2[] = {static_cast<arrElemType> (b[0]), static_cast<arrElemType> (b[1])};

		r[0] = vec1[0] + vec2[0];
		r[1] = vec1[1] + vec2[1];
	}

	template <typename T, typename U, typename V, typename W>
	static inline void LXx_VADDS3 (T *r, U const *a, V const *b, W const &x)
	{
		using arrElemType = decltype(+r[0]);
		arrElemType const vec1[] = {static_cast<arrElemType> (a[0]), static_cast<arrElemType> (a[1]), static_cast<arrElemType> (a[2])};
		arrElemType const vec2[] = {static_cast<arrElemType> (b[0]), static_cast<arrElemType> (b[1]), static_cast<arrElemType> (b[2])};
		auto const value = static_cast<arrElemType> (x);

		r[0] = vec1[0] + vec2[0]*value;
		r[1] = vec1[1] + vec2[1]*value;
		r[2] = vec1[2] + vec2[2]*value;
	}

	template <typename T, typename U, typename V, typename W>
	static inline void LXx_VADDS3 (T &r, U const &a, V const &b, W const &x)
	{
		using arrElemType = decltype(+r[0]);
		arrElemType const vec1[] = {static_cast<arrElemType> (a[0]), static_cast<arrElemType> (a[1]), static_cast<arrElemType> (a[2])};
		arrElemType const vec2[] = {static_cast<arrElemType> (b[0]), static_cast<arrElemType> (b[1]), static_cast<arrElemType> (b[2])};
		auto const value = static_cast<arrElemType> (x);

		r[0] = vec1[0] + vec2[0]*value;
		r[1] = vec1[1] + vec2[1]*value;
		r[2] = vec1[2] + vec2[2]*value;
	}

	template <typename T, typename U, typename V>
	static inline void LXx_V2SUB3 (T *r, U const *a, V const *b)
	{
		using arrElemType = decltype(+r[0]);
		arrElemType const vec1[] = {static_cast<arrElemType> (a[0]), static_cast<arrElemType> (a[1])};
		arrElemType const vec2[] = {static_cast<arrElemType> (b[0]), static_cast<arrElemType> (b[1])};

		r[0] = vec1[0] - vec2[0];
		r[1] = vec1[1] - vec2[1];
	}

	template <typename T, typename U, typename V>
	static inline void LXx_V2SUB3 (T &r, U const &a, V const &b)
	{
		using arrElemType = decltype(+r[0]);
		arrElemType const vec1[] = {static_cast<arrElemType> (a[0]), static_cast<arrElemType> (a[1])};
		arrElemType const vec2[] = {static_cast<arrElemType> (b[0]), static_cast<arrElemType> (b[1])};

		r[0] = vec1[0] - vec2[0];
		r[1] = vec1[1] - vec2[1];
	}

	#define LXx_V2SCL3(r,a,x)          ((r)[0]=(a)[0]*(x),    (r)[1]=(a)[1]*(x))
	#define LXx_V2MUL3(r,a,b)          ((r)[0]=(a)[0]*(b)[0], (r)[1]=(a)[1]*(b)[1])
	#define LXx_V2MIN3(r,a,b)		LXx_V2BOP3(r,a,b,LXxMIN)
	#define LXx_V2MAX3(r,a,b)		LXx_V2BOP3(r,a,b,LXxMAX)
	// QWEB_MACRO_END - Trinary $$ macros


	// QWEB_MACRO_BEGIN - RGBA $$ macros
	#define LXx_V4BLACK(a)		LXx_V4SET4(a,0,0,0,1)
	#define LXx_V4ZERO(a)		LXx_V4SET4(a,0,0,0,0)
	#define LXx_V4SET(a,x)		LXx_V4SET4(a,x,x,x,x)
	#define LXx_V4SET4(a,x,y,z,w)	((a)[0] =(x),               (a)[1] =(y),               (a)[2] =(z),               (a)[3] =(w))

	template <typename T, typename U>
	static inline void LXx_V4CPY (T *a, U *b)
	{
		using arrElemType = decltype(+a[0]);

		a[0] = static_cast<arrElemType> (b[0]);
		a[1] = static_cast<arrElemType> (b[1]);
		a[2] = static_cast<arrElemType> (b[2]);
		a[3] = static_cast<arrElemType> (b[3]);
	}

	template <typename T, typename U>
	static inline void LXx_V4CPY (T &a, U &b)
	{
		using arrElemType = decltype(+a[0]);

		a[0] = static_cast<arrElemType> (b[0]);
		a[1] = static_cast<arrElemType> (b[1]);
		a[2] = static_cast<arrElemType> (b[2]);
	}

	#define LXx_V4ADD(a,b)		((a)[0]+=(b)[0],            (a)[1]+=(b)[1],            (a)[2]+=(b)[2],            (a)[3]+=(b)[3])
	#define LXx_V4ADD3(r,a,b)		((r)[0] =(a)[0]+(b)[0],     (r)[1] =(a)[1]+(b)[1],     (r)[2] =(a)[2]+(b)[2],     (r)[3] =(a)[3]+(b)[3])
	#define LXx_V4ADDS(a,b,x)		((a)[0]+=(b)[0]*(x),        (a)[1]+=(b)[1]*(x),        (a)[2]+=(b)[2]*(x),        (a)[3]+=(b)[3]*(x))
	#define LXx_V4ADDS3(r,a,b,x)	((r)[0] =(a)[0]+(b)[0]*(x), (r)[1] =(a)[1]+(b)[1]*(x), (r)[2] =(a)[2]+(b)[2]*(x), (r)[3] =(a)[3]+(b)[3]*(x))
	#define LXx_V4SUB(a,b)		((a)[0]-=(b)[0],            (a)[1]-=(b)[1],            (a)[2]-=(b)[2],            (a)[3]-=(b)[3])
	#define LXx_V4SCL(a,x)		((a)[0]*=(x),               (a)[1]*=(x),               (a)[2]*=(x),               (a)[3]*=(x))
	#define LXx_V4SCL3(r,a,x)		((r)[0] =(a)[0]*(x),        (r)[1] =(a)[1]*(x),        (r)[2] =(a)[2]*(x),        (r)[3] =(a)[3]*(x))
	#define LXx_V4DOT(a,b)		((a)[0]*(b)[0] + (a)[1]*(b)[1] + (a)[2]*(b)[2] + (a)[3]*(b)[3])
	#define LXx_V4EQ(a,b)		((a)[0]==(b)[0]&&(a)[1]==(b)[1]&&(a)[2]==(b)[2]&&(a)[3]==(b)[3])
	// QWEB_MACRO_END - RGBA $$ macros


	// QWEB_MACRO_BEGIN - Special $$ macros
	#define LXx_VDOT(a,b)		((a)[0]*(b)[0] + (a)[1]*(b)[1] + (a)[2]*(b)[2])
	#define LXx_VDOT3(a,x,y,z)	((a)[0]*(x)    + (a)[1]*(y)    + (a)[2]*(z))
	#define LXx_VLEN(a)		sqrt (LXx_VDOT(a,a))
	#define LXx_VLENSQ(a)		LXx_VDOT(a,a)
	#define LXx_VDIST(a,b)		sqrt (LXx_VDIST2(a,b))
	#define LXx_VDIST2(a,b)		( ((a)[0] - (b)[0]) * ((a)[0] - (b)[0]) +\
					  ((a)[1] - (b)[1]) * ((a)[1] - (b)[1]) +\
					  ((a)[2] - (b)[2]) * ((a)[2] - (b)[2]) )

	template <typename T, typename U, typename V>
	static inline void LXx_VCROSS (T *r, U *a, V *b)
	{
		using arrElemType = decltype(+r[0]);
		arrElemType const vec1[] = {static_cast<arrElemType> (a[0]), static_cast<arrElemType> (a[1]), static_cast<arrElemType> (a[2])};
		arrElemType const vec2[] = {static_cast<arrElemType> (b[0]), static_cast<arrElemType> (b[1]), static_cast<arrElemType> (b[2])};

		r[0] = vec1[1]*vec2[2]-vec1[2]*vec2[1];
		r[1] = vec1[2]*vec2[0]-vec1[0]*vec2[2];
		r[2] = vec1[0]*vec2[1]-vec1[1]*vec2[0];
	}

	template <typename T, typename U, typename V>
	static inline void LXx_VCROSS (T &r, U &a, V &b)
	{
		using arrElemType = decltype(+r[0]);
		arrElemType const vec1[] = {static_cast<arrElemType> (a[0]), static_cast<arrElemType> (a[1]), static_cast<arrElemType> (a[2])};
		arrElemType const vec2[] = {static_cast<arrElemType> (b[0]), static_cast<arrElemType> (b[1]), static_cast<arrElemType> (b[2])};

		r[0] = vec1[1]*vec2[2]-vec1[2]*vec2[1];
		r[1] = vec1[2]*vec2[0]-vec1[0]*vec2[2];
		r[2] = vec1[0]*vec2[1]-vec1[1]*vec2[0];
	}

	template <typename T, typename U, typename V, typename W>
	static inline void LXx_VLERP (T *r, U *a, V *b, W const c)
	{
		using arrElemType = decltype(+r[0]);
		arrElemType const vec1[] = {static_cast<arrElemType> (a[0]), static_cast<arrElemType> (a[1]), static_cast<arrElemType> (a[2])};
		arrElemType const vec2[] = {static_cast<arrElemType> (b[0]), static_cast<arrElemType> (b[1]), static_cast<arrElemType> (b[2])};
		auto const value = static_cast<arrElemType> (c);

		r[0] = vec1[0] + value*(vec2[0]-vec1[0]);
		r[1] = vec1[1] + value*(vec2[1]-vec1[1]);
		r[2] = vec1[2] + value*(vec2[2]-vec1[2]);
	}

	template <typename T, typename U, typename V, typename W>
	static inline void LXx_VLERP (T &r, U &a, V &b, W const c)
	{
		using arrElemType = decltype(+r[0]);
		arrElemType const vec1[] = {static_cast<arrElemType> (a[0]), static_cast<arrElemType> (a[1]), static_cast<arrElemType> (a[2])};
		arrElemType const vec2[] = {static_cast<arrElemType> (b[0]), static_cast<arrElemType> (b[1]), static_cast<arrElemType> (b[2])};
		auto const value = static_cast<arrElemType> (c);

		r[0] = vec1[0] + value*(vec2[0]-vec1[0]);
		r[1] = vec1[1] + value*(vec2[1]-vec1[1]);
		r[2] = vec1[2] + value*(vec2[2]-vec1[2]);
	}

	#define LXx_VLERP_TO(r,a,b,c)	( (r)[0] = (a)[0] + (c)*((b) - (a)[0]),\
					  (r)[1] = (a)[1] + (c)*((b) - (a)[1]),\
					  (r)[2] = (a)[2] + (c)*((b) - (a)[2]) )
	#define LXx_VLERP_FROM(r,a,b,c)   ( (r)[0] = (a) + (c)*((b)[0] - (a)),\
					  (r)[1] = (a) + (c)*((b)[1] - (a)),\
					  (r)[2] = (a) + (c)*((b)[2] - (a)) )
	#define LXx_V4LERP(r,a,b,c)	( (r)[0] = (a)[0] + (c)*((b)[0] - (a)[0]),\
					  (r)[1] = (a)[1] + (c)*((b)[1] - (a)[1]),\
					  (r)[2] = (a)[2] + (c)*((b)[2] - (a)[2]),\
					  (r)[3] = (a)[3] + (c)*((b)[3] - (a)[3]) )
	#define LXx_LUMAFV(a)		(0.30f * (a)[0] + 0.59f * (a)[1] + 0.11f * (a)[2])

	#define	LXx_COMPOSE_RGB(a,b,c,d)	( (a)[0] = (b)[0]*(1 - (d)) + (c)[0]*(d),\
					  (a)[1] = (b)[1]*(1 - (d)) + (c)[1]*(d),\
					  (a)[2] = (b)[2]*(1 - (d)) + (c)[2]*(d) )

	#define LXx_HP_TO_VECTOR(v,h,p)	( (v)[2] = cos((p)),\
					  (v)[0] = cos((h))*(v)[2],\
					  (v)[1] = sin((p)),\
					  (v)[2]*= sin((h)) )

	#define LXx_BYTE_FRACTION		(0.003921568627451f)
	#define LXx_BYTE_TO_FLOAT(b)	((float)(b) * LXx_BYTE_FRACTION)
	#define LXx_FLOAT_TO_BYTE(f)	((unsigned char) Dnint ((f) * 255.0))

	#define LXx_VPERP(a,b)		( (a)[0]=((b)[1]-(b)[2]), (a)[1]=((b)[2]-(b)[0]), (a)[2]=((b)[0]-(b)[1]) )

	#define LXx_V2DOT(a,b)             ((a)[0]*(b)[0] + (a)[1]*(b)[1])
	#define LXx_V2LEN(a)               sqrt (LXx_V2DOT(a,a))
	#define LXx_V2LENSQ(a)             LXx_V2DOT(a,a)
	#define LXx_V2DIST(a,b)            sqrt (LXx_V2DIST2(a,b))
	#define LXx_V2DIST2(a,b)           ( ((a)[0] - (b)[0]) * ((a)[0] - (b)[0]) + ((a)[1] - (b)[1]) * ((a)[1] - (b)[1]) )
	#define LXx_V2PERP(a,b)		 ( (a)[0]=-(b)[1], (a)[1]=(b)[0] )
	// QWEB_MACRO_END - Special $$ macros


	#define LXu_CLOUDELEMENT		"d738ab9f-1d5f-4ef5-aeb0-689279604b24"
	#define LXa_CLOUDELEMENT		"cloudelement"
	// [export]  ILxCloudElement celt


	#define LXu_SAMPLECLOUD		"813c9868-88af-4169-8149-38beaeae5923"
	#define LXa_SAMPLECLOUD		"samplecloud"
	// [local]  ILxSampleCloud	

#endif