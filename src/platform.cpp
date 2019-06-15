#include <SFML/Graphics.hpp>
#include "../include/Entity.hpp"
#include "../include/Platform.hpp"

void Platform::init(float X, float Y, float W, float H){
	x = X;
	y = Y;
	w = W;
	h = H;

	hitbox.left = x + 0.f;
	hitbox.right = x + w - 0.f;
	hitbox.top = y + 0.f;
	hitbox.bottom = y + h + 0.f;

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

	setPosition(x, y);
}