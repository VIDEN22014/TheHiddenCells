#include <proj.win32/Factories.h>


Card* Level1Factory::createMonster(position pos, cocos2d::Scene* scene) {
	std::string spriteCardPath = "Assets/NPC/Fantasy RPG NPCs - Individuel Frames/Knight - Standard/Knight_Idle_1.png";
	return new Card(pos,spriteCardPath, spriteFramePath, scene);
}
Card* AbstractFactory::createHero(position pos, cocos2d::Scene* scene) {
	std::string spriteCardPath = "Assets/NPC/Fantasy RPG NPCs - Individuel Frames/Knight - Standard/Knight_Idle_1.png";
	return new CardHero(pos,spriteCardPath,spriteFramePath, scene);
}
Card* AbstractFactory::createCoin(position pos,cocos2d::Scene* scene) {
	std::string spriteCardPath = "Assets/Icons/Coins_0/coin_01.png";
	return new CardCoin(pos,spriteCardPath, spriteFramePath, scene);
}
Card* AbstractFactory::createMonster(position pos, cocos2d::Scene* scene) { return nullptr; }

