//
//  Game.h
//  shooting
//
//  Created by LeeChungHee on 2014. 3. 30..
//
//

#ifndef __shooting__Game__
#define __shooting__Game__

#include "cocos2d.h"
#include "player.h"
#include "Enemy.h"
#include "BulletManager.h"
USING_NS_CC;

class Game : public cocos2d::CCLayerColor
{
private:
    Player*             _player;
    Enemy *             _enemy;
    BulletManager*      _bullet;
    
    
    CCSprite*           _background1;
    CCSprite*           _background2;
    
public:
    Game();
    ~Game();
    virtual bool init();
    
    static cocos2d::CCScene* scene();
    
    void menuCloseCallback(CCObject* pSender);

    virtual void ccTouchesBegan(CCSet *pTouches, CCEvent *pEvent);
    virtual void ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent);

    void BackUpdate();
    void EnemyCreate();
    void BulletCreate();
    CREATE_FUNC(Game);
};


#endif /* defined(__shooting__Game__) */
