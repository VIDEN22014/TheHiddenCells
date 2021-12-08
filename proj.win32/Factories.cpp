#include <proj.win32/Factories.h>


Card* Level1Factory::createMonster(position pos, cocos2d::Scene* scene) {
	//std::string spriteCardPath = "Assets/Monsters/Enchanted Forest - Individual Frames/Gnoll - Brute/GnollBrute_Idle_1.png";
	int GeneraTeCard;

	GeneraTeCard = rand() % 700;
	if (GeneraTeCard >= 0 && GeneraTeCard < (100 - gameData::RatioBossMonster))
	{
		return new CardCommonMonster(pos,  gameData::pathToMonsters[0], spriteFramePath, scene,gameData::MonstersMaxXP[0]);
	}
	else if (GeneraTeCard >= (100 - gameData::RatioBossMonster) && GeneraTeCard < (200 - gameData::RatioBossMonster))
	{
		return new CardCommonMonster(pos, gameData::pathToMonsters[1], spriteFramePath, scene, gameData::MonstersMaxXP[1]);
	}
	else if (GeneraTeCard >= (200 - gameData::RatioBossMonster) && GeneraTeCard < (300 - gameData::RatioBossMonster))
	{
		return new CardCommonMonster(pos, gameData::pathToMonsters[2], spriteFramePath, scene, gameData::MonstersMaxXP[2]);
	}
	else if (GeneraTeCard >= (300 - gameData::RatioBossMonster) && GeneraTeCard < (400 - gameData::RatioBossMonster))
	{
		return new CardCommonMonster(pos, gameData::pathToMonsters[3], spriteFramePath, scene, gameData::MonstersMaxXP[3]);
	}
	else if (GeneraTeCard >= (400 - gameData::RatioBossMonster) && GeneraTeCard < (500 - gameData::RatioBossMonster))
	{
		return new CardCommonMonster(pos, gameData::pathToMonsters[4], spriteFramePath, scene, gameData::MonstersMaxXP[4]);
	}
	else if (GeneraTeCard >= (500 - gameData::RatioBossMonster) && GeneraTeCard < (600 - gameData::RatioBossMonster))
	{
		return new CardCommonMonster(pos, gameData::pathToMonsters[5], spriteFramePath, scene, gameData::MonstersMaxXP[5]);
	}
	else if (GeneraTeCard >= (600 - gameData::RatioBossMonster) && GeneraTeCard < (700 - gameData::RatioBossMonster))
	{
		return new CardCommonMonster(pos, gameData::pathToMonsters[6], spriteFramePath, scene, gameData::MonstersMaxXP[6]);
	}
	else if (gameData::currentLevel==1&& GeneraTeCard >= (700-gameData::RatioBossMonster))
	{
		return new CardRegenXPMonster(pos,"Assets/Monsters/Enchanted Forest - Individual Frames/Elven King/HighElf_M_Idle + Walk_1(Big).png", spriteFramePath, scene, gameData::MonstersMaxXP[7]);
	}
	else if (gameData::currentLevel == 2 && GeneraTeCard >= (700 - gameData::RatioBossMonster))
	{
		return new CardPoisonedMonster(pos, "Assets/Monsters/Enchanted Forest - Individual Frames/Wizard/Wizard_Idle + Walk_1(Big).png", spriteFramePath, scene, gameData::MonstersMaxXP[7]);
	}
	else if (gameData::currentLevel == 3 && GeneraTeCard >= (700 - gameData::RatioBossMonster))
	{
		int GeneraetBoss = rand() % 1;
		if (GeneraetBoss==0) {
			return new CardPoisonedMonster(pos, "Assets/Monsters/Enchanted Forest - Individual Frames/Wizard/Wizard_Idle + Walk_1(Big).png", spriteFramePath, scene, gameData::MonstersMaxXP[7]);

		}
		else {
			return new CardRegenXPMonster(pos, "Assets/Monsters/Enchanted Forest - Individual Frames/Elven King/HighElf_M_Idle + Walk_1(Big).png", spriteFramePath, scene, gameData::MonstersMaxXP[7]);
		}
    }
	
}
Card* Level1Factory::createPotion(position pos, cocos2d::Scene* scene) {
	int generateCard;
	std::string spriteCardPath;
	generateCard = rand() % 100;
	if (generateCard >= 0 && generateCard < 25)
	{
		spriteCardPath = "Assets/Items/Flasks/Flasks_Big/flask_big_red.png";
		return new CardRedPotion(pos, spriteCardPath, spriteFramePath, scene);
	}
	else if (generateCard >= 25 && generateCard < 50)
	{
		spriteCardPath = "Assets/Items/Flasks/Flasks_Small/flask_small_green.png";
		return new CardGreenPotion(pos, spriteCardPath, spriteFramePath, scene);
	}
	else if (generateCard >= 50 && generateCard < 75)
	{
		spriteCardPath = "Assets/Items/Flasks/Flasks_Small/flask_small_blue.png";
		return new CardBluePotion(pos, spriteCardPath, spriteFramePath, scene);
	}
	else if (generateCard >= 75 && generateCard < 100)
	{
		spriteCardPath = "Assets/Items/Flasks/Flasks_Small/flask_small_yellow.png";
		return new CardYellowPotion(pos, spriteCardPath, spriteFramePath, scene);
	}
}



