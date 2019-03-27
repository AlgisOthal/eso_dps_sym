#ifndef DPS_SYM_H
#define DPS_SYM_H

#include <queue>

#include "skills.h"
#include "char_attributes.h"
#include "rotation_prepare.h"

#define STEP 10

struct TakenDamage
{
    uint64_t damage;
    SkillType skill;
    uint64_t time;

    TakenDamage( uint64_t dmg_,
                 SkillType skill_,
                 uint64_t time_):
        damage( dmg_ ),
        skill( skill_ ),
        time( time_ )
    {}
};
typedef std::vector< TakenDamage > TakenDamages;

//------------------------------------

class DpsSym
{
public:
    void prepare( RotationPrepare rotation );
    bool finish(){ return !_skills.size(); }

    TakenDamages symulate( CharAttributes &attr );

private:
    SkillWithTimes _skills;
    BuffWithTimes _buffs;
};

#endif // DPS_SYM_H
