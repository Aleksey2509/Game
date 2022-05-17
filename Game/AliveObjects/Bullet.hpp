#ifndef GAME_ALIVEOBJECTS_BULLET_HPP
#define GAME_ALIVEOBJECTS_BULLET_HPP

#include "Entity.hpp"

static constexpr float kBulletSpeed = 5.f;
static constexpr float kBulletHeight = 10.f;
static constexpr float kBulletWidth = 20.f;

enum Direction
{
    RIGHT = 0,
    LEFT
};

class Bullet : public Entity
{
public:
    Bullet(const float& dt, const float& fixdt, sf::Texture* texture, const float startY, Direction dir);
	virtual ~Bullet();

    virtual void FixedUpdate();
	virtual void Update();
    virtual const sf::Sprite& GetSprite() const;
    void kill();
    bool ifAlive();

private:

    Direction dir_ = Direction::RIGHT;
    float speed_ = kBulletSpeed;

    sf::Vector2u textureSize_{650, 415}; // hardcode, bad
    void InitCollisionBox(float startY);

    bool alive_ = true;

    sf::IntRect toDraw_;
    sf::Sprite sprite_;
    void InitSprite();
    const sf::Vector2i bulletSize = sf::Vector2i(20, 10);


    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

// inline bool operator==(const Bullet lhs, const Bullet rhs)
// {
//     return ((lhs.dir_ == rhs.dir_) && (lhs.alive_ == rhs.alive));
// }

#endif // GAME_ALIVEOBJECTS_BULLET_HPP