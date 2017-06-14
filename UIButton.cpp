#include "UIButton.h"
#include "Collision.h"
#include <iostream>

UIButton::UIButton()
{
	std::cout << "[<!>] UIButton pos and size has not been set you called the not overloaded ctor" << std::endl;
}

UIButton::UIButton(float button_size, Sprite content, float pos_x, float pos_y)
{
	BlankSpace.setFillColor(Color::White);
	BlankSpace.setSize(Vector2f(button_size, button_size));
	Content = content;
	std::cout << "[<?>] have you set UIButton content param of ctor to a loaded predefined sprite if empty will couse problems "<< std::endl;
	BlankSpace.setPosition(pos_x, pos_y);
}




void UIButton::draw(RenderWindow &window)
{
	window.draw(BlankSpace);
	window.draw(Content);
}

void UIButton::setSize(float s)
{
	BlankSpace.setSize(Vector2f(s,s));
}

bool UIButton::isPressed(RenderWindow& window) 
{
	return MContact(BlankSpace);
}

RectangleShape UIButton::obj()
{
	return BlankSpace;
}

