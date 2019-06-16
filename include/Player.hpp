#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "../include/Entity.hpp"
#include "../include/Hitbox.hpp"
#include "../include/Platform.hpp"

class Player : public Entity{
	private:
		bool collision;
		bool onGround;
		float speed;
		float jumpHeight;

		sf::SoundBuffer soundBuffer;
		sf::Sound sound;

	public:
		// Player(float X, float Y, float W, float H);
		void init(float X, float Y, float W, float H);
		void update(bool &W, bool &S, bool &A, bool &D, Platform level[8]);
		void collide(float xvel, float yvel, Platform level[8]);

};