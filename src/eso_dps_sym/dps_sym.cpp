#include "dps_sym.h"

#include <set>

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
    uint64_t time = 0;

    while( !finish() )
    {
        CharAttributes cur_attr = attr;

        // process buffs
        for( auto it = _buffs.begin(); it != _buffs.end(); )
        {
            BuffWithTime& buff = *it;
            if( buff.time )
            {
                BaseBuffPtr buff_ptr =
                        BaseBuffFabric::inst().createByType( buff.buff );
                buff_ptr->processAttr( cur_attr );

                buff.time -= STEP;
                ++it;
            }
            else
                it = _buffs.erase( it );
        }

        // process skills
        std::set< SkillType > dots_for_clear;
        std::vector< SkillWithTimes > dot_for_add;

        for( auto it = _skills.begin(); it != _skills.end(); )
        {
            SkillWithTime& skill = *it;

            // ready
            if( skill.time == 0 )
            {
                // calc damage
                auto skill_ptr = BaseSkillFabric::inst().createByType( skill.skill );
                uint64_t dmg = skill_ptr->damage( cur_attr );
                if( dmg > 0 )
                    dmgs.push_back( { dmg, skill.skill, time } );

                // save dots for readd
                SkillType dot_type = skill_ptr->typeOfDot();
                if( dot_type != SkillType::Undefine )
                {
                    dots_for_clear.insert( dot_type );
                    dot_for_add.push_back( skill_ptr->createDot() );
                }

                // add buff
                BuffType buff = skill_ptr->createBuff();
                if( buff != BuffType::Undefine )
                {
                    uint64_t time = BaseBuffFabric::inst().createByType( buff )->time;
                    _buffs.push_back( { buff, time } );
                }

                // erase finished skill
                it = _skills.erase( it );
            }
            else
            {
                skill.time -= STEP;
                ++it;
            }
        }

        // clear dots
        for( auto it = _skills.begin(); it != _skills.end(); )
        {
            SkillWithTime& skill = *it;
            if( dots_for_clear.count( skill.skill ))
                it = _skills.erase( it );
            else
                ++it;
        }

        // add all dots
        for( SkillWithTimes skills: dot_for_add )
            for( SkillWithTime skill: skills )
            {
                //skill.time -= STEP;
                _skills.push_back( skill );
            }

        time += STEP;

        // update current attrs
        attr.current_resource = cur_attr.current_resource;
    }

    return dmgs;
}
