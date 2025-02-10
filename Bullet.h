#pragma once

class Bullet {

public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	Bullet();

	/// <summary>
	/// 弾の移動
	/// </summary>
	void Update();

	/// <summary>
	/// 描画関数
	/// </summary>
	void Draw();

	/// <summary>
	/// posX_に任意の値を書き込む
	/// </summary>
	/// <param name="posX">書き込む値</param>
	void SetPosX(int posX);

	/// <summary>
	/// posY_に任意の値を書き込む
	/// </summary>
	/// <param name="posY">書き込む値</param>
	void SetPosY(int posY);

	/// <summary>
	/// isShot_に任意の値を書き込む
	/// </summary>
	/// <param name="isShot">書き込む値</param>
	void SetIsShot(int isShot);


	int GetPosX() { return posX_; }
	int GetPosY() { return posY_; }
	int GetRadius() { return radius_; }
	int GetSpeed() { return speed_; }
	bool GetIsShot() { return isShot_; }

private:
	int posX_;
	int posY_;
	int speed_;
	int radius_;
	bool isShot_;

};