Card* Level1Factory::createGoodTreasure(position pos, cocos2d::Scene* scene) {
	std::string spriteCardPath = "Assets/Items/Chests/Chest_Gold/chest_gold_empty_open_anim/chest_empty_open_anim_f1.png";

	return new CardGoodTreasure(pos, spriteCardPath, spriteFramePath, scene);
}
Card* Level1Factory::createBadTreasure(position pos, cocos2d::Scene* scene) {
	std::string spriteCardPath = "Assets/Items/Chests/Chest_Gold/chest_gold_empty_open_anim/chest_empty_open_anim_f1(bad).png";

	return new CardBadTreasure(pos, spriteCardPath, spriteFramePath, scene);
}
Card* AbstractFactory::createHero(position pos, cocos2d::Scene* scene) {
	std::string spriteCardPath;
	if (gameData::chosenHero % 4 == 0) {
		spriteCardPath = "Assets/NPC/Fantasy RPG NPCs - Individuel Frames/Knight - Standard /Knight_Idle_1(Big).png";
	}
	else if (gameData::chosenHero % 4 == 1 && gameData::lockHero[1]) {
		spriteCardPath = "Assets/NPC/Fantasy RPG NPCs - Individuel Frames/Knight - Elite/EliteKnight_Idle_1(Big).png";

	}
	else if (gameData::chosenHero % 4 == 2 && gameData::lockHero[2]) {
		spriteCardPath = "Assets/NPC/Fantasy RPG NPCs - Individuel Frames/Mage/Mage_Idle_1(Big).png";

	}
	else if (gameData::chosenHero % 4 == 3 && gameData::lockHero[3]) {
		spriteCardPath = "Assets/NPC/Fantasy RPG NPCs - Individuel Frames/Thief/Thief_Idle_1(Big).png";

	}
	if (gameData::lastBuyHero == 3) {
		spriteCardPath = "Assets/NPC/Fantasy RPG NPCs - Individuel Frames/Thief/Thief_Idle_1(Big).png";

	}
	else if (gameData::lastBuyHero == 2) {
		spriteCardPath = "Assets/NPC/Fantasy RPG NPCs - Individuel Frames/Mage/Mage_Idle_1(Big).png";

	}
	else if (gameData::lastBuyHero == 1) {
		spriteCardPath = "Assets/NPC/Fantasy RPG NPCs - Individuel Frames/Knight - Elite/EliteKnight_Idle_1(Big).png";

	}
	else if (gameData::lastBuyHero == 0) {
		spriteCardPath = "Assets/NPC/Fantasy RPG NPCs - Individuel Frames/Knight - Standard/Knight_Idle_1(Big).png";
	}

	return new CardHero(pos, spriteCardPath, spriteFramePath, scene);
}
Card* AbstractFactory::createCoin(position pos, cocos2d::Scene* scene) {
	std::string spriteCardPath = "Assets/Icons/Coins_0/coin_01.png";
	return new CardCoin(pos, spriteCardPath, spriteFramePath, scene);
}
Card* AbstractFactory::createWeapon(position pos, cocos2d::Scene* scene) {
	int generateCard;
	std::string spriteCardPath;
	generateCard = rand() % 100;
	if (generateCard >= 0 && generateCard < 25)
	{
		spriteCardPath = "Assets/Weapons/weapon_regular_sword.png";
		return new CardCommonWeapon(pos, spriteCardPath, spriteFramePath, scene);
	}
	else if (generateCard >= 25 && generateCard < 50)
	{
		spriteCardPath = "Assets/Weapons/weapon_knight_sword.png";
		return new CardCommonWeapon(pos, spriteCardPath, spriteFramePath, scene);
	}
	else if (generateCard >= 50 && generateCard < 75)
	{
		spriteCardPath = "Assets/Weapons/weapon_red_gem_sword.png";
		return new CardHealingWeapon(pos, spriteCardPath, spriteFramePath, scene);
	}
	else if (generateCard >= 75 && generateCard < 100)
	{
		spriteCardPath = "Assets/Weapons/androide.png";
		return new CardPoisonedWeapon(pos, spriteCardPath, spriteFramePath, scene);
	}

}
Card* AbstractFactory::createHeroWeapon(position pos, cocos2d::Scene* scene) {
	if (gameData::chosenHero==0) {
		return new CardCommonWeapon(pos, "Assets/Weapons/weapon_regular_sword.png", spriteFramePath, scene, gameData::amountAmmoHeros[gameData::chosenHero%4]);
	}
	else if (gameData::chosenHero == 1) {
		return new CardCommonWeapon(pos, "Assets/Weapons/weapon_knight_sword.png", spriteFramePath, scene, gameData::amountAmmoHeros[gameData::chosenHero % 4]);
	}
	else if (gameData::chosenHero == 2) {
		return new CardPoisonedWeapon(pos, "Assets/Weapons/androide.png", spriteFramePath, scene, gameData::amountAmmoHeros[gameData::chosenHero % 4]);
	}
	else if (gameData::chosenHero == 3) {
		return new CardHealingWeapon(pos, "Assets/Weapons/weapon_red_gem_sword.png", spriteFramePath, scene, gameData::amountAmmoHeros[gameData::chosenHero % 4]);
	}
}
Card* AbstractFactory::createMonster(position pos, cocos2d::Scene* scene) { return nullptr; }
Card* AbstractFactory::createPotion(position pos, cocos2d::Scene* scene) { return nullptr; }
Card* AbstractFactory::createGoodTreasure(position pos, cocos2d::Scene* scene) { return nullptr; }
Card* AbstractFactory::createBadTreasure(position pos, cocos2d::Scene* scene) { return nullptr; }
