#pragma once
#include <d3d11.h>
#include <map>
#include <memory>
#include <string>
#include "Effects\d3dx11effect.h"
#include "Camera.h"
#include "SystemClass.h"
#include "UISprite.h"


namespace RainyDay {
	class Model;

	class Renderer
	{
	public:
		Renderer();
		virtual ~Renderer();
		virtual bool Initialize(int winWidth, int winHeight, HWND hwnd);
		virtual bool Frame(float deltaTime, Scene* curScene);

		void AddModel(Model* model);
		void AddTransparentModel(Model* model);
		void AddUISprite(UISprite* sprite);
		void ShutDown();
		Camera& GetCamera() { return m_camera; };
		void SetLightDirection(XMFLOAT4 lightDirection);
		HRESULT LoadTexture(WCHAR* fileName);

	private:

		HRESULT InitDevice(HWND hwnd);
		void CreateShader();
		void CalculateMatrixForBox(float deltaTime, Model* model);
		void CreateDepthStencilState();
		void CreateDepthStencilTexture();
		HRESULT CreateBlendState();

		void SetBuffers(Model* model, float deltaTime);
		void SetUIBuffers(Model* model, float deltaTime);
		void CreateRenderState();

		XMFLOAT4 m_lightDirection = { -0.3f, -1.0f, -0.2f, 1.0f };
		XMFLOAT4 lightColor = { 1.0f, 1.0f, 1.0f, 1.0f };
		Camera				m_camera;
		int					m_width;
		int					m_height;

		IDXGISwapChain*									m_swapChain = nullptr; //DC �ٲٱ�
		ID3D11Device*									m_device = nullptr;
		ID3D11DeviceContext*							m_immediateContext = nullptr; //Dx�� DC
		ID3D11RenderTargetView*							m_renderTargetView = nullptr;

		D3D_FEATURE_LEVEL								m_featureLevel = D3D_FEATURE_LEVEL_11_0;
		ID3D11Texture2D*								m_depthStencil = nullptr;
		ID3D11DepthStencilView*							m_depthStencilView = nullptr;
		ID3D11DepthStencilState*						m_depthStencilStateForNormalModel = nullptr;
		ID3D11DepthStencilState*						m_depthStencilStateForUI = nullptr;
		ID3D11DepthStencilState*						m_depthStencilStateForTransparentModel = nullptr;
		ID3D11BlendState*								m_blendState = nullptr;


		ID3D11VertexShader*								m_vertexShader = nullptr;
		ID3D11InputLayout*								m_inputLayout = nullptr;
		ID3D11PixelShader*								m_pixelShader = nullptr;
		ID3D11Buffer*									m_constantBuffer = nullptr;

		ID3D11RasterizerState*							m_solidRS = nullptr;
		ID3D11RasterizerState*							m_wireFrameRS = nullptr;

		ID3DX11Effect*									m_effect = nullptr;
		ID3DX11EffectTechnique*							m_colorTech = nullptr;

		ID3DX11EffectSamplerVariable*			m_samplerVariable = nullptr;
		ID3DX11EffectShaderResourceVariable*	m_texDiffuse = nullptr;
		ID3DX11EffectMatrixVariable*			m_wvp;
		ID3DX11EffectMatrixVariable*			m_world;
		ID3DX11EffectVectorVariable*			m_lightDir;
		ID3DX11EffectVectorVariable*			m_lightColor;

		ID3D11Resource*							m_texture = nullptr;
		ID3D11SamplerState*						m_samplerState = nullptr;

		std::map<WCHAR*, ID3D11ShaderResourceView*>	m_textureRVList;
		std::vector<Model*>				m_modelList;
		std::vector<Model*>				m_transparentModelList;
		std::vector<UISprite*>					m_UIList;

		//friend class SystemClass;
	};
}
