#include "skills.h"

// skills
REGISTER_SKILL( SkillType::la, LightAttack );
REGISTER_SKILL( SkillType::swallow, SwallowSoul );
REGISTER_SKILL( SkillType::twisting_path, TwistingPath );
REGISTER_SKILL( SkillType::impale, Impale );
REGISTER_SKILL( SkillType::grasp, GrisplingGrasp );
REGISTER_SKILL( SkillType::blockade, BlokadeOfFlame );
REGISTER_SKILL( SkillType::spectral, SpectralBow );

// dots
REGISTER_SKILL( SkillType::twisting_path_dot, TwistingPathDot );
REGISTER_SKILL( SkillType::grasp_dot, GrisplingGraspDot );
REGISTER_SKILL( SkillType::blockade_dot, BlokadeOfFlameDot );

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

SkillWithTimes GrisplingGrasp::createDot()
{
    SkillWithTimes res;

    uint64_t time = 0;
    for( uint i = 0; i < 8; ++i )
    {
        res.push_back( { typeOfDot(), time } );
        time += 1000;
    }

    return res;
}

SkillWithTimes BlokadeOfFlame::createDot()
{
    SkillWithTimes res;

    uint64_t time = 0;
    for( uint i = 0; i < 8; ++i )
    {
        res.push_back( { typeOfDot(), time } );
        time += 1000;
    }

    return res;
}
