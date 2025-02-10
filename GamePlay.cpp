#include "GamePlay.h"
#include <math.h>

GamePlay::GamePlay()
{
	player = new Player();
	enemy = new Enemy(100, 100, 5, 5);

	sceneChange_ = false;
	distance = 0.0f;
	distanceX = 0.0f;
	distanceY = 0.0f;
}

GamePlay::~GamePlay()
{
	delete player;
	delete enemy;
}

void GamePlay::Update(char keys[256], char preKeys[256])
{

	///タイトルに戻る///
	if (preKeys[DIK_T] == 0 && keys[DIK_T] != 0) {
		sceneChange_ = true;
	}
	////////////////////

	player->Update(keys, preKeys);
	enemy->Update();


	if (enemy->GetIsAlive()) {

		///自機と敵の当たり判定///
		distanceX = static_cast<float>(player->GetPosX() - enemy->GetPosX());
		distanceY = static_cast<float>(player->GetPosY() - enemy->GetPosY());
		distance = sqrtf(distanceX * distanceX + distanceY * distanceY);
		if (distance <= player->GetRadius() + enemy->GetRadius()) {
			sceneChange_ = true;
		}
		//////////////////////////


		///弾と敵の当たり判定///
		if (player->GetBulletIsShot()) {
			distanceX = static_cast<float>(player->GetBulletPosX() - enemy->GetPosX());
			distanceY = static_cast<float>(player->GetBulletPosY() - enemy->GetPosY());
			distance = sqrtf(distanceX * distanceX + distanceY * distanceY);
			if (distance <= player->GetBulletRadius() + enemy->GetRadius()) {
				enemy->SetIsAlive(false);
			}
		}
		//////////////////////////
	}

}

void GamePlay::Draw()
{
	player->Draw();
	enemy->Draw();

	Novice::ScreenPrintf(0, 0, "WASD keys:PlayerMove  T:Title");

}

void GamePlay::SetSceneChange(bool sceneChange)
{
	this->sceneChange_ = sceneChange;
}
