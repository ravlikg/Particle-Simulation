#pragma once
#include <vector>

#include "Particle.hpp"

class Simulation {
public:
    void update() {
        const int sub_steps = 8;
        float sub_dt = dt_ / (float)sub_steps;

        for (int i = 0; i < sub_steps; ++i) {
            applyGravity();
            applyBorder();
            //solveCollisions();
            updateParticles(sub_dt);
        }
    }

    void addParticle(sf::Vector2f position, float radius) {
        Particle new_particle{position, radius};
        particles_.emplace_back(new_particle);
    }

    void draw(sf::RenderWindow& window) {
        sf::CircleShape shape;
        for (auto& p : particles_) {
            shape.setRadius(p.getRadius());
            shape.setOrigin({p.getRadius(), p.getRadius()});
            shape.setPosition(p.getPosition());
            shape.setFillColor(sf::Color::Blue);

            window.draw(shape);
        }
    }


private:
    void applyGravity() {
        for (auto& p : particles_) {
            p.accelerate(gravity_);
        }
    }

    void applyBorder() {
        float bounce = 0.9f;   // сколько энергии сохраняем при ударе
        float friction = 0.75f; // по перпендикулярной оси

        for (auto& p : particles_) {
            sf::Vector2f pos = p.getPosition();
            sf::Vector2f vel = p.getVelocity();
            float r = p.getRadius();

            // X
            if (pos.x < r) {
                pos.x = r;
                vel.x *= -bounce;
                vel.y *= friction;
            }
            else if (pos.x > bounds_.x - r) {
                pos.x = bounds_.x - r;
                vel.x *= -bounce;
                vel.y *= friction;
            }

            // Y
            if (pos.y < r) {
                pos.y = r;
                vel.y *= -bounce;
                vel.x *= friction;
            }
            else if (pos.y > bounds_.y - r) {
                pos.y = bounds_.y - r;
                vel.y *= -bounce;
                vel.x *= friction;
            }

            p.setPosition(pos);
            p.setVelocity(vel); // плавно обновляем previous_position
        }
    }

    void updateParticles(float dt) {
        for (auto& p : particles_) {
            p.update(dt);
        }
    }

private:
    std::vector<Particle> particles_;
    float dt_ = 1.0f / 60.0f;
    sf::Vector2f gravity_ = {0.0f, 1000.0f};
    sf::Vector2f bounds_ = {800.0f, 1000.0f};

};