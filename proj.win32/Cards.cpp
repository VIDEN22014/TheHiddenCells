#include "cocos2d.h"
#include <proj.win32/Cards.h>
#include <proj.win32/Game.h>
#include <proj.win32/GameData.h>
#include <proj.win32/GeneratorCard.h>



int Card::cardInteract(Card* cards[3][3]) {
	return 1;
}

void Card::cardOnTurn(Card* cards[3][3]) {
	this->labelUpdate(false);
	if (cardBuff == 1)//Regen
	{
		if (cardCurrentHP >= cardMaxHP)
		{
			cardBuff == 0;//None
		}
		else
		{
			cardCurrentHP++;
		}
	}
	if (cardBuff == 2)//Poisoned
	{
		if (cardCurrentHP <= 1)
		{
			cardBuff == 0;//None
		}
		else
		{
			cardCurrentHP--;
		}
	}
}

void Card::deleteCard() {
	if (spriteFrame != nullptr) { spriteFrame->removeFromParent(); }
	if (spriteCard != nullptr) { spriteCard->removeFromParent(); }
	if (labelCard != nullptr) { labelCard->removeFromParent(); }
}

void Card::openTreasure(std::string typeChest) {
	if (typeChest == "good") {
		this->spriteCard->setTexture("Assets/Items/Chests/Chest_Gold/chest_gold_empty_open_anim/chest_empty_open_anim_f2.png");
	}
	else if (typeChest == "bad") {
		this->spriteCard->setTexture("Assets/Items/Chests/Chest_Gold/chest_gold_empty_open_anim/chest_empty_open_anim_f2(bad).png");
	}
}
void Card::lockScene() {
	gameData::isSceneLocked = true;
}
void Card::unlockScene() {
	gameData::isSceneLocked = false;
}

void Card::labelUpdate(bool isHeroLabel) {
	if (isHeroLabel)
	{
		labelCard->setString(std::to_string(cardCurrentHP) + "/" + std::to_string(cardMaxHP));
		if (gameData::isHeroArmed)
		{
			labelWeapon->setString(std::to_string(weapon->cardCurrentHP));
		}
		return;
	}
	labelCard->setString(std::to_string(cardCurrentHP));
}

void Card::weaponEffect(Card* cards[3][3], Card* enemy) {}

int CardCoin::cardInteract(Card* cards[3][3]) {
	Game::MoneyChange(cardCurrentHP, gameData::currentMoneyLabel);
	gameData::tempMoney += cardCurrentHP;

	return 1;
}

void CardHero::cardOnTurn(Card* cards[3][3]) {
	this->labelUpdate(true);
	if (cardCurrentHP > cardMaxHP)//Overheal Decreases
	{
		cardCurrentHP--;
	}
	if (cardBuff == 1)//Regen
	{
		if (cardCurrentHP >= cardMaxHP)
		{
			cardBuff == 0;//None
		}
		else
		{
			cardCurrentHP++;
		}
	}
	if (cardBuff == 2)//Poisoned
	{
		if (cardCurrentHP <= 1)
		{
			cardBuff == 0;//None
		}
		else
		{
			cardCurrentHP--;
		}
	}
}

//Potion Cards
int CardPotion::cardInteract(Card* cards[3][3]) {
	if (cards[gameData::heroPosition.x][gameData::heroPosition.y]->cardBuff == 2)//Canel Poision
	{
		cards[gameData::heroPosition.x][gameData::heroPosition.y]->cardBuff = 0;
	}
	return 1;
}

int CardRedPotion::cardInteract(Card* cards[3][3]) {
	this->CardPotion::cardInteract(cards);
	if (cards[gameData::heroPosition.x][gameData::heroPosition.y]->cardCurrentHP < cards[gameData::heroPosition.x][gameData::heroPosition.y]->cardMaxHP)
	{
		cards[gameData::heroPosition.x][gameData::heroPosition.y]->cardCurrentHP += cardCurrentHP;
		if (cards[gameData::heroPosition.x][gameData::heroPosition.y]->cardCurrentHP > cards[gameData::heroPosition.x][gameData::heroPosition.y]->cardMaxHP)
		{
			cards[gameData::heroPosition.x][gameData::heroPosition.y]->cardCurrentHP = cards[gameData::heroPosition.x][gameData::heroPosition.y]->cardMaxHP;
		}
	}
	return 1;
}

int CardGreenPotion::cardInteract(Card* cards[3][3]) {
	cards[gameData::heroPosition.x][gameData::heroPosition.y]->cardCurrentHP--;
	cards[gameData::heroPosition.x][gameData::heroPosition.y]->cardBuff = 2;//Grants Poison Debuff
	return 1;
}

