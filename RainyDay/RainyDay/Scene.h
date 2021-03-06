#pragma once
#include <list>
#include "Renderer.h"
#include "InputClass.h"
#include "Model.h"
#include "UIModel.h"
#include "Camera.h"
#include "SystemClass.h"

namespace RainyDay {
class UIModel;
class UISprite;
class Model;
class InputClass;
class Camera;

	class DLL_API Scene
	{
	public:
		virtual ~Scene();
		void AddModel(Model* model);
		void AddUIModel(UIModel* model);
		void RemoveModel(std::function<bool(Model*)> compare);
		virtual void Start(Camera& camera) = 0;

		//false를 반환하면 프로세스 종료됨.
		virtual bool Update(float dt, InputClass& input, Camera& camera) = 0;

		virtual void UpdateUIString(Camera& camera);
		void ShutDownAll();
		virtual void ShutDown() = 0;

		XMFLOAT4 MakeCircularRGB(int seed);
	protected:
		std::list<Model*> m_modelsToBeRendered;
		std::list<UIModel*> m_UImodel;
		std::list<UISprite*> m_UISprites;

	private:

		//Play함수는 Update, Start함수를 적절히 불러주는 함수로 SystemClass객체만이 부를수 있습니다. 재정의 하는 함수가 아닙니다.
		bool Play(float detaTime, InputClass& input, Camera& camera);


		bool m_started = false;

		friend class SystemClass;
		friend class Renderer;
	};

}