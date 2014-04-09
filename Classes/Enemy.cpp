//
//  Enemy.cpp
//  shooting
//
//  Created by LeeChungHee on 2014. 3. 30..
//
//
#include "Enemy.h"
USING_NS_CC;
Enemy::Enemy(CCNode* parent)
{
    _target = NULL;
    _parent = parent;
    
}
Enemy::~Enemy()
{
    _parent->removeChild(_target,true);
    delete _target;
    
}

void Enemy::InitEnemy(const char* imagename)
{
    _target = new CCSprite;
    
    if(_target->initWithFile(imagename)== false)
    {
        delete _target;
        return;
    }
    _target = CCSprite::create(imagename);
    CCSize size = _target->getContentSize();
    
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
//    
   
    //위에서 아래로 떨어진다
    int minX = _target->getContentSize().width;
    int maxX = _target->getContentSize().width*40;
    
    int rangeX = maxX - minX;
    int actualX = ( rand() % rangeX ) + minX;
    
    _target->setPosition(ccp(actualX,winSize.height));    
    int minDuration = (int)2.0;
    int maxDuration = (int)4.0;
    int rangeDuration = maxDuration - minDuration;
    int actualDuration = ( rand() % rangeDuration ) + minDuration;
 
    CCFiniteTimeAction* actionMove = CCMoveTo::create((float)actualDuration, ccp(actualX,-1));
    CCFiniteTimeAction* actionMoveDone = CCCallFuncN::create(this,callfuncN_selector(Enemy::SpriteMoveFinished));
    
    _target->runAction(CCSequence::create(actionMove, actionMoveDone, NULL));

//    
//     //오른쪽에서 왼쪽으로 지나간다
//     int minY = _target->getContentSize().height/2;
//     int maxY = winSize.height - _target->getContentSize().height/2;
//     
//     int rangeY = maxY - minY;
//     int actualY = ( rand() % rangeY ) + minY;
//     
//     _target->setPosition(ccp(winSize.width + (_target->getContentSize().width/2),actualY));
//    
//     int minDuration = (int)2.0;
//     int maxDuration = (int)4.0;
//     int rangeDuration = maxDuration - minDuration;
//     int actualDuration = ( rand() % rangeDuration ) + minDuration;
//     
//     CCFiniteTimeAction* actionMove = CCMoveTo::create((float)actualDuration, ccp(0-_target->getContentSize().width/2,actualY));
//     
//     CCFiniteTimeAction* actionMoveDone = CCCallFuncN::create(this,callfuncN_selector(Enemy::SpriteMoveFinished));
//     
//     _target->runAction(CCSequence::create(actionMove, actionMoveDone, NULL));
//
    
    _parent ->addChild(_target);
    //target->setTag(1);
    
    
}
void Enemy::MoveEnemy()
{
    
}

void Enemy::SpriteMoveFinished(CCNode *sender)
{
    CCSprite* sprite = (CCSprite*) sender;
    _parent -> removeChild(sprite,true);

}