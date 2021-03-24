#include "Gui.h"

Gui::Gui()
{
	this->initVariables();
	this->initTextures();
	this->initSprites();
}

Gui::~Gui()
{
}

void Gui::update(const float dt)
{
}

void Gui::render(RenderTarget* target)
{
	target->draw(this->s_bg);
}

void Gui::initVariables()
{
	this->pos = Vector2f(420.f, 0.f);
}

void Gui::initTextures()
{
	this->t_bg.loadFromFile("r_graphics/gui_bg.png");
}

void Gui::initSprites()
{
	this->s_bg.setTexture(this->t_bg);
	this->s_bg.setScale(0.5, 0.5);
	this->s_bg.setPosition(pos);
}
