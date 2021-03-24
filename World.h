#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <string>
#include "Base.h"
#include "Entity.h"
#include "Stats.hpp"
using namespace std;
using namespace sf;
enum e_type { CLUB_MAN = 1, SLING_MAN = 2, DINO = 3 };
class World
{
public:
	World();
	~World();

	int getAllyBaseLevel();
	void render(RenderTarget* target);
	//void renderEntities(RenderTarget* target);
	void update(const float dt);
private:
	Base base_ally = Base(1);
	Base base_enemy = Base(-1);
	Texture t_background;
	Sprite s_background;

	Entity test = (Entity(Stats::ClubMan::clubman_floats, Stats::ClubMan::clubman_frame_sizes, CLUB_MAN, 1, Vector2f(300, 300)));

	// Functions
	void updateEntities(float dt);
	void initTextures();
	void initSprites();

};

