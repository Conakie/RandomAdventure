
#include <iostream>
#include <print>
#include "Encounterz.h"
#include "Playerz.h"
#include "Random.h"
#include "PrintErrors.h"
#include "KiiyuoMath.h"
#include "EncounterStatsSetter.h"
#include <string_view>
#include "EncounterType.h"



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
		std::print("{} left, you are alone now.", m_name);
	else
	{
		if (m_isUnderAttack)
		{
			if (m_hp < m_maxHp / 2)
			{
                if (Random::get(0, 99) < 50)
                {
                    std::print("{} is trying to heal himself.\n", m_name);
					heal(Random::get(1, static_cast<int>(m_maxHp / 10)));
                }
				else
					attack(*m_player);
            }
			else
				attack(*m_player);
		}
		else if (m_type == EncounterType::priest)
				talk();
		else
            std::print("{} is looking at you, but doesn't do anything.\n", m_name);
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

void Creatures::Encounter::Encounterz::printStats() const
{
	std::cout << m_name		<< "'s stats:\n"
		<< "Level: "		<< m_lvl		<< ";\n"
		<< "Health: "		<< m_hp			<< "/"	<< m_maxHp << ";\n"
		<< "Attack: "		<< m_atk		<< "/" << m_maxAtk << ";\n"
		<< "Defense: "		<< m_def		<< "/" << m_maxDef << ";\n"
		<< "Crit Rate: "	<< m_critRate	<< "%;\n"
		<< "Crit Damage: "	<< m_critDmg	<< "x;\n"
        << "XP dropped: "	<< m_xp			<< ".\n";
}

void Creatures::Encounter::Encounterz::setEncounter(int lvl)
{
	EncounterStatsSetter stats{};
	switch (m_type)
	{
	case Creatures::Encounter::EncounterType::guard:
		stats.set(70, 20, 6, 6, 10, 5, 2, 1, lvl);
		break;
	case Creatures::Encounter::EncounterType::drunkGuy:
		stats.set(60, 15, 4, 2, -10, 0, 2, 1, lvl);
		break;
	case Creatures::Encounter::EncounterType::soldier:
		stats.set(120, 25, 5, 10, 15, 10, 1.5, 3, lvl);
		break;
	case Creatures::Encounter::EncounterType::torturer:
		stats.set(70, 20, 5, 5, 25, 10, 1.5, 2, lvl);
		break;
	case Creatures::Encounter::EncounterType::giant:
		stats.set(100, 30, 3, 4, 15, 0, 0, 2, lvl);
		break;
	case Creatures::Encounter::EncounterType::priest:
		stats.set(100, 30, 3, 3, 10, 100, 2, 1, lvl);
		break;
	case Creatures::Encounter::EncounterType::elf:
		stats.set(50, 20, 3, 3, 0, 15, 1.5, 1, lvl);
		break;
	case Creatures::Encounter::EncounterType::dwarf:
		stats.set(80, 20, 4, 6, 20, 5, 2.5, 1, lvl);
		break;
	case Creatures::Encounter::EncounterType::prisoner:
		stats.set(50, 10, 5, 5, 0, 33, 2.5, 1, lvl);
		break;
	case Creatures::Encounter::EncounterType::theRock:
		stats.set(10, 0, 10, 0, 10, 5, 2, 1, lvl);
		break;
	case Creatures::Encounter::EncounterType::trader:
		stats.set(100, 10, 0, 5, 10, 5, 2, 1, lvl);
		break;
	case Creatures::Encounter::EncounterType::bartender:
		stats.set(100, 10, 0, 5, 10, 5, 2, 1, lvl);
		break;
	case Creatures::Encounter::EncounterType::bard:
		stats.set(100, 10, 0, 5, 10, 5, 2, 1, lvl);
		break;
	case Creatures::Encounter::EncounterType::loli:
		stats.set(50, 10, 9, 6, 10, 5, 2, 2, lvl);
		break;
	case Creatures::Encounter::EncounterType::shota:
		stats.set(150, 50, 3.3, 3.6, 0, 5, 1.5, 2, lvl);
		break;
	case Creatures::Encounter::EncounterType::zombie:
		stats.set(90, 30, 3, 5, 0, 4, 2, 2, lvl);
		break;
	case Creatures::Encounter::EncounterType::skeleton:
		stats.set(75, 25, 5, 3, 20, 11, 2, 2, lvl);
		break;
	case Creatures::Encounter::EncounterType::witch:
		stats.set(40, 10, 6.5, 6.5, 10, 5, 2, 1, lvl);
		break;
	case Creatures::Encounter::EncounterType::ghost:
		stats.set(5, 35, 5.5, 5.5, 0, 0, 1, 1, lvl);
		break;
	case Creatures::Encounter::EncounterType::theBeer:
		stats.set(0, 1, 0.1, 0.1, -100, 50, 10, 1, lvl);
		break;
	case Creatures::Encounter::EncounterType::yourself:
		stats.set(0, 0, 0, 0, 10, 5, 2, 1, lvl);
		break;
	case Creatures::Encounter::EncounterType::stoneGolem:
		stats.set(111, 55, 2.5, 3.5, 15, 0, 1, 3, lvl);
		break;
	case Creatures::Encounter::EncounterType::blurp:
		stats.set(21, 21, 0, 6.3, 0, 5, 2.1, 1, lvl);
		break;
	case Creatures::Encounter::EncounterType::smallRat:
		stats.set(0, 2.5, 0, 1, 0, 1, 2, 1, lvl);
		break;
	case Creatures::Encounter::EncounterType::rat:
		stats.set(2.5, 5, 1, 1.5, 0, 2, 2, 1, lvl);
		break;
	case Creatures::Encounter::EncounterType::giantRat:
		stats.set(5, 5, 2, 2, 0, 3, 2, 1, lvl);
		break;
	case Creatures::Encounter::EncounterType::enormousRat:
		stats.set(15, 10, 3, 3, 0, 4, 2, 2, lvl);
		break;
	case Creatures::Encounter::EncounterType::colossalRat:
		stats.set(20, 15, 4, 4, 0, 5, 2, 3, lvl);
		break;
	case Creatures::Encounter::EncounterType::colossalSpider:
		stats.set(15, 20, 6, 6, 10, 5, 1.5, 3, lvl);
		break;
	case Creatures::Encounter::EncounterType::ratman:
		stats.set(70, 30, 5, 5, 10, 10, 1.5, 4, lvl);
		break;
	case Creatures::Encounter::EncounterType::goblin:
		break;
	case Creatures::Encounter::EncounterType::hobgoblin:
		stats.set(50, 25, 3, 5, 10, 5, 2, 2, lvl);
		break;
	case Creatures::Encounter::EncounterType::orc:
		stats.set(60, 30, 5.5, 6.5, 15, 10, 1.5, 3, lvl);
		break;
	case Creatures::Encounter::EncounterType::kobold:
		stats.set(30, 25, 1.5, 3.5, 0, 10, 2, 1, lvl);
		break;
	case Creatures::Encounter::EncounterType::kockbold:
		stats.set(30, 25, 1.5, 3.5, 0, 10, 2, 1, lvl);
		break;
	case Creatures::Encounter::EncounterType::cockblin:
		stats.set(35, 25, 2, 4, 0, 5, 2, 1, lvl);
		break;
	case Creatures::Encounter::EncounterType::the104:
		break;
	case Creatures::Encounter::EncounterType::bugBox:
		stats.set(10, 10, 1, 1, 11, 11, 1.1, 1, lvl);
		break;
	case Creatures::Encounter::EncounterType::crackman:
		stats.set(60, 15, 4, 4, -20, 25, 2, 1, lvl);
		break;
	case Creatures::Encounter::EncounterType::errorGuy:
		stats.set(1, 1, 1, 0, 0, 0, 0, 1, 1);
		break;
	case Creatures::Encounter::EncounterType::elesya:
		stats.set(95, 45, 5, 10, 25, 0, 1, 5, lvl);
		break;
	case Creatures::Encounter::EncounterType::kelmod:
		stats.set(75, 35, 6, 9, 15, 5, 1.5, 5, lvl);
		break;
	case Creatures::Encounter::EncounterType::lenre:
		stats.set(65, 25, 6, 6, 35, 10, 2, 5, lvl);
		break;
	case Creatures::Encounter::EncounterType::necoto:
		stats.set(100, 50, 4, 6, 0, 10, 2, 5, lvl);
		break;
	case Creatures::Encounter::EncounterType::kyo:
		break;
	case Creatures::Encounter::EncounterType::expN30A:
		stats.set(74, 46, 4, 6, 0, 5, 2, 4, lvl);
		break;
	case Creatures::Encounter::EncounterType::expN30B:
		stats.set(85, 35, 5, 5, 10, 10, 2, 4, lvl);
		break;
	case Creatures::Encounter::EncounterType::expN30C:
		stats.set(96, 24, 6, 4, 20, 15, 2, 4, lvl);
		break;
	case Creatures::Encounter::EncounterType::sila:
		stats.set(60, 40, 6.5, 7.5, 0, 10, 1.5, 4, lvl);
		break;
	case Creatures::Encounter::EncounterType::armNuc:
		stats.set(45, 45, 7, 7, 25, 5, 2, 4, lvl);
		break;
	case Creatures::Encounter::EncounterType::miiro:
		stats.set(70, 50, 8, 7, 6, 10, 2, 4, lvl);
		break;
	case Creatures::Encounter::EncounterType::chishao:
		stats.set(65, 45, 7, 8, 9, 15, 1.5, 4, lvl);
		break;
	case Creatures::Encounter::EncounterType::nanre:
		stats.set(70, 20, 6, 6, 10, 5, 2, 1, lvl);
		break;
	case Creatures::Encounter::EncounterType::conakie:
		stats.set(70, 20, 6, 6, 10, 5, 2, 1, lvl);
		break;
	case Creatures::Encounter::EncounterType::yana:
		stats.set(70, 20, 6, 6, 10, 5, 2, 1, lvl);
		break;
	case Creatures::Encounter::EncounterType::fefr:
		stats.set(70, 20, 6, 6, 10, 5, 2, 1, lvl);
		break;
	case Creatures::Encounter::EncounterType::fiund:
		stats.set(70, 20, 6, 6, 10, 5, 2, 1, lvl);
		break;
	case Creatures::Encounter::EncounterType::none:
		stats.set(0, 0, 0, 0, 0, 0, 0, 0, 0, true, false, false);
		Print::Errors::noMatchCase(static_cast<int>(m_type), "Encounterz::setEncounter()");
		break;
	default:
		stats.set(0, 0, 0, 0, 0, 0, 0, 0, 0, true, false, false);
        Print::Errors::noMatchCase(static_cast<int>(m_type), "Encounterz::setEncounter()");
		break;
	}
    copyStats(stats);
	setNameFromType();
}

void Creatures::Encounter::Encounterz::setType(EncounterType type)
{
	m_type = type;
}

void Creatures::Encounter::Encounterz::setPlayer(Player::Playerz* player)
{
	m_player = player;
}

std::string_view Creatures::Encounter::Encounterz::getIntro() const
{
    //return "Nanre: \"What do you want?\"\n";
	switch (m_type)
	{
	case Creatures::Encounter::EncounterType::guard:
		return "There is a guard standing in front of you.\n";
	case Creatures::Encounter::EncounterType::drunkGuy:
		return "A drunk guy is walking wobbly towards you.\n";
	case Creatures::Encounter::EncounterType::soldier:
		return "A soldier is standing and looking at the horizon.\n";
	case Creatures::Encounter::EncounterType::torturer:
		return "There is a guy who looks worried. He looks like a torturer.\n";
	case Creatures::Encounter::EncounterType::giant:
		return "This giant doesn't seem friendly.\n";
	case Creatures::Encounter::EncounterType::priest:
		return "A priest of Miiro is walking. Your gaze meets his.\n";
	case Creatures::Encounter::EncounterType::elf:
		return "The elf hears you and turns around to check who's coming.\n";
	case Creatures::Encounter::EncounterType::dwarf:
		return "This dwarf wants a beer and a companion to drink with.\n";
	case Creatures::Encounter::EncounterType::prisoner:
		return "A girl is walking with chains on her shoulder. She's definately a prisoner.\n";
	case Creatures::Encounter::EncounterType::theRock:
		return "It is a rock. What did you expect?\n";
	case Creatures::Encounter::EncounterType::trader:
		return "A merchant approaches you. He seems friendly.\n";
	case Creatures::Encounter::EncounterType::bartender:
		return "That's a bartender. Never met one? Well, too bad for you.\n";
	case Creatures::Encounter::EncounterType::bard:
		return "This bard singing's is so bad that evenr rocks want to make him shut up.\n";
	case Creatures::Encounter::EncounterType::loli:
		return "There is a little human girl staring at you. She looks cute.\n";
	case Creatures::Encounter::EncounterType::shota:
		return "There is a little human boy staring at you. He looks \n";
	case Creatures::Encounter::EncounterType::zombie:
		return "A zombie seems to be looking for a certain someone. Is that you?\n";
	case Creatures::Encounter::EncounterType::skeleton:
		return "A skeletron. Made of bones and metal.\n";
	case Creatures::Encounter::EncounterType::witch:
		return "Oh no, a witch! Burn her!\n";
	case Creatures::Encounter::EncounterType::ghost:
		return "A ghost. Boo!\n";
	case Creatures::Encounter::EncounterType::theBeer:
		return "A mug of beer is sitting on the floor waiting for you. Or not. Who knows?\n";
	case Creatures::Encounter::EncounterType::yourself:
		return "It's you. I told you that cloning potions weren't good, didn't I?\n";
	case Creatures::Encounter::EncounterType::stoneGolem:
		return "A stone golem started moving as soon as you got close.\n";
	case Creatures::Encounter::EncounterType::blurp:
		return "A slime that goes by the name of blurp is hopping around.\n";
	case Creatures::Encounter::EncounterType::smallRat:
		return "A small rat is squeaking. *Sqek sqek*\n";
	case Creatures::Encounter::EncounterType::rat:
		return "A rat is looking for food. Are you the food?\n";
	case Creatures::Encounter::EncounterType::giantRat:
		return "There is a fat rat. It's a giant rat.\n";
	case Creatures::Encounter::EncounterType::enormousRat:
		return "This rat is way too big! It's enormous!\n";
	case Creatures::Encounter::EncounterType::colossalRat:
		return "I hope you like huge rats, because this is a colossal one.\n";
	case Creatures::Encounter::EncounterType::colossalSpider:
		return "Are you scared of spiders? Because this is a colossal spider.\n";
	case Creatures::Encounter::EncounterType::ratman:
		return "You found the mighty Ratman!\n";
	case Creatures::Encounter::EncounterType::goblin:
		return "A goblin saw your face and they started laughing.\n";
	case Creatures::Encounter::EncounterType::hobgoblin:
		return "Imagine a hobgoblin. Good, because that's what you have now in front of you.\n";
	case Creatures::Encounter::EncounterType::orc:
		return "An orc... Good luck for real.\n";
	case Creatures::Encounter::EncounterType::kobold:
		return "Kobolds are kinda cute. Have one.\n";
	case Creatures::Encounter::EncounterType::kockbold:
		return "You might be gat, because you just found a kockbold.\n";
	case Creatures::Encounter::EncounterType::cockblin:
		return "You're definitely gay now. You have found a cockblin.\n";
	case Creatures::Encounter::EncounterType::the104:
		return "Why am I keeping this? (104)\n";
	case Creatures::Encounter::EncounterType::bugBox:
		return "You found a bug box.\n";
	case Creatures::Encounter::EncounterType::crackman:
		return "You found Ratman's arch nemesis: Crackman!\n";
	case Creatures::Encounter::EncounterType::errorGuy:
		return "Error guy! Nanre's best friend.\n";
	case Creatures::Encounter::EncounterType::elesya:
		return "Elesya, the destroyer or save files and slapper of Kelmods is here.\n";
	case Creatures::Encounter::EncounterType::kelmod:
		return "The most annoying employee: Kelmod is here!\n";
	case Creatures::Encounter::EncounterType::lenre:
		return "Who remembers him? Nobody, so meet Lenre!\n";
	case Creatures::Encounter::EncounterType::necoto:
		return "The one and only: Necoto!\n";
	case Creatures::Encounter::EncounterType::kyo:
		return "He exists for no reason: Kyo!\n";
	case Creatures::Encounter::EncounterType::expN30A:
		return "Experiment Number 30A is here~\n";
	case Creatures::Encounter::EncounterType::expN30B:
		return "Experiment Number 30B arrived.\n";
	case Creatures::Encounter::EncounterType::expN30C:
		return "Experiment Number 30C is sitting down.\n";
	case Creatures::Encounter::EncounterType::sila:
		return "Sila is walking around aimlessy.\n";
	case Creatures::Encounter::EncounterType::armNuc:
		return "Arm Nuc seems bored. Why don't you do something?\n";
	case Creatures::Encounter::EncounterType::miiro:
		return "Miiro the Ersilia is here. She looks tired.\n";
	case Creatures::Encounter::EncounterType::chishao:
		return "Chishao noticed you ages ago. She is unsure if running away or not.\n";
	case Creatures::Encounter::EncounterType::nanre:
		return "Nanre. You probably know him. I mean, he made the game.\n";
	case Creatures::Encounter::EncounterType::conakie:
		return "Conakie. You probably know Conakie for the drawings.\n";
	case Creatures::Encounter::EncounterType::yana:
		return "Yana's intro.\n";
	case Creatures::Encounter::EncounterType::fefr:
		return "Fefr's intro.\n";
	case Creatures::Encounter::EncounterType::fiund:
		return "Fiund's intro.\n";
	case Creatures::Encounter::EncounterType::none:
		return "How the hell did you get the \"none\" type of encounter? Report this.\n";
	default:
		return "This is impossible. I swear that if this appears I'm nuking myself.\n";
		break;
	}
}

std::string_view Creatures::Encounter::Encounterz::getOutro() const
{
	return "Play Random adventure: Godot edition.\n";
}

void Creatures::Encounter::Encounterz::copyStats(EncounterStatsSetter& base)
{
	m_maxHp = base.getHpMax();
	m_maxAtk = base.getAtkMax();
	m_maxDef = base.getDefMax();
	m_critRate = base.getCritRate();
	m_critDmg = base.getCritDmg();
	m_xp = base.getXp();
    m_lvl = base.getLvl();
	m_isGone = base.getIsGone();
    m_isUnderAttack = base.getIsUnderAttack();
    m_canTalk = base.getCanTalk();

	m_hp = m_maxHp;
	m_atk = m_maxAtk;
	m_def = m_maxDef;
}

void Creatures::Encounter::Encounterz::dialogue()
{
	std::cout << "Lenre: \"Nuh uh~\"\n";

	m_canTalk = false;
	m_isUnderAttack = true;
}

void Creatures::Encounter::Encounterz::setNameFromType()
{
	switch (m_type)
	{
	case Creatures::Encounter::EncounterType::guard:
        m_name = "Guard";
		break;
	case Creatures::Encounter::EncounterType::drunkGuy:
		m_name = "Drunk Guy";
		break;
	case Creatures::Encounter::EncounterType::soldier:
		m_name = "Soldier";
		break;
	case Creatures::Encounter::EncounterType::torturer:
		m_name = "Torturer";
		break;
	case Creatures::Encounter::EncounterType::giant:
		m_name = "Giant";
		break;
	case Creatures::Encounter::EncounterType::priest:
		m_name = "Priest";
		break;
	case Creatures::Encounter::EncounterType::elf:
		m_name = "Elf";
		break;
	case Creatures::Encounter::EncounterType::dwarf:
		m_name = "Dwarf";
		break;
	case Creatures::Encounter::EncounterType::prisoner:
		m_name = "Prisoner";
		break;
	case Creatures::Encounter::EncounterType::theRock:
		m_name = "The Rock";
		break;
	case Creatures::Encounter::EncounterType::trader:
		m_name = "Trader";
		break;
	case Creatures::Encounter::EncounterType::bartender:
		m_name = "Bartender";
		break;
	case Creatures::Encounter::EncounterType::bard:
		m_name = "Bard";
		break;
	case Creatures::Encounter::EncounterType::loli:
		m_name = "Loli";
		break;
	case Creatures::Encounter::EncounterType::shota:
		m_name = "Shota";
		break;
	case Creatures::Encounter::EncounterType::zombie:
		m_name = "Zombie";
		break;
	case Creatures::Encounter::EncounterType::skeleton:
		m_name = "Skeleton";
		break;
	case Creatures::Encounter::EncounterType::witch:
		m_name = "Witch";
		break;
	case Creatures::Encounter::EncounterType::ghost:
		m_name = "Ghost";
		break;
	case Creatures::Encounter::EncounterType::theBeer:
		m_name = "The Beer";
		break;
	case Creatures::Encounter::EncounterType::yourself:
		m_name = "Yourself";
		break;
	case Creatures::Encounter::EncounterType::stoneGolem:
		m_name = "Stone Golem";
		break;
	case Creatures::Encounter::EncounterType::blurp:
		m_name = "Blurp";
		break;
	case Creatures::Encounter::EncounterType::smallRat:
		m_name = "Small Rat";
		break;
	case Creatures::Encounter::EncounterType::rat:
		m_name = "Rat";
		break;
	case Creatures::Encounter::EncounterType::giantRat:
		m_name = "Giant Rat";
		break;
	case Creatures::Encounter::EncounterType::enormousRat:
		m_name = "Enormous Rat";
		break;
	case Creatures::Encounter::EncounterType::colossalRat:
		m_name = "Colossal Rat";
		break;
	case Creatures::Encounter::EncounterType::colossalSpider:
		m_name = "Colossal Spider";
		break;
	case Creatures::Encounter::EncounterType::ratman:
		m_name = "Ratman";
		break;
	case Creatures::Encounter::EncounterType::goblin:
		m_name = "Goblin";
		break;
	case Creatures::Encounter::EncounterType::hobgoblin:
		m_name = "Hobgoblin";
		break;
	case Creatures::Encounter::EncounterType::orc:
		m_name = "Orc";
		break;
	case Creatures::Encounter::EncounterType::kobold:
		m_name = "Kobold";
		break;
	case Creatures::Encounter::EncounterType::kockbold:
		m_name = "Kockbold";
		break;
	case Creatures::Encounter::EncounterType::cockblin:
		m_name = "Cockblin";
		break;
	case Creatures::Encounter::EncounterType::the104:
		m_name = "The 104";
		break;
	case Creatures::Encounter::EncounterType::bugBox:
		m_name = "Bug Box";
		break;
	case Creatures::Encounter::EncounterType::crackman:
		m_name = "Crackman";
		break;
	case Creatures::Encounter::EncounterType::errorGuy:
		m_name = "Error Guy";
		break;
	case Creatures::Encounter::EncounterType::elesya:
		m_name = "Elesya";
		break;
	case Creatures::Encounter::EncounterType::kelmod:
		m_name = "Kelmod";
		break;
	case Creatures::Encounter::EncounterType::lenre:
		m_name = "Lenre";
		break;
	case Creatures::Encounter::EncounterType::necoto:
		m_name = "Necoto";
		break;
	case Creatures::Encounter::EncounterType::kyo:
		m_name = "Kyo";
		break;
	case Creatures::Encounter::EncounterType::expN30A:
		m_name = "Experiment Number 30A";
		break;
	case Creatures::Encounter::EncounterType::expN30B:
		m_name = "Experiment Number 30B";
		break;
	case Creatures::Encounter::EncounterType::expN30C:
		m_name = "Experiment Number 30C";
		break;
	case Creatures::Encounter::EncounterType::sila:
		m_name = "Sila";
		break;
	case Creatures::Encounter::EncounterType::armNuc:
		m_name = "Arm Nuc";
		break;
	case Creatures::Encounter::EncounterType::miiro:
		m_name = "Miiro";
		break;
	case Creatures::Encounter::EncounterType::chishao:
		m_name = "Chishao";
		break;
	case Creatures::Encounter::EncounterType::nanre:
		m_name = "Nanre";
		break;
	case Creatures::Encounter::EncounterType::conakie:
		m_name = "Conakie";
		break;
	case Creatures::Encounter::EncounterType::yana:
		m_name = "Yana";
		break;
	case Creatures::Encounter::EncounterType::fefr:
		m_name = "Fefr";
		break;
	case Creatures::Encounter::EncounterType::fiund:
		m_name = "Fiund";
		break;
	case Creatures::Encounter::EncounterType::none:
		m_name = "None";
		break;
	default:
        Print::Errors::noMatchCase(static_cast<int>(m_type), "Encounterz::setNameFromType()");
		m_name = "Unknown";
		break;
	}
}
