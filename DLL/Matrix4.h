#pragma once
#include "Matrix3.h"
#include "Vector3.h"
#include "Vector4.h"

#include <math.h>
#include <iostream>

#ifdef MATHDLL_EXPORTS  
#define  MATHDLL_API __declspec(dllexport)   
#else  
#define MATHDLL_API __declspec(dllimport)   
#endif  
namespace MathDLL {
	//4x4 
	// Xx, Yx ,Zx, Wx
	// Xy, Yy ,Zy, Wy
	// Xz, Yz ,Zz, Wz
	// Xw, Yw ,Zw, Ww
	class MATHDLL_API Matrix4 {
	public:
		union
		{
			struct { float Xx, Xy, Xz, Xw, Yx, Yy, Yz, Yw, Zx, Zy, Zz, Zw, Wx, Wy, Wz, Ww; };
			struct { float mat[16]; };
			struct { float matrix[4][4]; };
			struct { Vector4 xAx, yAx, zAx, wAx; };
			struct { Vector4 axis[4]; };
		};
		int size = 4;

		Matrix4();
		Matrix4(float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float);
		Matrix4(float** ar);
		Matrix4(Matrix3);
		Matrix4(Vector4, Vector4, Vector4, Vector4);
		Matrix4(Vector3, Vector3, Vector3, Vector3);

		Matrix4 operator * (Matrix4);
		Matrix4 operator*(Matrix3 m3);
		Vector4 operator * (Vector4);

		Matrix4 getTranspose();
		void transpose();

		Vector4 & operator [] (const int axis);

		operator float*();
		operator Matrix3();

		void stdPrintMat();

		void setRotateX(float angle);
		void setRotateY(float angle);
		void setRotateZ(float angle);

		void rotateX(float angle);
		void rotateY(float angle);
		void rotateZ(float angle);

		void setRotate(float x, float y, float z);
		void rotate(float x, float y, float z);

		void translate(Vector4 v);
		void translate(Vector3 v);

	};
}