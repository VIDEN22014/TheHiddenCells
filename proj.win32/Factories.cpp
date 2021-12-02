#include <proj.win32/Factories.h>


Card* Level1Factory::createMonster(position pos, cocos2d::Scene* scene, std::string pathToSprite) {
	std::string spriteCardPath = "Assets/Monsters/Enchanted Forest - Individual Frames/Gnoll - Brute/GnollBrute_Idle_1.png";

	return new CardMonster(pos, spriteCardPath, spriteFramePath, scene);
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
	std::string spriteCardPath = "Assets/NPC/Fantasy RPG NPCs - Individuel Frames/Knight - Standard/Knight_Idle_128.png";
	return new CardHero(pos, spriteCardPath, spriteFramePath, scene);
}
Card* AbstractFactory::createCoin(position pos, cocos2d::Scene* scene) {
	std::string spriteCardPath = "Assets/Icons/Coins_0/coin_01.png";
	return new CardCoin(pos, spriteCardPath, spriteFramePath, scene);
}
Card* AbstractFactory::createMonster(position pos, cocos2d::Scene* scene, std::string pathToSprite) { return nullptr; }
Card* AbstractFactory::createGoodTreasure(position pos, cocos2d::Scene* scene) { return nullptr; }
Card* AbstractFactory::createBadTreasure(position pos, cocos2d::Scene* scene) { return nullptr; }
