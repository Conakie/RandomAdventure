
#ifndef RATABS_ENCOUNTERSTATS
#define RATABS_ENCOUNTERSTATS

#include "Encounter UID.h"

struct Encounter
{
	Encounter() = default;

	EncounterUid uid{ EncounterUid::none };
	double hp{ 0 };
	double maxHp{ 0 };
	double atk{ 0 };
	double maxAtk{ 0 };
	int xp{ 0 };
	int lvlUpXp{ 22 };
	short lvl{ 1 };
	bool isGone{ false };
	bool isUnderAttack{ false };
	bool canTalk{ true };

};

#endif // !RATABS_ENCOUNTERSTATS