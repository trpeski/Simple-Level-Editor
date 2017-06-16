#include "UIButton.h"
#include "Collision.h"
#include <iostream>



UIButton::UIButton(float button_size, Sprite content, float pos_x, float pos_y)
{
	BlankSpace.setFillColor(Color::White);
	BlankSpace.setSize(Vector2f(button_size, button_size));
	Content = content;
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

