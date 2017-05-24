#pragma once

#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
#include "Matrix2.h"
#include "Matrix3.h"
#include "Matrix4.h"

#ifdef MATHDLL_EXPORTS  
#define  MATHDLL_API __declspec(dllexport)   
#else  
#define MATHDLL_API __declspec(dllimport)   
#endif  