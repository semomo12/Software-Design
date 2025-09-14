#include "pch.h"
#include "Scene.h"
#include "GameObject.h"

Scene::Scene(string sceneName) : GameElement(sceneName)
{
    this->gameObjects.push_back(new GameObject("apple"));
    this->gameObjects.push_back(new GameObject("kiwi"));
    this->gameObjects.push_back(new GameObject("melon"));
}
Scene::~Scene()
{
    for (auto& object : gameObjects) {
        delete object;
    }
}
string Scene::listAvailableElements()//
{
    return "string";
}

GameObject*  Scene::selectGameObject(string objectName)
{
    for (const auto object : gameObjects) {
        if (objectName == object->getName()) {

            return object;
        }
    }
    return nullptr;
}

bool Scene::isAvailable(string GameElementName)///
{
    bool available;
    return false;
}

bool Scene::isGameObject(string GameElementName)//
{
    return false;
}
