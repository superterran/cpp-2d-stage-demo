#include "graphics.h"
#include "sprite.h"
#include "animatedsprite.h"


AnimatedSprite::AnimatedSprite() {}

AnimatedSprite::~AnimatedSprite() {}


AnimatedSprite::AnimatedSprite(Graphics &graphics, const std::string &filePath, int sourceX, int sourceY, int width, int height, float posX, float posY, float timeToUpdate) : 
    Sprite(graphics, filePath, sourceX, sourceY, width, height, posX, posY),
    _frameIndex(0),
    _timeToUpdate(timeToUpdate),
    _visible(true),
    _currentAnimationOnce(false),
    _currentAnimation("")
    {}
