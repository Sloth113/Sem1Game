#pragma once
#include "Vector2.h"
#include <math.h>
#include <iostream>
#ifdef MATHDLL_EXPORTS  
#define  MATHDLL_API __declspec(dllexport)   
#else  
#define MATHDLL_API __declspec(dllimport)   
#endif  
namespace MathDLL {
	class MATHDLL_API Vector3 {
	public:
		union {
			struct { float x, y, z; };
			struct { float v[3]; };
		};

		Vector3();
		Vector3(float x, float y, float z);
		Vector3(Vector2 & vec2);

		Vector3 Translate(const Vector3 & other);
		Vector3 Add(const Vector3 & other);
		Vector3 Subtract(const Vector3 & other);
		Vector3 Scale(float scalar);
		Vector3 Multiply(float scalar);
		Vector3 Divide(float scalar);

		Vector3  operator +(const Vector3 & other);
		Vector3  operator -(const Vector3 & other);
		Vector3  operator *(float scalar);
		Vector3  operator /(float scalar);
		Vector3 & operator +=(const Vector3 & other);
		Vector3 & operator -=(const Vector3 & other);
		Vector3 & operator *=(float scalar);
		Vector3 & operator /=(float scalar);

		friend MATHDLL_API Vector3 operator * (float scalar, Vector3 vec);

		float& operator[](const int index);
		operator float*();
		operator Vector2();

		float magnitude();
		float getMagSquare();
		Vector3 getNormalised();
		void normalise();

		float dot(const Vector3 & other);
		Vector3 cross(const Vector3 & other);

		void stdPrintVec();
	};
}
