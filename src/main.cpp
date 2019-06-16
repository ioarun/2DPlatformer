#include <SFML/Graphics.hpp>
#include <iostream>
#include "../include/Entity.hpp"
#include "../include/Player.hpp"
#include "../include/Platform.hpp"

int windowWidth = 720;
int windowHeight = 640;

float accelGravity = .2f;
float maxGravity = 5.f;

class Env {
public:
	sf::RenderWindow window;
	bool W, A, S, D;
	int levelArray [10][10] = {
							 {0,0,0,0,0,0,0,0,0,0},
							 {0,0,0,0,0,0,0,0,0,0},
							 {0,0,0,0,0,0,0,0,0,0},
							 {0,0,0,0,0,0,0,0,0,0},
							 {0,0,0,0,0,0,0,0,0,0},
							 {0,0,0,0,0,0,0,0,0,0},
							 {0,0,0,0,0,0,0,0,0,0},
							 {0,0,0,0,0,0,0,0,0,0},
							 {0,0,0,0,0,0,0,0,0,0},
							 {1,1,1,1,1,0,0,1,1,1}
							 };

	// PlatformClass platformObj(100, 100, platformSprite);
	Platform level[100];
	Player player;
	int sizeOfLevel;
	sf::View view;
	

public:
	void setLayout(){
		for(int i = 0; i < 10; i++){
			for (int j = 0; j < 10; j++){
				if(levelArray[i][j] == 1){
					level[sizeOfLevel].init(j * 50, i * 50, 50, 50);
					level[sizeOfLevel].setTexture("data/images/brick.png"); 
					sizeOfLevel += 1;
				}
			}
		}
	}

	void loop(){
		while(window.isOpen()){
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

			player.update(W, S, A, D, level);

			view.setCenter(sf::Vector2f(player.x + player.w / 2.f, player.y + player.h / 2.f));
			window.setView(view);
			// Clear screen
			window.clear(sf::Color(10, 108, 188));

			window.draw(player);

			for (int i=0; i < sizeOfLevel ; i++){
				window.draw(level[i]);
			}	

			for (int i=0; i < sizeOfLevel ; i++){
				window.draw(level[i]);
			}

			window.display();

		}	
	}


	Env(){
		//Create the main window
		window.create(sf::VideoMode(windowWidth, windowHeight), "Snail Jumps");
		window.setFramerateLimit(60);
		sizeOfLevel = 0;
		setLayout();
		player.init(10, 200, 50, 50);
		player.setTexture("data/images/snail.png");	
		view = sf::View(sf::Vector2f(0.0f, 0.04), sf::Vector2f(windowWidth, windowHeight));
	}
};

int main(){
	
	Env env;
	env.loop();
	return EXIT_SUCCESS;
}