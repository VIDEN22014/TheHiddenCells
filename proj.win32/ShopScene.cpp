#include "ShopScene.h"
#include <cocos/ui/UIButton.h>
#include <proj.win32/Game.h>
#include <cocos/audio/include/SimpleAudioEngine.h>

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
    //НАЛАШТУВАННЯ UI
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

    
  
   //встановлення значка хп
    auto heartExp = Sprite::create("Assets/Icons/04_heart/heart.png");
    heartExp->setScale(5.0);
    heartExp->setPosition(Vec2(280, 420));
    this->addChild(heartExp);
    //лінії що показує хп
    lineExp = Sprite::create("Assets/UI/lineExp.png");
    lineExp->setPosition(Vec2(size.width / 2, 420));
    this->addChild(lineExp);

    //встановлення значка зброї
    auto weaponExp = Sprite::create("Assets/Weapons/weapon_regular_sword.png");
    weaponExp->setScale(4.0);
    weaponExp->setPosition(Vec2(280, 340));
    this->addChild(weaponExp);

    //встановлення спрайтів героя
    spriteStartHero = Sprite::create("Assets/NPC/Fantasy RPG NPCs - Individuel Frames/Knight - Standard/Knight_Idle_1.png");
    spriteStartHero->setPosition(Vec2(size.width / 2, 555));
    spriteStartHero->setScale(5.0);
    this->addChild(spriteStartHero);

    auto animationHero = Animation::create();
    animationHero->addSpriteFrameWithFile("Assets/NPC/Fantasy RPG NPCs - Individuel Frames/Knight - Standard/Knight_Idle_1.png");
    animationHero->addSpriteFrameWithFile("Assets/NPC/Fantasy RPG NPCs - Individuel Frames/Knight - Standard/Knight_Idle_2.png");
    animationHero->addSpriteFrameWithFile("Assets/NPC/Fantasy RPG NPCs - Individuel Frames/Knight - Standard/Knight_Idle_3.png");
    animationHero->addSpriteFrameWithFile("Assets/NPC/Fantasy RPG NPCs - Individuel Frames/Knight - Standard/Knight_Idle_4.png");
    animationHero->setDelayPerUnit(0.1111111112f);
    animationHero->setLoops(-1);
    spriteStartHero->runAction(Animate::create(animationHero));
    changeTextureHeroes(gameData::changeHero % 4);
    changeTexturelineExp(gameData::lvlHero[gameData::changeHero % 4]);


    //налаштування кнопок
    scroolrightButton->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
      switch (type)
      {
      case ui::Widget::TouchEventType::BEGAN:
            break;
      case ui::Widget::TouchEventType::ENDED:
          gameData::changeHero++;
          if(gameData::changeHero==-1){ gameData::changeHero =3;}
          changeTextureHeroes(abs(gameData::changeHero % 4));
          ShopScene::changeTexturelineExp(gameData::lvlHero[gameData::changeHero % 4]);
          //CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("SoundBlip.wav");
           break;
      default:
           break;
      }
    });
    this->addChild(scroolrightButton);

    scroolleftButton->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
        switch (type)
        {
        case ui::Widget::TouchEventType::BEGAN:
            break;
        case ui::Widget::TouchEventType::ENDED:
            gameData::changeHero--;
            if (gameData::changeHero == -1) { gameData::changeHero = 3; }
            changeTextureHeroes(abs(gameData::changeHero % 4));
            ShopScene::changeTexturelineExp(gameData::lvlHero[gameData::changeHero % 4]);
           // CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("SoundBlip.wav");
            break;
        default:
            break;
        }
        });
    this->addChild(scroolleftButton);

    auto returnButton = ui::Button::create("Assets/UI/StoneButtonsLight/tile005.png", "Assets/UI/StoneButtonsLightPressed/tile005.png");
    returnButton->setScale(5);
    returnButton->setAnchorPoint(Vec2(0, 0));
    returnButton->setPosition(Vec2(8 * returnButton->getScale(), 8 * returnButton->getScale()));
    returnButton->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
        switch (type)
        {
        case ui::Widget::TouchEventType::BEGAN:
            break;
        case ui::Widget::TouchEventType::ENDED:
            Game::GoToMainMenu();
            break;
        default:
            break;
        }
        });
    this->addChild(returnButton);

    auto plusButton = ui::Button::create("Assets/UI/plusButton.png", "Assets/UI/plusButtonPressed.png");
    plusButton->setScale(5);
    plusButton->setPosition(Vec2(680, 425));
    plusButton->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
        switch (type)
        {
        case ui::Widget::TouchEventType::BEGAN:
            break;
        case ui::Widget::TouchEventType::ENDED:
            if (gameData::lvlHero[gameData::changeHero % 4] < 7) {
                gameData::lvlHero[gameData::changeHero % 4]++;
                ShopScene::changeTexturelineExp(gameData::lvlHero[gameData::changeHero % 4]);
            }
            break;
        default:
            break;
        }
        });
    this->addChild(plusButton);
    return true;

}
void ShopScene::changeTexturelineExp(int index) {
    if (index == 0) { lineExp->setTexture("Assets/UI/lineExp.png"); }
    if (index == 1) { lineExp->setTexture("Assets/UI/lineExp1.png"); }
    else if(index==2){ lineExp->setTexture("Assets/UI/lineExp2.png"); }
    else if (index == 3) { lineExp->setTexture("Assets/UI/lineExp3.png"); }
    else if (index == 4) { lineExp->setTexture("Assets/UI/lineExp4.png"); }
    else if (index == 5) { lineExp->setTexture("Assets/UI/lineExp5.png"); }
    else if (index == 6) { lineExp->setTexture("Assets/UI/lineExp6.png"); }
}

