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
class Base
{
public:
	//Constructors/Destructors
	Base(int direction=1);
	~Base();

	//Level the base to next generation
	void levelup();

	//Add 1 tower space
	void upgrade();

	//Displays where you can click to place turrets when turret byuing is activated and update the towers vector
	//void placeTurret();

	//Update / Render
	void update(const float dt);
	void updateLife(const float dt);
	void updateTowers(const float dt);
	void updateBase(const float dt);
	void render(RenderTarget* target);

	//Getters / Setters
	int getLevel();
	int getLife();
	int getMaxLife();
	int getDirection();
	int getGold();
	int getXp();
	int getEmplacements();
	void setLevel(int level);
	void setLife(int life);
	void setMaxLife(int max_life);
	void setGold(int gold);
	void setXp(int xp);
	void setEmplacements(int emplacements);
	Vector2f getPos();
	
private:
	//Game logic
	int level, life, max_life, direction, gold, xp, emplacements;

	//Position
	Vector2f pos;

	//Health bar
	RectangleShape rs_life, rs_max_life;

	//Towers
	//vector <Tower> towers;

	//Images
	Texture t_base;
	Sprite s_base;

	//Inits
	void initVariables(int direction);
	void initTextures();
	void initSprites();
	void initShapes();
	
};

