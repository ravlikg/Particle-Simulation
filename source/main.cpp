#include <SFML/Graphics.hpp>

#include "Application.hpp"
#include "Particle.hpp"

int main() {
    sf::ContextSettings settings;
    settings.antiAliasingLevel = 8;

    Application application(settings);
    application.run();

    return 0;
}