void ShopScene::changeTextureHeroes(int index) {
    if (index == 0) {
      
       spriteStartHero->stopAllActions();
        spriteStartHero->setTexture("Assets/NPC/Fantasy RPG NPCs - Individuel Frames/Knight - Standard/Knight_Idle_1.png");

        auto animationHero = Animation::create();
       animationHero->addSpriteFrameWithFile("Assets/NPC/Fantasy RPG NPCs - Individuel Frames/Knight - Standard/Knight_Idle_1.png");
        animationHero->addSpriteFrameWithFile("Assets/NPC/Fantasy RPG NPCs - Individuel Frames/Knight - Standard/Knight_Idle_2.png");
        animationHero->addSpriteFrameWithFile("Assets/NPC/Fantasy RPG NPCs - Individuel Frames/Knight - Standard/Knight_Idle_3.png");
        animationHero->addSpriteFrameWithFile("Assets/NPC/Fantasy RPG NPCs - Individuel Frames/Knight - Standard/Knight_Idle_4.png");
        animationHero->setDelayPerUnit(0.1111111112f);
        animationHero->setLoops(-1);

        spriteStartHero->runAction(Animate::create(animationHero));
    }
    else if (index == 1) {
        spriteStartHero->stopAllActions();
        spriteStartHero->setTexture("Assets/NPC/Fantasy RPG NPCs - Individuel Frames/Large Knight - Standard/LargeKnight_Idle_1.png");

        auto animationHero = Animation::create();
       animationHero->addSpriteFrameWithFile("Assets/NPC/Fantasy RPG NPCs - Individuel Frames/Large Knight - Standard/LargeKnight_Idle_1.png");
        animationHero->addSpriteFrameWithFile("Assets/NPC/Fantasy RPG NPCs - Individuel Frames/Large Knight - Standard/LargeKnight_Idle_2.png");
        animationHero->addSpriteFrameWithFile("Assets/NPC/Fantasy RPG NPCs - Individuel Frames/Large Knight - Standard/LargeKnight_Idle_3.png");
        animationHero->addSpriteFrameWithFile("Assets/NPC/Fantasy RPG NPCs - Individuel Frames/Large Knight - Standard/LargeKnight_Idle_4.png");
        animationHero->setDelayPerUnit(0.1111111112f);
        animationHero->setLoops(-1);

        spriteStartHero->runAction(Animate::create(animationHero));
    }
    else if (index == 2) {
        spriteStartHero->stopAllActions();
        spriteStartHero->setTexture("Assets/NPC/Fantasy RPG NPCs - Individuel Frames/Mage/Mage_Idle_1.png");

        auto animationHero = Animation::create();
        animationHero->addSpriteFrameWithFile("Assets/NPC/Fantasy RPG NPCs - Individuel Frames/Mage/Mage_Idle_1.png");
        animationHero->addSpriteFrameWithFile("Assets/NPC/Fantasy RPG NPCs - Individuel Frames/Mage/Mage_Idle_2.png");
        animationHero->addSpriteFrameWithFile("Assets/NPC/Fantasy RPG NPCs - Individuel Frames/Mage/Mage_Idle_3.png");
        animationHero->addSpriteFrameWithFile("Assets/NPC/Fantasy RPG NPCs - Individuel Frames/Mage/Mage_Idle_4.png");
        animationHero->setDelayPerUnit(0.1111111112f);
        animationHero->setLoops(-1);

        spriteStartHero->runAction(Animate::create(animationHero));
    }
    else if (index == 3) {
        spriteStartHero->stopAllActions();
        spriteStartHero->setTexture("Assets/NPC/Fantasy RPG NPCs - Individuel Frames/Thief/Thief_Idle_1.png");

        auto animationHero = Animation::create();
        animationHero->addSpriteFrameWithFile("Assets/NPC/Fantasy RPG NPCs - Individuel Frames/Thief/Thief_Idle_1.png");
        animationHero->addSpriteFrameWithFile("Assets/NPC/Fantasy RPG NPCs - Individuel Frames/Thief/Thief_Idle_2.png");
        animationHero->addSpriteFrameWithFile("Assets/NPC/Fantasy RPG NPCs - Individuel Frames/Thief/Thief_Idle_3.png");
        animationHero->addSpriteFrameWithFile("Assets/NPC/Fantasy RPG NPCs - Individuel Frames/Thief/Thief_Idle_4.png");
        animationHero->setDelayPerUnit(0.1111111112f);
        animationHero->setLoops(-1);

        spriteStartHero->runAction(Animate::create(animationHero));
    }

}

    
