#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup") 
#include "Collision.h"
#include <iostream>
#include "UIButton.h"
#include <vector>  
#include <fstream>
#include <algorithm>
#include <string>
#include <sstream>
#include <set>

using namespace std;



int main()
{
	
	RectangleShape current_top;
	current_top.setFillColor(Color::Color(255,255,255,50));
	Text objname;
	Text numofobjs;
	Text saving;
	Sprite current;
	vector<Sprite> level;
	Texture tcloud ,troad, tearth, thouse, tgrass, tfence, ttree, tsun, mtsun, tpyramid, twatter, mtwatter;
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
	twatter.loadFromFile("data/watter.png");
	mtwatter.loadFromFile("data/watter.png", IntRect(4, 3, 30, 30));
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
	Sprite watter(twatter);
	Sprite mwatter(mtwatter);
	grass.setPosition(6,12);
	earth.setPosition(34,2);
	road.setPosition(67,12);
	house.setPosition(114,4);
	fence.setPosition(176,40);
	cloud.setPosition(285, 15); 
	tree.setPosition(372, 4);
	msun.setPosition(442, 5);
	pyramid.setPosition(543, 15);
	mwatter.setPosition(4, 37);
	UIButton bgrass(30, grass, 2, 2);
	UIButton bearth(30, earth, 34, 2);
	UIButton broad(31, road, 66, 2);
	UIButton bhouse(70, house, 100, 2);
	UIButton bfence(100, fence, 175, 2);
	UIButton bcloud(80, cloud, 280, 2);
	UIButton btree(70, tree, 363, 2);
	UIButton bsun(100, msun, 436, 2);
	UIButton bpyramid(102, pyramid, 540, 2);
	UIButton bwatter(35, mwatter, 2, 35);
	RectangleShape menu;
	menu.setSize(Vector2f(1000, 107));
	menu.setFillColor(Color::Black);
	Font textf;
	textf.loadFromFile("data/ariblk.ttf");
	objname.setFont(textf);
	objname.setCharacterSize(12);
	objname.setPosition(0, 580);
	objname.setFillColor(Color::Black); 
	saving.setFont(textf);
	saving.setPosition(70,580);
	saving.setFillColor(Color::Black);
	saving.setString("saving...");
	saving.setCharacterSize(12);
	numofobjs.setFont(textf);
	numofobjs.setCharacterSize(12);
	numofobjs.setPosition(60, 580);
	numofobjs.setFillColor(Color::Black);
	Text close(numofobjs);
	close.setString("you have not saved your work! sure you want to close the editor");
	close.setPosition(90,580);
	RectangleShape info(Vector2f(1000,18));
	info.setPosition(0,582);
	

	fstream filee("level.lvl" , ios::ios_base::in);

	CircleShape dot(4);
	dot.setPointCount(5);
	dot.setFillColor(Color::Cyan);

	vector<Sprite> deleted;
	
	int in;
	int in2;
	int in3;
	while(filee >> in)
	{
		Sprite *n;
		if(in == 1)n = new Sprite(tree);
		else if (in == 2)n = new Sprite(house);
		else if (in == 3)n = new Sprite(road);
		else if (in == 4)n = new Sprite(earth);
		else if (in == 5)n = new Sprite(grass);
		else if (in == 6)n = new Sprite(pyramid);
		else if (in == 7)n = new Sprite(sun);
		else if (in == 8)n = new Sprite(cloud);
		else if (in == 9)n = new Sprite(fence);
		else if (in == 10)n = new Sprite(watter);
		filee >> in;
		filee >> in2;
		filee >> in3;
		n->setPosition(in, in2);
		n->setRotation(in3);
		level.push_back(*n);
	}

	filee.close();

	RenderWindow window(VideoMode(1000, 600), "Level Editor");
	window.setMouseCursorVisible(false);
	ofstream file("level.lvl", ios::ios_base::out);
	  
	bool save; 
	bool cl_str = false;

	while(window.isOpen())
	{
		save = false;
		Event event;
		while(window.pollEvent(event))
		{
			if(event.type == Event::MouseWheelMoved)
			{
					current.rotate(event.mouseWheel.delta);
					current_top.rotate(event.mouseWheel.delta);
			}
			if (event.type == Event::Closed) 
			{ 
				if (cl_str)window.close();
				cl_str = true;
			}
			if (event.type == Event::KeyPressed)
			{

				if (event.key.control) {

					if (event.key.code == Keyboard::S)
					{

						save = true;
						for (int i = 0; i < level.size(); i++)
						{
							if (level[i].getTexture() == tree.getTexture())file << 1 << endl;
							else if (level[i].getTexture() == house.getTexture())file << 2 << endl;
							else if (level[i].getTexture() == road.getTexture())file << 3 << endl;
							else if (level[i].getTexture() == earth.getTexture())file << 4 << endl;
							else if (level[i].getTexture() == grass.getTexture())file << 5 << endl;
							else if (level[i].getTexture() == pyramid.getTexture())file << 6 << endl;
							else if (level[i].getTexture() == sun.getTexture())file << 7 << endl;
							else if (level[i].getTexture() == cloud.getTexture())file << 8 << endl;
							else if (level[i].getTexture() == fence.getTexture())file << 9 << endl;
							else if (level[i].getTexture() == watter.getTexture())file << 10 << endl;

							file << level[i].getPosition().x << endl << level[i].getPosition().y << endl;
							file << level[i].getRotation() << endl;


						}
						file.close();
					}
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
						while (level.size() != 0)
							for (int i = 0; i < level.size(); i++)
							{
								deleted.push_back(level[level.size() - 1]); 
								level.pop_back();
							}
					}
				}
				if (event.key.code == Keyboard::Left) 
				{
					current.rotate(-0.5f);
					current_top.rotate(-0.5f);
				}
				else if (event.key.code == Keyboard::Right)
				{
					current.rotate(0.5f);
					current_top.rotate(-0.5f);
			    }
				 
				if(event.key.code == Keyboard::Space) 
				{
					Sprite* s = new Sprite(current);
					s->setPosition(Mouse::getPosition(window).x - 10, Mouse::getPosition(window).y - 10);
					level.push_back(*s);
				}


			}
			
			if(event.type == Event::MouseButtonPressed)
			{
			
				if(Mouse::isButtonPressed(Mouse::Right))
				{
					Sprite* s = new Sprite(current);
					s->setPosition(Mouse::getPosition(window).x - 10, Mouse::getPosition(window).y - 10);
					level.push_back(*s); 
					if (!menu.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y)) {

						Mouse::setPosition(Vector2i(Mouse::getPosition().x - 20, Mouse::getPosition().y));
						if (current.getTexture() == tree.getTexture())
							Mouse::setPosition(Vector2i(Mouse::getPosition().x - 40, Mouse::getPosition().y));
						if (current.getTexture() == cloud.getTexture())
							Mouse::setPosition(Vector2i(Mouse::getPosition().x - 50, Mouse::getPosition().y - 12));
					}
				}
				if(Mouse::isButtonPressed(Mouse::Left))
				{
					if (MContact(bgrass.obj())) 
					{
						current = grass;
						objname.setString("grass");
					}
					else if (MContact(bearth.obj()))
					{
						current = earth;
						objname.setString("earth");
					}
					else if (MContact(broad.obj()))
					{
						current = road;
						objname.setString("road");
					}
					else if (MContact(bhouse.obj()))
					{
						current = house;
						objname.setString("house");
					}
					else if (MContact(bfence.obj()))
					{
						current = fence;
						objname.setString("fence");
					}
					else if (MContact(bcloud.obj()))
					{
						current = cloud;
						objname.setString("cloud");
					}
					else if (MContact(btree.obj()))
					{
						current = tree;
						objname.setString("tree");
					}
					else if (MContact(bsun.obj()))
					{
						current = sun;
						objname.setString("sun");
					}
					else if (MContact(bpyramid.obj()))
					{
						current = pyramid;
						objname.setString("pyramid");
					}
					else if (MContact(bwatter.obj()))
					{
						current = watter;
						objname.setString("watter");
					}
					else
					{
						Sprite* s = new Sprite(current);
						s->setPosition(Mouse::getPosition(window).x - 10, Mouse::getPosition(window).y - 10);
						level.push_back(*s);
						if (!menu.getGlobalBounds().contains(Mouse::getPosition(window).x, Mouse::getPosition(window).y)) {

							Mouse::setPosition(Vector2i(Mouse::getPosition().x + 20, Mouse::getPosition().y));
							if (current.getTexture() == tree.getTexture())
								Mouse::setPosition(Vector2i(Mouse::getPosition().x + 40, Mouse::getPosition().y));
							if (current.getTexture() == cloud.getTexture())
								Mouse::setPosition(Vector2i(Mouse::getPosition().x + 50, Mouse::getPosition().y + 12));
						}
					}
					
					
					
				}
			} 
		
			dot.setPosition(Mouse::getPosition(window).x, Mouse::getPosition(window).y);
			current_top.setPosition(current.getPosition()); 
			current_top.setSize(Vector2f(current.getTextureRect().width,current.getTextureRect().height));
		}
		ostringstream num;
		num << level.size();
		numofobjs.setString(num.str().c_str()); 
		current.setPosition(Mouse::getPosition(window).x - 10, Mouse::getPosition(window).y - 10);
		window.clear(Color(0,162,232));
		for (int i = 0; i < level.size(); i++)window.draw(level[i]);
		window.draw(menu);
		bwatter.draw(window);
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
		window.draw(current_top);
		window.draw(info);
		window.draw(objname);
		window.draw(numofobjs);
		if (cl_str)window.draw(close);
		if (save)window.draw(saving);
		window.draw(dot);
		window.display();
		
	}

	return 0;
}