#ifndef ROTATION_PREPARE_H
#define ROTATION_PREPARE_H

#include "base_skill.h"

struct SkillWithTime
{
    SkillType skill;
    uint64_t time;
};
typedef std::vector< SkillWithTime > SkillWithTimes;

class RotationPrepare
{
public:
    SkillWithTimes getSkills(){ return _skills; }

    void skillAndWait( SkillType skill, uint msec );
    void laAndSkill( SkillType skill,
                     uint msec_after,
                     uint msec_between = 100 );

private:
    SkillWithTimes _skills;
};

#endif // ROTATION_PREPARE_H
