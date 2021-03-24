#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
using namespace sf;
class Gui
{
public:
	Gui();
	~Gui();

	void update(const float dt);
	void render(RenderTarget* target);
private:


	//To draw
	Texture t_bg;
	Sprite s_bg;

	//Position
	Vector2f pos;




	void initVariables();
	void initTextures();
	void initSprites();

};

