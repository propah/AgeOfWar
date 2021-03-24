#include "World.h"

World::World()
{
	this->initTextures();
	this->initSprites();
}

World::~World()
{
}

int World::getAllyBaseLevel()
{
	return this->base_ally.getLevel();
}

void World::render(RenderTarget* target)
{
	target->draw(this->s_background);
	this->base_ally.render(target);
	this->base_enemy.render(target);
	this->test.render(target);
	//this->renderEntities(target);
}

/*void World::renderEntities(RenderTarget* target)
{
	for (Entity ent : this->entities) {
		ent.render(target);
	}
}*/

void World::update(const float dt)
{
	this->base_ally.update(dt);
	this->base_enemy.update(dt);
	this->test.update(dt);
	//this->updateEntities(dt);
}


/*void World::updateEntities(float dt)
{
	for (Entity ent : this->entities) {
		ent.update(dt);
	}
}*/

void World::initTextures()
{
	this->t_background.loadFromFile("r_graphics/background.png");
	this->t_background.setSmooth(true);
}

void World::initSprites()
{
	this->s_background.setTexture(t_background);
	this->s_background.setPosition(Vector2f(0.f, 0.f));
	this->s_background.setScale(0.5, 0.5);
}
