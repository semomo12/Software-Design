#pragma once
#include "Header.h"
#include "GameObject.h"
#include "GameObjectRepository.h"
#include "Scene.h"
#include "GameObject.h"


class Game {
	GameObjectRepository myGameObjects;
	Scene* currentScene;
	vector<Scene> playerInventory;
	GameObject* selectedGameObject = nullptr;
	InteractionTypes* selectedInteraction = nullptr;
	string selectedOption = "";
public:

	Game();
	~Game();
	vector<InteractionTypes*> selectGameObject(string name);
	vector<string> selectInteraction(string theInteraction);
	string setInteractionOptions(string theOption);

	//Available
	string startInteraction();
	string abortInteraction(GameObject gameObject);
	bool addGameObject(string name);
};