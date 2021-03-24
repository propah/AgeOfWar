#include "Entity.h"
Resources<Texture, int> Entity::textures;

void Entity::initVariables()
{
}

void Entity::initSprites()
{
    int texture_id = this->type;
    this->e_sprite.setTexture(Entity::textures.get(texture_id));
    this->e_sprite.setScale(0.5f, 0.5f);
}

void Entity::initTextures() {
        textures.load(1, "r_graphics/clubman.png");
}


Entity::Entity(const vector<float>& f_atri, const vector<Vector2i>& frame_sizes,const int type, const int side, const Vector2f& spawn_pos)
{
    //floats
    this->health = f_atri[0];
    this->dmg_melee = f_atri[1];
    this->dmg_ranged = f_atri[2];
    this->speed = f_atri[3];
    this->attack_speed = f_atri[4];
    this->range = f_atri[5];
    this->frame_count_atk = static_cast<unsigned int>(f_atri[6]);
    this->frame_count_walk = static_cast<unsigned int>(f_atri[7]);
    this->frame_count_stand = static_cast<unsigned int>(f_atri[8]);

    //Frame sizes
    this->size_per_frame_atk = frame_sizes[0];
    this->size_per_frame_walk = frame_sizes[1];
    this->size_per_frame_stand = frame_sizes[2];

    //Int
    this->type = type;
    this->side = side;

    //State
    this->is_in_attack_range = false;
    this->is_attaking = false;
    this->is_walking = false;
    this->is_standing = false;

    //Spawn position
    this->e_pos = spawn_pos;
    this->initTextures();
    this->initSprites();
    this->initVariables();

    
}

Entity::~Entity()
{
}

Vector2f Entity::getPosition()
{
    return this->e_pos;
}

void Entity::updateStates(float dt)
{
    if (Keyboard::isKeyPressed(Keyboard::A)) {
        this->is_attaking = true;
        this->is_walking = false;
    }
    if (Keyboard::isKeyPressed(Keyboard::W)) {
        this->is_attaking = false;
        this->is_walking = true;
    }
    if (Keyboard::isKeyPressed(Keyboard::S)) {
        this->is_attaking = false;
        this->is_walking = false;
        this->is_standing = true;
    }
}

void Entity::updateAnimation(float dt)
{
    if (this->is_attaking) {
        this->frame_index_walk = 0;
        this->frame_index_stand = 0;
        if (anim_last_atk.getElapsedTime().asSeconds()>(dt*7/this->attack_speed)) {
            this->frame_index_atk++;
            if (this->frame_index_atk >= this->frame_count_atk) {
                this->frame_index_atk = 0;
                //this->is_attaking = false;
                
            }
            this->anim_last_atk.restart();
        }
        this->e_sprite.setTextureRect(IntRect(this->frame_index_atk * this->size_per_frame_atk.x, 0,
                                              this->size_per_frame_atk.x, this->size_per_frame_atk.y));
        this->e_sprite.setOrigin(Vector2f(this->size_per_frame_atk.x / 2, this->size_per_frame_atk.y / 2));
        return;
    }
    if (this->is_walking) {
        this->frame_index_atk = 0;
        this->frame_index_stand = 0;
        if (this->anim_last_walk.getElapsedTime().asSeconds()>=dt*7) {
            this->frame_index_walk++;
            if (this->frame_index_walk >= this->frame_count_walk) {
                this->frame_index_walk = 0;
                //this->is_attaking = false;
            }
            this->anim_last_walk.restart();
        }
        this->e_sprite.setTextureRect(IntRect(this->frame_index_walk * this->size_per_frame_walk.x, this->size_per_frame_atk.y,
                                              this->size_per_frame_walk.x, this->size_per_frame_walk.y));
        this->e_sprite.setOrigin(Vector2f(this->size_per_frame_walk.x / 2, this->size_per_frame_walk.y / 2));
        return;
    }
    this->frame_index_atk = 0;
    this->frame_index_walk = 0;
    if (this->anim_last_stand.getElapsedTime().asSeconds()>=dt*6) {
        this->frame_index_stand++;
        if (this->frame_index_stand >= this->frame_count_stand) {
            this->frame_index_stand = 0;
            //this->is_attaking = false;
        }
        this->anim_last_stand.restart();
    }
    this->e_sprite.setTextureRect(IntRect(this->frame_index_stand * this->size_per_frame_stand.x, this->size_per_frame_atk.y+this->size_per_frame_stand.y+1,
                                          this->size_per_frame_stand.x, this->size_per_frame_stand.y));
    this->e_sprite.setOrigin(Vector2f(this->size_per_frame_stand.x / 2, this->size_per_frame_stand.y / 2));
}

void Entity::updatePosition(float dt)
{
    if (this->is_walking) {
        this->e_pos.x += 50 * dt;
    }
    this->e_sprite.setPosition(this->e_pos);
}

void Entity::update(float dt)
{
    this->updateStates(dt);
    this->updatePosition(dt);
    this->updateAnimation(dt);
}

void Entity::render(RenderTarget* target)
{
    target->draw(this->e_sprite);
}
 