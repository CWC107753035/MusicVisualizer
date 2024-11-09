// WindowDrag.hpp
#ifndef WINDOWDRAG_HPP
#define WINDOWDRAG_HPP


#ifdef _WIN32
    #include <windows.h>
#elif defined(__linux__)
    #include <X11/Xlib.h>
    #include <X11/Xatom.h>
    #include <X11/extensions/Xrender.h>
#endif

#include <SFML/Graphics.hpp>

class WindowDrag {
public:
    // Constructor
    WindowDrag(sf::RenderWindow& window);
    void setWindowTransparency(float transparency);
    // Method to handle mouse events for dragging
    void handleEvents(const sf::Event& event);

private:
    sf::RenderWindow& m_window;  // Reference to the SFML window
    bool m_dragging;             // Whether the window is being dragged
    sf::Vector2i m_dragStartPos; // Initial mouse position when dragging starts
};

#endif // WINDOWDRAG_HPP
