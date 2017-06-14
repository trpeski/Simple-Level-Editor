#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
#include "Collision.h"
#include <iostream>
#include "UIButton.h"
#include <vector>

using namespace std;

int main()
{
	Sprite current;
	vector<Sprite> level;
	Texture tcloud ,troad, tearth, thouse, tgrass, tfence, ttree, tsun, mtsun, tpyramid;
	tgrass.loadFromFile("data/grass.png");
	tearth.loadFromFile("data/earth.png");
	troad.loadFromFile("data/road.png");
	thouse.loadFromFile("data/house.png");
	tfence.loadFromFile("data/fence.png");
	tcloud.loadFromFile("data/cloud.png");
	ttree.loadFromFile("data/tree.png");
	tsun.loadFromFile("data/sun.png");
	mtsun.loadFromFile("data/sun.png" , IntRect(10,10,90,90));
	tpyramid.loadFromFile("data/pyramid.png");
	Sprite grass(tgrass);
	Sprite earth(tearth);
	Sprite road(troad);
	Sprite house(thouse);
	Sprite fence(tfence);
	Sprite cloud(tcloud);
	Sprite tree(ttree);
	Sprite sun(tsun);
	Sprite msun(mtsun);
	Sprite pyramid(tpyramid);
	grass.setPosition(6,12);
	earth.setPosition(34,2);
	road.setPosition(67,12);
	house.setPosition(114,4);
	fence.setPosition(176,40);
	cloud.setPosition(285, 15); 
	tree.setPosition(372, 4);
	msun.setPosition(442, 5);
	pyramid.setPosition(543, 15);
	UIButton bgrass(30, grass, 2, 2);
	UIButton bearth(30, earth, 34, 2);
	UIButton broad(31, road, 66, 2);
	UIButton bhouse(70, house, 100, 2);
	UIButton bfence(100, fence, 175, 2);
	UIButton bcloud(80, cloud, 280, 2);
	UIButton btree(70, tree, 363, 2);
	UIButton bsun(100, msun, 436, 2);
	UIButton bpyramid(102, pyramid, 540, 2);
	RectangleShape menu;
	menu.setSize(Vector2f(1000, 107));
	menu.setFillColor(Color::Black);

	vector<Sprite> deleted;

	RenderWindow window(VideoMode(1000, 600), "Level Editor");


	while(window.isOpen())
	{
		Event event;
		while(window.pollEvent(event))
		{
			if (event.type == Event::Closed)window.close();

			if(event.type == Event::KeyPressed)
			{
				if (event.key.control) {
					if (event.key.code == Keyboard::Z && level.size() > 0)
					{
						deleted.push_back(level[level.size() - 1]);
						level.pop_back();
					}
					else if (event.key.code == Keyboard::N && deleted.size() > 0)
					{
						level.push_back(deleted[deleted.size() - 1]);
						deleted.pop_back();
					}
					else if (event.key.code == Keyboard::C)
					{
						for(int i = 0; i < level.size(); i++)
						{
							deleted.push_back(level[level.size() - 1]);
							level.pop_back();
						}
					}
				}
				if (event.key.code == Keyboard::Left)current.rotate(-0.5f);
				else if (event.key.code == Keyboard::Right)current.rotate(0.5f);
				 
				if(event.key.code == Keyboard::Space) 
				{
					Sprite* s = new Sprite(current);
					s->setPosition(Mouse::getPosition(window).x - 10, Mouse::getPosition(window).y - 10);
					level.push_back(*s);
				}


			}
			
			if(event.type == Event::MouseButtonPressed)
			{
				if(Mouse::isButtonPressed(Mouse::Left))
				{
					if (MContact(bgrass.obj())) 
					{
						current = grass;
					}
					else if (MContact(bearth.obj()))
					{
						current = earth;
					}
					else if (MContact(broad.obj()))
					{
						current = road;
					}
					else if (MContact(bhouse.obj()))
					{
						current = house; 
					}
					else if (MContact(bfence.obj()))
					{
						current = fence;
					}
					else if (MContact(bcloud.obj()))
					{
						current = cloud;
					}
					else if (MContact(btree.obj()))
					{
						current = tree;
					}
					else if (MContact(bsun.obj()))
					{
						current = sun;
					}
					else if (MContact(bpyramid.obj()))
					{
						current = pyramid;
					}
					else
					{
						Sprite* s = new Sprite(current);
						s->setPosition(Mouse::getPosition(window).x - 10, Mouse::getPosition(window).y - 10);
						level.push_back(*s);
					}
					
					
				}
			}
		}

		current.setPosition(Mouse::getPosition(window).x - 10, Mouse::getPosition(window).y - 10);
		window.clear(Color(0,162,232));
		for (int i = 0; i < level.size(); i++)window.draw(level[i]);
		window.draw(menu);
		btree.draw(window);
		bpyramid.draw(window);
		bearth.draw(window);
		bgrass.draw(window);
		broad.draw(window);
		bfence.draw(window);
		bcloud.draw(window);
		bhouse.draw(window);
		bsun.draw(window);
		window.draw(current);
		window.display();
		
	}

	return 0;
}