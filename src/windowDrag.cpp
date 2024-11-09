#include <X11/Xlib.h>  // Include X11 headers first
#undef None             // Undefine the conflicting 'None'
#include "windowDrag.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>



WindowDrag::WindowDrag(sf::RenderWindow& window)
    : m_window(window), m_dragging(false) {}

void WindowDrag::handleEvents(const sf::Event& event) {
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        m_dragging = true;
        m_dragStartPos = sf::Vector2i(event.mouseButton.x, event.mouseButton.y);
    }

    if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
        m_dragging = false;
    }

    // Update window position if dragging
    if (m_dragging) {
        sf::Vector2i delta = sf::Mouse::getPosition(m_window) - m_dragStartPos;
        sf::Vector2i temp = m_window.getPosition() + delta;
        m_window.setPosition(temp);
    } 
}

void WindowDrag::setWindowTransparency(float transparency) {
    #ifdef _WIN32
        HWND hwnd = m_window.getSystemHandle();
        SetWindowLong(hwnd, GWL_EXSTYLE, GetWindowLong(hwnd, GWL_EXSTYLE) | WS_EX_LAYERED);
        SetLayeredWindowAttributes(hwnd, 0, (BYTE)(255 * transparency), LWA_ALPHA);
    #elif defined(__linux__)
        Display* display = XOpenDisplay(nullptr);
        unsigned long opacity = static_cast<unsigned long>(0xFFFFFFFF * transparency);
        Atom property = XInternAtom(display, "_NET_WM_WINDOW_OPACITY", False);
        XChangeProperty(display, m_window.getSystemHandle(), property,
                        XA_CARDINAL, 32, PropModeReplace,
                        reinterpret_cast<unsigned char*>(&opacity), 1);
        XFlush(display);
        XCloseDisplay(display);
    #endif
}
