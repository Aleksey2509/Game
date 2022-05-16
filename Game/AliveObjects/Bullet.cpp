#include "Bullet.hpp"
#include <iostream>
#include <fstream>

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
        box_.pos_.x = 1000;

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
        sprite_.setPosition(sf::Vector2f(1000.f, box_.pos_.y));
    }

    sprite_.setTextureRect(toDraw_);
	sprite_.setScale(sf::Vector2f(kBulletWidth / textureSize_.x, kBulletHeight / textureSize_.y));
    std::cout << kBulletWidth / textureSize_.x << ", " << kBulletHeight / textureSize_.y << std::endl;
}


void Bullet::FixedUpdate()
{
    #if 1
    std::ofstream log;
    log.open("log", std::ios_base::app);
    log << "\n\nUpdating bullet\n";
    log << "Previous box_sz_x - " << box_.sz_.x << " previous box_sz_y - " << box_.sz_.y << " previous box_pos_x - " << box_.pos_.x
    << " previous box_pos_y - " << box_.pos_.y << "\n";
    log << "Old toDraw_.left - " << toDraw_.left << " Old toDraw_.top - " << toDraw_.top << " Old toDraw_.width - " << toDraw_.width
    << " Old toDraw_.height - " << toDraw_.height << "\n";
    #endif

    if (dir_ == Direction::RIGHT)
    {
        if ((box_.sz_.x < kBulletWidth) && (box_.pos_.x == 0))
        {
            box_.sz_.x += speed_;
            toDraw_.width = textureSize_.x * box_.sz_.x / kBulletWidth;
            toDraw_.left  = textureSize_.x - toDraw_.width;

            sprite_.setTextureRect(toDraw_);
            // goto debugPrint;
            return;
        }

        if (box_.pos_.x >= (1000 - kBulletWidth))
        {
            if (box_.sz_.x != 0)
                box_.sz_.x -= speed_;
            if (box_.pos_.x != 1000)
                box_.pos_.x += speed_;
            toDraw_.width = textureSize_.x * box_.sz_.x / kBulletWidth;

            sprite_.setTextureRect(toDraw_);
            // goto debugPrint;
            return;
        }

        box_.pos_.x += speed_;
        sprite_.move(speed_, 0.f);
    }

    else
    {
        if ((box_.sz_.x < kBulletWidth) && (box_.pos_.x == 1000))
        {
            box_.sz_.x += speed_;
            toDraw_.width = textureSize_.x * box_.sz_.x / kBulletWidth;

            sprite_.setTextureRect(toDraw_);
            goto debugPrint;
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
            goto debugPrint;
            return;
        }

        box_.pos_.x -= speed_;
        sprite_.move(speed_ * (-1), 0.f);
    }



    #if 1
debugPrint:
    log << "Now: \n";
    log << "box_sz_x - " << box_.sz_.x << " box_sz_y - " << box_.sz_.y << " box_pos_x - " << box_.pos_.x
    <<  "box_pos_y - " << box_.pos_.y << "\n";
    log << "toDraw_.left - " << toDraw_.left << " toDraw_.top - " << toDraw_.top << " toDraw_.width - " << toDraw_.width
    << " toDraw_.height - " << toDraw_.height << "\n";

    log.close();
    #endif

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