#pragma once
#include "Header.h"
#include "GameObject.h"
#include "InteractionTypes.h"
class Scene : public GameElement {
private:
	vector<GameObject*> gameObjects;

public:
	Scene() = default;
	Scene(string sceneName); 
	~Scene();
	
	string listAvailableElements();
	GameObject* selectGameObject(string objectName);
	
	bool isAvailable(string GameElementName);
	bool isGameObject(string GameElementName);
};
