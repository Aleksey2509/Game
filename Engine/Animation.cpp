#include "Animation.hpp"

Animation::Animation(unsigned int framesX, unsigned int framesY, float time, sf::Vector2i frameSize, sf::Sprite& sprite, unsigned int startY)
{
	unsigned int fCount = framesX * (framesY > 0 ? framesY : 1);
	updateTime_ = time;
	sprite_ = &sprite;
	frames_ = new sf::IntRect[fCount];
	frameCount_ = fCount;

	CutFrames(framesX, framesY, startY, frameSize);
}

void Animation::Create(unsigned int framesX, unsigned int framesY, float time, sf::Vector2i frameSize, sf::Sprite& sprite, unsigned int startY)
{
	if(frameCount_ > 0)
	{
		return;
	}
	unsigned int fCount = framesX * (framesY > 0 ? framesY : 1);
	updateTime_ = time;
	sprite_ = &sprite;
	frames_ = new sf::IntRect[fCount];
	frameCount_ = fCount;

	CutFrames(framesX, framesY, startY, frameSize);
}

void Animation::Update(float dt)
{
	goneTime_ += dt;
	while(goneTime_ >= updateTime_)
	{
		goneTime_ -= updateTime_;
		UpdateAnimation();
	}
}

unsigned int Animation::GetCurrentFrame() const
{
	return currentFrame_;
}

unsigned int Animation::GetFrameCount() const
{
	return frameCount_;
}

void Animation::SetFrame(unsigned frame)
{
	currentFrame_ = frame;
	sprite_->setTextureRect(frames_[currentFrame_]);
}

void Animation::SetUpdateTime(float time)
{
	updateTime_ = time;
}

Animation::~Animation()
{
	delete [] frames_;
}

void Animation::UpdateAnimation()
{
	if(++currentFrame_ > frameCount_ - 1)
	{
		currentFrame_ = 0;
	}
	sprite_->setTextureRect(frames_[currentFrame_]);
}

void Animation::CutFrames(unsigned int framesX, unsigned int framesY, unsigned int startY, const sf::Vector2i& frameSize)
{
	if(framesY > 0)
	{
		unsigned int iter = 0;
		for(unsigned int y = startY; y < startY + framesY; y++)
		{
			for(unsigned int x = 0; x < framesX; x++)
			{
				frames_[iter] = sf::IntRect(x * frameSize.x, y * frameSize.y, frameSize.x, frameSize.y);
				iter++;
			}
		}
	}
	else
	{
		for(unsigned int i = 0; i < framesX; i++)
		{
			frames_[i] = sf::IntRect(i * frameSize.x, startY * frameSize.y, frameSize.x, frameSize.y);
		}
	}
}