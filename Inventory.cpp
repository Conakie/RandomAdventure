
#include <iostream>
#include "Inventory.h"
#include "PrintErrors.h"
#include "Playerz.h"
#include "Encounterz.h"
#include "Random.h"



bool Creatures::Player::Inventory::useItem(Items::ItemName item, int quantity)
{
	switch (item)
	{
	case Items::ItemName::cota:
		if (m_items.cota >= quantity)
		{
			if (m_player)
			{
				m_items.cota -= quantity;
				printMessage("You used some money");
				return true;
			}
		}
		else
		{
			printInsufficientItems();
			return false;
		}
		break;
	case Items::ItemName::smallHealingPotion:
		if (isTheQuantityOk(&m_items.smallHealingPotion, quantity))
		{
			if (m_player)
			{
				double uwu{ 0 };
				m_items.smallHealingPotion -= quantity;
				for (int i{ 0 }; i < quantity; ++i)
					uwu += Random::get(1, 2 * m_player->getLvl());
				printMessage("You drink a small healing potion");
				m_player->heal(uwu);
				return true;
			}
		}
		else
		{
			printInsufficientItems();
			return false;
		}
		break;
	case Items::ItemName::mediumHealingPotion:
		if (isTheQuantityOk(&m_items.mediumHealingPotion, quantity))
		{
			if (m_player)
			{
				double uwu{ 0 };
				m_items.mediumHealingPotion -= quantity;
				for (int i{ 0 }; i < quantity; ++i)
					uwu += Random::get(1, 4 * m_player->getLvl());
				printMessage("You drink a medium healing potion");
				m_player->heal(uwu);
				return true;
			}
		}
		else
		{
			printInsufficientItems();
			return false;
		}
		break;
	case Items::ItemName::bigHealingPotion:
		if (isTheQuantityOk(&m_items.bigHealingPotion, quantity))
		{
			if (m_player)
			{
				double uwu{ 0 };
				m_items.bigHealingPotion -= quantity;
				for (int i{ 0 }; i < quantity; ++i)
					uwu += Random::get(1, 6 * m_player->getLvl());
				printMessage("You drink a big healing potion");
				m_player->heal(uwu);
				return true;
			}
		}
		else
		{
			printInsufficientItems();
			return false;
		}
		break;
	case Items::ItemName::molotov:
		if (isTheQuantityOk(&m_items.molotov, quantity))
		{
			if (m_player && m_encounter)
			{
				m_items.molotov -= quantity;
				printMessage("You throw a molotov at your enemy");
				m_encounter->takeDamage(4 * m_player->getLvl() * quantity);
				return true;
			}
		}
		else
		{
			printInsufficientItems();
			return false;
		}
		break;
	case Items::ItemName::nuke:
		if (isTheQuantityOk(&m_items.nuke, quantity))
		{
			if (m_player && m_encounter)
			{
				m_items.nuke -= quantity;
				for (int i{ 0 }; i < quantity; ++i)
				{
					printMessage("Radio message: \"Tactical nuke: incoming!\"");
					m_encounter->takeDamage(m_encounter->getHealth() * quantity);
					m_player->takeDamage(m_player->getHealth() * quantity * 0.6f);
					return true;
				}
			}
		}
		else
		{
			printInsufficientItems();
			return false;
		}
		break;
	case Items::ItemName::herbs:
		if (isTheQuantityOk(&m_items.herbs, quantity))
		{
			if (m_player)
			{
				double uwu{ 0 };
				m_items.herbs -= quantity;
				for (int i{ 0 }; i < quantity; ++i)
					uwu += Random::get(10, 30 * m_player->getLvl()) / 10.0f;
				m_player->heal(uwu);
				return true;
			}
		}
		else
		{
			printInsufficientItems();
			return false;
		}
		break;
	case Items::ItemName::wood:
		if (isTheQuantityOk(&m_items.wood, quantity))
		{
			if (m_encounter && m_player)
			{
				m_items.wood -= quantity;
				m_encounter->takeDamage(2 * m_player->getLvl() * quantity);
				return true;
			}
		}
		else
		{
			printInsufficientItems();
			return false;
		}
		break;
	case Items::ItemName::arrow:
		if (isTheQuantityOk(&m_items.arrow, quantity))
		{
			if (m_encounter && m_player)
			{
				m_items.arrow -= quantity;
				m_encounter->takeDamage(4 * m_player->getLvl() * quantity);
				return true;
			}
		}
		else
		{
			printInsufficientItems();
			return false;
		}
		break;
	case Items::ItemName::leather:
		if (isTheQuantityOk(&m_items.leather, quantity))
		{
			if (m_player)
			{
				m_items.leather -= quantity;
				printMessage("Nothing happens. UwU");
				return true;
			}
		}
		else
		{
			printInsufficientItems();
			return false;
		}
		break;
	case Items::ItemName::stone:
		if (isTheQuantityOk(&m_items.stone, quantity))
		{
			if (m_encounter && m_player)
			{
				m_items.stone -= quantity;
				m_encounter->takeDamage(0.1 * m_player->getLvl() * quantity);
				return true;
			}
		}
		else
		{
			printInsufficientItems();
			return false;
		}
		break;
	case Items::ItemName::bone:
		if (isTheQuantityOk(&m_items.bone, quantity))
		{
			if (m_player)
			{
				m_items.bone -= quantity;
				for (int i{ 0 }; i < quantity; ++i)
					m_encounter->takeDamage(3 * m_player->getLvl());
				return true;
			}
		}
		else
		{
			printInsufficientItems();
			return false;
		}
		break;
	case Items::ItemName::paper:
		if (isTheQuantityOk(&m_items.paper, quantity))
		{
			if (m_player)
			{
				m_items.paper -= quantity;
				m_player->takeDamage(0.1 * quantity);
				return true;
			}
		}
		else
		{
			printInsufficientItems();
			return false;
		}
		break;
	case Items::ItemName::meat:
		if (isTheQuantityOk(&m_items.meat, quantity))
		{
			if (m_player)
			{
				double uwu{ 0 };
				m_items.meat -= quantity;
				for (int i{ 0 }; i < quantity; ++i)
					uwu += Random::get(0, 1 * m_player->getLvl());
				m_player->heal(uwu);
				return true;
			}
		}
		else
		{
			printInsufficientItems();
			return false;
		}
		break;
	case Items::ItemName::fish:
		if (isTheQuantityOk(&m_items.fish, quantity))
		{
			if (m_player)
			{
				m_items.fish -= quantity;
				m_player->heal(1 * quantity);
				return true;
			}
		}
		else
		{
			printInsufficientItems();
			return false;
		}
		break;
	case Items::ItemName::mushroom:
		if (isTheQuantityOk(&m_items.mushroom, quantity))
		{
			if (m_player)
			{
				m_items.mushroom -= quantity;
				m_player->takeDamage(1 * m_player->getLvl() * quantity);
				return true;
			}
		}
		else
		{
			printInsufficientItems();
			return false;
		}
		break;
	case Items::ItemName::magicScroll:
		if (isTheQuantityOk(&m_items.magicScroll, quantity))
		{
			if (m_encounter && m_player)
			{
				double uwu{ 0 };
				m_items.magicScroll -= quantity;
				for (int i{ 0 }; i < quantity; ++i)
					uwu += Random::get(1, 6 * m_player->getLvl());
				m_encounter->takeDamage(uwu);
				return true;
			}
		}
		else
		{
			printInsufficientItems();
			return false;
		}
		break;
	default:
		Print::Errors::genericError("Tell Nanre he should delete himself from the game");
		return false;
		break;
	}
	return false;
}

