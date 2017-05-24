#pragma once
#include "Vector3.h"
#include "Matrix2.h"

#include <math.h>
#include <iostream>

#ifdef MATHDLL_EXPORTS  
#define  MATHDLL_API __declspec(dllexport)   
#else  
#define MATHDLL_API __declspec(dllimport)   
#endif  
namespace MathDLL {
	//3x3
	// Xx, Yx, Zx
	// Xy, Yy, Zy
	// Xz, Yz, Zz
	class MATHDLL_API Matrix3 {
	public:
		union
		{
			struct { float Xx, Xy, Xz, Yx, Yy, Yz, Zx, Zy, Zz; };
			struct { float mat[9]; };
			struct { float matrix[3][3]; };
			struct { Vector3 xAx, yAx, zAx; };
			struct { Vector3 axis[3]; };
		};
		int size = 3;
		Matrix3();
		Matrix3(float Xx, float Xy, float Xz, float Yx, float Yy, float Yz, float Zx, float Zy, float Zz);
		Matrix3(float** ar);
		Matrix3(Vector3 v1, Vector3 v2, Vector3 v3);
		Matrix3(Matrix2 m2);

		Matrix3 operator * (Matrix3 m3);
		Vector3 operator * (Vector3 v3);
		Matrix3 operator * (float f);
		friend MATHDLL_API Matrix3 operator *(float f, Matrix3 m3);

		Matrix3 getTranspose();
		void transpose();

		Vector3& operator [] (const int axis);

		operator float*();
		operator Matrix2();

		void stdPrintMat();

		void setRotateX(float angle);
		void setRotateY(float angle);
		void setRotateZ(float angle);

		void rotateX(float angle);
		void rotateY(float angle);
		void rotateZ(float angle);

		void setRotate(float x, float y, float z);
		void rotate(float x, float y, float z);
		Matrix3 getInverse();
		void inverse();

		//Homogeneous translation
		void translate(Vector3 v);

	};
}