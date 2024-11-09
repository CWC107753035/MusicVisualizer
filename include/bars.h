
#ifndef BARS_H
#define BARS_H

#include <SFML/Graphics.hpp>
#include <vector>

class Bars : public sf::Drawable {
public:
    Bars(unsigned int count, float width, float height);  // Constructor
    void update(const std::vector<float>& values);        // Update bar heights

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    std::vector<sf::VertexArray> m_bars;  // Stores each bar as a rectangle
    float m_width;                        // Width of each bar
    float m_height;                       // Maximum height of each bar
};

#endif // BARS_H
