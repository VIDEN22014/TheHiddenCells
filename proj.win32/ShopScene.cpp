#include "ShopScene.h"
#include <cocos/ui/UIButton.h>
#include <proj.win32/Game.h>
#include <cocos/audio/include/SimpleAudioEngine.h>


USING_NS_CC;

Scene* ShopScene::createScene()
{
    return ShopScene::create();
}
ui::Button* lockHero;
cocos2d::Sprite*weaponExp;
cocos2d::Label* priceHero;
cocos2d::Label* LabelpriceHeart;
cocos2d::Label* LabelpriceAmmo;
cocos2d::Label* CoinLabel;
cocos2d::Label* InfoLabel;
cocos2d::Sprite* minixp;
cocos2d::Sprite* miniammo;
cocos2d::Label* LabelAmountXP;
cocos2d::Label* LabelAmountAmmo;

bool ShopScene::init()
{

    if (!Scene::init())
    {
        return false;
    }
    //НАЛАШТУВАННЯ UI
    auto sprite = Sprite::create("Assets/Backgrounds/BG 4.png");
    Size size = Director::getInstance()->getWinSize();
    sprite->setPosition(Vec2(size.width / 2, size.height / 2));
    this->addChild(sprite);


    auto spriteIcon = Sprite::create("Assets/Icons/iconForHero.png");
    spriteIcon->setPosition(Vec2(size.width / 2, 550));
    spriteIcon->setScale(5.0);
    this->addChild(spriteIcon);

    auto scroolrightButton = ui::Button::create("Assets/UI/Test-Button/scrollRightButton.png", "Assets/UI/Test-Button/scrollRightButtonPressed.png");
    scroolrightButton->setAnchorPoint(Vec2(0, 0));
    scroolrightButton->setScale(4.5);
    scroolrightButton->setPosition(Vec2(580, 520));


    auto scroolleftButton = ui::Button::create("Assets/UI/Test-Button/scrollLeftButton.png", "Assets/UI/Test-Button/scrollLeftButtonPressed.png");
    scroolleftButton->setAnchorPoint(Vec2(0, 0));
    scroolleftButton->setScale(4.5);
    scroolleftButton->setPosition(Vec2(305, 520));



    //встановлення значка хп
    auto heartExp = Sprite::create("Assets/Icons/04_heart/heart.png");
    heartExp->setScale(5.0);
    heartExp->setPosition(Vec2(280, 420));
    this->addChild(heartExp);

    //лінії що показує хп
    lineExpXP = Sprite::create("Assets/UI/lineExp.png");
    lineExpXP->setPosition(Vec2(size.width / 2, 420));
    this->addChild(lineExpXP);

    //встановлення значка зброї
    weaponExp = Sprite::create("Assets/Weapons/weapon_regular_sword.png");
    weaponExp->setScale(4.0);
    weaponExp->setPosition(Vec2(280, 340));
    this->addChild(weaponExp);
    //лінії що показує прокачку зброї

    lineExpAmmo = Sprite::create("Assets/UI/lineExp.png");
    lineExpAmmo->setPosition(Vec2(size.width / 2, 340));
    this->addChild(lineExpAmmo);


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


    auto CoinSprite = Sprite::create("Assets/Icons/Coins_0/coin_01.png");
    CoinSprite->setPosition(Vec2(0 + CoinSprite->getContentSize().width, 960 - CoinSprite->getContentSize().height));//820 900
    this->addChild(CoinSprite);

    auto animation = Animation::create();
    animation->addSpriteFrameWithFile("Assets/Icons/Coins_0/coin_01.png");
    animation->addSpriteFrameWithFile("Assets/Icons/Coins_0/coin_02.png");
    animation->addSpriteFrameWithFile("Assets/Icons/Coins_0/coin_03.png");
    animation->addSpriteFrameWithFile("Assets/Icons/Coins_0/coin_04.png");
    animation->addSpriteFrameWithFile("Assets/Icons/Coins_0/coin_05.png");
    animation->addSpriteFrameWithFile("Assets/Icons/Coins_0/coin_06.png");
    animation->addSpriteFrameWithFile("Assets/Icons/Coins_0/coin_07.png");
    animation->addSpriteFrameWithFile("Assets/Icons/Coins_0/coin_08.png");
    animation->setDelayPerUnit(0.1111111112f);
    animation->setLoops(-1);
    CoinSprite->runAction(Animate::create(animation));

    //label кілкьість монеток
    CoinLabel = Label::createWithTTF(std::to_string(gameData::money), "Fonts/DungeonFont.ttf", 42);
    CoinLabel->setAnchorPoint(Vec2(0, 0.5));
    CoinLabel->setPosition(Vec2(CoinSprite->getPositionX() + CoinSprite->getContentSize().width, CoinSprite->getPositionY()));
    this->addChild(CoinLabel);

    //label недовстатньо монеток для покупки
    InfoLabel = Label::createWithTTF("not enough coins!", "DungeonFont.ttf", 42);
    InfoLabel->setColor(Color3B::RED);
    InfoLabel->setAnchorPoint(Vec2(0, 0.5));
    InfoLabel->setPosition(550, 700);
    this->addChild(InfoLabel);
    InfoLabel->setVisible(false);

    //встановлення іконки хп на іконку героя
    minixp = Sprite::create("Assets/Icons/04_heart/heart.png");
    minixp->setScale(1.7);
    minixp->setPosition(420, 615);
    this->addChild(minixp);
    //встановлення іконки зброї на іконку героя
    miniammo = Sprite::create("Assets/Weapons/weapon_regular_sword.png");
    miniammo->setScale(2.0);
    miniammo->setPosition(520, 610);
    this->addChild(miniammo);

    //встановлення лейбла к-сті хп
    LabelAmountXP = Label::create("", "Fonts/DungeonFont.ttf", 18);
    LabelAmountXP->setAnchorPoint(Vec2(0, 0.5));
    LabelAmountXP->setPosition(435, 615);
    this->addChild(LabelAmountXP);
    // встановлення лейбла к-сті хп зброї(урону)
    LabelAmountAmmo = Label::create("", "Fonts/DungeonFont.ttf", 18);
    LabelAmountAmmo->setAnchorPoint(Vec2(0, 0.5));
    LabelAmountAmmo->setPosition(535, 610);
    this->addChild(LabelAmountAmmo);

    //налаштування кнопок
    scroolrightButton->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
        switch (type)
        {
        case ui::Widget::TouchEventType::BEGAN:
            break;
        case ui::Widget::TouchEventType::ENDED:
            InfoLabel->setVisible(false);
            gameData::changeHero++;
            if (gameData::changeHero == -1) { gameData::changeHero = 3; }
            changeTextureHeroes(abs(gameData::changeHero % 4),false);
            changeTexturelineExp(gameData::lvlHeart[gameData::changeHero % 4],0);
            changeTexturelineExp(gameData::lvlAmmo[gameData::changeHero % 4], 1);
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
            InfoLabel->setVisible(false);
            gameData::changeHero--;
            if (gameData::changeHero == -1) { gameData::changeHero = 3; }
            changeTextureHeroes(abs(gameData::changeHero % 4),false);
           
            changeTexturelineExp(gameData::lvlHeart[gameData::changeHero % 4],0);
          changeTexturelineExp(gameData::lvlAmmo[gameData::changeHero % 4], 1);
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
           // whichHeroBuy();
            break;
        case ui::Widget::TouchEventType::ENDED:
            Game::GoToMainMenu();
            break;
        default:
            break;
        }
        });
    this->addChild(returnButton);

    auto plusButtonXP = ui::Button::create("Assets/UI/plusButton.png", "Assets/UI/plusButtonPressed.png");
    plusButtonXP->setScale(5);
    plusButtonXP->setPosition(Vec2(680, 425));
    plusButtonXP->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
        switch (type)
        {
        case ui::Widget::TouchEventType::BEGAN:
            break;
        case ui::Widget::TouchEventType::ENDED:
            if (gameData::lockHero[gameData::changeHero % 4]&& gameData::money >= gameData::priceHeart) {
                if (gameData::lvlHeart[gameData::changeHero % 4] < 7) {
                    gameData::lvlHeart[gameData::changeHero % 4]++;
                    changeTexturelineExp(gameData::lvlHeart[gameData::changeHero % 4], 0);
                
                    Game::MoneyChange(-gameData::priceHeart, CoinLabel);
                    gameData::priceHeart += 20;
                    LabelpriceHeart->setString(std::to_string(gameData::priceHeart));
                    //Game::MoneyChange(20, LabelpriceHeart);
                }
            }
            break;
        default:
            break;
        }
        });
    this->addChild(plusButtonXP);

    auto plusButtonAmmo = ui::Button::create("Assets/UI/plusButton.png", "Assets/UI/plusButtonPressed.png");
    plusButtonAmmo->setScale(5);
    plusButtonAmmo->setPosition(Vec2(680, 330));
    plusButtonAmmo->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
        switch (type)
        {
        case ui::Widget::TouchEventType::BEGAN:
            break;
        case ui::Widget::TouchEventType::ENDED:
            if (gameData::lockHero[gameData::changeHero % 4]) {
                if (gameData::lvlAmmo[gameData::changeHero % 4] < 7&& gameData::money >= gameData::priceAmmo) {
                    gameData::lvlAmmo[gameData::changeHero % 4]++;
                    ShopScene::changeTexturelineExp(gameData::lvlAmmo[gameData::changeHero % 4], 1);
                
                    Game::MoneyChange(-gameData::priceAmmo, CoinLabel);
                    gameData::priceAmmo += 20;
                    LabelpriceAmmo->setString(std::to_string(gameData::priceAmmo));
                    //  Game::MoneyChange(20, LabelpriceAmmo);
                }
            }
            break;
        default:
            break;
        }
        });
    this->addChild(plusButtonAmmo);

    lockHero= ui::Button::create("Assets/UI/lockButton.png", "Assets/UI/lockButtonPressed.png");
    lockHero->setScale(5);
    lockHero->setPosition(Vec2(485, 555));
    lockHero->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
        switch (type)
        {
        case ui::Widget::TouchEventType::BEGAN:
            break;
        case ui::Widget::TouchEventType::ENDED:
            if (gameData::money>=abs( gameData::priceHero[gameData::changeHero % 4])) {
                gameData::lockHero[gameData::changeHero % 4] = true;
                lockHero->setVisible(false);
                changeTextureHeroes(gameData::changeHero % 4,true);
                Game::MoneyChange(gameData::priceHero[gameData::changeHero % 4], CoinLabel);
            }
            else { InfoLabel->setVisible(true); }
            break;
        default:
            break;
        }
        });
   
    this->addChild(lockHero);

    //label ціна героїв
    priceHero = Label::create("", "Fonts/DungeonFont.ttf", 42);
    priceHero->setPosition(480, 700);
    this->addChild(priceHero);

    //label ціна хп
    LabelpriceHeart= Label::create(std::to_string(gameData::priceHeart), "Fonts/DungeonFont.ttf", 42);
    LabelpriceHeart->setPosition(750, 430);
    this->addChild(LabelpriceHeart);
    //label ціна зброї
    LabelpriceAmmo = Label::create(std::to_string(gameData::priceAmmo), "Fonts/DungeonFont.ttf", 42);
    LabelpriceAmmo->setPosition(750, 330);
    this->addChild(LabelpriceAmmo);

    changeTextureHeroes(gameData::changeHero % 4,false);
    changeTexturelineExp(gameData::lvlHeart[gameData::changeHero % 4], 0);
    changeTexturelineExp(gameData::lvlAmmo[gameData::changeHero % 4], 1);



    return true;

}

