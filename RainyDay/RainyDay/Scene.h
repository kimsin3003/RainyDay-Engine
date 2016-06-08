#pragma once
#include <list>
#include "Renderer.h"
#include "InputClass.h"
#include "Model.h"
#include "UIModel.h"
#include "Camera.h"
#include "SystemClass.h"

class UIModel;
class UISprite;
class Model;
class InputClass;
class Camera;

class Scene
{
public:
	virtual ~Scene();
	void AddModel(Model* model);
	void AddUIModel(UIModel* model);
	void RemoveModel(std::function<bool(Model*)> compare);
	virtual void Start(Camera& camera) = 0;

	//false�� ��ȯ�ϸ� ���μ��� �����.
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

	//Play�Լ��� Update, Start�Լ��� ������ �ҷ��ִ� �Լ��� SystemClass��ü���� �θ��� �ֽ��ϴ�. ������ �ϴ� �Լ��� �ƴմϴ�.
	bool Play(float detaTime, InputClass& input, Camera& camera);


	bool m_started = false;

	friend class SystemClass;
	friend class Renderer;
};