void Creatures::Player::Inventory::addItem(Items::ItemName item, int quantity)
{
	switch (item)
	{
	case Items::ItemName::cota:
		m_items.cota += quantity;
		break;
	case Items::ItemName::smallHealingPotion:
		m_items.smallHealingPotion += quantity;
		break;
	case Items::ItemName::mediumHealingPotion:
		m_items.mediumHealingPotion += quantity;
		break;
	case Items::ItemName::bigHealingPotion:
		m_items.bigHealingPotion += quantity;
		break;
	case Items::ItemName::molotov:
		m_items.molotov += quantity;
		break;
	case Items::ItemName::nuke:
		m_items.nuke += quantity;
		break;
	case Items::ItemName::herbs:
		m_items.herbs += quantity;
		break;
	case Items::ItemName::wood:
		m_items.wood += quantity;
		break;
	case Items::ItemName::arrow:
		m_items.arrow += quantity;
		break;
	case Items::ItemName::leather:
		m_items.leather += quantity;
		break;
	case Items::ItemName::stone:
		m_items.stone += quantity;
		break;
	case Items::ItemName::bone:
		m_items.bone += quantity;
		break;
	case Items::ItemName::paper:
		m_items.paper += quantity;
		break;
	case Items::ItemName::meat:
		m_items.meat += quantity;
		break;
	case Items::ItemName::fish:
		m_items.fish += quantity;
		break;
	case Items::ItemName::mushroom:
		m_items.mushroom += quantity;
		break;
	case Items::ItemName::magicScroll:
		m_items.magicScroll += quantity;
		break;
	default:
		Print::Errors::genericError("Item is not a real item.");
		break;
	}
}

