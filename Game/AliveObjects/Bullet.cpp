#include "Bullet.hpp"
#include <iostream>
#include <fstream>

static const unsigned kWidth = 1000;
static const unsigned kHeight = 1000;

Bullet::Bullet(const float& dt, const float& fixdt, sf::Texture* texture, const float startY, Direction dir) :
    Entity::Entity(dt, fixdt)
{
    texture_ = texture;
    dir_ = dir;

    InitCollisionBox(startY);
    InitSprite();
}


void Bullet::InitCollisionBox(float startY)
{
    if (dir_ == Direction::RIGHT)
        box_.pos_.x = 0;
    else
        box_.pos_.x = kHeight;

    box_.pos_.y = startY;
    box_.sz_.x = speed_;
    box_.sz_.y = kBulletHeight;
}

void Bullet::InitSprite()
{
    sprite_.setTexture(*texture_);

    toDraw_.top = 0;
    toDraw_.height = textureSize_.y;

    if (dir_ == Direction::RIGHT)
    {
        toDraw_.left = (kBulletWidth - speed_) * textureSize_.x / kBulletWidth;
        toDraw_.width = static_cast<float>(textureSize_.x) - toDraw_.left;
	    sprite_.setPosition(sf::Vector2f(0.f, box_.pos_.y));
    }
    else
    {
        toDraw_.left = 0;
        toDraw_.width = speed_ * textureSize_.x / kBulletWidth;
        sprite_.setPosition(sf::Vector2f(kHeight, box_.pos_.y));
    }

    sprite_.setTextureRect(toDraw_);
	sprite_.setScale(sf::Vector2f(kBulletWidth / textureSize_.x, kBulletHeight / textureSize_.y));
}


void Bullet::FixedUpdate()
{

    if (dir_ == Direction::RIGHT)
    {
        if ((box_.sz_.x < kBulletWidth) && (box_.pos_.x == 0))
        {
            box_.sz_.x += speed_;
            toDraw_.width = textureSize_.x * box_.sz_.x / kBulletWidth;
            toDraw_.left  = textureSize_.x - toDraw_.width;

            sprite_.setTextureRect(toDraw_);
            return;
        }

        if (box_.pos_.x >= (kWidth - kBulletWidth))
        {
            if (box_.sz_.x != 0)
                box_.sz_.x -= speed_;
            if (box_.pos_.x != kWidth)
                box_.pos_.x += speed_;
            toDraw_.width = textureSize_.x * box_.sz_.x / kBulletWidth;

            sprite_.setTextureRect(toDraw_);
            return;
        }

        box_.pos_.x += speed_;
        sprite_.move(speed_, 0.f);
    }

    else
    {
        if ((box_.sz_.x < kBulletWidth) && (box_.pos_.x == kWidth))
        {
            box_.sz_.x += speed_;
            toDraw_.width = textureSize_.x * box_.sz_.x / kBulletWidth;

            sprite_.setTextureRect(toDraw_);
            return;
        }

        if (box_.pos_.x <= kBulletWidth)
        {
            if (box_.sz_.x != 0)
                box_.sz_.x -= speed_;
            if (box_.pos_.x > 0)
                box_.pos_.x -= speed_;
            
            toDraw_.width = textureSize_.x * box_.sz_.x / kBulletWidth;
            toDraw_.left = textureSize_.x - toDraw_.width;

            sprite_.setTextureRect(toDraw_);
            return;
        }

        box_.pos_.x -= speed_;
        sprite_.move(speed_ * (-1), 0.f);
    }

    return;
}

void Bullet::Update()
{

}

void Bullet::kill() { alive_ = false; }

bool Bullet::ifAlive() { return alive_; }

const sf::Sprite& Bullet::GetSprite() const
{
    return sprite_;
}

Bullet::~Bullet()
{
}

void Bullet::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(sprite_);
}