#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Graphics.hpp>

int main() {
    std::cout << "Testing SFML...\n";

    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML Test");
    if (!window.isOpen()) {
        std::cerr << "SFML window did not open.\n";
        return 1;
    }

    sf::Clock clock;
    while (clock.getElapsedTime().asSeconds() < 1) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }

    std::cout << "SFML window opened successfully!\n";
    return 0;
}