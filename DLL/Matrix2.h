#pragma once
#include "Vector2.h"
#include <iostream>
#include <math.h>
#ifdef MATHDLL_EXPORTS  
#define  MATHDLL_API __declspec(dllexport)   
#else  
#define MATHDLL_API __declspec(dllimport)   
#endif  
namespace MathDLL {
	//2x2 
	// Xx, Yx
	// Xy, Yy
	class MATHDLL_API Matrix2 {
	public:
		union
		{
			struct { float Xx, Xy, Yx, Yy; };
			struct { float mat[4]; };
			struct { float matrix[2][2]; };
			struct { Vector2 xAx, yAx; };
			struct { Vector2 axis[2]; };
		};

		int size = 2;
		 Matrix2();
		 Matrix2(float Xx, float Xy, float Yx, float Yy);
		 Matrix2(float** ar);
		 Matrix2(Vector2 v1, Vector2 v2);

		 Matrix2 operator * (Matrix2 m2);
		 Vector2 operator * (Vector2 v2);
		 Matrix2 operator * (float f);
		//friend operator as float * matrix looks better
		friend MATHDLL_API Matrix2 operator * (float f, Matrix2 m2);

		Matrix2 getTranspose();
		void transpose();

		Vector2& operator [] (const int axis);

		operator float*();

		void setRotate(const float angle);
		void rotate(const float angle);
		void inverse();
		Matrix2 getInverse();

		void stdPrintMat();
	};
}