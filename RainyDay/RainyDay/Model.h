#pragma once
#include <d3d11.h>
#include <vector>
#include "Camera.h"
#include "Object.h"
#include "Vertex.h"
#include "Shader.h"

namespace RainyDay {

	class DLL_API PreLoadedData {
	public:
		std::vector<Vertex>		vertices;
		std::vector<WORD>			indices;
	};

	class DLL_API Model : public Object
	{
	public:
		Model();
		virtual ~Model();
		bool IsUI() { return m_isUI; };

		static PreLoadedData* PreLoadFromFile(std::string filename);
		void LoadFromPreLoadedData(PreLoadedData* data);
		void LoadFromFile(std::string filename);
		HRESULT CreateVertexBuffer(ID3D11Device* device);
		HRESULT CreateIndexBuffer(ID3D11Device* device);
		ID3D11Buffer*& GetVB() { return m_vertexBuffer; };
		ID3D11Buffer*& GetIB() { return m_indexBuffer; };
		int GetTransparency() { return m_transparency; };
		Shader* GetShader() { return m_shader; };
		void SetShader(Shader* shader) { m_shader = shader; };
		void SetTransParency(float alpha);

		void ReleaseVB();
		void ReleaseIB();
		UINT indexSize() { return m_indices.size(); };

		void SetSample();
		void SetToCube(XMFLOAT3 boxSize);
		void SetToBackground(float width, float height, XMFLOAT3 normal);
		void SetToRectangle(float width, float height, XMFLOAT3 normal);
		void SetTextureName(WCHAR* textureName);
		void SetColor(float r, float g, float b, float a);
		void SetRGB(float r, float g, float b);
		void SetAlpha(float a);
		void RotationToCamera(Camera& c);

		inline DirectX::XMFLOAT4 GetColor() { return m_rgba; };
		WCHAR*& GetTextureName() { return m_textureName; };


	protected:
		void AddRectangle(Vertex& v1, Vertex& v2, Vertex& v3, Vertex& v4);
		bool m_vertexIsChanged = true;

		WCHAR*						m_textureName = nullptr;

		ID3D11Buffer*				m_vertexBuffer = nullptr;
		ID3D11Buffer*				m_indexBuffer = nullptr;
		std::vector<Vertex>			m_vertices;
		std::vector<WORD>			m_indices;
		int							m_transparency = 0;
		Shader*						m_shader = nullptr;
		bool						m_isUI = false;
	};
}