#pragma once

#include <SFML/Graphics.hpp>
using namespace sf;

class UIButton
{
	public:
		UIButton();
		UIButton(float button_size, Sprite content, float pos_x,float pos_y);
		void draw(RenderWindow&);
		void setSize(float);
		bool isPressed(RenderWindow&);
		RectangleShape obj();
	private:
		RectangleShape BlankSpace;
		Sprite Content;
};

