#include "Novice.h"
#include "Player.h"

Player::Player() {
	posX_ = 640;
	posY_ = 360;
	radius_ = 15;
	speed_ = 10;
	bullet_ = new Bullet();
}

Player::~Player() {
	delete bullet_;
}

void Player::Update(char* keys, char* preKeys) {

	///自機の操作///
	if (posY_ > radius_) {
		if (keys[DIK_W] || keys[DIK_UP]) {
			posY_ -= speed_;
		}
	}
	if (posY_ < 720 - radius_) {
		if (keys[DIK_S] || keys[DIK_DOWN]) {
			posY_ += speed_;
		}
	}
	if (posX_ > radius_) {
		if (keys[DIK_A] || keys[DIK_LEFT]) {
			posX_ -= speed_;
		}
	}
	if (posX_ < 1280 - radius_) {
		if (keys[DIK_D] || keys[DIK_RIGHT]) {
			posX_ += speed_;
		}
	}
	////////////////

	///弾の発射///
	if (preKeys[DIK_SPACE] == 0 && keys[DIK_SPACE] != 0) {
		if (bullet_->GetIsShot() == false) {
			bullet_->SetPosX(posX_);
			bullet_->SetPosY(posY_);
			bullet_->SetIsShot(true);
		}
	}
	//////////////

	///弾の移動///
	if (bullet_->GetIsShot()) {
		bullet_->Update();
	}
	//////////////
}

void Player::Draw() {

	///自機の表示
	Novice::DrawEllipse(posX_, posY_, radius_, radius_, 0.0f, WHITE, kFillModeSolid);

	///弾の表示
	if (bullet_->GetIsShot()) {
		bullet_->Draw();
	}
}