void Creatures::Player::Inventory::printAndAdd(Items::ItemName item, int quantity)
{
	switch (item)
	{
	case Items::ItemName::cota:
		std::cout << "(You got " << quantity << " cota)";
		break;
	case Items::ItemName::smallHealingPotion:
		std::cout << "(You got " << quantity << " small healing potions)";
		break;
	case Items::ItemName::mediumHealingPotion:
		std::cout << "(You got " << quantity << " medium healing potions)";
		break;
	case Items::ItemName::bigHealingPotion:
		std::cout << "(You got " << quantity << " big healing potions)";
		break;
	case Items::ItemName::molotov:
		std::cout << "(You got " << quantity << " molotov)";
		break;
	case Items::ItemName::nuke:
		std::cout << "(You got " << quantity << " nuke)";
		break;
	case Items::ItemName::herbs:
		std::cout << "(You got " << quantity << " herbs)";
		break;
	case Items::ItemName::wood:
		std::cout << "(You got " << quantity << " wood)";
		break;
	case Items::ItemName::arrow:
		std::cout << "(You got " << quantity << " arrow)";
		break;
	case Items::ItemName::leather:
		std::cout << "(You got " << quantity << " leather)";
		break;
	case Items::ItemName::stone:
		std::cout << "(You got " << quantity << " stones)";
		break;
	case Items::ItemName::bone:
		std::cout << "(You got " << quantity << " bones)";
		break;
	case Items::ItemName::paper:
		std::cout << "(You got " << quantity << " paper)";
		break;
	case Items::ItemName::meat:
		std::cout << "(You got " << quantity << " meat)";
		break;
	case Items::ItemName::fish:
		std::cout << "(You got " << quantity << " fish)";
		break;
	case Items::ItemName::mushroom:
		std::cout << "(You got " << quantity << " mushroom)";
		break;
	case Items::ItemName::magicScroll:
		std::cout << "(You got " << quantity << " magic scrolls)";
		break;
	default:
		break;
	}
}

void Creatures::Player::Inventory::printInventory() const
{
	std::cout << "Your inventory:\n"
		<< "Cota: "						<< m_items.cota					<< '\n'
		<< "Small Healing Potions: "	<< m_items.smallHealingPotion	<< '\n'
		<< "Medium Healing Potions: "	<< m_items.mediumHealingPotion	<< '\n'
		<< "Big Healing Potions: "		<< m_items.bigHealingPotion		<< '\n'
		<< "Molotovs: "					<< m_items.molotov				<< '\n'
		<< "Nukes: "					<< m_items.nuke					<< '\n'
		<< "Herbs: "					<< m_items.herbs				<< '\n'
		<< "Wood: "						<< m_items.wood					<< '\n'
		<< "Arrows: "					<< m_items.arrow				<< '\n'
		<< "Leather: "					<< m_items.leather				<< '\n'
		<< "Stones: "					<< m_items.stone				<< '\n'
		<< "Bones: "					<< m_items.bone					<< '\n'
		<< "Paper: "					<< m_items.paper				<< '\n'
		<< "Meat: "						<< m_items.meat					<< '\n'
		<< "Fish: "						<< m_items.fish					<< '\n'
		<< "Mushrooms: "				<< m_items.mushroom				<< '\n'
        << "Magic Scrolls: "			<< m_items.magicScroll			<< '\n';
}

void Creatures::Player::Inventory::reset()
{
	m_items.cota = 0;
	m_items.smallHealingPotion = 0;
	m_items.mediumHealingPotion = 0;
	m_items.bigHealingPotion = 0;
	m_items.molotov = 0;
	m_items.nuke = 0;
	m_items.herbs = 0;
	m_items.wood = 0;
	m_items.arrow = 0;
	m_items.leather = 0;
	m_items.stone = 0;
	m_items.bone = 0;
	m_items.paper = 0;
	m_items.meat = 0;
	m_items.fish = 0;
	m_items.mushroom = 0;
	m_items.magicScroll = 0;

	m_player = nullptr;
	m_encounter = nullptr;
}

void Creatures::Player::Inventory::setTarget(Playerz* player)
{
	m_player = player;
}

void Creatures::Player::Inventory::setTarget(Encounter::Encounterz* encounter)
{
	m_encounter = encounter;
}

bool Creatures::Player::Inventory::isTheQuantityOk(int* item, int quantity) const
{
	return (quantity <= *item);
}

void Creatures::Player::Inventory::printInsufficientItems() const
{
	std::cout << "Quantity too high!";
}

void Creatures::Player::Inventory::printMessage(std::string_view message) const
{
	std::cout << "\n("
		<< message
		<< ")\n";
}
