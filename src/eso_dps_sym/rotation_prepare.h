#ifndef ROTATION_PREPARE_H
#define ROTATION_PREPARE_H

#include "base_skill.h"

class RotationPrepare
{
public:
    SkillWithTimes getSkills(){ return _skills; }

    void skillAndWait( SkillType skill, uint msec );
    void laAndSkill(SkillType skill,
                     uint msec_before = 1000,
                     uint msec_between = 100 );

private:
    SkillWithTimes _skills;
};

#endif // ROTATION_PREPARE_H
