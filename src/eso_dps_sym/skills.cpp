#include "skills.h"

// skills
REGISTER_SKILL( SkillType::la, LightAttack );
REGISTER_SKILL( SkillType::swallow, SwallowSoul );
REGISTER_SKILL( SkillType::twisting_path, TwistingPath );

// dots
REGISTER_SKILL( SkillType::twisting_path_dot, TwistingPathDot );

// buffs
REGISTER_SKILL( SkillType::resolve, MiracleResolve );

//-------------------------

SkillWithTimes TwistingPath::createDot()
{
    SkillWithTimes res;

    uint64_t time = 0;
    for( uint i = 0; i < 11; ++i )
    {
        res.push_back( { typeOfDot(), time } );
        time += 1000;
    }

    return res;
}
