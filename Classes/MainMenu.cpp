#include "MainMenu.h"
#include <cocos/ui/UIButton.h>
#include <proj.win32/GameScene.h>
#include <proj.win32/ShopScene.h>
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* MainMenu::createScene()
{
    return MainMenu::create();
}
bool playSound = true;
bool playMusic = true;
bool MainMenu::init()
{
    
    if ( !Scene::init() )
    {
        return false;
    }
   
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("SoundBlip.wav");
    CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("backgroundmusic.mp3");

  
   
    CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("backgroundmusic.mp3",true);
     CocosDenshion::SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(0.25f);

    auto spriteBack = Sprite::create("BG 4.png");
    Size size = Director::getInstance()->getWinSize();
    spriteBack->setPosition(Vec2(size.width/2, size.height/2));
    this->addChild(spriteBack);

  

   auto CoinSprite = Sprite::create("coin_01.png");
    CoinSprite->setPosition(Vec2(35, 900));//820 900
    spriteBack->setScale(3.3);
    this->addChild(CoinSprite);

    auto animation = Animation::create();
    animation->addSpriteFrameWithFile("coin_01.png");
    animation->addSpriteFrameWithFile("coin_02.png");
    animation->addSpriteFrameWithFile("coin_03.png");
    animation->addSpriteFrameWithFile("coin_04.png");
    animation->addSpriteFrameWithFile("coin_05.png");
    animation->addSpriteFrameWithFile("coin_06.png");
    animation->addSpriteFrameWithFile("coin_07.png");
    animation->addSpriteFrameWithFile("coin_08.png");
    animation->setDelayPerUnit(0.1111111112f);
    animation->setLoops(-1);

    auto action = Animate::create(animation);
    CoinSprite->runAction(action);
  
    auto CointLabel =  Label::createWithTTF("000" ,"DungeonFont.ttf" , 43);
    CointLabel->setPosition(Vec2(95, 900));
    this->addChild(CointLabel);

    auto spriteIcon = Sprite::create("iconForHero.png");
    spriteIcon->setPosition(Vec2(size.width / 2, 555));
    spriteIcon->setScale(5.0);
    this->addChild(spriteIcon);

    auto spriteStartHero = Sprite::create("StartHero1.png");
    spriteStartHero->setPosition(Vec2(size.width / 2, 555));
    spriteStartHero->setScale(5.0);
    this->addChild(spriteStartHero);

    auto animationHero = Animation::create();
    animationHero->addSpriteFrameWithFile("StartHero1.png");
    animationHero->addSpriteFrameWithFile("StartHero2.png");
    animationHero->addSpriteFrameWithFile("StartHero3.png");
    animationHero->addSpriteFrameWithFile("StartHero4.png");
    animationHero->setDelayPerUnit(0.1111111112f);
    animationHero->setLoops(-1);

    auto action2 = Animate::create(animationHero);
    spriteStartHero->runAction(action2);


    auto spriteKNIS = Sprite::create("knisback.png");
    spriteKNIS->setPosition(Vec2(825, 135));
    this->addChild(spriteKNIS);

    auto spriteKNISGerb = Sprite::create("knisGerb01.png");
    spriteKNISGerb->setPosition(Vec2(825, 135));
    this->addChild(spriteKNISGerb);

    auto animationGerb = Animation::create();
    animationGerb->addSpriteFrameWithFile("knisGerb02.png");
    animationGerb->addSpriteFrameWithFile("knisGerb03.png");
    animationGerb->addSpriteFrameWithFile("knisGerb04.png");
    animationGerb->addSpriteFrameWithFile("knisGerb05.png");
    animationGerb->addSpriteFrameWithFile("knisGerb06.png");
    animationGerb->addSpriteFrameWithFile("knisGerb07.png");
    animationGerb->addSpriteFrameWithFile("knisGerb08.png");
    animationGerb->addSpriteFrameWithFile("knisGerb09.png");
    animationGerb->addSpriteFrameWithFile("knisGerb10.png");
    animationGerb->addSpriteFrameWithFile("knisGerb11.png");
    animationGerb->addSpriteFrameWithFile("knisGerb12.png");
    animationGerb->setDelayPerUnit(0.322222222f);
    animationGerb->setLoops(-1);

    auto action3 = Animate::create(animationGerb);
    spriteKNISGerb->runAction(action3);

    auto playItemStart = ui::Button::create("startButton.png", "startButtonPressed.png");
    playItemStart->setAnchorPoint(Vec2(0, 0));
    playItemStart->setScale(4.5);
    playItemStart->setPosition(Vec2(440 , 375));
   
    playItemStart->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
        switch (type)
        {
        case ui::Widget::TouchEventType::BEGAN:
            break;
        case ui::Widget::TouchEventType::ENDED:
            if (playSound) {
                CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("SoundBlip.wav");
                CocosDenshion::SimpleAudioEngine::getInstance()->unloadEffect("SoundBlip.wav");
                CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic(); 
            }
            GoToGameScene(this);
            break;
        default:
            break;
        }
        });
    this->addChild(playItemStart);
    //
    auto playItemShop = ui::Button::create("shopButton.png", "shopButtonPressed.png");
    playItemShop->setAnchorPoint(Vec2(0, 0));
    playItemShop->setScale(4.5);
    playItemShop->setPosition(Vec2(440, 275));

    playItemShop->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
        switch (type)
        {
        case ui::Widget::TouchEventType::BEGAN:
            break;
        case ui::Widget::TouchEventType::ENDED:
            if (playSound) {
                CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("SoundBlip.wav");
            }
            GoToShopScene(this);
            break;
        default:
            break;
        }
        });
    this->addChild(playItemShop);
    //
    auto playItemExit = ui::Button::create("exitButton.png", "exitButtonPressed.png");
    playItemExit->setAnchorPoint(Vec2(0, 0));
    playItemExit->setScale(4.5);
    playItemExit->setPosition(Vec2(440, 175));

    playItemExit->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
        switch (type)
        {
        case ui::Widget::TouchEventType::BEGAN:

            break;
        case ui::Widget::TouchEventType::ENDED:
            if (playSound) {
                CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("SoundBlip.wav");
                 GoToExit(this);
            }
            break;
        default:
            break;
        }
        });
    this->addChild(playItemExit);
    //
   
    auto playItemSount = ui::Button::create("sountButton.png", "sountButtonPressed.png");
    playItemSount->setAnchorPoint(Vec2(0, 0));
    playItemSount->setScale(4.5);
    playItemSount->setPosition(Vec2(735, 855));
    this->addChild(playItemSount);
    playItemSount->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
        switch (type)
        {
        case ui::Widget::TouchEventType::BEGAN:
            break;
        case ui::Widget::TouchEventType::ENDED:
            playSound = true;
            CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("SoundBlip.wav");
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("SoundBlip.wav");
            break;
        default:
            break;
        }
     });
    //
    auto playItemEndSound = ui::Button::create("sountEndButton.png", "sountEndButtonPressed.png");
    playItemEndSound->setAnchorPoint(Vec2(0, 0));
    playItemEndSound->setScale(4.5);
    playItemEndSound->setPosition(Vec2(825, 855));
    this->addChild(playItemEndSound);
    playItemEndSound->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
        switch (type)
        {
        case ui::Widget::TouchEventType::BEGAN:
            break;
        case ui::Widget::TouchEventType::ENDED:
            CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("SoundBlip.wav");
            playSound = false;
            CocosDenshion::SimpleAudioEngine::getInstance()->unloadEffect("SoundBlip.wav");
            break;
        default:
            break;
        }
        });
  //
    auto playItemMusic = ui::Button::create("musicButton.png", "musicButtonPressed.png");
    playItemMusic->setAnchorPoint(Vec2(0, 0));
    playItemMusic->setScale(4.5);
    playItemMusic->setPosition(Vec2(735, 775));
    this->addChild(playItemMusic);
    playItemMusic->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
        switch (type)
        {
        case ui::Widget::TouchEventType::BEGAN:
            break;
        case ui::Widget::TouchEventType::ENDED:
            playMusic = true;
            if (playSound) {
               CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("SoundBlip.wav");
           }
            CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("backgroundmusic.mp3");
            CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("backgroundmusic.mp3", true);
            break;
        default:
            break;
        }
        });
    //
    auto playItemEndMusic = ui::Button::create("musicEndButton.png", "musicEndButtonPressed.png");
    playItemEndMusic->setAnchorPoint(Vec2(0, 0));
    playItemEndMusic->setScale(4.5);
    playItemEndMusic->setPosition(Vec2(825, 775));
    this->addChild(playItemEndMusic);
    playItemEndMusic->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
        switch (type)
        {
        case ui::Widget::TouchEventType::BEGAN:
            break;
        case ui::Widget::TouchEventType::ENDED:
            playMusic = false;
            if (playSound) {
                CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("SoundBlip.wav");
            }
            CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("backgroundmusic.mp3");
            CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic();
            break;
        default:
            break;
        }
        });
    //
    return true;
}

void MainMenu::GoToGameScene(Ref*sender) {
   // Director::getInstance()->end();
    auto scene = GameScene::createScene();
    Director::getInstance()->replaceScene(scene);
  
}


void MainMenu::GoToShopScene(Ref* pSender)
{
    auto scene = ShopScene::createScene();
    Director::getInstance()->replaceScene(TransitionSlideInT::create(0.5, scene));
}
void MainMenu::GoToExit(Ref* sender) {

    CCDirector::sharedDirector()->end();

}
