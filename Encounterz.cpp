
#include <iostream>
#include "Encounterz.h"
#include "Playerz.h"
#include "Random.h"
#include "PrintErrors.h"
#include "KiiyuoMath.h"



void Creatures::Encounter::Encounterz::attack(Player::Playerz& player)
{
	if (m_player)
	{
		std::cout << m_name << " attacks you.\n";
		if (Random::get(0, 99) < m_critRate)
		{
			std::cout << m_name << " did a critical hit!\n";
			m_player->takeDamage(m_atk * m_critDmg);
		}
		else
		{
			m_player->takeDamage(m_atk);
		}
	}
	else
	{
		std::cout << m_name << " stares angrily at you.\n";
	}
}

void Creatures::Encounter::Encounterz::heal(double healing)
{
	healing = roundToTwoDecimals(healing);
	std::cout << m_name << " healed of " << healing << " hp.\n";
	// if the hp plus the healing is less than the max hp
	// add healing to hp
	// otherwise hp is set to maxHp
	if (m_hp + healing < m_maxHp)
		m_hp += healing;
	else
		m_hp = m_maxHp;

	std::cout << m_name << " has " << m_hp << " hp now.\n";
}

void Creatures::Encounter::Encounterz::takeDamage(double damage)
{
	damage = roundToTwoDecimals(damage);
	m_hp -= roundToTwoDecimals((damage - (damage * m_def / 100)));

	if (isAlive())
	{
		std::cout << m_name << " took " << damage << " hp of damage.\n"
			<< m_name << " has " << m_hp << " hp.\n";
		m_isUnderAttack = true;
		m_canTalk = false;
	}
	else
		std::cout << m_name << " died!\n";
}

void Creatures::Encounter::Encounterz::talk()
{
	if (m_player)
	{
		if (m_canTalk && !m_isUnderAttack && !m_isGone)
		{
			dialogue();
		}
		else
		{
			std::cout << m_name << " isn't interested in talking with you.\n";
		}
	}
	else
	{
		std::cout << "Lenre: \"No player set... Nanre is useless. He had one job.\"\n";
	}
}

void Creatures::Encounter::Encounterz::thinkAndAct()
{
	if (m_isGone)
	{
		std::cout << m_name << " is gone.\n";
	}
	else
	{
		if (m_player)
		{
			if (m_isUnderAttack && isAlive())
			{
				attack(*m_player);
			}
			else
				talk();
		}
	}
}

