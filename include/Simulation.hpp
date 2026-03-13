#pragma once
#include <vector>

#include "Particle.hpp"

class Simulation {
public:
    void update(float dt) {
        applyGravity();
        updateParticles(dt);
    }

    void addParticle(sf::Vector2f position, float radius) {
        Particle new_particle{position, radius};
        particles_.emplace_back(new_particle);
    }

    void draw(sf::RenderWindow& window) {
        for (auto& p : particles_) {
            p.draw(window);
        }
    }


private:
    void applyGravity() {
        for (auto& p : particles_) {
            p.accelerate(gravity_);
        }
    }

    void updateParticles(float dt) {
        for (auto& p : particles_) {
            p.update(dt);
        }
    }

private:
    std::vector<Particle> particles_;
    sf::Vector2f gravity_ = {0.0f, 1000.0f};
};