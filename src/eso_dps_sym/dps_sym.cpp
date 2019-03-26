#include "dps_sym.h"

void DpsSym::prepare(RotationPrepare rotation)
{
    uint64_t time = 0;

    for( SkillWithTime skill: rotation.getSkills() )
    {
        time += skill.time;
        skill.time = time;

        _skills.push_back( skill );
    }
}

TakenDamages DpsSym::symulate( CharAttributes& attr )
{
    TakenDamages dmgs;

    while( !finish() )
    {
        for( auto it = _skills.begin(); it != _skills.end(); )
        {
            SkillWithTime& skill = *it;

            // ready
            if( skill.time == 0 )
            {
                it = _skills.erase( it );

                auto skill_ptr = BaseSkillFabric::inst().createByType( skill.skill );
                uint64_t dmg = skill_ptr->damage( attr );
                dmgs.push_back( { dmg, skill.skill } );
            }
            else
            {
                skill.time -= STEP;
                ++it;
            }
        }
    }

    return dmgs;
}
