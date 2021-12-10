#include <proj.win32/GameData.h>
namespace gameData {
	bool FirstStart = true;//зманна для провірки першого запуску тіп чи це перший раз відкримваємо головне меню чи ні  використав для запуску музики
	bool playSound = true;
	bool playMusic = true;
	int  money = 500;
	double tempSpeedMove=0.6;
	int tempMoney = 0;
	int  chosenHero = 0;
	int  lastBuyHero = 0;
	int  lvlHeart[4] = { 1,1,1,1 };
	int  lvlAmmo[4] = { 1,1,1,1 };
	bool lockHero[4] = { true,false,false,false };
	int  priceHero[4] = { 0,-150,-300,-350 };
	int priceHeart = 20;
	int priceAmmo = 20;
	int amountXPHeros[4] = { 8,12,10,10 };
	int amountAmmoHeros[4] = { 5,10,8,5 };
	position heroPosition(1, 1);
	cocos2d::Scene* currentScene;
	int currentLevel = 1;
	cocos2d::Label* currentMoneyLabel;
	cocos2d::Sprite* kickSprite;
	int fontSize = 42;
	bool isSceneLocked = false;
	bool isbought[4] = { true,false,false,false };

	std::string pathToWeaponLvl1[4] = { "Assets/Weapons/weapon_regular_sword.png","Assets/Weapons/weapon_knight_sword.png","Assets/Weapons/weapon_red_gem_sword.png","Assets/Weapons/androide.png" };
	int WeaponMaxXPLvl1[4] = {7,5,10,9};

	std::string pathToMonstersLvl1[7] ={ "Assets/Monsters/Enchanted Forest - Individual Frames/Gnoll - Scout/GnollScout_Idle_1(Big).png","Assets/Monsters/Enchanted Forest - Individual Frames/Troll/Troll_Idle_1(Big).png","Assets/Monsters/Enchanted Forest - Individual Frames/Bear/Bear_Idle_1(Big).png","Assets/Monsters/Enchanted Forest - Individual Frames/Centaur - Male/Centaur_M_Idle_1(Big).png","Assets/Monsters/Enchanted Forest - Individual Frames/Wolf/Wolf_Idle_1(Big).png","Assets/Monsters/Enchanted Forest - Individual Frames/Gnoll - Shaman/GnollShaman_Idle_1(Big).png","Assets/Monsters/Enchanted Forest - Individual Frames/Ent/Ent_Idle_1(Big).png" };
	std::string pathToMonstersLvl2[7]= { "Assets/Monsters/Enchanted Forest - Individual Frames/Gnoll - Brute/GnollBrute_Idle_1.png","Assets/Monsters/Enchanted Forest - Individual Frames/Golem/Golem_Idle_1(Big).png","Assets/Monsters/Enchanted Forest - Individual Frames/Mushroom - Large/LargeMushroom_Idle_1(Big).png","Assets/Monsters/Enchanted Forest - Individual Frames/Centuar - Female/Centaur_F_Idle_1(Big).png","Assets/Monsters/Monster RPG Pack/Orcs/Ogre/ogre_idle_anim/ogre_idle_anim_f1(Big).png","Assets/Monsters/Monster RPG Pack/Orcs/Orc_Warrior/orc_warrior_idle_anim/orc_warrior_idle_anim_f1(Big).png","Assets/Monsters/Monster RPG Pack/Undeads/Skelet/skelet_idle_anim/skelet_idle_anim_f1(Big).png"};
	std::string pathToMonstersLvl3[7]= { "Assets/Monsters/Enchanted Forest - Individual Frames/Gnoll - Overseer/GnollOverseer_Idle_1(Big).png","Assets/Monsters/Monster RPG Pack/Orcs/Orc_Masked/orc_masked_idle_anim/orc_masked_idle_anim_f1(Big)","Assets/Monsters/Monster RPG Pack/Orcs/Goblin/goblin_idle_anim/goblin_idle_anim_f1(Big)","Assets/Monsters/Monster RPG Pack/Demons/Demon_Big/demon_big_idle_anim/demon_big_idle_anim_f1(Big).png","Assets/Monsters/Monster RPG Pack/Undeads/Zombie_Tiny/zombie_tiny_idle_anim/zombie_tiny_idle_anim_f1(Big).png","Assets/Monsters/Monster RPG Pack/Undeads/Zombie/zombie_idle_anim/zombie_idle_anim_f1(Big).png","Assets/Monsters/Monster RPG Pack/Undeads/Zombie_Big/zombie_big_idle_anim/zombie_big_idle_anim_f1(Big).png"};
	int MonstersMaxXPLvl1[8] = { 4,3,3,4,8,7,8,9};
	int MonstersMaxXPLvl2[8] = { 5,2,1,7,4,5,7,9 };
	int MonstersMaxXPLvl3[8] = { 4,2,3,4,1,8,7,9 };

	int RatioBossMonster = 0;
	bool isHeroArmed = false;
	position posBossHpRegen(0,0);
	 bool weaponIsPoisned = false;
	 bool weaponIsHeling=false;
	 double ScaleCard = 0;
}
