#pragma once
#include <unordered_map>
#include <string>
#include "Scene.h"
#include <iostream>

#define SM SceneManager::Instance()
class SceneManager {
private:
	std::unordered_map<std::string, Scene*> scenes;
	Scene* currentScene = nullptr;
	std::string nextScene = "";

	SceneManager() = default;
	SceneManager(SceneManager&) = delete;
	SceneManager& operator=(const SceneManager&) = delete;

public:
	inline static SceneManager& Instance() {
		static SceneManager sm;
		return sm;
	}
	inline bool AddScene(std::string name, Scene* scene){
		if (scenes.find(name) == scenes.end()) {
			scenes.emplace(name, scene);
			return true;
		} 
		return false;
	}
	inline Scene* GetScene(std::string name) {
		if (scenes.find(name) != scenes.end()) return scenes[name];
		
		return nullptr;
	}

	inline bool InitFirstScene(std::string name) {
		if (scenes.find(name) != scenes.end()) {
			currentScene = scenes[name];
			currentScene->OnEnter();
			return true;
		}
		return false;
	}
	
	inline Scene* GetCurrentScene() const { return currentScene; }

	inline bool SetNextScene(std::string name) {
		if (scenes.find(name) == scenes.end()) {
			std::cout << "Scene Not Found" << std::endl;
			return false;
		}
		std::cout << "Scene Found" << std::endl;
		nextScene = name;
		return true;
	}

	inline void UpdateCurrentScene() {
		if (nextScene != "") {
			currentScene->OnExit();
			auto it = scenes.find(nextScene);
			if (it != scenes.end()) {
				currentScene = it->second;	
				currentScene->OnEnter();
			}
			nextScene = "";
		}
		currentScene->Update();
	}
};
