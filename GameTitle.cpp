#include "GameTitle.h"

GameTitle::GameTitle()
{
	sceneChange_ = false;
}

GameTitle::~GameTitle()
{
}

void GameTitle::Update(char keys[256], char preKeys[256])
{
	if (preKeys[DIK_SPACE] == 0 && keys[DIK_SPACE] != 0) {
		sceneChange_ = true;
	}
}

void GameTitle::Draw()
{
	Novice::ScreenPrintf(50, 50, "title");
	Novice::ScreenPrintf(50, 70, "SPACE key:START");
}

void GameTitle::SetSceneChange(bool sceneChange)
{
	this->sceneChange_ = sceneChange;
}

