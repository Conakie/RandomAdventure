
#ifndef RATABS_PLAYERSTATS_STRUCTS_H
#define RATABS_PLAYERSTATS_STRUCTS_H

#include <string_view>

struct Players
{
    Players() = default;

	std::string name{ "You" };
	short lvl		{ 0 };
	short critRate	{ 0 };
	short stamina	{ 0 };
	int xp			{ 0 };
	int lvlUpXp		{ 0 };
	int weight		{ 0 };
	double critDmg	{ 0 };
	double hp		{ 0 };
	double maxHp	{ 0 };
	double atk		{ 0 };
	double maxAtk	{ 0 };
	double def		{ 0 };
	double maxDef	{ 0 };
};



struct Stats
{
    Stats() = default;

	short strength    { 0 };
	short dexterity   { 0 };
	short constitution{ 0 };
	short intelligence{ 0 };
	short wisdom      { 0 };
	short charisma    { 0 };
};



//struct Items
//{
//
//    Items() = default;
//
//    short smallHealingPotion{ 0 };
//    short mediumHealingPotion{ 0 };
//    short bigHealingPotion{ 0 };
//    short molotov{ 0 };
//    short nuke{ 0 };
//    short herbs{ 0 };
//    short wood{ 0 };
//    short arrow{ 0 };
//    short leather{ 0 };
//    short stone{ 0 };
//    short bone{ 0 };
//    short paper{ 0 };
//    short meat{ 0 };
//    short fish{ 0 };
//    short mushroom{ 0 };
//    short magicScroll{ 0 };
//    int cota{ 0 };
//    //none,
//
//};

#endif // !RATABS_PLAYERSTATS_STRUCTS_H