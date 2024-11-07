#include <SFML/Graphics.hpp>
#include<SFML/Window.hpp>


int main(int argc, char const *argv[])
{
    sf::RenderWindow window(sf::VideoMode(600,600), "Hello From SFML");
    sf::VertexArray quad(sf::Quads, 4);
    quad[0].position = sf::Vector2f(10, 10);
    quad[1].position = sf::Vector2f(110, 10);
    quad[1].position = sf::Vector2f(10, 200);
    quad[1].position = sf::Vector2f(110, 20);
    

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed){
                window.close();
            }
        }
        window.clear();
        window.draw(quad);
        window.display();
        
    }

    return 0;
}