void Creatures::Encounter::Encounterz::dropItems()
{
	// if no player has been set return early
	if (!m_player)
	{
		std::cout << m_name << " didn't have any items to drop.\n";
		return;
	}
	Items::ItemName item{ Items::ItemName::none };
	int percentage{ Random::get(0,99) };
	int quantity{ Random::get(1, 3) };
	Player::Playerz& player{ *m_player };
	// common -> 40%
	// rare -> 30%
	// epic -> 20%
	//legendary -> 10%

	if (percentage < 40)
	{// the drop is a common item
		switch (Random::get(0, 4))
		{
		case 0:// small healing potion
			std::cout << "You got " << quantity << " small healing potions.";
			player.openInventory().addItem(Items::ItemName::smallHealingPotion, quantity);
			break;
		case 1:// herbs
			std::cout << "You got " << quantity << " herbs.";
			player.openInventory().addItem(Items::ItemName::herbs, quantity);
			break;
		case 2:// bone
			item = Items::ItemName::bone;
			std::cout << "You got " << quantity << " bones.";
			player.openInventory().addItem(Items::ItemName::bone, quantity);
			break;
		case 3:// meat
			std::cout << "You got " << quantity << " steaks.";
			player.openInventory().addItem(Items::ItemName::meat, quantity);
			break;
		case 4:// fish
			std::cout << "You got " << quantity << " fish.";
			player.openInventory().addItem(Items::ItemName::fish, quantity);
			break;
		default:
			Print::Errors::wrongRandNum(40);
			break;
		}
	}
	else if (percentage >= 40 && percentage < 70)
	{// the drop is a rare item
		switch (Random::get(0, 4))
		{
		case 0:// medium healing potion
			std::cout << "You got " << quantity << " medium healing potions.";
			player.openInventory().addItem(Items::ItemName::mediumHealingPotion, quantity);
			break;
		case 1:// molotov
			std::cout << "You got " << quantity << " molotov.";
			player.openInventory().addItem(Items::ItemName::molotov, quantity);
			break;
		case 2:// arrow
			std::cout << "You got " << quantity << " arrows.";
			player.openInventory().addItem(Items::ItemName::arrow, quantity);
			break;
		case 3:// stone
			std::cout << "You got " << quantity << " stone.";
			player.openInventory().addItem(Items::ItemName::stone, quantity);
			break;
		case 4:// paper
			std::cout << "You got " << quantity << " sheets of papers.";
			player.openInventory().addItem(Items::ItemName::paper, quantity);
			break;
		default:
			Print::Errors::wrongRandNum(4070);
			break;
		}
	}
	else if (percentage >= 70 && percentage < 90)
	{// the drop is a epic item
		switch (Random::get(0, 2))
		{
		case 0:// big healing potion
			std::cout << "You got " << quantity << " big healing potions.";
			player.openInventory().addItem(Items::ItemName::bigHealingPotion, quantity);
			break;
		case 1:// wood
			std::cout << "You got " << quantity << " wood logs.";
			player.openInventory().addItem(Items::ItemName::wood, quantity);
			break;
		case 2:// leather
			std::cout << "You got " << quantity << " leather.";
			player.openInventory().addItem(Items::ItemName::leather, quantity);
			break;
		default:
			Print::Errors::wrongRandNum(7090);
			break;
		}
	}
	else if (percentage <= 90)
	{// the drop is a legendary item
		switch (Random::get(0, 1))
		{
		case 0:// nuke
			std::cout << "You got " << quantity << " nukes.";
			player.openInventory().addItem(Items::ItemName::nuke, quantity);
			break;
		case 1:// magic scroll
			std::cout << "You got " << quantity << " magic scroll.";
			player.openInventory().addItem(Items::ItemName::magicScroll, quantity);
			break;
		default:
			Print::Errors::wrongRandNum(90);
			break;
		}
	}
	else
		std::cout << m_name << " didn't drop any item.";
	std::cout << '\n';
}

void Creatures::Encounter::Encounterz::resetEncounter()
{
	m_hp = 0;
	m_maxHp = 0;
	m_atk = 0;
	m_maxAtk = 0;
	m_critDmg = 0;
	m_critRate = 0;
	m_def = 0;
	m_maxDef = 0;
	m_xp = 1;
	m_xpForLvlUp = 0;
	m_lvl = 1;
	m_player = nullptr;
	m_type = EncounterType::none;
	m_isGone = false;
	m_isUnderAttack = false;
	m_canTalk = true;
}

