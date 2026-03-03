#pragma once

#include <SFML/Graphics.hpp>

constexpr float G = 9.8;

class Particle {
public:
    Particle(float level, sf::Vector2f position)
        : shape_(100, 30),
          velocity_({0, 0}),
          acceleration_({0, 0}),
          level_(level),
          mass_(1) {
        shape_.setOrigin(sf::Vector2f({shape_.getRadius(), shape_.getRadius()}));
        shape_.setPosition(position);
        shape_.setFillColor(sf::Color(150, 50, 250));
    }

    void update() {
        addGravity();
        shape_.move(velocity_);
    }

    void addGravity() {
        constexpr float kPxPermM = 50;
        constexpr float fps = 60;
        velocity_.y += level_ * G / (fps * fps) * kPxPermM;
    }

    void draw(sf::RenderWindow& window) {
        update();
        window.draw(shape_);
    }

private:
    sf::CircleShape shape_;

    sf::Vector2f velocity_;
    sf::Vector2f acceleration_;

    float level_{};

    float mass_{};
    //float m_radius{};
    //float m_restitution{};
};