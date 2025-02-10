#pragma once
#include "GameTitle.h"
#include "GamePlay.h"
#include <Novice.h>

class SceneManager
{
public:

	/// <summary>
	/// コンストラクタ
	/// </summary>
	SceneManager();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~SceneManager();

	/// <summary>
	/// 更新処理
	/// </summary>
	/// <param name="keys">現在のキーの状態</param>
	/// <param name="preKeys">前フレームのキーの状態</param>
	void Update(char keys[256], char preKeys[256]);

	/// <summary>
	/// 描画関数
	/// </summary>
	void Draw();

private:

	enum class SceneState {
		GAMETITLE,
		GAMEPLAY
	};

	SceneState current_scene;

	GameTitle* gameTitle;

	GamePlay* gamePlay;


};


