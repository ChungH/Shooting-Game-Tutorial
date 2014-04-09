//
//  BulletManager.cpp
//  shooting
//
//  Created by LeeChungHee on 2014. 4. 5..
//
//

#include "BulletManager.h"

BulletManager::BulletManager(CCNode* parent)
{
    _bullet = NULL;
    _parent = parent;
}
BulletManager::~BulletManager()
{
    delete _bullet;
    
}

void BulletManager::PlayerShootingBullet(const CCPoint& _position)
{
    _bullet = new CCSprite;
    
    if(_bullet->initWithFile("Projectile.png")==false)
    {
        delete _bullet;
        return;
    }
    
    _bullet->setPosition(_position);
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
//  CCPoint _dest(winSize.width,_bullet->getPosition().y); // X축 발사
    CCPoint _dest(_bullet->getPosition().x,winSize.height); // Y축 발사
//    float velocity = 480/1; //480fixel per 1sec
//    float realmovedulation = (winSize.width - _bullet->getPosition().x/velocity);
    CCFiniteTimeAction* moved = CCMoveTo::create(0.8f,_dest);
    CCFiniteTimeAction* finished = CCCallFuncN::create(this,callfuncN_selector(BulletManager::SpriteMoveFinished));
    
    _parent->addChild(_bullet);
    _bullet->runAction(CCSequence::create(moved,finished,NULL));
}

void BulletManager::SpriteMoveFinished(CCNode* sender)
{
    CCSprite* sprite = (CCSprite*) sender;
    _parent -> removeChild(sprite,true);
}




