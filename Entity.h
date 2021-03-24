#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <string>
#include "Resources.h"
using namespace std;
using namespace sf;
class Entity
{
private:
	/////
	// Variables
	/////

	//Attributes
	bool is_in_attack_range, is_attaking, is_walking, is_standing;
	float health, dmg_melee, dmg_ranged, speed, attack_speed, range;
	int type, side;

	//Frames sizes in pixels
	Vector2i size_per_frame_atk;
	Vector2i size_per_frame_walk;
	Vector2i size_per_frame_stand;

	//Current frame in sprite
	unsigned int frame_index_atk=0;
	unsigned int frame_index_walk = 0;
	unsigned int frame_index_stand = 0;

	//Number of frames per anim
	unsigned int frame_count_atk;
	unsigned int frame_count_walk;
	unsigned int frame_count_stand;

	//Clock times for anim
	Clock anim_last_atk;
	Clock anim_last_walk;
	Clock anim_last_stand;

	//Textures
	enum Textures : int{ClubMan};
	static Resources<sf::Texture, int> textures;

	//Sprites
	Sprite e_sprite;

	//Position
	Vector2f e_pos;

	//Size hitbox
	Vector2f e_hitbox;

	//Animation location



	//Functions
	void initVariables();
	void initSprites();
	static void initTextures();
public:
	// Constructors / Destructors
	Entity(const vector<float>& f_atri, const vector<Vector2i>& frame_sizes, const int type, const int side, const Vector2f& spawn_pos);
	~Entity();

	//Functions
	Vector2f getPosition();
	void updateStates(float dt);
	void updateAnimation(float dt);
	void updatePosition(float dt);
	void update(float dt);
	void render(RenderTarget* target);

};