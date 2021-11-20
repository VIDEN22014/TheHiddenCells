#include "GameScene.h"

USING_NS_CC;

Scene* GameScene::createScene()
{
    return GameScene::create();
}

bool GameScene::init()
{

    if (!Scene::init())
    {
        return false;
    }
    size = Director::getInstance()->getWinSize();

    auto spriteBack = Sprite::create("backLvl1.png");
    Size size = Director::getInstance()->getWinSize();
    spriteBack->setPosition(Vec2(size.width / 2, size.height / 2));
    this->addChild(spriteBack);

    spriteRiver = Sprite::create("riverGreen.png");
    spriteRiver->setPosition(Vec2(size.width / 2, 85));
    spriteRiver->setScale(1);
    this->addChild(spriteRiver);
 
   // this->scheduleUpdate();
}
void GameScene::update(float dt) {
 //   Point p = spriteRiver->getPosition();
   // spriteRiver->setPosition(Vec2(p.x + 3, p.y));
   /* if ((spriteRiver->getPositionX() - spriteRiver->getContentSize().width / 2) > size.width)
    {
        spriteRiver->setPosition(Vec2(0.0 - spriteRiver->getContentSize().width / 2, spriteRiver->getPositionY()));
    }*/

}

