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

}

