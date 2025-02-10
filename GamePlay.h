#pragma once
#include "Player.h"
#include "Enemy.h"
#include <Novice.h>

class GamePlay
{
public:

	/// <summary>
	/// コンストラクタ
	/// </summary>
	GamePlay();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~GamePlay();

	/// <summary>
	/// 更新処理
	/// </summary>
	/// <param name="keys">現在のキーの状態</param>
	/// <param name="preKeys">前フレームのキーの状態</param>
	void Update(char keys[256], char preKeys[256]);

	/// <summary>
	/// 描画処理
	/// </summary>
	void Draw();

	/// <summary>
	/// sceneChange_を任意の値を書き込む
	/// </summary>
	/// <param name="sceneChange">書き込む値</param>
	void SetSceneChange(bool sceneChange);

	bool GetSceneChange() { return sceneChange_; }

private:

	Player* player;
	Enemy* enemy;

	bool sceneChange_;

	float distanceX = 0.0f;
	float distanceY = 0.0f;
	float distance = 0.0f;

};

