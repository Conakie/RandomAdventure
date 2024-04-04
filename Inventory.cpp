
#include <iostream>
#include "Inventory.h"
#include "Object UID.h"
#include "Print Errors.h"
#include "Stats.h"



void Inventory::setItem(ObjectUid item, int value)
{

	if (value < 0)
	{
		value = 0;
	}
	else
	{

	}


	switch (item)
	{
	case ObjectUid::smallHealingPotion:

		m_items.smallHealingPotion = value;

		break;

	case ObjectUid::mediumHealingPotion:

		m_items.mediumHealingPotion = value;

		break;

	case ObjectUid::bigHealingPotion:

		m_items.bigHealingPotion = value;

		break;

	case ObjectUid::molotov:

		m_items.molotov = value;

		break;

	case ObjectUid::nuke:

		m_items.nuke = value;

		break;

	case ObjectUid::herbs:

		m_items.herbs = value;

		break;

	case ObjectUid::wood:

		m_items.wood = value;

		break;

	case ObjectUid::arrow:

		m_items.arrow = value;

		break;

	case ObjectUid::leather:

		m_items.leather = value;

		break;

	case ObjectUid::stone:

		m_items.stone = value;

		break;

	case ObjectUid::bone:

		m_items.bone = value;

		break;

	case ObjectUid::paper:

		m_items.paper = value;

		break;

	case ObjectUid::meat:

		m_items.meat = value;

		break;

	case ObjectUid::fish:

		m_items.fish = value;

		break;

	case ObjectUid::mushroom:

		m_items.mushroom = value;

		break;

	case ObjectUid::magicScroll:

		m_items.magicScroll = value;

		break;

	default:

		PrintError::notFound();

		break;
	}


}



void Inventory::addItem(ObjectUid item, int value)
{

	if (value < 0)
	{
		value = 0;
	}
	else
	{

	}


	switch (item)
	{
	case ObjectUid::smallHealingPotion:

		m_items.smallHealingPotion += value;

		break;

	case ObjectUid::mediumHealingPotion:

		m_items.mediumHealingPotion += value;

		break;

	case ObjectUid::bigHealingPotion:

		m_items.bigHealingPotion += value;

		break;

	case ObjectUid::molotov:

		m_items.molotov += value;

		break;

	case ObjectUid::nuke:

		m_items.nuke += value;

		break;

	case ObjectUid::herbs:

		m_items.herbs += value;

		break;

	case ObjectUid::wood:

		m_items.wood += value;

		break;

	case ObjectUid::arrow:

		m_items.arrow += value;

		break;

	case ObjectUid::leather:

		m_items.leather += value;

		break;

	case ObjectUid::stone:

		m_items.stone += value;

		break;

	case ObjectUid::bone:

		m_items.bone += value;

		break;

	case ObjectUid::paper:

		m_items.paper += value;

		break;

	case ObjectUid::meat:

		m_items.meat += value;

		break;

	case ObjectUid::fish:

		m_items.fish += value;

		break;

	case ObjectUid::mushroom:

		m_items.mushroom += value;

		break;

	case ObjectUid::magicScroll:

		m_items.magicScroll += value;

		break;

	default:

		PrintError::notFound();

		break;
	}


}



void Inventory::reset()
{

	m_items.smallHealingPotion = 0;
	m_items.mediumHealingPotion = 0;
	m_items.bigHealingPotion = 0;
	m_items.molotov = 0;
	m_items.nuke = 0;
	m_items.herbs = 0;
	m_items.leather = 0;
	m_items.stone = 0;
	m_items.bone = 0;
	m_items.paper = 0;
	m_items.meat = 0;
	m_items.fish = 0;
	m_items.mushroom = 0;
	m_items.magicScroll = 0;
	m_items.cota = 0;

}



