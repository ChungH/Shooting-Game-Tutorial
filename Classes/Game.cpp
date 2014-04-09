//
//  Game.cpp
//  shooting
//
//  Created by LeeChungHee on 2014. 3. 30..
//
//

#include "Game.h"
USING_NS_CC;

Game::Game()
{
    _player         =   NULL;
    _enemy          =   NULL;
    _background1    =   NULL;
    _background2    =   NULL;
    _bullet         =   NULL;
}
Game::~Game()
{
    
}

CCScene* Game::scene()
{
    CCScene *scene = CCScene::create();
    
    Game *layer = Game::create();
    
    scene -> addChild(layer);

    return scene;
}

bool Game::init()
{
    if(!CCLayerColor::initWithColor(ccc4(255,255,255,255)))
    {
        return false;
    }
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
    
    
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                                          "CloseNormal.png",
                                                          "CloseSelected.png",
                                                          this,
                                                          menu_selector(Game::menuCloseCallback));
    
	pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
                                origin.y + pCloseItem->getContentSize().height/2));
    
    // create menu, it's an autorelease object
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, 1);
    
    //코드추가
    _background1 = new CCSprite;
    _background2 = new CCSprite;
    if(!_background1->initWithFile("Back1.png") ||
       !_background2->initWithFile("Back2.png"))
    {
        delete _background1;
        delete _background2;
        return false;
    }
    _background1->setAnchorPoint(ccp(0,0));
    _background1->setPosition(ccp(0,0));
    this->addChild(_background1);
    
    _background2->setAnchorPoint(ccp(0,0));
    _background2->setPosition(ccp(0,_background1->getContentSize().height));
    this->addChild(_background2);
    
    _player =   new Player(this);
    _enemy  =   new Enemy(this);
    
    CCSize winSize = CCDirector::sharedDirector()->getWinSize();
    CCPoint centerInScreen(winSize.width/2, winSize.height/2);
    _player->Init("Player.png", centerInScreen);\

    this->setTouchEnabled(true);
    
    
    this->schedule(schedule_selector(Game::EnemyCreate),0.2f);
    this->schedule(schedule_selector(Game::BackUpdate));
    this->schedule(schedule_selector(Game::BulletCreate),0.1f);
    
    
    return true;
    
}



void Game::menuCloseCallback(CCObject* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
#else
    CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
#endif
    
}
void Game::ccTouchesBegan(CCSet *pTouches,CCEvent *pEvent)
{
    CCSetIterator touchiter;
    for(touchiter=pTouches->begin(); touchiter != pTouches->end(); ++touchiter)
    {
        const CCTouch* pTouch = (const CCTouch*)(*touchiter);
        CCPoint pos = pTouch->getLocation();

        _player->SetPosition(pos);
    }
}

void Game::ccTouchesMoved(CCSet *pTouches, CCEvent *pEvent)
{
    CCSetIterator touchiter;
    for(touchiter=pTouches->begin(); touchiter != pTouches->end(); ++touchiter)
    {
        const CCTouch* pTouch = (const CCTouch*)(*touchiter);
        CCPoint pos = pTouch->getLocation();

        _player->SetPosition(pos);
        
    }
    
}

void Game::EnemyCreate()
{
    _enemy->InitEnemy("Enemy.png");
}

void Game::BackUpdate()
{
    CCPoint p1 = _background1->getPosition();
    CCPoint p2 = _background2->getPosition();
    
    p1.y -= 2;
    p2.y -= 2;
    
    float height = _background1->getContentSize().height;
    
    if(p1.y <= -height)
    {
        p1.y = height;
    }
    else if(p2.y <= -height)
    {
        p2.y = height;
    }
    
    _background1->setPosition(p1);
    _background2->setPosition(p2);
    
}

void Game::BulletCreate()
{
    _bullet = new BulletManager(this);
    _bullet->PlayerShootingBullet(_player->GetPosition());
}