void Creatures::Encounter::Encounterz::setEncounter()
{
	switch (m_type)
	{
	case Creatures::Encounter::EncounterType::guard:
		m_maxHp = 0 + (0 * (m_lvl - 1));
		m_maxAtk = 0 + (0 * m_lvl);
		m_maxDef = 0;
		m_critRate = 0;
		m_critDmg = 0;
		m_xp = 1;

		m_hp = m_maxHp;
		m_atk = m_maxAtk;
		m_def = m_maxDef;
		break;
	case Creatures::Encounter::EncounterType::drunkGuy:
		m_maxHp = 0 + (0 * (m_lvl - 1));
		m_maxAtk = 0 + (0 * m_lvl);
		m_maxDef = 0;
		m_critRate = 0;
		m_critDmg = 0;
		m_xp = 1;

		m_hp = m_maxHp;
		m_atk = m_maxAtk;
		m_def = m_maxDef;
		break;
	case Creatures::Encounter::EncounterType::soldier:
		m_maxHp = 0 + (0 * (m_lvl - 1));
		m_maxAtk = 0 + (0 * m_lvl);
		m_maxDef = 0;
		m_critRate = 0;
		m_critDmg = 0;
		m_xp = 1;

		m_hp = m_maxHp;
		m_atk = m_maxAtk;
		m_def = m_maxDef;
		break;
	case Creatures::Encounter::EncounterType::torturer:
		m_maxHp = 0 + (0 * (m_lvl - 1));
		m_maxAtk = 0 + (0 * m_lvl);
		m_maxDef = 0;
		m_critRate = 0;
		m_critDmg = 0;
		m_xp = 1;

		m_hp = m_maxHp;
		m_atk = m_maxAtk;
		m_def = m_maxDef;
		break;
	case Creatures::Encounter::EncounterType::giant:
		m_maxHp = 0 + (0 * (m_lvl - 1));
		m_maxAtk = 0 + (0 * m_lvl);
		m_maxDef = 0;
		m_critRate = 0;
		m_critDmg = 0;
		m_xp = 1;

		m_hp = m_maxHp;
		m_atk = m_maxAtk;
		m_def = m_maxDef;
		break;
	case Creatures::Encounter::EncounterType::priest:
		m_maxHp = 0 + (0 * (m_lvl - 1));
		m_maxAtk = 0 + (0 * m_lvl);
		m_maxDef = 0;
		m_critRate = 0;
		m_critDmg = 0;
		m_xp = 1;

		m_hp = m_maxHp;
		m_atk = m_maxAtk;
		m_def = m_maxDef;
		break;
	case Creatures::Encounter::EncounterType::elf:
		m_maxHp = 0 + (0 * (m_lvl - 1));
		m_maxAtk = 0 + (0 * m_lvl);
		m_maxDef = 0;
		m_critRate = 0;
		m_critDmg = 0;
		m_xp = 1;

		m_hp = m_maxHp;
		m_atk = m_maxAtk;
		m_def = m_maxDef;
		break;
	case Creatures::Encounter::EncounterType::dwarf:
		m_maxHp = 0 + (0 * (m_lvl - 1));
		m_maxAtk = 0 + (0 * m_lvl);
		m_maxDef = 0;
		m_critRate = 0;
		m_critDmg = 0;
		m_xp = 1;

		m_hp = m_maxHp;
		m_atk = m_maxAtk;
		m_def = m_maxDef;
		break;
	case Creatures::Encounter::EncounterType::prisoner:
		m_maxHp = 0 + (0 * (m_lvl - 1));
		m_maxAtk = 0 + (0 * m_lvl);
		m_maxDef = 0;
		m_critRate = 0;
		m_critDmg = 0;
		m_xp = 1;

		m_hp = m_maxHp;
		m_atk = m_maxAtk;
		m_def = m_maxDef;
		break;
	case Creatures::Encounter::EncounterType::theRock:
		m_maxHp = 0 + (0 * (m_lvl - 1));
		m_maxAtk = 0 + (0 * m_lvl);
		m_maxDef = 0;
		m_critRate = 0;
		m_critDmg = 0;
		m_xp = 1;

		m_hp = m_maxHp;
		m_atk = m_maxAtk;
		m_def = m_maxDef;
		break;
	case Creatures::Encounter::EncounterType::trader:
		m_maxHp = 0 + (0 * (m_lvl - 1));
		m_maxAtk = 0 + (0 * m_lvl);
		m_maxDef = 0;
		m_critRate = 0;
		m_critDmg = 0;
		m_xp = 1;

		m_hp = m_maxHp;
		m_atk = m_maxAtk;
		m_def = m_maxDef;
		break;
	case Creatures::Encounter::EncounterType::bartender:
		m_maxHp = 0 + (0 * (m_lvl - 1));
		m_maxAtk = 0 + (0 * m_lvl);
		m_maxDef = 0;
		m_critRate = 0;
		m_critDmg = 0;
		m_xp = 1;

		m_hp = m_maxHp;
		m_atk = m_maxAtk;
		m_def = m_maxDef;
		break;
	case Creatures::Encounter::EncounterType::bard:
		m_maxHp = 0 + (0 * (m_lvl - 1));
		m_maxAtk = 0 + (0 * m_lvl);
		m_maxDef = 0;
		m_critRate = 0;
		m_critDmg = 0;
		m_xp = 1;

		m_hp = m_maxHp;
		m_atk = m_maxAtk;
		m_def = m_maxDef;
		break;
	case Creatures::Encounter::EncounterType::loli:
		m_maxHp = 0 + (0 * (m_lvl - 1));
		m_maxAtk = 0 + (0 * m_lvl);
		m_maxDef = 0;
		m_critRate = 0;
		m_critDmg = 0;
		m_xp = 1;

		m_hp = m_maxHp;
		m_atk = m_maxAtk;
		m_def = m_maxDef;
		break;
	case Creatures::Encounter::EncounterType::shota:
		m_maxHp = 0 + (0 * (m_lvl - 1));
		m_maxAtk = 0 + (0 * m_lvl);
		m_maxDef = 0;
		m_critRate = 0;
		m_critDmg = 0;
		m_xp = 1;

		m_hp = m_maxHp;
		m_atk = m_maxAtk;
		m_def = m_maxDef;
		break;
	case Creatures::Encounter::EncounterType::zombie:
		m_maxHp = 0 + (0 * (m_lvl - 1));
		m_maxAtk = 0 + (0 * m_lvl);
		m_maxDef = 0;
		m_critRate = 0;
		m_critDmg = 0;
		m_xp = 1;

		m_hp = m_maxHp;
		m_atk = m_maxAtk;
		m_def = m_maxDef;
		break;
	case Creatures::Encounter::EncounterType::skeleton:
		m_maxHp = 0 + (0 * (m_lvl - 1));
		m_maxAtk = 0 + (0 * m_lvl);
		m_maxDef = 0;
		m_critRate = 0;
		m_critDmg = 0;
		m_xp = 1;

		m_hp = m_maxHp;
		m_atk = m_maxAtk;
		m_def = m_maxDef;
		break;
	case Creatures::Encounter::EncounterType::witch:
		m_maxHp = 0 + (0 * (m_lvl - 1));
		m_maxAtk = 0 + (0 * m_lvl);
		m_maxDef = 0;
		m_critRate = 0;
		m_critDmg = 0;
		m_xp = 1;

		m_hp = m_maxHp;
		m_atk = m_maxAtk;
		m_def = m_maxDef;
		break;
	case Creatures::Encounter::EncounterType::ghost:
		m_maxHp = 0 + (0 * (m_lvl - 1));
		m_maxAtk = 0 + (0 * m_lvl);
		m_maxDef = 0;
		m_critRate = 0;
		m_critDmg = 0;
		m_xp = 1;

		m_hp = m_maxHp;
		m_atk = m_maxAtk;
		m_def = m_maxDef;
		break;
	case Creatures::Encounter::EncounterType::theBeer:
		m_maxHp = 0 + (0 * (m_lvl - 1));
		m_maxAtk = 0 + (0 * m_lvl);
		m_maxDef = 0;
		m_critRate = 0;
		m_critDmg = 0;
		m_xp = 1;

		m_hp = m_maxHp;
		m_atk = m_maxAtk;
		m_def = m_maxDef;
		break;
	case Creatures::Encounter::EncounterType::yourself:
		m_maxHp = 0 + (0 * (m_lvl - 1));
		m_maxAtk = 0 + (0 * m_lvl);
		m_maxDef = 0;
		m_critRate = 0;
		m_critDmg = 0;
		m_xp = 1;

		m_hp = m_maxHp;
		m_atk = m_maxAtk;
		m_def = m_maxDef;
		break;
	case Creatures::Encounter::EncounterType::stoneGolem:
		m_maxHp = 0 + (0 * (m_lvl - 1));
		m_maxAtk = 0 + (0 * m_lvl);
		m_maxDef = 0;
		m_critRate = 0;
		m_critDmg = 0;
		m_xp = 1;

		m_hp = m_maxHp;
		m_atk = m_maxAtk;
		m_def = m_maxDef;
		break;
	case Creatures::Encounter::EncounterType::blurp:
		m_maxHp = 0 + (0 * (m_lvl - 1));
		m_maxAtk = 0 + (0 * m_lvl);
		m_maxDef = 0;
		m_critRate = 0;
		m_critDmg = 0;
		m_xp = 1;

		m_hp = m_maxHp;
		m_atk = m_maxAtk;
		m_def = m_maxDef;
		break;
	case Creatures::Encounter::EncounterType::smallRat:
		m_maxHp = 0 + (0 * (m_lvl - 1));
		m_maxAtk = 0 + (0 * m_lvl);
		m_maxDef = 0;
		m_critRate = 0;
		m_critDmg = 0;
		m_xp = 1;

		m_hp = m_maxHp;
		m_atk = m_maxAtk;
		m_def = m_maxDef;
		break;
	case Creatures::Encounter::EncounterType::rat:
		m_maxHp = 0 + (0 * (m_lvl - 1));
		m_maxAtk = 0 + (0 * m_lvl);
		m_maxDef = 0;
		m_critRate = 0;
		m_critDmg = 0;
		m_xp = 1;

		m_hp = m_maxHp;
		m_atk = m_maxAtk;
		m_def = m_maxDef;
		break;
	case Creatures::Encounter::EncounterType::giantRat:
		m_maxHp = 0 + (0 * (m_lvl - 1));
		m_maxAtk = 0 + (0 * m_lvl);
		m_maxDef = 0;
		m_critRate = 0;
		m_critDmg = 0;
		m_xp = 1;

		m_hp = m_maxHp;
		m_atk = m_maxAtk;
		m_def = m_maxDef;
		break;
	case Creatures::Encounter::EncounterType::enormousRat:
		m_maxHp = 0 + (0 * (m_lvl - 1));
		m_maxAtk = 0 + (0 * m_lvl);
		m_maxDef = 0;
		m_critRate = 0;
		m_critDmg = 0;
		m_xp = 1;

		m_hp = m_maxHp;
		m_atk = m_maxAtk;
		m_def = m_maxDef;
		break;
	case Creatures::Encounter::EncounterType::colossalRat:
		m_maxHp = 0 + (0 * (m_lvl - 1));
		m_maxAtk = 0 + (0 * m_lvl);
		m_maxDef = 0;
		m_critRate = 0;
		m_critDmg = 0;
		m_xp = 1;

		m_hp = m_maxHp;
		m_atk = m_maxAtk;
		m_def = m_maxDef;
		break;
	case Creatures::Encounter::EncounterType::colossalSpider:
		m_maxHp = 0 + (0 * (m_lvl - 1));
		m_maxAtk = 0 + (0 * m_lvl);
		m_maxDef = 0;
		m_critRate = 0;
		m_critDmg = 0;
		m_xp = 1;

		m_hp = m_maxHp;
		m_atk = m_maxAtk;
		m_def = m_maxDef;
		break;
	case Creatures::Encounter::EncounterType::ratman:
		m_maxHp = 0 + (0 * (m_lvl - 1));
		m_maxAtk = 0 + (0 * m_lvl);
		m_maxDef = 0;
		m_critRate = 0;
		m_critDmg = 0;
		m_xp = 1;

		m_hp = m_maxHp;
		m_atk = m_maxAtk;
		m_def = m_maxDef;
		break;
	case Creatures::Encounter::EncounterType::goblin:
		m_maxHp = 0 + (0 * (m_lvl - 1));
		m_maxAtk = 0 + (0 * m_lvl);
		m_maxDef = 0;
		m_critRate = 0;
		m_critDmg = 0;
		m_xp = 1;

		m_hp = m_maxHp;
		m_atk = m_maxAtk;
		m_def = m_maxDef;
		break;
	case Creatures::Encounter::EncounterType::hobgoblin:
		m_maxHp = 0 + (0 * (m_lvl - 1));
		m_maxAtk = 0 + (0 * m_lvl);
		m_maxDef = 0;
		m_critRate = 0;
		m_critDmg = 0;
		m_xp = 1;

		m_hp = m_maxHp;
		m_atk = m_maxAtk;
		m_def = m_maxDef;
		break;
	case Creatures::Encounter::EncounterType::orc:
		m_maxHp = 0 + (0 * (m_lvl - 1));
		m_maxAtk = 0 + (0 * m_lvl);
		m_maxDef = 0;
		m_critRate = 0;
		m_critDmg = 0;
		m_xp = 1;

		m_hp = m_maxHp;
		m_atk = m_maxAtk;
		m_def = m_maxDef;
		break;
	case Creatures::Encounter::EncounterType::kobold:
		m_maxHp = 0 + (0 * (m_lvl - 1));
		m_maxAtk = 0 + (0 * m_lvl);
		m_maxDef = 0;
		m_critRate = 0;
		m_critDmg = 0;
		m_xp = 1;

		m_hp = m_maxHp;
		m_atk = m_maxAtk;
		m_def = m_maxDef;
		break;
	case Creatures::Encounter::EncounterType::kockbold:
		m_maxHp = 0 + (0 * (m_lvl - 1));
		m_maxAtk = 0 + (0 * m_lvl);
		m_maxDef = 0;
		m_critRate = 0;
		m_critDmg = 0;
		m_xp = 1;

		m_hp = m_maxHp;
		m_atk = m_maxAtk;
		m_def = m_maxDef;
		break;
	case Creatures::Encounter::EncounterType::cockblin:
		m_maxHp = 0 + (0 * (m_lvl - 1));
		m_maxAtk = 0 + (0 * m_lvl);
		m_maxDef = 0;
		m_critRate = 0;
		m_critDmg = 0;
		m_xp = 1;

		m_hp = m_maxHp;
		m_atk = m_maxAtk;
		m_def = m_maxDef;
		break;
	case Creatures::Encounter::EncounterType::the104:
		m_maxHp = 0 + (0 * (m_lvl - 1));
		m_maxAtk = 0 + (0 * m_lvl);
		m_maxDef = 0;
		m_critRate = 0;
		m_critDmg = 0;
		m_xp = 1;

		m_hp = m_maxHp;
		m_atk = m_maxAtk;
		m_def = m_maxDef;
		break;
	case Creatures::Encounter::EncounterType::errorGuy:
		m_maxHp = 0 + (0 * (m_lvl - 1));
		m_maxAtk = 0 + (0 * m_lvl);
		m_maxDef = 0;
		m_critRate = 0;
		m_critDmg = 0;
		m_xp = 1;

		m_hp = m_maxHp;
		m_atk = m_maxAtk;
		m_def = m_maxDef;
		break;
	case Creatures::Encounter::EncounterType::elesya:
		m_maxHp = 0 + (0 * (m_lvl - 1));
		m_maxAtk = 0 + (0 * m_lvl);
		m_maxDef = 0;
		m_critRate = 0;
		m_critDmg = 0;
		m_xp = 1;

		m_hp = m_maxHp;
		m_atk = m_maxAtk;
		m_def = m_maxDef;
		break;
	case Creatures::Encounter::EncounterType::kelmod:
		m_maxHp = 0 + (0 * (m_lvl - 1));
		m_maxAtk = 0 + (0 * m_lvl);
		m_maxDef = 0;
		m_critRate = 0;
		m_critDmg = 0;
		m_xp = 1;

		m_hp = m_maxHp;
		m_atk = m_maxAtk;
		m_def = m_maxDef;
		break;
	case Creatures::Encounter::EncounterType::lenre:
		m_maxHp = 0 + (0 * (m_lvl - 1));
		m_maxAtk = 0 + (0 * m_lvl);
		m_maxDef = 0;
		m_critRate = 0;
		m_critDmg = 0;
		m_xp = 1;

		m_hp = m_maxHp;
		m_atk = m_maxAtk;
		m_def = m_maxDef;
		break;
	case Creatures::Encounter::EncounterType::necoto:
		m_maxHp = 0 + (0 * (m_lvl - 1));
		m_maxAtk = 0 + (0 * m_lvl);
		m_maxDef = 0;
		m_critRate = 0;
		m_critDmg = 0;
		m_xp = 1;

		m_hp = m_maxHp;
		m_atk = m_maxAtk;
		m_def = m_maxDef;
		break;
	case Creatures::Encounter::EncounterType::kyo:
		m_maxHp = 0 + (0 * (m_lvl - 1));
		m_maxAtk = 0 + (0 * m_lvl);
		m_maxDef = 0;
		m_critRate = 0;
		m_critDmg = 0;
		m_xp = 1;

		m_hp = m_maxHp;
		m_atk = m_maxAtk;
		m_def = m_maxDef;
		break;
	case Creatures::Encounter::EncounterType::expN30A:
		m_maxHp = 0 + (0 * (m_lvl - 1));
		m_maxAtk = 0 + (0 * m_lvl);
		m_maxDef = 0;
		m_critRate = 0;
		m_critDmg = 0;
		m_xp = 1;

		m_hp = m_maxHp;
		m_atk = m_maxAtk;
		m_def = m_maxDef;
		break;
	case Creatures::Encounter::EncounterType::expN30B:
		m_maxHp = 0 + (0 * (m_lvl - 1));
		m_maxAtk = 0 + (0 * m_lvl);
		m_maxDef = 0;
		m_critRate = 0;
		m_critDmg = 0;
		m_xp = 1;

		m_hp = m_maxHp;
		m_atk = m_maxAtk;
		m_def = m_maxDef;
		break;
	case Creatures::Encounter::EncounterType::expN30C:
		m_maxHp = 0 + (0 * (m_lvl - 1));
		m_maxAtk = 0 + (0 * m_lvl);
		m_maxDef = 0;
		m_critRate = 0;
		m_critDmg = 0;
		m_xp = 1;

		m_hp = m_maxHp;
		m_atk = m_maxAtk;
		m_def = m_maxDef;
		break;
	case Creatures::Encounter::EncounterType::sila:
		m_maxHp = 0 + (0 * (m_lvl - 1));
		m_maxAtk = 0 + (0 * m_lvl);
		m_maxDef = 0;
		m_critRate = 0;
		m_critDmg = 0;
		m_xp = 1;

		m_hp = m_maxHp;
		m_atk = m_maxAtk;
		m_def = m_maxDef;
		break;
	case Creatures::Encounter::EncounterType::armNuc:
		m_maxHp = 0 + (0 * (m_lvl - 1));
		m_maxAtk = 0 + (0 * m_lvl);
		m_maxDef = 0;
		m_critRate = 0;
		m_critDmg = 0;
		m_xp = 1;

		m_hp = m_maxHp;
		m_atk = m_maxAtk;
		m_def = m_maxDef;
		break;
	case Creatures::Encounter::EncounterType::miiro:
		m_maxHp = 0 + (0 * (m_lvl - 1));
		m_maxAtk = 0 + (0 * m_lvl);
		m_maxDef = 0;
		m_critRate = 0;
		m_critDmg = 0;
		m_xp = 1;

		m_hp = m_maxHp;
		m_atk = m_maxAtk;
		m_def = m_maxDef;
		break;
	case Creatures::Encounter::EncounterType::chishao:
		m_maxHp = 0 + (0 * (m_lvl - 1));
		m_maxAtk = 0 + (0 * m_lvl);
		m_maxDef = 0;
		m_critRate = 0;
		m_critDmg = 0;
		m_xp = 1;

		m_hp = m_maxHp;
		m_atk = m_maxAtk;
		m_def = m_maxDef;
		break;
	case Creatures::Encounter::EncounterType::nanre:
		m_maxHp = 0 + (0 * (m_lvl - 1));
		m_maxAtk = 0 + (0 * m_lvl);
		m_maxDef = 0;
		m_critRate = 0;
		m_critDmg = 0;
		m_xp = 1;

		m_hp = m_maxHp;
		m_atk = m_maxAtk;
		m_def = m_maxDef;
		break;
	case Creatures::Encounter::EncounterType::conakie:
		m_maxHp = 0 + (0 * (m_lvl - 1));
		m_maxAtk = 0 + (0 * m_lvl);
		m_maxDef = 0;
		m_critRate = 0;
		m_critDmg = 0;
		m_xp = 1;

		m_hp = m_maxHp;
		m_atk = m_maxAtk;
		m_def = m_maxDef;
		break;
	case Creatures::Encounter::EncounterType::none:
		m_maxHp = 0 + (0 * (m_lvl - 1));
		m_maxAtk = 0 + (0 * m_lvl);
		m_maxDef = 0;
		m_critRate = 0;
		m_critDmg = 0;
		m_xp = 1;

		m_hp = m_maxHp;
		m_atk = m_maxAtk;
		m_def = m_maxDef;
		break;
	default:
		m_maxHp = 0 + (0 * (m_lvl - 1));
		m_maxAtk = 0 + (0 * m_lvl);
		m_maxDef = 0;
		m_critRate = 0;
		m_critDmg = 0;
		m_xp = 1;

		m_hp = m_maxHp;
		m_atk = m_maxAtk;
		m_def = m_maxDef;
		break;
	}
}

void Creatures::Encounter::Encounterz::setType(EncounterType type)
{
	m_type = type;
}

void Creatures::Encounter::Encounterz::setLvl(int lvl)
{
	m_lvl = lvl;
}

void Creatures::Encounter::Encounterz::setPlayer(Player::Playerz* player)
{
	m_player = player;
}

void Creatures::Encounter::Encounterz::dialogue()
{
	std::cout << "Lenre: \"Nuh uh~\"\n";

	m_canTalk = false;
	m_isUnderAttack = true;
}
