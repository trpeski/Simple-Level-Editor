#pragma once

#include <SFML/Graphics.hpp>
using namespace sf;

#define MContact(a) a.getGlobalBounds().contains(Mouse::getPosition(window).x , Mouse::getPosition(window).y)