bool Inventory::useItem(ObjectUid item, int quantity)
{

	bool failedToUse{ false };
	

	if (quantity < 0)
	{
		quantity = 0;
		failedToUse = true;
	}
	else
	{

	}

	switch (item)
	{
	case ObjectUid::smallHealingPotion: 

		if (m_items.smallHealingPotion < quantity)
		{
			failedToUse = true;
		}
		else
		{
			std::cout << "(You drink the potion)\n";
			m_items.smallHealingPotion -= quantity;
			player().heal(2 * player().getLvl() * quantity);
		}

		break;

	case ObjectUid::mediumHealingPotion:

		if (m_items.mediumHealingPotion < quantity)
		{
			failedToUse = true;
		}
		else
		{
			std::cout << "(You drink the potion)\n";
			m_items.mediumHealingPotion -= quantity;
			player().heal(4 * player().getLvl() * quantity);
		}

		break;

	case ObjectUid::bigHealingPotion:

		if (m_items.bigHealingPotion < quantity)
		{
			failedToUse = true;
		}
		else
		{
			std::cout << "(You drink the potion)\n";
			m_items.bigHealingPotion -= quantity;
			player().heal(6 * player().getLvl() * quantity);
		}

		break;

	case ObjectUid::molotov:

		if (m_items.molotov < quantity)
		{
			failedToUse = true;
		}
		else
		{
			std::cout << "Blyatman: \"Molotov incoming!\"\n";
			m_items.molotov -= quantity;
			encounter().takeDamage(player().getAttack() * quantity);
		}

		break;

	case ObjectUid::nuke:

		if (m_items.nuke < quantity)
		{
			failedToUse = true;
		}
		else
		{
			std::cout << "Radio: \"Tactical nuke, incoming!\"\n";
			m_items.nuke -= quantity;
			encounter().takeDamage(encounter().getHealth() * quantity);
			player().takeDamage(player().getHealth() / (quantity * 0.6));
		}

		break;

	case ObjectUid::herbs:

		if (m_items.herbs < quantity)
		{
			failedToUse = true;
		}
		else
		{
			std::cout << "(You eat some grass)\n";
			m_items.herbs -= quantity;
			player().heal(0.2 * quantity);
		}

		break;

	case ObjectUid::wood:

		if (m_items.wood < quantity)
		{
			failedToUse = true;
		}
		else
		{
			std::cout << "(Nothing happens)\n";
			m_items.wood -= quantity;
		}

		break;

	case ObjectUid::arrow:

		if (m_items.arrow < quantity)
		{
			failedToUse = true;
		}
		else
		{
			std::cout << "You attack the encounter with an arrow an a bow.\n";
			m_items.arrow -= quantity;
			encounter().takeDamage(player().getAttack() * quantity);
		}

		break;

	case ObjectUid::leather:

		if (m_items.leather < quantity)
		{
			failedToUse = true;
		}
		else
		{
			std::cout << "(Nothing happens but at least you're warmer than before)\n";
			m_items.leather -= quantity;
		}

		break;

	case ObjectUid::stone:

		if (m_items.stone < quantity)
		{
			failedToUse = true;
		}
		else
		{
			std::cout << "You throw rocks at the encounter.\n";
			m_items.stone -= quantity;
			encounter().takeDamage(2 * player().getLvl() * quantity);
		}

		break;

	case ObjectUid::bone:

		if (m_items.bone < quantity)
		{
			failedToUse = true;
		}
		else
		{
			std::cout << "You attack the encounter with a bone doing almost nothing.\n";
			m_items.bone -= quantity;
			encounter().takeDamage(0.5 * player().getLvl() * quantity);
		}

		break;

	case ObjectUid::paper:

		if (m_items.paper < quantity)
		{
			failedToUse = true;
		}
		else
		{
			std::cout << "Ouch! you have cut yourself with paper. Be careful next time!\n";
			m_items.paper -= quantity;
			player().takeDamage(0.1 * quantity);
		}

		break;

	case ObjectUid::meat:

		if (m_items.meat < quantity)
		{
			failedToUse = true;
		}
		else
		{
			std::cout << "It was really time for a good ol' hot meat.\n";
			m_items.meat -= quantity;
			player().heal(1 * player().getLvl() * quantity);
		}

		break;

	case ObjectUid::fish:

		if (m_items.fish < quantity)
		{
			failedToUse = true;
		}
		else
		{
			std::cout << "When was the last time you had such a good meal?\n";
			m_items.fish -= quantity;
			player().heal(1 * player().getLvl() * quantity);
		}

		break;

	case ObjectUid::mushroom:

		if (m_items.mushroom < quantity)
		{
			failedToUse = true;
		}
		else
		{
			std::cout << "Oh no! The mushroom was poisonous!\n";
			m_items.mushroom -= quantity;
			player().takeDamage(1 * player().getLvl() * quantity);
		}

		break;

	case ObjectUid::magicScroll:

		if (m_items.magicScroll < quantity)
		{
			failedToUse = true;
		}
		else
		{
			std::cout << "Bakuretus Bakuretsu la la la~\n";
			m_items.magicScroll -= quantity;
			encounter().takeDamage(5 * player().getLvl() * quantity);
		}

		break;

	case ObjectUid::cota:

		if (m_items.cota < quantity)
		{
			failedToUse = true;
		}
		else
		{
			m_items.cota -= quantity;
		}

		break;

	default:

		PrintError::notFound();
		failedToUse = true;

		break;
	}


    return failedToUse;

}



void Inventory::print() const
{

	std::cout << "Your inventory:\n"
		<< "\n1 --> Small healing potion: " << m_items.smallHealingPotion
		<< "\n2 --> Medium healing potion: " << m_items.mediumHealingPotion
		<< "\n3 --> Big healing potion: " << m_items.bigHealingPotion
		<< "\n4 --> Molotov: " << m_items.molotov
		<< "\n5 --> Nuke: " << m_items.nuke
		<< "\n6 --> Herbs: " << m_items.herbs
		<< "\n7 --> Wood: " << m_items.wood
		<< "\n8 --> Arrow: " << m_items.arrow
		<< "\n9 --> Leather: " << m_items.leather
		<< "\n10 -> Stone: " << m_items.stone
		<< "\n11 -> Bone: " << m_items.bone
		<< "\n12 -> Paper: " << m_items.paper
		<< "\n13 -> Meat: " << m_items.meat
		<< "\n14 -> Fish: " << m_items.fish
		<< "\n15 -> Mushroom: " << m_items.mushroom
		<< "\n16 -> Magic Scoll: " << m_items.magicScroll
		<< "\n";

}