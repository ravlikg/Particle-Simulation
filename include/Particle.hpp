#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

constexpr float G = 9.8;

class Particle {
public:
    Particle(const sf::Vector2f position, const float radius)
        : position_(position),
          previous_position_(position),
          acceleration_({0.0f, 0.0f}),
          radius_(radius) {
    }

    void update(float dt) {
        sf::Vector2f displacement = position_ - previous_position_;
        previous_position_ = position_;
        position_ += displacement + acceleration_ * (dt * dt);
        acceleration_ = {};
    }

    sf::Vector2f getPosition() const {
        return position_;
    }

    void setPosition(sf::Vector2f position) {
        position_ = position;
    }

    float getRadius() const {
        return radius_;
    }

    void accelerate(sf::Vector2f a) {
        acceleration_ += a;
    }

    void setVelocity(sf::Vector2f v) {
        previous_position_ = position_ - (v);
    }

    sf::Vector2f getVelocity() const {
        return position_ - previous_position_;
    }

private:

    sf::Vector2f position_;
    sf::Vector2f previous_position_;
    sf::Vector2f acceleration_;

    float radius_;
};