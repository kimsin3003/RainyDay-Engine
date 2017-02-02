// stdafx.h : ���� ��������� ���� ��������� �ʴ�
// ǥ�� �ý��� ���� ���� �Ǵ� ������Ʈ ���� ���� ������
// ��� �ִ� ���� �����Դϴ�.
//
#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // ���� ������ �ʴ� ������ Windows ������� �����մϴ�.
	// Windows ��� ����:
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

