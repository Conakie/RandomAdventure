
#ifndef KIIYUO_RATABS_CREATURES_ENCOUNTER_ENCOUNTERZ_CLASS_H
#define KIIYUO_RATABS_CREATURES_ENCOUNTER_ENCOUNTERZ_CLASS_H

#include <string>
#include <string_view>
#include "EncounterBase.h"
#include "Costants.h"
#include "Tests.h"
#include "Encounter UID.h"


namespace Creatures
{
    namespace Player
    {
        class Playerz;
    };
};

namespace Creatures
{
    namespace Encounter
    {
        class Encounterz : protected EncounterBase
        {
        public:
            void heal(double healing);
            virtual void takeDamage(double damage);
            virtual void attack(Creatures::Player::Playerz& player);
            virtual void talk();
            void dropItems() const;
            //void dropItems(Inventoryz* inventory) const;
            virtual void thinkAndAct();
            virtual void printStats() const;

            bool isAlive() const { return (hp >= 0.01); }
            bool isGone() const { return m_isGone; }
            virtual void resetStats();

            void setPlayer(Creatures::Player::Playerz* player);
            void setEncounter();
            void setType(EncounterType type) { encounterType = type; }
            void setLevel(int level) { lvl = level; }

            double getHealth() const { return hp; }
            std::string_view getName() const { return name; }
            int getXp() const { return xp; }

            // delete these later. Just for older versions
            bool getIsGone() const { return m_isGone; }
            bool getIsUnderAttack() const { return m_isUnderAttack; }
            bool getCanTalk() const { return m_canTalk; }
            double getAttack() const { return atk; }
            int getLvl() const { return lvl; }
            EncounterUid getUid() const { return toEncUid(encounterType); }

            void setUid(EncounterUid uid) const { return; }
            void setCanTalk(bool burb) { m_canTalk = burb; }
            void setIsGone(bool burb) { m_isGone = burb; }
            void setIsUnderAttack(bool burb) { m_isUnderAttack = burb; }

            int increaseXp(int i) const { return xp; }
        protected:
            void announceEncounter() const;
            virtual void setName();
            virtual void setStats();
            void setState();
            Player::Playerz* m_player{ nullptr };
        };
    };
};

#endif // !KIIYUO_RATABS_CREATURES_ENCOUNTER_ENCOUNTERZ_CLASS_H
