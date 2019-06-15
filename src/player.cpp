#include <SFML/Graphics.hpp>
#include "../include/Entity.hpp"
#include "../include/Player.hpp"
#include "../include/Platform.hpp"
#include <iostream>

extern float accelGravity;
extern float maxGravity;

Player::Player(float X, float Y, float W, float H){
	speed = 2.5f;
	jumpHeight = 6.f;

	x = X;
	y = Y;
	w = W;
	h = H;

	vertices.setPrimitiveType(sf::Quads);
	vertices.resize(4);

	vertices[0].position = sf::Vector2f(0, 0);
	vertices[1].position = sf::Vector2f(W, 0);
	vertices[2].position = sf::Vector2f(W, H);
	vertices[3].position = sf::Vector2f(0, H);

	vertices[0].texCoords = sf::Vector2f(0, 0);
	vertices[1].texCoords = sf::Vector2f(W, 0);
	vertices[2].texCoords = sf::Vector2f(W, H);
	vertices[3].texCoords = sf::Vector2f(0, H);

	// audio stuff
	if(!soundBuffer.loadFromFile("data/audio/jump_small.wav"))
			std::cout << "ERROR: Loading sound!" << std::endl;

	sound.setBuffer(soundBuffer);

}

void Player::update(bool &W, bool &S, bool &A, bool &D, Platform level[10]){
	// player controls
	if(W and onGround){
		velocity.y = jumpHeight * -1; // -ve is up +ve is down
		sound.play();

	}

	if(not onGround){
		velocity.y += accelGravity;
		if(velocity.y > maxGravity) velocity.y = maxGravity;
	}

	if(A) velocity.x = -1.f;
	// if(S) velocity.y = 0.25f;
	if(D) velocity.x = 1.f;
	if(!(A||D)) velocity.x = 0.0;

	x += velocity.x * speed;
	collide(velocity.x, 0, level);

	onGround = false;
	y += velocity.y * speed;
	collide(0, velocity.y, level);


	setPosition(x, y);
 }

 void Player::collide(float xvel, float yvel, Platform level[13]){
 	for(int i = 0; i < 13; i++){
 		if(x + 0.f < level[i].hitbox.right && 
 			x + w - 0.f > level[i].hitbox.left &&
 			y < level[i].hitbox.bottom &&
 			y + h > level[i].hitbox.top){

 			collision = true;
 		}else{
 			collision = false;
 		}
 		if(collision){
 			if(xvel > 0){
				x = level[i].hitbox.left -  w + 0.f;
				velocity.x = 0.f;
	 		}
	 		if(xvel < 0){
				x = level[i].hitbox.right - 0.f;
				velocity.x = 0.f;
	 		}
	 		if(yvel > 0){
				y = level[i].hitbox.top - h + 0.f;
				velocity.y = 0.f;
				onGround = true;
	 		}
	 		if(yvel < 0){
				y = level[i].hitbox.bottom - 0.f;
	 			velocity.y = 0.f;
	 		}


		}

	}
 }