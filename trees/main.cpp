#include <iostream> 
#include <SFML/Graphics.hpp>

struct plant {
	
	sf::Vector2f pos;
	sf::Texture image;
	plant() {};
	void init(std::string filepath, sf::Vector2f position = {0,0}) {
		pos = position;
		if (!image.loadFromFile(filepath)) {
			fputs("error openning file", stderr);
			exit(1);
		}
	}
};
struct tree :  plant {
	sf::Sprite sprite;

	tree(sf::Vector2f pos, sf::Vector2f size ) {
		//create a shape 
		this->init("tree.png.png", pos);
		sprite.setPosition( this->pos);
		sprite.setTexture(this->image);

		//sprite.setScale(size);
	};
	
	
};
struct shrub : plant {
	sf::Sprite sprite;
	shrub(sf::Vector2f pos, sf::Vector2f size) {
		this->init("shrub.png", pos);
		sprite.setPosition(this->pos);
		sprite.setTexture(this->image);
	}
};


int main(void) {
	sf::RenderWindow window({ 800,800 }, "hello");
	tree bruh({ 400,400 }, {1.0, 1.0});
	shrub fd({ 200,200 }, { 1,1 });
	sf::Event event;
	while (window.isOpen() == true) {
		while (window.pollEvent(event)) {

		}
		
		//draw plants
		window.clear(sf::Color::Black);
		window.draw(bruh.sprite);
		window.draw(fd.sprite);
		window.display();
	}



}
