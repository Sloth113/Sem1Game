#pragma once
#include "Vector3.h"
#include <math.h>
#include <iostream>
#ifdef MATHDLL_EXPORTS  
#define  MATHDLL_API __declspec(dllexport)   
#else  
#define MATHDLL_API __declspec(dllimport)   
#endif  
namespace MathDLL {
	class MATHDLL_API Vector4 {
	public:
		union {
			struct { float x, y, z, w; };
			struct { float v[4]; };
		};

		Vector4();
		Vector4(float x, float y, float z);
		Vector4(float x, float y, float z, float w);
		Vector4(Vector3 & vec3);
		Vector4(Vector2 & vec2);

		Vector4 Translate(const Vector4 & other);
		Vector4 Add(const Vector4 & other);
		Vector4 Subtract(const Vector4 & other);
		Vector4 Scale(float scalar);
		Vector4 Multiply(float scalar);
		Vector4 Divide(float scalar);

		Vector4  operator +(const Vector4 & other);
		Vector4  operator -(const Vector4 & other);
		Vector4  operator *(float scalar);
		Vector4  operator /(float scalar);
		Vector4 & operator +=(const Vector4 & other);
		Vector4 & operator -=(const Vector4 & other);
		Vector4 & operator *=(float scalar);
		Vector4 & operator /=(float scalar);

		friend MATHDLL_API Vector4 operator * (float scalar, Vector4 vec);

		float& operator[](const int index);
		operator float*();
		operator Vector3();
		operator Vector2();

		float magnitude();
		float getMagSquare();
		Vector4 getNormalised();
		void normalise();

		float dot(const Vector4 & other);
		Vector4 cross(const Vector4 & other);

		void stdPrintVec();
	};
}
