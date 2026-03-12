#pragma once
#include <SFML/Graphics.hpp>

class Application {
public:
    Application(const sf::ContextSettings& settings)
        : window_(sf::VideoMode({800, 600}), "Particle Simulation", sf::Style::Default,
                  sf::State::Windowed, settings) {
    }

public:
    void run() {
        sf::Clock clock;

        while (window_.isOpen()) {
            handleEvents();
            auto elapsed_time = clock.restart();
            update(elapsed_time.asSeconds());
            render();
        }
    }

private:
    void handleEvents() {
        while (auto event = window_.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window_.close();
            }
        }
    }

    void update(float dt);

    void render() {
        window_.clear(sf::Color::Black);

        window_.display();
    }

private:
    sf::RenderWindow window_;
};