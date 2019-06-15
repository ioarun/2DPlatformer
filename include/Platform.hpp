#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../include/Entity.hpp"

class Platform : public Entity{
	public:
		void init(float X, float Y, float W, float H);

};