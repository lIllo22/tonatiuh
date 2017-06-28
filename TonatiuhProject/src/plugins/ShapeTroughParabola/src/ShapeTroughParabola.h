/***************************************************************************
Copyright (C) 2008 by the Tonatiuh Software Development Team.

This file is part of Tonatiuh.

Tonatiuh program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.


Acknowledgments:

The development of Tonatiuh was started on 2004 by Dr. Manuel J. Blanco,
then Chair of the Department of Engineering of the University of Texas at
Brownsville. From May 2004 to July 2008, it was supported by the Department
of Energy (DOE) and the National Renewable Energy Laboratory (NREL) under
the Minority Research Associate (MURA) Program Subcontract ACQ-4-33623-06.
During 2007, NREL also contributed to the validation of Tonatiuh under the
framework of the Memorandum of Understanding signed with the Spanish
National Renewable Energy Centre (CENER) on February, 20, 2007 (MOU#NREL-07-117).
Since June 2006, the development of Tonatiuh is being led by the CENER, under the
direction of Dr. Blanco, now Director of CENER Solar Thermal Energy Department.

Developers: Manuel J. Blanco (mblanco@cener.com), Amaia Mutuberria, Victor Martin.

Contributors: Javier Garcia-Barberena, I�aki Perez, Inigo Pagola,  Gilda Jimenez,
Juana Amieva, Azael Mancillas, Cesar Cantu.
***************************************************************************/

#ifndef SHAPETROUGHPARABOLA_H_
#define SHAPETROUGHPARABOLA_H_

#include "TNodeType.h"
#include "TShape.h"

//!  ShapeTroughParabola is the class to represent a surface of parabolic trough geometry.
/*!
  ShapeTroughParabola class provides the methods for a parabolic trough surface. The parameters to define the surface are:
  * - focusLength: the focal length of the parabola.
  * - xMin: the start point of the parabola arc.
  * - xMax: the end point of the parabola arc.
  * - lengthXMin: length of the trough in the xMin point.
  * - lengthXMax: length of the trough in the xMax point
*/
class ShapeTroughParabola : public TShape
{
	Q_OBJECT

private:
	Q_DISABLE_COPY(ShapeTroughParabola)

public:
	static void* CreateInstance();
	static void Init();

	ShapeTroughParabola();


	QString GetIcon();
	BBox GetBondingBox() const;
	TNodeType GetType() const;
	bool Intersect( const Ray& objectRay, double* tHit, DifferentialGeometry* dg, bool* isShapeFront ) const;
	void Draw() const;

protected:
	~ShapeTroughParabola();

private:
	static TNodeType m_nodeType;
};


/*
#include <Inventor/fields/SoSFEnum.h>
#include <Inventor/fields/SoSFDouble.h>
#include <Inventor/fields/SoSFFloat.h>

#include "TShape.h"
#include "trt.h"

class SoSensor;

class ShapeTroughParabola : public TShape
{
	SO_NODE_HEADER(ShapeTroughParabola);

public:
	ShapeTroughParabola( );
	static void initClass();
	double GetArea() const;
	double GetVolume() const {return 0.0;};
	BBox GetBBox() const;
	QString GetIcon() const;

	bool Intersect(const Ray &ray, double *tHit, DifferentialGeometry *dg ) const;
	bool IntersectP( const Ray &ray ) const;

	Point3D Sample( double u, double v) const;

	enum Side{
		INSIDE = 0,
		OUTSIDE   = 1,
	};

	trt::TONATIUH_REAL focusLength;
	trt::TONATIUH_REAL xMin;
	trt::TONATIUH_REAL xMax;
	trt::TONATIUH_REAL lengthXMin;
	trt::TONATIUH_REAL lengthXMax;
	SoSFEnum activeSide;

 
protected:
	static void updateXMinValues( void *data, SoSensor *);
	static void updateXMaxValues( void *data, SoSensor *);

	Point3D GetPoint3D ( double u, double v ) const;
	NormalVector GetNormal( double u, double v ) const;
	bool OutOfRange( double u, double v ) const;

	void computeBBox( SoAction* action, SbBox3f& box, SbVec3f& center);
	void generatePrimitives(SoAction *action);
	virtual ~ShapeTroughParabola();
};

*/

#endif /*SHAPETROUGHPARABOLA_H_*/
