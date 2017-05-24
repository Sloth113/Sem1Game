#pragma once
#include <math.h>
#include <iostream>
#ifdef MATHDLL_EXPORTS  
#define  MATHDLL_API __declspec(dllexport)   
#else  
#define MATHDLL_API __declspec(dllimport)   
#endif  
namespace MathDLL {
	class MATHDLL_API Vector2 {
	protected:

	public:
		union {
			struct { float x, y; };
			struct { float v[2]; };
		};

		Vector2();
		Vector2(float x, float y);

		Vector2 Translate(const Vector2 & other);
		Vector2 Add(const Vector2 & other);
		Vector2 Subtract(const Vector2 & other);
		Vector2 Scale(const float scalar);
		Vector2 Multiply(const float scalar);
		Vector2 Divide(const float scalar);

		Vector2  operator +(const Vector2 & other);
		Vector2  operator -(const Vector2 & other);
		Vector2  operator *(const float scalar);
		Vector2  operator /(const float scalar);

		Vector2 & operator +=(const Vector2 & other);
		Vector2 & operator -=(const Vector2 & other);
		Vector2 & operator *=(const float scalar);
		Vector2 & operator /=(const float scalar);

		//Vector as right hand side
		friend MATHDLL_API Vector2 operator * (float scalar, Vector2 vec);

		float& operator[](const int index);

		operator float*();

		float magnitude();
		float getMagSquare();
		Vector2 getNormalised();
		void normalise();

		float dot(const Vector2 & other);
		float angleBetween(Vector2 & other);

		void stdPrintVec();
	};
}
