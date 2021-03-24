#include "Base.h"

Base::Base(int direction)
{
	this->initVariables(direction);
	this->initTextures();
	this->initSprites();
	this->initShapes();
}

Base::~Base()
{
}

void Base::levelup()
{
	this->level++;
}

void Base::initVariables(int direction)
{
	this->direction = direction;
	//this->towers = { 0, 0, 0, 0 };
	this->level = 1;
	this->life = 500;
	this->max_life = 500;
	this->gold = 175;
	this->xp = 0;
	this->emplacements = 4;
	this->pos = (Vector2f(-7.f, 120.f));
		if (direction == -1) {
			this->pos = (Vector2f(500.f, 120.f));
	}
	
}

void Base::initTextures()
{
	this->t_base.loadFromFile("r_graphics/bases.png");
	this->t_base.setSmooth(true);
}

void Base::initSprites()
{
	this->s_base.setTexture(this->t_base);
	this->s_base.setTextureRect(IntRect(0, 0, 333, 655));
	this->s_base.setScale(0.5, 0.5);
	if (this->direction == -1) {
		this->s_base.setOrigin(Vector2f(333.f, 0));
		this->s_base.setScale(-0.5, 0.5);
	}
	this->s_base.setPosition(this->pos);
}

void Base::initShapes()
{
	this->rs_max_life.setSize(Vector2f(15, 149));
	this->rs_max_life.setFillColor(Color::Color(30, 0, 8));
	this->rs_max_life.setPosition(this->pos.x + 37.f, this->pos.y + 20.f);
	if (this->direction == -1) {
		this->rs_max_life.setPosition(this->pos.x + 116, this->pos.y + 20.f);
	}
	this->rs_life.setSize(Vector2f(rs_max_life.getSize().x-4, rs_max_life.getSize().y - 2));
	this->rs_life.setFillColor(Color::Color(255, 23, 0));
	this->rs_life.setPosition(Vector2f(rs_max_life.getPosition().x+2, rs_max_life.getPosition().y + 2));
}

void Base::upgrade()
{
	/*for (int i = 0; i < this->towers.size(); i++) {
		if (this->towers[i] == 0) {
			this->towers[i] = 1;
			return;
		}
	}*/
}

/*void Base::placeTurret()
{
}*/

void Base::update(const float dt)
{
	this->updateLife(dt);
	this->updateBase(dt);
	this->updateTowers(dt);
}

void Base::updateLife(const float dt)
{
	this->rs_life.setSize(Vector2f(this->rs_life.getSize().x, static_cast<float>(this->life)/ static_cast<float>(this->max_life)*this->rs_max_life.getSize().y-4 ));
}

void Base::updateTowers(const float dt)
{
	// To be done
}

void Base::updateBase(const float dt)
{
	this->s_base.setTextureRect(IntRect(333*(this->emplacements - 1), 0, 333, 655));
}

void Base::render(RenderTarget* target)
{
	target->draw(this->s_base);
	target->draw(this->rs_max_life);
	target->draw(this->rs_life);
}

int Base::getLevel()
{
	return this->level;
}

int Base::getLife()
{
	return this->life;
}

int Base::getMaxLife()
{
	return this->max_life;
}

int Base::getDirection()
{
	return this->direction;
}

int Base::getGold()
{
	return this->gold;
}

int Base::getXp()
{
	return this->xp;
}

int Base::getEmplacements()
{
	return this->emplacements;
}

void Base::setLevel(int level)
{
	this->level = level;
}

void Base::setLife(int life)
{
	this->life = life;
}

void Base::setMaxLife(int max_life)
{
	this->max_life = max_life;
}

void Base::setGold(int gold)
{
	this->gold = gold;
}

void Base::setXp(int xp)
{
	this->xp = xp;
}

void Base::setEmplacements(int emplacements)
{
	this->emplacements = emplacements;
}

Vector2f Base::getPos()
{
	return this->pos;
}
