//
//  Player.h
//  shooting
//
//  Created by LeeChungHee on 2014. 3. 30..
//
//

#ifndef __shooting__Player__
#define __shooting__Player__

#include "cocos2d.h"
USING_NS_CC;

class Player
{
private:
    CCSprite*       _sprite;
    CCNode*         _parent;

public:
    Player(CCNode* parent);
    ~Player();
    
public:
    bool Init(const char* imageName, const CCPoint& startPosition);
    
public:
    void SetPosition(const CCPoint& pos);
    const CCPoint& GetPosition();
};

#endif /* defined(__shooting__Player__) */
