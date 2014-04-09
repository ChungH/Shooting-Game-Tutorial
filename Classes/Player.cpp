//
//  Player.cpp
//  shooting
//
//  Created by LeeChungHee on 2014. 3. 30..
//
//

#include "Player.h"
USING_NS_CC;

Player::Player(CCNode* parent)
{
    _sprite = NULL;
    _parent = parent;
}

Player::~Player()
{
    _parent->removeChild(_sprite, true);
    delete _sprite;

}

bool Player::Init(const char* imageName, const CCPoint& startPosition)
{
    _sprite = new CCSprite;
    
    if( _sprite->initWithFile(imageName) == false )
    {
        delete _sprite;
        return false;
    }
    
    _sprite->setPosition(startPosition);
    _sprite->setAnchorPoint(ccp(0.5f, 0.5f));
    
    _parent->addChild(_sprite);
    
    return true;
}

void Player::SetPosition(const CCPoint& pos)
{
    _sprite->setPosition(pos);
}

const CCPoint& Player::GetPosition()
{
    return _sprite->getPosition();
}
