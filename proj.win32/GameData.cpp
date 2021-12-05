#include <proj.win32/GameData.h>
namespace gameData {
	int  money = 2000000;
	int tempMoney = 0;
	int  chosenHero = 0;
	int  lastBuyHero = 0;
	int  lvlHeart[4] = { 0,0,0,0 };
	int  lvlAmmo[4] = { 0,0,0,0 };
	bool lockHero[4] = { true,false,false,false };
	int  priceHero[4] = { 0,-150,-300,-350 };
	int priceHeart = 20;
	int priceAmmo = 20;
	int amountXPHeros[4] = { 8,15,12,10 };
	int amountAmmoHeros[4] = { 5,10,8,5 };
	position heroPosition(1, 1);
	cocos2d::Scene* currentScene;
	int currentLevel = 1;
	cocos2d::Label* currentMoneyLabel;
	int fontSize = 42;
	bool isSceneLocked = false;
	std::string pathToMonsters[7] = { "Assets/Monsters/Enchanted Forest - Individual Frames/Gnoll - Brute/GnollBrute_Idle_1.png","Assets/Monsters/Enchanted Forest - Individual Frames/Troll/Troll_Idle_1.png","Assets/Monsters/Enchanted Forest - Individual Frames/Bear/Bear_Idle_1.png","Assets/Monsters/Enchanted Forest - Individual Frames/Centaur - Male/Centaur_M_Idle_1.png","Assets/Monsters/Enchanted Forest - Individual Frames/Wolf/Wolf_Idle_1.png","Assets/Monsters/Enchanted Forest - Individual Frames/Gnoll - Shaman/GnollShaman_Idle_1.png","Assets/Monsters/Enchanted Forest - Individual Frames/Ent/Ent_Idle_1.png" };
	int RatioBossMonster=0;
}
