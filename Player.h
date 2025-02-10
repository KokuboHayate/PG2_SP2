#pragma once
#include "Bullet.h"

class Player {
public:

	/// <summary>
	/// コンストラクタ
	/// </summary>
	Player();

	/// <summary>
	/// デストラクタ
	/// </summary>
	~Player();

	/// <summary>
	/// プレイヤー操作
	/// </summary>
	/// <param name="keys">現在のキーの状態</param>
	/// <param name="preKeys">前フレームのキーの状態</param>
	void Update(char* keys, char* preKeys);

	/// <summary>
	/// 描画関数
	/// </summary>
	void Draw();


	int GetPosX() { return posX_; }
	int GetPosY() { return posY_; }
	int GetRadius() { return radius_; }

	bool GetBulletIsShot() { return bullet_->GetIsShot(); }
	int GetBulletPosX() { return bullet_->GetPosX(); }
	int GetBulletPosY() { return bullet_->GetPosY(); }
	int GetBulletRadius() { return bullet_->GetRadius(); }

private:
	Bullet* bullet_;
	int posX_;
	int posY_;
	int radius_;
	int speed_;

};

