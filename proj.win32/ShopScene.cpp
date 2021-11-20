#include "ShopScene.h"

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
  // this->scheduleUpdate();
}
void ShopScene::update(float dt) {}


