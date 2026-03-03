#include <SFML/Graphics.hpp>
#include "Particle.hpp"

int main() {
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 8;

    sf::RenderWindow window(sf::VideoMode({800, 600}), "SFML shapes", sf::Style::Default, sf::State::Windowed, settings);
    window.setFramerateLimit(60);

    // Допустим, твоё окно называется window
    sf::Vector2u windowSize = window.getSize();

    float centerX = windowSize.x / 2.0f;
    float centerY = windowSize.y / 2.0f;

    // Теперь передаем эти координаты частице при создании
    Particle p(0.5f, {centerX, centerY});

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        window.clear(sf::Color::Black);

        p.draw(window);

        window.display();
    }
    return 0;
}