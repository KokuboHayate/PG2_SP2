#include "Novice.h"
#include "Bullet.h"

Bullet::Bullet() {
	posX_ = 0;
	posY_ = 0;
	speed_ = 15;
	radius_ = 7;
	isShot_ = false;
}

void Bullet::Update() {
	if (isShot_) {
		posY_ -= speed_;

		if (posY_ < -radius_) {
			isShot_ = false;
		}
	}
}

void Bullet::Draw() {
	if (isShot_) {
		Novice::DrawEllipse(posX_, posY_, radius_, radius_, 0.0f, WHITE, kFillModeSolid);
	}
}

void Bullet::SetPosX(int posX)
{
	this->posX_ = posX;
}

void Bullet::SetPosY(int posY)
{
	this->posY_ = posY;
}

void Bullet::SetIsShot(int isShot)
{
	this->isShot_ = isShot;
}
