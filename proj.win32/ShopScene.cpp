#include "ShopScene.h"
#include <cocos/ui/UIButton.h>

USING_NS_CC;

Scene* ShopScene::createScene()
{
    return ShopScene::create();
}

bool ShopScene::init()
{

    if (!Scene::init())
    {
        return false;
    }

    auto sprite = Sprite::create("BG 4.png");
    Size size = Director::getInstance()->getWinSize();
    sprite->setPosition(Vec2(size.width / 2, size.height / 2));
    this->addChild(sprite);


    auto spriteIcon = Sprite::create("iconForHero.png");
    spriteIcon->setPosition(Vec2(size.width / 2, 550));
    spriteIcon->setScale(5.0);
    this->addChild(spriteIcon);

    auto scroolrightButton = ui::Button::create("scrollRightButton.png", "scrollRightButtonPressed.png");
    scroolrightButton->setAnchorPoint(Vec2(0, 0));
    scroolrightButton->setScale(4.5);
    scroolrightButton->setPosition(Vec2(580, 520));


    auto scroolleftButton = ui::Button::create("scrollLeftButton.png", "scrollLeftButtonPressed.png");
    scroolleftButton->setAnchorPoint(Vec2(0, 0));
    scroolleftButton->setScale(4.5);
    scroolleftButton->setPosition(Vec2(305, 520));
    this->addChild(scroolleftButton);

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

    spriteStartHero->runAction(Animate::create(animationHero));

   // scroolrightButton->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
     //  switch (type)
     //  {
    //    case ui::Widget::TouchEventType::BEGAN:
      ///      break;
     //   case ui::Widget::TouchEventType::ENDED:
 
               //CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("SoundBlip.wav");

          // GoToGameScene(this);
       //    break;
      //  default:
      //     break;
  //  }
   // });
    this->addChild(scroolrightButton);

    return true;

}

    
