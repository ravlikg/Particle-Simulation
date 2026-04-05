#pragma once
#include <SFML/Graphics.hpp>

#include "Simulation.hpp"

class Application {
public:
    Application(const sf::ContextSettings& settings)
        : window_(sf::VideoMode({800, 1000}), "Particle Simulation", sf::Style::Default,
                  sf::State::Windowed, settings) {
    }

    void run() {
        window_.setFramerateLimit(60);
        auto window_size = window_.getSize();
        float x_position = window_size.x / 2;
        float y_position = 0;
        sf::Vector2f particle_position{x_position, y_position};
        simulation_.addParticle(particle_position, 10.0f);
        simulation_.addParticle(particle_position, 10.0f);
        simulation_.addParticle(particle_position, 10.0f);

        while (window_.isOpen()) {
            handleEvents();
            update();
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

    void update() {
        simulation_.update();
    }

    void render() {
        window_.clear(sf::Color::Black);
        simulation_.draw(window_);
        window_.display();
    }

private:
    sf::RenderWindow window_;
    Simulation simulation_;
};