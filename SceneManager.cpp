#include "SceneManager.h"

SceneManager::SceneManager()
	: current_scene(SceneState::GAMETITLE)
{
	current_scene = SceneState::GAMETITLE;
	gameTitle = new GameTitle();
	gamePlay = NULL;
}

SceneManager::~SceneManager()
{
}

void SceneManager::Update(char keys[256], char preKeys[256])
{
	switch (current_scene)
	{
	case SceneManager::SceneState::GAMETITLE:

		gameTitle->Update(keys, preKeys);

		///シーン切り替え
		if (gameTitle->GetSceneChange() == true) {
			current_scene = SceneState::GAMEPLAY;
			gamePlay = new GamePlay();
			gameTitle->SetSceneChange(false);
		}

		break;
	case SceneManager::SceneState::GAMEPLAY:

		gamePlay->Update(keys, preKeys);

		///シーン切り替え
		if (gamePlay->GetSceneChange() == true) {
			current_scene = SceneState::GAMETITLE;
			delete gamePlay;
		}

		break;
	default:
		break;
	}
}

void SceneManager::Draw()
{
	switch (current_scene)
	{
	case SceneManager::SceneState::GAMETITLE:

		gameTitle->Draw();

		break;
	case SceneManager::SceneState::GAMEPLAY:

		gamePlay->Draw();

		break;
	default:
		break;
	}
}
