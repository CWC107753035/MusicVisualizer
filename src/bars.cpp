// bars.cpp
#include "bars.h"

Bars::Bars(unsigned int count, float width, float height)
    : m_width(width), m_height(height) {

    // Initialize each bar with two triangles (making a rectangle)
    for (unsigned int i = 0; i < count; ++i) {
        sf::VertexArray bar(sf::Quads, 4);
        
        // Set the initial position and size of the bar
        float xPos = i * (m_width + 2);  // 2 is the spacing between bars

        bar[0].position = sf::Vector2f(xPos, height);           // Bottom-left
        bar[1].position = sf::Vector2f(xPos + m_width, height); // Bottom-right
        bar[2].position = sf::Vector2f(xPos + m_width, height); // Top-right
        bar[3].position = sf::Vector2f(xPos, height);           // Top-left

        // Set initial color of the bar
        for (int j = 0; j < 4; ++j) {
            bar[j].color = sf::Color::Green;
        }

        m_bars.push_back(bar);
    }
}

void Bars::update(const std::vector<float>& values) {
    // Update each bar's height based on the corresponding value
    for (size_t i = 0; i < m_bars.size() && i < values.size(); ++i) {
        float newHeight = m_height * values[i];  // Scale height by value
        
        m_bars[i][2].position.y = m_height - newHeight;  // Top-right
        m_bars[i][3].position.y = m_height - newHeight;  // Top-left
    }
}

void Bars::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    // Draw each bar
    for (const auto& bar : m_bars) {
        target.draw(bar, states);
    }
}
