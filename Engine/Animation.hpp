#ifndef ENGINE_ANIMATION_HPP
#define ENGINE_ANIMATION_HPP

#include <SFML/Graphics.hpp>

class Animation
{
public:
	Animation() = default;
	Animation(unsigned int framesX, unsigned int framesY, float time, sf::Vector2i frameSize, sf::Sprite& sprite, unsigned int startY = 0);
	~Animation();

	void Create(unsigned int framesX, unsigned int framesY, float time, sf::Vector2i frameSize, sf::Sprite& sprite, unsigned int startY = 0);
	void Update(float dt);

	unsigned int GetCurrentFrame() const;
	unsigned int GetFrameCount() const;
	void SetFrame(unsigned frame);
	void SetUpdateTime(float time);
private:
	unsigned int currentFrame_ = 0;
	unsigned int frameCount_ = 0;
	sf::IntRect* frames_ = nullptr;
	sf::Sprite* sprite_ = nullptr;

	float goneTime_ = 0.f;
	float updateTime_ = 0.f;

	void UpdateAnimation();
	void CutFrames(unsigned int framesX, unsigned int framesY, unsigned int startY, const sf::Vector2i& frameSize);
};

#endif //ENGINE_ANIMATION_HPP