void ShopScene::changeTexturelineExp(int index,int sprite) {
    if (sprite == 0) {
        if (index == 0) { lineExpXP->setTexture("Assets/UI/lineExp.png"); }
        if (index == 1) { lineExpXP->setTexture("Assets/UI/lineExp1.png"); }
        else if (index == 2) { lineExpXP->setTexture("Assets/UI/lineExp2.png"); }
        else if (index == 3) { lineExpXP->setTexture("Assets/UI/lineExp3.png"); }
        else if (index == 4) { lineExpXP->setTexture("Assets/UI/lineExp4.png"); }
        else if (index == 5) { lineExpXP->setTexture("Assets/UI/lineExp5.png"); }
        else if (index == 6) { lineExpXP->setTexture("Assets/UI/lineExp6.png"); }
    }
    else if (sprite == 1) {
        if (index == 0) { lineExpAmmo->setTexture("Assets/UI/lineExp.png"); }
        if (index == 1) { lineExpAmmo->setTexture("Assets/UI/lineExp1.png"); }
        else if (index == 2) { lineExpAmmo->setTexture("Assets/UI/lineExp2.png"); }
        else if (index == 3) { lineExpAmmo->setTexture("Assets/UI/lineExp3.png"); }
        else if (index == 4) { lineExpAmmo->setTexture("Assets/UI/lineExp4.png"); }
        else if (index == 5) { lineExpAmmo->setTexture("Assets/UI/lineExp5.png"); }
        else if (index == 6) { lineExpAmmo->setTexture("Assets/UI/lineExp6.png"); }
    }
}