int CardBluePotion::cardInteract(Card* cards[3][3]) {
	this->CardPotion::cardInteract(cards);
	cards[gameData::heroPosition.x][gameData::heroPosition.y]->cardBuff = 1;//Regen
	return 1;
}

int CardYellowPotion::cardInteract(Card* cards[3][3]) {
	this->CardPotion::cardInteract(cards);
	cards[gameData::heroPosition.x][gameData::heroPosition.y]->cardCurrentHP += cardCurrentHP;//Grants Overheal
	return 1;
}

//Weapon Cards
int CardWeapon::cardInteract(Card* cards[3][3]) {
	//Give Weapon To Hero Card
	if (!gameData::isHeroArmed || (gameData::isHeroArmed && this->cardCurrentHP > cards[gameData::heroPosition.x][gameData::heroPosition.y]->weapon->cardCurrentHP))
	{
		if (gameData::isHeroArmed)
		{
			gameData::isHeroArmed = false;
			//Weapon Delete
			gameData::currentScene->removeChild(cards[gameData::heroPosition.x][gameData::heroPosition.y]->spriteWeapon, true);
			gameData::currentScene->removeChild(cards[gameData::heroPosition.x][gameData::heroPosition.y]->labelWeapon, true);
		}
		gameData::isHeroArmed = true;
		cards[gameData::heroPosition.x][gameData::heroPosition.y]->weapon = new CardWeapon(*this);
		auto sprite = cocos2d::Sprite::create("Assets/Weapons/weapon_regular_sword.png");
		sprite->setTexture(this->spriteCard->getTexture());
		sprite->setScale(0.5);
		sprite->setAnchorPoint(Vec2(0, 0.5));
		sprite->setPosition(Vec2(cards[gameData::heroPosition.x][gameData::heroPosition.y]->spriteCard->getPosition().x - 192 / 2.0 + 16,
			cards[gameData::heroPosition.x][gameData::heroPosition.y]->spriteCard->getPosition().y));
		cards[gameData::heroPosition.x][gameData::heroPosition.y]->spriteWeapon = sprite;
		gameData::currentScene->addChild(sprite, 4);

		auto label = Label::create(std::to_string(cardCurrentHP), "Fonts/DungeonFont.ttf", gameData::fontSize - 6);
		label->setAnchorPoint(Vec2(0, 0));
		label->setPosition(Vec2(cards[gameData::heroPosition.x][gameData::heroPosition.y]->spriteCard->getPosition().x - 192 / 2.0 + 16,
			cards[gameData::heroPosition.x][gameData::heroPosition.y]->spriteCard->getPosition().y - 192 / 2.0 + 16));
		label->setColor(Color3B::BLUE);

		cards[gameData::heroPosition.x][gameData::heroPosition.y]->labelWeapon = label;
		gameData::currentScene->addChild(label, 4);
	}
	return 1;
}

void CardWeapon::weaponEffect(Card* cards[3][3], Card* enemy) {
	int min = std::min(cardCurrentHP, enemy->cardCurrentHP);
	enemy->cardCurrentHP -= min;
	cardCurrentHP -= min;//Weapon Durability Decreases
	//If weapon Broken
	if (cardCurrentHP <= 0)
	{
		gameData::isHeroArmed = false;
		//Weapon Delete
		gameData::currentScene->removeChild(cards[gameData::heroPosition.x][gameData::heroPosition.y]->spriteWeapon, true);
		gameData::currentScene->removeChild(cards[gameData::heroPosition.x][gameData::heroPosition.y]->labelWeapon, true);
		//delete cards[gameData::heroPosition.x][gameData::heroPosition.y]->weapon;
	}
}

void CardHealingWeapon::weaponEffect(Card* cards[3][3], Card* enemy) {
	this->CardWeapon::weaponEffect(cards, enemy);
	cards[gameData::heroPosition.x][gameData::heroPosition.y]->cardCurrentHP += std::min(cardCurrentHP, enemy->cardCurrentHP);
	if (cards[gameData::heroPosition.x][gameData::heroPosition.y]->cardCurrentHP > cards[gameData::heroPosition.x][gameData::heroPosition.y]->cardMaxHP)
	{
		cards[gameData::heroPosition.x][gameData::heroPosition.y]->cardCurrentHP = cards[gameData::heroPosition.x][gameData::heroPosition.y]->cardMaxHP;
	}
}

void CardPoisonedWeapon::weaponEffect(Card* cards[3][3], Card* enemy) {
	this->CardWeapon::weaponEffect(cards, enemy);
	//Poisoned weapon code
}


