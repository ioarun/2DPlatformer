#include <SFML/Graphics.hpp>
#include <iostream>
#include "../include/Entity.hpp"
#include "../include/Player.hpp"
#include "../include/Platform.hpp"

int windowWidth = 720;
int windowHeight = 640;

float accelGravity = .2f;
float maxGravity = 5.f;


int main(){
	//Create the main window
	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Snail Jumps");
	window.setFramerateLimit(60);
	
	bool W, A, S, D;

	int levelArray[10][10] = {{0,0,0,0,0,0,0,0,0,0},
							{0,0,0,0,0,0,0,0,0,0},
							{0,0,0,1,1,0,1,1,0,0},
							{0,0,0,0,0,0,0,1,0,0},
							{0,0,0,0,0,0,0,0,0,0},
							{0,0,0,0,0,0,0,0,0,0},
							{0,0,0,0,0,0,0,0,0,0},
							{0,0,0,0,0,0,0,0,0,0},
							{0,0,0,0,0,0,0,0,0,0},
							{1,1,1,1,1,0,0,1,1,1}};

	// PlatformClass platformObj(100, 100, platformSprite);
	Platform level[100];

	int sizeOfLevel = 0;

	for(int i = 0; i < 10; i++){
		for (int j = 0; j < 10; j++){
			if(levelArray[i][j] == 1){
				level[sizeOfLevel].init(j * 50, i * 50, 50, 50);
				level[sizeOfLevel].setTexture("data/images/brick.png"); 
				sizeOfLevel += 1;
			}
		}
	}
	
	// PlatformClass level[5] = {PlatformClass(100, 200, platformSprite),
	// 						  PlatformClass(150, 200, platformSprite),
	// 						  PlatformClass(200, 200, platformSprite),
	// 						  PlatformClass(250, 200, platformSprite),
	// 						  PlatformClass(300, 200, platformSprite)}; // passing arguments to each object
	
	Player player(10, 200, 50, 50);
	player.setTexture("data/images/snail.png");						  

	sf::View view(sf::Vector2f(0.0f, 0.04), sf::Vector2f(windowWidth, windowHeight));
	// view.zoom(0.2f);
	// Start the game loop
	while(window.isOpen()){
		//Process event
		sf::Event event;
		while(window.pollEvent(event)){
			//Close window : exit
			if (event.type == sf::Event::Closed)
				window.close();
		}

		W = sf::Keyboard::isKeyPressed(sf::Keyboard::W);
		S = sf::Keyboard::isKeyPressed(sf::Keyboard::S);
		A = sf::Keyboard::isKeyPressed(sf::Keyboard::A);
		D = sf::Keyboard::isKeyPressed(sf::Keyboard::D);
		
		// playerObj.update(keyRight, keyLeft, keyUp, keyDown, level);
		player.update(W, S, A, D, level);

		view.setCenter(sf::Vector2f(player.x + player.w / 2.f, player.y + player.h / 2.f));
		window.setView(view);
		// Clear screen
		window.clear(sf::Color(10, 108, 188));

		// window.draw(platformObj.image);
		// window.draw(playerObj.image);

		window.draw(player);

		for (int i=0; i < sizeOfLevel ; i++){
			window.draw(level[i]);
		}
		
		// playerObj.image.move(Vector2f(playerObj.xVel, playerObj.yVel));


		// Update the window
		window.display();

	}
	return EXIT_SUCCESS;
}