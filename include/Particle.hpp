#pragma once

#include <SFML/Graphics.hpp>

constexpr float G = 9.8;

class Particle {
public:
    Particle(const float level, const float radius, const sf::Vector2f position)
        : shape_(20, radius),
          acceleration_({10.0f, 10.0f}),
          level_(level),
          mass_(1),
          position_(position),
          previous_position_(position),
          radius_(radius) {
        shape_.setOrigin(sf::Vector2f({radius_, shape_.getRadius()}));
        shape_.setPosition(position);
        shape_.setFillColor(sf::Color(0, 60, 150));
    }

    void update(float dt) {
        sf::Vector2f displacement = position_ - previous_position_;
        previous_position_ = position_;
        position_ += displacement + acceleration_ * (dt * dt);
        //acceleration_ = {};

        shape_.setPosition(position_);
    }


    void draw(sf::RenderWindow& window) {
        window.draw(shape_);
    }

private:
    sf::CircleShape shape_;

    sf::Vector2f position_;
    sf::Vector2f previous_position_;
    sf::Vector2f acceleration_;

    float level_;

    int mass_;
    float radius_;
    //float m_restitution{};
};