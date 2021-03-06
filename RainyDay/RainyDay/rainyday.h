// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 또는 프로젝트 관련 포함 파일이
// 들어 있는 포함 파일입니다.
//
#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용은 Windows 헤더에서 제외합니다.
	// Windows 헤더 파일:
#include <windows.h>
#include <DirectXMath.h>
using namespace DirectX;

namespace RainyDay
{
#ifdef DLL_EXPORTS
#define DLL_API __declspec( dllexport )
#else
#define DLL_API __declspec( dllimport )
#endif

	DLL_API struct Vector4 {
		float x;
		float y;
		float z;
		float w;
	};

	DLL_API struct Vector3 {
		float x;
		float y;
		float z;
	};

	DLL_API struct Vector2 {
		float x;
		float y;
	};

}

