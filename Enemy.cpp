#include "Enemy.h"
#include "Novice.h"

Enemy::Enemy(int posX, int posY, int speedX, int speedY)
{
	posX_ = posX;
	posY_ = posY;
	speedX_ = speedX;
	speedY_ = speedY;
	radius_ = 8;
	respownTime_ = 120;
	respownTimer_ = 120;
	isAlive_ = true;
}

Enemy::~Enemy()
{
}

void Enemy::Update()
{
	if (isAlive_) {

		//移動処理
		posX_ += speedX_;
		posY_ += speedY_;

		if (posX_ - radius_ <= 0 || posX_ + radius_ >= 1280) {
			speedX_ *= -1;
		}
		if (posY_ - radius_ <= 0 || posY_ + radius_ >= 720) {
			speedY_ *= -1;
		}
	} else {

		///リスポーン処理
		respownTimer_--;
		if (respownTimer_ == 0) {
			respownTimer_ = respownTime_;
			isAlive_ = true;
		}
	}
}

void Enemy::Draw()
{
	if (isAlive_) {
		Novice::DrawEllipse(posX_, posY_, radius_, radius_, 0.0f, RED, kFillModeSolid);
	}
}

void Enemy::SetSpeedX(int speedX)
{
	this->speedX_ = speedX;
}

void Enemy::SetSpeedY(int speedY)
{
	this->speedY_ = speedY;
}

void Enemy::SetIsAlive(int isAlive)
{
	this->isAlive_ = isAlive;
}
