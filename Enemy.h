#pragma once
class Enemy
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="posX">X座標</param>
	/// <param name="posY">Y座標</param>
	/// <param name="speedX">移動速度X</param>
	/// <param name="speedY">移動速度Y</param>
	Enemy(int posX, int posY, int speedX, int speedY);

	/// <summary>
	/// デストラクタ
	/// </summary>
	~Enemy();

	/// <summary>
	/// 更新
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	/// <summary>
	/// speedX_に任意の値を書き込む
	/// </summary>
	/// <param name="speedX">書き込む値</param>
	void SetSpeedX(int speedX);

	/// <summary>
	/// speedY_に任意の値を書き込む
	/// </summary>
	/// <param name="speedY">書き込む値</param>
	void SetSpeedY(int speedY);

	/// <summary>
	/// speedY_に任意の値を書き込む
	/// </summary>
	/// <param name="speedY">書き込む値</param>
	void SetIsAlive(int isAlive);


	int GetPosX() { return posX_; }
	int GetPosY() { return posY_; }
	int GetRadius() { return radius_; }
	int GetSpeedX() { return speedX_; }
	int GetSpeedY() { return speedY_; }
	bool GetIsAlive() { return isAlive_; }

private:
	// メンバ変数
	int posX_;
	int posY_;
	int speedX_;
	int speedY_;
	int radius_;
	int respownTime_;
	int respownTimer_;
	bool isAlive_;

};

