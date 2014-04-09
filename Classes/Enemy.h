//
//  Enemy.h
//  shooting
//
//  Created by LeeChungHee on 2014. 3. 30..
//
//

#ifndef __shooting__Enemy__
#define __shooting__Enemy__

#include "cocos2d.h"
USING_NS_CC;

class Enemy : public cocos2d::CCLayer
{
private:
    CCSprite*   _target;
    CCNode*     _parent;
public:
    Enemy(CCNode* parent);
    ~Enemy();
public:

    void InitEnemy(const char* imagename);         //적을 생성한다
    void MoveEnemy();
    void SpriteMoveFinished(CCNode *sender);      //적을 제거한다
  };

#endif /* defined(__shooting__Enemy__) */
