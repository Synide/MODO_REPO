/*
 * Plug-in SDK Header: C++ Services
 *
 * Copyright 0000
 *
 * Helper class for doing math with modo quaternions.
 */

#ifndef LX_QUATERNION_HPP
#define LX_QUATERNION_HPP

#include <lxvmath.h>
#include <lxu_vector.hpp>


class CLxMatrix4;

class CLxQuaternion
{
public:
	LXtQuaternion	q;

	 CLxQuaternion();
	~CLxQuaternion();
	
	CLxQuaternion(const CLxQuaternion &src);
	CLxQuaternion(double xx, double yy, double zz, double ww);
	CLxQuaternion(const double qq[4]);
	CLxQuaternion (const CLxVector &axis, double angle);
	CLxQuaternion(const CLxVector &v0, const CLxVector &v1);
	CLxQuaternion( const CLxMatrix4& mat);

	CLxMatrix4	asMatrix() const;

	CLxQuaternion& Conjugate ()  ;
	CLxQuaternion Conjugated () const ;
	
	CLxQuaternion &	operator=(const CLxMatrix4& mat);
	CLxQuaternion &	operator=(const CLxQuaternion& src) ;
	
	
	/**@brief Return the length squared of the quaternion */
	double lengthSquared() const ;
	
	/**@brief Return the length of the quaternion */
	double length() const ;
	
	
	/**@brief Scale this quaternion
	 * @param s The scalar to scale by */
	CLxQuaternion& operator*=(const double s) ;
	
	/**@brief Return scaled quaternion
	 * @param s The scalar to scale by */
	CLxQuaternion operator*(const double s) ;
	
	/**@brief Inversely scale this quaternion
	 * @param s The scale factor */
	CLxQuaternion& operator/=(const double s) ;
	
	/**@brief Return inversely scaled quaternion
	 * @param s The scale factor */
	CLxQuaternion operator/(const double s) const ;
	
	
	CLxQuaternion& normalize() ;
	CLxQuaternion normal() const ;
	
	
	/**@brief Return the dot product between this quaternion and another
	 * @param q The other quaternion */
	double dot(const CLxQuaternion& qq) const ;
	
	
	// Slerp interpolates from this quat to given quat by t.
	CLxQuaternion slerp(const CLxQuaternion& qq, const double t) const ;
	
	
	/**@brief Return the product of two quaternions */
	CLxQuaternion operator*( const CLxQuaternion& qq) ;
	
	CLxQuaternion operator*( const CLxVector& vv ) ;
	CLxQuaternion operator+(const CLxQuaternion& qq) const ;
	CLxQuaternion operator-(const CLxQuaternion& qq) const ;

	bool operator==(const CLxQuaternion &qq) const ;
	bool operator!=(const CLxQuaternion &qq) const ;

	bool epsilonEquals (const CLxQuaternion &other, double epsilon = 1.0e-8 ) const ;

	/**@brief Return the negative of this quaternion
	 * This simply negates each element */
	CLxQuaternion operator-() const ;

	/**@brief Return the inverse of this quaternion */
	CLxQuaternion inverse() const ;

	/**@brief Invert this quaternion */
	CLxQuaternion& invert() ;
	
	static const CLxQuaternion&	getIdentity() ;
	
	double operator[] (unsigned int i) const ;
	double& operator[] (unsigned int i) ;
	
	/**@brief Return the x value */
	const double& x() const ;
	/**@brief Return the y value */
	const double& y() const ;
	/**@brief Return the z value */
	const double& z() const ;
	/**@brief Return the w value */
	const double& w() const ;
	
};

std::ostream& operator<< (std::ostream& stream, const CLxQuaternion& quat) ;

#endif	/* LX_QUATERNION_HPP */