//Treause Cards
int CardGoodTreasure::cardInteract(Card* cards[3][3]) {
	this->spriteCard->runAction(Sequence::create(CallFunc::create(std::bind(&Card::lockScene, this)), CallFunc::create(std::bind(&Card::openTreasure, this, "good")), DelayTime::create(0.75), CallFunc::create(std::bind(&Card::deleteCard, this)), CallFunc::create(std::bind(&Card::unlockScene, this)), /*DelayTime::create(2 * 0.75), CallFunc::create(std::bind(&Card::spawnCoin, this,cards)),*/ nullptr));
	cards[this->pos.x][this->pos.y] = new CardCoin(this->pos, "Assets/Icons/Coins_0/coin_01.png", "Assets/Cards/squareGoldenFrame.png", gameData::currentScene);
	return 0;
}
int CardBadTreasure::cardInteract(Card* cards[3][3]) {

	this->spriteCard->runAction(Sequence::create(CallFunc::create(std::bind(&Card::lockScene, this)), CallFunc::create(std::bind(&Card::openTreasure, this, "bad")), DelayTime::create(0.75), CallFunc::create(std::bind(&Card::deleteCard, this)), CallFunc::create(std::bind(&Card::unlockScene, this)), /*DelayTime::create(2 * 0.75), CallFunc::create(std::bind(&Card::spawnCoin, this,cards)),*/ nullptr));
	cards[this->pos.x][this->pos.y] = GeneratorCard(1, gameData::currentScene).GenerateBadCard(*(new position(this->pos.x, this->pos.y)));
	return 0;
}
int CardCommonMonster::cardInteract(Card* cards[3][3]) {
	if (gameData::isHeroArmed)
	{
		cards[gameData::heroPosition.x][gameData::heroPosition.y]->weapon->weaponEffect(cards, this);
	//	cards[gameData::heroPosition.x][gameData::heroPosition.y]->weapon->labelUpdate(false);
		if (this->cardCurrentHP <= 0) { return 1; }
		return 0;
	}
	else if (!gameData::isHeroArmed ) {
		if (cards[gameData::heroPosition.x][gameData::heroPosition.y]->cardCurrentHP > this->cardCurrentHP) {
			cards[gameData::heroPosition.x][gameData::heroPosition.y]->cardCurrentHP -= this->cardCurrentHP;
			cards[gameData::heroPosition.x][gameData::heroPosition.y]->labelUpdate(true);
		}
		else if (cards[gameData::heroPosition.x][gameData::heroPosition.y]->cardCurrentHP <= this->cardCurrentHP) {
			Game::GoToEndGame();
		}
	}
	return 1;
}
int CardRegenXPMonster::cardInteract(Card* cards[3][3]) {
	this->cardBuff = 1;
	if (gameData::isHeroArmed)
	{
		cards[gameData::heroPosition.x][gameData::heroPosition.y]->weapon->weaponEffect(cards, this);
		//	cards[gameData::heroPosition.x][gameData::heroPosition.y]->weapon->labelUpdate(false);
		if (this->cardCurrentHP <= 0) { return 1; }
		return 0;
	}
	else if (!gameData::isHeroArmed) {
		if (cards[gameData::heroPosition.x][gameData::heroPosition.y]->cardCurrentHP > this->cardCurrentHP) {
			cards[gameData::heroPosition.x][gameData::heroPosition.y]->cardCurrentHP -= this->cardCurrentHP;
			cards[gameData::heroPosition.x][gameData::heroPosition.y]->labelUpdate(true);
		}
		else if (cards[gameData::heroPosition.x][gameData::heroPosition.y]->cardCurrentHP <= this->cardCurrentHP) {
			Game::GoToEndGame();
		}
	}
	return 1;
}
int CardPoisonedMonster::cardInteract(Card* cards[3][3]) {
	cards[gameData::heroPosition.x][gameData::heroPosition.y]->cardBuff = 2;
	if (gameData::isHeroArmed)
	{
		cards[gameData::heroPosition.x][gameData::heroPosition.y]->weapon->weaponEffect(cards, this);
		//	cards[gameData::heroPosition.x][gameData::heroPosition.y]->weapon->labelUpdate(false);
		if (this->cardCurrentHP <= 0) { return 1; }
		return 0;
	}
	else if (!gameData::isHeroArmed) {
		if (cards[gameData::heroPosition.x][gameData::heroPosition.y]->cardCurrentHP > this->cardCurrentHP) {
			cards[gameData::heroPosition.x][gameData::heroPosition.y]->cardCurrentHP -= this->cardCurrentHP;
			cards[gameData::heroPosition.x][gameData::heroPosition.y]->labelUpdate(true);
		}
		else if (cards[gameData::heroPosition.x][gameData::heroPosition.y]->cardCurrentHP <= this->cardCurrentHP) {
			Game::GoToEndGame();
		}
	}
	return 1;
}
//організувати інтеракт таки самий як для звичайного монстра, але  робити запамятовування координат монстра і якщо в тому векторі є наш монстра то він генерить своє хп на +2 поки не буде максимальним