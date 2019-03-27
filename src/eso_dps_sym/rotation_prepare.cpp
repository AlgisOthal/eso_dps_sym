#include "rotation_prepare.h"

void RotationPrepare::skillAndWait(SkillType skill, uint msec)
{
    _skills.push_back( { skill, msec } );
}

void RotationPrepare::laAndSkill( SkillType skill, uint msec_before, uint msec_between )
{
    skillAndWait( SkillType::la, msec_before );
    skillAndWait( skill, msec_between );
}
