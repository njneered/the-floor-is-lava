#include <SFML/Graphics.hpp>
#include <iostream>
#include "Map.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(1280, 720), "The Floor is Lava!");
    window.setFramerateLimit(60);

    Map gameMap;

    if (!gameMap.loadFromFile("maps/map.tmx", "maps/spritesheet.png", 32, 16)) {
        std::cerr << "Failed to load the map.\n";
        return 1;
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);
        gameMap.draw(window);
        window.display();
    }

    return 0;
}