void ShopScene::changeTextureHeroes(int index,bool ThisHeroBuy) {
  if (index == 0) {
      weaponExp->setTexture("Assets/Weapons/weapon_regular_sword.png");
      miniammo->setTexture("Assets/Weapons/weapon_regular_sword.png");
      LabelAmountXP->setString(std::to_string(gameData::amountXPHeros[0]));
      LabelAmountAmmo->setString(std::to_string(gameData::amountAmmoHeros[0]));
      if (!gameData::lockHero[index]) {
          lockHero->setVisible(true);

      }
       else if (gameData::lockHero[index]){
          lockHero->setVisible(false);
          if (ThisHeroBuy) { gameData::lastBuyHero = 0; }
        }
      
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
      weaponExp->setTexture("Assets/Weapons/weapon_hammer.png");
      miniammo->setTexture("Assets/Weapons/weapon_hammer.png");
      LabelAmountXP->setString(std::to_string(gameData::amountXPHeros[1]));
      LabelAmountAmmo->setString(std::to_string(gameData::amountAmmoHeros[1]));
      if (!gameData::lockHero[index]) {
          lockHero->setVisible(true);
          priceHero->setString("150");
      }
      else if(gameData::lockHero[index]) {
          if (ThisHeroBuy ) { gameData::lastBuyHero = 1; }
          lockHero->setVisible(false);
          priceHero->setString("");

      }
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
      weaponExp->setTexture("Assets/Weapons/weapon_red_magic_staff.png");
      miniammo->setTexture("Assets/Weapons/weapon_red_magic_staff.png");
      miniammo->setScale(1.5);
      LabelAmountXP->setString(std::to_string(gameData::amountXPHeros[2]));
      LabelAmountAmmo->setString(std::to_string(gameData::amountAmmoHeros[2]));
      if (!gameData::lockHero[index]) {
          lockHero->setVisible(true);
          priceHero->setString("300");
      }
      else if (gameData::lockHero[index]) {
          if (ThisHeroBuy ) { gameData::lastBuyHero = 2; }
          lockHero->setVisible(false);
          priceHero->setString("");
      }
          
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
      weaponExp->setTexture("Assets/Weapons/weapon_golden_sword.png");
      miniammo->setTexture("Assets/Weapons/weapon_golden_sword.png");
      LabelAmountXP->setString(std::to_string(gameData::amountXPHeros[3]));
      LabelAmountAmmo->setString(std::to_string(gameData::amountAmmoHeros[3]));
      if (!gameData::lockHero[index]) {
          lockHero->setVisible(true);
          priceHero->setString("350");
      }
      else if (gameData::lockHero[index] ) {
          if (ThisHeroBuy) { gameData::lastBuyHero = 3; }
          lockHero->setVisible(false);
          priceHero->setString("");
      }
       
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


