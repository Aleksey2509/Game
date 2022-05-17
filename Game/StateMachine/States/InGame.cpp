#include <iostream>
#include "InGame.hpp"

static std::random_device rd;
static std::mt19937 gen(rd());

static int maxBullets = 5;

static const int kWidth = 1000;
static const int kHeight = 1000;

InGame::InGame(StateMachine& machine) : State(machine)
{
	InitPlatforms();
	InitAssets();
	InitSprites();
	InitEntities();
}

InGame::~InGame()
{
	delete player_;
	delete heart_;
}

void InGame::FixedUpdate()
{
	if(player_->IsAlive())
	{
        FixedUpdateEntities();
        resolveBulletCollisions();
	}
}

void InGame::Update()
{
    if(player_->IsAlive())
	{
        UpdateEntities();
        static int ticks = 1;
        if (bullets_.size() < maxBullets && (ticks % 200) == 0)
            InitBullet();

        ticks = (ticks + 1) % 200;
    }
}

void InGame::Render(sf::RenderTarget& target)
{
	target.draw(sprites_["background"]);
	target.draw(*player_);
    for (auto bulletIt = bullets_.begin(); bulletIt != bullets_.end(); ++bulletIt)
    {
        target.draw(bulletIt->GetSprite());
    }
	if(heart_)
	{
		target.draw(*heart_);
	}
}

void InGame::SpawnHeart()
{
	if(heartSpawnClock_.getElapsedTime().asSeconds() > 10.f)
	{
		heart_ = new Heart(dt_, fixdt_, &textureManager_.Get("heart"));
	}
}

void InGame::InitAssets()
{
	textureManager_.Load("player", "../Images/player.png");
	textureManager_.Load("background", "../Images/map.png");
    textureManager_.Load("rightBullet", "../Images/rightBullet.png");
    textureManager_.Load("leftBullet", "../Images/leftBullet.png");
	textureManager_.Load("heart", "../Images/heart.png");
	textureManager_.Load("healthbar", "../Images/healthbar.png");
}

void InGame::InitPlatforms()
{
	platforms_.push_back(Platform(sf::Vector2f(kWidth/2.f, 940.f), sf::Vector2f(1100.f, 100.f)));
	platforms_.push_back(Platform(sf::Vector2f(140.f, 755.f), sf::Vector2f(220.f, 50.f)));
	platforms_.push_back(Platform(sf::Vector2f(500.f, 755.f), sf::Vector2f(260.f, 50.f)));
	platforms_.push_back(Platform(sf::Vector2f(810.f, 755.f), sf::Vector2f(200.f, 50.f)));
	platforms_.push_back(Platform(sf::Vector2f(200.f, 595.f), sf::Vector2f(200.f, 50.f)));
	platforms_.push_back(Platform(sf::Vector2f(730.f, 565.f), sf::Vector2f(180.f, 50.f)));
	platforms_.push_back(Platform(sf::Vector2f(480.f, 445.f), sf::Vector2f(200.f, 50.f)));
	platforms_.push_back(Platform(sf::Vector2f(210.f, 305.f), sf::Vector2f(200.f, 50.f)));
	platforms_.push_back(Platform(sf::Vector2f(810.f, 335.f), sf::Vector2f(200.f, 50.f)));
	platforms_.push_back(Platform(sf::Vector2f(420.f, 175.f), sf::Vector2f(200.f, 50.f)));
	platforms_.push_back(Platform(sf::Vector2f(730.f, 175.f), sf::Vector2f(200.f, 50.f)));
}

void InGame::InitSprites()
{
	auto& sprite = sprites_["background"];
	sprite.setTexture(textureManager_.Get("background"));
	sprite.setScale(sf::Vector2f(1.f, 1.f));
	sprite.setPosition(sf::Vector2f(0.f, 0.f));
}

void InGame::InitEntities()
{
	player_ = new Player(dt_, fixdt_, &textureManager_.Get("player"));
	player_->healthbar_ = new HealthBar(&textureManager_.Get("healthbar"));
}

void InGame::FixedUpdateEntities()
{
	player_->FixedUpdate();
    for (auto bulletIt = bullets_.begin(); bulletIt != bullets_.end(); ++bulletIt)
    {
        bulletIt->FixedUpdate();
        if (bulletIt->GetBox().sz_.x <= 0)
        {
            auto toErase = bulletIt;
            bulletIt--;
            bullets_.erase(toErase);
        }
    }
	if(heart_)
	{
		heart_->FixedUpdate();
	}
}

void InGame::UpdateEntities()
{
	player_->ResolveCollision(platforms_);
    	if(heart_)
	{
		player_->ResolveCollision(heart_);
	}
	player_->Update();
	if(!heart_)
	{
		SpawnHeart();
	}
	if(heart_ && !heart_->IsExist())
	{
		delete heart_;
		heart_ = nullptr;
	}
	else if(heart_)
	{
		heart_->Update();
		heart_->ResolveCollision(platforms_);
		heartSpawnClock_.restart();
	}
	player_->Update();
}

void InGame::InitBullet()
{
    std::uniform_int_distribution<int> distributionY(0, window_.getSize().y - 100);
    std::uniform_int_distribution<int> distributionDir(0, 1);

    int startY = distributionY(gen);
    if (distributionDir(gen) == 0)
        bullets_.push_back(Bullet(dt_, fixdt_, &(textureManager_.Get("rightBullet")), startY, Direction::LEFT));
    else
        bullets_.push_back(Bullet(dt_, fixdt_, &(textureManager_.Get("leftBullet")), startY, Direction::RIGHT));
}

void InGame::resolveBulletCollisions()
{
    for (auto& bulletIt : bullets_)
    {
        if (!bulletIt.ifAlive())
            continue;

        auto& bulletBox = bulletIt.GetBox();

        sf::Vector2f intersect{};
        for (auto& bulletIt2 : bullets_)
        {
            if (!bulletIt2.ifAlive() || (bulletBox == bulletIt2.GetBox()))
                continue;

            if (bulletBox.CheckCollision(bulletIt2.GetBox(), intersect))
            {
                bulletIt.kill();
                bulletIt2.kill();
            }
        }

    }

    removeDeadBullets();
}


void InGame::removeDeadBullets()
{
    for (auto it = bullets_.begin(); it != bullets_.end(); it++)
    {
        if (it->ifAlive())
            continue;

        auto toErase = it;
        it--;
        bullets_.erase(toErase);
    }
}


