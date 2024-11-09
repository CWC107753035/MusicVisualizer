#include <SFML/Graphics.hpp>
#include "bars.h"
#include <vector>
#include "windowDrag.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Transparent Window");
    window.setPosition(sf::Vector2i(100, 100));

    WindowDrag dragHandler(window);  // Assuming WindowDrag is a custom class
    dragHandler.setWindowTransparency(0.5f);

    unsigned int barCount = 50;
    float barWidth = 10.0f;
    float maxHeight = 500.0f;
    
    Bars bars(barCount, barWidth, maxHeight);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            dragHandler.handleEvents(event);
        }

        // Update bars with random values for testing
        std::vector<float> values(barCount);
        for (auto& value : values) {
            value = static_cast<float>(rand()) / RAND_MAX;  // Random value between 0 and 1
        }
        bars.update(values);

        window.clear();
        window.draw(bars);
        window.display();
    }

    return 0;
}
