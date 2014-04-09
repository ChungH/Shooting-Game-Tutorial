//
//  BulletManager.h
//  shooting
//
//  Created by LeeChungHee on 2014. 4. 5..
//
//

#ifndef __shooting__BulletManager__
#define __shooting__BulletManager__

#include "cocos2d.h"
USING_NS_CC;

class BulletManager :public CCLayer
{
private:
    CCSprite*      _bullet;
    CCNode*        _parent;
    
public:
    BulletManager(CCNode* parent);
    ~BulletManager();
    
    void PlayerShootingBullet(const CCPoint& _position);
    void SpriteMoveFinished(CCNode* sender);
    
    
};





#endif /* defined(__shooting__BulletManager__) */
