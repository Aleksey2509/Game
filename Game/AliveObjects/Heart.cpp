#include "Heart.hpp"
#include <random>

static const int kWidth = 1000;
static const int kHeight = 1000;

Heart::Heart(const float& dt, const float& fixdt, sf::Texture* texture) : Entity(dt, fixdt)
{
	texture_ = texture;
	InitBody();
	InitAnimations();
}

Heart::~Heart() {}

void Heart::FixedUpdate()
{
	const float gravity = 300.f;
	if(!grounded_)
	{
		box_.pos_.y += gravity*fixdt_;
	}

	reinterpret_cast<sf::Sprite*>(drawable_)->setPosition(box_.pos_);
}

void Heart::Update()
{
	animations_.Update(dt_);
	if(realDeSpawnClock_.GetTime().asSeconds() > deSpawnTime_ * 3.f)
	{
		exist_ = false;
	}
	if(deSpawnClock_.GetTime().asSeconds() > deSpawnTime_)
	{
		disapTime_ -= 0.2f;
		disap_ = true;
		deSpawnClock_.restart();
	}
	if(disap_)
	{
		Animate();
	}
}

void Heart::ResolveCollision(std::vector<Platform>& platforms)
{
	for(auto& it : platforms)
	{
		sf::Vector2f pos;
		if(!GetBox().CheckCollision(it.GetBox(), pos))
		{
			continue;
		}
		box_.pos_ += pos;
		grounded_ = true;
		break;
	}
}

bool Heart::IsExist() const
{
	return exist_;
}

void Heart::Animate()
{
	if(disapClock_.GetTime().asSeconds() > disapTime_)
	{
		curclr_++;
		if(curclr_ > 4)
		{
			curclr_ = 0;
		}
		disapClock_.restart();
	}
	reinterpret_cast<sf::Sprite*>(drawable_)->setColor(colors_[curclr_]);
}

void Heart::InitBody()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> rand(32, kWidth - 32);
	int pos = rand(gen);
	drawable_ = new sf::Sprite(*texture_);
	reinterpret_cast<sf::Sprite*>(drawable_)->setOrigin(sf::Vector2f(32.f, 32.f)/2.f);
	reinterpret_cast<sf::Sprite*>(drawable_)->setPosition(sf::Vector2f(pos, -100.f));
	const sf::Vector2f size = sf::Vector2f(32.f, 32.f);
	box_.sz_ = size;
	box_.pos_ = sf::Vector2f(pos, -100.f);
}

void Heart::InitAnimations()
{
	animations_.Create(4, 0, 0.1f, sf::Vector2i(32, 32), *reinterpret_cast<sf::Sprite*>(drawable_));
}

void Heart::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(*drawable_);
}